//
//  Menu.h
//  project3
//
//  Created by Andrew on 2/14/18.
//  Copyright © 2018 Andrew. All rights reserved.
//
#ifndef Menu_h
#define Menu_h

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <map>
#include "Event.h"

using namespace std;

typedef multimap<string, Event> mmap;
typedef pair<string, Event> mmap_pair;

class Menu
{
private:
	mmap container;
public:
	Menu(mmap newContainer);
	~Menu();
	void start();
};

#endif /* Menu_h */
