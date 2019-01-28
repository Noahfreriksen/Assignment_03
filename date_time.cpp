//
// Created by Gebruiker on 12-12-2018.
//

#include "date_time.h"
#include <chrono>
#include <ctime>
#include <cmath>
#include <vector>
#include <sstream>

using namespace std;

date_time::date_time() {
    rawtime = time(nullptr);
}

date_time::date_time(int y, int m, int d){
    rawtime = time(nullptr);
    struct tm * timeinfo;
    timeinfo = localtime(&rawtime);
    timeinfo->tm_year = y-1900;
    timeinfo->tm_mon = m-1;
    timeinfo->tm_mday = d;
    rawtime = mktime(timeinfo);
}

//setters
void date_time::setYear(int year) {
    struct tm * timeinfo;
    timeinfo = localtime(&rawtime);
    timeinfo->tm_year = year-1900;
    rawtime = mktime(timeinfo);
}

void date_time::setMonth(int month) {
    struct tm * timeinfo;
    timeinfo = localtime(&rawtime);
    timeinfo->tm_mon = month-1;
    rawtime = mktime(timeinfo);
}

void date_time::setDay(int day) {
    struct tm * timeinfo;
    timeinfo = localtime(&rawtime);
    timeinfo->tm_mday = day;
    rawtime = mktime(timeinfo);
}

void date_time::setHour(int hour) {
    struct tm * timeinfo;
    timeinfo = localtime(&rawtime);
    timeinfo->tm_hour = hour;
    rawtime = mktime(timeinfo);
}

void date_time::setMinute(int minute) {
    struct tm * timeinfo;
    timeinfo = localtime(&rawtime);
    timeinfo->tm_min = minute;
    rawtime = mktime(timeinfo);
}

void date_time::setSecond(int second) {
    struct tm * timeinfo;
    timeinfo = localtime(&rawtime);
    timeinfo->tm_sec = second;
    rawtime = mktime(timeinfo);
}

//getters

int date_time::getYear() {
    struct tm * timeinfo;
    timeinfo = localtime(&rawtime);
    return timeinfo->tm_year+1900;
}

int date_time::getMonth() {
    struct tm * timeinfo;
    timeinfo = localtime(&rawtime);
    return timeinfo->tm_mon+1;
}

int date_time::getDay() {
    struct tm * timeinfo;
    timeinfo = localtime(&rawtime);
    return timeinfo->tm_mday;
}

int date_time::getHour() {
    struct tm * timeinfo;
    timeinfo = localtime(&rawtime);
    return timeinfo->tm_hour;
}

int date_time::getMinute() {
    struct tm * timeinfo;
    timeinfo = localtime(&rawtime);
    return timeinfo->tm_min;
}

int date_time::getSecond() {
    struct tm * timeinfo;
    timeinfo = localtime(&rawtime);
    return timeinfo->tm_sec;
}

void date_time::str() {
    cout << ctime(&rawtime);
}

void date_time::str(string fmt){
    if (fmt == "DD/MM/YYYY hh:mm:ss"){
        cout <<this->getDay()<<"/"<<this->getMonth()<<"/"<<this->getYear()<<" "<<this->getHour()<<":"<<this->getMinute()<<":"<<this->getSecond()<<"\n";
    }
    else if (fmt == "YYYY/MM/DD"){
        cout <<this->getYear()<<"/"<<this->getMonth()<<"/"<<this->getDay()<<"\n";
    }
    else{
        cout << "Unknown format";
    }
}

//method that splits the given date in format DD_MM_YY
void date_time::parse(string date) {
    std::stringstream ss(date);
    std::string segment;
    std::vector<std::string> seglist;

    while(std::getline(ss, segment, '_'))
    {
        seglist.push_back(segment);
    }

    this->setDay(stoi(seglist[0]));
    this->setMonth(stoi(seglist[1]));
    this->setYear(stoi(seglist[2]));
}

void date_time::parse(string date, string fmt) {
    std::stringstream ss(date);
    std::string segment;
    std::vector<std::string> seglist;

    if(fmt == "DD/MM/YYYY/HH/MM") {

        while (std::getline(ss, segment, '/')) {
            seglist.push_back(segment);
        }

        this->setDay(stoi(seglist[0]));
        this->setMonth(stoi(seglist[1]));
        this->setYear(stoi(seglist[2]));
        this->setHour(stoi(seglist[3]));
        this->setMinute(stoi(seglist[4]));
    }

    else if(fmt == "YYYY/MM/DD") {

        while (std::getline(ss, segment, '/')) {
            seglist.push_back(segment);
        }

        this->setYear(stoi(seglist[0]));
        this->setMonth(stoi(seglist[1]));
        this->setDay(stoi(seglist[2]));
    }

    else{
        cout << "Unknown format\n";
    }
}

void date_time::advance(std::chrono::seconds seconds){
    chrono::duration<int> s1 = seconds;
    rawtime += s1.count();
}

void date_time::step_back(std::chrono::seconds seconds) {
    chrono::duration<int> s1 = seconds;
    rawtime -= s1.count();
}
