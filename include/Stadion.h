#ifndef STADION_H
#define STADION_H
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Stadion
{
public:
    string name, sport;
    int year, places, arenas, bukva;
    Stadion();
    Stadion(const Stadion &st);
    Stadion *Next, *Prev;
    friend ostream& operator<<(ostream& os, const Stadion& temp);
    friend istream& operator>>(istream& is, Stadion& temp);
    void Save();
    void Load();
    Stadion& operator=(const Stadion &drob)
    {
        places = drob.places;
        arenas = drob.arenas;
        year = drob.year;

        return *this;
    }
};

#endif // STADION_H
