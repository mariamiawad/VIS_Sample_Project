/*-----------------------------------------------------------------------------
Module: CANoeEmu - AUTOSAR platform emulator for CANoe and VTT
Interfaces: all
-------------------------------------------------------------------------------
This header file provides APIs for controlling the emulated CPU together with
the integrated interrupt controller and a system timer.
-------------------------------------------------------------------------------
Copyright (c) Vector Informatik GmbH. All rights reserved.
-----------------------------------------------------------------------------*/

#ifndef CANOEEMUPROCESSOR_H
#define CANOEEMUPROCESSOR_H


#ifdef __cplusplus
extern "C" {
#endif


#include "Platform_Types.h"


// ================================================================================================
// Interrupt Controller
//
// The interrupt controller of CANoeEmu can handle several interrupts that are executed at 
// different interrupts levels. 
//
// The execution of an interrupt can only be interrupted by an interrupt with a higher interrupt 
// level. The controller has an interrupt level register for enabling and disabling interrupts.
// Only interrupts with an interrupt level that is greater than the value in the interrupt level 
// register are served.
//
// An interrupt request is cleared automatically when interrupt service routine starts execution.
//
// The simulation supports non-maskable interrupts (NMI). An interrupt is non-maskable, when it's
// priority is set a non-maskable level. A non-maskable interrupt cannot be disabled by the 
// interrupt level register. Also the global disabling of interrupts (function 
// CANoeEmuProcessor_DisableInterrupts) has no effect for non-maskable interrupts.
//
// The total number of interrupts (MAXIRQ) and the number of interrupt levels (MAXLEVEL)
// can be configured in the init-hook of the CANoe emulation (CANoeAPI_InitHook) with the 
// function CANoeAPI_ConfigureInterruptController. The function 
// CANoeAPI_ConfigureNumberOfNonMaskableInterruptLevels configures the amount of interrupt 
// levels, that are 'non-maskable'. The non-maskable interrupt levels are always the 
// interrupt levels with the highest priority of the virtual processor.
// 
// Interrupts are numbered from 0 to MAXIRQ (with MAXIRQ = number of interrupts -1)
// Execution levels are numbered from 0 to MAXLEVEL, where level 0 is always the task level.
//
// Example: 
// You have configured 32 interrupts, 4 interrupt levels and one of the interrupt levels 
// should be non-maskable.
//   CANoeAPI_ConfigureInterruptController(32, 4);
//   CANoeAPI_ConfigureNumberOfNonMaskableInterruptLevels(1)
// The execution levels are numbered from 0 to 4
//   Level 0: task level
//   Level 1: interrupt level 1, maskable
//   Level 2: interrupt level 2, maskable
//   Level 3: interrupt level 3, maskable
//   Level 4: interrupt level 4, non-maskable
// MAXIRQ = 31
// MAXLEVEL = 4
// ================================================================================================

// Modify the interrupt level register, that enables or disables the execution of
// interrupt service routines. Only interrupts with a level greater than
// then value in the interrupt level register are served. Non-maskable interrupts can not be 
// disabled by this function. If the function is called with a non-maskable interrrupt level, then
// the interrupt level register is set to highest maskable interrupt level.
// The function returns the previous value of the interrupt level register.
// parameter level: value for interrupt level register
//                  value 0 enables all interrupts
//                  value MAXLEVEL disables all maskable interrupts
// return value: previous value of the interrupt level register
extern sint32 CANoeEmuProcessor_SetInterruptLevel(sint32 level);

// Return the content of the interrupt level register. (values 0 .. MAXLEVEL)
extern sint32 CANoeEmuProcessor_GetInterruptLevel(void);

// Return maximum of interrupt level register and currently executed level. (values 0 .. MAXLEVEL)
extern sint32 CANoeEmuProcessor_GetCurrentLevel(void);

// Set the interrupt with the given number. The interrupt is always requested on the local core,
// the interrupt router is not in use.
// parameter irqNumber:  number of IRQ, values 0 .. MAXIRQ
extern void CANoeEmuProcessor_RequestInterrupt(sint32 irqNumber);

// Clear the interrupt with the given number
// parameter irqNumber:  number of IRQ, values 0 .. MAXIRQ
extern void CANoeEmuProcessor_ClearInterrupt(sint32 irqNumber);

// Check, if the interrupt with the given number is requested
// parameter irqNumber:  number of IRQ, values 0 .. MAXIRQ
// return value 0: interrupts is not requested
// return value 1: interrupts is requested
extern sint32 CANoeEmuProcessor_IsInterruptRequested(sint32 irqNumber);

// Mask a single interrupt
// In case of a non-maskable interrupt, the function has no effect.
// parameter irqNumber:  number of IRQ, values 0 .. MAXIRQ
// return value 0: interrupt was previously unmasked
// return value 1: interrupt was previously masked
extern sint32 CANoeEmuProcessor_MaskInterrupt(sint32 irqNumber);

// Unmask a single interrupt
// parameter irqNumber:  number of IRQ, values 0 .. MAXIRQ
// return value 0: interrupt was previously unmasked
// return value 1: interrupt was previously masked
extern sint32 CANoeEmuProcessor_UnmaskInterrupt(sint32 irqNumber);

// Check if a single interrupt is masked
// parameter irqNumber:  number of IRQ, values 0 .. MAXIRQ
// return value 0: interrupt is unmasked
// return value 1: interrupt is masked
extern sint32 CANoeEmuProcessor_IsInterruptMasked(sint32 irqNumber);

// Set the interrupt vector for the interrupt with the given number
// parameter irqNumber:  number of IRQ, values 0 .. MAXIRQ
// parameter f        :  start address of interrupt service routine
extern void CANoeEmuProcessor_ConfigureISR(sint32 irqNumber, void (*f)(void));

// Set the execution level (priority) for the given interrupt
// parameter irqNumber:  number of IRQ, values 0 .. MAXIRQ
// parameter level:      execution level for interrupt, values 1 - MAXLEVEL
extern void CANoeEmuProcessor_ConfigureInterruptPriority(sint32 irqNumber, sint32 level);

// Set the name for the given interrupt
// parameter irqNumber:  number of IRQ, values 0 .. MAXIRQ
// parameter name     :  name of the interrupt
extern void CANoeEmuProcessor_ConfigureInterruptName(sint32 irqNumber, const char* name);

// Get interrupt number of the currently processed interrupt.
// return value: If the emulation currently executes an ISR, the corresponding interrupt number
//               is returned. Otherwise CANOEEMUPROCESSOR_INVALIDIRQ (-1) is returned.
extern sint32 CANoeEmuProcessor_GetCurrentInterruptNumber(void);
#define CANOEEMUPROCESSOR_INVALIDIRQ -1

// Configure the behavior of the global interrupt state (enable/disable ) when the processor 
// starts the execution of an interrupt service routine (ISR).
// parameter disable:
//   value 0: The interrupt state remains unchanged.
//   value 1: At start of the interrupt service routine (ISR) the interrupts are automatically 
//            globally disabled (CANoeEmuProcessor_DisableInterrupts). The ISR code must manually 
//            enable the interrupts before leaving the ISR.
extern void CANoeEmuProcessor_DisableInterruptsAtStartOfISR(uint8 disable);


// ================================================================================================
//  CPU:  Thread-Handling with stack and register set
//        Sleep Mode
// ================================================================================================

// Disable all maskable interrupts
// The function has no effect for non-maskable interrupts.
// return value 0: interrupts are previously disabled
// return value 1: interrupts are previously enabled
extern uint8 CANoeEmuProcessor_DisableInterrupts(void);

// Enable interrupts
// return value 0: interrupts are previously disabled
// return value 1: interrupts are previously enabled
extern uint8 CANoeEmuProcessor_EnableInterrupts(void);

// CANoeEmuProcessor_InterruptsEnabled checks, if interrupts are enabled
// return value 0: interrupt are disabled
// return value 1: interrupt are enabled
extern uint8 CANoeEmuProcessor_InterruptsEnabled(void);

// Return the task number of the currently running task. If the function is called from 
// an interrupt service routine, then CANOEEMUPROCESSOR_IRQRUNNING (-1) is returned.
extern sint32 CANoeEmuProcessor_GetCurrentTask(void);
#define CANOEEMUPROCESSOR_IRQRUNNING -1

// CANoeEmuProcessor_SetTaskToRun is called by a task or interrupt routine to 
// tell the emulation layer which task it should run.
// If the function is called by a task, the calling task is suspended and
// execution is continued with the new task or the system goes idle when 
// called with parameter CANOEEMUPROCESSOR_IDLE.
// If the function is called by a interrupt routine the interrupt routine 
// is not suspended. When interrupt processing ends, the execution is 
// continued with the given task or the system goes idle when called with
// parameter CANOEEMUPROCESSOR_IDLE.
extern void CANoeEmuProcessor_SetTaskToRun(sint32 taskNr);
#define CANOEEMUPROCESSOR_IDLE -1

// CANoeEmuProcessor_SetTaskToRunAndEnableInterrupts is an atomic operation that executes
// the two functions CANoeEmuProcessor_SetTaskToRun and CANoeEmuProcessor_EnableInterrupts.
extern void CANoeEmuProcessor_SetTaskToRunAndEnableInterrupts(sint32 taskNr);

// Rollback the stack of a currently running task or ISR, so that it can start from beginning
extern void CANoeEmuProcessor_RollbackStack(void);

// Rollback the stack of the given task, so that it can start from beginning.
// parameter taskNr :  number of the task, where the rollback of the stack should happen.
// return value: 
//   CANOEEMUPROCESSOR_ROLLBACK        The function call was successful.
//   CANOEEMUPROCESSOR_INVALIDTASKNR   Parameter taskNr is invalid (task does not exists).
//   CANOEEMUPROCESSOR_NOTIMPLEMENTED  The function is only implemented in preemptive execution mode
//                                     (CANOEAPI_EXECUTE_PREEMPTIVE_MULTITHREAD).
extern sint32 CANoeEmuProcessor_RollbackStackOfTask(sint32 taskNr);

// Rollback the stack of the ISR, that is running on the given interrupt level, so that it can start from beginning
// parameter level: number of the interrupt level, where the rollback of the stack should happen.
// return value:
//   CANOEEMUPROCESSOR_ROLLBACK        The function call was successful.
//   CANOEEMUPROCESSOR_INVALIDLEVEL    Parameter level is invalid (level does not exists).
//   CANOEEMUPROCESSOR_NOTIMPLEMENTED  The function is only implemented in preemptive execution mode
//                                     (CANOEAPI_EXECUTE_PREEMPTIVE_MULTITHREAD).
extern sint32 CANoeEmuProcessor_RollbackStackOfIsr(sint32 level);

// Return codes for the rollback functions
#define CANOEEMUPROCESSOR_ROLLBACK         1
#define CANOEEMUPROCESSOR_INVALIDTASKNR   -1
#define CANOEEMUPROCESSOR_NOTIMPLEMENTED  -2
#define CANOEEMUPROCESSOR_INVALIDLEVEL    -3


// Configure number of task
extern void CANoeEmuProcessor_ConfigureNumberOfTasks(sint32 numberOfTasks);

// Configure the start address of a task
// parameter taskNr :  number of task
// parameter f      :  pointer to function, that is executed when the task stars.
extern void CANoeEmuProcessor_ConfigureTaskFunction(sint32 taskNr, void (*f)(void) );

// Set the name of a task. (For debugging purposes only)
// parameter taskNr :  number of task
// parameter name   :  name of the interrupt
extern void CANoeEmuProcessor_ConfigureTaskName(sint32 taskNr, char* name);

// Configure a callback function, that is called every time a TASK reaches its end.
// parameter taskEndHook: the callback function
extern void CANoeEmuProcessor_ConfigureTaskEndHook( void (*taskEndHook)(void) );

// Enter sleep mode
extern void CANoeEmuProcessor_GotoSleep(void);

// Power off the virtual ECU
extern void CANoeEmuProcessor_PowerOff(void);


// ================================================================================================
// Operations for multi core support
// ================================================================================================


// The function CANoeEmuProcessor_InterlockedExchange atomically exchanges the value of a variable.
// parameter destination: pointer to the variable, that is manipulated by this function
// parameter exchange: the new value for the variable
// return value: the initial value of the variable
extern uint32 CANoeEmuProcessor_InterlockedExchange(volatile uint32* destination, uint32 exchange);

// The function CANoeEmuProcessor_InterlockedCompareExchange atomically compares a variable
// with a given value. If they are the same, that the variable is set to the given exchange value.
// parameter destination: pointer to the variable, that is manipulated by this function
// parameter exchange: the new value for the variable, if the comparison succeeds
// parameter comperand: the value used for comparison with the variable
// return value: the initial value of the variable
extern uint32 CANoeEmuProcessor_InterlockedCompareExchange(volatile uint32* destination, uint32 exchange, uint32 comperand);


// Set the start address of the given core. When the a core is started, the execution of code
// starts at this address.
// parameter core: number of the processor core, that should be configured
// parameter f   : pointer to function, that is executed when the core starts execution.
extern void CANoeEmuProcessor_SetStartAddr(sint32 core, void (*f)(void));

// Trigger start of execution for the given processor core.
// parameter core: number of the processor core, that should be started
extern void CANoeEmuProcessor_StartCore(sint32 core);

// Core to core notification
// Request an interrupt on a specific core. The interrupt is directly delivered to the other core, 
// the interrupt router is not in use.
// parameter core      : number of the processor core, that should be notified
// parameter irqNumber : number of IRQ, values 0 .. MAXIRQ
extern void CANoeEmuProcessor_RequestInterruptOnCore(sint32 coreNumber, sint32 irqNumber);

// The function CANoeEmuProcessor_GetCoreNumber asks for the own core number.
// return value: The number of the core, that executes this function call.
extern sint32 CANoeEmuProcessor_GetCoreNumber(void);


// ================================================================================================
// Interrupt Router
//
// The Interrupt router delegates requested interrupts to the processor cores.
// ================================================================================================


// Clear all routing information. After this call, the routing mask of all interrupts is zero.
extern void CANoeEmuProcessor_InitInterruptRouter(void);

// Set the routing mask for the given interrupt number.
// The routing mask is a bit mask, that determines the cores to which an interrupt request should be
// delegated. (Bit 0 means core 0, bit 1 means core 1, ...)
// parameter irqNumber  : number of IRQ, values 0 .. MAXIRQ
// parameter routingMask: the new routing mask for the given interrupt
extern void CANoeEmuProcessor_SetInterruptRoutingMask(sint32 irqNumber, uint32 routingMask);

// Read the routing mask for the given interrupt number.
// parameter irqNumber:  number of IRQ, values 0 .. MAXIRQ
// return value       :  the new routing mask of the given interrupt
extern uint32 CANoeEmuProcessor_GetInterruptRoutingMask(sint32 irqNumber);


// ================================================================================================
// SystemTimer
//
// A simple cyclic timer. You can configure the cycle time and the interrupt number that is 
// requested every time the timer firers.
// ================================================================================================

// Get the number of high resolution timers that the virtual ECU has.
// return value:   number of high resolution timers, value 0 or 1
extern sint32 CANoeEmuSystemTimer_GetNumberOfTimers(void);

// Configure the cycle time register of the system timer. If cycleTime is zero,
// the timer is disabled. Otherwise the timer is started immediately.
// parameter cycleTime:  cycle time of timer in microseconds
extern void CANoeEmuSystemTimer_WriteCycleTime(uint32 cycleTime);

// Read the configured cycle time of the timer. The unit is microseconds.
extern uint32 CANoeEmuSystemTimer_ReadCycleTime(void);

// Configure interrupt number, that the timer should request when fired.
// parameter irqNumber:  number of IRQ, values 0 .. MAXIRQ
extern void CANoeEmuSystemTimer_WriteIrqNumber(sint32 irqNumber);

// Read the configured interrupt number, values 0 .. MAXIRQ
extern sint32 CANoeEmuSystemTimer_ReadIrqNumber(void);

// ================================================================================================
// High Resolution Timer
//
// A high resolution timer (HRTimer) consists of a counter register and a compare register.
// The counter register is a 32 bit up counter running with a configurable frequency.
//
// The compare register triggers an interrupt, when the value in the counter register matches the
// value in the compare register.
//
// The frequency of the counter can be configured with the function CANoeEmuHRTimer_SetSecondsPerTick.
// By default, the counter is running with 1MHz (cycle time 1 micro second). 
//
// A reset of the ECU sets the frequency back to its default and clears the counter and compare register.
//
// The virtual ECU can have several high resolution timers. The number of timers is configured with 
// API function CANoeAPI_ConfigureNumberOfHRTimers.
/// ================================================================================================

#define CANOEEMUHRTIMER_INVALIDINDEX -1

// Get the number of high resolution timers that the virtual ECU has.
// return value:   number of high resolution timers
extern sint32 CANoeEmuHRTimer_GetNumberOfTimers(void);

// Read the counter register of the high resolution timer. The unit is microseconds.
// parameter hrtIndex:   index of the high resolution timer
//                       range 0 .. number of high resolution timers -1
// return value:         value of the counter register
extern uint32 CANoeEmuHRTimer_GetCounterValue(sint32 hrtIndex);

// Set the compare register of the high resolution timer. The unit is microseconds.
// parameter hrtIndex:       index of the high resolution timer
//                           values 0 .. number of high resolution timers -1
// parameter expirationTime: The new value for the compare register
extern void CANoeEmuHRTimer_SetCompareValue(sint32 hrtIndex, uint32 expirationTime);

// Read the compare register of the high resolution timer. The unit is microseconds.
// parameter hrtIndex:       index of the high resolution timer
//                           values 0 .. number of high resolution timers -1
// return value:             value of the compare register
extern uint32 CANoeEmuHRTimer_GetCompareValue(sint32 hrtIndex);

// Configure the interrupt number, that the high resolution timer should trigger, when the counter
// register matches the compare register. The value CANOEEMUPROCESSOR_INVALIDIRQ (-1) disables 
// the interrupt generation.
// After a reset of the ECU, the interrupt generation is disabled by default.
// parameter hrtIndex:   index of the high resolution timer
//                       values 0 .. number of high resolution timers -1
// parameter irqNumber:  The interrupt number to fire (0 .. MAXIRQ) when the compare register 
//                       matches the counter register  or CANOEEMUPROCESSOR_INVALIDIRQ to 
//                       disable the interrupt generation.
extern void CANoeEmuHRTimer_SetIrqNumber(sint32 hrtIndex, sint32 irqNumber);

// Configure the frequency of a high resolution timer by setting the duration of a timer tick.
// The duration must not be less then one nanosecond.
// The implementation rounds the given duration to an integer multiple of one nanosecond.
// parameter hrtIndex:  index of the high resolution timer
//                      values 0 .. number of high resolution timers -1
// parameter duration:  the duration (unit seconds) of a single tick of the timer.
//                      the minimum duration is one nanosecond.
extern void CANoeEmuHRTimer_SetSecondsPerTick(sint32 hrtIndex, float64 duration);

// The Function 'CANoeEmuHRTimer_GetSecondsPerTick' returns the duration of a single tick of a
// high resolution timer.
// parameter hrtIndex:   index of the high resolution timer
//                       values 0 .. number of high resolution timers -1
// return value:         duration of a tick in seconds
extern float64 CANoeEmuHRTimer_GetSecondsPerTick(sint32 hrtIndex);


#ifdef __cplusplus
}  /* extern "C" */
#endif


#endif /* CANOEEMUPROCESSOR_H */



