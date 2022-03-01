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
 *              File: VttCntrl_Icu_Cfg.c
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

# define VTTICU_CFG_SOURCE

/**********************************************************************************************************************
*  INCLUDES
*********************************************************************************************************************/
#include "VttCntrl_Icu.h"
#include "CANoeApi.h"
#include "CANoeEmuProcessor.h"
#include "VTTCntrl_Base.h"

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
#if (  (VTTCNTRL_SW_MAJOR_VERSION != (9u)) \
    || (VTTCNTRL_SW_MINOR_VERSION != (0u)) \
    || (VTTCNTRL_SW_PATCH_VERSION != (0u)) )
  #error "Vendor specific version numbers of VttCntrl_Icu.c and VttCntrl_Base.h are inconsistent"
#endif

/* Check the version of VttCntrl_Icu header file */
#if (  (VTTICU_SW_MAJOR_VERSION != (0x03u)) \
    || (VTTICU_SW_MINOR_VERSION != (0x00u)) \
    || (VTTICU_SW_PATCH_VERSION != (0x06u)) )
# error "Vendor specific version numbers of VttCntrl_Icu_Cfg.c and VttCntrl_Icu.h are inconsistent"
#endif

/* Check the version of the configuration header file */
#if (  (VTTICU_CFG_MAJOR_VERSION != (0x13u)) \
    || (VTTICU_CFG_MINOR_VERSION != (0x00u)) \
    || (VTTICU_CFG_PATCH_VERSION != (0x01u)))
  #error "Version numbers of VttCntrl_Icu_Cfg.c and VttCntrl_Icu_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
*  GLOBAL DATA
**********************************************************************************************************************/

VttIcu_CntrlType VttIcu_Cntrl[VTTICU_CHANNELS] = 
{
  {
    "IcuChannel_0",
    VTTICU_FALSE, 
    ICU_RISING_EDGE,
    ICU_RISING_EDGE,
    VTTICU_FALSE,
    VttIcu_State_Edge_x,
    0,
    0,
    0,
    0,
  },
};

/**********************************************************************************************************************
*  END OF FILE: VttCntrl_Icu_Cfg.c
**********************************************************************************************************************/

