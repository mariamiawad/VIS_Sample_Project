/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: VTTMcu
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Mcu_Cfg.h
 *   Generation Time: 2019-11-13 15:54:53
 *           Project: Bootcamp - Version 1.0
 *          Delivery: CBD1500710_D05
 *      Tool Version: DaVinci Configurator (beta) 5.16.27
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! These programs are fully operative programs. With regard to the fact that the programs are a beta-version only,    !
 ! Vector Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent           !
 ! admissible by law or statute.                                                                                      !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

#if !defined MCU_CFG_H
#define MCU_CFG_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define MCU_CFG_MAJOR_VERSION    (4U) 
#define MCU_CFG_MINOR_VERSION    (2U) 
#define MCU_CFG_PATCH_VERSION    (0U) 


/**********************************************************************************************************************
 *  Start - Configuration class PreCompile (public part of configuration)
 **********************************************************************************************************************/
/* Compiler switches for API enabling */
/* static config parameters */
#define MCU_VERSION_INFO_API          (STD_OFF) 
#define MCU_GET_RAM_STATE_API         (STD_OFF)
#define MCU_PERFORM_RESET_API         (STD_ON)
#define MCU_INIT_CLOCK                (STD_ON)
#define MCU_NO_PLL                    (STD_OFF)

/* generation of MCU_DEV_ERROR_DETECT  and MCU_DEV_ERROR_REPORT */
#ifndef MCU_DEV_ERROR_DETECT
#define MCU_DEV_ERROR_DETECT STD_ON
#endif
#ifndef MCU_DEV_ERROR_REPORT
#define MCU_DEV_ERROR_REPORT STD_ON
#endif

/**********************************************************************************************************************
 *  Settings for Development Mode
 *********************************************************************************************************************/
#if (STD_ON == MCU_DEV_ERROR_REPORT)
  #include "Det.h"
  #define Mcu_Errorhook(Mcu_FunctionId, Mcu_ErrorCode) \
    ( (void) Det_ReportError ((MCU_MODULE_ID), (MCU_INSTANCE_ID), (Mcu_FunctionId), (Mcu_ErrorCode)) )
#else
  #define Mcu_Errorhook(Mcu_FunctionId, Mcu_ErrorCode)
#endif /* (STD_ON == MCU_DEV_ERROR_REPORT) */

#define Mcu_Init(x) Mcu_Init_Vtt(&McuModuleConfiguration)


/**********************************************************************************************************************
 *  TYPE DEFINITIONS
 **********************************************************************************************************************/


/**********************************************************************************************************************
 * INCLUDES AFTER TYPE DEFINITIONS
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  Start - Configuration class PostBuild (public part of configuration)
 **********************************************************************************************************************/
/* Symbolic Name Values  of the symbolic names of Mcu modes */
#define McuConf_McuModeSettingConf_NORMAL              (0u) 
#define McuConf_McuModeSettingConf_RESET               (2u) 
#define McuConf_McuModeSettingConf_SLEEP               (1u) 
#define McuConf_McuModeSettingConf_POWER_OFF           (3u) 
#define McuConf_McuModeSettingConf_McuModeSettingConf0 (1u) 
 

/* Highest number of all configured McuModes */
#define MCU_HIGHEST_MODE_NUMBER (3u)

/* Symbolic Name Values of RAM sections */
#define McuRamSectorSettingConf_0 (0u) 
 

/* Symbolic Name Values of Mcu clocks */
#define McuConf_McuClockSettingConfig_McuClockSettingConfig  (0u) 
#define McuConf_McuClockSettingConfig_McuClockSettingConfig0 (1u) 
 

/* Symbolic Name Values  of the reset reasons */
#define McuConf_McuResetReasonConf_McuResetReasonConf (0u) 
 

#if !defined MCU_PBCFG_SOURCE
  /* Extern declarations of configuration instances */
  extern CONST(Mcu_ConfigType, MCU_APPL_CONST) McuModuleConfiguration; 
  extern CONST(Mcu_ConfigType, MCU_APPL_CONST) McuModuleConfiguration_0; 
  
#endif /* !defined MCU_PBCFG_SOURCE */


#endif /* !defined MCU_CFG_H */


/*********************************************************************************************************************
 *  END OF FILE: Mcu_Cfg.h
 *********************************************************************************************************************/
 
