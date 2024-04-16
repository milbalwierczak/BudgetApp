#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <ctime>

using namespace std;

class DateMethods
{
    static bool isLeapYear(int year);
    static int getMonthLastDay(int month, int year);
public:
    static bool validateDate(string dateAsString);
    static int getCurrentDate();
    static int getCurrentMonthFirstDayDate();
    static int getCurrentMonthLastDayDate();
    static int getPreviousMonthFirstDayDate();
    static int getPreviousMonthLastDayDate();
    static int convertStringDateToInt(string dateAsString);
    static string convertIntDateToStringWithDashes(int dateAsInt);
};

#endif
