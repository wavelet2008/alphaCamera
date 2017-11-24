/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hi_awb_comm.h
  Version       : Initial Draft
  Author        : Hisilicon multimedia software group
  Created       : 2012/12/19
  Description   : 
  History       :
  1.Date        : 2012/12/19
    Author      : n00168968
    Modification: Created file

******************************************************************************/
#ifndef __HI_AWB_COMM_H__
#define __HI_AWB_COMM_H__

#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* End of #ifdef __cplusplus */

#define HI_AWB_LIB_NAME "hisi_awb_lib"

typedef struct hiAWB_DBG_ATTR_S
{
    HI_U16 u16WhiteLevel;
    HI_U16 u16BlackLevel;
    HI_U16 u16CrMax;
    HI_U16 u16CrMin;
    HI_U16 u16CbMax;
    HI_U16 u16CbMin;
    HI_U16 u16CrHigh;
    HI_U16 u16CrLow;
    HI_U16 u16CbHigh;
    HI_U16 u16CbLow;
    HI_U16 u16RawWhiteLevel;
    HI_U16 u16RawBlackLevel;
    HI_U16 u16RawCrMax;
    HI_U16 u16RawCrMin;
    HI_U16 u16RawCbMax;
    HI_U16 u16RawCbMin;
    HI_U16 u16RawCrHigh;
    HI_U16 u16RawCrLow;
    HI_U16 u16RawCbHigh;
    HI_U16 u16RawCbLow;

    HI_U16 u16WDRMode;
    HI_U16 u16Enable;
    HI_U16 u16ManualEnable;
    HI_U16 u16Zone;
    HI_U16 u16HighTemp;
    HI_U16 u16LowTemp;
    HI_U16 u16RefTemp;
    HI_U16 u16RgainBase;
    HI_U16 u16GgainBase;
    HI_U16 u16BgainBase;
    HI_S32 s32p1;
    HI_S32 s32p2;
    HI_S32 s32q;
    HI_S32 s32a;
    HI_S32 s32c;
    
    HI_U16 u16ManSatEnable;
    HI_U16 u16SatTarget;
} AWB_DBG_ATTR_S;

typedef struct hiAWB_ZONE_DBG_S
{
    HI_U16 u16Sum;
    HI_U16 u16Rg;
    HI_U16 u16Bg;
    HI_U16 u16CountAll;
    HI_U16 u16CountMin;
    HI_U16 u16CountMax;
    HI_U16 u16RawRAvg;
    HI_U16 u16RawGAvg;
    HI_U16 u16RawBAvg;
    HI_U16 u16TK;
    HI_U16 u16Weight;
    HI_S16 s16Shift;
}AWB_ZONE_DBG_S;

typedef struct hiAWB_DBG_STATUS_S
{
    HI_U32 u32FrmNumBgn;
    HI_U32 u32GlobalSum;
    HI_U16 u16GlobalRgSta;
    HI_U16 u16GlobalBgSta;
    HI_U16 u16GlobalCountAll;
    HI_U16 u16GlobalCountMin;
    HI_U16 u16GlobalCountMax;
    HI_U16 u16GlobalRAvg;
    HI_U16 u16GlobalGAvg;
    HI_U16 u16GlobalBAvg;
    HI_U16 u16TK;
    HI_U16 u16Rgain;
    HI_U16 u16Ggain;
    HI_U16 u16Bgain;
    HI_U16 au16CCM[CCM_MATRIX_SIZE];

    HI_U32 au32HistInfo[256];
    AWB_ZONE_DBG_S astZoneDebug[AWB_ZONE_NUM];

    HI_U32 u32FrmNumEnd;    
} AWB_DBG_STATUS_S;

/************************** sensor's interface to awb *********************/
typedef struct hiAWB_CCM_S
{    
    HI_U16 u16HighColorTemp;    /* D50 lighting source is  recommended */
    HI_U16 au16HighCCM[CCM_MATRIX_SIZE];
    HI_U16 u16MidColorTemp;     /* D32 lighting source is  recommended */
    HI_U16 au16MidCCM[CCM_MATRIX_SIZE];       
    HI_U16 u16LowColorTemp;     /* A lighting source is  recommended */
    HI_U16 au16LowCCM[CCM_MATRIX_SIZE];
}AWB_CCM_S;

typedef struct hiAWB_AGC_TABLE_S
{
    HI_BOOL bValid;
    
    HI_U8   au8Saturation[ISP_AUTO_STENGTH_NUM];   /* adjust saturation, different iso with different saturation */
} AWB_AGC_TABLE_S;

typedef struct hiAWB_SENSOR_DEFAULT_S
{
    HI_U16  u16WbRefTemp;       /* reference color temperature for WB  */    
    HI_U16  au16GainOffset[ISP_BAYER_CHN_NUM];  /* gain offset for white balance */
    HI_S32  as32WbPara[AWB_CURVE_PARA_NUM];      /* parameter for wb curve,p1,p2,q1,a1,b1,c1 */

    AWB_AGC_TABLE_S stAgcTbl;
    AWB_CCM_S stCcm;
} AWB_SENSOR_DEFAULT_S;

typedef struct hiAWB_SENSOR_EXP_FUNC_S
{
    HI_S32(*pfn_cmos_get_awb_default)(ISP_DEV IspDev, AWB_SENSOR_DEFAULT_S *pstAwbSnsDft);
} AWB_SENSOR_EXP_FUNC_S;

typedef struct hiAWB_SENSOR_REGISTER_S
{
    AWB_SENSOR_EXP_FUNC_S stSnsExp;
} AWB_SENSOR_REGISTER_S;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif
