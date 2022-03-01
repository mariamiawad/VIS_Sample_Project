/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  ComXf.h
 *        Config:  Bootcamp.dpa
 *   ECU-Project:  SCU
 *
 *     Generator:  MICROSAR ComXf Generator Version 1.8.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1500710 for AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *
 *   Description:  MICROSAR ComXf header file
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _COMXF_H
# define _COMXF_H


# include "SchM_ComXf_Type.h"

# define COMXF_SW_MAJOR_VERSION (0x01U)
# define COMXF_SW_MINOR_VERSION (0x08U)
# define COMXF_SW_PATCH_VERSION (0x00U)

# define COMXF_VENDOR_ID (0x1EU)
# define COMXF_MODULE_ID (0xAFU)

# define COMXF_AR_RELEASE_MAJOR_VERSION     (0x04U)
# define COMXF_AR_RELEASE_MINOR_VERSION     (0x02U)
# define COMXF_AR_RELEASE_REVISION_VERSION  (0x02U)

/* Return Codes */
# define COMXF_E_SER_GENERIC_ERROR (0x81U)

/**********************************************************************************************************************
 * ComXf Init/DeInit API
 *********************************************************************************************************************/

typedef uint8 ComXf_ConfigType;
FUNC(void, COMXF_CODE) ComXf_Init(P2CONST(ComXf_ConfigType, AUTOMATIC, COMXF_APPL_DATA) config);
FUNC(void, COMXF_CODE) ComXf_DeInit(void);

#endif /* _COMXF_H */
