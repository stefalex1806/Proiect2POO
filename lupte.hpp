#pragma once
#include "arene.hpp"
#include "personaje.hpp"

class Lupta {
    Personaj *p1, *p2;
    Arena* locatie;

public:
    Lupta(Personaj *p1, Personaj *p2, Arena* locatie) : p1(p1), p2(p2), locatie(locatie) {}

    void desfasurare() {
        std::cout << "\n------Inceput De Lupta------\nLOCATIE: " << *locatie << "\n";
        std::cout << "\nPrimul Competitor: " << *p1;
        std::cout << "\nAl Doilea Competitor: " << *p2 << "\n\n";

        // Preia puterea direct prin functia High-Level
        int putere_p1 = p1->get_putere_baza();
        int putere_p2 = p2->get_putere_baza();
        
        int clasa_p1 = p1->get_id_clasa(); // 1=Mag, 2=Erou, 3=Goblin
        int clasa_p2 = p2->get_id_clasa();

        int avantaj = locatie->get_avantaj_total();

        // Downcast cu sens (Cerinta 2.e.2) pentru a verifica tipul arenei
        if (dynamic_cast<ArenaMag*>(locatie)) {
            if (clasa_p1 == 1) { putere_p1 = (putere_p1 * (100 + avantaj)) / 100; std::cout << "P1(Mag) ia bonus arena!\n"; }
            else if (clasa_p1 == 2) { putere_p1 = (putere_p1 * (100 - avantaj)) / 100; std::cout << "P1(Erou) ia penalizare arena!\n"; }
            
            if (clasa_p2 == 1) { putere_p2 = (putere_p2 * (100 + avantaj)) / 100; std::cout << "P2(Mag) ia bonus arena!\n"; }
            else if (clasa_p2 == 2) { putere_p2 = (putere_p2 * (100 - avantaj)) / 100; std::cout << "P2(Erou) ia penalizare arena!\n"; }
        }
        else if (dynamic_cast<ArenaErou*>(locatie)) {
            if (clasa_p1 == 2) { putere_p1 = (putere_p1 * (100 + avantaj)) / 100; std::cout << "P1(Erou) ia bonus arena!\n"; }
            else if (clasa_p1 == 3) { putere_p1 = (putere_p1 * (100 - avantaj)) / 100; std::cout << "P1(Goblin) ia penalizare arena!\n"; }
            
            if (clasa_p2 == 2) { putere_p2 = (putere_p2 * (100 + avantaj)) / 100; std::cout << "P2(Erou) ia bonus arena!\n"; }
            else if (clasa_p2 == 3) { putere_p2 = (putere_p2 * (100 - avantaj)) / 100; std::cout << "P2(Goblin) ia penalizare arena!\n"; }
        }
        else if (dynamic_cast<ArenaGoblin*>(locatie)) {
            if (clasa_p1 == 3) { putere_p1 = (putere_p1 * (100 + avantaj)) / 100; std::cout << "P1(Goblin) ia bonus arena!\n"; }
            else if (clasa_p1 == 1) { putere_p1 = (putere_p1 * (100 - avantaj)) / 100; std::cout << "P1(Mag) ia penalizare arena!\n"; }
            
            if (clasa_p2 == 3) { putere_p2 = (putere_p2 * (100 + avantaj)) / 100; std::cout << "P2(Goblin) ia bonus arena!\n"; }
            else if (clasa_p2 == 1) { putere_p2 = (putere_p2 * (100 - avantaj)) / 100; std::cout << "P2(Mag) ia penalizare arena!\n"; }
        }

        // Avantaj de clasa: Mag(1) > Erou(2) > Goblin(3) > Mag(1)
        if ((clasa_p1 == 1 && clasa_p2 == 2) || (clasa_p1 == 2 && clasa_p2 == 3) || (clasa_p1 == 3 && clasa_p2 == 1)) {
            std::cout << "Primul Competitor are avantaj de clasa (+10%)!\n";
            putere_p1 = (putere_p1 * 110) / 100;
        }
        else if ((clasa_p2 == 1 && clasa_p1 == 2) || (clasa_p2 == 2 && clasa_p1 == 3) || (clasa_p2 == 3 && clasa_p1 == 1)) {
            std::cout << "Al Doilea Competitor are avantaj de clasa (+10%)!\n";
            putere_p2 = (putere_p2 * 110) / 100;
        }

        std::cout << "Putere Finala P1: " << putere_p1 << "\n";
        std::cout << "Putere Finala P2: " << putere_p2 << "\n";

        if (putere_p1 > putere_p2) {
            std::cout << ((putere_p1 - putere_p2 > 150) ? "Lupta usoara pentru primul!\n" : "Dupa o lupta crunta a castigat primul.\n");
        } else if (putere_p2 > putere_p1) {
            std::cout << ((putere_p2 - putere_p1 > 150) ? "Lupta usoara pentru al doilea!\n" : "Dupa o lupta crunta a castigat al doilea.\n");
        } else {
            std::cout << "EGALITATE!\n";
        }
    }
};