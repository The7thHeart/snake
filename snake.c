#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <time.h>






void main()
{
    // inti
    int gameover=0;
    int i, j;
    char l =30;
    int score=0;
    int fruit=1;

    // init map
    int map[20][20];
    for (i=0; i<20; i++)
    {
        for (j=0; j<20; j++)
        {
            map[i][j]=0;
        }
    }
    map[4][4]=0;

    // create snake
    int s;
    int x[400];
    int y[400];
    int hx=4;
    int hy=4;
    int pos=0;
    int direction=0;
    int size = 1;
    for (i=0; i<20; i++)
    {
        x[i]=-1;
        y[i]=-1;
    }
    x[0]=4;
    y[0]=4;
    
    


    // create fruit
    int xf;
    int yf;
    time_t t0;
    srand((unsigned) time(&t0));
    xf = rand() % 20;
    yf = rand() % 20;
    if (xf==4 && yf==4) yf++;
    printf("type 0");
    scanf("%d",&i);
   

    // start the game
    while(1)
    {
        clock_t t;
        t = clock();

        // clear map
        for (i=0; i<20; i++)
        {
            for (j=0; j<20; j++)
            {
                map[i][j]=0;
            }
        }


        // move snake
        hx=x[0];
        hy=y[0];
        switch (direction)
        {
        case 0:
            y[0]++;
            break;
        case 1:
            y[0]--;
            break;
        case 2:
            x[0]--;
            break;
        default:
            x[0]++;
            break;
        }
        if(x[0]<0 || x[0]>=20 || y[0]<0 || y[0]>=20) gameover=1;
        if (xf==x[0] && yf==y[0])
        {
            score++;
            x[size]=x[size-1];
            y[size]=y[size-1];
            size++;
            xf = rand() % 20;
            yf = rand() % 20;
        }
        
        
        for (pos=size-1; pos>1; pos--)
        {
            x[pos]=x[pos-1];
            y[pos]=y[pos-1];
            if (x[pos]==x[0] && y[pos]==y[0]) gameover=1;
        }
        x[1]=hx;
        y[1]=hy;
 
        if (gameover) break;

        // fix $ if it is in the way and draw map
        for (pos=0; pos<size; pos++)
        {
            map[x[pos]][y[pos]]=1;
        }
        while (map[xf][yf]==1)
        {
            if(yf==19)
            {
                if (xf==19)
                {
                    xf=0;
                    yf=0;
                }
                else
                {
                    xf++;
                    yf=0;
                }
            }
            else
            {
                yf++;
            }
        }
        map[xf][yf]=2;


        //ClearScreen();
        system("cls");
        // print border
        for (i=0; i<21; i++) printf("* ");
        printf("*\n");

        // print land
        for (i=0; i<20; i++)
        {
            printf("* ");
            for (j=0; j<20; j++)
            {
                if (map[i][j]==0) printf("  ");
                if (map[i][j]==1) printf("s ");
                if (map[i][j]==2) printf("$ ");
            }
            printf("*\n");
        }
        for (i=0; i<21; i++) printf("* ");
        printf("*\n");
        
        printf("score: %d\n", score);
        
 
       

        
        // wait and check keyboard
        while(clock()-t<500)
        {
            if(kbhit()){
                l = getch();
                 
            }
        }
        switch (l)
        {
        case 77: //right
            if (direction != 1) direction=0;
            break;
        case 75: //left
            if (direction != 0) direction=1;
            break;
        case 72: //up
            if (direction != 3) direction=2;
            break;
        case 80: //down
            if (direction != 2) direction=3;
            break;
        default:
            break;
        }



        // wait 
        //t = clock() - t;
        //double time_taken = ((double)t)/CLOCKS_PER_SEC;
        //printf("The program took %f seconds to execute", time_taken);
    }
printf("gameover");
scanf("%d",&i);
}