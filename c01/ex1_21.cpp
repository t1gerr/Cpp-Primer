#include <iostream>
#include "Sales_item.h"

int main() {
    Sales_item item1, item2;
    
    std::cout << "Please input two sales items:" << std::endl;
    
    std::cin >> item1 >> item2;
    
    if (item1.isbn() == item2.isbn()) {
        std::cout << item1 + item2 << std::endl;
    } else {
        std::cout << "They are different items" << std::endl;
    }
}