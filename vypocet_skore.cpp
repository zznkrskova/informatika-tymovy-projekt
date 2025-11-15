#include <vector>
#include <iostream>
#include "vypocet_skore.h"

int vypocetSkore(const std::vector<int>& hody) {
    int celkoveSkore = 0;
    int frame = 0;
    int pocetHodu = 0;

    auto bonusZaStrike = [&]() {
        if (pocetHodu + 2 < hody.size()) {
            return hody[pocetHodu + 1] + hody[pocetHodu + 2];
        }
        if (pocetHodu + 1 < hody.size()) {
            return hody[pocetHodu + 1];
        }
        return 0;
    };

    auto bonusZaSpare = [&](){
        if (pocetHodu + 2 < hody.size()) {
            return hody[pocetHodu + 2];
        }
        return 0;
    };

    while (frame < 10 && pocetHodu < hody.size()) {
        if (hody[pocetHodu] == 10) {
            celkoveSkore= celkoveSkore + 10 + bonusZaStrike();
            pocetHodu += 1;
        }
        else if (pocetHodu + 1 < hody.size()) { 
            int soucet_framu = hody[pocetHodu] + hody[pocetHodu + 1];

            if (soucet_framu == 10) {
                celkoveSkore = celkoveSkore + 10 + bonusZaSpare();
                pocetHodu += 2;
            }
            else {
                celkoveSkore += hody[pocetHodu];
                pocetHodu += 2;
            }
        }
        else {
            celkoveSkore = celkoveSkore + hody[pocetHodu];
            pocetHodu += 1;
        }
        frame++;
    }
    return celkoveSkore;
}