#include "Reminder.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <chrono>

int userCH;
Menu menu;
using namespace std;


void Functions::setTimer(){

    unsigned long long days = 0;
    unsigned long long hours = 0;
    unsigned long long minutes = 0;               // days, hours, minutes, seconds equals to 0 , they are long long just in case if the time is large.
    unsigned long long seconds = 0;

    cout <<"How long should be reminder set?"<<endl;

    cout <<"Please add days - 0 to skip!"<<endl;

    cin >> days;

    if(days > 0) {     //add days

        cout <<days <<" "<<"Days ave been added!"<<endl;
    }

    else{
        cout <<"Days skip!"<<endl;
    }

    cout <<"Please add hours - 0 to skip!"<<endl;

    cin >> hours;   //add hours

    if(hours > 0){
        cout <<hours <<" "<<"Hours have been added!"<<endl;
    }
    else{
        cout <<"Hours skip!"<<endl;
    }

    cout <<"Please add minutes - 0 to skip!"<<endl;

    cin >> minutes;

    if(minutes > 0) {        //add mins
        cout <<minutes <<" "<<"Minutes have been added!"<<endl;
    }
    else{
        cout <<"Minutes skip!"<<endl;
    }

    cout <<"Please add seconds - 0 to skip!"<<endl;

    cin >> seconds;
    //add seconds
    if(seconds > 0){
        cout <<seconds <<" "<<"Seconds have been added!"<<endl;
    }
    else{
        cout <<"Seconds skip!"<<endl;
        if(days>0||minutes>0||hours>0){

        }
        else{
            cout << "No Input, Transfering to the menu!" <<endl;                //if everything is 0 then no alarm set, transferes to the menu.
            Sleep(2000);
            menu.start();
            }
    }



    days = days * 86400000;
    hours = hours * 3600000;                   //working will millisconds
    minutes = minutes * 60000;
    seconds = seconds * 1000;


    chrono::steady_clock::time_point tend = std::chrono::steady_clock::now()              // chrono function gets the real time that alarm was set then adds
                                            + std::chrono::milliseconds(days+hours+minutes+seconds);                       // the days, hours or seconds was set by user and calculates the time alarm will be ready

    while (std::chrono::steady_clock::now() != tend){
        if(chrono::steady_clock::now() < tend) {                                            //if time is up then reminder is ready
            cout <<"You asked me to remind you!\n";
            cout <<"Your time is up!"<<endl;
            cout <<"Your are going to be transfered to the menu!"<<endl;
            //cout << '\a'; //beep sound
            Beep(523,500);
            Sleep(100);
            Beep(523,500);                  //Beef feature added 3 times, from windows h header file
            Sleep(100);
            Beep(523,500);
            Sleep(3000);

            system("cls");
            menu.start();
        }

    }

}

void Functions::userCH()
{
    system("cls");
    int userChoice;
    cout <<"Choice between the functions below 1-3"<<endl;
    cout <<"1.Set timer"<<endl;
    cout <<"2.Show clock"<<endl;
    cout <<"3.Menu"<<endl;
    cin >> userChoice;                                  //this is the menu for the reminder part

    if(userChoice == 1){
        Functions::setTimer();
    }

    else if(userChoice == 2){
        Functions::showClock();
        Sleep(1000);
        Functions::userCH();
    }
    else if(userChoice==3){
        menu.start();
    }
    else{
        cout <<"Wrong input, transfering back to Menu." <<endl;
        Sleep(1500);
        menu.start();
    }

}
void Functions::showClock(){

    time_t rawtime;
    struct tm * timeinfo;
    //this prints the real time and prints
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    printf ("%s", asctime(timeinfo));
    system("cls");
    menu.start();
}
