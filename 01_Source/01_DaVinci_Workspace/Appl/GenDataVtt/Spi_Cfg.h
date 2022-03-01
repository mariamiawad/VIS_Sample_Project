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
 *            Module: VTTSpi
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Spi_Cfg.h
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

#if !defined SPI_CFG_H
#define SPI_CFG_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SPI_CFG_MAJOR_VERSION    (3U) 
#define SPI_CFG_MINOR_VERSION    (3U) 
#define SPI_CFG_PATCH_VERSION    (0U) 


/**********************************************************************************************************************
 *  Start - Configuration class PreCompile (public part of configuration)
 **********************************************************************************************************************/
/* Compiler switches for API enabling */
/* static config parameters */
#define SPI_VERSION_INFO_API                 (STD_ON)
#define SPI_CANCEL_API                       (STD_OFF)
#define SPI_HW_STATUS_API                    (STD_OFF)

/* The level to be implemented: 0/1/2 */
#define SPI_LEVEL_DELIVERED                  (0x01u)

/* 0 internal, 1 external, 2 both */
#define SPI_CHANNEL_BUFFERS_ALLOWED          (0x02u)

/* generation of SPI_DEV_ERROR_DETECT and SPI_DEV_ERROR_REPORT */
#ifndef SPI_DEV_ERROR_DETECT
#define SPI_DEV_ERROR_DETECT STD_ON
#endif
#ifndef SPI_DEV_ERROR_REPORT
#define SPI_DEV_ERROR_REPORT STD_ON
#endif  
  

#if (STD_ON == SPI_DEV_ERROR_REPORT)
  #include "Det.h"
  #define Spi_Errorhook(Spi_FunctionId, Spi_ErrorCode) \
    ( (void)Det_ReportError((SPI_MODULE_ID), (SPI_INSTANCE_ID), (Spi_FunctionId), (Spi_ErrorCode)) )
#else
  #define Spi_Errorhook(Spi_FunctionId, Spi_ErrorCode)
#endif /* (STD_ON == SPI_DEV_ERROR_REPORT) */

#define Spi_Init(x) Spi_Init_Vtt(&SpiDriver0)

/* Useful definitions: empty values */
#define SPI_JOB_NONE                         (0xFFu)
#define SPI_SEQ_NONE                         (0xFFu)
#define SPI_CHL_NONE                         (0xFFu)


/**********************************************************************************************************************
 *  TYPE DEFINITIONS
 **********************************************************************************************************************/


/**********************************************************************************************************************
 * Notification prototypes
 **********************************************************************************************************************/
  

/**********************************************************************************************************************
 *  Start - Configuration class PostBuild (public part of configuration)
 **********************************************************************************************************************/
/* Symbolic Name Values of all sequences */
#define SpiConf_SpiSequence_SpiSequence_PMIC  (0u)  /* SpiDriver0 */ 
#define SpiConf_SpiSequence_SpiSequence_EQ3  (1u) 


/* Symbolic Name Values of all jobs */
#define SpiConf_SpiJob_SpiJob_EQ3  (0u)  /* SpiDriver0 */ 
#define SpiConf_SpiJob_SpiJob_PMIC  (1u) 


/* Symbolic Name Values of all channels */
#define SpiConf_SpiChannel_SpiChannel_PMIC  (0u)  /* SpiDriver0 */ 
#define SpiConf_SpiChannel_SpiChannel_EQ3  (1u) 


/* Defines of all used HwUnits */
#define SPI_CSIB2 2U 
#define SPI_CSIB1 1U 


#if !defined SPI_PBCFG_SOURCE 
  /* The configuration instance */
  extern CONST(Spi_ConfigType, SPI_APPL_CONST) SpiDriver0; 

#endif /* !defined SPI_PBCFG_SOURCE  */


#endif /* !defined SPI_CFG_H */

 
/*********************************************************************************************************************
 *  END OF FILE: Spi_Cfg.h
 *********************************************************************************************************************/
