#include <iostream>
#include "comp.h"

using namespace std;

void print_computer(Computer &c)
{
	cout << c.get_mhz() << " " << c.get_vendor() << " " << c.get_memory() << endl;
}

int main(void)
{
    Computer computer(1800, "intel", 1000);
    Computer *notebook = new Notebook(2000, "amd", 2000, 15.6);
    Computer *tablet = new Tablet(2200, "intel", 4000, 10.1, "android");
    

    cout << computer.upgrade(2000, 1500) << endl;
    print_computer(computer);

    cout << notebook->upgrade(2400, 3000) << endl;
    print_computer(*notebook);
    
    cout << tablet->upgrade(2300, 4500) << endl;
    print_computer(*tablet);
    
    return 0;
}

