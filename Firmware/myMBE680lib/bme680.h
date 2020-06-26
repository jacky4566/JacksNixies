#ifndef __BME680_H__
#define __BME680_H__

#include "Arduino.h"
#include <SPI.h>
#include "bme680.h"

#define reg_status 0x73
#define reg_chip_id 0x50
#define reg_config 0x75
#define reg_ctrl_meas 0x74
#define reg_ctrl_hum 0x72
#define reg_meas_status 0x1D

/** Array Index to Field data mapping for Calibration Data*/
#define BME680_T2_LSB_REG 0x8A
#define BME680_T2_MSB_REG 0x8B
#define BME680_T3_REG 0x8C
#define BME680_P1_LSB_REG 0x8E
#define BME680_P1_MSB_REG 0x8F
#define BME680_P2_LSB_REG 0x90
#define BME680_P2_MSB_REG 0x91
#define BME680_P3_REG 0x92
#define BME680_P4_LSB_REG 0x94
#define BME680_P4_MSB_REG 0x95
#define BME680_P5_LSB_REG 0x96
#define BME680_P5_MSB_REG 0x97
#define BME680_P7_REG 0x98
#define BME680_P6_REG 0x99
#define BME680_P8_LSB_REG 0x9C
#define BME680_P8_MSB_REG 0x9D
#define BME680_P9_LSB_REG 0x9E
#define BME680_P9_MSB_REG 0x9F
#define BME680_P10_REG 0xA0
#define BME680_H2_MSB_REG 0x102
#define BME680_H2_LSB_REG 0x103
#define BME680_H1_LSB_REG 0x103
#define BME680_H1_MSB_REG 0x104
#define BME680_H3_REG 0x105
#define BME680_H4_REG 0x106
#define BME680_H5_REG 0x107
#define BME680_H6_REG 0x108
#define BME680_H7_REG 0x109
#define BME680_T1_LSB_REG 0x10A
#define BME680_T1_MSB_REG 0x10B
#define BME680_GH2_LSB_REG 0x10C
#define BME680_GH2_MSB_REG 0x10D
#define BME680_GH1_REG 0x10E
#define BME680_GH3_REG 0x10F

struct	bme680_calib_data {
	uint16_t par_h1;
	uint16_t par_h2;
	int8_t par_h3;
	int8_t par_h4;
	int8_t par_h5;
	uint8_t par_h6;
	int8_t par_h7;
	int8_t par_gh1;
	int16_t par_gh2;
	int8_t par_gh3;
	uint16_t par_t1 = 26041;
	int16_t par_t2 = 26469;
	int8_t par_t3 = 3;
	uint16_t par_p1;
	int16_t par_p2;
	int8_t par_p3;
	int16_t par_p4;
	int16_t par_p5;
	int8_t par_p6;
	int8_t par_p7;
	int16_t par_p8;
	int16_t par_p9;
	uint8_t par_p10;
    
	float t_fine;

	uint8_t res_heat_range;
	int8_t res_heat_val;
	int8_t range_sw_err;
};

class bme680{
    public:
        bme680(int8_t cspin);
        boolean begin();
        void performReading(); //Blocking
        void hexFinder();

        float temperature;
        uint32_t pressure;
        float humidity;
    private:
        int8_t _cs;
        bme680_calib_data calib_data;
        void getCalibration();
        byte readRegister(byte address);
        void writeRegister(byte reg_addr, byte reg_data);

};
#endif