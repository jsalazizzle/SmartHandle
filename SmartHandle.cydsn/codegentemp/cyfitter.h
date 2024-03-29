/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.2
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cy_device_headers.h"
#include "cyfitter_gpio.h"
#include "cyfitter_sysint.h"

/* MCWDT */
#define MCWDT_MCWDT__HW MCWDT_STRUCT0
#define MCWDT_MCWDT__IDX 0

/* CO_CLK */
#define CO_CLK__DIV_IDX 6
#define CO_CLK__DIV_NUM 6
#define CO_CLK__DIV_TYPE CY_SYSCLK_DIV_8_BIT

/* CT_CLK */
#define CT_CLK__DIV_IDX 9
#define CT_CLK__DIV_NUM 1
#define CT_CLK__DIV_TYPE CY_SYSCLK_DIV_16_BIT

/* LT_CLK */
#define LT_CLK__DIV_IDX 10
#define LT_CLK__DIV_NUM 2
#define LT_CLK__DIV_TYPE CY_SYSCLK_DIV_16_BIT

/* MT_CLK */
#define MT_CLK__DIV_IDX 8
#define MT_CLK__DIV_NUM 0
#define MT_CLK__DIV_TYPE CY_SYSCLK_DIV_16_BIT

/* Clock_B */
#define Clock_B__DIV_IDX 1
#define Clock_B__DIV_NUM 1
#define Clock_B__DIV_TYPE CY_SYSCLK_DIV_8_BIT

/* Clock_G */
#define Clock_G__DIV_IDX 2
#define Clock_G__DIV_NUM 2
#define Clock_G__DIV_TYPE CY_SYSCLK_DIV_8_BIT

/* Clock_M */
#define Clock_M__DIV_IDX 3
#define Clock_M__DIV_NUM 3
#define Clock_M__DIV_TYPE CY_SYSCLK_DIV_8_BIT

/* Clock_R */
#define Clock_R__DIV_IDX 0
#define Clock_R__DIV_NUM 0
#define Clock_R__DIV_TYPE CY_SYSCLK_DIV_8_BIT

/* Bluetooth */
#define Bluetooth_cy_mxs40_ble__HW BLE
#define Bluetooth_cy_mxs40_ble__IDX 0

/* SensorBus */
#define SensorBus_SCB__HW SCB6
#define SensorBus_SCB__IDX 6
#define SensorBus_SCB__SS0_POSITION 0u
#define SensorBus_SCB__SS1_POSITION 1u
#define SensorBus_SCB__SS2_POSITION 2u
#define SensorBus_SCB__SS3_POSITION 3u
#define SensorBus_SCBCLK__DIV_IDX 4
#define SensorBus_SCBCLK__DIV_NUM 4
#define SensorBus_SCBCLK__DIV_TYPE CY_SYSCLK_DIV_8_BIT

/* ChimeTimer */
#define ChimeTimer_TCPWM__CNT_HW TCPWM0_CNT5
#define ChimeTimer_TCPWM__CNT_IDX 5u
#define ChimeTimer_TCPWM__HW TCPWM0
#define ChimeTimer_TCPWM__IDX 0u

/* LightTimer */
#define LightTimer_TCPWM__CNT_HW TCPWM0_CNT3
#define LightTimer_TCPWM__CNT_IDX 3u
#define LightTimer_TCPWM__HW TCPWM0
#define LightTimer_TCPWM__IDX 0u

/* MotorTimer */
#define MotorTimer_TCPWM__CNT_HW TCPWM0_CNT6
#define MotorTimer_TCPWM__CNT_IDX 6u
#define MotorTimer_TCPWM__HW TCPWM0
#define MotorTimer_TCPWM__IDX 0u

/* UART_DEBUG */
#define UART_DEBUG_SCB__HW SCB5
#define UART_DEBUG_SCB__IDX 5
#define UART_DEBUG_SCB__SS0_POSITION 0u
#define UART_DEBUG_SCB__SS1_POSITION 1u
#define UART_DEBUG_SCB__SS2_POSITION 2u
#define UART_DEBUG_SCB__SS3_POSITION 3u
#define UART_DEBUG_SCBCLK__DIV_IDX 5
#define UART_DEBUG_SCBCLK__DIV_NUM 5
#define UART_DEBUG_SCBCLK__DIV_TYPE CY_SYSCLK_DIV_8_BIT

/* ChimeOutput */
#define ChimeOutput_TCPWM__CNT_HW TCPWM1_CNT2
#define ChimeOutput_TCPWM__CNT_IDX 2u
#define ChimeOutput_TCPWM__HW TCPWM1
#define ChimeOutput_TCPWM__IDX 1u

/* MotorOutput */
#define MotorOutput_TCPWM__CNT_HW TCPWM0_CNT4
#define MotorOutput_TCPWM__CNT_IDX 4u
#define MotorOutput_TCPWM__HW TCPWM0
#define MotorOutput_TCPWM__IDX 0u

/* LightOutputA */
#define LightOutputA_TCPWM__CNT_HW TCPWM0_CNT1
#define LightOutputA_TCPWM__CNT_IDX 1u
#define LightOutputA_TCPWM__HW TCPWM0
#define LightOutputA_TCPWM__IDX 0u

/* LightOutputB */
#define LightOutputB_TCPWM__CNT_HW TCPWM0_CNT2
#define LightOutputB_TCPWM__CNT_IDX 2u
#define LightOutputB_TCPWM__HW TCPWM0
#define LightOutputB_TCPWM__IDX 0u

/* LightOutputC */
#define LightOutputC_TCPWM__CNT_HW TCPWM0_CNT0
#define LightOutputC_TCPWM__CNT_IDX 0u
#define LightOutputC_TCPWM__HW TCPWM0
#define LightOutputC_TCPWM__IDX 0u

/* Miscellaneous */
#define CPUSS__CTI_TR_IN_0 TRIG5_OUT_CPUSS_CTI_TR_IN0
#define CPUSS__CTI_TR_IN_1 TRIG5_OUT_CPUSS_CTI_TR_IN1
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_DRIVEMODE CY_GPIO_DM_PULLDOWN
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_INBUF_ENABLED 1u
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_INIT_DRIVESTATE 0u
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_INIT_MUXSEL 29u
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_INPUT_SYNC 2u
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_NUM 7u
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_PORT GPIO_PRT6
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_SLEWRATE CY_GPIO_SLEW_FAST
#define CY_CPUSS_SWJ_SWCLK_TCLK_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define CY_CPUSS_SWJ_SWCLK_TCLK_DRIVEMODE CY_GPIO_DM_PULLDOWN
#define CY_CPUSS_SWJ_SWCLK_TCLK_INBUF_ENABLED 1u
#define CY_CPUSS_SWJ_SWCLK_TCLK_INIT_DRIVESTATE 0u
#define CY_CPUSS_SWJ_SWCLK_TCLK_INIT_MUXSEL 29u
#define CY_CPUSS_SWJ_SWCLK_TCLK_INPUT_SYNC 2u
#define CY_CPUSS_SWJ_SWCLK_TCLK_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CY_CPUSS_SWJ_SWCLK_TCLK_NUM 7u
#define CY_CPUSS_SWJ_SWCLK_TCLK_PORT GPIO_PRT6
#define CY_CPUSS_SWJ_SWCLK_TCLK_SLEWRATE CY_GPIO_SLEW_FAST
#define CY_CPUSS_SWJ_SWCLK_TCLK_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define CY_CPUSS_SWJ_SWDIO_TMS_0_DRIVEMODE CY_GPIO_DM_PULLUP
#define CY_CPUSS_SWJ_SWDIO_TMS_0_INBUF_ENABLED 1u
#define CY_CPUSS_SWJ_SWDIO_TMS_0_INIT_DRIVESTATE 0u
#define CY_CPUSS_SWJ_SWDIO_TMS_0_INIT_MUXSEL 29u
#define CY_CPUSS_SWJ_SWDIO_TMS_0_INPUT_SYNC 2u
#define CY_CPUSS_SWJ_SWDIO_TMS_0_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CY_CPUSS_SWJ_SWDIO_TMS_0_NUM 6u
#define CY_CPUSS_SWJ_SWDIO_TMS_0_PORT GPIO_PRT6
#define CY_CPUSS_SWJ_SWDIO_TMS_0_SLEWRATE CY_GPIO_SLEW_FAST
#define CY_CPUSS_SWJ_SWDIO_TMS_0_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define CY_CPUSS_SWJ_SWDIO_TMS_DRIVEMODE CY_GPIO_DM_PULLUP
#define CY_CPUSS_SWJ_SWDIO_TMS_INBUF_ENABLED 1u
#define CY_CPUSS_SWJ_SWDIO_TMS_INIT_DRIVESTATE 0u
#define CY_CPUSS_SWJ_SWDIO_TMS_INIT_MUXSEL 29u
#define CY_CPUSS_SWJ_SWDIO_TMS_INPUT_SYNC 2u
#define CY_CPUSS_SWJ_SWDIO_TMS_INTERRUPT_MODE CY_GPIO_INTR_DISABLE
#define CY_CPUSS_SWJ_SWDIO_TMS_NUM 6u
#define CY_CPUSS_SWJ_SWDIO_TMS_PORT GPIO_PRT6
#define CY_CPUSS_SWJ_SWDIO_TMS_SLEWRATE CY_GPIO_SLEW_FAST
#define CY_CPUSS_SWJ_SWDIO_TMS_THRESHOLD_LEVEL CY_GPIO_VTRIP_CMOS
#define CY_PROJECT_NAME "SmartHandle"
#define CY_VERSION "PSoC Creator  4.2"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 21u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC6
#define CYDEV_CHIP_JTAG_ID 0xE2F02100u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 21u
#define CYDEV_CHIP_MEMBER_4D 16u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 22u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 20u
#define CYDEV_CHIP_MEMBER_4I 26u
#define CYDEV_CHIP_MEMBER_4J 17u
#define CYDEV_CHIP_MEMBER_4K 18u
#define CYDEV_CHIP_MEMBER_4L 25u
#define CYDEV_CHIP_MEMBER_4M 24u
#define CYDEV_CHIP_MEMBER_4N 11u
#define CYDEV_CHIP_MEMBER_4O 8u
#define CYDEV_CHIP_MEMBER_4P 23u
#define CYDEV_CHIP_MEMBER_4Q 14u
#define CYDEV_CHIP_MEMBER_4R 9u
#define CYDEV_CHIP_MEMBER_4S 12u
#define CYDEV_CHIP_MEMBER_4T 10u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 19u
#define CYDEV_CHIP_MEMBER_4W 13u
#define CYDEV_CHIP_MEMBER_4X 7u
#define CYDEV_CHIP_MEMBER_4Y 15u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 27u
#define CYDEV_CHIP_MEMBER_FM3 31u
#define CYDEV_CHIP_MEMBER_FM4 32u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 28u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 29u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 30u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_6A
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4T_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4V_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4W_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4X_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_ES 17u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 33u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 33u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_6A_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CLK_ALTSYSTICKCLK__HZ 32768U
#define CYDEV_CLK_ALTSYSTICKCLK__KHZ 32U
#define CYDEV_CLK_ALTSYSTICKCLK__MHZ 0U
#define CYDEV_CLK_BAKCLK__HZ 32768U
#define CYDEV_CLK_BAKCLK__KHZ 32U
#define CYDEV_CLK_BAKCLK__MHZ 0U
#define CYDEV_CLK_FASTCLK__HZ 50000000U
#define CYDEV_CLK_FASTCLK__KHZ 50000U
#define CYDEV_CLK_FASTCLK__MHZ 50U
#define CYDEV_CLK_FLL__HZ 50000000U
#define CYDEV_CLK_FLL__KHZ 50000U
#define CYDEV_CLK_FLL__MHZ 50U
#define CYDEV_CLK_HFCLK0__HZ 50000000U
#define CYDEV_CLK_HFCLK0__KHZ 50000U
#define CYDEV_CLK_HFCLK0__MHZ 50U
#define CYDEV_CLK_ILO__HZ 32000U
#define CYDEV_CLK_ILO__KHZ 32U
#define CYDEV_CLK_ILO__MHZ 0U
#define CYDEV_CLK_IMO__HZ 8000000U
#define CYDEV_CLK_IMO__KHZ 8000U
#define CYDEV_CLK_IMO__MHZ 8U
#define CYDEV_CLK_LFCLK__HZ 32768U
#define CYDEV_CLK_LFCLK__KHZ 32U
#define CYDEV_CLK_LFCLK__MHZ 0U
#define CYDEV_CLK_PATHMUX0__HZ 8000000U
#define CYDEV_CLK_PATHMUX0__KHZ 8000U
#define CYDEV_CLK_PATHMUX0__MHZ 8U
#define CYDEV_CLK_PATHMUX1__HZ 8000000U
#define CYDEV_CLK_PATHMUX1__KHZ 8000U
#define CYDEV_CLK_PATHMUX1__MHZ 8U
#define CYDEV_CLK_PATHMUX2__HZ 8000000U
#define CYDEV_CLK_PATHMUX2__KHZ 8000U
#define CYDEV_CLK_PATHMUX2__MHZ 8U
#define CYDEV_CLK_PATHMUX3__HZ 8000000U
#define CYDEV_CLK_PATHMUX3__KHZ 8000U
#define CYDEV_CLK_PATHMUX3__MHZ 8U
#define CYDEV_CLK_PATHMUX4__HZ 8000000U
#define CYDEV_CLK_PATHMUX4__KHZ 8000U
#define CYDEV_CLK_PATHMUX4__MHZ 8U
#define CYDEV_CLK_PERICLK__HZ 25000000U
#define CYDEV_CLK_PERICLK__KHZ 25000U
#define CYDEV_CLK_PERICLK__MHZ 25U
#define CYDEV_CLK_PILO__HZ 32768U
#define CYDEV_CLK_PILO__KHZ 32U
#define CYDEV_CLK_PILO__MHZ 0U
#define CYDEV_CLK_PUMPCLK__HZ 25000000U
#define CYDEV_CLK_PUMPCLK__KHZ 25000U
#define CYDEV_CLK_PUMPCLK__MHZ 25U
#define CYDEV_CLK_SLOWCLK__HZ 25000000U
#define CYDEV_CLK_SLOWCLK__KHZ 25000U
#define CYDEV_CLK_SLOWCLK__MHZ 25U
#define CYDEV_CLK_TIMERCLK__HZ 50000000U
#define CYDEV_CLK_TIMERCLK__KHZ 50000U
#define CYDEV_CLK_TIMERCLK__MHZ 50U
#define CYDEV_CONFIG_READ_ACCELERATOR 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_CORE_VOLTAGE CY_SYSPM_LDO_VOLTAGE_1_1V
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_ENABLE_SIMO_BUCK false
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PMIC_ENABLED 0
#define CYDEV_PMIC_MODE CYDEV_PMIC_MODE_DISABLED
#define CYDEV_POWER_MODE CYDEV_POWER_MODE_LDO_LINEAR_REG_1_1V
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_SYSTEM_AREF_CURRENT_HIGH 1
#define CYDEV_SYSTEM_AREF_CURRENT CYDEV_SYSTEM_AREF_CURRENT_HIGH
#define CYDEV_SYSTEM_AREF_CURRENT_LOW 0
#define CYDEV_SYSTEM_AREF_DEEPSLEEP 0
#define CYDEV_SYSTEM_AREF_SOURCE CY_SYSANALOG_VREF_SOURCE_LOCAL_1_2V
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VBAC_SUPPLY CYDEV_VBAC_SUPPLY_VDDD
#define CYDEV_VBACKUP 3.3
#define CYDEV_VBACKUP_MV 3300
#define CYDEV_VDD 3.3
#define CYDEV_VDD_MV 3300
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
