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
 *            Module: VTTOs
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Hal_Interrupt_Lcfg.c
 *   Generation Time: 2019-11-13 15:54:55
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

/* PRQA S 0777, 0779, 0810, 0828, 0857 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779, MD_MSR_1.1_810, MD_MSR_1.1_828, MD_MSR_1.1_857 */

#define OS_HAL_INTERRUPT_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Interrupt_Lcfg.h"
#include "Os_Hal_Interrupt.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
#include "Os_Hal_Core.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL ISR configuration data: AdcIsr_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_AdcIsr_0 =
{
  /* .Name  =       */ "AdcIsr_0",
  /* .Source =      */ OS_IRQ_AdcIsr_0,
  /* .Level =       */ 1,
  /* .Handler =     */ &Os_Hal_CanoeIrqHandler_AdcIsr_0,
  /* .RoutingMask = */ (1<<0)
};

/*! HAL ISR configuration data: CanIsrErr_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsrErr_0 =
{
  /* .Name  =       */ "CanIsrErr_0",
  /* .Source =      */ OS_IRQ_CanIsrErr_0,
  /* .Level =       */ 2,
  /* .Handler =     */ &Os_Hal_CanoeIrqHandler_CanIsrErr_0,
  /* .RoutingMask = */ (1<<0)
};

/*! HAL ISR configuration data: CanIsrRx_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsrRx_0 =
{
  /* .Name  =       */ "CanIsrRx_0",
  /* .Source =      */ OS_IRQ_CanIsrRx_0,
  /* .Level =       */ 3,
  /* .Handler =     */ &Os_Hal_CanoeIrqHandler_CanIsrRx_0,
  /* .RoutingMask = */ (1<<0)
};

/*! HAL ISR configuration data: CanIsrTx_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CanIsrTx_0 =
{
  /* .Name  =       */ "CanIsrTx_0",
  /* .Source =      */ OS_IRQ_CanIsrTx_0,
  /* .Level =       */ 4,
  /* .Handler =     */ &Os_Hal_CanoeIrqHandler_CanIsrTx_0,
  /* .RoutingMask = */ (1<<0)
};

/*! HAL ISR configuration data: CounterIsr_SystemTimer */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_CounterIsr_SystemTimer =
{
  /* .Name  =       */ "CounterIsr_SystemTimer",
  /* .Source =      */ OS_IRQ_CounterIsr_SystemTimer,
  /* .Level =       */ 10,
  /* .Handler =     */ &Os_Hal_CanoeIrqHandler_CounterIsr_SystemTimer,
  /* .RoutingMask = */ (1<<0)
};

/*! HAL ISR configuration data: GptIsr_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_GptIsr_0 =
{
  /* .Name  =       */ "GptIsr_0",
  /* .Source =      */ OS_IRQ_GptIsr_0,
  /* .Level =       */ 5,
  /* .Handler =     */ &Os_Hal_CanoeIrqHandler_GptIsr_0,
  /* .RoutingMask = */ (1<<0)
};

/*! HAL ISR configuration data: IcuIsr_0 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_IcuIsr_0 =
{
  /* .Name  =       */ "IcuIsr_0",
  /* .Source =      */ OS_IRQ_IcuIsr_0,
  /* .Level =       */ 1,
  /* .Handler =     */ &Os_Hal_CanoeIrqHandler_IcuIsr_0,
  /* .RoutingMask = */ (1<<0)
};

/*! HAL ISR configuration data: SpiIsrTx_1 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SpiIsrTx_1 =
{
  /* .Name  =       */ "SpiIsrTx_1",
  /* .Source =      */ OS_IRQ_SpiIsrTx_1,
  /* .Level =       */ 7,
  /* .Handler =     */ &Os_Hal_CanoeIrqHandler_SpiIsrTx_1,
  /* .RoutingMask = */ (1<<0)
};

/*! HAL ISR configuration data: SpiIsrTx_2 */
CONST(Os_Hal_IntIsrConfigType, OS_CONST) OsCfg_Hal_IntIsr_SpiIsrTx_2 =
{
  /* .Name  =       */ "SpiIsrTx_2",
  /* .Source =      */ OS_IRQ_SpiIsrTx_2,
  /* .Level =       */ 8,
  /* .Handler =     */ &Os_Hal_CanoeIrqHandler_SpiIsrTx_2,
  /* .RoutingMask = */ (1<<0)
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Interrupt_Lcfg.c
 *********************************************************************************************************************/
