#include<stdio.h>
#include<graphics.h>
#include<conio.h>
int main()
{

    int gd = DETECT,gm;        
    int choice;

    printf("Enter size of set A: ");
    scanf("%d",&nA);

    for(i=0;i<nA;i++)
    {
        printf("Enter Value %d: ",(i+1));
        scanf("%d",&a[i]);
    }

    printf("\nEnter size of set B: ");
    scanf("%d",&nB);

    if(nA==0 && nB==0)
    {
        printf("No Set operation possible!!!!");
        getch();
    }

    for(i=0;i<nB;i++)
    {
        printf("Enter Value %d: ",(i+1));
        scanf("%d",&b[i]);
    }


    k=0;
    for(i=0;i<nA;i++)
        for(j=0;j<nB;j++)
            if(a[i]==b[j])
              {
                 c[k++] = a[i];
                 countC++;
              }

    countA = nA - countC;
    countB = nB - countC;

    radA = nA * 10;
    radB = nB * 10;
    widC = countC * 10;

    xA = x;                     // center of circle
    xB = x + radA + radB - widC;    // center of circle

    Ax1 = x - radA;                    // start of setA on radius
    Ax2 = x + radA - widC;           // end of setA on radius

    Bx1 = x + radA + 1;              // start of setB on radius
    Bx2 = xB + radB;                    // end of setB on radius

    Cx1 = Ax2 + 1;               // start of intersect
    Cx2 = Bx1 - 1;                  // end of intersect
    
    while(1)
    {
        printf("\n1. Union\n\n2. Difference\n\n3. Intersection\n\n4. Subset\n\n5. First Set\n\n6. Second Set\n\n7. Exit");
        scanf("%d",&choice);

        initgraph(&gd, &gm, "C:\\TC\\BGI");

        switch(choice)
        {
        case 1:
                Union();
                break;
        case 2:
                Difference();
                break;
        case 3:
                Intersection();
                break;
        case 4:
                Subset(countA,countB,countC);
                break;
        case 5:
                setcolor(13);
                circle(xA, y, radA);
                plotset(radA,Ax1,Ax2,y,nA,countC,a,c);
                plotset(widC/2,Cx1,Cx2-20,y,countC,0,c,c);
                break;

        case 6:
                setcolor(10);
                circle(xB, y, radB);
                plotset(radB,Bx1,Bx2,y,nB,countC,b,c);
                plotset(widC/2,Cx1,Cx2-20,y,countC,0,c,c);
                break;

        case 7:
                exit(0);

        default:
                printf("\nWrong Choice!!!!!!!!! Try Again...........");
                getch();
        }
    }

    getch();
    closegraph();
return 0;
}
void Union(void)
{
    setcolor(13);
    circle(xA, y, radA);
    plotset(radA,Ax1,Ax2,y,nA,countC,a,c);
    circle(xB, y, radB);
    plotset(radB,Bx1,Bx2,y,nB,countC,b,c);
    plotset(widC/2,Cx1,Cx2-20,y,countC,0,c,c);

}
void Difference(void)
{
    int ch;

    printf("\n\n1. A - B\n\n2. B - A");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:
                setcolor(10);
                outtextxy(xA,y+radA+15,"A - B");
                circle(xA, y, radA);
                plotset(radA,Ax1,Ax2,y,nA,countC,a,c);
                break;
        case 2:
                setcolor(12);
                outtextxy(xB,y+radB+15,"B - A");
                circle(xB, y, radB);
                plotset(radB,Bx1,Bx2,y,nB,countC,b,c);
                break;
        default:
               printf("\nWrong Choice!!!!!!!!! Try Again...........");
                getch();
    }
}
void Intersection(void)
{
    setcolor(8);
    circle(xA, y, radA);
    circle(xB, y, radB);
    setcolor(13);
    plotset(widC/2,Cx1,Cx2-20,y,countC,0,c,c);
}
void Subset(int a, int b, int c)
{
    if(a==b)
        outtextxy(200,150,"\nA and B are Proper Subset to each other");
    else if(a<b && a==c)
     {
         outtextxy(200,150,"\nA is Proper Subset of B");
         outtextxy(200,200,"\nB is Superset of A");
     }
    else if(b<a && b==c)
    {
          outtextxy(200,150,"\nB is Proper Subset of A");
          outtextxy(200,200,"\nB is Superset of A");
    }
    else if(a<b && a>c)
        outtextxy(200,150,"\nNeither A Nor B is Subset to each other");

}
void plotset(int rad, int x1, int x2, int y, int setN, int setComm, int setplot[],int comset[])
{
    int plotX, plotY, plotGap, flag,plotcnt=0, i, j,k;
    char p[10];

    plotGap = (int)((rad*2)/(setN-setComm));
    plotX = x1 + ((x2 - x1)/2);
    plotY = y + rad - plotGap;
    i= 20;

    for(j=0;j<setN;j++)
        {
            flag = 0;
            for(k=0;k<setComm;k++)
            {
                if(setplot[j]==comset[k])
                 {
                     flag=1;
                     break;
                 }
            }

            if(flag==0)
             {
                 itoa(setplot[j],p,10);
                 outtextxy(plotX,plotY,p);
                 plotX = plotX  +  i ;
                 i = i * -1;
                 plotcnt++;
                 if(plotcnt%1==0)
                 {
                        plotY = plotY - plotGap ;  
		 } 
	     }
	 }
}

