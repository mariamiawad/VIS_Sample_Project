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
 *              File: Adc_PBcfg.c
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

#define ADC_PBCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "Adc.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 **********************************************************************************************************************/
#define ADC_CFG_C_MAJOR_VERSION    (3U) 
#define ADC_CFG_C_MINOR_VERSION    (3U) 
#define ADC_CFG_C_PATCH_VERSION    (0U) 

#if (  (ADC_SW_MAJOR_VERSION != (2U)) \
    || (ADC_SW_MINOR_VERSION != (5U)))
  #error "Version numbers of Adc_PBcfg.c and Adc.h are inconsistent!"
#endif

#if (  (ADC_CFG_MAJOR_VERSION != ADC_CFG_C_MAJOR_VERSION) \
    || (ADC_CFG_MINOR_VERSION != ADC_CFG_C_MINOR_VERSION) )
  #error "Version numbers of Adc_PBcfg.c and Adc_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  GLOBAL CONFIG DATA
 **********************************************************************************************************************/
/* Declare RAM variable for active channel. One variable for each of the runtimes and HW units */
/* ADC_ACTIVE_GROUP_VARS */
VAR(Adc_GroupType, ADC_VAR) Adc_ActiveGroupRt0_at[1]; 
 

/* Declare RAM variables for the groups. One array for each of the runtimes and HW units */
/* ADC_GROUP_DATA_LIST */
static VAR(Adc_GroupDataType, ADC_VAR) Adc_GroupDataListRt0Hw0_at[1]; 


/* Create group configuration sets (ROM). One array for each of the runtimes */
/* ADC_GROUP_CONFIG_LIST */
static CONST(Adc_GroupConfigType, ADC_APPL_CONST) Adc_GroupConfigListRt0_at[] = 
{ 
  { 
    &Adc_GroupDataListRt0Hw0_at[0], 
    Hw0, 
    NULL_PTR, 
    &Adc_ProcessConversionSingle, 
    1, /* Number of samples */ 
    ADC_CONV_MODE_ONESHOT, /* Group Conversion Mode */ 
    ADC_TRIGG_SRC_SW, /* Group Trigger Source */ 
    ADC_HW_TRIG_RISING_EDGE, /* HW Trigger Signal not relevant because of SW Trigger */ 
    12, /* Number of channels in this group */ 
    ADC_GROUP_STOP_IMPLICIT 
  } 
}; 


/* Create runtime configurations. One structure per runtime. */
/* ADC_CONFIG */
CONST(Adc_ConfigType, ADC_APPL_CONST) AdcConfigSet_0 = 
{ 
  Adc_GroupConfigListRt0_at, 
  Adc_ActiveGroupRt0_at, 
  1, /* Number of groups in this runtime */ 
  1 /* Number of HW units in this runtime */ 
}; 


/**********************************************************************************************************************
 *  END OF FILE: Adc_PBcfg.c
 **********************************************************************************************************************/
