#include "path.h"
#include <windows.h>

namespace ntlibr3
{
    namespace path
    {
        std::wstring devicePath_2_dosPath(std::wstring devicePath)
        {
            std::wstring dosPath;
            // 只处理了A-Z的情况，AA，AB的没有考虑
            WCHAR driveLetters[150] = { 0 };
            do
            {
                GetLogicalDriveStrings(ARRAYSIZE(driveLetters), driveLetters);
                PWCHAR pStart = driveLetters;

                while (*pStart != L'\0')
                {
                    std::wstring drive = pStart;
                    if (drive.empty())
                    {
                        break;
                    }
                    pStart += drive.length() + 1;

                    WCHAR deviceTmp[100];
                    drive[drive.length() - 1] = L'\0';
                    QueryDosDevice(drive.c_str(), deviceTmp, ARRAYSIZE(deviceTmp));
                    std::wstring deviceName = deviceTmp;

                    if (devicePath.find(deviceName) == 0)
                    {
                        drive[drive.length() - 1] = L'\\';
                        dosPath = drive + devicePath.substr(deviceName.length() + 1);
                        break;
                    }
                }
            } while (FALSE);
            return dosPath;
        }

        std::wstring dosPath_2_devicePath(std::wstring dosPath)
        {
            std::wstring devicePath;
            return devicePath;
        }

        std::wstring dosPath_2_NtPath(std::wstring dosPath)
        {
            std::wstring NtPath;
            NtPath = L"\\??\\" + dosPath;
            return NtPath;
        }

        std::wstring NtPath_2_dosPath(std::wstring NtPath)
        {
            std::wstring dosPath;
            dosPath = NtPath.substr(std::wstring(L"\\??\\").length());
            return dosPath;
        }

    }
};