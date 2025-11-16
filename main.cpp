#include "draha.h"
#include <thread>
#include <iostream>

int main()
{
    // Run animation on separate thread so main can continue or wait.
    
    std::thread anim(bwl_koule, -1); // -1 = nekonecno
    std::cout << "Press Enter to stop...\n";
    std::cin.get();
    std::cout << "Vystrel\n";

    anim.detach();
    vypisDrahu();
    return 0;
}
