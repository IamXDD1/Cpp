#include "Counter.h"
#include <iostream>
#include <vector>

int main() {
    int myints[] = { 1, 2, 3, 3, 2, 1, 2 };
    std::vector<int> a(myints, myints + sizeof(myints) / sizeof(int));
    Counter<int> c(a);
    std::cout << c[99] << std::endl;
    std::cout << c.total();
    for (auto i : c) {
        std::cout << i.first << ", " << i.second << std::endl;
    }
}
