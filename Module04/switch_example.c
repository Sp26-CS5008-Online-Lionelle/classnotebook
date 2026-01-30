/**
Example code to demonstrate switch statements in C
Includes example where there is no break
*/

#include <stdio.h>
#include <stdlib.h>

// enum for days of the week

enum Day {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
};

// case where every case has a break
void print_day_message(enum Day day) {
    switch(day) {
        case SUNDAY:
            printf("It's Sunday, time to relax!\n");
            break;
        case MONDAY:
            printf("It's Monday, back to work!\n");
            break;
        case TUESDAY:
            printf("It's Tuesday, keep going!\n");
            break;
        case WEDNESDAY:
            printf("It's Wednesday, halfway there!\n");
            break;
        case THURSDAY:
            printf("It's Thursday, almost the weekend!\n");
            break;
        case FRIDAY:
            printf("It's Friday, the weekend is near!\n");
            break;
        case SATURDAY:
            printf("It's Saturday, enjoy your day!\n");
            break;
        default:
            printf("Invalid day!\n");
    }
}

void print_day_type(enum Day day) {
    switch(day) {
        case SUNDAY:
        case SATURDAY:
            printf("Its the weekend!\n");
            break;
        case MONDAY:
            printf("Oh, no - monday!");
        case TUESDAY:
        case WEDNESDAY:
        case THURSDAY:
        case FRIDAY:
            printf("Its the week day!\n");
            break;
        default:
            printf("Invalid day!\n");
    }
}

/**
Prompts for the year-month-day, returns an array with each as a number */
int* get_calendar_day() {
    int * date = malloc(3 * sizeof(int));
    printf("Enter a date (year-month-day): ");
    scanf("%d-%d-%d", &date[0], &date[1], &date[2]);
    return date;
}

/*
 * Zeller's Congruence - calculates day of week for any date
 *
 * f = (q + 13(m+1)/5 + k + k/4 + j/4 + 5j) mod 7
 *
 * Where:
 *   f = day of week (0=Sat, 1=Sun, 2=Mon, 3=Tue, 4=Wed, 5=Thu, 6=Fri)
 *   q = day of month
 *   m = month (3=Mar, 4=Apr, ... 12=Dec, 13=Jan, 14=Feb)
 *       (Jan/Feb are treated as months 13/14 of the previous year)
 *   k = year of century (year % 100)
 *   j = century (year / 100)
 *
 * Note: Uses +5j instead of -2j to avoid negative modulo issues in C
 */
int calculate_day_of_week(int year, int month, int day) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int k = year % 100;
    int j = year / 100;
    int f = day + (13 * (month + 1)) / 5 + k + (k / 4) + (j / 4) + (5 * j);
    return f % 7;
}


// main that asks for someone to give a date in year-month-day, it calculates the
// day of the week, and prints both messages
int main() {
    int* date = get_calendar_day();
    int day_of_week = calculate_day_of_week(date[0], date[1], date[2]);
    print_day_message(day_of_week);
    print_day_type(day_of_week);
    free(date);
    return 0;
}
