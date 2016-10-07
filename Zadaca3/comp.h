#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Computer
{
public:
    static vector<Computer *> niz;
    int brzina_procesora, kolicina_memorije;
    string proizvodac_procesora;
    Computer(int mhz, string vendor, int memory);
    int get_mhz();
    int get_memory();
    string get_vendor();
    virtual int upgrade(int mhz, int memory);
    Computer& next_fastest();
    static Computer& fastest_computer();
    static Computer& faster(Computer &comp1, Computer &comp2);
    /*virtual*/ ~Computer();
    
};

class Notebook : public Computer
{
public:
    float velicina_ekrana;
    Notebook(int mhz, string vendor, int memory, float screen_size);
    float get_screen_size();
    virtual int upgrade(int mhz, int memory);  
    //virtual ~Notebook();
};

class Tablet : public Notebook
{
public:
    string operacijski_sustav;
    Tablet(int mhz, string vendor, int memory, float screen_size, string os);
    string get_os();
    int upgrade(int mhz, int memory);
   // ~Tablet();
};
    

