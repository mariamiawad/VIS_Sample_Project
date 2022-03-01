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
 *              File: Icu_PBcfg.c
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

#define ICU_PBCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "Icu.h"


/**********************************************************************************************************************
 *  VERSION CHECK
 **********************************************************************************************************************/
#define ICU_CFG_C_MAJOR_VERSION    (3U) 
#define ICU_CFG_C_MINOR_VERSION    (3U) 
#define ICU_CFG_C_PATCH_VERSION    (0U) 

#if (  (ICU_SW_MAJOR_VERSION != (2U)) \
    || (ICU_SW_MINOR_VERSION != (5U)) )
    #error "Version numbers of Icu_PBcfg.c and Icu.h are inconsistent!"
#endif

#if (  (ICU_CFG_MAJOR_VERSION != ICU_CFG_C_MAJOR_VERSION) \
    || (ICU_CFG_MINOR_VERSION != ICU_CFG_C_MINOR_VERSION) )
    #error "Version numbers of Icu_PBcfg.c and Icu_Cfg.h are inconsistent!"
#endif


/* Preprocessor define STATIC is no longer available in Compiler.h in MSR4 - provide local define */
#if !defined (STATIC)
  #define STATIC static
#endif

/**********************************************************************************************************************
 *  GLOBAL CONFIG DATA
 **********************************************************************************************************************/
/* ------ Edge Counting channel configuration ----------------------------- */



/* ------ Timestamping channel configuration ------------------------------ */



/* ----- Edge Detection channel configuration ----------------------------- */
#define ICU_ED_NOF_CHLS_0          (1U) 

/* ED Channel Configuration of IcuConfigSet_0 */ 
VAR(Icu_EdChlCfgType, ICU_APPL_DATA) Icu_EdChannel_0[ICU_ED_NOF_CHLS_0] = 
{ 
  {STD_OFF, FALSE, ICU_IDLE, ICU_RISING_EDGE, NULL_PTR, 0x00, 0} 
}; 


/* ----- Signal Measurement channel configuration ------------------------- */



/* IsrMappingTables */
/* MappingTable for the cryptic channel id and the hardware id for IcuConfigSet_0 */ 
STATIC VAR(Icu_ChannelType, ICU_VAR) Icu_IsrMappingTable0[ICU_MAX_NOF_CHANNELS0]; 


/* ----- Main Configuration struct ---------------------------------------- */
CONST(Icu_ConfigType, ICU_APPL_CONST) IcuConfigSet_0 = 
{ 
  /* Configuration for EC channels of IcuConfigSet_0 */ 
  NULL_PTR, 
  0, 
 
  /* Configuration for TS channels of IcuConfigSet_0 */ 
  NULL_PTR, 
  NULL_PTR, 
  0, 
 
  /* Configuration for ED channels of IcuConfigSet_0 */ 
  Icu_EdChannel_0, 
  ICU_ED_NOF_CHLS_0, 
 
  /* Configuration for SM channels of IcuConfigSet_0 */ 
  NULL_PTR, 
  NULL_PTR, 
  NULL_PTR, 
  NULL_PTR, 
  0, 
 
  /* Mapping table for interrupt service routines of IcuConfigSet_0 */ 
  Icu_IsrMappingTable0, 
  ICU_MAX_NOF_CHANNELS0 
}; 
 

/*********************************************************************************************************************
 *  END OF FILE: Icu_PBcfg.c
 *********************************************************************************************************************/
