#ifndef ML_I2C_H
#define ML_I2C_H

#include "ti_msp_dl_config.h"
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>


void I2C_Write(uint8_t devAddr, uint8_t reg, uint8_t *data, uint16_t len);
void I2C_Read(uint8_t devAddr, uint8_t reg, uint8_t *data, uint16_t len);
void I2C_Init(void);

#endif // ML_I2C_H
