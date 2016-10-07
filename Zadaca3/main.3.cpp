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
    Notebook notebook(2000, "amd", 2000, 15.6);
    Tablet tablet(2200, "intel", 4000, 10.1, "android");
    
    Computer &faster_1 = Computer::faster(computer, notebook);
    print_computer(faster_1);

    Computer &faster_2 = Computer::faster(tablet, notebook);
    print_computer(faster_2);

    return 0;
}

