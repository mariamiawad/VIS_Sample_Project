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
 *            Module: VTTCntrl
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: VttCntrl_Can_Cfg.c
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



#define VTTCAN_SOURCE

/**********************************************************************************************************************
*  INCLUDES
*********************************************************************************************************************/
#include "VttCntrl_Can.h"

/**********************************************************************************************************************
*  PRAGMAS
*********************************************************************************************************************/
/* The following pragmas ensure that all variables of this module are places in memory that is not cleared during a
 * simulated ECU reset/poweron */
#pragma bss_seg()
#pragma data_seg()

/**********************************************************************************************************************
*  VERSION CHECK
*********************************************************************************************************************/

/* vendor specific version information is BCD coded */
#if (  (VTTCAN_SW_MAJOR_VERSION != (0x03)) || (VTTCAN_SW_MINOR_VERSION != (0x01)) || (VTTCAN_SW_PATCH_VERSION != (0x02)) )
# error "Vendor specific version numbers of VttCntrl_Can_Cfg.c and VttCntrl_Can.h are inconsistent"
#endif

#if (  (VTTCAN_CFG_SW_MAJOR_VERSION != (0x14)) || (VTTCAN_CFG_SW_MINOR_VERSION != (0x00)) || (VTTCAN_CFG_SW_PATCH_VERSION != (0x01)) )
# error "Vendor specific version numbers of VttCntrl_Can_Cfg.c and VttCntrl_Can_Cfg.h are inconsistent"
#endif

/**********************************************************************************************************************
*  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

const char* VttCan_BusName[VTTCAN_CHANNELS] = /* PRQA S 0850,5013 */ /* MD_MSR_19.8,MD_Can_5013_LL */
{
  "CAN",
};


/**********************************************************************************************************************
*  END OF FILE: VttCntrl_Can_Cfg.c
*********************************************************************************************************************/

