/* 2015kucp1034
   Shams Ali
   
   To implement Liang Barsky line clipping algorithm.
   User needs to input the value two points and the co-ordinates of window.
*/

#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<stdbool.h>

float max(float a, float b)
{
	float m;
	if(a>b)
		m=a;
	else 
		m=b;
	return m;
}

float min(float c, float d)
{
	float m;
	if(c<d)
		m=c;
	else 
		m=d;
	return m;
}

int main()
{
	int gd = DETECT, gm;
	gm=VGAMAX;
	int i;
	float x1,y1,x2,y2,dx,dy;
	float t1,t2;
	float status=0;
	float xmin,xmax,ymin,ymax;
	float p[4],q[4];
	float temp=0,temp1=0;
	float x,y,xf,yf;
	printf("Enter the value of x1,y1,x2,y2\n");
	scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
	printf("Enter the value of xmin,ymin,xmax,ymax\n");
	scanf("%f %f %f %f",&xmin,&ymin,&xmax,&ymax);
	dx=x2-x1;
	dy=y2-y1;
	
	i=0;
	p[i]=-dx;
	i++;
	p[i]=dx;
	i++;
	p[i]=-dy;
	i++;
	p[i]=dy;
	
	i=0;
	q[i]=x1-xmin;
	i++;
	q[i]=xmax-x1;
	i++;
	q[i]=y1-ymin;
	i++;
	q[i]=ymax-y1;
	
	t1=0;
	t2=1;
	
	initgraph(&gd, &gm, NULL);
    rectangle(xmin, ymin, xmax, ymax);
    setcolor(BLUE);
    line(x1,y1,x2,y2);
    delay(5555);
    for(i=0;i<4;i++)
	{
		if(p[i]==0)
		{
			printf("Line is parallel to the window\n");
			if(q[i]<0)
			{
				printf("Line is outside the window\n");
				exit(0);
			}
		}
		
		if(p[i]!=0)
		{
			if(p[i]<0)
			{
				temp=max( 0,(q[i]/p[i]) );
				if(temp>=t1);
					t1=temp;	
			}
			if(p[i]>0)
			{
				temp1=min( 1,(q[i]/p[i]) );
				if(temp1<=t2)
					t2=temp1;
			}
		}
		if(t1 > t2)
		{
			printf("Line is completely outside the window\n");
			exit(0);
		}
	}
    
   		x=x1+(t1*dx);
		y=y1+(t1*dy);
		printf("line accepted from ( %f,%f ) ",x,y);
		xf=x1+(t2*dx);
		yf=y1+(t2*dy);
		printf("to ( %f,%f )\n",xf,yf);
		setcolor(GREEN);
		line(x,y,xf,yf);
		delay(9999);
		
    closegraph();
	
}
