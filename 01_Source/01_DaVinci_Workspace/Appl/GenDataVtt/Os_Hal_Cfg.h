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
 *              File: Os_Hal_Cfg.h
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

#if !defined (OS_HAL_CFG_H)                                                          /* PRQA S 0883 */ /* MD_Os_0883 */
# define OS_HAL_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! HAL configuration major version identification. */
# define OS_CFG_HAL_MAJOR_VERSION                (2U)

/*! HAL configuration minor version identification. */
# define OS_CFG_HAL_MINOR_VERSION                (7U)

/* ISR core and level definitions */
# define OS_ISR_ADCISR_0_CORE      (0)
# define OS_ISR_ADCISR_0_LEVEL     (1)
# define OS_ISR_CANISRERR_0_CORE      (0)
# define OS_ISR_CANISRERR_0_LEVEL     (2)
# define OS_ISR_CANISRRX_0_CORE      (0)
# define OS_ISR_CANISRRX_0_LEVEL     (3)
# define OS_ISR_CANISRTX_0_CORE      (0)
# define OS_ISR_CANISRTX_0_LEVEL     (4)
# define OS_ISR_COUNTERISR_SYSTEMTIMER_CORE      (0)
# define OS_ISR_COUNTERISR_SYSTEMTIMER_LEVEL     (10)
# define OS_ISR_GPTISR_0_CORE      (0)
# define OS_ISR_GPTISR_0_LEVEL     (5)
# define OS_ISR_ICUISR_0_CORE      (0)
# define OS_ISR_ICUISR_0_LEVEL     (1)
# define OS_ISR_SPIISRTX_1_CORE      (0)
# define OS_ISR_SPIISRTX_1_LEVEL     (7)
# define OS_ISR_SPIISRTX_2_CORE      (0)
# define OS_ISR_SPIISRTX_2_LEVEL     (8)

/* Hardware counter timing macros */

/* Counter timing macros and constants: SystemTimer */
# define OSMAXALLOWEDVALUE_SystemTimer     (2147483647UL) /* 0x7FFFFFFFUL */
# define OSMINCYCLE_SystemTimer            (1UL)
# define OSTICKSPERBASE_SystemTimer        (80000UL)
# define OSTICKDURATION_SystemTimer        (1000000UL)

/* OSEK compatibility for the system timer. */
# define OSMAXALLOWEDVALUE     (OSMAXALLOWEDVALUE_SystemTimer)
# define OSMINCYCLE            (OSMINCYCLE_SystemTimer)
# define OSTICKSPERBASE        (OSTICKSPERBASE_SystemTimer)
# define OSTICKDURATION        (OSTICKDURATION_SystemTimer)

/*! Macro OS_NS2TICKS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_NS2TICKS_SystemTimer(x)     ( (TickType) (((((uint32)(x)) * 1) + 500000) / 1000000) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2NS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2NS_SystemTimer(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1000000) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Macro OS_US2TICKS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_US2TICKS_SystemTimer(x)     ( (TickType) (((((uint32)(x)) * 1) + 500) / 1000) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2US_SystemTimer was approximated with a deviation of 1.1102230246251565E-10ppm. */
# define OS_TICKS2US_SystemTimer(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1000) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Macro OS_MS2TICKS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_MS2TICKS_SystemTimer(x)     ( (TickType) (((((uint32)(x)) * 1) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2MS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2MS_SystemTimer(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */

/*! Macro OS_SEC2TICKS_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_SEC2TICKS_SystemTimer(x)     ( (TickType) (((((uint32)(x)) * 1000) + 0) / 1) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */
/*! Macro OS_TICKS2SEC_SystemTimer was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2SEC_SystemTimer(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 500) / 1000) )     /* PRQA S 3453 */ /* MD_MSR_19.7 */






#define OS_IRQ_AdcIsr_0 0
#define OS_IRQ_CanIsrErr_0 1
#define OS_IRQ_CanIsrRx_0 2
#define OS_IRQ_CanIsrTx_0 3
#define OS_IRQ_CounterIsr_SystemTimer 4
#define OS_IRQ_GptIsr_0 5
#define OS_IRQ_IcuIsr_0 6
#define OS_IRQ_SpiIsrTx_1 7
#define OS_IRQ_SpiIsrTx_2 8
#define OS_CANOE_IRQ_COUNT 9


#define OS_CFG_CAT1_ISR_COUNT         (0)
#define OS_CFG_MAX_INT_LEVEL          (10)

typedef enum
{
  /* OsCore_CORE0 */
  CANoeTaskId_BSW_OIEsTask = 1,
  CANoeTaskId_BSW_Task = 2,
  CANoeTaskId_OsTask_App = 3,
  CANoeTaskId_OsTask_Init = 4,
  CANoeTaskId_OsTask_Nv_Data = 5,
  CANoeTaskId_Os_IdleTask = 6,
  CANoeTaskId_SWCsInitTask = 7,
  CANoeTaskId_AdcIsr_0 = 8,
  CANoeTaskId_CanIsrErr_0 = 9,
  CANoeTaskId_CanIsrRx_0 = 10,
  CANoeTaskId_CanIsrTx_0 = 11,
  CANoeTaskId_CounterIsr_SystemTimer = 12,
  CANoeTaskId_GptIsr_0 = 13,
  CANoeTaskId_IcuIsr_0 = 14,
  CANoeTaskId_SpiIsrTx_1 = 15,
  CANoeTaskId_SpiIsrTx_2 = 16,
  CANoeTaskId_Os_CoreInitHook_OsCore_CORE0 = 17,
  
} CANoeTaskIdType;

typedef enum
{
  OS_CANOE_HRT_COUNT = 1
} CANoeHrtIdType;

typedef enum
{
  CANoePitId_OsHardwareTimerChannel  = 1,
  OS_CANOE_PIT_COUNT = 2
} CANoePitIdType;



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_HAL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Cfg.h
 *********************************************************************************************************************/
