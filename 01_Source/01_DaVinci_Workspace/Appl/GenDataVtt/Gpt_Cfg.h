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
 *            Module: VTTGpt
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Gpt_Cfg.h
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

#if !defined GPT_CFG_H
#define GPT_CFG_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define GPT_CFG_MAJOR_VERSION    (4U) 
#define GPT_CFG_MINOR_VERSION    (3U) 
#define GPT_CFG_PATCH_VERSION    (0U) 


/**********************************************************************************************************************
 *  Start - Configuration class PreCompile (public part of configuration)
 **********************************************************************************************************************/
/* Compiler switches for API enabling */
/* static config parameters */
#define GPT_VERSION_INFO_API                 (STD_OFF)    /* Include the GptVersionInfo */ 
#define GPT_DEINIT_API                       (STD_OFF)    /* Include the Gpt_DeInit */ 
#define GPT_TIME_ELAPSED_API                 (STD_ON)    /*Include the Gpt_GetTimeElapsed */ 
#define GPT_TIME_REMAINING_API               (STD_ON)    /* Include the Gpt_GetTimeRemaining */ 
#define GPT_ENABLE_DISABLE_NOTIFICATION_API  (STD_OFF)    /* Include the Gpt_Enable/Disible Notification */ 
#define GPT_WAKEUP_FUNCTIONALITY_API         (STD_OFF)    /* Include the wakeup functionality */ 


/* generation of GPT_DEV_ERROR_DETECT  and GPT_DEV_ERROR_REPORT */
#ifndef GPT_DEV_ERROR_DETECT
#define GPT_DEV_ERROR_DETECT STD_ON
#endif
#ifndef GPT_DEV_ERROR_REPORT
#define GPT_DEV_ERROR_REPORT STD_ON
#endif


/* Gpt development error handler */
#if (STD_ON == GPT_DEV_ERROR_REPORT)
  #include "Det.h"
  #define Gpt_Errorhook(Gpt_FunctionId, Gpt_ErrorCode) \
    ( (void) Det_ReportError ((GPT_MODULE_ID), (GPT_INSTANCE_ID), (Gpt_FunctionId), (Gpt_ErrorCode)) )
#else
    #define Gpt_Errorhook(Gpt_FunctionId, Gpt_ErrorCode)
#endif /* (STD_ON == GPT_DEV_ERROR_REPORT) */

#if (STD_ON == GPT_WAKEUP_FUNCTIONALITY_API)
  /* Enable reporting of wake up events to EcuM */
  #define GPT_REPORT_WAKEUP_SOURCE           (STD_OFF)    
  
  #if (STD_ON == GPT_REPORT_WAKEUP_SOURCE)
    /* The global wake-up definition */
    #include "Ecum_Cbk.h"
  #endif
#else
  #define GPT_REPORT_WAKEUP_SOURCE           (STD_OFF)     
#endif

#define Gpt_Init(x) Gpt_Init_Vtt(&GptChannelConfigSet_0)


/**********************************************************************************************************************
 *  TYPE DEFINITIONS
 **********************************************************************************************************************/
/* Channel configuration structure */
typedef struct
{
  uint32 TimerValue_u32;                          /* Timer Value for the user in Microseconds        */
  uint8  TimerActive_u8;                          /* Indicates whether the Timer is active or not    */
  uint8  NotificationEnabled_u8;                  /* Indicates if Notification Capability is enabled */
  Gpt_ChannelModeType ChannelMode;                /* Channel Mode - Continuous or OneShot            */
  Gpt_NotifyType Gpt_Notification_pt;             /* Pointer to Notification Function                */
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
  uint8 WakeupCapable_u8;                         /* Indicates if Channel is Wakeup Capable          */
  uint8 WakeupEnabled_u8;                         /* Indicates if Wakeup if enabled for the Channel  */
  #if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
    uint32 WakeupEvent_u32;                       /* Holds the Wakeup Event is Wakeup occurs         */
  #endif
#endif
} Gpt_ChannelConfigType;

/* global runtime configuration structure */
typedef struct
{
  P2VAR(Gpt_ChannelConfigType, AUTOMATIC, GPT_APPL_DATA) Channels; /* Array of configured channels   */
  CONST(uint8, GPT_APPL_CONST) ChannelQuantity_u8;                 /* Number of configured channels  */
} Gpt_ConfigType;


/**********************************************************************************************************************
 * Notification prototypes
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  Start - Configuration class PostBuild (public part of configuration)
 **********************************************************************************************************************/
/* symbolic names are specified by the configuration tool */
#define GptConf_GptChannelConfiguration_FreeRunning_Timer_2us  (0u) 



#if !defined GPT_PBCFG_SOURCE
  /* Extern declarations of configuration instances */
  extern CONST(Gpt_ConfigType, GPT_APPL_CONST) GptChannelConfigSet_0; 

#endif


#endif /* !defined GPT_CFG_H */


/*********************************************************************************************************************
 *  END OF FILE: Gpt_Cfg.h
 *********************************************************************************************************************/
