#pragma once
#include <exception>
#include <string>

class EroareJoc : public std::exception {
protected:
    std::string mesaj;
public:
    EroareJoc(const std::string& msg) : mesaj(msg) {}
    virtual ~EroareJoc() noexcept {}
    const char* what() const noexcept override { return mesaj.c_str(); }
};

class EroareCrearePersonaj : public EroareJoc {
public:
    EroareCrearePersonaj(const std::string& d) : EroareJoc("Eroare fatala la personaj: " + d) {}
};

class EroareArena : public EroareJoc {
public:
    EroareArena(const std::string& d) : EroareJoc("Eroare in arena: " + d) {}
};