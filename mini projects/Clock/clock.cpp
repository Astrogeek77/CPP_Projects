#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

int main()
{
    //getting local time
    time_t t = time(NULL);
    tm *timePtr = localtime(&t);
    //store local time in variables
    int sec = (timePtr->tm_sec);
    int min = (timePtr->tm_min);
    int hours = (timePtr->tm_hour);
    int year = (timePtr->tm_year + 1900);
    int date = (timePtr->tm_mday);
    string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string month = months[timePtr->tm_mon];
    string weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    string weekday = weekdays[timePtr->tm_wday];
    int days = 365 - (timePtr->tm_yday);
    string timestr;
    //convert time to 12 hrs format
    if (hours > 12)
    {
        hours = hours % 12;
        timestr = "PM";
    }
    else
    {
        timestr = "AM";
    }

    while (true)
    {
        system("cls");
        cout << "\n\t\t    Indian Clock Local time" << endl;
        cout << "\t\t-------------------------------" << endl;
        cout << "\t\t" << hours << " : " << min << " : " << sec << " " << timestr << "\t\t" << endl;
        cout << "\t\tDay: " << weekday << "\n\t\tDate: " << date << " " << month << ", " << year << "\t\t" << endl;
        cout << "\t\t" << days << " days remain in this year." << endl;
        cout << "\t\t-------------------------------" << endl;

        sec++;
        if (sec > 59)
        {
            sec = 0;
            min++;
        }

        if (min > 59)
        {
            min = 0;
            hours++;
        }

        if (hours > 12)
        {
            hours = 1;
        }

        Sleep(1000);
    }

    return 0;
}