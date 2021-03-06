/**
 * @file     hi_product_statemng.h
 * @brief    Describes the data structure define,the message define,
 *           and the function about statemng module.
 *
 * Copyright (c) 2017 Huawei Tech.Co.,Ltd
 *
 * @author   HiMobileCam Reference Develop Team
 * @date     2017/12/11
 * @version  1.0
 */
#ifndef __HI_PRODUCT_STATEMNG_H__
#define __HI_PRODUCT_STATEMNG_H__

#include "hi_appcomm.h"
#include "hi_storagemng.h"
#include "hi_message.h"
#include "hi_product_param_define.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* End of #ifdef __cplusplus */

/** \addtogroup     STATEMNG */
/** @{ */  /** <!-- [STATEMNG] */

/** product error id */
#define HI_PDT_STATEMNG_EINITIALIZED    HI_APPCOMM_ERR_ID(HI_APP_MOD_STATEMNG,HI_EINITIALIZED)/**<Initialized already */
#define HI_PDT_STATEMNG_ENOTINIT        HI_APPCOMM_ERR_ID(HI_APP_MOD_STATEMNG,HI_ENOINIT)/**<Not inited */
#define HI_PDT_STATEMNG_EINVAL          HI_APPCOMM_ERR_ID(HI_APP_MOD_STATEMNG,HI_EINVAL)/**<Parameter invalid */
#define HI_PDT_STATEMNG_EINTER          HI_APPCOMM_ERR_ID(HI_APP_MOD_STATEMNG,HI_EINTER)/**<Internal error */
#define HI_PDT_STATEMNG_ENULLPTR        HI_APPCOMM_ERR_ID(HI_APP_MOD_STATEMNG,HI_ERRNO_CUSTOM_BOTTOM + 1)/**<Null pointer */
#define HI_PDT_STATEMNG_EINPROGRESS     HI_APPCOMM_ERR_ID(HI_APP_MOD_STATEMNG,HI_ERRNO_CUSTOM_BOTTOM + 2)/**<Operation now in progress */

/** product workmode information */
typedef struct hiPDT_STATEMNG_WORKMODE_STATE_S
{
    HI_PDT_WORKMODE_E enWorkMode;/**<current workmode */
    HI_BOOL bRunning;/**<workmode status */
    HI_BOOL bStateMngInProgress;/**<statemng status */
} HI_PDT_STATEMNG_WORKMODE_STATE_S;

/** product message enum */
typedef enum hiEVENT_STATEMNG_E
{
    HI_EVENT_STATEMNG_SWITCH_WORKMODE = HI_APPCOMM_EVENT_ID(HI_APP_MOD_STATEMNG,0),
    HI_EVENT_STATEMNG_START,
    HI_EVENT_STATEMNG_STOP,
    HI_EVENT_STATEMNG_SETTING,
    HI_EVENT_STATEMNG_POWEROFF,
    HI_EVENT_STATEMNG_SD_AVAILABLE,
    HI_EVENT_STATEMNG_SD_UNAVAILABLE,
    HI_EVENT_STATEMNG_SD_FORMAT,
    HI_EVENT_STATEMNG_VO_SWITCH,
    HI_EVENT_STATEMNG_FACTORY_RESET,
    HI_EVENT_STATEMNG_DEBUG_SWITCH,
    HI_EVENT_STATEMNG_RESET,
    HI_EVENT_STATEMNG_UPGRADE_START,
    HI_EVENT_STATEMNG_DONOTUPGRADE,
    HI_EVENT_STATEMNG_UPGRADE_ABNORMAL,
    HI_EVENT_STATEMNG_UPGRADE_FAILED,
    HI_EVENT_STATEMNG_BUTT
} HI_EVENT_STATEMNG_E;

/** exit mode */
typedef enum hiEXIT_MODE_E
{
    HI_EXIT_MODE_POWEROFF,
    HI_EXIT_MODE_RESET,
    HI_EXIT_MODE_BUTT
} HI_EXIT_MODE_E;

/** exit mode callback */
typedef HI_S32 (*HI_PDT_STATEMNG_EXIT_MODE_CALLBACK_FN_PTR)(HI_EXIT_MODE_E enExitMode);

/** statemng configure */
typedef struct hiPDT_STATEMNG_CONFIG_S
{
    HI_PDT_STATEMNG_EXIT_MODE_CALLBACK_FN_PTR pfnExitCB;
    HI_STORAGEMNG_FORMAT_PREPROC_CALLBACK_FN_PTR pfnFormatPreProc;
} HI_PDT_STATEMNG_CONFIG_S;

/**
 * @brief        statemng initialization
 * @return       0 success, non-zero error code.
 * @exception    None
 * @author       HiMobileCam Reference Develop Team
 * @date         2017/12/11
 */
HI_S32 HI_PDT_STATEMNG_Init(const HI_PDT_STATEMNG_CONFIG_S* stStatemngCfg);

/**
 * @brief        statemng deinitialization
 * @return       0 success, non-zero error code.
 * @exception    None
 * @author       HiMobileCam Reference Develop Team
 * @date         2017/12/11
 */
HI_S32 HI_PDT_STATEMNG_Deinit(HI_VOID);

/**
 * @brief        get current wokemode state
 * @param[out]   pstWorkModeState, state structure to descript current workmode's state
 * @return       0 success, non-zero error code
 * @exception    None
 * @author       HiMobileCam Reference Develop Team
 * @date         2017/12/11
 */
HI_S32 HI_PDT_STATEMNG_GetState(HI_PDT_STATEMNG_WORKMODE_STATE_S* pstWorkModeState);

/**
 * @brief        send message to statemng with parameter
 * @param[in]    pstMessage, message structure, including message and parameter
 * @return       0 success, non-zero error code
 * @exception    None
 * @author       HiMobileCam Reference Develop Team
 * @date         2017/12/11
 */
HI_S32 HI_PDT_STATEMNG_SendMessage(const HI_MESSAGE_S* pstMessage);

/**
 * @brief        generate Power on workmode
 * @param[out]   penPoweronAction, PoweronAction enum
 * @param[out]   penPoweronWorkmode, PoweronWorkmode enum
 * @return       0 success, non-zero error code
 * @exception    None
 * @author       HiMobileCam Reference Develop Team
 * @date         2017/12/11
 */
HI_S32 HI_PDT_STATEMNG_GeneratePoweronWorkmode(HI_PDT_POWERON_ACTION_E *penPoweronAction,
    HI_PDT_WORKMODE_E *penPoweronWorkmode);

/**
 * @brief        registe event to eventhub for publish
 * @return       0 success, non-zero error code
 * @exception    None
 * @author       HiMobileCam Reference Develop Team
 * @date         2017/12/11
 */
HI_S32 HI_PDT_STATEMNG_RegisterEvent(HI_VOID);

/** @}*/  /** <!-- ==== STATEMNG End ====*/

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /* End of #ifndef __HI_PRODUCT_STATEMNG_H__ */
