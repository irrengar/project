#include <iostream>
#include <string>
#include <fstream>
#include "../Header/19ToDo.h"
using namespace std;

bool addToList(string description, int priority, string dueDate);
bool getNextItem(MyToDo &mytodo);
bool getByPriority(MyToDo matches[100], int search);
void printToDo();
bool IsLoggedIn();
int Authentication_login();


class LoginManager{
public:

    LoginManager(){
        accessGranted = 0;
    }
    int Authentication_login()
    {
        int choice;
        cout << "1: Register\n2: Login\nYour choice: ";cin>>choice;
        if(choice == 1)
        {
            string username, password;

            cout<<"select a username: ";cin>>username;
            cout<<"select a password: ";cin>>password;

            ofstream file;
            file.open("C:\\"+username+".txt");

            file << username <<endl<<password;
            file.close();
            Authentication_login();
        }
        else if(choice==2)
        {
            Login();
        }
    }
    void Login(){
        cout<<"Enter ur username: \nUsername: ";
        cin>>UserNameAttempt;

        UserName = getFile("C:\\Users\\Ehsan\\CLionProjects\\project\\sources\\users.dat");

        if(UserNameAttempt==UserName)
        {
            cout << "password: ";
            cin >> PassWordAttempt;

            PassWord = getFile("C:\\Users\\Ehsan\\CLionProjects\\project\\sources\\pswds.dat");

            if (PassWordAttempt == PassWord)
            {
                cout << "The password is right";
                system("pause");
                system("cls");
            }
            else
            {
                cout << "wrong password\n";
                system("pause");
                system("cls");
                Login();
            }
        }
        else
        {
            cout << "Try again\n";
            Login();
        }

    }
    string getFile(const char* p_fileName)                          //p is stand for parameter variables
    {
        string line;
        fstream file;

        file.open(p_fileName, ios::in);                                 //in this simply indcates what type of data coming in not out
        if (file.is_open())
        {
            getline(file, line);
        }

        file.close();

        return line;

    }
private:
    string PassWord="1234";
    string UserName="ali";
    string UserNameAttempt;
    string PassWordAttempt;
    bool accessGranted;
};


int main()
{

    LoginManager LoginManagerObj;
    LoginManagerObj.Authentication_login();
    LoginManagerObj.Login();
    cin.get();




    //
    int choice = 0;
    char nextmove = 'y';


    while ('y' == nextmove)
    {
        system("cls");
        cout << "This will keep of the things you need to do!" << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Add to my to do list" << endl;
        cout << "2. Display the next item in my list" << endl;
        cout << "3. Search for activities of a certain priority" << endl;
        cout << "4. Print out my whole list" << endl;

        cin >> choice;

        if (choice == 1)
        {
            string description;
            int priority;
            string dueDate;

            system("cls");
            cout << "what is the description of the activity?" << endl;
            cin.ignore();
            getline(cin, description);
            system("cls");
            cout << "how urgent is this? rank 1-5. 1 for not really important, 5 for very important" << endl;
            cin >> priority;
            system("cls");
            cout << "when is the due date? is day/month format" << endl;
            cin >> dueDate;
            system("cls");
            addToList(description, priority, dueDate);

        }
        else if (choice == 2)
        {

            MyToDo y;

            getNextItem(y);

            system("cls");
            cout <<"Description: " << y.description << endl;
            cout << "Priority :" << y.priority << endl;
            cout << "Due Date :" << y.dueDate << endl;


        }
        else if (choice == 3)
        {
            struct MyToDo matches[100];
            int search = 0;
            cout << "Enter a priority level to search for 1-5" << endl;
            cin >> search;

            getByPriority(&matches[100], search);
            for (int i = 0; i < 10; i++)
            {
                cout << "Description: " << matches[i].description << endl;
                cout << "Priority : " << matches[i].priority << endl;
                cout << "Due Date : " << matches[i].dueDate << endl;
            }
        }
        else if (choice == 4)
        {
            system("cls");
            printToDo();
        }
        else
        {
            system("cls");
            cout << "That was an incorrect choice!" << endl;
        }
        cout << "would you like to keep playing? y for YES" << endl;
        cin >> nextmove;

    }

    cout << "Good job keeping yourself on schedule!" << endl;
    return 0;
}