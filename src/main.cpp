#include <cstddef>
#include <iostream>
#include "myStructures.hpp"
int main () {
    ms::ll::LinkedList<int> list(1);
    list.push_back(2);
    list.push_back(5);
    list.print();
    std::cout << "\nfind 2: " << list.find(2) << "\n";
    std::cout << "\nfind 1: " << list.find(1) << "\n";
    std::cout << "\nfind 5: " << list.find(5) << "\n";
    list.pop_back();
    list.print();
    list.push_back(10);
    list.print();
    std::cout << "\nget val on 2: " << list.get_val(2) << "\n";
    std::cout << "\nget val on 0: " << list.get_val(0) << "\n";
    std::cout << "\nget val on 1: " << list.get_val(1) << "\n";
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.print();
    list.insert(-1, 0);
    list.print();
    list.insert(-2, 0);
    list.print();
    list.insert(-3, 0);
    list.print();
    list.insert(6, 6);
    list.print();
    list.remove(1);
    list.print();
    list.remove(0);
    list.print();

    list.delete_llist();
    return 0;
}
