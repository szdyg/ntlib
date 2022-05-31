#pragma once
#include <string>

namespace ntlibr3
{
    namespace path 
    {
        // L"\\Device\\HarddiskVolume1\\Test.exe" -> L"E:\\Test.exe"
        std::wstring devicePath_2_dosPath(std::wstring devicePath);
        // L"E:\\Test.exe" -> L"\\Device\\HarddiskVolume1\\Test.exe"
        std::wstring dosPath_2_devicePath(std::wstring  dosPath);

        // L"E:\\Test.exe" -> L"\\??\\E:\\Test.exe"
        std::wstring dosPath_2_NtPath(std::wstring  dosPath);
        // L"\\??\\E:\\Test.exe" -> L"E:\\Test.exe"
        std::wstring NtPath_2_dosPath(std::wstring  NtPath);

    }

};

