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
 *            Module: VTTFls
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Fls_Lcfg.c
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

#define FLS_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "Fls.h"


/**********************************************************************************************************************
 *  VERSION CHECK
 **********************************************************************************************************************/
#define FLS_CFG_C_MAJOR_VERSION    (4u) 
#define FLS_CFG_C_MINOR_VERSION    (4u) 
#define FLS_CFG_C_PATCH_VERSION    (0u) 



#if (  (FLS_SW_MAJOR_VERSION != (3u)) \
    || (FLS_SW_MINOR_VERSION != (3u)))
  #error "Version numbers of Fls_Lcfg.c and Fls.h are inconsistent!"
#endif

#if (  (FLS_CFG_MAJOR_VERSION != FLS_CFG_C_MAJOR_VERSION) \
    || (FLS_CFG_MINOR_VERSION != FLS_CFG_C_MINOR_VERSION) )
  #error "Version numbers of Fls_Lcfg.c and Fls_Cfg.h are inconsistent!"
#endif


/**********************************************************************************************************************
 *  GLOBAL CONFIG DATA
 **********************************************************************************************************************/
/* Configuration structure of the Fls */
CONST(Fls_ConfigType, FLS_APPL_CONST) FlsConfigSet_0 =
{
  FLS_MODULE_ID /*  Fls Module Id  */ , 
  0 /*  Fls Base Address  */ , 
  130368UL /*  Used size of Fls in bytes  */ , 
  256 /*  No of bytes to read in each job proc. cycle in normal mode  */ , 
  512 /*  No of bytes to read in each job proc. cycle in fast mode  */ , 
  4 /*  No of bytes to write in each job proc. cycle in normal mode  */ , 
  0 /*  No of bytes to write in each job proc. cycle in fast mode  */ , 
  MEMIF_MODE_SLOW /*  Fls default mode after init  */ , 
  Fee_JobEndNotification /*  Callback function for positive job result  */ , 
  Fee_JobErrorNotification /*  Callback function to notify error in an erase or a write job  */ 
};

/*********************************************************************************************************************
 *  END OF FILE: Fls_LCFG.C
 *********************************************************************************************************************/
