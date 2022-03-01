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
 *            Module: VTTMcu
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Mcu_PBcfg.c
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

#define MCU_PBCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "Mcu.h"


/**********************************************************************************************************************
 *  VERSION CHECK
 **********************************************************************************************************************/
#define MCU_CFG_C_MAJOR_VERSION    (4U) 
#define MCU_CFG_C_MINOR_VERSION    (2U) 
#define MCU_CFG_C_PATCH_VERSION    (0U) 

#if (  (MCU_SW_MAJOR_VERSION != (2u)) \
    || (MCU_SW_MINOR_VERSION != (4u)) )
    #error "Version numbers of Mcu_PBcfg.c and Mcu.h are inconsistent!"
#endif

#if (  (MCU_CFG_MAJOR_VERSION != MCU_CFG_C_MAJOR_VERSION) \
    || (MCU_CFG_MINOR_VERSION != MCU_CFG_C_MINOR_VERSION) )
    #error "Version numbers of Mcu_PBcfg.c and Mcu_Cfg.h are inconsistent!"
#endif


/**********************************************************************************************************************
 *  MODE MAPPING TABLE
 **********************************************************************************************************************/
CONST(VttMcu_ModeType, MCU_APPL_CONST) Mcu_ModeMappingTable[] =
{
  VTTMCU_MODE_NORMAL, 
  VTTMCU_MODE_SLEEP, 
  VTTMCU_MODE_NORMAL, 
  VTTMCU_MODE_RESET, 
  VTTMCU_MODE_POWER_OFF
};


/**********************************************************************************************************************
 *  GLOBAL CONFIG DATA
 **********************************************************************************************************************/
CONST(Mcu_ConfigType, MCU_APPL_CONST) McuModuleConfiguration =  
{ 
  Mcu_ModeMappingTable, /* Pointer to the MCU mode mapping table */ 
  1, /* Number of Clock Configuration */ 
  0  /* Number of RamSection          */ 
}; 
CONST(Mcu_ConfigType, MCU_APPL_CONST) McuModuleConfiguration_0 =  
{ 
  Mcu_ModeMappingTable, /* Pointer to the MCU mode mapping table */ 
  1, /* Number of Clock Configuration */ 
  1  /* Number of RamSection          */ 
}; 
 

/*********************************************************************************************************************
 *  END OF FILE: Mcu_PBcfg.c
 *********************************************************************************************************************/
