#include <iostream>
#include "comp.h"

using namespace std;

void print_computer(Computer &c)
{
	cout << c.get_mhz() << " " << c.get_vendor() << " " << c.get_memory() << endl;
}

int main(void)
{
    Computer c_1(1800, "intel", 1000), c_2(1500, "amd", 500);
    Notebook n_1(2000, "amd", 2000, 15.6), n_2(1800, "amd", 500, 13.3);
    Notebook *n_3 = new Notebook(3000, "intel", 1000, 17);
    Tablet t_1(2200, "intel", 4000, 10.1, "android"), t_2(1500, "via", 1000, 9, "ios");
    Tablet *t_3 = new Tablet(2500, "via", 2000, 15.6, "android");

    print_computer(Computer::fastest_computer());
    delete n_3;
    cout << "hgf" << endl;
    print_computer(Computer::fastest_computer());
    delete t_3;
    print_computer(Computer::fastest_computer());
    return 0;
}
