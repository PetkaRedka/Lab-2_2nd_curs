#include "List.h"

 bool operator == (Stadion a, Stadion b)
 {
     if (b == a)
        return true;
     return false;
 }

bool operator > (Stadion a, Stadion b)
{
    if (a > b)
        return true;
    return false;
}

bool operator < (Stadion a, Stadion b)
{
    if (a < b)
        return true;
    return false;
}

ostream& operator<<(ostream& os, const List& lst)
{
       Stadion *temp=lst.Tail;
       temp = lst.Head;
      while (temp != NULL)
     {
         os << "Stadion's name " << temp->name << " " <<"\n" << "Kind of Sport: " << temp->sport << " " << "\n" << "Year of foundation: "<< temp->year << " " << "\n" << "Amount of places :" <<temp->places << " " << "\n"<< "Amount of arenas :"<< temp->arenas << " " << "\n"<< "\n";
         temp = temp->Next;
     }
     cout << "\n";
     return os;
}

istream& operator>>(istream& is, List& lst)
{
    string name, sport, adress;
     {
         while (in >> name >> sport >>year >> places >>arenas)
         {
             lst.Add(name,sport,year,places,arenas);
         }
     }
     else{cout << "Could not open file..";}
     return is;
}

 List::List():Head(NULL),Tail(NULL){ count_ = 0; };

 List::List(const List &lst): count_(lst.count_)
 {
    cout << "Copy constructor worked here!\n\n";
 }

void List::Delete(int x)
{
        if (x>count_)
        {
            cout << "Wrong number!"<< endl;
        }
       else if ((x == 1) and (Head->Next))
            {
                Stadion *temp = Head;
                Head = Head->Next;
                Head->Prev = NULL;
                delete temp;
                count_--;
                return ;
            }
        else if ((x == 1) and (Head == Tail))
            {

                Head->Next = NULL;
                Head = NULL;
                delete Head;
                count_ = 0;
                return;
            }
        else if (x==count_)
            {
                Stadion *temp = Tail;
                Tail = Tail->Prev;
                Tail->Next = NULL;
                delete temp;
                count_--;
                return;
            }
        else
            {
                Stadion *temp = Head, *temp2;
                for (int i=0; i<(x-1); i++)
                        temp = temp->Next;
                temp2 = temp;
                temp2->Prev->Next =   temp->Next;
                temp2->Next->Prev = temp->Prev;
                count_--;
                delete temp;
            }

}

void List::Add_1(string name, string sport , int year, int places, int arenas, int x)
 {
    Stadion *temp = new Stadion;
    Stadion *temp2 =Head;
    temp->year = year;
    temp->places = places;
    temp->arenas = arenas;
    temp->name = name;
    temp->sport = sport;

    if ((x == 1) and (count_>0))
        {
            Head->Prev = temp;
            temp->Next = Head;
            Head = temp;
        }
    else if((x == 1) && (Head == NULL))
        {
            temp->Next = NULL;
            temp->Prev = NULL;
            Head = Tail = temp;
        }
    else if (x>count_)
        {
            temp->Next = NULL;
            temp->Prev = Tail;
            Tail->Next = temp;
            Tail = temp;
        }
    else
        {
           for (int i=0; i<(x-1); i++)
                        temp2 = temp2->Next;
            temp2->Prev->Next =  temp;
            temp->Next = temp2;
            temp2->Prev = temp;
         }
    count_++;
 }


 List::~List()
 {
     while (Head)
     {
         Tail = Head->Next;
         delete Head;
         Head = Tail;
     }
 }

void List::Add(string name, string sport , int year, int places, int arenas)
 {
   Stadion *temp = new Stadion;
   temp->Next = NULL;
   temp->year = year;
   temp->places = places;
   temp->arenas = arenas;
   temp->name = name;
   temp->sport = sport;

   if (Head != NULL)
   {
       temp->Prev = Tail;
       Tail->Next = temp;
       Tail = temp;
   }
   else
   {
       temp->Prev = NULL;
       Head = Tail = temp;
   }
   count_++;
   temp->bukva = temp->name[0] - '0';
 }

void List::Order()
 {
   Stadion *temp = new Stadion;

   for (int i =0; i<count_; i++)
        {
                Stadion *reserv = Head;
                Stadion *reserv1 = Head;
                reserv1 = reserv1->Next;
            for (int j = 0; j <count_-i-1;j++)
               {

                   if((reserv->bukva)>(reserv1->bukva))
                   {
                       temp->year = reserv->year;
                       temp->places = reserv->places;
                       temp->arenas = reserv->arenas;
                       temp->name = reserv->name;
                       temp->sport = reserv->sport;

                       reserv->year = reserv1-> year;
                       reserv->places = reserv1->places;
                       reserv->arenas = reserv1->arenas;
                       reserv->name = reserv1->name;
                       reserv->sport = reserv1->sport;

                       reserv1->year = temp-> year;
                       reserv1->places = temp-> places;
                       reserv1->arenas = temp->arenas;
                       reserv1->name = temp->name;
                       reserv1->sport = temp->sport;
                   }
                   reserv1 = reserv1->Next;
                   reserv = reserv->Next;
               }
        }
 }

void List::Filter(string choos)
 {

    if (choos == "name")
    {
        string sgna;
        cout << "Select a word with which to compare: ";
        cin >> sgna;
        List znd;
        Stadion *temp = Head;
        for (int i= 1; i<=count_; i++)
        {
            if (sgna ==(temp->name))
            {
                znd.Add(temp->name, temp->sport, temp->year, temp->places, temp->arenas);
            }
            temp = temp->Next;
        }
        cout <<znd;
    }
    else if (choos == "sport")
    {
        string sgna;
        cout << "Select a word with which to compare: ";
        cin >> sgna;
        List znd;
        Stadion *temp = Head;
        for (int i= 1; i<=count_; i++)
        {
            if (sgna ==(temp->sport))
            {
                znd.Add(temp->name, temp->sport, temp->year, temp->places, temp->arenas);
            }
            temp = temp->Next;
        }
        cout << znd;
    }
    else if (choos == "year")
    {
        char sgna;
        int x;
        cout << "Select a number with which you will compare: ";
        cin >> x;
        cout << "Now, comparison mark (<,>,=): ";
        cin >> sgna;
        if (sgna == '=')
        {
            List znd;
            Stadion *temp = Head;
            for (int i= 1; i<=count_; i++)
            {
                if (x ==(temp->year))
                {
                    znd.Add(temp->name, temp->sport, temp->year, temp->places, temp->arenas);
                }
                temp = temp->Next;
            }
            cout << znd;
        }
        else if (sgna == '<')
        {
            List znd;
            Stadion *temp = Head;
            for (int i= 1; i<=count_; i++)
            {
                if (x >(temp->year))
                {
                    znd.Add(temp->name, temp->sport, temp->year, temp->places, temp->arenas);
                }
                temp = temp->Next;
            }
            cout << znd;
        }
        else if (sgna == '>')
        {
            List znd;
            Stadion *temp = Head;
            for (int i= 1; i<=count_; i++)
            {
                if (x <(temp->year))
                {
                    znd.Add(temp->name, temp->sport, temp->year, temp->places, temp->arenas);
                }
                temp = temp->Next;
            }
            cout << znd;
        }
    }
    else if (choos == "places")
    {
        char sgna;
        int x;
        cout << "Select a number with which you will compare: ";
        cin >> x;
        cout << "Now, comparison mark (<,>,=): ";
        cin >> sgna;
        if (sgna == '=')
        {
            List znd;
            Stadion *temp = Head;
            for (int i= 1; i<=count_; i++)
            {
                if (x ==(temp->places))
                {
                    znd.Add(temp->name, temp->sport, temp->year, temp->places, temp->arenas);
                }
                temp = temp->Next;
            }
            cout << znd;
        }
        else if (sgna == '<')
        {
            List znd;
            Stadion *temp = Head;
            for (int i= 1; i<=count_; i++)
            {
                if (x >(temp->places))
                {
                    znd.Add(temp->name, temp->sport, temp->year, temp->places, temp->arenas);
                }
                temp = temp->Next;
            }
            cout << znd;
        }
        else if (sgna == '>')
        {
            List znd;
            Stadion *temp = Head;
            for (int i= 1; i<=count_; i++)
            {
                if (x <(temp->places))
                {
                    znd.Add(temp->name, temp->sport, temp->year, temp->places, temp->arenas);
                }
                temp = temp->Next;
            }
            cout << znd;
        }
    }
    else if (choos == "arenas")
    {
        char sgna;
        int x;
        cout << "Select a number with which you will compare: ";
        cin >> x;
        cout << "Now, comparison mark (<,>,=): ";
        cin >> sgna;
        if (sgna == '=')
        {
            List znd;
            Stadion *temp = Head;
            for (int i= 1; i<=count_; i++)
            {
                if (x ==(temp->arenas))
                {
                    znd.Add(temp->name, temp->sport, temp->year, temp->places, temp->arenas);
                }
                temp = temp->Next;
            }
            cout << znd;
        }
        else if (sgna == '<')
        {
            List znd;
            Stadion *temp = Head;
            for (int i= 1; i<=count_; i++)
            {
                if (x >(temp->arenas))
                {
                    znd.Add(temp->name, temp->sport, temp->year, temp->places, temp->arenas);
                }
                temp = temp->Next;
            }
            cout << znd;
        }
        else if (sgna == '>')
        {
            List znd;
            Stadion *temp = Head;
            for (int i= 1; i<=count_; i++)
            {
                if (x <(temp->arenas))
                {
                    znd.Add(temp->name, temp->sport, temp->year, temp->places, temp->arenas);
                }
                temp = temp->Next;
            }
            cout << znd;
        }
    }
    else
    {
        cout << "No such parametr!" << endl << endl;
    }
 }
