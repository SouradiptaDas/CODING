#include "P_O_Algorithm_capi_host.h"
static P_O_Algorithm_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        P_O_Algorithm_host_InitializeDataMapInfo(&(root), "P_O_Algorithm");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
