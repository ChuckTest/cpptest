#include <iostream>
#include <iomanip>
#include <sstream>
#include <windows.h>

// Date structure
struct Date {
    int year;
    int month;
    int day;
};

// Check if a year is a leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Get the number of days in a specific month
int getDaysInMonth(int year, int month) {
    const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysInMonth[month];
}

// Format date as string YYYY-MM-DD
std::string formatDate(const Date& date) {
    std::ostringstream oss;
    oss << date.year << "-"
        << std::setw(2) << std::setfill('0') << date.month << "-"
        << std::setw(2) << std::setfill('0') << date.day;
    return oss.str();
}

// Get current system date (using a simple method)
Date getCurrentDate() {
    // Note: This is for demonstration purposes only. In a real application,
    // you should use a system API to get the actual current date
    // Here we assume the current date is 2025-04-02
    Date today;
    today.year = 2025;
    today.month = 12;
    today.day = 27;
    return today;
}

// Calculate the number of days between two dates
int daysBetween(const Date& date1, const Date& date2) {
    // Convert both dates to days since January 1, year 1
    auto dateToDays = [](const Date& d) {
        int days = d.day;
        for (int m = 1; m < d.month; ++m) {
            days += getDaysInMonth(d.year, m);
        }
        
        int years = d.year - 1;
        return days + 365 * years + years / 4 - years / 100 + years / 400;
    };
    
    return dateToDays(date2) - dateToDays(date1);
}

// Add days to a date
Date addDays(Date date, int days) {
    while (days > 0) {
        int daysInCurrentMonth = getDaysInMonth(date.year, date.month);
        if (date.day + days <= daysInCurrentMonth) {
            date.day += days;
            break;
        } else {
            days -= (daysInCurrentMonth - date.day + 1);
            date.day = 1;
            if (date.month == 12) {
                date.month = 1;
                date.year++;
            } else {
                date.month++;
            }
        }
    }
    return date;
}

// Print weekly date ranges
void printWeeklyDateRanges() {
    // Get current date
    Date today = getCurrentDate();
    
    // Define start date: September 7, 2025
    Date startOfFirstWeek = {2025, 9, 7};
    
    // Calculate current week number
    int weekNumber;
    if (daysBetween(startOfFirstWeek, today) < 0) {
        weekNumber = 0; // If current date is before start date
    } else {
        int daysDifference = daysBetween(startOfFirstWeek, today);
        weekNumber = (daysDifference / 7) + 1;
    }
    
    std::cout << "Current date: " << formatDate(today) << std::endl;
    std::cout << "Today is week " << weekNumber << std::endl;
    std::cout << std::endl;
    std::cout << "Weekly Date Ranges from September 7, 2025:" << std::endl;
    std::cout << "============================================" << std::endl;
    
    // Calculate and print each week
    Date weekStart = startOfFirstWeek;
    int currentWeekCount = 1;
    
    while (daysBetween(weekStart, today) >= 0) {
        Date weekEnd = addDays(weekStart, 6);
        
        std::string currentWeekIndicator = (currentWeekCount == weekNumber) ? " ← CURRENT WEEK" : "";
        
        std::cout << "Week " << std::setw(2) << std::setfill('0') << currentWeekCount << ": " 
                 << formatDate(weekStart) << " to " 
                 << formatDate(weekEnd) << currentWeekIndicator << std::endl;
        
        weekStart = addDays(weekStart, 7);  // Move to next week
        currentWeekCount++;
    }
}

// Original test function implemented in C++
void test2025_0402_001() {
    // Get current date
    Date today = getCurrentDate();
    
    // Define start date: September 7, 2025
    Date startOfFirstWeek = {2025, 9, 7};
    
    // Calculate current week number
    int weekNumber;
    if (daysBetween(startOfFirstWeek, today) < 0) {
        weekNumber = 0; // If current date is before start date
    } else {
        int daysDifference = daysBetween(startOfFirstWeek, today);
        weekNumber = (daysDifference / 7) + 1;
    }
    
    std::cout << "Today is week " << weekNumber << std::endl;
}

int main() {
    SetConsoleOutputCP(65001);  // 控制台输出 UTF-8
    printWeeklyDateRanges();
    return 0;
}