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
 *            Module: VTTPort
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Port_Cfg.h
 *   Generation Time: 2019-11-13 15:54:52
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

#if !defined PORT_CFG_H
#define PORT_CFG_H

/*********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PORT_CFG_MAJOR_VERSION    (4U) 
#define PORT_CFG_MINOR_VERSION    (1U) 
#define PORT_CFG_PATCH_VERSION    (0U) 


/**********************************************************************************************************************
 *  Start - Configuration class PreCompile (public part of configuration)
 **********************************************************************************************************************/
/* Compiler switches for API enabling */
/* static config parameters */
#define PORT_SET_PIN_DIRECTION_API           (STD_ON) 
#define PORT_VERSION_INFO_API                (STD_OFF)           
#define PORT_SET_PIN_MODE_API                (STD_ON)          

/* generation of PORT_DEV_ERROR_DETECT  and PORT_DEV_ERROR_REPORT */
#ifndef PORT_DEV_ERROR_DETECT
#define PORT_DEV_ERROR_DETECT STD_ON
#endif
#ifndef PORT_DEV_ERROR_REPORT
#define PORT_DEV_ERROR_REPORT STD_ON
#endif   
 

#if (STD_ON == PORT_DEV_ERROR_REPORT)
  #include "Det.h"
  #define Port_Errorhook(Port_FunctionId, Port_ErrorCode) \
    ( (void)Det_ReportError((PORT_MODULE_ID),(PORT_INSTANCE_ID), (Port_FunctionId), (Port_ErrorCode)) )
#else 
  #define Port_Errorhook(Port_FunctionId, Port_ErrorCode)
#endif  /* (STD_ON == PORT_DEV_ERROR_REPORT) */

#define Port_Init(x) Port_Init_Vtt(&PortConfigSet_0)


/**********************************************************************************************************************
 *  TYPE DEFINITIONS
 **********************************************************************************************************************/
/* Configuration structure of the Port */
typedef struct
{
  uint8 Port_CurrNoOfRefreshCfg_u8;
  uint8 Port_CurrNoOfPinChannelCfg_u8;
#if (STD_ON == PORT_SET_PIN_DIRECTION_API)
  P2CONST(uint8, AUTOMATIC, PORT_APPL_CONST) PinDirectionChangeable_pt;
#endif /* (STD_ON == PORT_SET_PIN_DIRECTION_API) */
} Port_ConfigType;


/**********************************************************************************************************************
 * INCLUDES AFTER TYPE DEFINITIONS
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  Start - Configuration class PostBuild (public part of configuration)
 **********************************************************************************************************************/
/* List of symbolic names for Dio pin channels */
#define PortConf_PortPin_PortPin  (0u) 


#if !defined PORT_PBCFG_SOURCE
  /* Extern declarations of configuration instances */
  extern CONST(Port_ConfigType, PORT_APPL_CONST) PortConfigSet_0; 

#endif /* !defined PORT_PBCFG_SOURCE */

#endif !defined PORT_CFG_H


/*********************************************************************************************************************
 *  END OF FILE: Port_Cfg.h
 *********************************************************************************************************************/
