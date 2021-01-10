


#include "Menu.h"



Menu::Menu(mmap newContainer)
{
    container = newContainer;
}
Menu::Menu() {}

Menu::~Menu()
{

}

void Menu::start() {
    int choice;

    cout << "\nMENU\n1. Create New Event\n2. Edit Saved Event\n3. Delete Saved Event\n4. Time\n5. Quit";
    cin >> choice;

    if (choice == 1) {
        string title, description, done;
        int hour, minute, month, day, year;

        cin.ignore();

        cout << "CREATING NEW EVENT..." << endl;

        cout << "Enter title: ";
        getline(cin, title);
        cout << "\nEnter description: ";
        getline(cin, description);
        cout << "\nEnter done/undone: ";
        getline(cin, done);
        cout << "\nEnter hour: ";
        cin >> hour;
        cout << "\nEnter minute: ";
        cin >> minute;
        cout << "\nEnter month: ";
        cin >> month;
        cout << "\nEnter day: ";
        cin >> day;
        cout << "\nEnter year: ";
        cin >> year;
        Event newEvent = Event(title, day, MONTH(month), year, hour, minute, description, done);

        container.insert(mmap_pair(title, newEvent));

        cout << "\nNEW EVENT SAVED" << endl;

        ofstream fout;

        fout.open("savedEvents.txt");

        for (mmap::iterator it = container.begin(); it != container.end(); ++it)
            (*it).second.writeEvent(fout);

        //return 1;
    }
    else if (choice == 2) {
        string title4edit;
        Event event4edit;
        int choice2;

        cin.ignore();

        cout << "\nWhat is title of event to edit?\n";
        getline(cin, title4edit);

        event4edit = container.find(title4edit)->second;

        cout << "EVENT FOUND!" << endl;

        //cin.ignore();

        cout << "1. Edit Title\n2. Edit Description\n3. Edit Date\n4. Edit done";
        cin >> choice2;

        if (choice2 == 1) {
            string newTitle;

            cout << "\nNew Title: ";
            getline(cin, newTitle);

            event4edit.editTitle(newTitle);

            event4edit.showMenu();

            cin.ignore();

            ofstream fout;

            fout.open("savedEvents.txt");

            event4edit.getTitle();

            for (mmap ::iterator it = container.begin(); it != container.end(); ++it)
                (*it).second.writeEvent(fout);
        }
        else if (choice2 == 2) {
            string newDescript;

            cout << "\nNew Description: ";
            getline(cin, newDescript);

            event4edit.editDescript(newDescript);

            event4edit.showMenu();

            cin.ignore();

            ofstream fout;

            fout.open("savedEvents.txt");

            for (mmap::iterator it = container.begin(); it != container.end(); ++it)
                (*it).second.writeEvent(fout);
            cin.ignore();
        }
        else if (choice2 == 3){
            int newHour, newMinute, newMonth, newDay, newYear;

            cout << "\nEnter hour: ";
            cin >> newHour;
            cout << "\nEnter minute: ";
            cin >> newMinute;
            cout << "\nEnter month: ";
            cin >> newMonth;
            cout << "\nEnter day: ";
            cin >> newDay;
            cout << "\nEnter year: ";
            cin >> newYear;

            event4edit.editDate(newDay, MONTH(newMonth), newYear, newHour, newMinute);

            event4edit.showMenu();

            ofstream fout;

            fout.open("savedEvents.txt");

            for (mmap::iterator it = container.begin(); it != container.end(); ++it)
                (*it).second.writeEvent(fout);
        }
        else if (choice2 == 4){
            string newStabilize;

            cout << "\nNew stabilize: ";
            getline(cin, newStabilize);

            event4edit.editDone(newStabilize);

            event4edit.showMenu();

            cin.ignore();

            ofstream fout;

            fout.open("savedEvents.txt");

            for (mmap::iterator it = container.begin(); it != container.end(); ++it)
                (*it).second.writeEvent(fout);
            cin.ignore();
        } else{
            cout << "Wrong number!" << endl;
        }

        cout << "\nEVENT EDITED AND SAVED" << endl;

        //return 2;
    }
    else if(choice == 3) {
        string title4edit;

        cout << "\nWhat is title of event to delete?\n";
        cin >> title4edit;

        container.erase(title4edit);

        ofstream fout;

        fout.open("savedEvents.txt");

        for (mmap::iterator it = container.begin(); it != container.end(); ++it)
            (*it).second.writeEvent(fout);

        //return 3;
    }
    else if (choice == 4){
        Functions timer;
        timer.userCH();
        //return 4;
    }
    else{
        system("pause");
    }
}
