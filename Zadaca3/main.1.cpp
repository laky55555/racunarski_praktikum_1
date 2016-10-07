#include <iostream>
#include "comp.h"

using namespace std;

void print_computer(Computer &c)
{
	cout << c.get_mhz() << " " << c.get_vendor() << " " << c.get_memory() << endl;
}

int main(void)
{
    Computer computer(1800, "intel", 1024);
    Notebook notebook(2000, "amd", 2048, 15.6);
    Tablet tablet(2200, "intel", 4096, 10.1, "android");
    
    print_computer(computer);

    print_computer(notebook);
    cout << notebook.get_screen_size() << endl;

    print_computer(tablet);
    cout << tablet.get_screen_size() << " " << tablet.get_os() << endl;

    return 0;
}

