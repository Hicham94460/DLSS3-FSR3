#include "nvngx.h"

NGXDLLEXPORT uint32_t NVSDK_NGX_GetAPIVersion()
{
	return 19;
}

NGXDLLEXPORT uint32_t NVSDK_NGX_GetApplicationId()
{
	return 0x0E658703; // NGXAppId
}

NGXDLLEXPORT uint32_t NVSDK_NGX_GetDriverVersion()
{
	return 0x2080000; // NGXMinimumDriverVersion 520.00
}

NGXDLLEXPORT NGXResult NVSDK_NGX_GetDriverVersionEx(uint32_t *Versions, uint32_t InputVersionCount, uint32_t *TotalDriverVersionCount)
{
	if (!Versions && !TotalDriverVersionCount)
		return 0xBAD00005;

	if (TotalDriverVersionCount)
		*TotalDriverVersionCount = 2;

	if (Versions && InputVersionCount >= 1)
	{
		Versions[0] = 0x208; // 520

		if (InputVersionCount >= 2)
			Versions[1] = 0;
	}

	return NGX_SUCCESS;
}

NGXDLLEXPORT uint32_t NVSDK_NGX_GetGPUArchitecture()
{
	return NGXHardcodedArchitecture; // NGXGpuArchitecture NV_GPU_ARCHITECTURE_AD100 (0x190)
}

NGXDLLEXPORT uint32_t NVSDK_NGX_GetSnippetVersion()
{
	return 0x30500; // NGXSnippetVersion 3.5.0
}

NGXDLLEXPORT NGXResult NVSDK_NGX_ProcessCommand(const char *Command, const char *Value, void *Unknown)
{
	return NGX_SUCCESS; // Command gets logged but otherwise does nothing
}

NGXDLLEXPORT NGXResult NVSDK_NGX_SetInfoCallback(void *Callback)
{
	return NGX_SUCCESS;
}

NGXDLLEXPORT NGXResult NVSDK_NGX_SetTelemetryEvaluateCallback(void *Callback)
{
	return NGX_SUCCESS;
}
