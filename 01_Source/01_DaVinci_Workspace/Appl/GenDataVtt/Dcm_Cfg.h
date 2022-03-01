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
 *            Module: Dcm
 *           Program: MSR_Vector_SLP4
 *          Customer: AUTOSAR 4 Evaluation Bundle for CANoe/VTT
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: VTT
 *    License Scope : The usage is restricted to CBD1500710_D05
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Dcm_Cfg.h
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



#if !defined(DCM_CFG_H)
# define DCM_CFG_H
/* ----------------------------------------------
 ~&&&   Versions
---------------------------------------------- */

/*! Implementation version */
# define DCM_CFG_MAJOR_VERSION                                                  8u
# define DCM_CFG_MINOR_VERSION                                                  3u
# define DCM_CFG_PATCH_VERSION                                                  1u
/* ----------------------------------------------
 ~&&&   Switches
---------------------------------------------- */

/*! Access to version information */
# define DCM_VERSION_INFO_API                                                  STD_OFF
# define DCM_RUNTIME_USAGE_LIMIT_ENABLED                                       STD_OFF
# define DCM_RUNTIME_USAGE_LIMIT_SINGLE_LOOP_ENABLED                           STD_OFF
/*! AUTOSAR 3.x BSW environment */
# define DCM_BSW_ENV_ASR_VERSION_3XX_ENABLED                                   STD_OFF
/*! AUTOSAR 4.0.1 BSW environment */
# define DCM_BSW_ENV_ASR_VERSION_401_ENABLED                                   STD_OFF
/*! AUTOSAR 4.x BSW environment */
# define DCM_BSW_ENV_ASR_VERSION_4XX_ENABLED                                   STD_ON
/*! Support simple structure-to-structure assignment */
# define DCM_UTI_STRUCT_ASSIGNMENT_ENABLED                                     STD_ON
/*! Support global RAM shredder */
# define DCM_DEV_RAM_SHREDDER_ENABLED                                          STD_OFF
/*! Support of internal NvM write SW-C data API */
# define DCM_EXT_NEED_API_UTINVMSWCDATAWRITE_ENABLED                           STD_OFF
/*! Support of internal generic NvM write API */
# define DCM_EXT_NEED_API_UTINVMWRITE_ENABLED                                  STD_OFF
/*! Support of internal generic NvM read API */
# define DCM_EXT_NEED_API_UTINVMREAD_ENABLED                                   STD_OFF
/*! Development error detection and reporting */
# define DCM_DEV_ERROR_REPORT                                                  STD_ON
/*! Highest possible safety module usage */
# define DCM_DEV_ERROR_DETECT                                                  STD_ON
/*! Specifies whether DCM will be put into SafeBSW mode (restricted features). */
# define DCM_DEV_RUNTIME_CHECKS                                                STD_OFF
/*! Internal debug information */
# define DCM_DEBUG_ERROR_DETECT                                                STD_OFF
/*! Internal API for access to current DCM initialization state */
# define DCM_EXT_NEED_API_DEBUGISMODULEINITIALIZED_ENABLED                     STD_OFF
/*! Optimization for single client configurations */
# define DCM_NET_MULTI_CLIENT_ENABLED                                          STD_OFF
/*! Optimization for single channel configurations */
# define DCM_NET_MULTI_CHANNEL_ENABLED                                         STD_OFF
/*! Support communication control on all ECU channels */
# define DCM_NET_COMCTRL_ALLNET_SUPPORT_ENABLED                                STD_OFF
/*! Optimization for single protocol configurations */
# define DCM_NET_MULTI_PROTOCOL_ENABLED                                        STD_OFF
/*! Periodic transmission unit */
# define DCM_NET_PERIODIC_TX_ENABLED                                           STD_OFF
/*! Periodic transmission unused byte padding */
# define DCM_NET_PERIODIC_MSG_PADDING_ENABLED                                  STD_OFF
/*! Periodic transmission UUDT delay timer */
# define DCM_NET_UUDT_DELAYTIMER_ENABLED                                       STD_OFF
/*! Protocol prioritization */
# define DCM_NET_PROTOCOL_PRIORITISATION_ENABLED                               STD_OFF
/*! Protocol switch notification */
# define DCM_NET_PROTOCOL_SWITCH_NOTIFICATION_ENABLED                          STD_OFF
/*! Connection specific periodic messages usage */
# define DCM_NET_PERIODIC_TX_CONN_SPECIFIC_NUM_TX_OBJ_ENABLED                  STD_OFF
/*! Support general suppression on functional requests */
# define DCM_NET_SUPPRESS_ON_FUNC_REQ_ENABLED                                  STD_OFF
/*! Support monitoring of requests to other ECUs */
# define DCM_NET_MONITOR_FOREIGN_N_TA_ENABLED                                  STD_OFF
/*! Protect against clients other than the one started the non-default session */
# define DCM_NET_PROTECT_SESSION_OF_CLIENT_ENABLED                             STD_OFF
/*! Support for internal API for ComM state */
# define DCM_EXT_NEED_API_NETGETCOMSTATE_ENABLED                               STD_OFF
/*! Support general suppression on any request */
# define DCM_NET_CONNECTION_WITHOUT_TX_ENABLED                                 STD_OFF
/*! Support ECU address information */
# define DCM_NET_CONN_ECU_ADDRESS_ENABLED                                      STD_OFF
/*! Paged buffer support for DEM APIs */
# define DCM_DEM_API_PAGED_BUFFER_ENABLED                                      STD_OFF
/*! Paged buffer support */
# define DCM_PAGED_BUFFER_ENABLED                                              STD_OFF
/*! DCM extension module needs this API */
# define DCM_REPEATER_EXT_CONTEXT_GETTER_ENABLED                               STD_OFF
/*! Support mode management */
# define DCM_MODEMGR_SUPPORT_ENABLED                                           STD_ON
/*! Any diagnostic object needs rule check */
# define DCM_MODEMGR_CHECK_SUPPORT_ENABLED                                     STD_OFF
/*! ECU rapid shutdown mode management support */
# define DCM_MODE_RPD_SHTDWN_ENABLED                                           STD_OFF
/*! ECU reset mode management support */
# define DCM_MODE_ECU_RESET_ENABLED                                            STD_OFF
/*! Control DTC setting mode management support */
# define DCM_MODE_CTRLDTCSETTING_ENABLED                                       STD_OFF
/*! Control DTC setting mode management monitoring support */
# define DCM_MODE_CTRLDTCSETTING_MONITOR_ENABLED                               STD_OFF
/*! Communication control mode management support */
# define DCM_MODE_COMMCTRL_ENABLED                                             STD_OFF
/*! Communication control mode management monitoring support */
# define DCM_MODE_COMMCTRL_MONITOR_ENABLED                                     STD_OFF
/*! Security access mode management support */
# define DCM_MODE_SECURITY_ACCESS_ENABLED                                      STD_OFF
/*! Response on event mode management support */
# define DCM_MODE_ROE_ENABLED                                                  STD_OFF
/*! Support security access state management */
# define DCM_STATE_SECURITY_ENABLED                                            STD_OFF
/*! Support security access timer 1 */
# define DCM_STATE_SEC_TIMER_1_ENABLED                                         STD_OFF
/*! Support security access wrong key attempt counter */
# define DCM_STATE_SEC_RETRY_ENABLED                                           STD_OFF
/*! Support security access delay on boot */
# define DCM_STATE_SEC_DELAY_ON_BOOT_ENABLED                                   STD_OFF
/*! Support security access delay on failed GetAttemptCounter */
# define DCM_STATE_SEC_DELAY_TIME_ON_FAILED_GET_ATT_CNTR_ENABLED               STD_OFF
/*! Support SecurityGet-/SetAttemptCounter APIs */
# define DCM_STATE_SEC_ATT_CNTR_EXT_STORAGE_ENABLED                            STD_OFF
/*! Support security fixed bytes */
# define DCM_STATE_SECURITY_FIXED_BYTES_ENABLED                                STD_OFF
/*! Support mulitple secuirty fixed bytes per security level */
# define DCM_STATE_MULTIPLE_SECURITYFIXEDBYTES_ENABLED                         STD_OFF
/*! Support session change notifications */
# define DCM_STATE_SESSION_NOTIFICATION_ENABLED                                STD_OFF
/*! Support security access level change notifications */
# define DCM_STATE_SECURITY_NOTIFICATION_ENABLED                               STD_OFF
/*! DEM APIs usage */
# define DCM_DEMAPIMGR_SUPPORT_ENABLED                                         STD_ON
/*! DEM APIs for AR 4.0.3 */
# define DCM_DEM_API_403_ENABLED                                               STD_OFF
/*! DEM APIs for AR 4.1.2 */
# define DCM_DEM_API_412_ENABLED                                               STD_OFF
/*! DEM APIs for AR 4.2.1 */
# define DCM_DEM_API_421_ENABLED                                               STD_OFF
/*! DEM APIs for AR 4.3.0 */
# define DCM_DEM_API_430_ENABLED                                               STD_ON
/*! Support DemClientId */
# define DCM_DEM_CLIENTID_ENABLED                                              STD_ON
/*! Support DID manager  */
# define DCM_DIDMGR_SUPPORT_ENABLED                                            STD_ON
/*! Support any DID with asynchronous access */
# define DCM_DIDMGR_ASYNC_DID_SUPPORT_ENABLED                                  STD_ON
/*! Support any static DID with asynchronous access */
# define DCM_DIDMGR_STATIC_DID_ASYNC_SUPPORT_ENABLED                           STD_ON
/*! Support any static DID with dynamic length */
# define DCM_DIDMGR_STATIC_DID_OPTYPE_READ_LENGTH_ENABLED                      STD_OFF
/*! All DID signals support check condition read operation */
# define DCM_DIDMGR_OPTYPE_READ_CHECKCOND_ALL_ENABLED                          STD_ON
/*! Support external DID look up filter */
# define DCM_DIDMGR_EXTENDED_LOOKUP_ENABLED                                    STD_OFF
/*! Any DID ranges supported */
# define DCM_DIDMGR_RANGE_SUPPORT_ENABLED                                      STD_OFF
/*! Support IO control enable mask record */
# define DCM_DIDMGR_IO_MASKRECORD_ENABLED                                      STD_OFF
/*! Support IO control with asynchronous operations */
# define DCM_DIDMGR_ASYNC_IODID_SUPPORT_ENABLED                                STD_OFF
/*! Support IO control with read operation */
# define DCM_DIDMGR_IODID_READ_SUPPORT_ENABLED                                 STD_OFF
/*! Support IO control with execution preconditions */
# define DCM_DIDMGR_IODID_EXEC_PRECOND_LIMIT_ENABLED                           STD_OFF
/*! Support IO control with more than 4 byte CEMR in application call */
# define DCM_DIDMGR_IODID_NBYTE_EXT_CEMR_ENABLED                               STD_OFF
/*! Support IO control (Reset To Default, Freeze Current State, Short Term Adjustment) operation in S/R style */
# define DCM_DIDMGR_SR_IO_CONTROL_ENABLED                                      STD_OFF
/*! Support IO control (Return Control To Ecu) in S/R style */
# define DCM_DIDMGR_SR_IO_RESET_ENABLED                                        STD_OFF
/*! Support IO control (Short Term Adjustment) in S/R style */
# define DCM_DIDMGR_SR_IO_SHORT_TERM_ADJUSTMENT_ENABLED                        STD_OFF
/*! Support scaling information access with asynchronous operation */
# define DCM_DIDMGR_ASYNC_SCALINGDID_SUPPORT_ENABLED                           STD_OFF
/*! There is a dynamically define non-periodic DID */
# define DCM_DIDMGR_NONPERIODICDYNDID_ENABLED                                  STD_OFF
/*! There is a dynamically define periodic DID */
# define DCM_DIDMGR_PERIODICDYNDID_ENABLED                                     STD_OFF
/*! There is a IO controlled periodic DID */
# define DCM_DIDMGR_PERIODICIODID_ENABLED                                      STD_OFF
/*! There is a writeable periodic DID */
# define DCM_DIDMGR_PERIODICWRITEDID_ENABLED                                   STD_OFF
/*! There is a periodic DID with a check condition read operation */
# define DCM_DIDMGR_PERIODICDID_CHK_COND_ENABLED                               STD_ON
/*! All periodic DIDs have check read condition operation */
# define DCM_DIDMGR_PERIODICDID_CHK_COND_ALL_ENABLED                           STD_OFF
/*! Automatically remove any periodic DID not supported any more in the current state */
# define DCM_DIDMGR_PERIODICDID_CLR_ON_STATE_CHG_ENABLED                       STD_OFF
/*! Support scaling additional information */
# define DCM_DIDMGR_OP_INFO_SCALING_ENABLED                                    STD_OFF
/*! Support IO control additional information */
# define DCM_DIDMGR_OP_INFO_IOCONTROL_ENABLED                                  STD_OFF
/*! Support dynamically define DID additional information */
# define DCM_DIDMGR_OP_INFO_DEFINE_ENABLED                                     STD_OFF
/*! Support combined DID operation additional information */
# define DCM_DIDMGR_OP_INFO_COMBINED_ENABLED                                   STD_OFF
/*! Support any DID operation additional information */
# define DCM_DIDMGR_OP_INFO_ANY_ENABLED                                        STD_OFF
/*! Some DDDIDs have different number of references */
# define DCM_DIDMGR_DYNDID_VAR_NUM_ITEMS_ENABLED                               STD_OFF
/*! The ConditionCheckRead operation on source items will be called */
# define DCM_DIDMGR_DYNDID_SRCITEM_CHECK_COND_ENABLED                          STD_OFF
/*! The session and security states as well as any configured mode conditions on source items will be validated */
# define DCM_DIDMGR_DYNDID_SRCITEM_CHECK_STATE_ENABLED                         STD_OFF
/*! Automatically clear any dynamically defined DID not supported any more in the current state */
# define DCM_DIDMGR_DYNDID_CLR_ON_STATE_CHG_ENABLED                            STD_OFF
/*! At least one DID has dynamic length */
# define DCM_DIDMGR_DYNLEN_DID_SUPPORT_ENABLED                                 STD_OFF
/*! At least one DID has at least one gap in its signal definition */
# define DCM_DIDMGR_MSIG_OPTYPE_READ_GAP_ENABLED                               STD_OFF
/*! Supports any DID multiple signals */
# define DCM_DIDMGR_MULTISIGNAL_ENABLED                                        STD_OFF
/*! Supports any DID NvM signals with read operation */
# define DCM_DIDMGR_NVM_READ_ENABLED                                           STD_OFF
/*! Supports any DID NvM signals with write operation */
# define DCM_DIDMGR_NVM_WRITE_ENABLED                                          STD_OFF
/*! Supports DID 0xF186 signal with read operation */
# define DCM_DIDMGR_DID_F186_READ_ENABLED                                      STD_OFF
/*! Supports IO DIDs with dynamic length */
# define DCM_DIDMGR_IODID_DYNLEN_ENABLED                                       STD_OFF
/*! Support report of NODI Byte */
# define DCM_DIDMGR_REPORT_NODIBYTE_ENABLED                                    STD_OFF
/*! Support dynamic length read DIDs */
# define DCM_DIDMGR_OPTYPE_READ_LENGTH_ENABLED                                 STD_OFF
/*! Support DID ranges with gaps */
# define DCM_DIDMGR_OPTYPE_RANGE_ISAVAIL_ENABLED                               STD_OFF
/*! Support return control to ECU */
# define DCM_DIDMGR_OPTYPE_IO_RETCTRL2ECU_ENABLED                              STD_OFF
/*! Support reset to default state */
# define DCM_DIDMGR_OPTYPE_IO_RST2DEFAULT_ENABLED                              STD_OFF
/*! Support freeze current state */
# define DCM_DIDMGR_OPTYPE_IO_FRZCURSTATE_ENABLED                              STD_OFF
/*! Support short term adjustment */
# define DCM_DIDMGR_OPTYPE_IO_SHRTTERMADJ_ENABLED                              STD_OFF
/*! Support multiple read operations per DID */
# define DCM_DIDMGR_MSIG_OPTYPE_READ_ENABLED                                   STD_OFF
/*! Support multiple read check condition operations per DID */
# define DCM_DIDMGR_MSIG_OPTYPE_READ_CHKCOND_ENABLED                           STD_OFF
/*! Support multiple read length operations per DID */
# define DCM_DIDMGR_MSIG_OPTYPE_READ_LENGTH_ENABLED                            STD_OFF
/*! Support multiple write operations per DID */
# define DCM_DIDMGR_MSIG_OPTYPE_WRITE_ENABLED                                  STD_OFF
/*! Support multiple IO short term adjustment operations per DID */
# define DCM_DIDMGR_MSIG_OPTYPE_IO_SHRTTRMADJ_ENABLED                          STD_OFF
/*! Support multiple IO return control to ECU operations per DID */
# define DCM_DIDMGR_MSIG_OPTYPE_IO_RETCTRL2ECU_ENABLED                         STD_OFF
/*! Support multiple IO reset and return to default operations per DID */
# define DCM_DIDMGR_MSIG_OPTYPE_IO_RST2DEFAULT_ENABLED                         STD_OFF
/*! Support multiple IO freeze current state operations per DID */
# define DCM_DIDMGR_MSIG_OPTYPE_IO_FRZCURSTATE_ENABLED                         STD_OFF
/*! Support multiple scaling reading operations per DID */
# define DCM_DIDMGR_MSIG_OPTYPE_GETSCALINGINFO_ENABLED                         STD_OFF
/*! Support write operation on DID ranges */
# define DCM_DIDMGR_OPCLS_WRITE_RANGE_ENABLED                                  STD_OFF
/*! Support asynchronous write on static length DIDs */
# define DCM_DIDMGR_OPCLS_WRITE_NLEN_ASYNC_NRES_ERROR_ENABLED                  STD_OFF
/*! Support asynchronous write on dynamic length DIDs */
# define DCM_DIDMGR_OPCLS_WRITE_LEN_ASYNC_NRES_ERROR_ENABLED                   STD_OFF
/*! Support synchronous write on static length DIDs */
# define DCM_DIDMGR_OPCLS_WRITE_NLEN_SYNC_NRES_ERROR_ENABLED                   STD_OFF
/*! Support synchronous write on dynamic length DIDs */
# define DCM_DIDMGR_OPCLS_WRITE_LEN_SYNC_NRES_ERROR_ENABLED                    STD_OFF
/*! Support synchronous write on dynamic length DIDs with response data */
# define DCM_DIDMGR_OPCLS_WRITE_LEN_SYNC_RES_ERROR_ENABLED                     STD_OFF
/*! Support synchronous write on static length DIDs with no error code */
# define DCM_DIDMGR_OPCLS_WRITE_NLEN_SYNC_NRES_NERROR_ENABLED                  STD_OFF
/*! Support read operation on DID ranges */
# define DCM_DIDMGR_OPCLS_READ_RANGE_ENABLED                                   STD_OFF
/*! Support asynchronous, paged read on DIDs */
# define DCM_DIDMGR_OPCLS_READ_PAGED_ENABLED                                   STD_OFF
/*! Support asynchronous read on DIDs */
# define DCM_DIDMGR_OPCLS_READ_ASYNC_ENABLED                                   STD_ON
/*! Support synchronous read on DIDs */
# define DCM_DIDMGR_OPCLS_READ_SYNC_ENABLED                                    STD_OFF
/*! Support sender-receiver read on DIDs */
# define DCM_DIDMGR_OPCLS_READ_SR_ENABLED                                      STD_OFF
/*! Support read on OBD VID DIDs */
# define DCM_DIDMGR_OPCLS_READ_VID_ENABLED                                     STD_OFF
/*! Support asynchronous read on DIDs */
# define DCM_DIDMGR_OPCLS_READ_CHECKCOND_ASYNC_ENABLED                         STD_ON
/*! Support synchronous read on DIDs */
# define DCM_DIDMGR_OPCLS_READ_CHECKCOND_SYNC_ENABLED                          STD_OFF
/*! Support read length on DID ranges */
# define DCM_DIDMGR_OPCLS_READ_LENGTH_RANGE_ENABLED                            STD_OFF
/*! Support asynchronous read length on DIDs */
# define DCM_DIDMGR_OPCLS_READ_LENGTH_ASYNC_ENABLED                            STD_OFF
/*! Support synchronous read length on DIDs */
# define DCM_DIDMGR_OPCLS_READ_LENGTH_SYNC_ENABLED                             STD_OFF
/*! Support synchronous IO control without request data, without request length parameter, without CEMR and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_NREQ_NLEN_SYNC_NRES_NCEMR_ERROR_ENABLED           STD_OFF
/*! Support synchronous IO control with request data, without request length parameter, without CEMR and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_REQ_NLEN_SYNC_NRES_NCEMR_ERROR_ENABLED            STD_OFF
/*! Support synchronous IO control with request data, with request length parameter, without CEMR and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_REQ_LEN_SYNC_NRES_NCEMR_ERROR_ENABLED             STD_OFF
/*! Support asynchronous IO control without request data, without request length parameter, without CEMR and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_NREQ_NLEN_ASYNC_NRES_NCEMR_ERROR_ENABLED          STD_OFF
/*! Support asynchronous IO control with request data, without request length parameter, without CEMR and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_REQ_NLEN_ASYNC_NRES_NCEMR_ERROR_ENABLED           STD_OFF
/*! Support asynchronous IO control with request data, with request length parameter, without CEMR and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_REQ_LEN_ASYNC_NRES_NCEMR_ERROR_ENABLED            STD_OFF
/*! Support synchronous IO control with request data, with request length parameter, with response data, without CEMR and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_REQ_LEN_SYNC_RES_NCEMR_ERROR_ENABLED              STD_OFF
/*! Support synchronous IO control without request data, without request length parameter, with CEMR 8Bit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_NREQ_NLEN_SYNC_NRES_CEMR8_ERROR_ENABLED           STD_OFF
/*! Support synchronous IO control with request data, without request length parameter, with CEMR 8Bit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_REQ_NLEN_SYNC_NRES_CEMR8_ERROR_ENABLED            STD_OFF
/*! Support synchronous IO control with request data, with request length parameter, with CEMR 8Bit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_REQ_LEN_SYNC_NRES_CEMR8_ERROR_ENABLED             STD_OFF
/*! Support asynchronous IO control without request data, without request length parameter, with CEMR 8Bit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_NREQ_NLEN_ASYNC_NRES_CEMR8_ERROR_ENABLED          STD_OFF
/*! Support asynchronous IO control with request data, without request length parameter, with CEMR 8Bit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_REQ_NLEN_ASYNC_NRES_CEMR8_ERROR_ENABLED           STD_OFF
/*! Support asynchronous IO control with request data, with request length parameter, with CEMR 8Bit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_REQ_LEN_ASYNC_NRES_CEMR8_ERROR_ENABLED            STD_OFF
/*! Support synchronous IO control without request data, without request length parameter, with CEMR 16Bit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_NREQ_NLEN_SYNC_NRES_CEMR16_ERROR_ENABLED          STD_OFF
/*! Support synchronous IO control with request data, without request length parameter, with CEMR 16Bit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_REQ_NLEN_SYNC_NRES_CEMR16_ERROR_ENABLED           STD_OFF
/*! Support synchronous IO control with request data, with request length parameter, with CEMR 16Bit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_REQ_LEN_SYNC_NRES_CEMR16_ERROR_ENABLED            STD_OFF
/*! Support asynchronous IO control without request data, without request length parameter, with CEMR 16Bit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_NREQ_NLEN_ASYNC_NRES_CEMR16_ERROR_ENABLED         STD_OFF
/*! Support asynchronous IO control with request data, without request length parameter, with CEMR 16Bit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_REQ_NLEN_ASYNC_NRES_CEMR16_ERROR_ENABLED          STD_OFF
/*! Support asynchronous IO control with request data, with request length parameter, with CEMR 16Bit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_REQ_LEN_ASYNC_NRES_CEMR16_ERROR_ENABLED           STD_OFF
/*! Support synchronous IO control without request data, without request length parameter, with CEMR 32Bit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_NREQ_NLEN_SYNC_NRES_CEMR32_ERROR_ENABLED          STD_OFF
/*! Support synchronous IO control with request data, without request length parameter, with CEMR 32Bit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_REQ_NLEN_SYNC_NRES_CEMR32_ERROR_ENABLED           STD_OFF
/*! Support synchronous IO control with request data, with request length parameter, with CEMR 32Bit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_REQ_LEN_SYNC_NRES_CEMR32_ERROR_ENABLED            STD_OFF
/*! Support asynchronous IO control without request data, without request length parameter, with CEMR 32Bit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_NREQ_NLEN_ASYNC_NRES_CEMR32_ERROR_ENABLED         STD_OFF
/*! Support asynchronous IO control with request data, without request length parameter, with CEMR 32Bit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_REQ_NLEN_ASYNC_NRES_CEMR32_ERROR_ENABLED          STD_OFF
/*! Support asynchronous IO control with request data, with request length parameter, with CEMR 32Bit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_REQ_LEN_ASYNC_NRES_CEMR32_ERROR_ENABLED           STD_OFF
/*! Support synchronous IO control without request data, without request length parameter, with CEMR NBit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_NREQ_NLEN_SYNC_NRES_CEMRN_ERROR_ENABLED           STD_OFF
/*! Support synchronous IO control with request data, without request length parameter, with CEMR NBit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_REQ_NLEN_SYNC_NRES_CEMRN_ERROR_ENABLED            STD_OFF
/*! Support synchronous IO control with request data, with request length parameter, with CEMR NBit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_REQ_LEN_SYNC_NRES_CEMRN_ERROR_ENABLED             STD_OFF
/*! Support asynchronous IO control without request data, without request length parameter, with CEMR NBit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_NREQ_NLEN_ASYNC_NRES_CEMRN_ERROR_ENABLED          STD_OFF
/*! Support asynchronous IO control with request data, without request length parameter, with CEMR NBit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_REQ_NLEN_ASYNC_NRES_CEMRN_ERROR_ENABLED           STD_OFF
/*! Support asynchronous IO control with request data, with request length parameter, with CEMR NBit and with ErrorCode */
# define DCM_DIDMGR_OPCLS_IO_REQ_LEN_ASYNC_NRES_CEMRN_ERROR_ENABLED            STD_OFF
/*! Support IO control with CEMR that will be handled by DCM */
# define DCM_DIDMGR_OPCLS_IO_ANY_WITH_INT_CEMR_ENABLED                         STD_OFF
/*! Support IO control with CEMR that will be handled by SW-C */
# define DCM_DIDMGR_OPCLS_IO_ANY_WITH_EXT_CEMR_ENABLED                         STD_OFF
/*! Support synchronous read scaling on DIDs */
# define DCM_DIDMGR_OPCLS_GETSCALINGINFO_SYNC_ENABLED                          STD_OFF
/*! Support asynchronous read scaling on DIDs */
# define DCM_DIDMGR_OPCLS_GETSCALINGINFO_ASYNC_ENABLED                         STD_OFF
/*! Service 0x22 needs DID operation lock */
# define DCM_DIDMGR_22_ACCESS_LOCK_ENABLED                                     STD_OFF
/*! Service 0x2A needs DID operation lock */
# define DCM_DIDMGR_2A_ACCESS_LOCK_ENABLED                                     STD_OFF
/*! Service 0x2C needs DID operation lock */
# define DCM_DIDMGR_2C_ACCESS_LOCK_ENABLED                                     STD_OFF
/*! Service 0x2E needs DID operation lock */
# define DCM_DIDMGR_2E_ACCESS_LOCK_ENABLED                                     STD_OFF
/*! Service 0x2F needs DID operation lock */
# define DCM_DIDMGR_2F_ACCESS_LOCK_ENABLED                                     STD_OFF
/*! Any DID service needs an operation lock */
# define DCM_DIDMGR_XX_ACCESS_LOCK_ENABLED                                     STD_OFF
/*! Any DID manager global data to be stored */
# define DCM_DIDMGR_RAM_CONTEXT_ENABLED                                        STD_OFF
/*! Support 'SupportedDIDs' that report availability of configured IO-Control DIDs */
# define DCM_DIDMGR_IO_CONTROL_SUPPORTEDDID_ENABLED                            STD_OFF
/*! Support 'SupportedDIDs' that report availability of configured Read DIDs */
# define DCM_DIDMGR_READ_SUPPORTEDDID_ENABLED                                  STD_OFF
/*! Support 'SupportedDIDs' that report availability of configured Write DIDs */
# define DCM_DIDMGR_WRITE_SUPPORTEDDID_ENABLED                                 STD_OFF
/*! Support RID manager  */
# define DCM_RIDMGR_SUPPORT_ENABLED                                            STD_ON
/*! Support dynamic length requests RIDs */
# define DCM_RIDMGR_DYN_REQ_LEN_ENABLED                                        STD_OFF
/*! Support dynamic length responses RIDs */
# define DCM_RIDMGR_DYN_RES_LEN_ENABLED                                        STD_OFF
/*! Support dynamic length RIDs */
# define DCM_RIDMGR_DYN_LEN_ENABLED                                            STD_OFF
/*! Support Routine Info Byte */
# define DCM_RIDMGR_SUPPORT_ROUTINEINFOBYTE_ENABLED                            STD_OFF
/*! Support rids without signals. */
# define DCM_RIDMGR_OPTYPE_NONE_ENABLED                                        STD_ON
/*! Support rids with static length, having request signals only. */
# define DCM_RIDMGR_OPTYPE_REQ_ENABLED                                         STD_ON
/*! Support rids with static request and response signals. */
# define DCM_RIDMGR_OPTYPE_REQ_RES_ENABLED                                     STD_OFF
/*! Support rids with static length, having response signals only. */
# define DCM_RIDMGR_OPTYPE_RES_ENABLED                                         STD_ON
/*! Support rids with dynamic length request signals. */
# define DCM_RIDMGR_OPTYPE_REQ_DYNLEN_ENABLED                                  STD_OFF
/*! Support rids with dynamic request and static response signals. */
# define DCM_RIDMGR_OPTYPE_REQ_DYNLEN_RES_ENABLED                              STD_OFF
/*! Support rids with dynamic length, having response signals only. */
# define DCM_RIDMGR_OPTYPE_RES_DYNLEN_ENABLED                                  STD_OFF
/*! Support rids with dynamic length, having request and response signals. */
# define DCM_RIDMGR_OPTYPE_REQ_DYNLEN_RES_DYNLEN_ENABLED                       STD_OFF
/*! Support rids with static request length and dynamic response signals. */
# define DCM_RIDMGR_OPTYPE_REQ_RES_DYNLEN_ENABLED                              STD_OFF
/*! Support external RID look up filter */
# define DCM_RIDMGR_EXTENDED_LOOKUP_ENABLED                                    STD_OFF
/*! Support 'SupportedRIDs' that report availability of configured RIDs */
# define DCM_RIDMGR_START_SUPPORTEDRID_ENABLED                                 STD_OFF
/*! Support direct memory access */
# define DCM_MEMMGR_SUPPORT_ENABLED                                            STD_OFF
/*! Support only specific ALFID values */
# define DCM_MEMMGR_ALFID_RESTRICTION_ENABLED                                  STD_OFF
/*! Support MID extensions on memory range */
# define DCM_MEMMGR_MID_SUPPORT_ENABLED                                        STD_OFF
/*! Support multiple MID extensions on memory range */
# define DCM_MEMMGR_MULTIMID_SUPPORT_ENABLED                                   STD_OFF
/*! Memory access race condition possible */
# define DCM_MEMMGR_ACCESS_LOCK_ENABLED                                        STD_OFF
/*! Memory access global RAM usage */
# define DCM_MEMMGR_RAM_CONTEXT_ENABLED                                        STD_OFF
/*! Support manager for OBD and UDS IDs */
# define DCM_OBDUDSIDMGR_SUPPORT_ENABLED                                       STD_OFF
/*! Support calibration for OBD and UDS IDs */
# define DCM_OBDUDSIDMGR_CALIBRATION_ENABLED                                   STD_OFF
/*! Support UDS MIDs provided by DEM module */
# define DCM_OBDUDSIDMGR_UDSMID_SUPPORT_BY_DEM_ENABLED                         STD_OFF
/*! Support UDS MIDs from DCM configuration */
# define DCM_OBDUDSIDMGR_UDSMID_SUPPORT_BY_DCM_ENABLED                         STD_OFF
# define DCM_SVC_22_OBD_CALIBRATION_ENABLED                                    STD_OFF
# define DCM_SVC_31_OBD_CALIBRATION_ENABLED                                    STD_OFF
/*! Support OBD manager for IDs */
# define DCM_OBDIDMGR_SUPPORT_ENABLED                                          STD_OFF
/*! Support OBD-MIDs through the AUTOSAR DEM APIs */
# define DCM_OBDIDMGR_OBDMID_SUPPORT_BY_DEM_ENABLED                            STD_OFF
/*! Support OBD-MIDs in DCM, don't use the AUTOSAR DEM APIs */
# define DCM_OBDIDMGR_OBDMID_SUPPORT_BY_DCM_ENABLED                            STD_OFF
/*! Support manager for OBD DTCs */
# define DCM_OBDDTCMGR_SUPPORT_ENABLED                                         STD_OFF
/*! Split task concept */
# define DCM_SPLIT_TASKS_ENABLED                                               STD_OFF
/*! Delay the unregistration of a diagnostic user */
# define DCM_NET_KEEP_ALIVE_TIME_ENABLED                                       STD_OFF
/*! Support OEM notifications */
# define DCM_DIAG_OEM_NOTIFICATION_ENABLED                                     STD_OFF
/*! Support SYS notifications */
# define DCM_DIAG_SYS_NOTIFICATION_ENABLED                                     STD_OFF
/*! Support service initializers */
# define DCM_DIAG_SVC_INITIALIZERS_ENABLED                                     STD_OFF
/*! Support external service processors */
# define DCM_DIAG_EXTERN_SVC_HANDLING_ENABLED                                  STD_OFF
/*! Support RCR-RP on jumping to the FBL */
# define DCM_DIAG_RCRRP_ON_BOOT_ENABLED                                        STD_ON
/*! Ignore any reqeust with response SID */
# define DCM_DIAG_IGNORE_RESPONSE_SID_ENABLED                                  STD_OFF
/*! Support final response after reset from FBL */
# define DCM_DIAG_JUMPFROMFBL_ENABLED                                          STD_ON
/*! Support jump to the FBL */
# define DCM_DIAG_JUMPTOFBL_ENABLED                                            STD_OFF
/*! Support multiple service tables */
# define DCM_DIAG_MULTI_SVC_TABLE_ENABLED                                      STD_OFF
/*! Support of fast post processing */
# define DCM_DIAG_FAST_POST_PROCESSING_ENABLED                                 STD_ON
/*! Suppression of NRC 0x7E, 0x7F on functional requests */
# define DCM_DIAG_SUPPRESS_NRC_7F_7E_ENABLED                                   STD_ON
/*! BswM notification for updated application */
# define DCM_DIAG_NOTIF_BSWM_APPL_UPDATED_ENABLED                              STD_OFF
/*! Reset to default session on any functionally requested OBD service */
# define DCM_DIAG_RST2DEF_ON_FUNC_OBD_REQ_ENABLED                              STD_OFF
/*! Support DCM state recovery */
# define DCM_DIAG_STATE_RECOVERY_ENABLED                                       STD_OFF
/*! Support RCR-RP transmission limitation */
# define DCM_DIAG_RCRRP_LIMIT_ENABLED                                          STD_ON
/*! Support virtual requests */
# define DCM_DIAG_VIRTUAL_REQUEST_ENABLED                                      STD_OFF
/*! Support internal API for access to the sub-module's activity state */
# define DCM_EXT_NEED_API_DIAGGETACTIVITYSTATE_ENABLED                         STD_OFF
/*! Has any internally handled diagnostic service with sub-function according to UDS */
# define DCM_DIAG_ANY_SERVICE_WITH_SF_ENABLED                                  STD_ON
/*! Support variant management */
# define DCM_VARMGR_SUPPORT_ENABLED                                            STD_OFF
/*! Support configuration variant management */
# define DCM_VARMGR_MULTI_SVC_EXCLUSIVE_ENABLED                                STD_OFF
/*! Support VSG variant management */
# define DCM_VARMGR_MULTI_SVC_INCLUSIVE_ENABLED                                STD_OFF
/*! Support communication variant management */
# define DCM_VARMGR_MULTI_COM_ENABLED                                          STD_OFF
/*! Active configuration mode for pre-compile */
# define DCM_VARMGR_MODE_PRECOMPILE_ENABLED                                    STD_ON
/*! Active configuration mode for link-time */
# define DCM_VARMGR_MODE_LINKTIME_ENABLED                                      STD_OFF
/*! Active configuration mode for post build loadable */
# define DCM_VARMGR_MODE_POSTBUILD_LOAD_ENABLED                                STD_OFF
/*! Active configuration mode for post build selectable */
# define DCM_VARMGR_MODE_POSTBUILD_SELECT_ENABLED                              STD_OFF
/*! Internal API for access to current communication variant */
# define DCM_EXT_NEED_API_VARMGRGETACTIVECOMVARIANT_ENABLED                    STD_OFF
/*! Diagnostic service 0x01 handled by DCM */
# define DCM_SVC_01_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x02 handled by DCM */
# define DCM_SVC_02_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x03 handled by DCM */
# define DCM_SVC_03_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x04 handled by DCM */
# define DCM_SVC_04_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x06 handled by DCM */
# define DCM_SVC_06_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x07 handled by DCM */
# define DCM_SVC_07_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x08 handled by DCM */
# define DCM_SVC_08_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x09 handled by DCM */
# define DCM_SVC_09_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x0A handled by DCM */
# define DCM_SVC_0A_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x10 handled by DCM */
# define DCM_SVC_10_SUPPORT_ENABLED                                            STD_ON
/*! Support jump to bootloader */
# define DCM_SVC_10_JMP2BOOT_ENABLED                                           STD_OFF
/*! Reset the ECU before the final response is sent */
# define DCM_SVC_10_RST2BOOT_HIS_ENABLED                                       STD_ON
/*! Diagnostic service 0x11 handled by DCM */
# define DCM_SVC_11_SUPPORT_ENABLED                                            STD_OFF
# define DCM_SVC_11_ECU_RESET_ENABLED                                          STD_OFF
# define DCM_SVC_11_RAPID_SHTDWN_ENABLED                                       STD_OFF
/*! Any user defined sub-functions available */
# define DCM_SVC_11_USER_ENABLED                                               STD_OFF
# define DCM_SVC_11_01_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_11_02_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_11_03_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_11_04_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_11_05_SUPPORT_ENABLED                                         STD_OFF
/*! Diagnostic service 0x14 handled by DCM */
# define DCM_SVC_14_SUPPORT_ENABLED                                            STD_ON
/*! Diagnostic service 0x19 handled by DCM */
# define DCM_SVC_19_SUPPORT_ENABLED                                            STD_OFF
# define DCM_SVC_19_01_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_02_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_03_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_04_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_05_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_06_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_07_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_08_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_09_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_0A_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_0B_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_0C_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_0D_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_0E_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_0F_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_10_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_11_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_12_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_13_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_14_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_15_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_16_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_17_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_18_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_19_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_19_42_SUPPORT_ENABLED                                         STD_OFF
/*! User memory identifier evaluation */
# define DCM_SVC_19_USER_MEM_ID_CHECK_ENABLED                                  STD_OFF
/*! Diagnostic service 0x22 handled by DCM */
# define DCM_SVC_22_SUPPORT_ENABLED                                            STD_ON
/*! Diagnostic service 0x23 handled by DCM */
# define DCM_SVC_23_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x24 handled by DCM */
# define DCM_SVC_24_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x27 handled by DCM */
# define DCM_SVC_27_SUPPORT_ENABLED                                            STD_OFF
/*! Support of at least one internal sub-function */
# define DCM_SVC_27_SUBFUNC_SUPPORT_ENABLED                                    STD_OFF
/*! Support multiple attempt counter instances */
# define DCM_SVC_27_MULTI_ATTEMPT_COUNTER_ENABLED                              STD_OFF
/*! Support multiple delay timer instances */
# define DCM_SVC_27_MULTI_DELAY_TIMER_ENABLED                                  STD_OFF
/*! Diagnostic service 0x28 handled by DCM */
# define DCM_SVC_28_SUPPORT_ENABLED                                            STD_OFF
/*! Support communication control on specific ECU channels */
# define DCM_SVC_28_SUBNET_SUPPORT_ENABLED                                     STD_OFF
/*! Support communication control on the request channel */
# define DCM_SVC_28_CURNET_SUPPORT_ENABLED                                     STD_OFF
/*! Any user defined sub-functions available */
# define DCM_SVC_28_USER_ENABLED                                               STD_OFF
/*! Diagnostic service 0x2A handled by DCM */
# define DCM_SVC_2A_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x2C handled by DCM */
# define DCM_SVC_2C_SUPPORT_ENABLED                                            STD_OFF
/*! Support dynamically define DID by identifier */
# define DCM_SVC_2C_01_SUPPORT_ENABLED                                         STD_OFF
/*! Support dynamically define DID by memory address */
# define DCM_SVC_2C_02_SUPPORT_ENABLED                                         STD_OFF
/*! Support clear dynamically defined DID */
# define DCM_SVC_2C_03_SUPPORT_ENABLED                                         STD_OFF
/*! Diagnostic service 0x2E handled by DCM */
# define DCM_SVC_2E_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x2F handled by DCM */
# define DCM_SVC_2F_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x31 handled by DCM */
# define DCM_SVC_31_SUPPORT_ENABLED                                            STD_ON
/*! Diagnostic service 0x34 handled by DCM */
# define DCM_SVC_34_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x35 handled by DCM */
# define DCM_SVC_35_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x36 handled by DCM */
# define DCM_SVC_36_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x37 handled by DCM */
# define DCM_SVC_37_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x38 handled by DCM */
# define DCM_SVC_38_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x3D handled by DCM */
# define DCM_SVC_3D_SUPPORT_ENABLED                                            STD_OFF
/*! Diagnostic service 0x3E handled by DCM */
# define DCM_SVC_3E_SUPPORT_ENABLED                                            STD_ON
/*! Diagnostic service 0x85 handled by DCM */
# define DCM_SVC_85_SUPPORT_ENABLED                                            STD_OFF
/*! Support DTC group in requests  */
# define DCM_SVC_85_DTC_GRP_ENABLED                                            STD_OFF
/*! Diagnostic service 0x86 handled by DCM */
# define DCM_SVC_86_SUPPORT_ENABLED                                            STD_OFF
# define DCM_SVC_86_00_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_86_01_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_86_04_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_86_05_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_86_06_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_86_40_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_86_41_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_86_43_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_86_45_SUPPORT_ENABLED                                         STD_OFF
# define DCM_SVC_86_46_SUPPORT_ENABLED                                         STD_OFF
/*! Service 0x86 needs a timer */
# define DCM_SVC_86_TIMER_ENABLED                                              STD_OFF
/*! Service 0x86 will be reset on session transition */
# define DCM_SVC_86_RST_ON_DSC_ENABLED                                         STD_OFF
/*! Service 0x86 needs nv blocks */
# define DCM_SVC_86_NVM_SUPPORT_ENABLED                                        STD_OFF
/*! Service 0x86 needs a notification on RoE response confirmation */
# define DCM_SVC_86_TX_END_IND_ENABLED                                         STD_OFF
/* ----------------------------------------------
 ~&&&   Defines
---------------------------------------------- */

/*! The maximum number of iterations per DCM task activation */
# define DCM_RUNTIME_USAGE_ITERATIONS                                           0u
# define DCM_RUNTIME_USAGE_ITERATIONS_CONST                                     0u
/*! DCM AUTOSAR versions */
# define DCM_DCM_AR_VERSION_403                                                0x0403u
/*! DCM AUTOSAR versions */
# define DCM_DCM_AR_VERSION_421                                                0x0421u
/*! DCM AUTOSAR versions */
# define DCM_DCM_AR_VERSION_422                                                0x0422u
/*! DCM active AUTOSAR version */
# define DCM_DCM_AR_VERSION                                                    0x0421u
/*! Vendor specific DCM extension identifier */
# define DCM_EXTENSION_ID                                                      0x96ACD543UL
/*! Specifies the AUTOSAR version of the PduR API */
# define DCM_PDUR_API_AR_VERSION                                               0x412
/*! Number of available buffers */
# define DCM_NET_NUM_BUFFERS                                                    1u
# define DCM_NET_NUM_BUFFERS_CONST                                              1u
/*! Maximum number of ComM channels to keep ECU awake */
# define DCM_NET_MAX_NUM_COMM_CHANNELS                                          1u
# define DCM_NET_MAX_NUM_COMM_CHANNELS_CONST                                    1u
/*! Maximum number of ComM channels DCM communicates over */
# define DCM_NET_MAX_NUM_CHANNELS                                               1u
# define DCM_NET_MAX_NUM_CHANNELS_CONST                                         1u
/*! Maximum number of parallel running connections */
# define DCM_NET_MAX_NUM_TRANSP_OBJECTS                                         1u
# define DCM_NET_MAX_NUM_TRANSP_OBJECTS_CONST                                   1u
/*! Maximum number of periodic transmission objects */
# define DCM_NET_MAX_NUM_PERIODIC_TX_OBJ                                        0u
# define DCM_NET_MAX_NUM_PERIODIC_TX_OBJ_CONST                                  0u
/*! Periodic buffer size */
# define DCM_NET_PERIODIC_BUFFER_SIZE                                           0u
/*! Pattern byte used for periodic transmission message padding */
# define DCM_NET_PERIODIC_MSG_PADDING_PATTERN                                  0xAAu
# define DCM_NET_PERIODIC_MSG_PADDING_PATTERN_CONST                            0xAAu
/*! The maximum size of all configured buffers */
# define DCM_NET_MAX_BUFFER_SIZE                                                256u
# define DCM_NET_MAX_BUFFER_SIZE_CONST                                          256u
/*! Maximum number of connections */
# define DCM_NET_MAX_NUM_CONNECTIONS                                            1u
# define DCM_NET_MAX_NUM_CONNECTIONS_CONST                                      1u
/*! Number of channels from main connections and ComControl channels */
# define DCM_NET_MAX_NUM_ALL_COMM_CHANNELS                                        1u
# define DCM_NET_MAX_NUM_ALL_COMM_CHANNELS_CONST                                  1u
/*! The default DemClientId */
# define DCM_NET_DEFAULT_DEM_CLIENTID                                          DemConf_DemClient_DemClient
# define DCM_NET_DEFAULT_DEM_CLIENTID_CONST                                    DemConf_DemClient_DemClient
/*! Size of table Dcm_CfgNetBufferInfo */
# define DCM_CFGNETBUFFERINFO_SIZE                                              1u
# define DCM_CFGNETBUFFERINFO_SIZE_CONST                                        1u
/*!  ----- Symbolic name values for DCM protocols -----  */
# define DcmConf_DcmDslProtocolRow_DcmDslProtocolRow_0                          3u
/*!  ----- Symbolic name values for Rx PduIds -----  */
# define DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_0                            1u
# define DcmConf_DcmDslProtocolRx_DcmDslProtocolRx_1                            0u
/*!  ----- Symbolic name values for Tx PduIds -----  */
# define DcmConf_DcmDslProtocolTx_DcmDslProtocolTx                              0u
/*! Number of receive PduIds */
# define DCM_NET_NUM_RX_PDUIDS                                                  2u
# define DCM_NET_NUM_RX_PDUIDS_CONST                                            2u
/*! Number of send PduIds */
# define DCM_NET_NUM_TX_PDUIDS                                                  1u
# define DCM_NET_NUM_TX_PDUIDS_CONST                                            1u
/*! The total number of configured protocols */
# define DCM_NET_NUM_PROTOCOLS                                                  1u
# define DCM_NET_NUM_PROTOCOLS_CONST                                            1u
/*! The minimum RxPduID value of the CanTp */
# define DCM_NET_CANTP_RX_PDUID_MIN                                               0u
# define DCM_NET_CANTP_RX_PDUID_MIN_CONST                                         0u
/*! The maximum RxPduID value of the CanTp */
# define DCM_NET_CANTP_RX_PDUID_MAX                                               0u
# define DCM_NET_CANTP_RX_PDUID_MAX_CONST                                         0u
/*! The total number of CanTp RxPduIDs */
# define DCM_NET_NUM_CANTP_RX_PDUIDS                                              0u
# define DCM_NET_NUM_CANTP_RX_PDUIDS_CONST                                        0u
/*! Size of table Dcm_CfgNetRxPduInfo */
# define DCM_CFGNETRXPDUINFO_SIZE                                               2u
# define DCM_CFGNETRXPDUINFO_SIZE_CONST                                         2u
/*! Size of table Dcm_CfgNetTxPduInfo */
# define DCM_CFGNETTXPDUINFO_SIZE                                               1u
# define DCM_CFGNETTXPDUINFO_SIZE_CONST                                         1u
/*! Size of table Dcm_CfgNetConnectionInfo */
# define DCM_CFGNETCONNECTIONINFO_SIZE                                          1u
# define DCM_CFGNETCONNECTIONINFO_SIZE_CONST                                    1u
/*! Size of table Dcm_CfgNetProtocolInfo */
# define DCM_CFGNETPROTOCOLINFO_SIZE                                            1u
# define DCM_CFGNETPROTOCOLINFO_SIZE_CONST                                      1u
/*! Size of table Dcm_CfgNetAllComMChannelMap */
# define DCM_CFGNETALLCOMMCHANNELMAP_SIZE                                       1u
# define DCM_CFGNETALLCOMMCHANNELMAP_SIZE_CONST                                 1u
/*! Size of table Dcm_CfgNetConnComMChannelMap */
# define DCM_CFGNETCONNCOMMCHANNELMAP_SIZE                                      1u
# define DCM_CFGNETCONNCOMMCHANNELMAP_SIZE_CONST                                1u
/*! Size of table Dcm_CfgNetNetworkHandleLookUpTable */
# define DCM_CFGNETNETWORKHANDLELOOKUPTABLE_SIZE                                2u
# define DCM_CFGNETNETWORKHANDLELOOKUPTABLE_SIZE_CONST                          2u
/*! Reference to padding function */
# define DCM_PAGEDBUFFER_PADDING_FUNC_REF                                       1u
# define DCM_PAGEDBUFFER_PADDING_FUNC_REF_CONST                                 1u
/*! The mode rule reference for DTC setting re-enabling */
# define DCM_MODE_CTRLDTCSETTING_MONITOR_MODERULE_REF                             0u
# define DCM_MODE_CTRLDTCSETTING_MONITOR_MODERULE_REF_CONST                       0u
/*! The mode rule reference for communication control re-enabling */
# define DCM_MODE_COMMCTRL_MONITOR_MODERULE_REF                                   0u
# define DCM_MODE_COMMCTRL_MONITOR_MODERULE_REF_CONST                             0u
/*! Number of session states */
# define DCM_STATE_NUM_SESSION                                                  3u
/*! Number of security access states */
# define DCM_STATE_NUM_SECURITY                                                 0u
/*! Number of security levels (all security states except the "locked" one) */
# define DCM_STATE_SECURITY_NUM_LEVELS                                          0u
/*! Size of table Dcm_CfgStatePreconditions */
# define DCM_CFGSTATEPRECONDITIONS_SIZE                                         3u
# define DCM_CFGSTATEPRECONDITIONS_SIZE_CONST                                   3u
/*! Size of table Dcm_CfgStateSessionInfo */
# define DCM_CFGSTATESESSIONINFO_SIZE                                           3u
# define DCM_CFGSTATESESSIONINFO_SIZE_CONST                                     3u
/*!  ----- Symbolic name values for Session -----  */
# define DcmConf_DcmDspSessionRow_Default                                       1u
# define DcmConf_DcmDspSessionRow_Programming                                   2u
# define DcmConf_DcmDspSessionRow_Extended                                      3u
/*! Number of DID ranges */
# define DCM_NUM_DID_RANGES                                                     0u
# define DCM_NUM_DID_RANGES_CONST                                               0u
/*! Number of items per DynDID */
# define DCM_NUM_ITEMS_PER_DYNDID                                               0u
# define DCM_NUM_ITEMS_PER_DYNDID_CONST                                         0u
/*! Total number of DynDID items */
# define DCM_NUM_DYNDID_ITEMS                                                     0u
# define DCM_NUM_DYNDID_ITEMS_CONST                                               0u
/*! Number of dynamically defined DIDs */
# define DCM_NUM_DYNDIDS                                                          0u
# define DCM_NUM_DYNDIDS_CONST                                                    0u
/*! Number of IO control DIDs */
# define DCM_NUM_IODIDS                                                           0u
# define DCM_NUM_IODIDS_CONST                                                     0u
/*! Maximum size of an IO control DIDs CEMR to be passed to the application */
# define DCM_DIDMGR_IODID_MAX_EXT_CEMR_SIZE                                       0u
# define DCM_DIDMGR_IODID_MAX_EXT_CEMR_SIZE_CONST                                 0u
/*! Size of table Dcm_CfgDidMgrDidLookUpTable */
# define DCM_CFGDIDMGRDIDLOOKUPTABLE_SIZE                                       3u
# define DCM_CFGDIDMGRDIDLOOKUPTABLE_SIZE_CONST                                 3u
/*! Size of table Dcm_CfgDidMgrDidInfo */
# define DCM_CFGDIDMGRDIDINFO_SIZE                                              2u
# define DCM_CFGDIDMGRDIDINFO_SIZE_CONST                                        2u
/*! Size of table Dcm_CfgDidMgrOpInfo */
# define DCM_CFGDIDMGROPINFO_SIZE                                               2u
# define DCM_CFGDIDMGROPINFO_SIZE_CONST                                         2u
/*! Size of table Dcm_CfgDidMgrSignalOpClassInfo */
# define DCM_CFGDIDMGRSIGNALOPCLASSINFO_SIZE                                    4u
# define DCM_CFGDIDMGRSIGNALOPCLASSINFO_SIZE_CONST                              4u
/*! Invalid value for Routine Info Byte */
# define DCM_CFGRIDMGR_INVALID_ROUTINEINFOBYTE                                    0u
# define DCM_CFGRIDMGR_INVALID_ROUTINEINFOBYTE_CONST                              0u
/*! Size of table Dcm_CfgRidMgrRidLookUpTable */
# define DCM_CFGRIDMGRRIDLOOKUPTABLE_SIZE                                       2u
# define DCM_CFGRIDMGRRIDLOOKUPTABLE_SIZE_CONST                                 2u
/*! Size of table Dcm_CfgRidMgrRidInfo */
# define DCM_CFGRIDMGRRIDINFO_SIZE                                              1u
# define DCM_CFGRIDMGRRIDINFO_SIZE_CONST                                        1u
/*! Size of table Dcm_CfgRidMgrOpInfo */
# define DCM_CFGRIDMGROPINFO_SIZE                                               3u
# define DCM_CFGRIDMGROPINFO_SIZE_CONST                                         3u
/*! Specifies total number of supported memory operations */
# define DCM_MEMMGR_NUM_MEMORY_OPERATIONS                                       0u
# define DCM_MEMMGR_NUM_MEMORY_OPERATIONS_CONST                                 0u
/*! Specifies total number of memory ranges in single MID or no MID mode */
# define DCM_MEMMGR_MEMMAP_NUM_ENTRIES                                            0u
# define DCM_MEMMGR_MEMMAP_NUM_ENTRIES_CONST                                      0u
/*! Configured main function period time */
# define DCM_TASK_CYCLE_MS                                                       10u
# define DCM_TASK_CYCLE_MS_CONST                                                 10u
/*! Configured keep alive time */
# define DCM_NET_KEEP_ALIVE_TIME                                                  0u
# define DCM_NET_KEEP_ALIVE_TIME_CONST                                            0u
/*! Tester present timeout */
# define DCM_DIAG_TIME_S3                                                       500u
# define DCM_DIAG_TIME_S3_CONST                                                 500u
/*! Maximum number of RCR-RP response before processing interruption */
# define DCM_DIAG_RCRRP_LIMIT_COUNT                                             2u
# define DCM_DIAG_RCRRP_LIMIT_COUNT_CONST                                       2u
/*! Specifies the NRC to be sent, once the maximum number of RCR-RP responses has been reached */
# define DCM_DIAG_CANCEL_OP_NRC                                                DCM_E_GENERALREJECT
# define DCM_DIAG_CANCEL_OP_NRC_CONST                                          DCM_E_GENERALREJECT
/*! Specifies the reference to function that stops the repeater */
# define DCM_DIAG_SERVICEINFO_REPEATEREND_IDX                                   5u
/*! Size of table Dcm_CfgDiagSvcIdLookUpTable */
# define DCM_CFGDIAGSVCIDLOOKUPTABLE_SIZE                                       6u
# define DCM_CFGDIAGSVCIDLOOKUPTABLE_SIZE_CONST                                 6u
/*! Size of table Dcm_CfgDiagServiceInfo */
# define DCM_CFGDIAGSERVICEINFO_SIZE                                            6u
# define DCM_CFGDIAGSERVICEINFO_SIZE_CONST                                      6u
/*! Size of table Dcm_CfgDiagSvcIdExecPrecondTable */
# define DCM_CFGDIAGSVCIDEXECPRECONDTABLE_SIZE                                  5u
# define DCM_CFGDIAGSVCIDEXECPRECONDTABLE_SIZE_CONST                            5u
/*! Size of table Dcm_CfgDiagSvcPostProcessors */
# define DCM_CFGDIAGSVCPOSTPROCESSORS_SIZE                                      3u
# define DCM_CFGDIAGSVCPOSTPROCESSORS_SIZE_CONST                                3u
/*! Total number of configuration variants */
# define DCM_VARMGR_NUM_CFG_VARIANTS                                              1u
# define DCM_VARMGR_NUM_CFG_VARIANTS_CONST                                        1u
/*! Release specific variant magic number */
# define DCM_CFG_FINAL_MAGIC_NUMBER                                            0x3530u
/*! Release specific generator compatibility number */
# define DCM_CFG_GEN_COMPATIBILITY_VERSION                                     0x8181u
/*! Size of table Dcm_CfgSvc10SubFuncLookUpTable */
# define DCM_CFGSVC10SUBFUNCLOOKUPTABLE_SIZE                                    4u
# define DCM_CFGSVC10SUBFUNCLOOKUPTABLE_SIZE_CONST                              4u
/*! Size of table Dcm_CfgSvc10SubFuncInfo */
# define DCM_CFGSVC10SUBFUNCINFO_SIZE                                           3u
# define DCM_CFGSVC10SUBFUNCINFO_SIZE_CONST                                     3u
/*! Size of table Dcm_CfgSvc10SubFuncExecPrecondTable */
# define DCM_CFGSVC10SUBFUNCEXECPRECONDTABLE_SIZE                               3u
# define DCM_CFGSVC10SUBFUNCEXECPRECONDTABLE_SIZE_CONST                         3u
/*! Specifies the user memory identifier to be accepted */
# define DCM_SVC_19_USER_MEM_ID                                                0x00u
# define DCM_SVC_19_USER_MEM_ID_CONST                                          0x00u
/*! Specifies the maximum number of DIDs per single request service 0x22 */
# define DCM_SVC_22_MAX_DID_LIST_LEN                                            1u
# define DCM_SVC_22_MAX_DID_LIST_LEN_CONST                                      1u
/*! The total number of failed attempt counter monitors */
# define DCM_SVC_27_NUM_ATTEMPT_COUNTERS                                        0u
/*! The total number of failed attempt timers */
# define DCM_SVC_27_NUM_DELAY_TIMERS                                            0u
/*! Specifies the buffers size needed for data extraction of a DDDID source item */
# define DCM_SVC_2C_READ_BUFFER_SIZE                                              0u
/*! Size of table Dcm_CfgSvc3ESubFuncLookUpTable */
# define DCM_CFGSVC3ESUBFUNCLOOKUPTABLE_SIZE                                    2u
# define DCM_CFGSVC3ESUBFUNCLOOKUPTABLE_SIZE_CONST                              2u
/*! Size of table Dcm_CfgSvc3ESubFuncExecPrecondTable */
# define DCM_CFGSVC3ESUBFUNCEXECPRECONDTABLE_SIZE                               1u
# define DCM_CFGSVC3ESUBFUNCEXECPRECONDTABLE_SIZE_CONST                         1u
#endif /* !defined(DCM_CFG_H) */
/* ********************************************************************************************************************
 * END OF FILE: Dcm_Cfg.h
 * ******************************************************************************************************************** */

