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
 *            Module: VTTIcu
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Icu_Cfg.h
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


#if !defined ICU_CFG_H
#define ICU_CFG_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define ICU_CFG_MAJOR_VERSION    (3U) 
#define ICU_CFG_MINOR_VERSION    (3U) 
#define ICU_CFG_PATCH_VERSION    (0U) 


/**********************************************************************************************************************
 *  Start - Configuration class PreCompile (public part of configuration)
 **********************************************************************************************************************/
/* Compiler switches for API enabling */
/* static config parameters */
/* Main functionality API switches */
#define ICU_EDGE_COUNT_API                   (STD_ON)
#define ICU_TIMESTAMP_API                    (STD_ON)
#define ICU_EDGE_DETECT_API                  (STD_ON)
#define ICU_SIGNAL_MEASUREMENT_API           (STD_ON)

#if (STD_ON == ICU_SIGNAL_MEASUREMENT_API)
  #define ICU_GET_TIME_ELAPSED_API           (STD_ON)
  #define ICU_GET_DUTY_CYCLE_VALUES_API      (STD_ON)
#else
  /* do not modify these values */
  #define ICU_GET_TIME_ELAPSED_API           (STD_OFF)
  #define ICU_GET_DUTY_CYCLE_VALUES_API      (STD_OFF)
#endif

/* API function switches */
#define ICU_DE_INIT_API                      (STD_ON)
#define ICU_SET_MODE_API                     (STD_ON)
#define ICU_DISABLE_WAKEUP_API               (STD_ON)
#define ICU_ENABLE_WAKEUP_API                (STD_ON)
#define ICU_GET_INPUT_STATE_API              (STD_ON)
#define ICU_GET_VERSION_INFO_API             (STD_ON)

/* generation of ICU_DEV_ERROR_DETECT  and ICU_DEV_ERROR_REPORT */
#ifndef ICU_DEV_ERROR_DETECT
#define ICU_DEV_ERROR_DETECT STD_OFF
#endif
#ifndef ICU_DEV_ERROR_REPORT
#define ICU_DEV_ERROR_REPORT STD_OFF
#endif


#if (STD_ON == ICU_DEV_ERROR_REPORT)
  #include "Det.h"
  #define Icu_Errorhook(Icu_FunctionId, Icu_ErrorCode) \
    ( (void) Det_ReportError( (ICU_MODULE_ID), (ICU_INSTANCE_ID), (Icu_FunctionId), (Icu_ErrorCode)) )
#else
  #define Icu_Errorhook(Icu_FunctionId, Icu_ErrorCode)
#endif /* (STD_ON == ICU_DEV_ERROR_REPORT) */

#define ICU_WAKEUP_FUNCTIONALITY_API         (STD_ON)

#if (STD_ON == ICU_WAKEUP_FUNCTIONALITY_API)
  #define ICU_REPORT_WAKEUP_SOURCE           (STD_OFF)
#else
  #define ICU_REPORT_WAKEUP_SOURCE           (STD_OFF)
#endif

#define Icu_Init(x) Icu_Init_Vtt(&IcuConfigSet_0)


/**********************************************************************************************************************
 *  TYPE DEFINITIONS
 **********************************************************************************************************************/
/* Numeric ID of an ICU channel */
typedef uint8 Icu_ChannelType;

/* Width of the buffer for timestamp ticks and measured elapsed timeticks */
typedef uint32 Icu_ValueType;

/* Type to abstract the return value of the service Icu_GetTimestampIndex() */
typedef uint8 Icu_IndexType;

/* Type, to abstract the return value of the service Icu_GetEdgeNumbers() */
typedef uint16 Icu_EdgeNumberType;

/* Numeric ID of an Icu Interrupt Source */
typedef uint8 Icu_InterruptSourceType;

/* Definition of the type of activation of an ICU channel                   */
typedef enum
{
  ICU_RISING_EDGE = 0,
  ICU_FALLING_EDGE,
  ICU_BOTH_EDGES
} Icu_ActivationType;

/* Definition of the measurement mode type */
typedef enum
{
  ICU_MODE_EDGE_DETECTION     = 0x00,
  ICU_MODE_SIGNAL_MEASUREMENT = 0x40,
  ICU_MODE_TIMESTAMP          = 0x80,
  ICU_MODE_EDGE_COUNTER       = 0xC0
} Icu_MeasurementModeType;

/* Definition of the measurement property type */
typedef enum
{
  ICU_LOW_TIME = 0,
  ICU_HIGH_TIME,
  ICU_PERIOD_TIME,
  ICU_DUTY_CYCLE
} Icu_SignalMeasurementPropertyType;

/* Definition of the timestamp measurement property type */
typedef enum
{
  ICU_LINEAR_BUFFER = 0,
  ICU_CIRCULAR_BUFFER
} Icu_TimestampBufferType;

/* Input state of an ICU channel */
typedef enum
{
  ICU_IDLE = 0,
  ICU_ACTIVE
} Icu_InputStateType;

/* Type for notification function pointer */
typedef P2FUNC(void, ICU_APPL_CODE, Icu_NotifyType) (void);

/* Type for wakeup notification function pointer */
typedef P2FUNC(void, ICU_APPL_CODE, Icu_WakeupNotifyType) (uint32);

/* Type which shall contain the values, needed for calculating duty cycles */
typedef struct
{
  Icu_ValueType ActiveTime;
  Icu_ValueType PeriodTime;
} Icu_DutyCycleType;

/* Configuration for Edge-Counting functionality */
typedef struct
{
  /* Counting Activation can be TRUE / FALSE */
  uint8 Icu_EcActive_u8;

  /* Default-activation-edge which shall be used for this channel if
   * there was no activation-edge configured by the call of service
   * Icu_SetActivationCondition() */
  Icu_ActivationType  Icu_DefaultStartEdge_t;

  /* The Counter Variable where the Edge count Result is saved */
  Icu_EdgeNumberType Icu_EdgeValue_u16;

  /* The HardwareId where the Channel is uniquely defined within a RunTime */
  Icu_ChannelType Icu_ChannelId_u8;
} Icu_EcChlCfgType;

/* Configuration for Edge Detection functionality */
typedef struct
{
  /* WakeUp capability can be TRUE / FALSE */
  uint8 Icu_WakeupCapability_u8;

  /* EdgeDetection Activation can be TRUE / FALSE */
  uint8 Icu_EdActive_u8;

  /* Edge Input State  can be Active oder Idle*/
  Icu_InputStateType Icu_Ed_InputState;

  /* Default-activation-edge which shall be used for this channel if
   * there was no activation-edge configured by the call of service
   * Icu_SetActivationCondition() */
  Icu_ActivationType  Icu_DefaultStartEdge_t;

  /* Pointer to the notification function for this channel */
  Icu_NotifyType  Icu_Notify_pt;

  /* Wakeup source for this channel */
  uint32 Icu_WakeupSource_u32;

  /* The HardwareId where the Channel is uniquely defined within a RunTime */
  Icu_ChannelType Icu_ChannelId_u8;
}Icu_EdChlCfgType;

/* Configuration for Timestamping functionality */
typedef struct
{
  /* Default-activation-edge which shall be used for this channel if
   * there was no activation-edge configured by the call of service
   * Icu_SetActivationCondition() */
  Icu_ActivationType  Icu_DefaultStartEdge_t;

  /* Buffer type = circular or linear buffer */
  Icu_TimestampBufferType Icu_BufferType_t;

  /* Pointer to a notification function */
  Icu_NotifyType  Icu_Notify_pt;

  /* The HardwareId where the Channel is uniquely defined within a RunTime */
  Icu_ChannelType Icu_ChannelId_u8;
} Icu_TsChlCfgType;

/* Type to store information about the timestamping setting for a channel */
typedef struct
{
  /* Is the channel running / stopped */
  boolean RunState;
  /* Is the notification enabled=? */
  boolean NotifyInfo;

  /* Stores next value to be written */
  Icu_IndexType BufferIndex; 
  uint16 BufferSize;
  uint16 NotifyInterval;
  /* Counter for notificaton control */
  uint16 NotifyCnt; 

  P2VAR(Icu_ValueType, ICU_VAR, ICU_APPL_DATA) BufferPtr;
} Icu_TsArrayType;

/* Configuration for Signal Measurement functionality */
typedef struct
{
  /* Signal Start edge for this measurement channel.
   * This edge can not be changed during runtime. */
  Icu_ActivationType  Icu_SignalStartEdge_t;

  /* The Signal Measurement Property type */
  Icu_SignalMeasurementPropertyType Icu_MeasurementProperty_t;

  /* The HardwareId where the Channel is uniquely defined within a RunTime */
  Icu_ChannelType Icu_ChannelId_u8;
} Icu_SmChlCfgType;

/* Final configuration type for ICU */
typedef struct
{
  P2VAR(Icu_EcChlCfgType, AUTOMATIC, ICU_APPL_DATA)   Icu_EcChls_at; /* Configuration array for Edge Counting      */
  Icu_ChannelType Icu_EcChlCount_u8;

  P2VAR(Icu_TsChlCfgType, AUTOMATIC, ICU_APPL_DATA)   Icu_TsChls_at; /* Configuration array for Timestamping       */
  P2VAR(Icu_TsArrayType, AUTOMATIC, ICU_APPL_DATA)    Icu_TsData_at; /* Array to store data for timestamping       */
  Icu_ChannelType Icu_TsChlCount_u8;

  P2VAR(Icu_EdChlCfgType, AUTOMATIC, ICU_APPL_DATA)   Icu_EdChls_at; /* Configuration array for Edge detection     */
  Icu_ChannelType Icu_EdChlCount_u8;

  P2VAR(Icu_SmChlCfgType, AUTOMATIC, ICU_APPL_DATA)   Icu_SmChls_at; /* Configuration array for Signal Measurement */  
  P2VAR(Icu_DutyCycleType, AUTOMATIC, ICU_APPL_DATA)  Icu_SmDutyCylceData_at; /* Array to store data for signal measurement  */
  P2VAR(Icu_ValueType, AUTOMATIC, ICU_APPL_DATA)      Icu_SmValue_at; 
  P2VAR(Icu_InputStateType, AUTOMATIC, ICU_APPL_DATA) Icu_SmChlStatus_at; /* Array to store the status of the signal measurement */
  Icu_ChannelType Icu_SmChlCount_u8;

  P2VAR(Icu_ChannelType, AUTOMATIC, ICU_APPL_DATA)    Icu_IsrMappingTable_at; /* Array to store the channels isr information */
  Icu_ChannelType Icu_MaxNrOfChannels;
} Icu_ConfigType;

/**********************************************************************************************************************
 * Notification prototypes
 **********************************************************************************************************************/


/**********************************************************************************************************************
 * INCLUDES AFTER TYPE DEFINITIONS
 **********************************************************************************************************************/
#if (STD_ON == ICU_WAKEUP_FUNCTIONALITY_API)
  #if (STD_ON == ICU_REPORT_WAKEUP_SOURCE)
    /* The global wake-up definition */
    #include "Ecum_Cbk.h"
  #endif /* (STD_ON == ICU_REPORT_WAKEUP_SOURCE) */
#endif /* (STD_ON == ICU_WAKEUP_FUNCTIONALITY_API) */


/**********************************************************************************************************************
 *  Start - Configuration class PostBuild (public part of configuration)
 **********************************************************************************************************************/
/* Maximum numbers of channels per ConfigSet */
#define ICU_MAX_NOF_CHANNELS0    (1U) 


/* Symbolic Name Values of all channels configured for Edge Counting */


/* Symbolic Name Values of all channels configured for Timestamp Measurement */


/* Symbolic Name Values of all channels configured for Edge Detection */
#define IcuConf_IcuChannel_IcuChannel_0     (0u | (ICU_MODE_EDGE_DETECTION)) /*  Channel names for IcuConfigSet_0  */  


/* Symbolic Name Values of all channels configured for Signal Measurement */



#if !defined ICU_PBCFG_SOURCE
  /* Extern declarations of configuration instances */
  extern CONST(Icu_ConfigType, ICU_APPL_CONST)  IcuConfigSet_0; 

#endif


#endif /* !defined ICU_CFG_H */


/*********************************************************************************************************************
 *  END OF FILE: Icu_Cfg.h
 *********************************************************************************************************************/
