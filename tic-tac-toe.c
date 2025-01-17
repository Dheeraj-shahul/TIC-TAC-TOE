#include<stdio.h>
#include<stdlib.h>
#define max_length 100

typedef struct player{
    char name[max_length];
    int id;
    int arr[3][3];
}player;

void converter(int c, int *a, int *b) 
{
    c--;
    if (c >= 0 && c < 9) 
    { 
        *a = c / 3; 
        *b = c % 3; 
    } 
}

int haswon(int arr[3][3])
{
    if((arr[0][0]+arr[0][1]+arr[0][2])==3){return 1;}
    if((arr[1][0]+arr[1][1]+arr[1][2])==3){return 1;}
    if((arr[2][0]+arr[2][1]+arr[2][2])==3){return 1;}
    if((arr[0][0]+arr[1][0]+arr[2][0])==3){return 1;}
    if((arr[0][1]+arr[1][1]+arr[2][1])==3){return 1;}
    if((arr[0][2]+arr[1][2]+arr[2][2])==3){return 1;}
    if((arr[0][0]+arr[1][1]+arr[2][2])==3){return 1;}
    if((arr[0][2]+arr[1][1]+arr[2][0])==3){return 1;}
    return 0;
}

void printboard(char arr[3][3])
{
    for(int i=0;i<=2;i++)
    {
        for(int j=0;j<=2;j++)
        {
            printf(" %c ",arr[i][j]);
            if(j<2)
            {
                printf("|");
            }
        }
        printf("\n");
        if(i<2)
        {
            printf("---|---|---\n");
        }
    }
}

void tictactoe(player *p1,player *p2)
{
    char arr[3][3];
    int count1 =0;
    int count2 =0;
    int a,b,c;
    int flag1=0;
    int flag2=0;
    int t=1;
    int mastercounter=0;

    for(int i=0;i<=2;i++)
    {
        for(int j=0;j<=2;j++)
        {
           arr[i][j]='-';
        }
    }
    printboard(arr);
    printf("\n");


    while(1)
    {
        if(mastercounter>=9)
        {
            printf("\n\n--NICE TRY!! BUT MATCH IS A DRAW!!--\n");
            break;
        }


        while(1)
        {
        printf("%s's move : ",p1->name);
        if(scanf("%d", &c) != 1 || !(c >= 1 && c <= 9))
        {
            printf("\n--INVALID MOVE--PLEASE TRY AGAIN--\n");
            printboard(arr);
            while(getchar() != '\n');
            continue;
        }

        converter(c,&a,&b);
        if(p2->arr[a][b]==1)
        {
            printf("\n--INVALID MOVE PLACE ALEREADY OCCUPIED---PLEASE PLAY YOUR MOVE AGAIN!!--\n\n");
            printboard(arr);
            continue;
        }
        
        arr[a][b]='X';
        p1->arr[a][b]=1;
        count1++;
        mastercounter++;
        if(count1>=3)
        {
            if(haswon((p1->arr)))
            {
                printboard(arr);
                printf("%s has won!",p1->name);
                flag1=1;
            } 
        }
        break;
        }

        if(flag1==1)
        {
            break;
        }
        printf("\n");
        printboard(arr);

        if(mastercounter>=9)
        {
            printf("\n\n--NICE TRY!! BUT MATCH IS A DRAW!!--\n");
            break;
        }
       

        while(1)
        {
              
        printf("%s's move : ",p2->name);
        if(scanf("%d", &c) != 1 || !(c >= 1 && c <= 9))
        {
            printf("\n--INVALID MOVE--PLEASE TRY AGAIN--\n");
            printboard(arr);
            while(getchar() != '\n');
            continue;
        }
        converter(c,&a,&b);
        if(p1->arr[a][b]==1)
        {
            printf("\n--INVALID MOVE PLACE ALEREADY OCCUPIED---PLEASE PLAY YOUR MOVE AGAIN!!--\n\n");
            printboard(arr);
            continue;
        }
        arr[a][b]='O';
        p2->arr[a][b]=1;
        count2++;
        mastercounter++;
        if(count2>=3)
        {
            if(haswon((p2->arr)))
            {
                printboard(arr);
                printf("\n\n%s has won!\n",p2->name);
                flag2=1;
            }
        }
        break;
        }
        if(flag2==1)
        {
            break;
        }
        printf("\n");
        printboard(arr);

    }
}

int main()
{
    printf("\t\t\t\t\t\t\tTICK--TACK--TOE\n");
    printf("\t\t\t\t\t\t----CREATED BY DHEERAJ SHAHUL----\n\n");
    player p1,p2;
    printf("Enter name of first player  : ");
    gets(p1.name);
    p1.id = 1;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            p1.arr[i][j]=0;
        }
    }
    printf("Enter name of second player : ");
    gets(p2.name);
    p2.id =2;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            p2.arr[i][j]=0;
        }
    }

    printf("\nIntialising game .....\n\nBoard Intilaised....\n");
    
    tictactoe(&p1,&p2);

    printf("\n\n");
 

     system("pause");
    return 0;

}