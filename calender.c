#include<stdio.h>
#include<stdlib.h>

int get_1st_weekday(int year){
    int day;
    day=(((year-1)*365)+((year-1)/4) - ((year-1)/100) + ((year)/400)+1) %7;
    return day;
}

int main()
{
    system("Color 003");
    int year,day,daysinmonth,weekday=0,startingday;
    printf("\nEnter the year\n");
    scanf("%d",&year);

    char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if((year%4==0 && year%100!=0) || year%400==0)
    monthDay[1]=29;
    startingday=get_1st_weekday(year);

    for(int month=0;month<= 11;month++)
    {
        daysinmonth=monthDay[month];

        
        printf("\n\n-------------------%s--------------------\n\n",month[months]);
        printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        for(weekday=0;weekday<startingday;weekday++)
        printf("     ");



        for(day=1;day<=daysinmonth;day++){
            printf("%5d",day);
            if(++weekday>6){
            printf("\n");
            weekday=0;
            }   
            startingday=weekday;
        
        }

    
    }
}