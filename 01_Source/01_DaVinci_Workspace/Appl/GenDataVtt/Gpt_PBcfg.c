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
 *              File: Gpt_PBcfg.c
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

#define GPT_PBCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "Gpt.h"


/**********************************************************************************************************************
 *  VERSION CHECK
 **********************************************************************************************************************/
#define GPT_CFG_C_MAJOR_VERSION    (4U) 
#define GPT_CFG_C_MINOR_VERSION    (3U) 
#define GPT_CFG_C_PATCH_VERSION    (0U) 

#if (  (GPT_SW_MAJOR_VERSION != (2U)) \
    || (GPT_SW_MINOR_VERSION != (5U)) )
    #error "Version numbers of Gpt_PBcfg.c and Gpt.h are inconsistent!"
#endif

#if (  (GPT_CFG_MAJOR_VERSION != GPT_CFG_C_MAJOR_VERSION) \
    || (GPT_CFG_MINOR_VERSION != GPT_CFG_C_MINOR_VERSION) )
    #error "Version numbers of Gpt_PBcfg.c and Gpt_Cfg.h are inconsistent!"
#endif


/**********************************************************************************************************************
 *  GLOBAL CONFIG DATA
 **********************************************************************************************************************/
/* Configuration structure of the Gpt */
VAR(Gpt_ChannelConfigType, GPT_APPL_DATA) GptChannelConfigSet_0_Channels[] = 
{
  {
    0 /* Timer Value */, 
    FALSE /* Channel Active Status */, 
    FALSE /* Notification Active Status */, 
    GPT_CH_MODE_CONTINUOUS, 
    NULL_PTR /* No notification assigned */
  }
}; 

CONST(Gpt_ConfigType, GPT_APPL_CONST) GptChannelConfigSet_0 = 
{
  GptChannelConfigSet_0_Channels /* Array of configured channels */, 
  1U /* Number of configured GPT Channels */
}; 



/*********************************************************************************************************************
 *  END OF FILE: GPT_PBCFG.C
 *********************************************************************************************************************/
