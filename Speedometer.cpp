#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#include<windows.h>
#include<stdio.h>

#define WBC 5
#define X 250
#define Y 300

int size = 160;

void dial(int x, int y);
void needle(int ,int );

void needle(int x,int speed)
{
    int x1,y1;
    setlinestyle(0,0,3);

    x1= X-((size-80) * cos(speed*0.0314));
    y1= Y-((size-80) * sin(speed*0.0314));

    setcolor(x);
    line(x1,y1,X,Y);

    setcolor(1);
    circle(X,Y,4);
}

void dial(int x,int y)
{
    int m,n;

    sector(x,y,-20,200,size,size);
    setfillstyle(1,4);
    sector(x,y,-20,60,size,size);
    setfillstyle(1,2);
    sector(x,y,100,150,size,size);
    size-=20;
    setfillstyle(1,0);
    sector(x,y,-20,200,size,size);

    size-=30;

    for(int i = 0,j=0 ; i<=180 ;i+=18,j++)
    {
        char p[10];
        setcolor(11);
        sprintf(p,"%d",j*10);
        m = x-(size*cos(i*3.14/180));
        n = y-(size*sin(i*3.14/180));
        outtextxy(m,n,p);
    }
    size+=50;
    circle(x,y,4);
}

int main()
{
    int gd=DETECT, gm,i,j;
    initgraph(&gd,&gm,"C:\\MinGW\\include\ ");
    initwindow(1340,720,"Car simulator");
    dial(250,300);
    for (int i=0;i<=100;i++){
        needle(4,i);
        delay(100);
        needle(0,i);
    }
    getch();
    closegraph();
}
