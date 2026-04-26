#pragma once
#include <iostream>
#include <string>

class Arena {
protected:
    std::string nume;
    int nivel;
    static int nr_arene;

    // Funcție virtuală pură pentru NVI (Non-Virtual Interface)
    virtual void afisare_impl(std::ostream& os) const = 0; 

public:
    Arena(std::string nume = "Arena Neutra", int nivel = 1);
    Arena(const Arena& other);
    virtual ~Arena();

    friend void swap(Arena& first, Arena& second) noexcept;
    Arena& operator=(const Arena& other);

    // Interfața NVI
    void afisare(std::ostream& os) const { afisare_impl(os); }
    
    // Funcție virtuală pură (face clasa abstractă)
    virtual int get_avantaj_total() const = 0; 

    // Operator supraîncărcat <<
    friend std::ostream& operator<<(std::ostream& os, const Arena& a);

    static int get_nr_arene() { return nr_arene; }
};

class ArenaMag : public Arena {
    int avantaj;
    void afisare_impl(std::ostream& os) const override;
public:
    ArenaMag(std::string nume = "Arena Mag Oarecare", int nivel = 1, int avantaj = 1);
    ArenaMag(const ArenaMag& other);
    friend void swap(ArenaMag& first, ArenaMag& second) noexcept;
    ArenaMag& operator=(ArenaMag other);

    int get_avantaj_total() const override;
};

class ArenaErou : public Arena {
    int avantaj;
    void afisare_impl(std::ostream& os) const override;
public:
    ArenaErou(std::string nume = "Arena Eroilor Standard", int nivel = 1, int avantaj = 1);
    ArenaErou(const ArenaErou& other);
    friend void swap(ArenaErou& first, ArenaErou& second) noexcept;
    ArenaErou& operator=(ArenaErou other);

    int get_avantaj_total() const override;
};

class ArenaGoblin : public Arena {
    int avantaj;
    void afisare_impl(std::ostream& os) const override;
public:
    ArenaGoblin(std::string nume = "Barlogul Goblinilor", int nivel = 1, int avantaj = 1);
    ArenaGoblin(const ArenaGoblin& other);
    friend void swap(ArenaGoblin& first, ArenaGoblin& second) noexcept;
    ArenaGoblin& operator=(ArenaGoblin other);

    int get_avantaj_total() const override;
};
