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
 *            Module: PduR
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_Lcfg.h
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


#if !defined (PDUR_LCFG_H)
# define PDUR_LCFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "PduR_Types.h"
# include "PduR_PBcfg.h"


/* include headers with symbolic name values */
/* \trace SPEC-2020167 */

#include "CanIf.h"
#include "Com_Cbk.h"
#include "CanTp.h"
#include "Dcm_Cbk.h"




/**********************************************************************************************************************
 * GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  PduRPCDataSwitches  PduR Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define PDUR_BMTXBUFFERARRAYRAM                                       STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferArrayRam' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERINDROM                                         STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferIndRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_BMTXBUFFERROMIDXOFBMTXBUFFERINDROM                       STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferIndRom.BmTxBufferRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERINSTANCERAM                                    STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferInstanceRam' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_LINEARBUFFERSIZEOFBMTXBUFFERINSTANCERAM                  STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferInstanceRam.LinearBufferSize' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_LINEARDATASIZEOFBMTXBUFFERINSTANCERAM                    STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferInstanceRam.LinearDataSize' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM                   STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferInstanceRam.PduRBufferState' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RXWRITEIDXOFBMTXBUFFERINSTANCERAM                        STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferInstanceRam.RxWriteIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TOTALBUFFERSIZEOFBMTXBUFFERINSTANCERAM                   STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferInstanceRam.TotalBufferSize' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TOTALDATASIZEOFBMTXBUFFERINSTANCERAM                     STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferInstanceRam.TotalDataSize' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TXBUFFERUSEDOFBMTXBUFFERINSTANCERAM                      STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferInstanceRam.TxBufferUsed' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TXREADIDXOFBMTXBUFFERINSTANCERAM                         STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferInstanceRam.TxReadIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERINSTANCEROM                                    STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferInstanceRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_BMTXBUFFERROMIDXOFBMTXBUFFERINSTANCEROM                  STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferInstanceRom.BmTxBufferRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERRAM                                            STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRam' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_INSTANCESTOPIDXOFBMTXBUFFERRAM                           STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRam.InstanceStopIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_LINEARBUFFERSIZEOFBMTXBUFFERRAM                          STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRam.LinearBufferSize' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_LINEARDATASIZEOFBMTXBUFFERRAM                            STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRam.LinearDataSize' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_PDURBUFFERSTATEOFBMTXBUFFERRAM                           STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRam.PduRBufferState' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RXLENGTHOFBMTXBUFFERRAM                                  STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRam.RxLength' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RXWRITEIDXOFBMTXBUFFERRAM                                STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRam.RxWriteIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TOTALBUFFERSIZEOFBMTXBUFFERRAM                           STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRam.TotalBufferSize' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TOTALDATASIZEOFBMTXBUFFERRAM                             STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRam.TotalDataSize' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TPBUFMGRSTATEOFBMTXBUFFERRAM                             STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRam.TpBufMgrState' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TXREADIDXOFBMTXBUFFERRAM                                 STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRam.TxReadIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERROM                                            STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_BMTXBUFFERARRAYRAMENDIDXOFBMTXBUFFERROM                  STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERARRAYRAMLENGTHOFBMTXBUFFERROM                  STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERARRAYRAMSTARTIDXOFBMTXBUFFERROM                STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERARRAYRAMUSEDOFBMTXBUFFERROM                    STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERINSTANCEROMENDIDXOFBMTXBUFFERROM               STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferInstanceRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERINSTANCEROMLENGTHOFBMTXBUFFERROM               STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferInstanceRomLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERINSTANCEROMSTARTIDXOFBMTXBUFFERROM             STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferInstanceRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERINSTANCEROMUSEDOFBMTXBUFFERROM                 STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferInstanceRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_CANCELRECEIVEFCTPTR                                      STD_OFF  /**< Deactivateable: 'PduR_CancelReceiveFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_CANCELTRANSMITFCTPTR                                     STD_OFF  /**< Deactivateable: 'PduR_CancelTransmitFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_CHANGEPARAMETERFCTPTR                                    STD_OFF  /**< Deactivateable: 'PduR_ChangeParameterFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_CONFIGID                                                 STD_ON
#define PDUR_COPYRXDATAFCTPTR                                         STD_ON
#define PDUR_COPYRXDATARXSMTRANSITION                                 STD_OFF  /**< Deactivateable: 'PduR_CopyRxDataRxSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFCOPYRXDATARXSMTRANSITION                         STD_OFF  /**< Deactivateable: 'PduR_CopyRxDataRxSmTransition.FctPtr' Reason: 'No TransportProtocol Gateway Routing available' */
#define PDUR_COPYTXDATAFCTPTR                                         STD_ON
#define PDUR_COPYTXDATATXINSTSMTRANSITION                             STD_OFF  /**< Deactivateable: 'PduR_CopyTxDataTxInstSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFCOPYTXDATATXINSTSMTRANSITION                     STD_OFF  /**< Deactivateable: 'PduR_CopyTxDataTxInstSmTransition.FctPtr' Reason: 'No TransportProtocol Gateway Routing available' */
#define PDUR_ENABLEDCNTOFRPGDESTSTATE                                 STD_OFF  /**< Deactivateable: 'PduR_EnabledCntOfRpgDestState' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FIFOINITVALUES                                           STD_OFF  /**< Deactivateable: 'PduR_FiFoInitValues' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FINALMAGICNUMBER                                         STD_OFF  /**< Deactivateable: 'PduR_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define PDUR_FINISHREADFMSMTRANSITION                                 STD_OFF  /**< Deactivateable: 'PduR_FinishReadFmSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFFINISHREADFMSMTRANSITION                         STD_OFF  /**< Deactivateable: 'PduR_FinishReadFmSmTransition.FctPtr' Reason: 'No queued Routing Paths available' */
#define PDUR_FINISHRECEPTIONRMSMTRANSITION                            STD_OFF  /**< Deactivateable: 'PduR_FinishReceptionRmSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFFINISHRECEPTIONRMSMTRANSITION                    STD_OFF  /**< Deactivateable: 'PduR_FinishReceptionRmSmTransition.FctPtr' Reason: 'No TransportProtocol Gateway Routing available' */
#define PDUR_FINISHTRANSMISSIONRMSMTRANSITION                         STD_OFF  /**< Deactivateable: 'PduR_FinishTransmissionRmSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFFINISHTRANSMISSIONRMSMTRANSITION                 STD_OFF  /**< Deactivateable: 'PduR_FinishTransmissionRmSmTransition.FctPtr' Reason: 'No TransportProtocol Gateway Routing available' */
#define PDUR_FINISHWRITEFMSMTRANSITION                                STD_OFF  /**< Deactivateable: 'PduR_FinishWriteFmSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFFINISHWRITEFMSMTRANSITION                        STD_OFF  /**< Deactivateable: 'PduR_FinishWriteFmSmTransition.FctPtr' Reason: 'No queued Routing Paths available' */
#define PDUR_FMFIFOELEMENTRAM                                         STD_OFF  /**< Deactivateable: 'PduR_FmFifoElementRam' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERROMIDXOFFMFIFOELEMENTRAM                       STD_OFF  /**< Deactivateable: 'PduR_FmFifoElementRam.BmTxBufferRomIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_DEDICATEDTXBUFFEROFFMFIFOELEMENTRAM                      STD_OFF  /**< Deactivateable: 'PduR_FmFifoElementRam.DedicatedTxBuffer' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMSRCIDXOFFMFIFOELEMENTRAM                               STD_OFF  /**< Deactivateable: 'PduR_FmFifoElementRam.RmSrcIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_STATEOFFMFIFOELEMENTRAM                                  STD_OFF  /**< Deactivateable: 'PduR_FmFifoElementRam.State' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FMFIFOINSTANCERAM                                        STD_OFF  /**< Deactivateable: 'PduR_FmFifoInstanceRam' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERINSTANCEROMIDXOFFMFIFOINSTANCERAM              STD_OFF  /**< Deactivateable: 'PduR_FmFifoInstanceRam.BmTxBufferInstanceRomIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FMFIFOINSTANCEROM                                        STD_OFF  /**< Deactivateable: 'PduR_FmFifoInstanceRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FMFIFOROMIDXOFFMFIFOINSTANCEROM                          STD_OFF  /**< Deactivateable: 'PduR_FmFifoInstanceRom.FmFifoRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FMFIFORAM                                                STD_OFF  /**< Deactivateable: 'PduR_FmFifoRam' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FILLLEVELOFFMFIFORAM                                     STD_OFF  /**< Deactivateable: 'PduR_FmFifoRam.FillLevel' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FMFIFOELEMENTRAMREADIDXOFFMFIFORAM                       STD_OFF  /**< Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamReadIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FMFIFOELEMENTRAMWRITEIDXOFFMFIFORAM                      STD_OFF  /**< Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamWriteIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_PENDINGCONFIRMATIONSOFFMFIFORAM                          STD_OFF  /**< Deactivateable: 'PduR_FmFifoRam.PendingConfirmations' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TPTXSMSTATEOFFMFIFORAM                                   STD_OFF  /**< Deactivateable: 'PduR_FmFifoRam.TpTxSmState' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FMFIFOROM                                                STD_OFF  /**< Deactivateable: 'PduR_FmFifoRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FMFIFOELEMENTRAMENDIDXOFFMFIFOROM                        STD_OFF  /**< Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FMFIFOELEMENTRAMLENGTHOFFMFIFOROM                        STD_OFF  /**< Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FMFIFOELEMENTRAMSTARTIDXOFFMFIFOROM                      STD_OFF  /**< Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FMFLUSHFIFOELEMENT                                       STD_OFF  /**< Deactivateable: 'PduR_FmFlushFifoElement' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFFMFLUSHFIFOELEMENT                               STD_OFF  /**< Deactivateable: 'PduR_FmFlushFifoElement.FctPtr' Reason: 'No queued IF Gateway Routing Paths available' */
#define PDUR_IFROUTINGSTATETABLE                                      STD_ON
#define PDUR_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE STD_ON
#define PDUR_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE STD_ON
#define PDUR_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE STD_ON
#define PDUR_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE STD_ON
#define PDUR_IFRXINDICATIONFCTPTR                                     STD_ON
#define PDUR_IFTRIGGERTRANSMITFCTPTR                                  STD_OFF  /**< Deactivateable: 'PduR_IfTriggerTransmitFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_IFTXCONFIRMATIONFCTPTR                                   STD_OFF  /**< Deactivateable: 'PduR_IfTxConfirmationFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_INITDATAHASHCODE                                         STD_OFF  /**< Deactivateable: 'PduR_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define PDUR_INITIALIZED                                              STD_ON
#define PDUR_RMDESTROM                                                STD_OFF  /**< Deactivateable: 'PduR_RmDestRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_COPYRXDATAFCTPTRIDXOFRMDESTROM                           STD_OFF  /**< Deactivateable: 'PduR_RmDestRom.CopyRxDataFctPtrIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_COPYRXDATAFCTPTRUSEDOFRMDESTROM                          STD_OFF  /**< Deactivateable: 'PduR_RmDestRom.CopyRxDataFctPtrUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_DESTHNDOFRMDESTROM                                       STD_OFF  /**< Deactivateable: 'PduR_RmDestRom.DestHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTRPGROMIDXOFRMDESTROM                               STD_OFF  /**< Deactivateable: 'PduR_RmDestRom.RmDestRpgRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTRPGROMUSEDOFRMDESTROM                              STD_OFF  /**< Deactivateable: 'PduR_RmDestRom.RmDestRpgRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMGDESTROMIDXOFRMDESTROM                                 STD_OFF  /**< Deactivateable: 'PduR_RmDestRom.RmGDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMGDESTROMUSEDOFRMDESTROM                                STD_OFF  /**< Deactivateable: 'PduR_RmDestRom.RmGDestRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_STARTOFRECEPTIONFCTPTRIDXOFRMDESTROM                     STD_OFF  /**< Deactivateable: 'PduR_RmDestRom.StartOfReceptionFctPtrIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_STARTOFRECEPTIONFCTPTRUSEDOFRMDESTROM                    STD_OFF  /**< Deactivateable: 'PduR_RmDestRom.StartOfReceptionFctPtrUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TPRXINDICATIONFCTPTRIDXOFRMDESTROM                       STD_OFF  /**< Deactivateable: 'PduR_RmDestRom.TpRxIndicationFctPtrIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TPRXINDICATIONFCTPTRUSEDOFRMDESTROM                      STD_OFF  /**< Deactivateable: 'PduR_RmDestRom.TpRxIndicationFctPtrUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TRANSMITFCTPTRIDXOFRMDESTROM                             STD_OFF  /**< Deactivateable: 'PduR_RmDestRom.TransmitFctPtrIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TRANSMITFCTPTRUSEDOFRMDESTROM                            STD_OFF  /**< Deactivateable: 'PduR_RmDestRom.TransmitFctPtrUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTRPGROM                                             STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_INITIALENABLEDCNTOFRMDESTRPGROM                          STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRom.InitialEnabledCnt' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMGDESTROMIDXOFRMDESTRPGROM                              STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRom.RmGDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMGDESTROMIFIDXOFRMDESTRPGROM                            STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRom.RmGDestRomIfIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMGDESTROMIFUSEDOFRMDESTRPGROM                           STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRom.RmGDestRomIfUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMGDESTROMUSEDOFRMDESTRPGROM                             STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRom.RmGDestRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TXIFMULTI2LOIDXOFRMDESTRPGROM                            STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRom.TxIfMulti2LoIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TXIFMULTI2LOUSEDOFRMDESTRPGROM                           STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRom.TxIfMulti2LoUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTRPGROMIND                                          STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRomInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMGDESTRAM                                               STD_OFF  /**< Deactivateable: 'PduR_RmGDestRam' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_PDURFIFOROUTINGSTATEOFRMGDESTRAM                         STD_OFF  /**< Deactivateable: 'PduR_RmGDestRam.PduRFiFoRoutingState' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TPTXINSTSMSTATEOFRMGDESTRAM                              STD_OFF  /**< Deactivateable: 'PduR_RmGDestRam.TpTxInstSmState' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMGDESTROM                                               STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_BMTXBUFFERINDROMENDIDXOFRMGDESTROM                       STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.BmTxBufferIndRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERINDROMLENGTHOFRMGDESTROM                       STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.BmTxBufferIndRomLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERINDROMSTARTIDXOFRMGDESTROM                     STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.BmTxBufferIndRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERINDROMUSEDOFRMGDESTROM                         STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.BmTxBufferIndRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_DEDICATEDTXBUFFEROFRMGDESTROM                            STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.DedicatedTxBuffer' Reason: 'No CommunicationInterface Gateway Routing available' */
#define PDUR_DESTHNDOFRMGDESTROM                                      STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.DestHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_DESTLAYERTYPEOFRMGDESTROM                                STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.DestLayerType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FIFOINITVALUESENDIDXOFRMGDESTROM                         STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.FiFoInitValuesEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FIFOINITVALUESLENGTHOFRMGDESTROM                         STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.FiFoInitValuesLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FIFOINITVALUESSTARTIDXOFRMGDESTROM                       STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.FiFoInitValuesStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FIFOINITVALUESUSEDOFRMGDESTROM                           STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.FiFoInitValuesUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FIFOTYPEOFRMGDESTROM                                     STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.FifoType' Reason: 'No CommunicationInterface Gateway Routing available' */
#define PDUR_FMFIFOINSTANCEROMIDXOFRMGDESTROM                         STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.FmFifoInstanceRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FMFIFOINSTANCEROMUSEDOFRMGDESTROM                        STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.FmFifoInstanceRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_IF2LOMULTIROUTINGOFRMGDESTROM                            STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.If2LoMultiRouting' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_IFRXINDICATIONFCTPTRIDXOFRMGDESTROM                      STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.IfRxIndicationFctPtrIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_IFRXINDICATIONFCTPTRUSEDOFRMGDESTROM                     STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.IfRxIndicationFctPtrUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_MAXPDULENGTHOFRMGDESTROM                                 STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.MaxPduLength' Reason: 'No CommunicationInterface Gateway Routing available' */
#define PDUR_RMIFRXINDICATIONFCTPTRIDXOFRMGDESTROM                    STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.RmIfRxIndicationFctPtrIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMIFRXINDICATIONFCTPTRUSEDOFRMGDESTROM                   STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.RmIfRxIndicationFctPtrUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SMGDESTFILTERFCTPTRIDXOFRMGDESTROM                       STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.SmGDestFilterFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMGDESTFILTERFCTPTRUSEDOFRMGDESTROM                      STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.SmGDestFilterFctPtrUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMGDESTROMIDXOFRMGDESTROM                                STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.SmGDestRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMGDESTROMUSEDOFRMGDESTROM                               STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.SmGDestRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_TRANSMITFCTPTRIDXOFRMGDESTROM                            STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.TransmitFctPtrIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TRANSMITFCTPTRUSEDOFRMGDESTROM                           STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.TransmitFctPtrUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMIFRXINDICATIONFCTPTR                                   STD_OFF  /**< Deactivateable: 'PduR_RmIfRxIndicationFctPtr' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMSRCRAM                                                 STD_OFF  /**< Deactivateable: 'PduR_RmSrcRam' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FMFIFOELEMENTRAMWRITEIDXOFRMSRCRAM                       STD_OFF  /**< Deactivateable: 'PduR_RmSrcRam.FmFifoElementRamWriteIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TPRXSMSTATEOFRMSRCRAM                                    STD_OFF  /**< Deactivateable: 'PduR_RmSrcRam.TpRxSmState' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMSRCROM                                                 STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_BMTXBUFFERINDROMENDIDXOFRMSRCROM                         STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.BmTxBufferIndRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERINDROMLENGTHOFRMSRCROM                         STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.BmTxBufferIndRomLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERINDROMSTARTIDXOFRMSRCROM                       STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.BmTxBufferIndRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_BMTXBUFFERINDROMUSEDOFRMSRCROM                           STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.BmTxBufferIndRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_DEDICATEDTXBUFFEROFRMSRCROM                              STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.DedicatedTxBuffer' Reason: 'No PduRTxBuffer exists' */
#define PDUR_FMFIFOROMIDXOFRMSRCROM                                   STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.FmFifoRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_FMFIFOROMUSEDOFRMSRCROM                                  STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.FmFifoRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_METADATALENGTHOFRMSRCROM                                 STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.MetaDataLength' Reason: 'Meta Data Support is not active' */
#define PDUR_METADATALENGTHUSEDOFRMSRCROM                             STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.MetaDataLengthUsed' Reason: 'No TransportProtocol Gateway Routing available' */
#define PDUR_RMDESTROMENDIDXOFRMSRCROM                                STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.RmDestRomEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTROMLENGTHOFRMSRCROM                                STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.RmDestRomLength' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTROMSTARTIDXOFRMSRCROM                              STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.RmDestRomStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RXIF2DESTKEYOFRMSRCROM                                   STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.RxIf2DestKey' Reason: 'the optional indirection is deactivated because RmSrcRomUsedOfRxIf2Dest is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_SMSRCFILTERFCTPTRIDXOFRMSRCROM                           STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.SmSrcFilterFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSRCFILTERFCTPTRUSEDOFRMSRCROM                          STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.SmSrcFilterFctPtrUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSRCROMIDXOFRMSRCROM                                    STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.SmSrcRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSRCROMUSEDOFRMSRCROM                                   STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.SmSrcRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_TPTHRESHOLDOFRMSRCROM                                    STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.TpThreshold' Reason: 'No TransportProtocol Gateway Routing available' */
#define PDUR_RPG                                                      STD_OFF  /**< Deactivateable: 'PduR_Rpg' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_ENABLEDATINITOFRPG                                       STD_OFF  /**< Deactivateable: 'PduR_Rpg.EnabledAtInit' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_INVALIDHNDOFRPG                                          STD_OFF  /**< Deactivateable: 'PduR_Rpg.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTRPGROMINDENDIDXOFRPG                               STD_OFF  /**< Deactivateable: 'PduR_Rpg.RmDestRpgRomIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTRPGROMINDSTARTIDXOFRPG                             STD_OFF  /**< Deactivateable: 'PduR_Rpg.RmDestRpgRomIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTRPGROMINDUSEDOFRPG                                 STD_OFF  /**< Deactivateable: 'PduR_Rpg.RmDestRpgRomIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RPGSTATE                                                 STD_OFF  /**< Deactivateable: 'PduR_RpgState' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_ENABLEDOFRPGSTATE                                        STD_OFF  /**< Deactivateable: 'PduR_RpgState.Enabled' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RXIF2DEST                                                STD_ON
#define PDUR_BSWMPDURRXINDICATIONCALLBACKOFRXIF2DEST                  STD_OFF  /**< Deactivateable: 'PduR_RxIf2Dest.BswMPduRRxIndicationCallback' Reason: 'Callback Support is not active' */
#define PDUR_DESTHNDOFRXIF2DEST                                       STD_ON
#define PDUR_IFRXINDICATIONFCTPTRIDXOFRXIF2DEST                       STD_ON
#define PDUR_INVALIDHNDOFRXIF2DEST                                    STD_OFF  /**< Deactivateable: 'PduR_RxIf2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxIf2Dest is always 'false' due to this, the array is deactivated.' */
#define PDUR_RMDESTRPGROMIDXOFRXIF2DEST                               STD_OFF  /**< Deactivateable: 'PduR_RxIf2Dest.RmDestRpgRomIdx' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRxIf2Dest is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMDESTRPGROMUSEDOFRXIF2DEST                              STD_OFF  /**< Deactivateable: 'PduR_RxIf2Dest.RmDestRpgRomUsed' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRxIf2Dest is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RXTP2DEST                                                STD_ON
#define PDUR_BSWMPDURTPRXINDICATIONCALLBACKOFRXTP2DEST                STD_OFF  /**< Deactivateable: 'PduR_RxTp2Dest.BswMPduRTpRxIndicationCallback' Reason: 'Callback Support is not active' */
#define PDUR_BSWMPDURTPSTARTOFRECEPTIONCALLBACKOFRXTP2DEST            STD_OFF  /**< Deactivateable: 'PduR_RxTp2Dest.BswMPduRTpStartOfReceptionCallback' Reason: 'Callback Support is not active' */
#define PDUR_COPYRXDATAFCTPTRIDXOFRXTP2DEST                           STD_ON
#define PDUR_DESTHNDOFRXTP2DEST                                       STD_ON
#define PDUR_INVALIDHNDOFRXTP2DEST                                    STD_OFF  /**< Deactivateable: 'PduR_RxTp2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Dest is always 'false' due to this, the array is deactivated.' */
#define PDUR_RMDESTRPGROMIDXOFRXTP2DEST                               STD_OFF  /**< Deactivateable: 'PduR_RxTp2Dest.RmDestRpgRomIdx' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRxTp2Dest is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMDESTRPGROMUSEDOFRXTP2DEST                              STD_OFF  /**< Deactivateable: 'PduR_RxTp2Dest.RmDestRpgRomUsed' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRxTp2Dest is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_STARTOFRECEPTIONFCTPTRIDXOFRXTP2DEST                     STD_ON
#define PDUR_TPRXINDICATIONFCTPTRIDXOFRXTP2DEST                       STD_ON
#define PDUR_RXTP2SRC                                                 STD_ON
#define PDUR_CANCELRECEIVEFCTPTRIDXOFRXTP2SRC                         STD_OFF  /**< Deactivateable: 'PduR_RxTp2Src.CancelReceiveFctPtrIdx' Reason: 'the optional indirection is deactivated because CancelReceiveFctPtrUsedOfRxTp2Src is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_CANCELRECEIVEFCTPTRUSEDOFRXTP2SRC                        STD_OFF  /**< Deactivateable: 'PduR_RxTp2Src.CancelReceiveFctPtrUsed' Reason: 'the optional indirection is deactivated because CancelReceiveFctPtrUsedOfRxTp2Src is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_CHANGEPARAMETERFCTPTRIDXOFRXTP2SRC                       STD_OFF  /**< Deactivateable: 'PduR_RxTp2Src.ChangeParameterFctPtrIdx' Reason: 'the optional indirection is deactivated because ChangeParameterFctPtrUsedOfRxTp2Src is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_CHANGEPARAMETERFCTPTRUSEDOFRXTP2SRC                      STD_OFF  /**< Deactivateable: 'PduR_RxTp2Src.ChangeParameterFctPtrUsed' Reason: 'the optional indirection is deactivated because ChangeParameterFctPtrUsedOfRxTp2Src is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_INVALIDHNDOFRXTP2SRC                                     STD_OFF  /**< Deactivateable: 'PduR_RxTp2Src.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Src is always 'false' due to this, the array is deactivated.' */
#define PDUR_RMDESTRPGROMIDXOFRXTP2SRC                                STD_OFF  /**< Deactivateable: 'PduR_RxTp2Src.RmDestRpgRomIdx' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRxTp2Src is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMDESTRPGROMUSEDOFRXTP2SRC                               STD_OFF  /**< Deactivateable: 'PduR_RxTp2Src.RmDestRpgRomUsed' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRxTp2Src is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_SRCHNDOFRXTP2SRC                                         STD_ON
#define PDUR_SIZEOFCOPYRXDATAFCTPTR                                   STD_ON
#define PDUR_SIZEOFCOPYTXDATAFCTPTR                                   STD_ON
#define PDUR_SIZEOFIFROUTINGSTATETABLE                                STD_ON
#define PDUR_SIZEOFIFRXINDICATIONFCTPTR                               STD_ON
#define PDUR_SIZEOFRXIF2DEST                                          STD_ON
#define PDUR_SIZEOFRXTP2DEST                                          STD_ON
#define PDUR_SIZEOFRXTP2SRC                                           STD_ON
#define PDUR_SIZEOFSTARTOFRECEPTIONFCTPTR                             STD_ON
#define PDUR_SIZEOFTPRXINDICATIONFCTPTR                               STD_ON
#define PDUR_SIZEOFTPTXCONFIRMATIONFCTPTR                             STD_ON
#define PDUR_SIZEOFTRANSMITFCTPTR                                     STD_ON
#define PDUR_SIZEOFTX2LO                                              STD_ON
#define PDUR_SIZEOFTXIF2UP                                            STD_ON
#define PDUR_SIZEOFTXTP2SRC                                           STD_ON
#define PDUR_SMDATAPLANEROM                                           STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMFIBRAMENDIDXOFSMDATAPLANEROM                           STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamEndIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMFIBRAMSTARTIDXOFSMDATAPLANEROM                         STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamStartIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMFIBRAMUSEDOFSMDATAPLANEROM                             STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYROMIDXOFSMDATAPLANEROM  STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmLinearTaToSaCalculationStrategyRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYROMUSEDOFSMDATAPLANEROM STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmLinearTaToSaCalculationStrategyRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSATAFROMMETADATACALCULATIONSTRATEGYROMIDXOFSMDATAPLANEROM STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmSaTaFromMetaDataCalculationStrategyRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSATAFROMMETADATACALCULATIONSTRATEGYROMUSEDOFSMDATAPLANEROM STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmSaTaFromMetaDataCalculationStrategyRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMFIBRAM                                                 STD_OFF  /**< Deactivateable: 'PduR_SmFibRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_LEARNEDCONNECTIONIDOFSMFIBRAM                            STD_OFF  /**< Deactivateable: 'PduR_SmFibRam.LearnedConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMGDESTFILTERFCTPTR                                      STD_OFF  /**< Deactivateable: 'PduR_SmGDestFilterFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMGDESTROM                                               STD_OFF  /**< Deactivateable: 'PduR_SmGDestRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_CONNECTIONIDOFSMGDESTROM                                 STD_OFF  /**< Deactivateable: 'PduR_SmGDestRom.ConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_METADATALENGTHOFSMGDESTROM                               STD_OFF  /**< Deactivateable: 'PduR_SmGDestRom.MetaDataLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMDATAPLANEROMIDXOFSMGDESTROM                            STD_OFF  /**< Deactivateable: 'PduR_SmGDestRom.SmDataPlaneRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYGETSAFCTPTR             STD_OFF  /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyGetSaFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYROM                     STD_OFF  /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_MASKOFSMLINEARTATOSACALCULATIONSTRATEGYROM               STD_OFF  /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom.Mask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_OFFSETOFSMLINEARTATOSACALCULATIONSTRATEGYROM             STD_OFF  /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom.Offset' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSATAFROMMETADATACALCULATIONSTRATEGYROM                 STD_OFF  /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SAMASKOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM         STD_OFF  /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.SaMask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SASTARTBITOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM     STD_OFF  /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.SaStartBit' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_TAMASKOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM         STD_OFF  /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.TaMask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_TASTARTBITOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM     STD_OFF  /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.TaStartBit' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSRCFILTERFCTPTR                                        STD_OFF  /**< Deactivateable: 'PduR_SmSrcFilterFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSRCROM                                                 STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_CONNECTIONIDOFSMSRCROM                                   STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.ConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_METADATALENGTHOFSMSRCROM                                 STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.MetaDataLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMDATAPLANEROMIDXOFSMSRCROM                              STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.SmDataPlaneRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYGETSAFCTPTRIDXOFSMSRCROM STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.SmLinearTaToSaCalculationStrategyGetSaFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYGETSAFCTPTRUSEDOFSMSRCROM STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.SmLinearTaToSaCalculationStrategyGetSaFctPtrUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_STARTOFRECEPTIONFCTPTR                                   STD_ON
#define PDUR_STARTOFRECEPTIONRXSMTRANSITION                           STD_OFF  /**< Deactivateable: 'PduR_StartOfReceptionRxSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFSTARTOFRECEPTIONRXSMTRANSITION                   STD_OFF  /**< Deactivateable: 'PduR_StartOfReceptionRxSmTransition.FctPtr' Reason: 'No TransportProtocol Gateway Routing available' */
#define PDUR_TPACTIVATENEXTFIFOSMTRANSITION                           STD_OFF  /**< Deactivateable: 'PduR_TpActivateNextFifoSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFTPACTIVATENEXTFIFOSMTRANSITION                   STD_OFF  /**< Deactivateable: 'PduR_TpActivateNextFifoSmTransition.FctPtr' Reason: 'No TransportProtocol Gateway Routing available' */
#define PDUR_TPACTIVATEREADFIFOSMTRANSITION                           STD_OFF  /**< Deactivateable: 'PduR_TpActivateReadFifoSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFTPACTIVATEREADFIFOSMTRANSITION                   STD_OFF  /**< Deactivateable: 'PduR_TpActivateReadFifoSmTransition.FctPtr' Reason: 'No queued Routing Paths available' */
#define PDUR_TPACTIVATEWRITEFIFOSMTRANSITION                          STD_OFF  /**< Deactivateable: 'PduR_TpActivateWriteFifoSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFTPACTIVATEWRITEFIFOSMTRANSITION                  STD_OFF  /**< Deactivateable: 'PduR_TpActivateWriteFifoSmTransition.FctPtr' Reason: 'No queued Routing Paths available' */
#define PDUR_TPCANCELRECEIVEFIFOSMTRANSITION                          STD_OFF  /**< Deactivateable: 'PduR_TpCancelReceiveFifoSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFTPCANCELRECEIVEFIFOSMTRANSITION                  STD_OFF  /**< Deactivateable: 'PduR_TpCancelReceiveFifoSmTransition.FctPtr' Reason: 'No TransportProtocol Gateway Routing available' */
#define PDUR_TPCANCELTRANSMITTXINSTSMTRANSITION                       STD_OFF  /**< Deactivateable: 'PduR_TpCancelTransmitTxInstSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFTPCANCELTRANSMITTXINSTSMTRANSITION               STD_OFF  /**< Deactivateable: 'PduR_TpCancelTransmitTxInstSmTransition.FctPtr' Reason: 'No TransportProtocol Gateway Routing available' */
#define PDUR_TPCHECKREADY2TRANSMITRMSMTRANSITION                      STD_OFF  /**< Deactivateable: 'PduR_TpCheckReady2TransmitRmSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFTPCHECKREADY2TRANSMITRMSMTRANSITION              STD_OFF  /**< Deactivateable: 'PduR_TpCheckReady2TransmitRmSmTransition.FctPtr' Reason: 'No TransportProtocol Gateway Routing available' */
#define PDUR_TPDISABLEROUTINGTXSMTRANSITION                           STD_OFF  /**< Deactivateable: 'PduR_TpDisableRoutingTxSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFTPDISABLEROUTINGTXSMTRANSITION                   STD_OFF  /**< Deactivateable: 'PduR_TpDisableRoutingTxSmTransition.FctPtr' Reason: 'No Gw Tp RoutingPaths which is part of a RPG' */
#define PDUR_TPRXINDICATIONFCTPTR                                     STD_ON
#define PDUR_TPRXINDICATIONRXSMTRANSITION                             STD_OFF  /**< Deactivateable: 'PduR_TpRxIndicationRxSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFTPRXINDICATIONRXSMTRANSITION                     STD_OFF  /**< Deactivateable: 'PduR_TpRxIndicationRxSmTransition.FctPtr' Reason: 'No TransportProtocol Gateway Routing available' */
#define PDUR_TPTRIGGERTRANSMITTXINSTSMTRANSITION                      STD_OFF  /**< Deactivateable: 'PduR_TpTriggerTransmitTxInstSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFTPTRIGGERTRANSMITTXINSTSMTRANSITION              STD_OFF  /**< Deactivateable: 'PduR_TpTriggerTransmitTxInstSmTransition.FctPtr' Reason: 'No TransportProtocol Gateway Routing available' */
#define PDUR_TPTXCONFIRMATIONFCTPTR                                   STD_ON
#define PDUR_TPTXCONFIRMATIONTXSMTRANSITION                           STD_OFF  /**< Deactivateable: 'PduR_TpTxConfirmationTxSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFTPTXCONFIRMATIONTXSMTRANSITION                   STD_OFF  /**< Deactivateable: 'PduR_TpTxConfirmationTxSmTransition.FctPtr' Reason: 'No TransportProtocol Gateway Routing available' */
#define PDUR_TRANSMITFCTPTR                                           STD_ON
#define PDUR_TX2LO                                                    STD_ON
#define PDUR_BSWMPDURTRANSMITCALLBACKOFTX2LO                          STD_OFF  /**< Deactivateable: 'PduR_Tx2Lo.BswMPduRTransmitCallback' Reason: 'Callback Support is not active' */
#define PDUR_CANCELTRANSMITFCTPTRIDXOFTX2LO                           STD_OFF  /**< Deactivateable: 'PduR_Tx2Lo.CancelTransmitFctPtrIdx' Reason: 'the optional indirection is deactivated because CancelTransmitFctPtrUsedOfTx2Lo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_CANCELTRANSMITFCTPTRUSEDOFTX2LO                          STD_OFF  /**< Deactivateable: 'PduR_Tx2Lo.CancelTransmitFctPtrUsed' Reason: 'the optional indirection is deactivated because CancelTransmitFctPtrUsedOfTx2Lo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_DESTHNDOFTX2LO                                           STD_ON
#define PDUR_INVALIDHNDOFTX2LO                                        STD_OFF  /**< Deactivateable: 'PduR_Tx2Lo.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTx2Lo is always 'false' due to this, the array is deactivated.' */
#define PDUR_RMDESTRPGROMIDXOFTX2LO                                   STD_OFF  /**< Deactivateable: 'PduR_Tx2Lo.RmDestRpgRomIdx' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfTx2Lo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMDESTRPGROMUSEDOFTX2LO                                  STD_OFF  /**< Deactivateable: 'PduR_Tx2Lo.RmDestRpgRomUsed' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfTx2Lo is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_TRANSMITFCTPTRIDXOFTX2LO                                 STD_ON
#define PDUR_TXIF2UP                                                  STD_OFF  /**< Deactivateable: 'PduR_TxIf2Up' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_BSWMPDURTXCONFIRMATIONCALLBACKOFTXIF2UP                  STD_OFF  /**< Deactivateable: 'PduR_TxIf2Up.BswMPduRTxConfirmationCallback' Reason: 'Callback Support is not active' */
#define PDUR_DESTHNDOFTXIF2UP                                         STD_OFF  /**< Deactivateable: 'PduR_TxIf2Up.DestHnd' Reason: 'the value of PduR_DestHndOfTxIf2Up is always 'PDUR_NO_DESTHNDOFTXIF2UP' due to this, the array is deactivated.' */
#define PDUR_IFTRIGGERTRANSMITFCTPTRIDXOFTXIF2UP                      STD_OFF  /**< Deactivateable: 'PduR_TxIf2Up.IfTriggerTransmitFctPtrIdx' Reason: 'the optional indirection is deactivated because IfTriggerTransmitFctPtrUsedOfTxIf2Up is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_IFTRIGGERTRANSMITFCTPTRUSEDOFTXIF2UP                     STD_OFF  /**< Deactivateable: 'PduR_TxIf2Up.IfTriggerTransmitFctPtrUsed' Reason: 'the optional indirection is deactivated because IfTriggerTransmitFctPtrUsedOfTxIf2Up is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_IFTXCONFIRMATIONFCTPTRIDXOFTXIF2UP                       STD_OFF  /**< Deactivateable: 'PduR_TxIf2Up.IfTxConfirmationFctPtrIdx' Reason: 'the optional indirection is deactivated because IfTxConfirmationFctPtrUsedOfTxIf2Up is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_IFTXCONFIRMATIONFCTPTRUSEDOFTXIF2UP                      STD_OFF  /**< Deactivateable: 'PduR_TxIf2Up.IfTxConfirmationFctPtrUsed' Reason: 'the optional indirection is deactivated because IfTxConfirmationFctPtrUsedOfTxIf2Up is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_INVALIDHNDOFTXIF2UP                                      STD_OFF  /**< Deactivateable: 'PduR_TxIf2Up.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxIf2Up is always 'false' due to this, the array is deactivated.' */
#define PDUR_TXIFMULTI2LO                                             STD_OFF  /**< Deactivateable: 'PduR_TxIfMulti2Lo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_ANYTXCONFREQUIREDOFTXIFMULTI2LO                          STD_OFF  /**< Deactivateable: 'PduR_TxIfMulti2Lo.AnyTxConfRequired' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_CANCELTRANSMITFCTPTRIDXOFTXIFMULTI2LO                    STD_OFF  /**< Deactivateable: 'PduR_TxIfMulti2Lo.CancelTransmitFctPtrIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_CANCELTRANSMITFCTPTRUSEDOFTXIFMULTI2LO                   STD_OFF  /**< Deactivateable: 'PduR_TxIfMulti2Lo.CancelTransmitFctPtrUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_DESTHNDOFTXIFMULTI2LO                                    STD_OFF  /**< Deactivateable: 'PduR_TxIfMulti2Lo.DestHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_IFTRIGGERTRANSMITFCTPTRIDXOFTXIFMULTI2LO                 STD_OFF  /**< Deactivateable: 'PduR_TxIfMulti2Lo.IfTriggerTransmitFctPtrIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_IFTRIGGERTRANSMITFCTPTRUSEDOFTXIFMULTI2LO                STD_OFF  /**< Deactivateable: 'PduR_TxIfMulti2Lo.IfTriggerTransmitFctPtrUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_IFTXCONFIRMATIONFCTPTRIDXOFTXIFMULTI2LO                  STD_OFF  /**< Deactivateable: 'PduR_TxIfMulti2Lo.IfTxConfirmationFctPtrIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_IFTXCONFIRMATIONFCTPTRUSEDOFTXIFMULTI2LO                 STD_OFF  /**< Deactivateable: 'PduR_TxIfMulti2Lo.IfTxConfirmationFctPtrUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SRCHNDOFTXIFMULTI2LO                                     STD_OFF  /**< Deactivateable: 'PduR_TxIfMulti2Lo.SrcHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SRCMODULEIDXOFTXIFMULTI2LO                               STD_OFF  /**< Deactivateable: 'PduR_TxIfMulti2Lo.SrcModuleIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TRANSMITFCTPTRIDXOFTXIFMULTI2LO                          STD_OFF  /**< Deactivateable: 'PduR_TxIfMulti2Lo.TransmitFctPtrIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TXIFMULTI2LOSTATEIDXOFTXIFMULTI2LO                       STD_OFF  /**< Deactivateable: 'PduR_TxIfMulti2Lo.TxIfMulti2LoStateIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TXIFMULTI2LOSTATE                                        STD_OFF  /**< Deactivateable: 'PduR_TxIfMulti2LoState' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_CALLERNEEDSTRIGGERTRANSMITOFTXIFMULTI2LOSTATE            STD_OFF  /**< Deactivateable: 'PduR_TxIfMulti2LoState.CallerNeedsTriggerTransmit' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_CALLERNEEDSTXCONFOFTXIFMULTI2LOSTATE                     STD_OFF  /**< Deactivateable: 'PduR_TxIfMulti2LoState.CallerNeedsTxConf' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SRCHNDOFTXIFMULTI2LOSTATE                                STD_OFF  /**< Deactivateable: 'PduR_TxIfMulti2LoState.SrcHnd' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TRANSMISSIONACTIVEOFTXIFMULTI2LOSTATE                    STD_OFF  /**< Deactivateable: 'PduR_TxIfMulti2LoState.TransmissionActive' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TXIFMULTI2LOIDXOFTXIFMULTI2LOSTATE                       STD_OFF  /**< Deactivateable: 'PduR_TxIfMulti2LoState.TxIfMulti2LoIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TXIFMULTI2LOSRCMODULEIDXOFTXIFMULTI2LOSTATE              STD_OFF  /**< Deactivateable: 'PduR_TxIfMulti2LoState.TxIfMulti2LoSrcModuleIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TXMULTI2LO                                               STD_OFF  /**< Deactivateable: 'PduR_TxMulti2Lo' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_CANCELTRANSMITFCTPTRIDXOFTXMULTI2LO                      STD_OFF  /**< Deactivateable: 'PduR_TxMulti2Lo.CancelTransmitFctPtrIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_CANCELTRANSMITFCTPTRUSEDOFTXMULTI2LO                     STD_OFF  /**< Deactivateable: 'PduR_TxMulti2Lo.CancelTransmitFctPtrUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_COPYTXDATAFCTPTRIDXOFTXMULTI2LO                          STD_OFF  /**< Deactivateable: 'PduR_TxMulti2Lo.CopyTxDataFctPtrIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_DESTHNDOFTXMULTI2LO                                      STD_OFF  /**< Deactivateable: 'PduR_TxMulti2Lo.DestHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTRPGROMIDXOFTXMULTI2LO                              STD_OFF  /**< Deactivateable: 'PduR_TxMulti2Lo.RmDestRpgRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTRPGROMUSEDOFTXMULTI2LO                             STD_OFF  /**< Deactivateable: 'PduR_TxMulti2Lo.RmDestRpgRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SRCHNDOFTXMULTI2LO                                       STD_OFF  /**< Deactivateable: 'PduR_TxMulti2Lo.SrcHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SRCMODULEIDXOFTXMULTI2LO                                 STD_OFF  /**< Deactivateable: 'PduR_TxMulti2Lo.SrcModuleIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TPTXCONFIRMATIONFCTPTRIDXOFTXMULTI2LO                    STD_OFF  /**< Deactivateable: 'PduR_TxMulti2Lo.TpTxConfirmationFctPtrIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TPTXCONFIRMATIONFCTPTRUSEDOFTXMULTI2LO                   STD_OFF  /**< Deactivateable: 'PduR_TxMulti2Lo.TpTxConfirmationFctPtrUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TRANSMITFCTPTRIDXOFTXMULTI2LO                            STD_OFF  /**< Deactivateable: 'PduR_TxMulti2Lo.TransmitFctPtrIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TXMULTI2LOSTATEIDXOFTXMULTI2LO                           STD_OFF  /**< Deactivateable: 'PduR_TxMulti2Lo.TxMulti2LoStateIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TXMULTI2LOSTATE                                          STD_OFF  /**< Deactivateable: 'PduR_TxMulti2LoState' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_SRCHNDOFTXMULTI2LOSTATE                                  STD_OFF  /**< Deactivateable: 'PduR_TxMulti2LoState.SrcHnd' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TRANSMISSIONACTIVEOFTXMULTI2LOSTATE                      STD_OFF  /**< Deactivateable: 'PduR_TxMulti2LoState.TransmissionActive' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TXMULTI2LOIDXOFTXMULTI2LOSTATE                           STD_OFF  /**< Deactivateable: 'PduR_TxMulti2LoState.TxMulti2LoIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TXMULTI2LOSRCMODULEIDXOFTXMULTI2LOSTATE                  STD_OFF  /**< Deactivateable: 'PduR_TxMulti2LoState.TxMulti2LoSrcModuleIdx' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TXTP2SRC                                                 STD_ON
#define PDUR_BSWMPDURTPTXCONFIRMATIONCALLBACKOFTXTP2SRC               STD_OFF  /**< Deactivateable: 'PduR_TxTp2Src.BswMPduRTpTxConfirmationCallback' Reason: 'Callback Support is not active' */
#define PDUR_COPYTXDATAFCTPTRIDXOFTXTP2SRC                            STD_ON
#define PDUR_INVALIDHNDOFTXTP2SRC                                     STD_OFF  /**< Deactivateable: 'PduR_TxTp2Src.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxTp2Src is always 'false' due to this, the array is deactivated.' */
#define PDUR_RMDESTRPGROMIDXOFTXTP2SRC                                STD_OFF  /**< Deactivateable: 'PduR_TxTp2Src.RmDestRpgRomIdx' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfTxTp2Src is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMDESTRPGROMUSEDOFTXTP2SRC                               STD_OFF  /**< Deactivateable: 'PduR_TxTp2Src.RmDestRpgRomUsed' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfTxTp2Src is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_SRCHNDOFTXTP2SRC                                         STD_ON
#define PDUR_TPTXCONFIRMATIONFCTPTRIDXOFTXTP2SRC                      STD_ON
#define PDUR_PCCONFIG                                                 STD_ON
#define PDUR_CONFIGIDOFPCCONFIG                                       STD_ON
#define PDUR_COPYRXDATAFCTPTROFPCCONFIG                               STD_ON
#define PDUR_COPYTXDATAFCTPTROFPCCONFIG                               STD_ON
#define PDUR_FINALMAGICNUMBEROFPCCONFIG                               STD_OFF  /**< Deactivateable: 'PduR_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define PDUR_IFROUTINGSTATETABLEOFPCCONFIG                            STD_ON
#define PDUR_IFRXINDICATIONFCTPTROFPCCONFIG                           STD_ON
#define PDUR_INITDATAHASHCODEOFPCCONFIG                               STD_OFF  /**< Deactivateable: 'PduR_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define PDUR_INITIALIZEDOFPCCONFIG                                    STD_ON
#define PDUR_RXIF2DESTOFPCCONFIG                                      STD_ON
#define PDUR_RXTP2DESTOFPCCONFIG                                      STD_ON
#define PDUR_RXTP2SRCOFPCCONFIG                                       STD_ON
#define PDUR_SIZEOFCOPYRXDATAFCTPTROFPCCONFIG                         STD_ON
#define PDUR_SIZEOFCOPYTXDATAFCTPTROFPCCONFIG                         STD_ON
#define PDUR_SIZEOFIFROUTINGSTATETABLEOFPCCONFIG                      STD_ON
#define PDUR_SIZEOFIFRXINDICATIONFCTPTROFPCCONFIG                     STD_ON
#define PDUR_SIZEOFRXIF2DESTOFPCCONFIG                                STD_ON
#define PDUR_SIZEOFRXTP2DESTOFPCCONFIG                                STD_ON
#define PDUR_SIZEOFRXTP2SRCOFPCCONFIG                                 STD_ON
#define PDUR_SIZEOFSTARTOFRECEPTIONFCTPTROFPCCONFIG                   STD_ON
#define PDUR_SIZEOFTPRXINDICATIONFCTPTROFPCCONFIG                     STD_ON
#define PDUR_SIZEOFTPTXCONFIRMATIONFCTPTROFPCCONFIG                   STD_ON
#define PDUR_SIZEOFTRANSMITFCTPTROFPCCONFIG                           STD_ON
#define PDUR_SIZEOFTX2LOOFPCCONFIG                                    STD_ON
#define PDUR_SIZEOFTXIF2UPOFPCCONFIG                                  STD_ON
#define PDUR_SIZEOFTXTP2SRCOFPCCONFIG                                 STD_ON
#define PDUR_STARTOFRECEPTIONFCTPTROFPCCONFIG                         STD_ON
#define PDUR_TPRXINDICATIONFCTPTROFPCCONFIG                           STD_ON
#define PDUR_TPTXCONFIRMATIONFCTPTROFPCCONFIG                         STD_ON
#define PDUR_TRANSMITFCTPTROFPCCONFIG                                 STD_ON
#define PDUR_TX2LOOFPCCONFIG                                          STD_ON
#define PDUR_TXIF2UPOFPCCONFIG                                        STD_ON
#define PDUR_TXTP2SRCOFPCCONFIG                                       STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCNoReferenceDefines  PduR No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define PDUR_NO_DESTHNDOFRXIF2DEST                                    255U
#define PDUR_NO_DESTHNDOFRXTP2DEST                                    255U
#define PDUR_NO_SRCHNDOFRXTP2SRC                                      255U
#define PDUR_NO_DESTHNDOFTX2LO                                        255U
#define PDUR_NO_SRCHNDOFTXTP2SRC                                      255U
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCEnumExistsDefines  PduR Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define PDUR_EXISTS_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE STD_ON
#define PDUR_EXISTS_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE STD_ON
#define PDUR_EXISTS_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE STD_OFF
#define PDUR_EXISTS_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE STD_ON
#define PDUR_EXISTS_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE STD_ON
#define PDUR_EXISTS_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE STD_ON
#define PDUR_EXISTS_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE STD_OFF
#define PDUR_EXISTS_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE STD_ON
#define PDUR_EXISTS_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE STD_ON
#define PDUR_EXISTS_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE STD_OFF
#define PDUR_EXISTS_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE STD_ON
#define PDUR_EXISTS_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE STD_ON
#define PDUR_EXISTS_IF_UPPER_LAYER_DESTLAYERTYPEOFRMGDESTROM          STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.DestLayerType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_EXISTS_IF_LOWER_LAYER_DESTLAYERTYPEOFRMGDESTROM          STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.DestLayerType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_EXISTS_TP_UPPER_LAYER_DESTLAYERTYPEOFRMGDESTROM          STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.DestLayerType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_EXISTS_TP_LOWER_LAYER_DESTLAYERTYPEOFRMGDESTROM          STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.DestLayerType' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_EXISTS_NO_BUFFER_FIFOTYPEOFRMGDESTROM                    STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.FifoType' Reason: 'No CommunicationInterface Gateway Routing available' */
#define PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMGDESTROM            STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.FifoType' Reason: 'No CommunicationInterface Gateway Routing available' */
#define PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMGDESTROM              STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.FifoType' Reason: 'No CommunicationInterface Gateway Routing available' */
#define PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMGDESTROM           STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.FifoType' Reason: 'No CommunicationInterface Gateway Routing available' */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCEnumDefines  PduR Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define PDUR_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE 0x00U
#define PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE 0x01U
#define PDUR_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE 0x00U
#define PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE 0x01U
#define PDUR_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE 0x02U
#define PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE 0x01U
#define PDUR_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE 0x02U
#define PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE 0x01U
#define PDUR_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE 0x02U
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCIsReducedToDefineDefines  PduR Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define PDUR_ISDEF_COPYRXDATAFCTPTR                                   STD_OFF
#define PDUR_ISDEF_COPYTXDATAFCTPTR                                   STD_OFF
#define PDUR_ISDEF_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE STD_OFF
#define PDUR_ISDEF_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE STD_OFF
#define PDUR_ISDEF_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE STD_OFF
#define PDUR_ISDEF_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE STD_OFF
#define PDUR_ISDEF_IFRXINDICATIONFCTPTR                               STD_OFF
#define PDUR_ISDEF_DESTHNDOFRXIF2DEST                                 STD_OFF
#define PDUR_ISDEF_IFRXINDICATIONFCTPTRIDXOFRXIF2DEST                 STD_OFF
#define PDUR_ISDEF_COPYRXDATAFCTPTRIDXOFRXTP2DEST                     STD_OFF
#define PDUR_ISDEF_DESTHNDOFRXTP2DEST                                 STD_OFF
#define PDUR_ISDEF_STARTOFRECEPTIONFCTPTRIDXOFRXTP2DEST               STD_OFF
#define PDUR_ISDEF_TPRXINDICATIONFCTPTRIDXOFRXTP2DEST                 STD_OFF
#define PDUR_ISDEF_SRCHNDOFRXTP2SRC                                   STD_OFF
#define PDUR_ISDEF_STARTOFRECEPTIONFCTPTR                             STD_OFF
#define PDUR_ISDEF_TPRXINDICATIONFCTPTR                               STD_OFF
#define PDUR_ISDEF_TPTXCONFIRMATIONFCTPTR                             STD_OFF
#define PDUR_ISDEF_TRANSMITFCTPTR                                     STD_OFF
#define PDUR_ISDEF_DESTHNDOFTX2LO                                     STD_OFF
#define PDUR_ISDEF_TRANSMITFCTPTRIDXOFTX2LO                           STD_OFF
#define PDUR_ISDEF_COPYTXDATAFCTPTRIDXOFTXTP2SRC                      STD_OFF
#define PDUR_ISDEF_SRCHNDOFTXTP2SRC                                   STD_OFF
#define PDUR_ISDEF_TPTXCONFIRMATIONFCTPTRIDXOFTXTP2SRC                STD_OFF
#define PDUR_ISDEF_COPYRXDATAFCTPTROFPCCONFIG                         STD_ON
#define PDUR_ISDEF_COPYTXDATAFCTPTROFPCCONFIG                         STD_ON
#define PDUR_ISDEF_IFROUTINGSTATETABLEOFPCCONFIG                      STD_ON
#define PDUR_ISDEF_IFRXINDICATIONFCTPTROFPCCONFIG                     STD_ON
#define PDUR_ISDEF_INITIALIZEDOFPCCONFIG                              STD_ON
#define PDUR_ISDEF_RXIF2DESTOFPCCONFIG                                STD_ON
#define PDUR_ISDEF_RXTP2DESTOFPCCONFIG                                STD_ON
#define PDUR_ISDEF_RXTP2SRCOFPCCONFIG                                 STD_ON
#define PDUR_ISDEF_STARTOFRECEPTIONFCTPTROFPCCONFIG                   STD_ON
#define PDUR_ISDEF_TPRXINDICATIONFCTPTROFPCCONFIG                     STD_ON
#define PDUR_ISDEF_TPTXCONFIRMATIONFCTPTROFPCCONFIG                   STD_ON
#define PDUR_ISDEF_TRANSMITFCTPTROFPCCONFIG                           STD_ON
#define PDUR_ISDEF_TX2LOOFPCCONFIG                                    STD_ON
#define PDUR_ISDEF_TXIF2UPOFPCCONFIG                                  STD_ON
#define PDUR_ISDEF_TXTP2SRCOFPCCONFIG                                 STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCEqualsAlwaysToDefines  PduR Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define PDUR_EQ2_COPYRXDATAFCTPTR                                     
#define PDUR_EQ2_COPYTXDATAFCTPTR                                     
#define PDUR_EQ2_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE 
#define PDUR_EQ2_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE 
#define PDUR_EQ2_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE 
#define PDUR_EQ2_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE 
#define PDUR_EQ2_IFRXINDICATIONFCTPTR                                 
#define PDUR_EQ2_DESTHNDOFRXIF2DEST                                   
#define PDUR_EQ2_IFRXINDICATIONFCTPTRIDXOFRXIF2DEST                   
#define PDUR_EQ2_COPYRXDATAFCTPTRIDXOFRXTP2DEST                       
#define PDUR_EQ2_DESTHNDOFRXTP2DEST                                   
#define PDUR_EQ2_STARTOFRECEPTIONFCTPTRIDXOFRXTP2DEST                 
#define PDUR_EQ2_TPRXINDICATIONFCTPTRIDXOFRXTP2DEST                   
#define PDUR_EQ2_SRCHNDOFRXTP2SRC                                     
#define PDUR_EQ2_STARTOFRECEPTIONFCTPTR                               
#define PDUR_EQ2_TPRXINDICATIONFCTPTR                                 
#define PDUR_EQ2_TPTXCONFIRMATIONFCTPTR                               
#define PDUR_EQ2_TRANSMITFCTPTR                                       
#define PDUR_EQ2_DESTHNDOFTX2LO                                       
#define PDUR_EQ2_TRANSMITFCTPTRIDXOFTX2LO                             
#define PDUR_EQ2_COPYTXDATAFCTPTRIDXOFTXTP2SRC                        
#define PDUR_EQ2_SRCHNDOFTXTP2SRC                                     
#define PDUR_EQ2_TPTXCONFIRMATIONFCTPTRIDXOFTXTP2SRC                  
#define PDUR_EQ2_COPYRXDATAFCTPTROFPCCONFIG                           PduR_CopyRxDataFctPtr
#define PDUR_EQ2_COPYTXDATAFCTPTROFPCCONFIG                           PduR_CopyTxDataFctPtr
#define PDUR_EQ2_IFROUTINGSTATETABLEOFPCCONFIG                        PduR_IfRoutingStateTable
#define PDUR_EQ2_IFRXINDICATIONFCTPTROFPCCONFIG                       PduR_IfRxIndicationFctPtr
#define PDUR_EQ2_INITIALIZEDOFPCCONFIG                                PduR_Initialized
#define PDUR_EQ2_RXIF2DESTOFPCCONFIG                                  PduR_RxIf2Dest
#define PDUR_EQ2_RXTP2DESTOFPCCONFIG                                  PduR_RxTp2Dest
#define PDUR_EQ2_RXTP2SRCOFPCCONFIG                                   PduR_RxTp2Src
#define PDUR_EQ2_STARTOFRECEPTIONFCTPTROFPCCONFIG                     PduR_StartOfReceptionFctPtr
#define PDUR_EQ2_TPRXINDICATIONFCTPTROFPCCONFIG                       PduR_TpRxIndicationFctPtr
#define PDUR_EQ2_TPTXCONFIRMATIONFCTPTROFPCCONFIG                     PduR_TpTxConfirmationFctPtr
#define PDUR_EQ2_TRANSMITFCTPTROFPCCONFIG                             PduR_TransmitFctPtr
#define PDUR_EQ2_TX2LOOFPCCONFIG                                      PduR_Tx2Lo
#define PDUR_EQ2_TXIF2UPOFPCCONFIG                                    PduR_TxIf2Up
#define PDUR_EQ2_TXTP2SRCOFPCCONFIG                                   PduR_TxTp2Src
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCSymbolicInitializationPointers  PduR Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define PduR_Config_Ptr                                               NULL_PTR  /**< symbolic identifier which shall be used to initialize 'PduR' */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCInitializationSymbols  PduR Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define PduR_Config                                                   NULL_PTR  /**< symbolic identifier which could be used to initialize 'PduR */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCGeneral  PduR General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define PDUR_CHECK_INIT_POINTER                                       STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define PDUR_FINAL_MAGIC_NUMBER                                       0x331EU  /**< the precompile constant to validate the size of the initialization structure at initialization time of PduR */
#define PDUR_INDIVIDUAL_POSTBUILD                                     STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'PduR' is not configured to be postbuild capable. */
#define PDUR_INIT_DATA                                                PDUR_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define PDUR_INIT_DATA_HASH_CODE                                      -713907762L  /**< the precompile constant to validate the initialization structure at initialization time of PduR with a hashcode. The seed value is '0x331EU' */
#define PDUR_USE_ECUM_BSW_ERROR_HOOK                                  STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define PDUR_USE_INIT_POINTER                                         STD_OFF  /**< STD_ON if the init pointer PduR shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  PduRLTDataSwitches  PduR Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define PDUR_LTCONFIG                                                 STD_OFF  /**< Deactivateable: 'PduR_LTConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 



/** BroadcastDummy */


#if (PDUR_FMFIFOELEMENTRAM == STD_OFF)
  #define PduR_FmFifoElementRamIterType uint16
#endif

/**********************************************************************************************************************
 * GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 MACROS_3453 */  /* MD_CSL_3453 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  PduRPCGetConstantDuplicatedRootDataMacros  PduR Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define PduR_GetConfigIdOfPCConfig()                                  0U  /**< DefinitionRef: /MICROSAR/PduR/PduRRoutingTables/PduRConfigurationId */
#define PduR_GetCopyRxDataFctPtrOfPCConfig()                          PduR_CopyRxDataFctPtr  /**< the pointer to PduR_CopyRxDataFctPtr */
#define PduR_GetCopyTxDataFctPtrOfPCConfig()                          PduR_CopyTxDataFctPtr  /**< the pointer to PduR_CopyTxDataFctPtr */
#define PduR_GetIfRoutingStateTableOfPCConfig()                       PduR_IfRoutingStateTable  /**< the pointer to PduR_IfRoutingStateTable */
#define PduR_GetIfRxIndicationFctPtrOfPCConfig()                      PduR_IfRxIndicationFctPtr  /**< the pointer to PduR_IfRxIndicationFctPtr */
#define PduR_GetInitializedOfPCConfig()                               PduR_Initialized  /**< the pointer to PduR_Initialized */
#define PduR_GetRxIf2DestOfPCConfig()                                 PduR_RxIf2Dest  /**< the pointer to PduR_RxIf2Dest */
#define PduR_GetRxTp2DestOfPCConfig()                                 PduR_RxTp2Dest  /**< the pointer to PduR_RxTp2Dest */
#define PduR_GetRxTp2SrcOfPCConfig()                                  PduR_RxTp2Src  /**< the pointer to PduR_RxTp2Src */
#define PduR_GetSizeOfCopyRxDataFctPtrOfPCConfig()                    1UL  /**< the number of accomplishable value elements in PduR_CopyRxDataFctPtr */
#define PduR_GetSizeOfCopyTxDataFctPtrOfPCConfig()                    1UL  /**< the number of accomplishable value elements in PduR_CopyTxDataFctPtr */
#define PduR_GetSizeOfIfRoutingStateTableOfPCConfig()                 4UL  /**< the number of accomplishable value elements in PduR_IfRoutingStateTable */
#define PduR_GetSizeOfIfRxIndicationFctPtrOfPCConfig()                1UL  /**< the number of accomplishable value elements in PduR_IfRxIndicationFctPtr */
#define PduR_GetSizeOfRxIf2DestOfPCConfig()                           7UL  /**< the number of accomplishable value elements in PduR_RxIf2Dest */
#define PduR_GetSizeOfRxTp2DestOfPCConfig()                           2UL  /**< the number of accomplishable value elements in PduR_RxTp2Dest */
#define PduR_GetSizeOfRxTp2SrcOfPCConfig()                            2UL  /**< the number of accomplishable value elements in PduR_RxTp2Src */
#define PduR_GetSizeOfStartOfReceptionFctPtrOfPCConfig()              1UL  /**< the number of accomplishable value elements in PduR_StartOfReceptionFctPtr */
#define PduR_GetSizeOfTpRxIndicationFctPtrOfPCConfig()                1UL  /**< the number of accomplishable value elements in PduR_TpRxIndicationFctPtr */
#define PduR_GetSizeOfTpTxConfirmationFctPtrOfPCConfig()              1UL  /**< the number of accomplishable value elements in PduR_TpTxConfirmationFctPtr */
#define PduR_GetSizeOfTransmitFctPtrOfPCConfig()                      2UL  /**< the number of accomplishable value elements in PduR_TransmitFctPtr */
#define PduR_GetSizeOfTx2LoOfPCConfig()                               7UL  /**< the number of accomplishable value elements in PduR_Tx2Lo */
#define PduR_GetSizeOfTxIf2UpOfPCConfig()                             6UL  /**< the number of accomplishable value elements in PduR_TxIf2Up */
#define PduR_GetSizeOfTxTp2SrcOfPCConfig()                            1UL  /**< the number of accomplishable value elements in PduR_TxTp2Src */
#define PduR_GetStartOfReceptionFctPtrOfPCConfig()                    PduR_StartOfReceptionFctPtr  /**< the pointer to PduR_StartOfReceptionFctPtr */
#define PduR_GetTpRxIndicationFctPtrOfPCConfig()                      PduR_TpRxIndicationFctPtr  /**< the pointer to PduR_TpRxIndicationFctPtr */
#define PduR_GetTpTxConfirmationFctPtrOfPCConfig()                    PduR_TpTxConfirmationFctPtr  /**< the pointer to PduR_TpTxConfirmationFctPtr */
#define PduR_GetTransmitFctPtrOfPCConfig()                            PduR_TransmitFctPtr  /**< the pointer to PduR_TransmitFctPtr */
#define PduR_GetTx2LoOfPCConfig()                                     PduR_Tx2Lo  /**< the pointer to PduR_Tx2Lo */
#define PduR_GetTxIf2UpOfPCConfig()                                   PduR_TxIf2Up  /**< the pointer to PduR_TxIf2Up */
#define PduR_GetTxTp2SrcOfPCConfig()                                  PduR_TxTp2Src  /**< the pointer to PduR_TxTp2Src */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCGetDataMacros  PduR Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define PduR_GetCopyRxDataFctPtr(Index)                               (PduR_GetCopyRxDataFctPtrOfPCConfig()[(Index)])
#define PduR_GetCopyTxDataFctPtr(Index)                               (PduR_GetCopyTxDataFctPtrOfPCConfig()[(Index)])
#define PduR_GetNextState_For_Init_If_Routing_StateOfIfRoutingStateTable(Index) (PduR_GetIfRoutingStateTableOfPCConfig()[(Index)].NextState_For_Init_If_Routing_StateOfIfRoutingStateTable)
#define PduR_GetNextState_For_Wait_For_RxIndicationOfIfRoutingStateTable(Index) (PduR_GetIfRoutingStateTableOfPCConfig()[(Index)].NextState_For_Wait_For_RxIndicationOfIfRoutingStateTable)
#define PduR_GetNextState_For_Wait_For_TriggerTransmitOfIfRoutingStateTable(Index) (PduR_GetIfRoutingStateTableOfPCConfig()[(Index)].NextState_For_Wait_For_TriggerTransmitOfIfRoutingStateTable)
#define PduR_GetNextState_For_Wait_For_TxConfirmationOfIfRoutingStateTable(Index) (PduR_GetIfRoutingStateTableOfPCConfig()[(Index)].NextState_For_Wait_For_TxConfirmationOfIfRoutingStateTable)
#define PduR_GetIfRxIndicationFctPtr(Index)                           (PduR_GetIfRxIndicationFctPtrOfPCConfig()[(Index)])
#define PduR_IsInitialized()                                          ((PduR_GetInitializedOfPCConfig()) != FALSE)
#define PduR_GetIfRxIndicationFctPtrIdxOfRxIf2Dest(Index)             (PduR_GetRxIf2DestOfPCConfig()[(Index)].IfRxIndicationFctPtrIdxOfRxIf2Dest)
#define PduR_GetStartOfReceptionFctPtrIdxOfRxTp2Dest(Index)           (PduR_GetRxTp2DestOfPCConfig()[(Index)].StartOfReceptionFctPtrIdxOfRxTp2Dest)
#define PduR_GetSrcHndOfRxTp2Src(Index)                               (PduR_GetRxTp2SrcOfPCConfig()[(Index)].SrcHndOfRxTp2Src)
#define PduR_GetStartOfReceptionFctPtr(Index)                         (PduR_GetStartOfReceptionFctPtrOfPCConfig()[(Index)])
#define PduR_GetTpRxIndicationFctPtr(Index)                           (PduR_GetTpRxIndicationFctPtrOfPCConfig()[(Index)])
#define PduR_GetTpTxConfirmationFctPtr(Index)                         (PduR_GetTpTxConfirmationFctPtrOfPCConfig()[(Index)])
#define PduR_GetTransmitFctPtr(Index)                                 (PduR_GetTransmitFctPtrOfPCConfig()[(Index)])
#define PduR_GetDestHndOfTx2Lo(Index)                                 (PduR_GetTx2LoOfPCConfig()[(Index)].DestHndOfTx2Lo)
#define PduR_GetTransmitFctPtrIdxOfTx2Lo(Index)                       (PduR_GetTx2LoOfPCConfig()[(Index)].TransmitFctPtrIdxOfTx2Lo)
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCGetDeduplicatedDataMacros  PduR Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define PduR_GetConfigId()                                            PduR_GetConfigIdOfPCConfig()
#define PduR_GetDestHndOfRxIf2Dest(Index)                             ((PduR_DestHndOfRxIf2DestType)((Index)))  /**< Handle to be used as parameter for the RxIndication function call. */
#define PduR_GetCopyRxDataFctPtrIdxOfRxTp2Dest(Index)                 PduR_GetStartOfReceptionFctPtrIdxOfRxTp2Dest(Index)  /**< the index of the 1:1 relation pointing to PduR_CopyRxDataFctPtr */
#define PduR_GetDestHndOfRxTp2Dest(Index)                             ((PduR_DestHndOfRxTp2DestType)((Index)))  /**< handle to be used as parameter for the StartOfReception, CopyRxData or RxIndication function call. */
#define PduR_GetTpRxIndicationFctPtrIdxOfRxTp2Dest(Index)             PduR_GetStartOfReceptionFctPtrIdxOfRxTp2Dest(Index)  /**< the index of the 1:1 relation pointing to PduR_TpRxIndicationFctPtr */
#define PduR_GetSizeOfCopyRxDataFctPtr()                              PduR_GetSizeOfCopyRxDataFctPtrOfPCConfig()
#define PduR_GetSizeOfCopyTxDataFctPtr()                              PduR_GetSizeOfCopyTxDataFctPtrOfPCConfig()
#define PduR_GetSizeOfIfRoutingStateTable()                           PduR_GetSizeOfIfRoutingStateTableOfPCConfig()
#define PduR_GetSizeOfIfRxIndicationFctPtr()                          PduR_GetSizeOfIfRxIndicationFctPtrOfPCConfig()
#define PduR_GetSizeOfRxIf2Dest()                                     PduR_GetSizeOfRxIf2DestOfPCConfig()
#define PduR_GetSizeOfRxTp2Dest()                                     PduR_GetSizeOfRxTp2DestOfPCConfig()
#define PduR_GetSizeOfRxTp2Src()                                      PduR_GetSizeOfRxTp2SrcOfPCConfig()
#define PduR_GetSizeOfStartOfReceptionFctPtr()                        PduR_GetSizeOfStartOfReceptionFctPtrOfPCConfig()
#define PduR_GetSizeOfTpRxIndicationFctPtr()                          PduR_GetSizeOfTpRxIndicationFctPtrOfPCConfig()
#define PduR_GetSizeOfTpTxConfirmationFctPtr()                        PduR_GetSizeOfTpTxConfirmationFctPtrOfPCConfig()
#define PduR_GetSizeOfTransmitFctPtr()                                PduR_GetSizeOfTransmitFctPtrOfPCConfig()
#define PduR_GetSizeOfTx2Lo()                                         PduR_GetSizeOfTx2LoOfPCConfig()
#define PduR_GetSizeOfTxIf2Up()                                       PduR_GetSizeOfTxIf2UpOfPCConfig()
#define PduR_GetSizeOfTxTp2Src()                                      PduR_GetSizeOfTxTp2SrcOfPCConfig()
#define PduR_GetCopyTxDataFctPtrIdxOfTxTp2Src(Index)                  ((PduR_CopyTxDataFctPtrIdxOfTxTp2SrcType)((Index)))  /**< the index of the 1:1 relation pointing to PduR_CopyTxDataFctPtr */
#define PduR_GetSrcHndOfTxTp2Src(Index)                               ((PduR_SrcHndOfTxTp2SrcType)((Index)))  /**< handle to be used as parameter for the CopyTxData or TxConfirmation function call. */
#define PduR_GetTpTxConfirmationFctPtrIdxOfTxTp2Src(Index)            ((PduR_TpTxConfirmationFctPtrIdxOfTxTp2SrcType)((Index)))  /**< the index of the 1:1 relation pointing to PduR_TpTxConfirmationFctPtr */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCSetDataMacros  PduR Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define PduR_SetInitialized(Value)                                    PduR_GetInitializedOfPCConfig() = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCHasMacros  PduR Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define PduR_HasConfigId()                                            (TRUE != FALSE)
#define PduR_HasCopyRxDataFctPtr()                                    (TRUE != FALSE)
#define PduR_HasCopyTxDataFctPtr()                                    (TRUE != FALSE)
#define PduR_HasIfRoutingStateTable()                                 (TRUE != FALSE)
#define PduR_HasNextState_For_Init_If_Routing_StateOfIfRoutingStateTable() (TRUE != FALSE)
#define PduR_HasNextState_For_Wait_For_RxIndicationOfIfRoutingStateTable() (TRUE != FALSE)
#define PduR_HasNextState_For_Wait_For_TriggerTransmitOfIfRoutingStateTable() (TRUE != FALSE)
#define PduR_HasNextState_For_Wait_For_TxConfirmationOfIfRoutingStateTable() (TRUE != FALSE)
#define PduR_HasIfRxIndicationFctPtr()                                (TRUE != FALSE)
#define PduR_HasInitialized()                                         (TRUE != FALSE)
#define PduR_HasRxIf2Dest()                                           (TRUE != FALSE)
#define PduR_HasDestHndOfRxIf2Dest()                                  (TRUE != FALSE)
#define PduR_HasIfRxIndicationFctPtrIdxOfRxIf2Dest()                  (TRUE != FALSE)
#define PduR_HasRxTp2Dest()                                           (TRUE != FALSE)
#define PduR_HasCopyRxDataFctPtrIdxOfRxTp2Dest()                      (TRUE != FALSE)
#define PduR_HasDestHndOfRxTp2Dest()                                  (TRUE != FALSE)
#define PduR_HasStartOfReceptionFctPtrIdxOfRxTp2Dest()                (TRUE != FALSE)
#define PduR_HasTpRxIndicationFctPtrIdxOfRxTp2Dest()                  (TRUE != FALSE)
#define PduR_HasRxTp2Src()                                            (TRUE != FALSE)
#define PduR_HasSrcHndOfRxTp2Src()                                    (TRUE != FALSE)
#define PduR_HasSizeOfCopyRxDataFctPtr()                              (TRUE != FALSE)
#define PduR_HasSizeOfCopyTxDataFctPtr()                              (TRUE != FALSE)
#define PduR_HasSizeOfIfRoutingStateTable()                           (TRUE != FALSE)
#define PduR_HasSizeOfIfRxIndicationFctPtr()                          (TRUE != FALSE)
#define PduR_HasSizeOfRxIf2Dest()                                     (TRUE != FALSE)
#define PduR_HasSizeOfRxTp2Dest()                                     (TRUE != FALSE)
#define PduR_HasSizeOfRxTp2Src()                                      (TRUE != FALSE)
#define PduR_HasSizeOfStartOfReceptionFctPtr()                        (TRUE != FALSE)
#define PduR_HasSizeOfTpRxIndicationFctPtr()                          (TRUE != FALSE)
#define PduR_HasSizeOfTpTxConfirmationFctPtr()                        (TRUE != FALSE)
#define PduR_HasSizeOfTransmitFctPtr()                                (TRUE != FALSE)
#define PduR_HasSizeOfTx2Lo()                                         (TRUE != FALSE)
#define PduR_HasSizeOfTxIf2Up()                                       (TRUE != FALSE)
#define PduR_HasSizeOfTxTp2Src()                                      (TRUE != FALSE)
#define PduR_HasStartOfReceptionFctPtr()                              (TRUE != FALSE)
#define PduR_HasTpRxIndicationFctPtr()                                (TRUE != FALSE)
#define PduR_HasTpTxConfirmationFctPtr()                              (TRUE != FALSE)
#define PduR_HasTransmitFctPtr()                                      (TRUE != FALSE)
#define PduR_HasTx2Lo()                                               (TRUE != FALSE)
#define PduR_HasDestHndOfTx2Lo()                                      (TRUE != FALSE)
#define PduR_HasTransmitFctPtrIdxOfTx2Lo()                            (TRUE != FALSE)
#define PduR_HasTxTp2Src()                                            (TRUE != FALSE)
#define PduR_HasCopyTxDataFctPtrIdxOfTxTp2Src()                       (TRUE != FALSE)
#define PduR_HasSrcHndOfTxTp2Src()                                    (TRUE != FALSE)
#define PduR_HasTpTxConfirmationFctPtrIdxOfTxTp2Src()                 (TRUE != FALSE)
#define PduR_HasPCConfig()                                            (TRUE != FALSE)
#define PduR_HasConfigIdOfPCConfig()                                  (TRUE != FALSE)
#define PduR_HasCopyRxDataFctPtrOfPCConfig()                          (TRUE != FALSE)
#define PduR_HasCopyTxDataFctPtrOfPCConfig()                          (TRUE != FALSE)
#define PduR_HasIfRoutingStateTableOfPCConfig()                       (TRUE != FALSE)
#define PduR_HasIfRxIndicationFctPtrOfPCConfig()                      (TRUE != FALSE)
#define PduR_HasInitializedOfPCConfig()                               (TRUE != FALSE)
#define PduR_HasRxIf2DestOfPCConfig()                                 (TRUE != FALSE)
#define PduR_HasRxTp2DestOfPCConfig()                                 (TRUE != FALSE)
#define PduR_HasRxTp2SrcOfPCConfig()                                  (TRUE != FALSE)
#define PduR_HasSizeOfCopyRxDataFctPtrOfPCConfig()                    (TRUE != FALSE)
#define PduR_HasSizeOfCopyTxDataFctPtrOfPCConfig()                    (TRUE != FALSE)
#define PduR_HasSizeOfIfRoutingStateTableOfPCConfig()                 (TRUE != FALSE)
#define PduR_HasSizeOfIfRxIndicationFctPtrOfPCConfig()                (TRUE != FALSE)
#define PduR_HasSizeOfRxIf2DestOfPCConfig()                           (TRUE != FALSE)
#define PduR_HasSizeOfRxTp2DestOfPCConfig()                           (TRUE != FALSE)
#define PduR_HasSizeOfRxTp2SrcOfPCConfig()                            (TRUE != FALSE)
#define PduR_HasSizeOfStartOfReceptionFctPtrOfPCConfig()              (TRUE != FALSE)
#define PduR_HasSizeOfTpRxIndicationFctPtrOfPCConfig()                (TRUE != FALSE)
#define PduR_HasSizeOfTpTxConfirmationFctPtrOfPCConfig()              (TRUE != FALSE)
#define PduR_HasSizeOfTransmitFctPtrOfPCConfig()                      (TRUE != FALSE)
#define PduR_HasSizeOfTx2LoOfPCConfig()                               (TRUE != FALSE)
#define PduR_HasSizeOfTxIf2UpOfPCConfig()                             (TRUE != FALSE)
#define PduR_HasSizeOfTxTp2SrcOfPCConfig()                            (TRUE != FALSE)
#define PduR_HasStartOfReceptionFctPtrOfPCConfig()                    (TRUE != FALSE)
#define PduR_HasTpRxIndicationFctPtrOfPCConfig()                      (TRUE != FALSE)
#define PduR_HasTpTxConfirmationFctPtrOfPCConfig()                    (TRUE != FALSE)
#define PduR_HasTransmitFctPtrOfPCConfig()                            (TRUE != FALSE)
#define PduR_HasTx2LoOfPCConfig()                                     (TRUE != FALSE)
#define PduR_HasTxIf2UpOfPCConfig()                                   (TRUE != FALSE)
#define PduR_HasTxTp2SrcOfPCConfig()                                  (TRUE != FALSE)
/** 
  \}
*/ 

  /* PRQA L:MACROS_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 MACROS_3453 */  /* MD_CSL_3453 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:MACROS_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* Communication Interface APIs */
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TransmitFctPtrType) (PduIdType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TriggerTransmitFctPtrType) (PduIdType, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_IfRxIndicationType) (PduIdType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_IfTxConfirmationFctPtrType) (PduIdType);

/* Transport Protocol APIs */
typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_StartOfReceptionFctPtrType) (PduIdType, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), PduLengthType, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_CopyRxDataFctPtrType) (PduIdType, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_CopyTxDataFctPtrType) (PduIdType, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpRxIndicationFctPtrType) (PduIdType, Std_ReturnType);

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpTxConfirmationFctPtrType) (PduIdType, Std_ReturnType);


#if (PDUR_CANCELTRANSMITFCTPTR == STD_ON)
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_CancelTransmitFctPtrType)(PduIdType);
#endif
#if (PDUR_CANCELRECEIVEFCTPTR == STD_ON)
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_CancelReceiveFctPtrType) (PduIdType);
#endif
#if (PDUR_CHANGEPARAMETERFCTPTR == STD_ON)
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_ChangeParameterFctPtrType) (PduIdType, TPParameterType, uint16);
#endif

typedef P2FUNC(void, PDUR_CODE, PduR_DisableRoutingFctPtrType) (PduR_RoutingPathGroupIdType);


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  PduRPCIterableTypes  PduR Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate PduR_CopyRxDataFctPtr */
typedef uint8_least PduR_CopyRxDataFctPtrIterType;

/**   \brief  type used to iterate PduR_CopyTxDataFctPtr */
typedef uint8_least PduR_CopyTxDataFctPtrIterType;

/**   \brief  type used to iterate PduR_IfRoutingStateTable */
typedef uint8_least PduR_IfRoutingStateTableIterType;

/**   \brief  type used to iterate PduR_IfRxIndicationFctPtr */
typedef uint8_least PduR_IfRxIndicationFctPtrIterType;

/**   \brief  type used to iterate PduR_RxIf2Dest */
typedef uint8_least PduR_RxIf2DestIterType;

/**   \brief  type used to iterate PduR_RxTp2Dest */
typedef uint8_least PduR_RxTp2DestIterType;

/**   \brief  type used to iterate PduR_RxTp2Src */
typedef uint8_least PduR_RxTp2SrcIterType;

/**   \brief  type used to iterate PduR_StartOfReceptionFctPtr */
typedef uint8_least PduR_StartOfReceptionFctPtrIterType;

/**   \brief  type used to iterate PduR_TpRxIndicationFctPtr */
typedef uint8_least PduR_TpRxIndicationFctPtrIterType;

/**   \brief  type used to iterate PduR_TpTxConfirmationFctPtr */
typedef uint8_least PduR_TpTxConfirmationFctPtrIterType;

/**   \brief  type used to iterate PduR_TransmitFctPtr */
typedef uint8_least PduR_TransmitFctPtrIterType;

/**   \brief  type used to iterate PduR_Tx2Lo */
typedef uint8_least PduR_Tx2LoIterType;

/**   \brief  type used to iterate PduR_TxTp2Src */
typedef uint8_least PduR_TxTp2SrcIterType;

/** 
  \}
*/ 

/** 
  \defgroup  PduRPCValueTypes  PduR Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for PduR_ConfigId */
typedef uint8 PduR_ConfigIdType;

/**   \brief  value based type definition for PduR_NextState_For_Init_If_Routing_StateOfIfRoutingStateTable */
typedef uint8 PduR_NextState_For_Init_If_Routing_StateOfIfRoutingStateTableType;

/**   \brief  value based type definition for PduR_NextState_For_Wait_For_RxIndicationOfIfRoutingStateTable */
typedef uint8 PduR_NextState_For_Wait_For_RxIndicationOfIfRoutingStateTableType;

/**   \brief  value based type definition for PduR_NextState_For_Wait_For_TriggerTransmitOfIfRoutingStateTable */
typedef uint8 PduR_NextState_For_Wait_For_TriggerTransmitOfIfRoutingStateTableType;

/**   \brief  value based type definition for PduR_NextState_For_Wait_For_TxConfirmationOfIfRoutingStateTable */
typedef uint8 PduR_NextState_For_Wait_For_TxConfirmationOfIfRoutingStateTableType;

/**   \brief  value based type definition for PduR_Initialized */
typedef boolean PduR_InitializedType;

/**   \brief  value based type definition for PduR_DestHndOfRxIf2Dest */
typedef uint8 PduR_DestHndOfRxIf2DestType;

/**   \brief  value based type definition for PduR_IfRxIndicationFctPtrIdxOfRxIf2Dest */
typedef uint8 PduR_IfRxIndicationFctPtrIdxOfRxIf2DestType;

/**   \brief  value based type definition for PduR_CopyRxDataFctPtrIdxOfRxTp2Dest */
typedef uint8 PduR_CopyRxDataFctPtrIdxOfRxTp2DestType;

/**   \brief  value based type definition for PduR_DestHndOfRxTp2Dest */
typedef uint8 PduR_DestHndOfRxTp2DestType;

/**   \brief  value based type definition for PduR_StartOfReceptionFctPtrIdxOfRxTp2Dest */
typedef uint8 PduR_StartOfReceptionFctPtrIdxOfRxTp2DestType;

/**   \brief  value based type definition for PduR_TpRxIndicationFctPtrIdxOfRxTp2Dest */
typedef uint8 PduR_TpRxIndicationFctPtrIdxOfRxTp2DestType;

/**   \brief  value based type definition for PduR_SrcHndOfRxTp2Src */
typedef uint8 PduR_SrcHndOfRxTp2SrcType;

/**   \brief  value based type definition for PduR_SizeOfCopyRxDataFctPtr */
typedef uint8 PduR_SizeOfCopyRxDataFctPtrType;

/**   \brief  value based type definition for PduR_SizeOfCopyTxDataFctPtr */
typedef uint8 PduR_SizeOfCopyTxDataFctPtrType;

/**   \brief  value based type definition for PduR_SizeOfIfRoutingStateTable */
typedef uint8 PduR_SizeOfIfRoutingStateTableType;

/**   \brief  value based type definition for PduR_SizeOfIfRxIndicationFctPtr */
typedef uint8 PduR_SizeOfIfRxIndicationFctPtrType;

/**   \brief  value based type definition for PduR_SizeOfRxIf2Dest */
typedef uint8 PduR_SizeOfRxIf2DestType;

/**   \brief  value based type definition for PduR_SizeOfRxTp2Dest */
typedef uint8 PduR_SizeOfRxTp2DestType;

/**   \brief  value based type definition for PduR_SizeOfRxTp2Src */
typedef uint8 PduR_SizeOfRxTp2SrcType;

/**   \brief  value based type definition for PduR_SizeOfStartOfReceptionFctPtr */
typedef uint8 PduR_SizeOfStartOfReceptionFctPtrType;

/**   \brief  value based type definition for PduR_SizeOfTpRxIndicationFctPtr */
typedef uint8 PduR_SizeOfTpRxIndicationFctPtrType;

/**   \brief  value based type definition for PduR_SizeOfTpTxConfirmationFctPtr */
typedef uint8 PduR_SizeOfTpTxConfirmationFctPtrType;

/**   \brief  value based type definition for PduR_SizeOfTransmitFctPtr */
typedef uint8 PduR_SizeOfTransmitFctPtrType;

/**   \brief  value based type definition for PduR_SizeOfTx2Lo */
typedef uint8 PduR_SizeOfTx2LoType;

/**   \brief  value based type definition for PduR_SizeOfTxIf2Up */
typedef uint8 PduR_SizeOfTxIf2UpType;

/**   \brief  value based type definition for PduR_SizeOfTxTp2Src */
typedef uint8 PduR_SizeOfTxTp2SrcType;

/**   \brief  value based type definition for PduR_DestHndOfTx2Lo */
typedef uint8 PduR_DestHndOfTx2LoType;

/**   \brief  value based type definition for PduR_TransmitFctPtrIdxOfTx2Lo */
typedef uint8 PduR_TransmitFctPtrIdxOfTx2LoType;

/**   \brief  value based type definition for PduR_CopyTxDataFctPtrIdxOfTxTp2Src */
typedef uint8 PduR_CopyTxDataFctPtrIdxOfTxTp2SrcType;

/**   \brief  value based type definition for PduR_SrcHndOfTxTp2Src */
typedef uint8 PduR_SrcHndOfTxTp2SrcType;

/**   \brief  value based type definition for PduR_TpTxConfirmationFctPtrIdxOfTxTp2Src */
typedef uint8 PduR_TpTxConfirmationFctPtrIdxOfTxTp2SrcType;

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


#if(PDUR_FMFIFORAM == STD_ON)
typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_StartOfReceptionFifoSmFctPtrType) (PduR_RmSrcRomIterType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), PduLengthType, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));
typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_CopyRxDataFifoSmFctPtrType) (PduR_RmSrcRomIterType, PduLengthType, SduDataPtrType, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpRxIndicationFifoSmFctPtrType) (PduR_RmSrcRomIterType, Std_ReturnType);
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpCancelReceiveFctPtrType) (PduR_RmSrcRomIterType);

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_CopyTxDataFifoSmFctPtrType) (PduR_RmGDestRomIterType, PduLengthType, SduDataPtrType, P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TpTriggerTransmitFctPtrType) (PduR_RmDestRomIterType);
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpTxConfirmationFifoSmFctPtrType) (PduR_RmGDestRomIterType, Std_ReturnType);
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TpCancelTransmitFctPtrType)(PduR_RmDestRomIterType);
typedef P2FUNC(void, PDUR_CODE, PduR_TpDisableRoutingFctPtrType) (PduR_RmGDestRomIterType);

typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_CheckReady2TransmitFctPtrType) (PduR_RmSrcRomIterType);

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_FinishReceptionFctPtrType) (PduR_RmSrcRomIterType, Std_ReturnType);

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_FinishTransmissionFctPtrType) (PduR_RmSrcRomIterType, Std_ReturnType);

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_ActivateNextFctPtrType) (PduR_FmFifoElementRamIterType, Std_ReturnType);
#endif

#if(PDUR_FINISHREADFMSMTRANSITION  == STD_ON)
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_FinishReadFctPtrType) (PduR_FmFifoElementRamIterType, Std_ReturnType);
#endif
#if (PDUR_FINISHWRITEFMSMTRANSITION  == STD_ON)
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_FinishWriteFctPtrType) (PduR_FmFifoElementRamIterType, Std_ReturnType);
#endif
#if (PDUR_TPACTIVATEREADFIFOSMTRANSITION == STD_ON)
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_ActivateReadFctPtrType) (PduR_FmFifoElementRamIterType);
#endif
#if (PDUR_TPACTIVATEWRITEFIFOSMTRANSITION == STD_ON)
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_ActivateWriteFctPtrType) (PduR_FmFifoElementRamIterType);
#endif

#if (PDUR_FMFLUSHFIFOELEMENT == STD_ON)
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_Fm_FlushFiFoElementPtrType) (PduR_FmFifoElementRamIterType);
#endif

#if(PDUR_SMDATAPLANEROM == STD_ON)
typedef uint8 PduR_FilterReturnType;
# define PDUR_FILTER_PASS  0u
# define PDUR_FILTER_BLOCK 1u

typedef uint32 PduR_SmSaType;
typedef uint32 PduR_SmTaType;

#define PDUR_SM_UNLEARNED_CONNECTION 0u
typedef P2FUNC(PduR_SmSaType, PDUR_CODE, PduR_Sm_LinearTaToSaCalculationStrategy_GetSaFctPtrType) (PduR_SmLinearTaToSaCalculationStrategyRomIterType, uint32);
typedef P2FUNC(void, PDUR_CODE, PduR_Sm_SrcFilterFctPtrType) (PduR_SmSrcRomIterType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));
typedef P2FUNC(PduR_FilterReturnType, PDUR_CODE, PduR_Sm_DestFilterFctPtrType) (PduR_SmGDestRomIterType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));
#endif

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  PduRPCStructTypes  PduR Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in PduR_IfRoutingStateTable */
typedef struct sPduR_IfRoutingStateTableType
{
  PduR_NextState_For_Init_If_Routing_StateOfIfRoutingStateTableType NextState_For_Init_If_Routing_StateOfIfRoutingStateTable;
  PduR_NextState_For_Wait_For_RxIndicationOfIfRoutingStateTableType NextState_For_Wait_For_RxIndicationOfIfRoutingStateTable;
  PduR_NextState_For_Wait_For_TriggerTransmitOfIfRoutingStateTableType NextState_For_Wait_For_TriggerTransmitOfIfRoutingStateTable;
  PduR_NextState_For_Wait_For_TxConfirmationOfIfRoutingStateTableType NextState_For_Wait_For_TxConfirmationOfIfRoutingStateTable;
} PduR_IfRoutingStateTableType;

/**   \brief  type used in PduR_RxIf2Dest */
typedef struct sPduR_RxIf2DestType
{
  PduR_IfRxIndicationFctPtrIdxOfRxIf2DestType IfRxIndicationFctPtrIdxOfRxIf2Dest;  /**< the index of the 1:1 relation pointing to PduR_IfRxIndicationFctPtr */
} PduR_RxIf2DestType;

/**   \brief  type used in PduR_RxTp2Dest */
typedef struct sPduR_RxTp2DestType
{
  PduR_StartOfReceptionFctPtrIdxOfRxTp2DestType StartOfReceptionFctPtrIdxOfRxTp2Dest;  /**< the index of the 1:1 relation pointing to PduR_StartOfReceptionFctPtr */
} PduR_RxTp2DestType;

/**   \brief  type used in PduR_RxTp2Src */
typedef struct sPduR_RxTp2SrcType
{
  PduR_SrcHndOfRxTp2SrcType SrcHndOfRxTp2Src;  /**< handle to be used as parameter for the CancelReceive or ChangeParameter function call. */
} PduR_RxTp2SrcType;

/**   \brief  type used in PduR_Tx2Lo */
typedef struct sPduR_Tx2LoType
{
  PduR_DestHndOfTx2LoType DestHndOfTx2Lo;  /**< Handle to be used as parameter for the Transmit function call. */
  PduR_TransmitFctPtrIdxOfTx2LoType TransmitFctPtrIdxOfTx2Lo;  /**< the index of the 1:1 relation pointing to PduR_TransmitFctPtr */
} PduR_Tx2LoType;

/**   \brief  type used in PduR_TxTp2Src */
typedef struct sPduR_TxTp2SrcType
{
  uint8 PduR_TxTp2SrcNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} PduR_TxTp2SrcType;

/** 
  \}
*/ 

/** 
  \defgroup  PduRPCRootValueTypes  PduR Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in PduR_PCConfig */
typedef struct sPduR_PCConfigType
{
  uint8 PduR_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} PduR_PCConfigType;

typedef PduR_PCConfigType PduR_PBConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
 * GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  PduR_CopyRxDataFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_CopyRxDataFctPtr
  \brief  Transport protocol CopyRxData function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(PduR_CopyRxDataFctPtrType, PDUR_CONST) PduR_CopyRxDataFctPtr[1];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_CopyTxDataFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_CopyTxDataFctPtr
  \brief  Transport protocol CopyTxData function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(PduR_CopyTxDataFctPtrType, PDUR_CONST) PduR_CopyTxDataFctPtr[1];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_IfRoutingStateTable
**********************************************************************************************************************/
/** 
  \var    PduR_IfRoutingStateTable
  \brief  Contains state transition for Communication Interface routings
  \details
  Element                                   Description
  NextState_For_Init_If_Routing_State   
  NextState_For_Wait_For_RxIndication   
  NextState_For_Wait_For_TriggerTransmit
  NextState_For_Wait_For_TxConfirmation 
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(PduR_IfRoutingStateTableType, PDUR_CONST) PduR_IfRoutingStateTable[4];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_IfRxIndicationFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_IfRxIndicationFctPtr
  \brief  Upper layer communication interface Rx indication function pointers.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(PduR_IfRxIndicationType, PDUR_CONST) PduR_IfRxIndicationFctPtr[1];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RxIf2Dest
**********************************************************************************************************************/
/** 
  \var    PduR_RxIf2Dest
  \brief  This table contains all routing information to perform the Rx handling of an interface routing. Used in the &lt;LLIf&gt;_RxIndication
  \details
  Element                    Description
  IfRxIndicationFctPtrIdx    the index of the 1:1 relation pointing to PduR_IfRxIndicationFctPtr
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(PduR_RxIf2DestType, PDUR_CONST) PduR_RxIf2Dest[7];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RxTp2Dest
**********************************************************************************************************************/
/** 
  \var    PduR_RxTp2Dest
  \brief  This table contains all routing information to perform the Rx handling of a Tp Routing. Used in the PduR_&lt;LLTp&gt;_StartOfReception, PduR_&lt;LLTp&gt;_CopyRxData and PduR_&lt;LLTp&gt;_RxIndication.
  \details
  Element                      Description
  StartOfReceptionFctPtrIdx    the index of the 1:1 relation pointing to PduR_StartOfReceptionFctPtr
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(PduR_RxTp2DestType, PDUR_CONST) PduR_RxTp2Dest[2];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RxTp2Src
**********************************************************************************************************************/
/** 
  \var    PduR_RxTp2Src
  \brief  This table contains all routing information to perform the ChangeParameter or CancelReceive handling. Used in ChangeParameter and CancelReceive APIs 	race SPEC-1024
  \details
  Element    Description
  SrcHnd     handle to be used as parameter for the CancelReceive or ChangeParameter function call.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(PduR_RxTp2SrcType, PDUR_CONST) PduR_RxTp2Src[2];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_StartOfReceptionFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_StartOfReceptionFctPtr
  \brief  Transport protocol StartOfReception function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(PduR_StartOfReceptionFctPtrType, PDUR_CONST) PduR_StartOfReceptionFctPtr[1];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TpRxIndicationFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_TpRxIndicationFctPtr
  \brief  Transport protocol TpRxIndication function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(PduR_TpRxIndicationFctPtrType, PDUR_CONST) PduR_TpRxIndicationFctPtr[1];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TpTxConfirmationFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_TpTxConfirmationFctPtr
  \brief  Transport protocol TpTxConfimation function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(PduR_TpTxConfirmationFctPtrType, PDUR_CONST) PduR_TpTxConfirmationFctPtr[1];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TransmitFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_TransmitFctPtr
  \brief  Lower layer transmit function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(PduR_TransmitFctPtrType, PDUR_CONST) PduR_TransmitFctPtr[2];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_Tx2Lo
**********************************************************************************************************************/
/** 
  \var    PduR_Tx2Lo
  \brief  Contains all informations to route a Pdu from a upper layer to a lower layer module, or to cancel a transmission
  \details
  Element              Description
  DestHnd              Handle to be used as parameter for the Transmit function call.
  TransmitFctPtrIdx    the index of the 1:1 relation pointing to PduR_TransmitFctPtr
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(PduR_Tx2LoType, PDUR_CONST) PduR_Tx2Lo[7];
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_Initialized
**********************************************************************************************************************/
/** 
  \var    PduR_Initialized
  \brief  Initialization state of PduR. TRUE, if PduR_Init() has been called, else FALSE
*/ 
#define PDUR_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern VAR(PduR_InitializedType, PDUR_VAR_ZERO_INIT) PduR_Initialized;
#define PDUR_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


#endif  /* PDUR_LCFG_H */
/**********************************************************************************************************************
 * END OF FILE: PduR_Lcfg.h
 *********************************************************************************************************************/

