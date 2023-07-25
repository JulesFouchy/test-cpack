#include <ShlObj.h> // Make sure to include the Windows Shell header
#include <iostream>


std::wstring GetRoamingAppDataPath()
{
    PWSTR path = nullptr;

    // Use the KNOWNFOLDERID for Roaming AppData folder
    HRESULT result = SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &path);

    if (SUCCEEDED(result))
    {
        // Convert the PWSTR to a std::wstring
        std::wstring appDataPath(path);

        // Free the memory allocated by SHGetKnownFolderPath
        CoTaskMemFree(static_cast<void*>(path));

        return appDataPath;
    }
    else
    {
        // Handle the error, e.g., return an empty string or throw an exception
        // For this example, we'll just return an empty string
        return L"";
    }
}

int main()
{
    std::wstring appDataPath = GetRoamingAppDataPath();

    if (!appDataPath.empty())
    {
        std::wcout << L"Roaming AppData Path: " << appDataPath << std::endl;
    }
    else
    {
        std::wcerr << L"Failed to get Roaming AppData Path." << std::endl;
    }

    return 0;
}
