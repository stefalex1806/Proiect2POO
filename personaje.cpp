#include "personaje.hpp"
#include "exceptii.hpp"

int Personaj::nr_personaje = 0;

Personaj::Personaj(std::string n, int v, int d) : nume(n), viata(v), damage(d) {
    if (v <= 0) throw EroareCrearePersonaj("Viata nu poate fi zero sau negativa!");
    if (d < 0) throw EroareCrearePersonaj("Damage-ul nu poate fi negativ!");
    if (n == "") throw EroareCrearePersonaj("Personajul trebuie sa aiba un nume!");
    nr_personaje++;
}

Personaj::Personaj(const Personaj& other) : nume(other.nume), viata(other.viata), damage(other.damage) {
    nr_personaje++;
}

Personaj::~Personaj() { nr_personaje--; }

void swap(Personaj& first, Personaj& second) noexcept {
    std::swap(first.nume, second.nume);
    std::swap(first.viata, second.viata);
    std::swap(first.damage, second.damage);
}

Personaj& Personaj::operator=(const Personaj& other) {
    if (this != &other) {
        nume = other.nume;
        viata = other.viata;
        damage = other.damage;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Personaj& p) {
    p.afisare(os);
    return os;
}

// === MAG ===
Mag::Mag(std::string n, int v, int d, std::string b) : Personaj(n, v, d), bagheta(b) {}
Mag::Mag(const Mag& other) : Personaj(other), bagheta(other.bagheta) {}
void swap(Mag& first, Mag& second) noexcept {
    swap(static_cast<Personaj&>(first), static_cast<Personaj&>(second));
    std::swap(first.bagheta, second.bagheta);
}
Mag& Mag::operator=(Mag other) { swap(*this, other); return *this; }
void Mag::afisare_impl(std::ostream& os) const {
    os << "[Mag] " << nume << " | Viata: " << viata << " | DMG: " << damage << " | Arma: " << bagheta;
}

// === EROU ===
Erou::Erou(std::string n, int v, int d, std::string s) : Personaj(n, v, d), sabie(s) {}
Erou::Erou(const Erou& other) : Personaj(other), sabie(other.sabie) {}
void swap(Erou& first, Erou& second) noexcept {
    swap(static_cast<Personaj&>(first), static_cast<Personaj&>(second));
    std::swap(first.sabie, second.sabie);
}
Erou& Erou::operator=(Erou other) { swap(*this, other); return *this; }
void Erou::afisare_impl(std::ostream& os) const {
    os << "[Erou] " << nume << " | Viata: " << viata << " | DMG: " << damage << " | Arma: " << sabie;
}

// === GOBLIN ===
Goblin::Goblin(std::string n, int v, int d, std::string s) : Personaj(n, v, d), sulita(s) {}
Goblin::Goblin(const Goblin& other) : Personaj(other), sulita(other.sulita) {}
void swap(Goblin& first, Goblin& second) noexcept {
    swap(static_cast<Personaj&>(first), static_cast<Personaj&>(second));
    std::swap(first.sulita, second.sulita);
}
Goblin& Goblin::operator=(Goblin other) { swap(*this, other); return *this; }
void Goblin::afisare_impl(std::ostream& os) const {
    os << "[Goblin] " << nume << " | Viata: " << viata << " | DMG: " << damage << " | Arma: " << sulita;
}