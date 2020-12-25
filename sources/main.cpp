#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class MySingleton{
public:
    static MySingleton* Instance;
    static MySingleton* getInstance();

private:
    MySingleton();
};
MySingleton* MySingleton::Instance= NULL;
MySingleton::MySingleton() {
    cout<<"in Constractor.."<<endl;
}
MySingleton* MySingleton::getInstance() {
    if(Instance==NULL)
        {
        Instance = new MySingleton();
        }
    return Instance;
}

class LoginManager{
public:

    LoginManager(){
        accessGranted = 0;
    }
    void Authentication_login()
    {
        int choice;
        cout << "1: Register\n2: Login\nYour choice: ";cin>>choice;
        if(choice == 1)
        {
            string username, password;

            cout<<"select a username: ";cin>>username;
            cout<<"select a password: ";cin>>password;

            ofstream file;
            file.open("C:\\Users\\Ehsan\\CLionProjects\\project\\sources"+username+".txt");

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

        file.open(p_fileName, ios::in);                                 //in this simply indicates what type of data coming in not out
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
    system("COLOR C");
    system("COLOR CC");

    todo obj;
    obj.choice();
}