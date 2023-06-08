#include <iostream>
#include "base_container.h"
#include "sequence_container.cpp"
#include "list_container.cpp"


template <typename T>
void run_test(  T & contName ) {
    size_t valNum=0;
    while (valNum != 10 ) {
        contName.push_back(valNum);
        valNum++;
    }
    contName.show();
    std::cout << "Size: " << contName.size() << std::endl;
    contName.erase(0);
    contName.show();
    contName.erase(4);
    contName.erase(5);
    contName.show();
    contName.insert(0, 10);
    contName.show();
    contName.insert(4, 20);
    contName.show();
    contName.insert(9, 30);
    contName.show();

    std::cout << "Element 1: " << contName[0] << std::endl;
    std::cout << "Element 4: " << contName[3] << std::endl;
    std::cout << "Element 9: " << contName[8] << std::endl;
}


int main() {
    std::cout << "Sequence container" << std::endl;
    Sequence_Container <int> con1;
    run_test(con1);
    Sequence_Container <int> moveCont3;
    moveCont3 = std::move(con1);
    std::cout << "\n\nMove semantic for Sequence_Container " << std::endl;
    for (size_t i=0; i < moveCont3.size(); ++i) {
        std::cout << moveCont3[i] << " ";
    }


    std::cout << "\n\nList container (one dir)" << std::endl;
    List_Container_oneDir <int> con3;
    run_test(con3);
    std::cout << "\n\nMove semantic for List_Container_oneDir" << std::endl;
    List_Container_oneDir <int> moveCont = std::move(con3);
    for (size_t i=0; i < moveCont.size(); ++i) {
        std::cout << moveCont[i] << " ";
    }
    return 0;
}



