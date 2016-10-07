#include <iostream>
#include <string>
#include <list>
using namespace std;

class Vehicle
{
private:
    int brzina;
    int kubik;
    string registracija;
protected:
    static list <Vehicle*> lista;
    int gorivo;
public:
    Vehicle (int max_speed, int cc, string registration);
    int get_max_speed();
    int get_cc();
    string get_registration ();
    int get_gas();
    virtual void drive_10km ();
    list <Vehicle*> same_speed ();
    static Vehicle& fastest();
    virtual ~Vehicle();
};

class Motorcycle:public Vehicle
{
private:
    char vrsta;
public:
    Motorcycle(int max_speed, int cc, string registration, char vrsta);
    void drive_10km();
    string get_type();
    ~Motorcycle();
};

class Car:public Vehicle
{
private:
    int volumen;
public:
    Car(int max_speed, int cc, string registration, int volume);
    void drive_10km();
    int get_volume();
    ~Car();
};
