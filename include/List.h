#ifndef LIST_H
#define LIST_H
#include "Stadion.h"

class List
{
     Stadion *Head, *Tail;
   public:
int count_ ;
     List();
     ~List();
     List(const List &lst);
     void Show();
     void Add(string name, string sport , int year, int places, int arenas);
     void Show_1(int x);
     void Add_1(string name, string sport , int year, int places, int arenas, int x);
     void Delete(int x);
     void Order();
     void Filter(string choos);
     void File();
     void operator[] (int x)
     {
            Stadion *temp= Head;
            if ((x<= 0) || (x>count_))
                {cout << "Wrong number!" <<"\n" << endl;}
            else
                {
                    for (int i = 1; i<x; i++)
                           temp = temp->Next;
                         cout << "Stadion's name " << temp->name << " " <<"\n";
                         cout << "Kind of Sport: " << temp->sport << " " << "\n";
                         cout << "Year of foundation: "<< temp->year << " " << "\n";
                         cout << "Amount of places :" <<temp->places << " " << "\n";
                         cout << "Amount of arenas :"<< temp->arenas << " " << "\n";
                         cout << "\n";
                         cout << "\n";
                }
     }
     friend ostream& operator<<(ostream& os, const List& lst);
     friend istream& operator>>(istream& is, List& lst);
     friend bool operator == (Stadion a, Stadion b);
     friend bool operator > (Stadion a, Stadion b);
     friend bool operator < (Stadion a, Stadion b);
     List& operator= (const List &lst)
     {
         count_ = lst.count_;
         return *this;
     }
};

#endif // LIST_H
