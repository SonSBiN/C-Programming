// Daytab array
#include<stdio.h>

static char daytab[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
			     {0, 31 ,29, 31, 30, 31, 31, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day)
{
	int i, leap;
// Determine whether it is a leap year or not
	leap = year%4 == 0 && year% 100 != 0 || year%400 == 0;
// Add the days up to the month to 'day'
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}
void month_day(int year, int yearday, int*pmonth, int *pday)
{
	int i, leap;
// Determine whether it is a leap year or not
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
// if 'yearday' is less than the corresponding index of 'daytab' it is the number of days in the month.
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}

int main(void)
{
	int dmonth;
	int dday;
//print Day of year and Month_Day
	printf("Day of year\n");
	printf("2021 4 30 : %d\n",day_of_year(2021,4,30));
	printf("2014 4 16 : %d\n",day_of_year(2020,4,16));
	putchar('\n');
	printf("Month_day\n");
	month_day(2021,200,&dmonth,&dday);
	printf("2021 200 : month:%d day:%d\n",dmonth,dday);
	month_day(2000,300,&dmonth,&dday);
	printf("2000 300 : month:%d day:%d\n",dmonth,dday);
			
	

	return 0;
}
