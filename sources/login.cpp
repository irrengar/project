#include <iostream>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
template <typename T>
T get_input(const std::string& strQuery);



int main() {

}
template <typename T>
T  get_input(const std::string& strQuery) {
    std::cout << strQuery << "\n> ";
    T out = T();

    while (!(std::cin >> out)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Error!" "\n";
        std::cout << strQuery << "\n> ";
    }
}