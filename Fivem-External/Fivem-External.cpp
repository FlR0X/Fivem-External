#include <Windows.h>
#include <thread>
#include <future>
#include <Cheat/Cheat.hpp>
#include <FrameWork/FrameWork.hpp>
#include <tchar.h>
#include "xor.hpp"
#include "../Fivem-External/Auth/auth.hpp"
#include "../Fivem-External/FrameWork/Render/Interface.hpp"

static BOOL CheckForUIAccess(DWORD* pdwErr, BOOL* pfUIAccess)
{
    BOOL result = FALSE;
    HANDLE hToken;

    if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken))
    {
        DWORD dwRetLen;

        if (GetTokenInformation(hToken, TokenUIAccess, pfUIAccess, sizeof(*pfUIAccess), &dwRetLen))
        {
            result = TRUE;
        }
        else
        {
            *pdwErr = GetLastError();
        }
        CloseHandle(hToken);
    }
    else
    {
        *pdwErr = GetLastError();
    }

    return result;
}

DWORD WINAPI Unload()
{
    SafeCall(ExitProcess)(0);
    return TRUE;
}



int main()
{
	SetConsoleTitleA((XorStr("Eichelkäse Technologie.vip")));
	std::string licensekey;
printf(XorStr("                Eichelkaese Paste Technology - PimmelHook Private                       \n"));
	Cheat::Initialize();

	while (!g_Options.General.ShutDown)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	
}



