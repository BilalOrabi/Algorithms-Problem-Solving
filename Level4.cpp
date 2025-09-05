#pragma warning(disable : 4996)

#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream> 
#include <iomanip>
#include <cctype>

using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

struct stPeriodDate
{
    stDate StartDate;
    stDate EndDate;
};

short ReadYear()
{
    short Year = 0;
    cout << "\nEnter the Year: ";
    cin >> Year;

    return Year;
}

short ReadMonth()
{
    short Month = 0;
    cout << "\nEnter the Month: ";
    cin >> Month;

    return Month;

}

short ReadDay()
{
    short Day = 0;
    cout << "\nEnter the Day: ";
    cin >> Day;

    return Day;
}

bool IsLeapYear(short Year)
{
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

short NumberOfDaysInYear(short Year)
{
    return (IsLeapYear(Year)) ? 366 : 365;

}

short NumberOfHoursInYear(short Year)
{
    return NumberOfDaysInYear(Year) * 24;
}

int NumberOfMinutesInYear(short Year)
{
    return NumberOfHoursInYear(Year) * 60;
}

int NumberOfSecondsInYear(short Year)
{
    return NumberOfMinutesInYear(Year) * 60;
}
//================================================================================================
//================================================================================================
//================================================================================================
short NumberOfDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month>12)
        return 0;

    int arrNumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arrNumberOfDays[Month - 1];

}

short NumberOfHoursInMonth(short Month, short Year)
{
    return NumberOfDaysInMonth(Month, Year) * 24;
}

int NumberOfMinutesInMonth(short Month, short Year)
{
    return NumberOfHoursInMonth(Month, Year) * 60;
}

int NumberOfSecondsInMonth(short Month, short Year)
{
    return NumberOfMinutesInMonth(Month, Year) * 60;
}

void PrintDate(short Year, short Month, short Day)
{
    printf("\nDate   :%0*d/%0*d/%d", 2, Day, 2, Month, Year);
}

short DayOfWeekOrder(short Year, short Month, short Day)
{
    int a, y, m;

    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;


}

short DayOfWeekOrder(stDate Date)
{
    return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string DayShortName(short DayOfWeekOrder)
{
    string arrDaysName[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Su" };
    return arrDaysName[DayOfWeekOrder];
}


string MonthShortName(short MonthNumber)
{
    string Months[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

    return (Months[MonthNumber - 1]);
}

void PrintCalanderMonth(short Month, short Year)
{
    int NumberOfDays;

    //Index Of the Day from 0 to 6
    int current = DayOfWeekOrder(Year, Month, 1);

    NumberOfDays = NumberOfDaysInMonth(Year, Month);

    // Print the current month name
    printf("\n_________________%s________________\n\n",
        MonthShortName(Month).c_str());

    // Print the columns
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int i;
    for (i = 0; i < current; i++)
        printf("   ");

    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d", j);

        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
    printf("\n________________________________________\n");


}

short TotalDaysFromBeginningOfYear(short day, short month, short year)
{
    short TotalDays = 0;

    for (int i = 1; i <= month - 1; i++)
    {

        TotalDays += NumberOfDaysInMonth(i, year);
    }
    TotalDays += day;

    return TotalDays;



}

stDate ReadFullDate()
{
    stDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

short ReadDaysToAdd()
{
    short Days;
    cout << "How Many Days To Add?";
    cin >> Days;

    return Days;
}

stDate GetDateFromDayOrderInYear(short DaysOrderInYear, short Year)
{
    stDate Date;
    short TotalDays = DaysOrderInYear;
    short MonthDay = 0;

    Date.Year = Year;
    Date.Month = 1;

    while (true)
    {
        MonthDay = NumberOfDaysInMonth(Date.Month, Year);
        if (TotalDays > MonthDay)
        {
            TotalDays -= MonthDay;
            Date.Month++;
        }
        else
        {
            TotalDays = Date.Day;
            break;
        }
    }
    return Date;
}

stDate DateAddDays(short NumberOfDays, stDate Date)
{
    int RemainingDays = NumberOfDays + TotalDaysFromBeginningOfYear(Date.Day, Date.Month, Date.Year);
    short MonthDay = 0;

    while (true)
    {
        MonthDay = NumberOfDaysInMonth(Date.Month, Date.Year);

        if (RemainingDays > MonthDay)
        {
            RemainingDays -= MonthDay;
            Date.Month++;

            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date2.Year > Date1.Year) ? true : ((Date2.Year == Date1.Year) ? (Date2.Month > Date1.Month ? true : (Date2.Month == Date1.Month ? Date2.Day > Date1.Day:false)) : false);
}

bool IsDate1EqualToDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

bool IsLastDayInMonth(stDate Date)
{
    return Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year);
}

stDate IncressDateByOneDay(stDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Year++;
            Date.Month = 1;
            Date.Day = 1;
        }
        else
        {
            Date.Month++;
            Date.Day = 1;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}

stDate DecreaseDateByOneDay(stDate Date)
{
    if (Date.Day == 1 && Date.Month == 1)
    {
        if (Date.Month == 1)
        {
            Date.Year--;
            Date.Month = 12;
            Date.Day = 31;
        }
        else
        {
            Date.Month--;
            Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
        }
    }
    else
    {
        Date.Day--;
    }




    return Date;
}
//================================================================================================
void SwapDates(stDate& Date1, stDate& Date2)
{
    stDate TempDate;

    TempDate.Day = Date1.Day;
    TempDate.Month = Date1.Month;
    TempDate.Year = Date1.Year;

    Date1.Day = Date2.Day;
    Date1.Month = Date2.Month;
    Date1.Year = Date2.Year;

    Date2.Day = TempDate.Day;
    Date2.Month = TempDate.Month;
    Date2.Year = TempDate.Year;
}

int CalculateDifferenceInDays(stDate Date1, stDate Date2, bool InculdeEndDay = false)
{
    int Days = 0;
    short SwapFlagValue = 1;

    if (!IsDate1BeforeDate2(Date1, Date2))
    {
        SwapDates(Date1, Date2);
        SwapFlagValue = -1;
    }

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncressDateByOneDay(Date1);
    }


    return InculdeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;

}

stDate GetSystemDate()
{
    stDate Date;

    time_t t = time(0);
    tm* now = localtime(&t);

    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;

    return Date;
}
//================================================================================================
stDate IncreaseDateByXDays(int XDays, stDate Date)
{

    for (int i = 1; i <= XDays; i++)
    {
        IncressDateByOneDay(Date);
    }

    return Date;
}

stDate DecreaseDateByXDays(int XDays, stDate Date)
{

    for (int i = 1; i <= XDays; i++)
    {
        DecreaseDateByOneDay(Date);
    }

    return Date;
}

//================================================================================================
stDate IncreaseDateByOneWeek(stDate Date)
{
    for (int i = 1; i <= 7; i++)
    {
        IncressDateByOneDay(Date);
    }

    return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
    for (int i = 1; i <= 7; i++)
    {
        DecreaseDateByOneDay(Date);
    }

    return Date;
}
//================================================================================================
stDate IncreaseDateByXWeeks(int XWeeks, stDate Date)
{
    
    for (int i = 1; i <= XWeeks; i++)
    {
        IncreaseDateByOneWeek(Date);
    }
    return Date;
}

stDate DecreaseDateByXWeeks(int XWeeks, stDate Date)
{
    
    for (int i = 1; i <= XWeeks; i++)
    {
        DecreaseDateByOneWeek(Date);
    }
    return Date;
}

//================================================================================================

stDate IncreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 12)
    {
        Date.Year++;
        Date.Month = 1;
    }
    else
    {
        Date.Month++;
    }
    short NumberOfDaysInCurrntMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

    if (Date.Day > NumberOfDaysInCurrntMonth)
    {
        Date.Day = NumberOfDaysInCurrntMonth;
    }
    return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
    if (Date.Month == 1)
    {
        Date.Year--;
        Date.Month = 12;
    }
    else
    {
        Date.Month--;
    }
    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

//================================================================================================
stDate IncreaseDateByXMonths(int XMonths, stDate Date)
{
    for (int i = 1; i <= XMonths; i++)
    {
        IncreaseDateByOneMonth(Date);
    }
    return Date;
}

stDate DecreaseDateByXMonths(int XMonths, stDate Date)
{
    for (int i = 1; i <= XMonths; i++)
    {
        DecreaseDateByOneMonth(Date);
    }
    return Date;
}
//================================================================================================


stDate IncreaseDateByOneYear(stDate Date)
{
    Date.Year++;
    return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
    Date.Year--;
    return Date;
}
//================================================================================================

stDate IncreaseDateByXYears(int XYears, stDate Date)
{
    for (int i = 1; i <= XYears; i++)
    {
        IncreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXYears(int XYears, stDate Date)
{
    for (int i = 1; i <= XYears; i++)
    {
        DecreaseDateByOneYear(Date);
    }
    return Date;
}

//================================================================================================

stDate IncreaseDateByXYearsFaster(int XYears, stDate Date)
{
    Date.Year += XYears;
    return Date;
}

stDate DecreaseDateByXYearsFaster(int XYears, stDate Date)
{
    Date.Year -= XYears;
    return Date;
}
//================================================================================================

stDate IncreaseDateByOneDecade(stDate Date)
{
    Date.Year += 10;
    return Date;
}

stDate DecreaseDateByOneDecade(stDate Date)
{
    Date.Year -= 10;
    return Date;
}
//================================================================================================

stDate IncreaseDateByXDecade(int XDecade, stDate Date)
{
    for (int i = 1; i <= XDecade * 10; i++)
    {
        IncreaseDateByOneYear(Date);
    }
    return Date;
}

stDate DecreaseDateByXDecade(int XDecade, stDate Date)
{
    for (int i = 1; i <= XDecade * 10; i++)
    {
        DecreaseDateByOneYear(Date);
    }
    return Date;
}

//================================================================================================
stDate IncreaseDateByXDecadeFaster(int XDecade, stDate Date)
{
    Date.Year += (XDecade * 10);
    return Date;
}

stDate DecreaseDateByXDecadeFaster(int XDecade, stDate Date)
{
    Date.Year -= (XDecade * 10);
    return Date;
}
//================================================================================================

stDate IncreaseDateByOneCentury(stDate Date)
{

    Date.Year += 100;
    return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{

    Date.Year -= 100;
    return Date;
}
//================================================================================================
stDate IncreaseDateByOneMillennium(stDate Date)
{
    Date.Year += 1000;
    return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
    Date.Year -= 1000;
    return Date;
}

bool IsEndOfWeek(stDate Date)
{
    return DayOfWeekOrder(Date) == 6;
}

bool IsWeekEnd(stDate Date)
{
    short DayIndex = DayOfWeekOrder(Date);
    return (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay(stDate Date)
{
    return (!IsWeekEnd(Date));
}

short DaysUntilTheEndOfTheWeek(stDate Date)
{
    return 6 - DayOfWeekOrder(Date);
}

short DaysUntilEndOfTheMonth(stDate Date1)
{
    stDate EndOfMonthDate;
    EndOfMonthDate.Day = NumberOfDaysInMonth(Date1.Month, Date1.Year);
    EndOfMonthDate.Month = Date1.Month;
    EndOfMonthDate.Year = Date1.Year;

    return CalculateDifferenceInDays(Date1, EndOfMonthDate, true);

}

short DaysUntilEndOfTheYear(stDate Date1)
{
    stDate EndOfYearDate;
    EndOfYearDate.Day = 31;
    EndOfYearDate.Month = 12;
    EndOfYearDate.Year = Date1.Year;

    return CalculateDifferenceInDays(Date1, EndOfYearDate, true);
}

short CalculateVacationDays(stDate DateFrom, stDate DateTo)
{
    short DayCount = 0;
    while (IsDate1BeforeDate2(DateFrom, DateTo))
    {
        if (IsBusinessDay(DateFrom))
            DayCount++;

        DateFrom = IncressDateByOneDay(DateFrom);

    }
    return DayCount;
}

stDate VacationReturnDate(stDate DateFrom, short VacationDays)
{
    short WeekEndCount = 0;

    while (IsWeekEnd(DateFrom))
    {
        DateFrom = IncressDateByOneDay(DateFrom);
    }

    for (int i = 1; i <= VacationDays + WeekEndCount; i++)
    {
        if (IsWeekEnd(DateFrom))
            WeekEndCount++;

        DateFrom = IncressDateByOneDay(DateFrom);
            
    }

    while (IsWeekEnd(DateFrom))
    {
        DateFrom = IncressDateByOneDay(DateFrom);
    }


    return DateFrom;
}


//Date1 2/3/2023
//Date2 1/2/2022

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualToDate2(Date1, Date2));
}

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;
        
    if (IsDate1EqualToDate2(Date1, Date2))
        return enDateCompare::Equal;

    return enDateCompare::After;
}

stPeriodDate ReadPeroid()
{
    stPeriodDate Period;
    cout << "Enter Start Date:\n";
    Period.StartDate = ReadFullDate();
    cout << "Enter End Date:\n";
    Period.EndDate = ReadFullDate();

    return Period;
}

bool IsOverlapPeriods(stPeriodDate Period1, stPeriodDate Period2)
{
    if (CompareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before || CompareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After)
        return false;
    else
        return true;
}

int CalculatePeriodLengthInDays(stPeriodDate Period1, bool IncludeEndDay = false)
{
    return CalculateDifferenceInDays(Period1.StartDate, Period1.EndDate, IncludeEndDay);
}

bool IsDateWithinPeriod(stDate Date, stPeriodDate Period1)
{
    return !(CompareDates(Date, Period1.StartDate) == enDateCompare::Before || CompareDates(Date, Period1.EndDate) == enDateCompare::After);
}

int CountOverlapDays(stPeriodDate Period1, stPeriodDate Period2)
{
    int Period1Length = CalculatePeriodLengthInDays(Period1, true);
    int Period2Length = CalculatePeriodLengthInDays(Period2, true);
    int OverlapDaysCount = 0;

    if (!IsOverlapPeriods(Period1, Period2))
        return 0;

    
    
        if (Period1Length > Period2Length)
        {
            while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
            {
                if (IsDateWithinPeriod(Period1.StartDate, Period2))
                    OverlapDaysCount++;


                Period1.StartDate = IncressDateByOneDay(Period1.StartDate);
            }
            
            
        }
        else if (Period2Length > Period1Length)
        {
            while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
            {
                if (IsDateWithinPeriod(Period2.StartDate, Period1))
                    OverlapDaysCount++;


                Period2.StartDate = IncressDateByOneDay(Period2.StartDate);
            }
            
            
        }
        
    
    return OverlapDaysCount;

}

bool ValidateDate(stDate Date)
{
    if (Date.Month > 12 || Date.Month < 1)
        return false;
    if (Date.Day > 31 || Date.Day < 1)
        return false;
    if (Date.Month == 2)
    {
        if (IsLeapYear(Date.Year))
        {
            if (Date.Day > 29)
                return false;
        }
        else 
        {
            if (Date.Day > 28)
                return false;
        }
    }




    short DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

    if (Date.Day > DaysInMonth)
        return false;

    // if you reach here return true
    return true;
    
            
        
    

}

vector <string> SplitFunction(string S1, string Delimiter)
{
    short pos = 0;
    string sWord = "";
    vector<string> vSplitWords;

    while ((pos = S1.find(Delimiter)) != S1.npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vSplitWords.push_back(sWord);
        }
        S1.erase(0, pos + Delimiter.length());
    }
    if (S1 != "")
    {
        vSplitWords.push_back(S1);
    }
    return vSplitWords;
}

string ReadDateAsString()
{
    string Datestring;
    cout << "Please Enter Date dd/mm/yyyy? ";
    getline(cin >> ws, Datestring);

    return Datestring;
}
stDate StringToDate(string DateString)
{
    stDate Date1;
    vector<string> vDate;
    vDate = SplitFunction(DateString, "/");

    Date1.Day = stoi(vDate[0]);
    Date1.Month = stoi(vDate[1]);
    Date1.Year = stoi(vDate[2]);

    return Date1;

}

string DateToString(stDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

string ReplaceWordsUsingBuiltInFun(string S1, string StringToreplace, string sReplace)
{

    short pos = S1.find(StringToreplace);

    while (pos != S1.npos)
    {
        S1.replace(pos, StringToreplace.length(), sReplace);
        pos = S1.find(StringToreplace);
    }

    return S1;

}

string FormatDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
    string FormatedDateString = "";
    FormatedDateString = ReplaceWordsUsingBuiltInFun(DateFormat, "dd", to_string(Date.Day));
    FormatedDateString = ReplaceWordsUsingBuiltInFun(FormatedDateString, "mm", to_string(Date.Month));
    FormatedDateString = ReplaceWordsUsingBuiltInFun(FormatedDateString, "yyyy", to_string(Date.Year));
    
    return FormatedDateString;
}

int main()
{
    short VacationDays = 0;
    stPeriodDate Period1 = ReadPeroid();
    //stDate Date1 = ReadFullDate();
    cout << endl;

   /* cout << "how many vacations? ";
    cin >> VacationDays;*/

    stDate Date2 = ReadFullDate();

    

    system("pause>0");

    return 0;
}












