#include "DateMethods.h"

int DateMethods::getCurrentDate()
{

    int currentDate;

    time_t now = time(nullptr);

    tm* local_time = localtime(&now);

    currentDate = local_time->tm_mday + (local_time->tm_mon + 1)*100 + (local_time->tm_year + 1900) * 10000;

    return currentDate;
}


int DateMethods::getMonthLastDay(int month, int year)
{
    int monthLastDay = 0;

    switch(month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        monthLastDay = 31;
        break;
    case 4: case 6: case 9: case 11:
        monthLastDay = 30;
        break;
    case 2:
        if(isLeapYear(year)) monthLastDay = 29;
        else monthLastDay = 28;
        break;
    default:
        exit(1);
        break;
    }

    return monthLastDay;

}

bool DateMethods::isLeapYear(int year)
{
    if(year % 4 == 0) return true;
    else return false;
}

int DateMethods::getCurrentMonthFirstDayDate()
{
    int currentDate = getCurrentDate();
    if (currentDate % 100 == 1) return currentDate;
    else return currentDate - currentDate % 100 + 1;
}

int DateMethods::getPreviousMonthFirstDayDate()
{
    int currentDate = getCurrentDate(), currentMonth = 0, currentYear = 0;

    currentMonth = (currentDate / 100) % 100;
    currentYear = currentDate / 10000;

    if (currentMonth > 1) return 1 + (currentMonth - 1) * 100 + currentYear * 10000;
    else return 1 + 1200 + (currentYear - 1) * 10000;
}

int DateMethods::getPreviousMonthLastDayDate()
{
    int previousMonthFirstDay = getPreviousMonthFirstDayDate(), previousMonth = 0, year = 0, previousMonthLastDay = 0;

    previousMonth = (previousMonthFirstDay / 100) % 100;
    year = previousMonthFirstDay / 10000;

    previousMonthLastDay = getMonthLastDay(previousMonth, year);

    return previousMonthLastDay + previousMonth * 100 + year * 10000;

}

int DateMethods::getCurrentMonthLastDayDate()
{
    int currentMonthFirstDay = getCurrentMonthFirstDayDate(), currentMonth = 0, currentYear = 0, currentMonthLastDay = 0;

    currentMonth = (currentMonthFirstDay / 100) % 100;
    currentYear = currentMonthFirstDay / 10000;

    currentMonthLastDay = getMonthLastDay(currentMonth, currentYear);

    return currentMonthLastDay + currentMonth * 100 + currentYear * 10000;

}

int DateMethods::convertStringDateToInt(string dateAsString){
    int year = 0, month = 0, day = 0;

    year = stoi(dateAsString.substr(0,4));
    month = stoi(dateAsString.substr(5,2));
    day = stoi(dateAsString.substr(8,2));

    return day + month * 100 + year * 10000;
}

string DateMethods::convertIntDateToStringWithDashes(int dateAsInt){

    string  year = "", month = "", day = "", date = "";
    size_t n_zero = 2;

    day = to_string(dateAsInt % 100);
    month = to_string((dateAsInt / 100) % 100);
    year = to_string(dateAsInt / 10000);

    day = string(n_zero - min(n_zero, day.length()), '0') + day;
    month = string(n_zero - min(n_zero, month.length()), '0') + month;
    year = string(n_zero - min(n_zero, year.length()), '0') + year;

    date = year + "-" + month + "-" + day;

    return date;
}

bool DateMethods::validateDate(string dateAsString){
    int date = convertStringDateToInt(dateAsString), year = 0, month = 0, day = 0;

    day = date % 100;
    month = (date / 100) % 100;
    year = date / 10000;

    if(year > 1999 && year < getCurrentDate() / 10000){
        if(month > 0 && month <= (getCurrentDate() / 100) % 100){
            if(day > 0 && day <= getCurrentMonthLastDayDate() % 100){
                return true;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}
