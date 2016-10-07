#include <iostream>
#include <string>
#include "vehicle.h"
#include <list>
using namespace std;


list<Vehicle*> Vehicle::lista;

Vehicle::Vehicle (int max_speed, int cc, string registration)
{
    brzina=max_speed;
    kubik=cc;
    registracija=registration;
    gorivo=100;
    lista.push_back(this);
}
int Vehicle::get_max_speed()
{
    return brzina;
}
int Vehicle::get_cc()
{
    return kubik;
}
string Vehicle::get_registration ()
{
    return registracija;
}
int Vehicle::get_gas()
{
    return gorivo;
}
void Vehicle::drive_10km ()
{
    this->gorivo-=10;
}
list <Vehicle*> Vehicle::same_speed()
{
    list <Vehicle*> nova;
    list<Vehicle*>::iterator i,j;
    for (i=lista.begin();i!=lista.end();i++)
    {
        if((*i)->brzina==brzina)
        {
            if(nova.empty()) nova.push_back(*i);
            else
            {
                for (j=nova.begin(); (j!=nova.end()&&(*j)->kubik<(*i)->kubik) ;j++);
                if(j==nova.end())nova.push_back(*i);
                else nova.insert(j,*i);

            }
        }
    }
    return nova;
}

Vehicle& Vehicle::fastest()
{
    list<Vehicle*>::iterator i;
    Vehicle *najbrzi;
    for (i=lista.begin();i!=lista.end();i++)
    {
        if(i==lista.begin()) najbrzi=*i;
        if((*i)->brzina>najbrzi->brzina||((*i)->brzina==najbrzi->brzina&&(*i)->kubik>najbrzi->kubik))najbrzi=*i;
    }
    return (*najbrzi);
}
Vehicle::~Vehicle()
{
    list <Vehicle*>::iterator i;
    for (i=lista.begin();i!=lista.end();)
    {
        if((*i)==this)
        {
            i=lista.erase(i);
        }
        else i++;
    }
}

Motorcycle::Motorcycle(int max_speed, int cc, string registration, char type):Vehicle(max_speed, cc, registration )
{
    vrsta=type;
}
void Motorcycle::drive_10km()
{
    this->gorivo-=5;
}
string Motorcycle::get_type()
{
    if(vrsta=='R') return (string("race"));
    else return (string("skuter"));
}
Motorcycle::~Motorcycle()
{
    list <Vehicle*>::iterator i;
    for (i=lista.begin();i!=lista.end();)
    {
        if((*i)==this)
        {
            i=lista.erase(i);
        }
        else i++;
    }
}
Car::Car(int max_speed, int cc, string registration, int volume):Vehicle(max_speed, cc, registration)
{
    volumen=volume;
}
void Car::drive_10km()
{
    this->gorivo-=15;
}
int Car::get_volume()
{
    return volumen;
}
Car::~Car()
{
    list <Vehicle*>::iterator i;
    for (i=lista.begin();i!=lista.end();)
    {
        if((*i)==this)
        {
            i=lista.erase(i);
        }
        else i++;
    }
}
