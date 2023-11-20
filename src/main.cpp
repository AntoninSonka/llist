#include <cstddef>
#include <iostream>
#include "myStructures.hpp"

int main () {
    ms::ll::LinkedList<int> list(1);
    for(int i = 0; i < 9; i++){
        list.push_back(i + 2);
    }
    list.print();
    

    return 0;
}
