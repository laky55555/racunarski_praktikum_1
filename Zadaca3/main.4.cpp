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
    Tablet t_1(2200, "intel", 4000, 10.1, "android"), t_2(1500, "via", 1000, 9, "ios");

    print_computer(c_1.next_fastest());
    print_computer(c_2.next_fastest());
    print_computer(n_1.next_fastest());
    print_computer(n_2.next_fastest());
    print_computer(t_2.next_fastest());

    return 0;
}