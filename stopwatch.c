#include <stdio.h>  
#include <conio.h>  
#include <stdlib.h>
//#include <unistd.h>
//#include <windows.h>
#include <time.h>

int hour=0,min=0,sec=0,flag=1,ms=0,count=1;



void content() //this function prints the contents has to be printed
{
    system("cls");
    printf("=========================>STOP WATCH<=========================\n\n\n");
    printf("--------------------------------------------------\n");
    printf("|1-->start/stop : 2-->reset : 3-->laps : 4-->exit|\n");
    printf("--------------------------------------------------\n\n\nHH : MM : SS : MS\n\n");
}




void delay(int ms) //this function is used to timer
{
    time_t stop=clock()+ms;
    while(clock()<stop);
}




void usecase()     //this function is used to choose the options like start,stop,reset
{
    switch(getch())
    {
        case 49:if(flag==0)flag=1;
                else flag=0; 
               break;
        case 50:hour=min=sec=ms=0;
               flag=1;
               content();
               break;
        case 51:if(flag==0)
                {
                    printf("\rTime laps %d  ===> %02d : %02d : %02d : %02d\n ",count++,hour,min,sec,ms);
                }
                break;
        case 52:exit(0);
    }
}




void print()      //this function is used to print the time:
{
    printf("\r%02d : %02d : %02d : %02d ",hour,min,sec,ms);
    fflush(stdout);
}



void counter()  //updates the time 
{
    while(!kbhit() && flag==0)  //if we didnt use kbhit() in this while loop became infinate loop
    {  
        if(ms==99)
        {
            if(sec==59)        //code for time updation similar to our clocks
            {                          
                if(min==59)
                {
                    if(hour==23) hour=0;
                    else hour+=1;
                    min=0;
                }
                else min+=1;
                sec=0;
            }
            else sec+=1;       
            ms=0;
        }
        else ms+=1;
        delay(5);
        print();
    }
    if(flag==1) print();
    usecase();
   
}




int main()  //main function
{  
    content();
    
   while(1)
   {
    counter();
   }
   return 0;
}