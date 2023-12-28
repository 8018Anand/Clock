#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
int hour=0,min=0,sec=0,thour=0,tmin=0,tsec=0,flag=1,total;


void estimate(int secs) //this function is used to print the line of estimated time 
{
  time_t now=time(NULL);
  now+=secs;
  struct tm *time = localtime(&now);
  printf("--------estimated time-->%02d : %02d : %02d--------",time->tm_hour,time->tm_min,time->tm_sec);
}

void content() //this function is used to print the content
{
  system("cls");
  printf("=========================>TIMER<=========================\n\n\n");
  printf("---------------------------------------------\n");
  printf("|1-->start/stop  :  2-->restart : 3-->Exit  |\n");
  printf("---------------------------------------------\n\n");
  estimate(total);
  printf("\n\n");
}

void usecase() //this function is used as options selector
{
  switch(getch())
  {
    case 49:if(flag==0) flag=1;
           else flag=0;
           break;
    case 50:thour=hour;
           tmin=min;
           tsec=sec;
           content();
           break;
    case 51:exit(1);
  }
}


void delay(int ms) //this function is used as timer 
{
  time_t stop=ms+clock();
  while(stop>clock());
}


void print() //this function prints the time 
{
  
  printf("\r%02d : %02d : %02d",thour,tmin,tsec);
  fflush(stdout);
}

void alarm() //this functio used as alarm when time is up
{
  
    
    fflush(stdout);
    printf("\n*******TIME'S UP!!********\n\n");
    printf("press anything to press");
    while(kbhit()==0)
    {
      Beep(350,500);
      Beep(400,500);
      Beep(450,500);
      Beep(500,500);
      Beep(550,500);
      Beep(600,500);
      Beep(650,500);
      Beep(700,500);
    }
    exit(1);
    

}


int counter()   //this function is used to update the time
{
  while(!kbhit() && flag==0)
  {
    print();
    if(tsec==0)
    {
      if(tmin==0)
      {
        if(thour!=0)
        {
          delay(1000);
          --thour;
          tmin=59;
        }
        else alarm();
      }
      else 
      {
        delay(1000);
        --tmin;
        tsec=59;
      }
    }
    else 
    {
      tsec-=1;
      delay(1000);
      
    }
  }
  if(flag==1) print();
  usecase();
}


void set()
{
  printf("set your timer-->\n");
  printf("hour:");
  scanf("%d",&hour);
  if(hour<0||hour>23)
  {
    printf("invalid input! Please enter a second in between 0 and 23.\n");
    exit(1);

  }
  thour=hour;
  printf("minute:");
  scanf("%d",&min);
  if(min<0||min>59)
  {
    printf("Invalid input! Please enter second in  between 0 and 59.\n");
    exit(1);
  }
  tmin=min;
  printf("second:");
  scanf("%d",&sec);
  if(sec<0 || sec>59)
  {
    printf("Invalid input! Please enter second in between o to 59.\n");
    exit(1);
  }
  tsec=sec;
}


void main() //main function
{
  system("cls");
  set();

  total=(hour*60*60)+(min*60)+sec;

  content();
  
  while(1)
  {
    counter();
  }
  
}

//problm-1:error in seconds not printing 00

