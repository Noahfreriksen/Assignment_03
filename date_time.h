//
// Created by Gebruiker on 12-12-2018.
//

#ifndef ASSIGNMENT_03_DATE_TIME_H
#define ASSIGNMENT_03_DATE_TIME_H
#include <ctime>
#include <iostream>
#include <chrono>

using namespace std;
class date_time {

public:

    time_t rawtime;

    //constructors
    date_time();
    date_time(int, int, int);

    //getters
    int getDay();
    int getMonth();
    int getYear();
    int getHour();
    int getMinute();
    int getSecond();

    //setters
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);

    void str();
    void str(string);

    void parse(string);
    void parse(string, string);

    void advance(std::chrono::seconds);
    void step_back(std::chrono::seconds);
};

#endif //ASSIGNMENT_03_DATE_TIME_H
