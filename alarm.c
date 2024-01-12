#include <stdio.h>
#include <conio.h> //for using of kbhit() 
#include <time.h> //for using of world clock
#include <windows.h> //for using of beep sound
#include <stdlib.h> //for using clear screen
int hour=0,min=0,flag=1;
int umin=0,uhour=0;
char use[50];


void alarm()
{
  fflush(stdout);
  system("cls");
  printf("\n*******TIME'S UP!!********\n\n");
  printf("------>%s<-----\n\n",use);
  printf("press anything to stop alarm");
  while(kbhit()==0)
  {
    Beep(850,700);
    Beep(900,800);
    Beep(1050,900);
    Beep(1100,1000);
    Beep(1250,1100);
    Beep(1300,1200);
    Beep(1450,1300);
    Beep(1500,1400);
  }
  exit(1);

}



void checker()
{
  time_t now = time(NULL);
  struct tm *tm = localtime(&now);
  
  if (hour==tm->tm_hour)
  {
    if(min==tm->tm_min)
    {
      if(flag==0)  alarm();
      else
      {
        uhour=24;
        umin=0;
      } 
    }
    else if(min>tm->tm_min)
    {
      flag=0;
      uhour=0;
      umin=min-tm->tm_min;
    }
    else
    {
      uhour=23;
      umin=60-(tm->tm_min-min);
    }
  }
  else if(hour>tm->tm_hour) 
  {
    if(min<tm->tm_min)
    {
      uhour=(hour-tm->tm_hour)-1;
      umin=60-(tm->tm_min-min);
    }
    else 
    {
      uhour=hour-tm->tm_hour;
      umin=min-tm->tm_min;
    }
  }
  else 
  {
    uhour=24-(tm->tm_hour-hour);
    if(min==tm->tm_min)
    {
      umin=0;
    }
    else if(min>tm->tm_min)
    { 
      umin=min-tm->tm_min;
    }
    else 
    {
      uhour--;
      umin=60-(tm->tm_min-min);
    }
  }
  printf("\rin %d hours, %d minutes",uhour,umin); 
}



void set()
{
  printf("set your alarm ==>\n");
  printf("hour:");
  scanf("%d",&hour);
  if(hour<0 || hour>23)
  {
    printf("invalid time:");
    exit(1);
  }
  printf("minute:");
  scanf("%d",&min); 
  if(min<0 || min>59)
  {
    printf("invalid time:");
    exit(1);
  }
  fflush(stdin);
  printf("Enter any text:");
  gets(use);
  
}




void print()
{
  system("cls");
  printf("=============================>ALARM<==============================\n\n");
  printf("\t %02d : %02d\n\n ",hour,min);
}



int main()
{
  system("cls");
  set();
  print();
  while(1)
  {
    checker();
  }
  return 0;
}


