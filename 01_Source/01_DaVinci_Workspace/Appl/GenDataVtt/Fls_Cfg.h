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
 *              File: Fls_Cfg.h
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


#if !defined FLS_CFG_H
#define FLS_CFG_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
#define FLS_CFG_MAJOR_VERSION    (4u) 
#define FLS_CFG_MINOR_VERSION    (4u) 
#define FLS_CFG_PATCH_VERSION    (0u) 



/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "MemIf_Types.h"
#include "SchM_Fls.h"


/**********************************************************************************************************************
 *  TYPE DEFINITIONS
 **********************************************************************************************************************/
/* Type for notification function pointer */
typedef P2FUNC(void, FLS_APPL_CODE, Fls_NotifyType) (void);

typedef struct
{
  uint16            ModuleID;                         /* Fls Module Id                                              */
  Fls_AddressType   BaseAddress;                      /* Fls Base Address                                           */
  Fls_LengthType    Size;                             /* used size of Fls in bytes                                  */
  Fls_LengthType    NormalReadBlockSize;              /* No of bytes to read in each job proc. cycle in normal mode */
  Fls_LengthType    FastReadBlockSize;                /* No of bytes to read in each job proc. cycle in fast mode   */
  Fls_LengthType    NormalWriteBlockSize;             /* No of bytes to read in each job proc. cycle in normal mode */
  Fls_LengthType    FastWriteBlockSize;               /* No of bytes to read in each job proc. cycle in fast mode   */
  MemIf_ModeType    DefaultMode;                      /* Fls Default Mode after initialization                      */
  Fls_NotifyType    JobEndNotif;                      /* Notification Function for positive job result              */
  Fls_NotifyType    JobErrorNotif;                    /* Notification Function for negative job result              */
} Fls_ConfigType;


typedef P2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) Fls_ConstBytePtrType;

typedef P2VAR(uint8,   AUTOMATIC, FLS_APPL_DATA ) Fls_VarBytePtrType;


/**********************************************************************************************************************
 *  Start - Configuration class PreCompile (public part of configuration)
 **********************************************************************************************************************/
/* Compiler switches for API enabling */
/* static config parameters */
#define FLS_GET_JOB_RESULT_API      (STD_ON)
#define FLS_GET_STATUS_API          (STD_ON)
#define FLS_CANCEL_API              (STD_ON)
#define FLS_COMPARE_API             (STD_ON)
#define FLS_VERSION_INFO_API        (STD_OFF)
#define FLS_SET_MODE_API            (STD_OFF)

#define FLS_BLANK_CHECK_API         (STD_OFF)
#define FLS_READSYNC_API            (STD_ON)
#define FLS_COPY_API                (STD_ON)

#define FLS_ERASE_UNIT_SIZE         (0x10U)    /* No of bytes that can be erased in one cycle */
#define FLS_ERASE_VALUE             (0xFFU)

/**********************************************************************************************************************
 * generation of FLS_DEV_ERROR_DETECT  and FLS_DEV_ERROR_REPORT
 **********************************************************************************************************************/
#ifndef FLS_DEV_ERROR_DETECT
#define FLS_DEV_ERROR_DETECT STD_ON
#endif
#ifndef FLS_DEV_ERROR_REPORT
#define FLS_DEV_ERROR_REPORT STD_ON
#endif


/* Fls development error handler */
#if (STD_ON == FLS_DEV_ERROR_REPORT)
  #include "Det.h"
  #define Fls_Errorhook(Fls_FunctionId, Fls_ErrorCode) \
    ( (void) Det_ReportError ((FLS_MODULE_ID),(FLS_INSTANCE_ID),(Fls_FunctionId), (Fls_ErrorCode)) )
#else
  #define Fls_Errorhook(Fls_FunctionId, Fls_ErrorCode)
#endif /* (STD_ON == FLS_DEV_ERROR_REPORT) */

#if !defined FLS_LCFG_SOURCE
  /* Extern declarations of configuration instances */
  extern CONST(Fls_ConfigType, FLS_APPL_CONST) FlsConfigSet_0; 

#endif

/**********************************************************************************************************************
 * generation of Init Macro
 **********************************************************************************************************************/
/* The init function is needed as define, because the ConfigPtr type is not defined via AUTOSAR and thus type is set by user.
 * Because of unknown ConfigPtr Type the macro usage is necessary.
 * Use always the Config-Struct from VTT component:
 * in case of NULL_PTR usage, because of Pre-Compile real component or 
 * in case the real component uses an other Config-Struct, like VTT 
 */
#define Fls_Init(x) Fls_Init_Vtt(&FlsConfigSet_0)

/**********************************************************************************************************************
 * Notification prototypes
 **********************************************************************************************************************/
void Fee_JobEndNotification(void); 
void Fee_JobErrorNotification(void); 



#endif /* !defined FLS_CFG_H */


/**********************************************************************************************************************
 *  END OF FILE: Fls_Cfg.h
 **********************************************************************************************************************/
