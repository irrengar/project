//
// Created by Ehsan on 12/5/2020.
//
/*
#include<iostream>
#include<fstream>
#include<string>


using namespace std;

bool IsLoggedIn()
{
    string username, password, un, pw;

    cout<< "Enter username: "<<username<<endl;
    cout<< "Enter password: "<<password<<endl;

    ifstream read("C:\\"+username+".txt");
    getline(read, un);
    getline(read, pw);

    if(un ==username && pw == password){
        return true;
    }
    else
        return false;
}
int Authentication_login()
{
    int choice;
    cout << "1: Register\n2: Login\nYour choice: ";cin>>choice;
    if(choice == 1)
    {
        string username, pasword;

        cout<<"select a username: ";cin>>username;
        cout<<"select a password: ";cin>>pasword;

        ofstream file;
        file.open("C:\\"+username+".txt");

        file << username <<endl<<pasword;
        file.close();
        Authentication_login();
    }
    else if(choice==2)
    {
        bool status = IsLoggedIn();

        if (!status)
        {
            cout<<"False login"<<endl;
            system("pause");
            return 0;
        }
        else
        {
            cout<<"Successfully logged in"<<endl;
            system("pause");
            return 1;
        }
    }
}
*/
/*
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

class LoginManager
{
public:

    LoginManager()
    {
        accessGranted = 0;
    }
    void login()
    {
        cout << "Ahem. A username is required. \nUsername:";
        cin >> userNameAttempt;

        int usrID = checkFile(userNameAttempt, "C:\\Users\\Ehsan\\CLionProjects\\project\\sources\\users.dat");
        if(usrID != 0)
        {
            cout << "Password:";
            cin >> passwordAttempt;

            int pwdID = checkFile(passwordAttempt, "C:\\Users\\Ehsan\\CLionProjects\\project\\sources\\pswds.dat");
            if(usrID == pwdID)
            {
                cout << "Hey, thats right. \n" << endl;;
                login();

            }
            else
            {
                cout << "Not even close." << endl;
                login();
            }
        }
        else
        {
            cout << "Nice try, bud." << endl;
            login();
        }
    }

    void addUser(const string username, const string password)
    {
        if(checkFile(username, "C:\\Users\\Ehsan\\CLionProjects\\project\\sources\\users.dat") != 0)
        {
            cout << "That username is not availble." << endl;
            return;
        }

        int id = 1 + getLastID();
        saveFile(username, "C:\\Users\\Ehsan\\CLionProjects\\project\\sources\\users.dat", id);
        saveFile(password, "C:\\Users\\Ehsan\\CLionProjects\\project\\sources\\pswds.dat", id);
    }

    int getLastID()
    {
        fstream file;
        file.open("C:\\Users\\Ehsan\\CLionProjects\\project\\sources\\users.dat", ios::in);
        file.seekg(0, ios::end);

        if(file.tellg() == -1)
            return 0;

        string s;

        for(int i = -1; s.find("#") == string::npos; i--)
        {
            file.seekg(i, ios::end);
            file >> s;
        }

        file.close();
        s.erase(0, 4);

        int id;
        istringstream(s) >> id;

        return id;
    }

    int checkFile(string attempt, const char* p_fileName)
    {
        string line;
        fstream file;

        string currentChar;
        long long eChar;

        file.open(p_fileName, ios::in);

        while(1)
        {
            file >> currentChar;
            if(currentChar.find("#ID:") != string::npos)
            {
                if(attempt == line)
                {
                    file.close();
                    currentChar.erase(0, 4);
                    int id;
                    istringstream(currentChar) >> id;
                    return id;
                }
                else
                {
                    line.erase(line.begin(), line.end());
                }
            }
            else
            {
                istringstream(currentChar) >> eChar;
                line += (char)decrypt(eChar);
                currentChar = "";
            }

            if(file.peek() == EOF)
            {
                file.close();
                return 0;
            }
        }
    }

    void saveFile(string p_line, const char* p_fileName, const int& id)
    {
        fstream file;
        file.open(p_fileName, ios::app);
        file.seekg(0, ios::end);

        if(file.tellg() != 0)
            file << "\n";

        file.seekg(0, ios::beg);

        for(int i = 0; i < p_line.length(); i++)
        {
            file << encrypt(p_line[i]);
            file << "\n";
        }

        file << "#ID:" << id;
        file.close();
    }

    long long encrypt(int p_letter)
    {
        return powf(p_letter, 5) * 4 - 14;
    }
    int decrypt(long long p_letter)
    {
        return powf((p_letter + 14) / 4, 1/5.f);
    }

private:
    string userNameAttempt;
    string passwordAttempt;
    bool accessGranted;
};

int main()
{
    LoginManager app;
    app.login();
    cin.get();
}
 */