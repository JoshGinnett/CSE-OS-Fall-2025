#include <iostream>
#include "MemoryManager.h"

int main() {
    MemoryManager mm;

    int virtualAddress = mm.allocateAnyPage();

    mm.writeVirtualMemory(virtualAddress, static_cast<uint8_t>(69));

    std::cout << std::flush;

    std::cout << std::showbase << std::hex;

    mm.printPageTableEntry(virtualAddress / 4096);

    std::cout << std::dec;

    std::cout << static_cast<int>(mm.readVirtualMemory(virtualAddress)) << std::endl;

    return 0;
}
