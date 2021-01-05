#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

enum MONTH {January, February, March, April, May, June, July, August, September, October, November, December};

class Event
{
private:
	string title;
	tm date;
	string description;
	string done;
public:
	Event();
	~Event();
	Event(string title, int day, MONTH month, int year, int hour, int minutes, string descript, string stabilize);

	void displayEvent();
	void displayEvent(ofstream &fout);
	void editTitle(string newTitle);
	void editDate(int day, MONTH month, int year, int hour, int minutes);
	void editDescript(string descript);
	void editDone(string stabilize);
	string getTitle();
	string getDescription();
	string getDone();
	tm getDate();


};

