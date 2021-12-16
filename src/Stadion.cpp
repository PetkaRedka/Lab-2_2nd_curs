#include "Stadion.h"

void Stadion:: Save()
{
     ofstream outstrm ("c:/binfiles/oonumber1.bin", std::ios::binary);
     if(outstrm.is_open())
     {
         outstrm.write((char*)&year, sizeof(int));
         outstrm.write((char*)&places, sizeof(int));
         outstrm.write((char*)&arenas, sizeof(int));
         outstrm.close();
     }
}

void Stadion:: Load()
{
    {   ifstream instrm ("c:/binfiles/oonumber1.bin", std::ios::binary);
        int a = 0;
        while(instrm.read((char *)&a, sizeof(int)))
            cout << a << ' ';
        cout << '\n';
        instrm.close();
    }
}

Stadion:: Stadion()
{
    places = 0;
    arenas = 0;
    year = 0;
};

Stadion:: Stadion(const Stadion &lst){};

ostream& operator<<(ostream& os, const Stadion& temp)
{
     os << "Stadion's name " << temp.name << " " <<"\n" << "Kind of Sport: " << temp.sport << " " << "\n" << "Year of foundation: "<< temp.year << " " << "\n" << "Amount of places :" <<temp.places << " " << "\n"<< "Amount of arenas :"<< temp.arenas << " " << "\n"<< "\n";
     cout << "\n";
     return os;
}
istream& operator<<(istream& is,  Stadion& temp)
{
     cout << "Name: ";
     is >> temp.name;
     cout << "Sport: ";
     is >> temp.sport;
     cout << "Year: ";
     is >> temp.year;
     cout << "Places: ";
     is >> temp.places;
     cout << "Arenas: ";
     is >> temp.arenas;
     return is;
}
