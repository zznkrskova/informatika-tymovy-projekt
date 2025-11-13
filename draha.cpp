#include "draha.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <string>
#include <functional>

// zde definovat funkce/třídy/struktury potřebné pro vypsání dráhy
// přidat potřebné knihovny pomocí #include

void clearConsole()
{
#if defined(_WIN32) || defined(_WIN64)
    ::system("cls");
#else
    std::cout << "\033[2J\033[H" << std::flush;
#endif
}

void bwl_koule(int iterations)
{
    int prubeh = 0;
    int count = 0;

    while (iterations < 0 || count < iterations)
    {
        clearConsole();

        int pos; // určí kolik mezer bude před "0"

        if (prubeh <= 1) pos = 0;
        else if (prubeh <= 3) pos = 2;
        else if (prubeh <= 5) pos = 4;
        else if (prubeh <= 8) pos = 6;
        else if (prubeh <= 10) pos = 8;
        else if (prubeh <= 12) pos = 10;
        else pos = 12;

        std::cout << std::string(pos, ' ') << "0" << std::endl;

        std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(75));

        prubeh = (prubeh + 1) % 15;
        ++count;
    }
}
