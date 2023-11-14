#include <cstddef>
#include <iostream>
#include "myStructures.hpp"
int main () {
    ms::ll::LinkedList<int> list(1);
    list.push_back(2);
    list.push_back(5);
    list.print();
    std::cout << "\n" << list.find(2) << "\n";
    list.pop_back();
    list.print();
    list.push_back(10);
    list.print();
    std::cout << "\n" << list.get_val(2) << "\n";
    list.set_val(0, 5);
    list.print();
    list.delete_llist();
    return 0;
}
