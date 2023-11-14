#include <cstddef>
#include <iostream>
#include "myStructures.hpp"

int main () {
    LinkedList<int> list(1);
    list.push_back(2);
    list.print();
    return 0;
}
