#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int CompBoard[10][10]={0};
int CompShips[10][10]={0};
int PlayBoard[10][10]={0};
int PlayShips[10][10]={0};
int Play2Board[10][10]={0};
int Play2Ships[10][10]={0};
void SetCompBoard()
{
    int i;
    srand(time(0));
    for(i=0; i<5; i++)
    {
        int g,h;
        g=rand()%5;
        h=rand()%5;
        CompShips[g][h]=1;
    }
}
void SetPlayBoard()
{
    int x, y, m;
    for(m=0; m<5; m++)
    {
    printf("Enter coordinates of ship %d:",m+1);
    scanf("%d,%d",&x,&y);
    PlayShips[x][y]=1;
    }
    system("cls");
}
void SetPlay2Board()
{
    int x, y, m;
    for(m=0; m<5; m++)
    {
    printf("Enter coordinates of ship %d:",m+1);
    scanf("%d,%d",&x,&y);
    Play2Ships[x][y]=1;
    }
    system("cls");
}
void displayCompBoard(){
int row, column;

        printf("  0 1 2 3 4\n\n");

    for(row=0; row<5; row++)
    {
        printf("%d",row);
        for(column=0; column<5; column++)
        {
            if(CompBoard[row][column]==0)
                printf(" ~");
            else if(CompBoard[row][column]==-1)
                printf(" -");
            else
                printf(" *");
        }
        printf("\n");
    }
}
void displayPlayBoard(){
int row, column;

        printf("  0 1 2 3 4\n\n");

    for(row=0; row<5; row++)
    {
        printf("%d",row);
        for(column=0; column<5; column++)
        {
            if(PlayBoard[row][column]==0)
                printf(" ~");
            else if(PlayBoard[row][column]==-1)
                printf(" -");
            else
                printf(" *");
        }
        printf("\n");
    }
}
void displayPlay2Board(){
int row, column;

        printf("  0 1 2 3 4\n\n");

    for(row=0; row<5; row++)
    {
        printf("%d",row);
        for(column=0; column<5; column++)
        {
            if(Play2Board[row][column]==0)
                printf(" ~");
            else if(Play2Board[row][column]==-1)
                printf(" -");
            else
                printf(" *");
        }
        printf("\n");
    }
}
int VsHuman()
{
int s=0, i,n;
    char difficulty;
    printf("Select difficulty(E,M,H):");
    scanf("%s",&difficulty);
    while(s=0){
    switch(difficulty)
   {
       case 'e':
       case 'E':    n=3;
                    s=1;
                    break;
       case 'm':
       case 'M':    n=5;
                    s=1;
                    break;
       case 'h':
       case 'H':    n=7;
                    s=1;
                    break;
        default:    printf("invalid");
                    s=0;
                    break;

   }
    }
    system("cls");
                    printf("player1 set your fleet");

                    SetPlayBoard();
                    //displayPlayBoard();
                    printf("player2 set your fleet");
                    SetPlay2Board();
                    //displayPlay2Board();
                    int Pcount=5 ,Ccount=5, x, y;
                    while(Pcount!=0&&Ccount!=0)
                    {
                    //system("cls");
                    printf("Player1 enter the coordinate of enemy fleet");
                    scanf("%d,%d",&x,&y);
                    //system("cls");
                    if(Play2Ships[x][y]==1){
                    printf("HIT!!!\n");
                    Play2Board[x][y]=1;
                    Ccount--;
                    }
                    else
                        Play2Board[x][y]= -1;
                    printf("player2board\n");
                    displayPlay2Board();

                    //system("cls");
                    printf("player 2'turn:\n");
                    printf("Player2 enter the coordinate of enemy fleet");
                    scanf("%d,%d",&x,&y);
                    if(PlayShips[x][y]==1 && PlayBoard[x][y]==0)
                    {
                        printf("HIT!!!\n");
                        PlayBoard[x][y]=1;
                        Pcount--;
                    }
                    else
                        PlayBoard[x][y]=-1;
                    printf("player1 board\n");
                    displayPlayBoard();

                    }

                 if(Pcount==0)
    {
        printf("player2 wins !!!");
        return 0;
    }
    else
    {
        printf("player1 wins !!!");
        return 1;
    }
}
int VsComp()
{
    int s=0, i,n;
    char difficulty;
    printf("Select difficulty(E,M,H):");
    scanf("%s",&difficulty);
    while(s=0){
    switch(difficulty)
   {
       case 'e':
       case 'E':    n=3;
                    s=1;
                    break;
       case 'm':
       case 'M':    n=5;
                    s=1;
                    break;
       case 'h':
       case 'H':    n=7;
                    s=1;
                    break;
        default:    printf("invalid");
                    s=0;
                    break;

   }
    }
    system("cls");
                    SetCompBoard();
                    SetPlayBoard();
                    int Pcount =5 ,Ccount=5, x, y;
                    while(Pcount!=0&&Ccount!=0)
                    {
                    printf("enter the coordinate of enemy fleet");
                    scanf("%d,%d",&x,&y);
                    system("cls");
                    if(CompShips[x][y]==1){
                    printf("missile hit!!!!!!\n");
                    CompBoard[x][y]=1;
                    Ccount--;
                    }
                    else
                        CompBoard[x][y]= -1;
                    displayCompBoard();
                    printf("Computer'turn:\n");
                    srand(time(0));
                    x=rand()%5;
                    y=rand()%5;
                    if(PlayShips[x][y]==1 && PlayBoard[x][y]==0)
                    {
                        printf("you have been hit\n");
                        PlayBoard[x][y]=1;
                        Pcount--;
                    }
                    else
                        PlayBoard[x][y]=-1;
                    displayPlayBoard();
                    }

                 if(Pcount==0)
    {
        printf("You lose!!!");
        return 0;
    }
    else
    {
        printf("You win!!");
        return 1;
    }
}

int Instructions()
{
    int x;
    printf("Vs Comp:\n1. First place your ships.\n2.Then enter co-ordinates to attack\n\nVs Human\n1. Both players place ships on their respective boards\n2.Then enter coordinates one-by-one to attack each other.\n\n\n");
    printf("1.Play game\n2.Exit\n");
    printf("Enter choice");
    scanf("%d",&x);
    return x;
}
int main()
{
    int ch, mode, result=-1;
    printf("**Welcome to Battleships**\n\n\n");
    printf("Menu:\n\n1.Play game\n2.How to play\n3.Exit\n");
    printf("Enter choice");
    scanf("%d",&ch);
    system("cls");
    while(result==-1)
    {
        switch(ch)
        {
        case 1: printf("Choose mode\n\n1. vs computer\n2. vs human\nEnter choice");
                scanf("%d",&mode);
                system("cls");
                if(mode==1)
                    result = VsComp();
                else if(mode==2)
                    result = VsHuman();
                else
                    printf("Invalid input");
                break;

        case 2: system("cls");
                int x;
                x=Instructions();
                ch = x;
                system("cls");
                break;
        case 3: return 0;
        }
    }
}
