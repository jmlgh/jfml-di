#include <iostream>
#include <string>
#include "di.h"

int main() {
    DependencyContainer container;

    container.registerType<std::string>();
    auto myString = container.resolve<std::string>();
    *myString = "Hello, Dependecy Injection!";

    container.registerType<int>();
    auto myInt = container.resolve<int>();
    *myInt = 42;

    std::cout << *myString << std::endl;
    std::cout << *myInt << std::endl;

    return 0;
}