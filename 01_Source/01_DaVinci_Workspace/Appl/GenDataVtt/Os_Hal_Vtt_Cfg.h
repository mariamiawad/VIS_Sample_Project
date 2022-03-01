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
 *              File: Os_Hal_Vtt_Cfg.h
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

#if !defined (Os_Hal_Vtt_CFG_H)
# define Os_Hal_Vtt_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether VTT debug information is active (STD_ON) or not (STD_OFF). */
#define OS_CFG_HAL_DEBUG_VTT   (STD_OFF)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/*******************
 * Category 2 ISRs
 *******************/

extern void Os_Hal_CanoeIrqHandler_AdcIsr_0(void);
extern void Os_Hal_CanoeIrqTask_AdcIsr_0(void);

extern void Os_Hal_CanoeIrqHandler_CanIsrErr_0(void);
extern void Os_Hal_CanoeIrqTask_CanIsrErr_0(void);

extern void Os_Hal_CanoeIrqHandler_CanIsrRx_0(void);
extern void Os_Hal_CanoeIrqTask_CanIsrRx_0(void);

extern void Os_Hal_CanoeIrqHandler_CanIsrTx_0(void);
extern void Os_Hal_CanoeIrqTask_CanIsrTx_0(void);

extern void Os_Hal_CanoeIrqHandler_CounterIsr_SystemTimer(void);
extern void Os_Hal_CanoeIrqTask_CounterIsr_SystemTimer(void);

extern void Os_Hal_CanoeIrqHandler_GptIsr_0(void);
extern void Os_Hal_CanoeIrqTask_GptIsr_0(void);

extern void Os_Hal_CanoeIrqHandler_IcuIsr_0(void);
extern void Os_Hal_CanoeIrqTask_IcuIsr_0(void);

extern void Os_Hal_CanoeIrqHandler_SpiIsrTx_1(void);
extern void Os_Hal_CanoeIrqTask_SpiIsrTx_1(void);

extern void Os_Hal_CanoeIrqHandler_SpiIsrTx_2(void);
extern void Os_Hal_CanoeIrqTask_SpiIsrTx_2(void);


/*******************
 * Category 1 ISRs
 *******************/

/*******************
 * Category 0 ISRs
 *******************/


#endif /* Os_Hal_Vtt_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Vtt_Cfg.h
 *********************************************************************************************************************/
