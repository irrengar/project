

#include "Event.h"


Event::Event()
{
}


Event::~Event()
{
}

Event::Event(string newTitle, int day, MONTH month, int year, int hour, int minutes, string newDescript, string newStabilize) {
    title = newTitle;
    date.tm_mday = day;
    date.tm_mon = month;
    date.tm_year = year;
    date.tm_hour = hour;
    date.tm_min = minutes;
    description = newDescript;
    done = newStabilize;
}

void Event::writeEvent(ofstream &fout) {
    fout << title << endl;
    fout << description << endl;
    fout << done << endl;
    fout << date.tm_hour << endl;
    fout << date.tm_min << endl;
    fout << MONTH(date.tm_mon) << endl;
    fout << date.tm_mday << endl;
    fout << date.tm_year << endl;
}

void Event::showMenu() {
    //fin >> title;
    cout << title << endl;
    //fin >> description;
    cout << description << endl;
    //fin >> done;
    cout << done << endl;
    //fin >> date.tm_hour;
    cout << date.tm_hour << endl;
    //fin >> date.tm_min;
    cout << date.tm_min << endl;
    //fin >> date.tm_mon;
    cout << MONTH(date.tm_mon) << endl;
    //fin >> date.tm_mday;
    cout << date.tm_mday << endl;
    //fin >> date.tm_year;
    cout << date.tm_year << endl;
}
void Event::editTitle(string newTitle) {
    title = newTitle;
}

void Event::editDate(int day, MONTH month, int year, int hour, int minutes) {
    date.tm_mday = day;
    date.tm_mon = month;
    date.tm_year = year;
    date.tm_hour = hour;
    date.tm_min = minutes;
}

void Event::editDescript(string newDescript) {
    description = newDescript;
}

void Event::editDone(string newStabilize) {
    done = newStabilize;
}

string Event::getTitle() {
    return title;
}

string Event::getDescription() {
    return description;
}

string Event::getDone() {
    return done;
}

tm Event::getDate() {
    return date;
}





