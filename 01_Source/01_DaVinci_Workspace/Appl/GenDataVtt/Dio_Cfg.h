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
 *            Module: VTTDio
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dio_Cfg.h
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

#if !defined DIO_CFG_H
#define DIO_CFG_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
#define DIO_CFG_MAJOR_VERSION    (4u) 
#define DIO_CFG_MINOR_VERSION    (1u) 
#define DIO_CFG_PATCH_VERSION    (0u) 

/* generation of DIO_DEV_ERROR_DETECT  and DIO_DEV_ERROR_REPORT */
#ifndef DIO_DEV_ERROR_DETECT
#define DIO_DEV_ERROR_DETECT STD_ON
#endif
#ifndef DIO_DEV_ERROR_REPORT
#define DIO_DEV_ERROR_REPORT STD_ON
#endif


#define DIO_VERSION_INFO_API        (STD_OFF)
#define DIO_FLIP_CHANNEL_API        (STD_ON)

/**********************************************************************************************************************
 *  TYPE DEFINITIONS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DEFINES
 **********************************************************************************************************************/
#define DIO_MAX_CHANNEL_COUNT       (26U)
#define DIO_MAX_PORT_COUNT          (8U)
#define DIO_MAX_CHANNELGROUP_COUNT  (2U)

/********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 ********************************************************************************************************************/
/* Extern declarations of configuration instances */
#define DioConf_DioChannel_DIO_I_GPIO_EQ2    ((Dio_ChannelType) 0) 
#define DioConf_DioChannel_DIO_I_MC_LOW_VBAT    ((Dio_ChannelType) 1) 
#define DioConf_DioChannel_DIO_I_GPIO_EQ3    ((Dio_ChannelType) 2) 
#define DioConf_DioChannel_DIO_I_GPIO_EQ4    ((Dio_ChannelType) 3) 
#define DioConf_DioChannel_DIO_I_MC_FSH_ENA_FB    ((Dio_ChannelType) 4) 
#define DioConf_DioChannel_DIO_O_MC_FSH_ENA    ((Dio_ChannelType) 5) 
#define DioConf_DioChannel_DIO_I_EQ_ERROUT    ((Dio_ChannelType) 6) 
#define DioConf_DioChannel_DIO_O_IP_RESET    ((Dio_ChannelType) 7) 
#define DioConf_DioChannel_DIO_O_EQ_NTRST    ((Dio_ChannelType) 8) 
#define DioConf_DioChannel_DIO_I_MC_VER_0    ((Dio_ChannelType) 9) 
#define DioConf_DioChannel_DIO_I_MC_VER_1    ((Dio_ChannelType) 10) 
#define DioConf_DioChannel_DIO_I_MC_VER_2    ((Dio_ChannelType) 11) 
#define DioConf_DioChannel_DIO_I_MC_VER_6    ((Dio_ChannelType) 12) 
#define DioConf_DioChannel_DIO_I_MC_VER_4    ((Dio_ChannelType) 13) 
#define DioConf_DioChannel_DIO_I_MC_VER_5    ((Dio_ChannelType) 14) 
#define DioConf_DioChannel_DIO_I_MC_VER_3    ((Dio_ChannelType) 15) 
#define DioConf_DioChannel_DIO_O_MC_WDI    ((Dio_ChannelType) 16) 
#define DioConf_DioChannel_DIO_O_1V8_DIG_ENA    ((Dio_ChannelType) 17) 
#define DioConf_DioChannel_DIO_O_1V1_ENA    ((Dio_ChannelType) 18) 
#define DioConf_DioChannel_DIO_O_3V3_IP_ENA    ((Dio_ChannelType) 19) 
#define DioConf_DioChannel_DIO_O_1V0_ENA    ((Dio_ChannelType) 20) 
#define DioConf_DioChannel_UC_CAN2_STB    ((Dio_ChannelType) 21) 
#define DioConf_DioChannel_UC_CAN1_EN    ((Dio_ChannelType) 22) 
#define DioConf_DioChannel_UC_CAN1_STB    ((Dio_ChannelType) 23) 
#define DioConf_DioChannel_DIO_I_GPIO_EQ1    ((Dio_ChannelType) 24) 
#define DioConf_DioChannel_TP404    ((Dio_ChannelType) 25) 

#define DioConf_DioPort_DioPort_4    ((Dio_PortType) (0)) 
#define DioConf_DioPort_DioPort_1    ((Dio_PortType) (1)) 
#define DioConf_DioPort_DioPort_9    ((Dio_PortType) (2)) 
#define DioConf_DioPort_DioPort_0    ((Dio_PortType) (3)) 
#define DioConf_DioPort_DioPort_6    ((Dio_PortType) (4)) 
#define DioConf_DioPort_DioPort_2    ((Dio_PortType) (5)) 
#define DioConf_DioPort_DioPort_5    ((Dio_PortType) (6)) 
#define DioConf_DioPort_DioPort_7    ((Dio_PortType) (7)) 

#if (!defined DIO_PBCFG_SOURCE)
  extern P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) Dio_ChannelGroupArray[];
#endif

/* Dio development error handler */
#if (DIO_DEV_ERROR_REPORT == STD_ON)
  #include "Det.h"
  #define Dio_ReportDet(Dio_ServiceId, Dio_ErrorCode) \
    ( (void)Det_ReportError((DIO_MODULE_ID), (DIO_INSTANCE_ID), (Dio_ServiceId), (Dio_ErrorCode)) )
#else
  /* development error reporting is disabled, don't use Det's reporting function */
  #define Dio_ReportDet(Dio_ServiceId, Dio_ErrorCode)
#endif

#define Dio_Init(x) Dio_Init_Vtt(&DioConfig_0)

extern CONST(Dio_ConfigType, DIO_APPL_CONST) DioConfig_0;

#endif  /* DIO_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio_Cfg.h
 **********************************************************************************************************************/
