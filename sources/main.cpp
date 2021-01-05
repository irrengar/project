

#include <string>
#include <iostream>
#include <ctime>
#include <fstream>
#include <map>
#include "Event.h"
#include "Menu.h"

using namespace std;

int main() {
    typedef multimap<string, Event> mmap;
    typedef pair<string, Event> mmap_pair;

    int thisMonth, thisDay, thisYear;
    //int menuChoice;

    char title[256], description[256], done[256];
    char hour[256], minute[256], month[256], day[256], year[256];

    mmap container;

    ifstream fin;
    ofstream fout;

    cout << "Welcome to REMINDER!" << endl;
    cout << "What is today's day?" << endl;
    cout << "Today's Month: ";
    cin >> thisMonth;
    cout << "\nToday's Day: ";
    cin >> thisDay;
    cout << "\nToday's Year: ";
    cin >> thisYear;

    fin.open("savedEvents.txt");

    if (!fin.is_open()) {
        cout << "NO FILE FOUND!" << endl;
    }

    cout << "\nTODAYS REMINDERS!" << endl;

    while (fin.getline(title, 256)) {

        fin.getline(description, 256);

        fin.getline(done, 256);

        fin.getline(hour, 256);

        fin.getline(minute, 256);

        fin.getline(month, 256);

        fin.getline(day, 256);

        fin.getline(year, 256);

        if ((stoi(string(month)) == thisMonth) && (stoi(string(day)) == thisDay) && (stoi(string(year)) == thisYear)) {
            cout << "Title -> " << string(title) << endl << "description-> "<< string(description) << endl << "stabilize : " << string(done) << endl;
        }

        Event newEvent = Event(string(title), stoi(string(day)), MONTH(stoi(string(month))), stoi(string(year)), stoi(string(hour)), stoi(string(minute)), string(description) ,string(done));

        container.insert(mmap_pair(title, newEvent));
    }

    fin.close();

    Menu newMenu = Menu(container);

    //menuChoice = 0;

    //while (menuChoice != 4) {
    newMenu.start();

    //cout << menuChoice << endl;
    //}

    system("pause");
    return 0;
}
