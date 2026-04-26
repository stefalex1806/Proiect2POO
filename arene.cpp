#include "arene.hpp"
#include "exceptii.hpp"

int Arena::nr_arene = 0;

Arena::Arena(std::string n, int niv) : nume(n), nivel(niv) {
    if (n == "") throw EroareArena("Arena trebuie sa aiba un nume!");
    if (niv > 3 || niv < 1) throw EroareArena("Nivelul trebuie sa fie intre 1 si 3!");
    nr_arene++;
}

Arena::Arena(const Arena& other) : nume(other.nume), nivel(other.nivel) { nr_arene++; }

Arena::~Arena() { nr_arene--; }

void swap(Arena& first, Arena& second) noexcept {
    std::swap(first.nume, second.nume);
    std::swap(first.nivel, second.nivel);
}

Arena& Arena::operator=(const Arena& other) {
    if (this != &other) {
        nume = other.nume;
        nivel = other.nivel;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Arena& a) {
    a.afisare(os);
    return os;
}

// === ARENA MAG ===
ArenaMag::ArenaMag(std::string n, int niv, int av) : Arena(n, niv), avantaj(av) {
    if (av > 5 || av < 0) throw EroareArena("Avantajul trebuie sa fie intre 0 si 5!");
}
ArenaMag::ArenaMag(const ArenaMag& other) : Arena(other), avantaj(other.avantaj) {}
void swap(ArenaMag& first, ArenaMag& second) noexcept {
    swap(static_cast<Arena&>(first), static_cast<Arena&>(second));
    std::swap(first.avantaj, second.avantaj);
}
ArenaMag& ArenaMag::operator=(ArenaMag other) { swap(*this, other); return *this; }
int ArenaMag::get_avantaj_total() const { return nivel * 5 + avantaj * 3; }
void ArenaMag::afisare_impl(std::ostream& os) const {
    os << nume << " (Nivel: " << nivel << ", Avantaj Mag: " << avantaj << ") - Clasa benefica: Mag";
}

// === ARENA EROU ===
ArenaErou::ArenaErou(std::string n, int niv, int av) : Arena(n, niv), avantaj(av) {
    if (av > 5 || av < 0) throw EroareArena("Avantajul trebuie sa fie intre 0 si 5!");
}
ArenaErou::ArenaErou(const ArenaErou& other) : Arena(other), avantaj(other.avantaj) {}
void swap(ArenaErou& first, ArenaErou& second) noexcept {
    swap(static_cast<Arena&>(first), static_cast<Arena&>(second));
    std::swap(first.avantaj, second.avantaj);
}
ArenaErou& ArenaErou::operator=(ArenaErou other) { swap(*this, other); return *this; }
int ArenaErou::get_avantaj_total() const { return nivel * 5 + avantaj * 2; }
void ArenaErou::afisare_impl(std::ostream& os) const {
    os << nume << " (Nivel: " << nivel << ", Avantaj Erou: " << avantaj << ") - Clasa benefica: Erou";
}

// === ARENA GOBLIN ===
ArenaGoblin::ArenaGoblin(std::string n, int niv, int av) : Arena(n, niv), avantaj(av) {
    if (av > 5 || av < 0) throw EroareArena("Avantajul trebuie sa fie intre 0 si 5!");
}
ArenaGoblin::ArenaGoblin(const ArenaGoblin& other) : Arena(other), avantaj(other.avantaj) {}
void swap(ArenaGoblin& first, ArenaGoblin& second) noexcept {
    swap(static_cast<Arena&>(first), static_cast<Arena&>(second));
    std::swap(first.avantaj, second.avantaj);
}
ArenaGoblin& ArenaGoblin::operator=(ArenaGoblin other) { swap(*this, other); return *this; }
int ArenaGoblin::get_avantaj_total() const { return nivel * 5 + avantaj * 4; }
void ArenaGoblin::afisare_impl(std::ostream& os) const {
    os << nume << " (Nivel: " << nivel << ", Avantaj Goblin: " << avantaj << ") - Clasa benefica: Goblin";
}