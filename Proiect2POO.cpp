#include <iostream>
#include <vector>
#include "exceptii.hpp"
#include "lupte.hpp"

int main() {
    std::cout << "--- Testare Exceptii ---\n";
    try {
        ArenaMag* arena_eroare = new ArenaMag("Arena Invalida", 5, 1);
    } catch (const EroareJoc& e) {
        std::cout << "Capturat: " << e.what() << "\n";
    }

    try {
        Goblin g_defect("Stinky", -10, 5, "Bata");
    } catch (const EroareJoc& e) {
        std::cout << "Capturat: " << e.what() << "\n";
    }

    std::cout << "\n--- Creare Personaje si Arene ---\n";

    Mag* m1 = new Mag("Gandalf", 120, 15, "Bagheta de Soc");
    Erou* e1 = new Erou("Arthur", 150, 10, "Excalibur");
    Goblin* g1 = new Goblin("Riz", 90, 18, "Sulita Ruginita");
    Mag* m2 = new Mag("Saruman");

    ArenaMag* arena_m = new ArenaMag("Turnul de Foc", 3, 5);
    ArenaErou* arena_e = new ArenaErou("Templul Eroilor", 2, 4);
    ArenaGoblin* arena_g = new ArenaGoblin("Mlastina", 1, 3);

    std::cout << "Total personaje in memorie: " << Personaj::get_nr_personaje() << "\n";
    std::cout << "Total arene in memorie: " << Arena::get_nr_arene() << "\n";

    std::cout << "\n--- Testare Copiere si Operator << ---\n";
    Mag m_copie = *m1; 
    std::cout << "Copie creata: \n" << m_copie << "\n";

    ArenaMag arena_atribuita;
    arena_atribuita = *arena_m; 
    std::cout << "Arena atribuita: \n" << arena_atribuita << "\n";

    std::cout << "\n--- SCENARIUL 1: Mag vs Erou (In Arena Magica) ---\n";
    Lupta runda1(m1, e1, arena_m);
    runda1.desfasurare();

    std::cout << "\n--- SCENARIUL 2: Erou vs Goblin (In Arena Eroilor) ---\n";
    Lupta runda2(e1, g1, arena_e);
    runda2.desfasurare();

    std::cout << "\n--- SCENARIUL 3: Goblin vs Mag (In Arena Goblinilor) ---\n";
    Lupta runda3(g1, m2, arena_g); 
    runda3.desfasurare();

    std::cout << "\n--- Final Program ---\n";
    delete m1; delete e1; delete g1; delete m2;
    delete arena_m; delete arena_e; delete arena_g;

    std::cout << "Personaje ramase: " << Personaj::get_nr_personaje() << "\n";
    std::cout << "Arene ramase: " << Arena::get_nr_arene() << "\n";

    return 0;
}