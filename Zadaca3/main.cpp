#include <iostream>
#include <string>
#include <vector>
#include "comp.h"

int main(void)
{
    Computer A(1800, "intel", 1024), B(2500, "amd", 23), C(2200, "intel", 4096); 
    Computer *niz_racunala[5];
    niz_racunala[0] = new Notebook(1500, "intel", 2048, 15.6);
    niz_racunala[1] = new Computer(3300, "apple", 1024);
    niz_racunala[2] = new Tablet(2000, "nvidia", 2048, 15.6, "android");
    niz_racunala[3] = new Tablet(1700, "arm", 2048, 10.1, "ios");
    niz_racunala[4] = new Notebook(2000, "via", 4096, 17.3);
        cout << "Velicina niza " <<A.niz.size() <<endl;

    Computer &brzi = Computer::fastest_computer();
    cout << "Najbrze racunalo:" << endl;
    cout << brzi.get_mhz() << " " << brzi.get_vendor() << " " << brzi.get_memory() << endl;
    cout << "Velicina niza " <<A.niz.size() <<endl;

        // Najbrze racunalo:
        // 3300 apple 1024
    cout << "Sljedece najbrze racunalo:" << endl;
    Computer &next = A.next_fastest();
    cout << next.get_mhz() << " " << next.get_vendor() << " " << next.get_memory() << endl;
        // Sljedece najbrze racunalo:
        // 2000 nvidia 2048
    cout << "Cijene nadogradnji:" << endl;
    for(int i = 0; i < 5 ; i++)
        cout << niz_racunala[i]->upgrade(niz_racunala[i]->get_mhz() + 1000, niz_racunala[i]->get_memory() + 1024) << endl;
        // Cijene nadogradnji:
        // 5048
        // 3024
        // 6072
        // 6072
        // 5048
    cout << "Nadogradjena racunala:" << endl;
    for(int i = 0; i < 5 ; i++)
        cout << niz_racunala[i]->get_mhz() << " " << niz_racunala[i]->get_vendor() << " " << niz_racunala[i]->get_memory() << endl;
            // Nadogradjena racunala:
            // 2500 intel 3072
            // 4300 apple 2048
            // 3000 nvidia 3072
            // 2700 arm 3072
            // 3000 via 5120
    Tablet t(1500, "intel", 1024, 9.8, "android");
    cout << "Tablet" << endl;
    cout << t.get_mhz() << " " << t.get_vendor() << " " << t.get_memory() << " " << t.get_screen_size() << " " << t.get_os() << endl;
            //Tablet
            //1500 intel 1024 9.8 android
    cout << "Velicina niza " <<A.niz.size() <<endl;
    Computer X(1800, "amd", 1024), Y(2200, "via", 1024);
    Computer &Z = Computer::faster(X, Y);
    cout << "Brze racunalo:" << endl;
    cout << Z.get_mhz() << " " << Z.get_vendor() << " " << Z.get_memory() << endl;
            //Brze racunalo:
            //2200 via 1024
    cout << "Velicina niza " <<A.niz.size() <<endl;
    for(int i = 0; i < 5; i++)
        delete niz_racunala[i]; 
    cout << "Velicina niza " <<A.niz.size() <<endl;
    cout << "E si mi dobar" << endl;
    
    
   /* Computer *niz_racunala[5];
    niz_racunala[0] = new Notebook(1500, "intel", 2048, 15.6);
    niz_racunala[1] = new Computer(3300, "apple", 1024);
    niz_racunala[2] = new Tablet(2000, "nvidia", 2048, 15.6, "android");
    niz_racunala[3] = new Tablet(1700, "arm", 2048, 10.1, "ios");
    niz_racunala[4] = new Notebook(2000, "via", 4096, 17.3);
    Computer &brzi = Computer::fastest_computer();
    
    cout << "Velicina niza " <<Computer::niz.size() <<endl;
    for(int i = 0; i < 5; i++)
        delete niz_racunala[i]; 
    cout << "Velicina niza " <<Computer::niz.size() <<endl;
    */
    return 0;
}
