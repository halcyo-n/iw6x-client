#include <std_include.hpp>
#include "steam/steam.hpp"
#include "component/steam_proxy.hpp"

namespace steam
{
	unsigned int utils::GetSecondsSinceAppActive()
	{
		return 0;
	}

	unsigned int utils::GetSecondsSinceComputerActive()
	{
		return 0;
	}

	int utils::GetConnectedUniverse()
	{
		return 1;
	}

	unsigned int utils::GetServerRealTime()
	{
		return 0;
	}

	const char* utils::GetIPCountry()
	{
		return "US";
	}

	bool utils::GetImageSize(int iImage, unsigned int* pnWidth, unsigned int* pnHeight)
	{
		return false;
	}

	bool utils::GetImageRGBA(int iImage, unsigned char* pubDest, int nDestBufferSize)
	{
		return false;
	}

	bool utils::GetCSERIPPort(unsigned int* unIP, unsigned short* usPort)
	{
		return false;
	}

	unsigned char utils::GetCurrentBatteryPower()
	{
		return 255;
	}

	unsigned int utils::GetAppID()
	{
		return 42690;
	}

	void utils::SetOverlayNotificationPosition(int eNotificationPosition)
	{
		const auto& overlay = steam_proxy::get_overlay_module();
		if (overlay)
		{
			overlay.invoke<void>("SetNotificationPosition", eNotificationPosition);
		}
	}

	bool utils::IsAPICallCompleted(unsigned long long hSteamAPICall, bool* pbFailed)
	{
		return false;
	}

	int utils::GetAPICallFailureReason(unsigned long long hSteamAPICall)
	{
		return -1;
	}

	bool utils::GetAPICallResult(unsigned long long hSteamAPICall, void* pCallback, int cubCallback,
	                             int iCallbackExpected, bool* pbFailed)
	{
		return false;
	}

	void utils::RunFrame()
	{
	}

	unsigned int utils::GetIPCCallCount()
	{
		return 0;
	}

	void utils::SetWarningMessageHook(void (*pFunction)(int hpipe, const char* message))
	{
	}

	bool utils::IsOverlayEnabled()
	{
		return false;
	}

	bool utils::BOverlayNeedsPresent()
	{
		return false;
	}

	unsigned long long utils::CheckFileSignature(const char* szFileName)
	{
		return 0;
	}
}
