#include <windows.h>
#include <iostream>
#include <string>

class CL_MMAP_LOGGER
{
private:
    HANDLE hFile;
    HANDLE hMapping;
    char *map;
    size_t offset;
    const size_t FILE_SIZE = 1024 * 100; // 100MB log file

public:
    CL_MMAP_LOGGER(const char *filename) : offset(0)
    {
        // Open or create the log file
        hFile = CreateFileA(
            filename, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile == INVALID_HANDLE_VALUE)
        {
            std::cerr << "Failed to open file\n";
            return;
        }

        // Create a file mapping object
        hMapping = CreateFileMappingA(hFile, NULL, PAGE_READWRITE, 0, FILE_SIZE, NULL);
        if (!hMapping)
        {
            std::cerr << "Failed to create file mapping\n";
            CloseHandle(hFile);
            return;
        }

        // Map the file into memory
        map = static_cast<char *>(MapViewOfFile(hMapping, FILE_MAP_WRITE, 0, 0, FILE_SIZE));
        if (!map)
        {
            std::cerr << "Failed to map file\n";
            CloseHandle(hMapping);
            CloseHandle(hFile);
            return;
        }
    }

    ~CL_MMAP_LOGGER()
    {
        if (map)
        {
            FlushViewOfFile(map, FILE_SIZE); // Ensure data is written to disk
            UnmapViewOfFile(map);
        }
        if (hMapping)
            CloseHandle(hMapping);
        if (hFile)
            CloseHandle(hFile);
    }

    void log(const std::string &message)
    {
        size_t len = message.size();
        if (offset + len >= FILE_SIZE)
            return; // Prevent overflow
        memcpy(map + offset, message.c_str(), len);
        offset += len;
        map[offset++] = '\n';
    }
};

// Usage Example
int main()
{
    CL_MMAP_LOGGER logger("mmap_log.txt");

    for (int i = 0; i < 10000; ++i)
    {
        logger.log("Log Message " + std::to_string(i));
        Sleep(1000);
    }

    getchar();

    return 0;
}
