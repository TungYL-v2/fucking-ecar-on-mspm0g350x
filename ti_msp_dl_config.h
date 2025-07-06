/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)


#define CPUCLK_FREQ                                                     32000000



/* Defines for PWM_motor */
#define PWM_motor_INST                                                     TIMG0
#define PWM_motor_INST_IRQHandler                               TIMG0_IRQHandler
#define PWM_motor_INST_INT_IRQN                                 (TIMG0_INT_IRQn)
#define PWM_motor_INST_CLK_FREQ                                           125000
/* GPIO defines for channel 0 */
#define GPIO_PWM_motor_C0_PORT                                             GPIOA
#define GPIO_PWM_motor_C0_PIN                                     DL_GPIO_PIN_12
#define GPIO_PWM_motor_C0_IOMUX                                  (IOMUX_PINCM34)
#define GPIO_PWM_motor_C0_IOMUX_FUNC                 IOMUX_PINCM34_PF_TIMG0_CCP0
#define GPIO_PWM_motor_C0_IDX                                DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_motor_C1_PORT                                             GPIOA
#define GPIO_PWM_motor_C1_PIN                                     DL_GPIO_PIN_13
#define GPIO_PWM_motor_C1_IOMUX                                  (IOMUX_PINCM35)
#define GPIO_PWM_motor_C1_IOMUX_FUNC                 IOMUX_PINCM35_PF_TIMG0_CCP1
#define GPIO_PWM_motor_C1_IDX                                DL_TIMER_CC_1_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMA1)
#define TIMER_0_INST_IRQHandler                                 TIMA1_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMA1_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                         (12499U)
/* Defines for TIMER_1 */
#define TIMER_1_INST                                                     (TIMA0)
#define TIMER_1_INST_IRQHandler                                 TIMA0_IRQHandler
#define TIMER_1_INST_INT_IRQN                                   (TIMA0_INT_IRQn)
#define TIMER_1_INST_LOAD_VALUE                                             (0U)




/* Defines for I2C_0 */
#define I2C_0_INST                                                          I2C0
#define I2C_0_INST_IRQHandler                                    I2C0_IRQHandler
#define I2C_0_INST_INT_IRQN                                        I2C0_INT_IRQn
#define GPIO_I2C_0_SDA_PORT                                                GPIOA
#define GPIO_I2C_0_SDA_PIN                                         DL_GPIO_PIN_0
#define GPIO_I2C_0_IOMUX_SDA                                      (IOMUX_PINCM1)
#define GPIO_I2C_0_IOMUX_SDA_FUNC                       IOMUX_PINCM1_PF_I2C0_SDA
#define GPIO_I2C_0_SCL_PORT                                                GPIOA
#define GPIO_I2C_0_SCL_PIN                                         DL_GPIO_PIN_1
#define GPIO_I2C_0_IOMUX_SCL                                      (IOMUX_PINCM2)
#define GPIO_I2C_0_IOMUX_SCL_FUNC                       IOMUX_PINCM2_PF_I2C0_SCL



/* Defines for PIN_1: GPIOA.28 with pinCMx 3 on package pin 3 */
#define track_PIN_1_PORT                                                 (GPIOA)
#define track_PIN_1_PIN                                         (DL_GPIO_PIN_28)
#define track_PIN_1_IOMUX                                         (IOMUX_PINCM3)
/* Defines for PIN_2: GPIOA.31 with pinCMx 6 on package pin 5 */
#define track_PIN_2_PORT                                                 (GPIOA)
#define track_PIN_2_PIN                                         (DL_GPIO_PIN_31)
#define track_PIN_2_IOMUX                                         (IOMUX_PINCM6)
/* Defines for PIN_3: GPIOA.2 with pinCMx 7 on package pin 8 */
#define track_PIN_3_PORT                                                 (GPIOA)
#define track_PIN_3_PIN                                          (DL_GPIO_PIN_2)
#define track_PIN_3_IOMUX                                         (IOMUX_PINCM7)
/* Defines for PIN_4: GPIOA.3 with pinCMx 8 on package pin 9 */
#define track_PIN_4_PORT                                                 (GPIOA)
#define track_PIN_4_PIN                                          (DL_GPIO_PIN_3)
#define track_PIN_4_IOMUX                                         (IOMUX_PINCM8)
/* Defines for PIN_5: GPIOA.4 with pinCMx 9 on package pin 10 */
#define track_PIN_5_PORT                                                 (GPIOA)
#define track_PIN_5_PIN                                          (DL_GPIO_PIN_4)
#define track_PIN_5_IOMUX                                         (IOMUX_PINCM9)
/* Defines for PIN_6: GPIOA.5 with pinCMx 10 on package pin 11 */
#define track_PIN_6_PORT                                                 (GPIOA)
#define track_PIN_6_PIN                                          (DL_GPIO_PIN_5)
#define track_PIN_6_IOMUX                                        (IOMUX_PINCM10)
/* Defines for PIN_7: GPIOB.2 with pinCMx 15 on package pin 14 */
#define track_PIN_7_PORT                                                 (GPIOB)
#define track_PIN_7_PIN                                          (DL_GPIO_PIN_2)
#define track_PIN_7_IOMUX                                        (IOMUX_PINCM15)
/* Defines for PIN_8: GPIOB.3 with pinCMx 16 on package pin 15 */
#define track_PIN_8_PORT                                                 (GPIOB)
#define track_PIN_8_PIN                                          (DL_GPIO_PIN_3)
#define track_PIN_8_IOMUX                                        (IOMUX_PINCM16)
/* Defines for AIN1: GPIOA.8 with pinCMx 19 on package pin 16 */
#define motor_AIN1_PORT                                                  (GPIOA)
#define motor_AIN1_PIN                                           (DL_GPIO_PIN_8)
#define motor_AIN1_IOMUX                                         (IOMUX_PINCM19)
/* Defines for AIN2: GPIOA.9 with pinCMx 20 on package pin 17 */
#define motor_AIN2_PORT                                                  (GPIOA)
#define motor_AIN2_PIN                                           (DL_GPIO_PIN_9)
#define motor_AIN2_IOMUX                                         (IOMUX_PINCM20)
/* Defines for BIN1: GPIOA.10 with pinCMx 21 on package pin 18 */
#define motor_BIN1_PORT                                                  (GPIOA)
#define motor_BIN1_PIN                                          (DL_GPIO_PIN_10)
#define motor_BIN1_IOMUX                                         (IOMUX_PINCM21)
/* Defines for BIN2: GPIOA.11 with pinCMx 22 on package pin 19 */
#define motor_BIN2_PORT                                                  (GPIOA)
#define motor_BIN2_PIN                                          (DL_GPIO_PIN_11)
#define motor_BIN2_IOMUX                                         (IOMUX_PINCM22)
/* Defines for E1A: GPIOA.7 with pinCMx 14 on package pin 13 */
#define motor_E1A_PORT                                                   (GPIOA)
// pins affected by this interrupt request:["E1A","E2A"]
#define motor_INT_IRQN                                          (GPIOA_INT_IRQn)
#define motor_INT_IIDX                          (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define motor_E1A_IIDX                                       (DL_GPIO_IIDX_DIO7)
#define motor_E1A_PIN                                            (DL_GPIO_PIN_7)
#define motor_E1A_IOMUX                                          (IOMUX_PINCM14)
/* Defines for E2A: GPIOA.6 with pinCMx 11 on package pin 12 */
#define motor_E2A_PORT                                                   (GPIOA)
#define motor_E2A_IIDX                                       (DL_GPIO_IIDX_DIO6)
#define motor_E2A_PIN                                            (DL_GPIO_PIN_6)
#define motor_E2A_IOMUX                                          (IOMUX_PINCM11)
/* Defines for E1B: GPIOB.6 with pinCMx 23 on package pin 20 */
#define motor_E1B_PORT                                                   (GPIOB)
#define motor_E1B_PIN                                            (DL_GPIO_PIN_6)
#define motor_E1B_IOMUX                                          (IOMUX_PINCM23)
/* Defines for E2B: GPIOB.7 with pinCMx 24 on package pin 21 */
#define motor_E2B_PORT                                                   (GPIOB)
#define motor_E2B_PIN                                            (DL_GPIO_PIN_7)
#define motor_E2B_IOMUX                                          (IOMUX_PINCM24)

/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_motor_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_TIMER_1_init(void);
void SYSCFG_DL_I2C_0_init(void);


bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
