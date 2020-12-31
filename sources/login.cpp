#include <iostream>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
template <typename T>
T get_input(const std::string& strQuery);
std::string get_username();
std::string get_password();
void save_user(const std::string& username, const std::string& password);
void login();

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
std::string get_password()
{
    std::string password1 = get_input <std::string>("Please enter your password.");
    std::string password2 = get_input <std::string>("Please re-enter your password.");

    while (password1 != password2) {
        std::cout << "Error! Passwords do not match." "\n";
        password1 = get_input <std::string>("Please enter your password.");
        password2 = get_input <std::string>("Please re-enter your password.");
    }

    return password1;
}
std::string get_username()
{
        std::string username = get_input <std::string>("Please enter a username.");
         std::cout << "Username: \"" << username << "\"\n";

    while (get_input <int>("Confirm? [0|1]") != 1) {
        username = get_input <std::string>("Please enter a username.");
        std::cout << "Username: \"" << username << "\"\n";
}
    
    void login()
    {
        std::cout << "You are being logged in!" "\n";
    }
