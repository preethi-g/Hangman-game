#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include"words.c"
#include<windows.h>
#include<string.h>
void gotoxy(int x,int y)
{
    COORD p;
    p.X=x;
    p.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}
void welcome()
{
    gotoxy(30,2);
    printf("\t\twelcome to hangman game...have fun with words\n");
    printf("\tpress any key to continue..\n");
    getch();
    printf("\t----INSTRUCTIONS!-----\n\n");
    printf("\n\t->you will be given a word to guess.\n\t->And you are provided with 6 chances.\n\t->You have to say a letter and if it is available in the word ,it is filled in the blank.");
    printf("\n\t->Else your chance will be reduced\n\t->You should not repeat the letters\n\t->If you fill the word before you lose all your chances,you will be won!\n\t->Else you lose the game");
    printf("\n\tpress any key to continue");
    getch();
    system("cls");
}
void box()
{
    int b;
    for(b=87;b<110;b++)
    {
        gotoxy(b,27);
        printf("$");
    }
    for(b=27;b<=40;b++)
    {
        gotoxy(87,b);
        printf("$");
    }
    for(b=87;b<110;b++)
    {
       gotoxy(b,40);
       printf("$");
    }
    for(b=27;b<=40;b++)
    {
        gotoxy(110,b);
        printf("$");
    }
}
void display(int c)
{
    int ind;
    fflush(stdin);
     switch(c)
     {

     case 0:
        gotoxy(90,30);
        printf("\t||===== ");
        gotoxy(90,31);
        printf("\t||    | ");
        gotoxy(90,32);
        printf("\t||   %cO/",'\\');
        gotoxy(90,33);
        printf("\t||    | ");
        gotoxy(90,34);
        printf("\t||   / %c",'\\');
        gotoxy(90,35);
        printf("\t||      ");
        break;
     case 1:
        gotoxy(90,34);
        printf("\t||     %c",'\\');
        break;
     case 2:
        gotoxy(90,33);
        printf("\t||    | ");
        break;
     case 3:
        gotoxy(90,32);
        printf("\t||   %cO/",'\\');
        break;
     case 4:
        gotoxy(90,32);
        printf("\t||   %cO ",'\\');
        break;
     case 5:
        gotoxy(90,30);
        printf("\t||===== ");
        gotoxy(90,31);
        printf("\t||    | ");
        gotoxy(90,32);
        printf("\t||    O ");
        gotoxy(90,33);
        printf("\t||      ");
        gotoxy(90,34);
        printf("\t||      ");
        gotoxy(90,35);
        printf("\t||      ");
        break;
      }//end of switch-case
 }

int random()
{
   srand(time(NULL)) ;
   int number=rand()%20;
   return number;
}
void play(char *qs)
{
    int i,a=10;
    int len=strlen(qs),flag=0,chance=6,count=0;
    char option[10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char letter;
    display(chance);
    gotoxy(7,a);
    printf("The word is\n\n");
    printf("\t\t");
    a+=3;
    for(i=0;i<len;i++)
    {
        printf("- ");
    }
    while((chance>=0)&&(count<len)){
    gotoxy(7,a);
    printf("Say your letter");
    a+=2;
    letter=getch();
    //printf("\n");
    for(i=0;i<len;i++)
    {
        if(letter==qs[i])
        {
            option[i]=letter;
            flag=1;
            count++;
        }
    }
    if(flag==0){
            chance-=1;
            if(chance==5)
            {
                box();
            }
            if(chance<0)
            {
                system("cls");
                box();
                display(0);
                gotoxy(90,36);
                printf("------------");
                gotoxy(90,37);
                printf("[H.A.N.G.E.D]");
                gotoxy(80,15);
                printf("########################################");
                gotoxy(88,18);
                printf("GAME OVER!!!");
                gotoxy(88,20);
                printf("the word is %s",qs);
                gotoxy(80,23);
                printf("#########################################");
                break;
            }
            else
            {
                gotoxy(7,a);
                printf("oops! I am afraid that is incorrect");
                a++;
                gotoxy(7,a);
                printf("you have %d trys left",chance);
                a+=2;
                display(chance);
            }
    }
    else{
        printf("\t\t");
        gotoxy(7,a);
        a+=2;
        for(i=0;i<len;i++)
        {
            printf("%c ",option[i]);
        }
        gotoxy(7,a);
        a+=4;
        for(i=0;i<len;i++)
        {
            printf("- ");
        }
        if(count==len)
        {
            system("cls");
            gotoxy(80,15);
            printf("######################################");
            gotoxy(90,17);
            printf("\tyou won!\n");
            gotoxy(80,20);
            printf("######################################");
            break;
        }
        flag=0;
    }
    }
}
int main()
{
    int n;
    char ques[10];
    welcome();
    n=random();
    char *playWord=word(n);
    play(playWord);
    return 0;
}
