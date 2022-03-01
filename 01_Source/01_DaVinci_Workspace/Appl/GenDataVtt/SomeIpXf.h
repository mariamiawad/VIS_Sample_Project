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
 *          File:  SomeIpXf.h
 *        Config:  Bootcamp.dpa
 *   ECU-Project:  SCU
 *
 *     Generator:  MICROSAR SomeIpXf Generator Version 1.8.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1500710 for AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *
 *   Description:  MICROSAR SomeIpXf header file
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _SOMEIPXF_H
# define _SOMEIPXF_H


# include "SchM_SomeIpXf_Type.h"

# define SOMEIPXF_SW_MAJOR_VERSION (0x01U)
# define SOMEIPXF_SW_MINOR_VERSION (0x08U)
# define SOMEIPXF_SW_PATCH_VERSION (0x00U)

# define SOMEIPXF_VENDOR_ID (0x1EU)
# define SOMEIPXF_MODULE_ID (0xAEU)

# define SOMEIPXF_AR_RELEASE_MAJOR_VERSION     (0x04U)
# define SOMEIPXF_AR_RELEASE_MINOR_VERSION     (0x02U)
# define SOMEIPXF_AR_RELEASE_REVISION_VERSION  (0x02U)

/* Return Codes */
# define SOMEIPXF_E_SER_GENERIC_ERROR (0x81U)
# define SOMEIPXF_E_SER_WRONG_PROTOCOL_VERSION (0x87U)
# define SOMEIPXF_E_SER_WRONG_INTERFACE_VERSION (0x88U)
# define SOMEIPXF_E_SER_MALFORMED_MESSAGE (0x89U)
# define SOMEIPXF_E_SER_WRONG_MESSAGE_TYPE (0x8AU)

/**********************************************************************************************************************
 * SomeIpXf Init/DeInit API
 *********************************************************************************************************************/

typedef uint8 SomeIpXf_ConfigType;
FUNC(void, SOMEIPXF_CODE) SomeIpXf_Init(P2CONST(SomeIpXf_ConfigType, AUTOMATIC, SOMEIPXF_APPL_DATA) config);
FUNC(void, SOMEIPXF_CODE) SomeIpXf_DeInit(void);

#endif /* _SOMEIPXF_H */
