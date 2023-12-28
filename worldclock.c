#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>



void printdatetime() //function to print local time and date
{
  system("cls");
  time_t now=time(NULL);  
  struct tm *time=localtime(&now);
  
  printf("-----DATE-----\n");
  printf("%02d : %02d : %02d\n",time->tm_mday,time->tm_mon+1,time->tm_year+1900);
  
  
  printf("\n");
  
  
  printf("--LOCAL TIME--\n");
  printf(" %02d : %02d : %02d ",time->tm_hour,time->tm_min,time->tm_sec);
  fflush(stdout);
  sleep(1);
}



int main() //main function
{
  //
  //printf("=========================>WORLD CLOCK<=========================\n\n\n");
  while(1)
  {
    printdatetime();  
  }
  
}




//use of \r
//asctime(date) to get-----> day month date time[hh:min:sec] year
//*** struct tm is a structure which consists of many methods as mentioned below:***
    /*tm_hour--> returns present hour-------it has range from 0 to 23
      tm_min---> returns present minute-----it has range from 0 to 59
      tm-sec---> returns present second-----it has range from 0 to 59 
      tm_mday--> returns present date-------it has range from 1 to 31
      tm_mon---> returns present month------it has range form 0 to 11----so we have to add 1 
      tm_year--> returns present year-------its starts form 1900---------the reason we added 1900  */