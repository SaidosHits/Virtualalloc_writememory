#include <iostream>
#include <Windows.h>

using namespace std;

int main() {

    //LPVOID VirtualAlloc(
    //	[in, optional] LPVOID lpAddress,
    //	[in]           SIZE_T dwSize,
    //	[in]           DWORD  flAllocationType,
    //	[in]           DWORD  flProtect
    //);

    SIZE_T size = 10;
    LPVOID address = (void*)0x0000017FAFD50000;

    // Pass 'address' instead of NULL to allocate at that specific location
    LPVOID freememory = VirtualAlloc(address, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    if (freememory == NULL) {
        cout << "Error : " << GetLastError() << endl;
        cout << "Could not allocate at address " << address << endl;
    }
    else {
        cout << "Memory successfully allocated at: " << freememory << endl;

        // You can now use this memory
        // Example: Write some data
        char* data = (char*)freememory;
        strcpy_s(data, size, "Hello from allocated memory!");
        cout << "Data written: " << data << endl;
    }

    // Don't forget to free the memory!
    if (freememory != NULL) {
        VirtualFree(freememory, 0, MEM_RELEASE);
        cout << "Memory freed successfully" << endl;
    }
    cin.get();

    return 0;
}