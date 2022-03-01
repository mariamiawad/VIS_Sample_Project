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
 *              File: Spi_PBcfg.c
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

#define SPI_PBCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
#include "Spi.h"


/**********************************************************************************************************************
 *  VERSION CHECK
 **********************************************************************************************************************/
#define SPI_CFG_C_MAJOR_VERSION    (3U) 
#define SPI_CFG_C_MINOR_VERSION    (3U) 
#define SPI_CFG_C_PATCH_VERSION    (0U) 

#if (  (SPI_SW_MAJOR_VERSION != (2U)) \
    || (SPI_SW_MINOR_VERSION != (5U)) )
    #error "Version numbers of Spi_PBcfg.c and Spi.h are inconsistent!"
#endif

#if (  (SPI_CFG_MAJOR_VERSION != SPI_CFG_C_MAJOR_VERSION) \
    || (SPI_CFG_MINOR_VERSION != SPI_CFG_C_MINOR_VERSION) )
    #error "Version numbers of Spi_PBcfg.c and Spi_Cfg.h are inconsistent!"
#endif


/**********************************************************************************************************************
 *  GLOBAL CONFIG DATA
 **********************************************************************************************************************/
/* ------ Defintion of all job sets --------------------------------------- */
Spi_JobType SpiDriver0_JobSet0 [] = 
{ 
  1 
}; 
 
Spi_JobType SpiDriver0_JobSet1 [] = 
{ 
  0 
}; 


/* ------ Sequence configuration ------------------------------------------ */
static Spi_SeqConfigType  SpiDriver0_Seq_Config [2] = 
{ 
  { 
    SpiDriver0_JobSet0,  /* Spi_JobType* JobList_pt */ 
    (1u),  /*uint8 JobListSize_u8*/ 
    NULL_PTR, /* Spi_EndNotification SeqEnd_t */ 
    (TRUE),  /* Uninterruptable Seq */ 
    (SPI_SEQ_OK),  /* The current Seq Status */ 
    (SPI_JOB_NONE)  /* The current Job Index */ 
  }, 
  { 
    SpiDriver0_JobSet1,  /* Spi_JobType* JobList_pt */ 
    (1u),  /*uint8 JobListSize_u8*/ 
    NULL_PTR, /* Spi_EndNotification SeqEnd_t */ 
    (TRUE),  /* Uninterruptable Seq */ 
    (SPI_SEQ_OK),  /* The current Seq Status */ 
    (SPI_JOB_NONE)  /* The current Job Index */ 
  } 
}; 


/* ------ Defintion of all channel sets ----------------------------------- */
Spi_ChannelType SpiDriver0_ChannelSet0[] = 
{ 
  1 
}; 
 
Spi_ChannelType SpiDriver0_ChannelSet1[] = 
{ 
  0 
}; 


/* ------ Job configuration ----------------------------------------------- */
static Spi_JobConfigType SpiDriver0_Job_Config [2] = 
{ 
  { 
    SpiDriver0_ChannelSet0,  /* Spi_ChannelType* ChannelList_pt */ 
    1,  /* uint8 ChannelListSize_u8 */ 
    NULL_PTR,  /* Spi_EndNotification JobEnd_t */ 
    3,  /* uint8 JobPriority_u8 */ 
    1,  /* Spi_ExternalDeviceIdType ExternalDeviceId_u8 */ 
    (SPI_JOB_OK),  /* Current Job Status */ 
    (SPI_CHL_NONE)  /* Current Channel Index */ 
  }, 
  { 
    SpiDriver0_ChannelSet1,  /* Spi_ChannelType* ChannelList_pt */ 
    1,  /* uint8 ChannelListSize_u8 */ 
    NULL_PTR,  /* Spi_EndNotification JobEnd_t */ 
    3,  /* uint8 JobPriority_u8 */ 
    0,  /* Spi_ExternalDeviceIdType ExternalDeviceId_u8 */ 
    (SPI_JOB_OK),  /* Current Job Status */ 
    (SPI_CHL_NONE)  /* Current Channel Index */ 
  } 
}; 


/* ------ Declarations of internal buffers -------------------------------- */
/* SpiDriver0_Buffers */ 
uint8 SpiChannel_EQ3ReadBuffer[64]; 
uint8 SpiChannel_EQ3WriteBuffer[64]; 


/* ------ Channel configuration ------------------------------------------- */
static Spi_ChlConfigType  SpiDriver0_Chl_Config [2] = 
{ 
  { 
    NULL_PTR, /* BufferIB_Src_p */ 
    NULL_PTR, /* BufferIB_Dst_p */ 
    204, /* uint8  DefaultWriteValue_u8 */ 
    0, /* uint8  DefaultReadValue_u8 */ 
    1, /* uint16  HeadCtrlValue_u16 */ 
    2, /* Spi_NumberOfData MaxData_u16 for external buffer */ 
    (Spi_DataModeType)SPI_DATA_8BIT, /* 0 means 8 Bit Mode*/ 
    NULL_PTR, /* Current Source Buffer */ 
    NULL_PTR, /* Current Destination Buffer */ 
    0 /* External Buffer DataAmount */ 
  }, 
  { 
    SpiChannel_EQ3ReadBuffer , /* BufferIB_Src_p */ 
    SpiChannel_EQ3WriteBuffer , /* BufferIB_Dst_pt */ 
    203, /* uint8  DefaultWriteValue_u8 */ 
    0, /* uint8  DefaultReadValue_u8 */ 
    1, /* uint16  HeadCtrlValue_u16 */ 
    64, /* Spi_NumberOfData MaxData_u16 for internal buffer */ 
    (Spi_DataModeType)SPI_DATA_8BIT, /* 0 means 8 Bit Mode*/ 
    NULL_PTR, /* Current Source Buffer */ 
    NULL_PTR, /* Current Destination Buffer */ 
    0 /* External Buffer DataAmount */ 
  } 
}; 


/* ------ External device configuration ----------------------------------- */
static Spi_ExternalDeviceType SpiExternalDevices[] = 
{
  {
    SPI_CSIB2 /*  HwUnitId_u8  */ 
  }, 
  {
    SPI_CSIB1 /*  HwUnitId_u8  */ 
  }
};

/* ------ HwUnitStatus array ---------------------------------------------- */
static Spi_StatusType SpiHwUnitStatus[] =
{
  SPI_UNINIT /*  Spi_StatusType of HwUnit CSIB0  */ , 
  SPI_UNINIT /*  Spi_StatusType of HwUnit CSIB1  */ , 
  SPI_UNINIT /*  Spi_StatusType of HwUnit CSIB2  */ 
};

/* ----- Main Configuration struct ---------------------------------------- */
CONST(Spi_ConfigType, SPI_APPL_CONST) SpiDriver0 = 
{ 
  SpiDriver0_Seq_Config,  /* Sequence List pointer */ 
  2,  /* Sequence List size */ 
  SpiDriver0_Job_Config,  /* Job List pointer */ 
  2,  /* Job List size */ 
  SpiDriver0_Chl_Config,  /* Channel List pointer */ 
  2,  /* Channel List size */ 
  SpiExternalDevices,  /* External Device List pointer */ 
  2,  /*  External Device List size  */  
  SpiHwUnitStatus,  /* HwUnitStatus pointer */ 
  3 /*  Number of used HwUnits  */  
}; 


/*********************************************************************************************************************
 *  END OF FILE: Spi_PBcfg.C
 *********************************************************************************************************************/
