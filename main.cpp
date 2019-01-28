#include <iostream>
#include <ctime>
#include "date_time.h"

using namespace std;

int main() {

    date_time date1(2018,12,5);
    date1.setYear(2020);
    //date1.str("DD/MM/YYYY hh:mm:ss");
    //date1.str("YYYY/MM/DD");
    //date1.parse("02_11_1995");
    //date1.str();

    //date1.parse("08/07/1997/22/56","DD/MM/YYYY/HH/MM");
    //date1.str();

    //advance with one day
    date1.advance(chrono::seconds(86400));
    //date1.str();


    return 0;
}