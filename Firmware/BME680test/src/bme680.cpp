#include "Arduino.h"
#include "bme680.h"

bme680::bme680(int8_t cspin){
  _cs = cspin;
}

boolean bme680::begin() {
    pinMode(_cs, OUTPUT);
    SPI.begin(_cs);
    SPI.setClockSpeed(1000000);
    writeRegister(reg_status, readRegister(reg_status) & ~0x10); //set page 0
    if (readRegister(reg_chip_id) != 0x61){
        return false;
    }
    getCalibration();
    writeRegister(reg_status, readRegister(reg_status) | 0x10); //set page 1
    writeRegister(reg_ctrl_hum, 0x01);//Humidity oversampling to 1x
    writeRegister(reg_ctrl_meas, 0x34);//Temperature oversampling to 2x, pressure oversampling to 16x, Sleep mode
    writeRegister(reg_config, 0x04);//IIR filter control 1
    return true;
}

void bme680::performReading() {
    writeRegister(reg_status, readRegister(reg_status) | 0x10); //set page 1
    writeRegister(reg_ctrl_meas, readRegister(reg_ctrl_meas) | 0x01); //start reading
    while((readRegister(reg_meas_status) & 0x20) == 0){

    }
    //Do a bunch of dumb math from Bosch
    double var1;
    double var2;
    double var3;
    double var4;
    //Calc Temperature
    //calcuate Temp
    uint32_t temp_adc = (uint32_t) (((uint32_t) readRegister(reg_temp_msb) * 4096) | ((uint32_t) readRegister(reg_temp_lsb) * 16) | ((uint32_t) readRegister(reg_temp_xlsb) / 16));

    /* calculate var1 data */
    var1  = ((((double)temp_adc / 16384.0f) - ((double)calib_data.par_t1 / 1024.0f))
            * ((double)calib_data.par_t2));

    /* calculate var2 data */
    var2  = (((((double)temp_adc / 131072.0f) - ((double)calib_data.par_t1 / 8192.0f)) 
        * (((double)temp_adc / 131072.0f) - ((double)calib_data.par_t1 / 8192.0f))) 
        * ((double)calib_data.par_t3 * 16.0f));

    /* t_fine value*/
    calib_data.t_fine = (var1 + var2);

    /* compensated temperature data*/
    temperature  = ((calib_data.t_fine) / 5120.0f);
    

    //calcuate Pressure
    uint32_t pres_adc = (uint32_t) (((uint32_t) readRegister(reg_press_msb) * 4096) | ((uint32_t) readRegister(reg_press_lsb) * 16) | ((uint32_t) readRegister(reg_press_xlsb) / 16));

    var1 = (((double)calib_data.t_fine / 2.0f) - 64000.0f);
    var2 = var1 * var1 * (((double)calib_data.par_p6) / (131072.0f));
    var2 = var2 + (var1 * ((double)calib_data.par_p5) * 2.0f);
    var2 = (var2 / 4.0f) + (((double)calib_data.par_p4) * 65536.0f);
    var1 = (((((double)calib_data.par_p3 * var1 * var1) / 16384.0f) + ((double)calib_data.par_p2 * var1)) / 524288.0f);
    var1 = ((1.0f + (var1 / 32768.0f)) * ((double)calib_data.par_p1));
    pressure = (1048576.0f - ((double)pres_adc));

    /* Avoid exception caused by division by zero */
    if ((int)var1 != 0) {
        pressure = (((pressure - (var2 / 4096.0f)) * 6250.0f) / var1);
        var1 = (((double)calib_data.par_p9) * pressure * pressure) / 2147483648.0f;
        var2 = pressure * (((double)calib_data.par_p8) / 32768.0f);
        var3 = ((pressure / 256.0f) * (pressure / 256.0f) * (pressure / 256.0f)
            * (calib_data.par_p10 / 131072.0f));
        pressure = (pressure + (var1 + var2 + var3 + ((double)calib_data.par_p7 * 128.0f)) / 16.0f);
    } else {
        pressure = 0;
    }
    //calc humidity
    uint16_t hum_adc = (uint16_t) (((uint32_t) readRegister(reg_hum_msb) * 256) | (uint32_t) readRegister(reg_hum_lsb));
    double temp_comp  = ((calib_data.t_fine) / 5120.0f);

    var1 = (double)((double)hum_adc) - (((double)calib_data.par_h1 * 16.0f) + (((double)calib_data.par_h3 / 2.0f) * temp_comp));
    var2 = var1 * ((double)(((double) calib_data.par_h2 / 262144.0f) * (1.0f + (((double)calib_data.par_h4 / 16384.0f) * temp_comp) + (((double)calib_data.par_h5 / 1048576.0f) * temp_comp * temp_comp))));
    var3 = (double) calib_data.par_h6 / 16384.0f;
    var4 = (double) calib_data.par_h7 / 2097152.0f;
    humidity = var2 + ((var3 + (var4 * temp_comp)) * var2 * var2);

    if (humidity > 100.0f)
        humidity = 100.0f;
    else if (humidity < 0.0f)
        humidity = 0.0f;
}

byte bme680::readRegister(byte reg_addr){
    byte returnvalue;
    digitalWrite(_cs, LOW);
    SPI.transfer(reg_addr | 0x80);
    returnvalue = SPI.transfer(0x00);
    digitalWrite(_cs, HIGH);
    return returnvalue;
}

void bme680::writeRegister(byte reg_addr, byte reg_data){
    digitalWrite(_cs, LOW);
    SPI.transfer(reg_addr);
    SPI.transfer(reg_data);
    digitalWrite(_cs, HIGH);
}

void bme680::getCalibration(){
    /* Temperature related coefficients */
    calib_data.par_t1 = ((uint16_t)readRegister(BME680_T1_MSB_REG) << 8) | (uint16_t)readRegister(BME680_T1_LSB_REG);
    calib_data.par_t2 = (int16_t)(((int16_t)readRegister(BME680_T2_MSB_REG) << 8) | (int16_t)readRegister(BME680_T2_LSB_REG));
    calib_data.par_t3 = (int8_t)readRegister(BME680_T3_REG);
    
    /* Pressure related coefficients */
    calib_data.par_p1 = ((uint16_t)readRegister(BME680_P1_MSB_REG) << 8) | (uint16_t)readRegister(BME680_P1_LSB_REG);
    calib_data.par_p2 = (int16_t)(((int16_t)readRegister(BME680_P2_MSB_REG) << 8) | (int16_t)readRegister(BME680_P2_LSB_REG));
    calib_data.par_p3 = (int8_t)readRegister(BME680_P3_REG);
    calib_data.par_p4 = (int16_t)(((int16_t)readRegister(BME680_P4_MSB_REG) << 8) | (int16_t)readRegister(BME680_P4_LSB_REG));
    calib_data.par_p5 = (int16_t)(((int16_t)readRegister(BME680_P5_MSB_REG) << 8) | (int16_t)readRegister(BME680_P5_LSB_REG));
    calib_data.par_p6 = (int8_t)readRegister(BME680_P6_REG);
    calib_data.par_p7 = (int8_t)readRegister(BME680_P7_REG);
    calib_data.par_p8 = (int16_t)(((int16_t)readRegister(BME680_P8_MSB_REG) << 8) | (int16_t)readRegister(BME680_P8_LSB_REG));
    calib_data.par_p9 = (int16_t)(((int16_t)readRegister(BME680_P9_MSB_REG) << 8) | (int16_t)readRegister(BME680_P9_LSB_REG));
    calib_data.par_p10 = (uint8_t)readRegister(BME680_P10_REG);

    /* Humidity related coefficients */
    #define BME680_HUM_REG_SHIFT_VAL	UINT8_C(4)
    #define	BME680_BIT_H1_DATA_MSK	UINT8_C(0x0F)
    calib_data.par_h1 = (uint16_t)((uint16_t)readRegister(BME680_H1_MSB_REG) << 4) | ((uint16_t)readRegister(BME680_H1_LSB_REG) & 0x0F);
    calib_data.par_h2 = (uint16_t)((uint16_t)readRegister(BME680_H2_MSB_REG) << 4) | ((uint16_t)readRegister(BME680_H2_LSB_REG) >> 4);
    calib_data.par_h3 = (int8_t)readRegister(BME680_H3_REG);
    calib_data.par_h4 = (int8_t)readRegister(BME680_H4_REG);
    calib_data.par_h5 = (int8_t)readRegister(BME680_H5_REG);
    calib_data.par_h6 = (uint8_t)readRegister(BME680_H6_REG);
    calib_data.par_h7 = (int8_t)readRegister(BME680_H7_REG);

    /* Gas heater related coefficients */
    calib_data.par_gh1 = (int8_t)readRegister(BME680_GH1_REG);
    calib_data.par_gh2 = (int16_t)(((int16_t)readRegister(BME680_GH2_MSB_REG) << 8) | (int16_t)readRegister(BME680_GH2_LSB_REG));
    calib_data.par_gh3 = (int8_t)readRegister(BME680_GH3_REG);
}

void bme680::printCalib(){
    Serial.print("gh1: ");Serial.println(calib_data.par_gh1);
    Serial.print("gh2: ");Serial.println(calib_data.par_gh2);
    Serial.print("gh3: ");Serial.println(calib_data.par_gh3);
    Serial.print("h1: ");Serial.println(calib_data.par_h1);
    Serial.print("h2: ");Serial.println(calib_data.par_h2);
    Serial.print("h3: ");Serial.println(calib_data.par_h3);
    Serial.print("h4: ");Serial.println(calib_data.par_h4);
    Serial.print("h5: ");Serial.println(calib_data.par_h5);
    Serial.print("h6: ");Serial.println(calib_data.par_h6);
    Serial.print("h7: ");Serial.println(calib_data.par_h7);
    Serial.print("p1: ");Serial.println(calib_data.par_p1);
    Serial.print("p10: ");Serial.println(calib_data.par_p10);
    Serial.print("p2: ");Serial.println(calib_data.par_p2);
    Serial.print("p3: ");Serial.println(calib_data.par_p3);
    Serial.print("p4: ");Serial.println(calib_data.par_p4);
    Serial.print("p5: ");Serial.println(calib_data.par_p5);
    Serial.print("p6: ");Serial.println(calib_data.par_p6);
    Serial.print("p7: ");Serial.println(calib_data.par_p7);
    Serial.print("p8: ");Serial.println(calib_data.par_p8);
    Serial.print("p9: ");Serial.println(calib_data.par_p9);
    Serial.print("t1: ");Serial.println(calib_data.par_t1);
    Serial.print("t2: ");Serial.println(calib_data.par_t2);
    Serial.print("t3: ");Serial.println(calib_data.par_t3);
}

void bme680::hexFinder(){
    uint16_t reg1;
    uint16_t reg2;
    uint16_t sample;
    writeRegister(reg_status, readRegister(reg_status) & ~0x10); //set page 0
    for (uint16_t i = 0; i < 0x200; i++){
        reg1 = readRegister(i);
        reg2 = readRegister(i + 1);
        sample = (reg2 << 8) | reg1;
        if (sample < 30000 && sample > 20000 && reg1 != 0xff && reg2 != 0xff){ //looking for ~26041
            Serial.print(i, HEX);Serial.print(":");Serial.print(sample);Serial.print(":");Serial.print(reg1);Serial.print(":");Serial.println(reg2);
        }
    }
}