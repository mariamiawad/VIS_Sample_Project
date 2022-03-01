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
 *              File: Port_PBcfg.c
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

#define PORT_PBCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "Port.h"


/**********************************************************************************************************************
 *  VERSION CHECK
 **********************************************************************************************************************/
#define PORT_CFG_C_MAJOR_VERSION    (4U) 
#define PORT_CFG_C_MINOR_VERSION    (1U) 
#define PORT_CFG_C_PATCH_VERSION    (0U) 

#if (  (PORT_SW_MAJOR_VERSION != (2u)) \
    || (PORT_SW_MINOR_VERSION != (3u)) )
    #error "Version numbers of Port_PBcfg.c and Port.h are inconsistent!"
#endif

#if (  (PORT_CFG_MAJOR_VERSION != PORT_CFG_C_MAJOR_VERSION) \
    || (PORT_CFG_MINOR_VERSION != PORT_CFG_C_MINOR_VERSION) )
    #error "Version numbers of Port_PBcfg.c and Port_Cfg.h are inconsistent!"
#endif


/**********************************************************************************************************************
 *  GLOBAL CONFIG DATA
 **********************************************************************************************************************/
/* ----- Pin direction changeable array ----------------------------------- */
static CONST(uint8, PORT_APPL_CONST) Port_PinDirectionChangeable_Rt0_au8[] = 
{ 
  FALSE 
}; 


/* ----- Main Configuration struct ---------------------------------------- */
CONST(Port_ConfigType, PORT_APPL_CONST) PortConfigSet_0= 
{ 
  (uint8) (1u), 
  (uint8) (1u), 
  Port_PinDirectionChangeable_Rt0_au8 
}; 


/*********************************************************************************************************************
 *  END OF FILE: PORT_PBCFG.C
 *********************************************************************************************************************/
