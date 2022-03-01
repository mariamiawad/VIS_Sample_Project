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
 *            Module: VTTAdc
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Adc_Cfg.h
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

#if !defined ADC_CFG_H
#define ADC_CFG_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define ADC_CFG_MAJOR_VERSION    (3U) 
#define ADC_CFG_MINOR_VERSION    (3U) 
#define ADC_CFG_PATCH_VERSION    (0U) 


/**********************************************************************************************************************
 *  TYPE DEFINITIONS
 **********************************************************************************************************************/
/* type defintion for configuring the trigger source for an ADC Channel Group */
typedef enum
{
  ADC_TRIGG_SRC_SW,
  ADC_TRIGG_SRC_HW
} Adc_TriggerSourceType;

/* type defintion for configuring the conversion mode of an ADC Channel Group */
typedef enum
{
  ADC_CONV_MODE_ONESHOT,
  ADC_CONV_MODE_CONTINUOUS
} Adc_GroupConvModeType;

/* Type for configuring on which edge of the hardware trigger signal the driver should react */
typedef enum
{
  ADC_HW_TRIG_FALLING_EDGE,
  ADC_HW_TRIG_RISING_EDGE,
  ADC_HW_TRIG_BOTH_EDGES
}Adc_HwTriggerSignalType;

/* type for configuring the notification capability */
typedef enum
{
  ADC_NOTIFICATION_OFF,
  ADC_NOTIFICATION_ON
} Adc_EnableNotificationType;

/* type for configuring the streaming access mode buffer type */
typedef enum
{
  ADC_GROUP_STOP_IMPLICIT,
  ADC_GROUP_STOP_EXPLICIT
} Adc_StreamBufferModeType;

/* Reference type for Adc_GroupType */
typedef P2VAR(Adc_GroupType, AUTOMATIC, ADC_VAR) Adc_GroupRefType;

/* This type is for storing runtime variables of each group (RAM) */
typedef struct
{
  Adc_ValueGroupRefType            ResultBuffer_pt;     /* Pointer to the result buffer provided by the user */
  volatile Adc_StreamNumSampleType SampleCountdown_t;   /* Responsible for buffer processing, e.g wrapping around  */
  volatile Adc_StreamNumSampleType ValidSampleCount_t;  /* Contains the nr. of valid samples, that are in buffer */
  volatile Adc_StreamNumSampleType SampleCountdownInIdle_t;   /* Responsible for reading the buffer when group is in idle state  */
  volatile Adc_StreamNumSampleType ValidSamplesInIdle_t;      /* Contains the nr. of valid samples, that are in buffer when group is in idle state */
  volatile Adc_StatusType          Status_t;            /* Contains the current status of the group */
  Adc_EnableNotificationType       Notification_u8;     /* Status of the notification function */ 
  Adc_GroupRefType                 GroupAssignment_pt;  /* Contains which group is currently active on this HW unit.
                                                         * If HW unit idles, it contains ADC_INVALID_GROUP_ID.
                                                         */                                                 
} Adc_GroupDataType;

/* Type for notification function pointer */
typedef P2FUNC(void, ADC_APPL_CODE, Adc_NotifyType) (void);

/* Type for Adc_ProcessConversion function pointer */
typedef P2FUNC(void, ADC_CODE, Adc_ProcessConvFuncPtrType) (Adc_GroupType Group);

/* This type is for storing post-build configured group variables (ROM) */
typedef struct
{
  P2VAR(Adc_GroupDataType, AUTOMATIC, ADC_APPL_DATA) GroupData_pt; /* Pointer to the runtime variables of this group */
  Adc_HwUnitEnumType               HwUnitOfTheGroup;               /* Contains the enumerated Hw-Id of the Group */
  Adc_NotifyType                   Notification_p;                 /* Pointers to notification functions */
  Adc_ProcessConvFuncPtrType       ProcessConversion_p;            /* Ptr to function that is called after buffer read. */
  Adc_StreamNumSampleType          StreamingNumSamples_t;          /* Contains how many samples fit into result buffer */
  Adc_GroupConvModeType            GroupConversionMode_u8;         /* Operation mode of the group (oneshot / cont.) */
  Adc_TriggerSourceType            GroupTriggSrc_u8;               /* Determines the trigger source (hw or sw trigger) */
  Adc_HwTriggerSignalType          HwTrigEvent_u8;                 /* Use rising or falling edge, or high or low level */
  Adc_GroupType                    SeqLength_u8;                   /* The number of channels of a group */
  Adc_StreamBufferModeType         GroupStopMode_u8;               /* Determines whether the group stops implicitly or has
                                                                    * to be stopped by the user
                                                                    */
} Adc_GroupConfigType;

/* Reference type for the Adc_GroupConfigType. */
typedef P2CONST(Adc_GroupConfigType, AUTOMATIC, ADC_APPL_CONST)   Adc_GroupConfigRefType;

/* Data structure containing the set of configuration parameters required for initializing the ADC Driver
 * and ADC HW Unit(s).
 */
typedef struct
{
  Adc_GroupConfigRefType           Group_at;               /* References the array of groups */
  Adc_GroupRefType                 ActiveGroupRtx_at;      /* References to the active group variable */
  Adc_GroupType                    NumberOfGroups_t;       /* Contains the number of groups configured */
  Adc_HwUnitType                   NumberOfHwUnits_t;      /* Contains the number of HW units configured */
} Adc_ConfigType;


/**********************************************************************************************************************
 *  Start - Configuration class PreCompile (public part of configuration)
 **********************************************************************************************************************/
/* Compiler switches for API enabling */
#define ADC_ENABLE_START_STOP_GROUP_API       (STD_ON)
#define ADC_DE_INIT_API                       (STD_OFF)
#define ADC_READ_GROUP_API                    (STD_ON)
#define ADC_HW_TRIGGER_API                    (STD_OFF)
#define ADC_GRP_NOTIF_CAPABILITY              (STD_ON)
#define ADC_VERSION_INFO_API                  (STD_OFF)

/* generation of ADC_DEV_ERROR_DETECT  and ADC_DEV_ERROR_REPORT */
#ifndef ADC_DEV_ERROR_DETECT
#define ADC_DEV_ERROR_DETECT STD_ON
#endif
#ifndef ADC_DEV_ERROR_REPORT
#define ADC_DEV_ERROR_REPORT STD_ON
#endif


/* Adc development error handler */
#if (STD_ON == ADC_DEV_ERROR_REPORT)
  #include "Det.h"
  #define Adc_ReportDet(Adc_ServiceId, Adc_ErrorCode) \
    ( (void)Det_ReportError ((ADC_MODULE_ID), (ADC_INSTANCE_ID), (Adc_ServiceId), (Adc_ErrorCode)) )
#else
  #define Adc_ReportDet(Adc_ServiceId, Adc_ErrorCode)
#endif /* (STD_ON == ADC_DEV_ERROR_REPORT) */

#define Adc_Init(x) Adc_Init_Vtt(&AdcConfigSet_0)


/**********************************************************************************************************************
 * Notification prototypes
 **********************************************************************************************************************/


/**********************************************************************************************************************
 *  Start - Configuration class PostBuild (public part of configuration)
 **********************************************************************************************************************/
/* Create symbolic names of AdcGroups for use in API functions */
/* ADC_CFG_GROUPNAME_LIST */
#define AdcConf_AdcGroup_SYS_MON    (0u) 


/* extern declarations of post-build configuration sets */
/* ADC_CFG_GENERAL_EXTERN */
extern CONST(Adc_ConfigType, ADC_APPL_CONST) AdcConfigSet_0; 
 
 
extern VAR(Adc_GroupType, ADC_VAR) Adc_ActiveGroupRt0_at[1]; 


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
FUNC(void, ADC_CODE) Adc_ProcessConversionLinear (Adc_GroupType Group);
FUNC(void, ADC_CODE) Adc_ProcessConversionSingle (Adc_GroupType Group);
FUNC(void, ADC_CODE) Adc_ProcessConversionCircular (Adc_GroupType Group);


#endif /* ADC_CFG_H */
 
 
/*********************************************************************************************************************
 *  END OF FILE: Adc_Cfg.h
 *********************************************************************************************************************/
