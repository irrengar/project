#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//string path;

class todo{
public:

    static void clean_buffer();
    static void addItems(int );
    static int menu();
    static int showList();
    static void removeItems();
    static int choice();

};
void todo::clean_buffer(){
    cin.clear();
    cin.sync();
}
void todo::addItems(int amount_items){
    clean_buffer();
    ofstream add("save.dat", ios::app);
    string item;
    for(int i = 1; i <= amount_items; i++) {
        cout << "Enter item #" << i << " ";
        getline(cin, item);
        add << item << endl;
}
    add.close();
    cout << endl;

}
int todo::menu(){

    int choice;
    cout << "\t The Menu\n" << endl;
    cout << "[1] - Show To Do list." << endl;
    cout << "[2] - Add new items to To Do list." << endl;
    cout << "[3] - Remove items from To Do list." << endl;
    cout << "[4] - Exit the program." << endl;
    cin >> choice;
    cout << endl;
    return choice;
}
int todo::showList(){

    bool stop = true;
    cout << "\t The To Do List\n" << endl;
    string line;
    ifstream show("save.dat", ios::in );
    getline(show, line);
    if(show.eof()) {
        cout << "\t**********************" << endl;
        cout << "\t*To Do list is empty.*" << endl;
        cout << "\t**********************" << endl;
        return stop;
    }
    for(int i = 1; !show.eof(); i++) {
    cout << i << "." << " " << line << endl;
    getline(show, line);
    }
    show.close();
    cout << endl;
    return false;
}
void todo::removeItems() {

    bool check = showList();
    if (check == true) {
        cout << endl;
    cout << "There are no items to remove." << endl;
    exit(1);
    }
    clean_buffer();
    string line, name;
    cout << "Please Enter the name of Todo you want to delete: ";
    cin >> name;

    ifstream myfile;
    ofstream temp;
    myfile.open("save.dat");
    temp.open("temp.dat");
    while (getline(myfile, line)) {
        if (line != name)
        temp << line << endl;
    }
    cout << "The record with the name '" << name << "' has been deleted if it existed" << endl;
    myfile.close();
    temp.close();
    remove("save.dat");
    rename("temp.dat", "save.dat");
}
    int todo::choice() {
    bool working = true;
    cout << "Welcome to To-Do list program!\n" << endl;
    do {
        int choice;
        choice = menu();

        switch (choice) {

            case 1:
               showList();
               break;
            case 2:
                int amount;
                cout << "\t Add New Items\n" << endl;
                cout << "Enter how many items do you want to add: ";
                clean_buffer();
                cin >> amount;
                addItems(amount);
                break;
            case 3:
                removeItems();
                break;
            case 4:
                cout << "Have a nice day!" << endl;
                working = false;
                break;
            default:
                cout << "Input was not recognized. Try again or "
                << "\nenter 4 to exit." << endl;
                working = true;
        }
    }while (working);
    return 0;
}
int main()
{
    system("COLOR C");
    system("COLOR CC");
    todo obj;
    obj.choice();
    return 0;
}