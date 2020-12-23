/*
 * icm.h
 *
 *  Created on: Dec 22, 2020
 *      Author: Mert Kilic
 */

#ifndef INC_ICM_H_
#define INC_ICM_H_

#define device_address 		0x68<<1
#define power_mgmt 			0x4E
#define DEVICE_CONFIG		0x11
#define DRIVE_CONFIG 		0x13
#define who_am_i			0x75
#define temp_data1			0x1D
#define temp_data0			0x1E
#define GYRO_CONFIG0		0x4F
#define ACCEL_CONFIG0		0x50
#define GYRO_CONFIG1		0x51
#define GYRO_ACCEL_CONFIG0	0x52
#define ACCEL_CONFIG1		0x53
#define XA_ST_DATA			0x3B
#define YA_ST_DATA			0x3C
#define ZA_ST_DATA			0x3D
#define BANK_SEL			0x76


#define ACCEL_DATA_X1		0x1F
#define ACCEL_DATA_X0		0x20

#define ACCEL_DATA_Y1		0x21
#define ACCEL_DATA_Y0		0x22

#define ACCEL_DATA_Z1		0x23
#define ACCEL_DATA_Z0		0x24

#define GYRO_DATA_X1		0x25
#define GYRO_DATA_X0		0x26

#define GYRO_DATA_Y1		0x27
#define GYRO_DATA_Y0		0x28

#define GYRO_DATA_Z1		0x29
#define GYRO_DATA_Z0		0x2A

#define FIFO_CONFIG_INIT	0x16
#define FIFO_CONFIGURATION	0x5F
#define FIFO_DATA_REG		0x30




void configure_device();
void icm_initialize();
void read_values();




#endif /* INC_ICM_H_ */
