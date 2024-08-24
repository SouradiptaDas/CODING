#include "__cf_P_O_Algorithm.h"
#ifndef RTW_HEADER_P_O_Algorithm_cap_host_h_
#define RTW_HEADER_P_O_Algorithm_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
P_O_Algorithm_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void P_O_Algorithm_host_InitializeDataMapInfo (
P_O_Algorithm_host_DataMapInfo_T * dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
