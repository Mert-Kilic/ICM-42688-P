/*
 * icm.c
 *
 *  Created on: Dec 22, 2020
 *      Author: Mert Kilic
 */
#include "icm.h"
#include "main.h"

extern I2C_HandleTypeDef hi2c1;

uint8_t fifo_data[16];

uint8_t  acc_data_X1;
uint8_t  acc_data_X0;
extern	uint16_t acc_data_X;

uint8_t  acc_data_Y1;
uint8_t  acc_data_Y0;
extern	uint16_t acc_data_Y;

uint8_t  acc_data_Z1;
uint8_t  acc_data_Z0;
extern	uint16_t acc_data_Z;

uint8_t  gyro_data_X1;
uint8_t  gyro_data_X0;
extern	uint16_t gyro_data_X;

uint8_t  gyro_data_Y1;
uint8_t  gyro_data_Y0;
extern	uint16_t gyro_data_Y;

uint8_t  gyro_data_Z1;
uint8_t  gyro_data_Z0;
extern	uint16_t gyro_data_Z;



void icm_initialize(){
	uint8_t configure_reset = 0x01;
	uint8_t fifo_conf_data = 0x03;
	uint8_t buffer = 0x1F; //  temperature sensor enabled. RC oscillator is on, gyro and accelerometer low noise mode,
	uint8_t fifo_init = 0x40;

	HAL_I2C_Mem_Write(&hi2c1, device_address, DEVICE_CONFIG, 1, &configure_reset, 1, 100);
	HAL_Delay(100);

	HAL_I2C_Mem_Write(&hi2c1, device_address, power_mgmt, 1, &buffer, 1, 100);
	HAL_Delay(100);

	HAL_I2C_Mem_Write(&hi2c1, device_address, FIFO_CONFIG_INIT, 1, &fifo_init, 1, 100);
	HAL_I2C_Mem_Write(&hi2c1, device_address, FIFO_CONFIGURATION, 1, &fifo_conf_data, 1, 100);
	HAL_Delay(100);
}


void read_values(){

	HAL_I2C_Mem_Read(&hi2c1, device_address, FIFO_DATA_REG,1,fifo_data,16,100);

	  acc_data_X1 = fifo_data[1];
	  acc_data_X0 = fifo_data[2];
	  acc_data_X = (acc_data_X1<<8) | acc_data_X0;

	  acc_data_Y1 = fifo_data[3];
	  acc_data_Y0 = fifo_data[4];
	  acc_data_Y = (acc_data_Y1<<8) | acc_data_Y0;

	  acc_data_Z1 = fifo_data[5];
	  acc_data_Z0 = fifo_data[6];
	  acc_data_Z = (acc_data_Z1<<8) | acc_data_Z0;

	  gyro_data_X1 = fifo_data[7];
	  gyro_data_X0 = fifo_data[8];
	  gyro_data_X = (gyro_data_X1<<8) | gyro_data_X0;

	  gyro_data_Y1 = fifo_data[9];
	  gyro_data_Y0 = fifo_data[10];
	  gyro_data_Y = (gyro_data_Y1<<8) | gyro_data_Y0;

	  gyro_data_Z1 = fifo_data[11];
	  gyro_data_Z0 = fifo_data[12];
	  gyro_data_Z = (gyro_data_Z1<<8) | gyro_data_Z0;


}
