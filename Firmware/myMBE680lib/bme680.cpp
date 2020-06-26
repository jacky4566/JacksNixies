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
    Serial.println("Pressure:");
    Serial.println(readRegister(0x1F));
    Serial.println(readRegister(0x20));
    Serial.println(readRegister(0x21));
    Serial.println("Temp:");
    Serial.println(readRegister(0x22));
    Serial.println(readRegister(0x23));
    Serial.println(readRegister(0x24));

    uint32_t temp_adc = (uint32_t) (((uint32_t) readRegister(0x22) * 4096) | ((uint32_t) readRegister(0x23) * 16) | ((uint32_t) readRegister(0x24) / 16));

	/* calculate var1 data */
	float var1  = ((((float)temp_adc / 16384.0f) - ((float)calib_data.par_t1 / 1024.0f))
			* ((float)calib_data.par_t2));

	/* calculate var2 data */
	float var2  = (((((float)temp_adc / 131072.0f) - ((float)calib_data.par_t1 / 8192.0f)) 
        * (((float)temp_adc / 131072.0f) - ((float)calib_data.par_t1 / 8192.0f))) 
        * ((float)calib_data.par_t3 * 16.0f));

	/* t_fine value*/
	calib_data.t_fine = (var1 + var2);

	/* compensated temperature data*/
	temperature  = ((calib_data.t_fine) / 5120.0f);

    //temperature = readRegister(0x22) << 12 | readRegister(0x23) << 4 | readRegister(0x24);
    Serial.println("calib");
    Serial.println(calib_data.par_t1);
    Serial.println(calib_data.par_t2);
    Serial.println(calib_data.par_t3);
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
    calib_data.par_t2 = (int16_t)(((uint16_t)readRegister(BME680_T2_MSB_REG) << 8) | (uint16_t)readRegister(BME680_T2_LSB_REG));
    calib_data.par_t3 = (int8_t)readRegister(BME680_T3_REG);
    
    /* Pressure related coefficients */
    dev->calib.par_p1 = (uint16_t) (BME680_CONCAT_BYTES(coeff_array[BME680_P1_MSB_REG],
        coeff_array[BME680_P1_LSB_REG]));
    dev->calib.par_p2 = (int16_t) (BME680_CONCAT_BYTES(coeff_array[BME680_P2_MSB_REG],
        coeff_array[BME680_P2_LSB_REG]));
    dev->calib.par_p3 = (int8_t) coeff_array[BME680_P3_REG];
    dev->calib.par_p4 = (int16_t) (BME680_CONCAT_BYTES(coeff_array[BME680_P4_MSB_REG],
        coeff_array[BME680_P4_LSB_REG]));
    dev->calib.par_p5 = (int16_t) (BME680_CONCAT_BYTES(coeff_array[BME680_P5_MSB_REG],
        coeff_array[BME680_P5_LSB_REG]));
    dev->calib.par_p6 = (int8_t) (coeff_array[BME680_P6_REG]);
    dev->calib.par_p7 = (int8_t) (coeff_array[BME680_P7_REG]);
    dev->calib.par_p8 = (int16_t) (BME680_CONCAT_BYTES(coeff_array[BME680_P8_MSB_REG],
        coeff_array[BME680_P8_LSB_REG]));
    dev->calib.par_p9 = (int16_t) (BME680_CONCAT_BYTES(coeff_array[BME680_P9_MSB_REG],
        coeff_array[BME680_P9_LSB_REG]));
    dev->calib.par_p10 = (uint8_t) (coeff_array[BME680_P10_REG]);
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