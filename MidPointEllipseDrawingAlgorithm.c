/*
	Author	:	Nilesh Agarwal
	ID		:	2015KUCP1004
	Code	:	Mid Point Ellipse Drawing Algorithm
	Command	:	gcc MidPointEllipseDrawingAlgorithm.c -o ellipse -lgraph && ./ellipse
*/

#include<graphics.h>
#include<stdio.h>

void drawPixels(double centerX,double centerY,double x,double y)
{
	putpixel(centerX+x,centerY+y,RED);
	putpixel(centerX+x,centerY-y,RED);
	putpixel(centerX-x,centerY+y,RED);
	putpixel(centerX-x,centerY-y,RED);
}

int main()
{
	/* Taking inputs */
	double centerX,centerY,radiusH,radiusV;
	printf("Enter the X-coordinate of the center point of the ellipse : ");
	scanf("%lf",&centerX);
	printf("Enter the Y-coordinate of the center point of the ellipse : ");
	scanf("%lf",&centerY);
	printf("Enter the radius of the horizontal axis of the ellipse : ");
	scanf("%lf",&radiusH);
	printf("Enter the radius of the vertical axis of the ellipse : ");
	scanf("%lf",&radiusV);
	
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
	/* Main Algorithm */
	
	/* Region 1 */
	double a=radiusH,b=radiusV;
	int startX = 0,startY = b;
	
	double perimeter = b*b - (2*a*a*b) + (a*a)/4.0;
	while(startX*b*b < startY*a*a)
	{
		drawPixels(centerX,centerY,startX,startY);
		startX++;
		if(perimeter < 0) perimeter = perimeter + b*b*(2*startX+1);
		else
		{
			startY--;
			perimeter = perimeter + b*b*(2*startX+1) - 2*a*a*startY;
		}
	}
	
	/* Region 2 */
	perimeter = (((double)startX+0.5)*((double)startX+0.5)*b*b)+((startY-1)*(startY-1)*a*a)-(a*a*b*b);
	while(startY >= 0)
	{
		drawPixels(centerX,centerY,startX,startY);
		startY--;
		if(perimeter > 0) perimeter = perimeter - (2*a*a*startY) + (a*a);
		else
		{
			startX++;
			perimeter = perimeter + (2*b*b*startX) - (2*a*a*startY) - (a*a);
		}
	}
	
	//drawing 'a' and 'b'
	setcolor(BLUE);
	line(centerX,centerY,centerX+a,centerY);
	line(centerX,centerY,centerX,centerY+b);
	char *aLength,*bLength;
	aLength = (char *)malloc(25*sizeof(char));
	bLength = (char *)malloc(25*sizeof(char));
	sprintf(aLength,"a = %.2lf",a);
	sprintf(bLength,"b = %.2lf",b);
	outtextxy(centerX+(a-60)/2,centerY+10,aLength);
	outtextxy(centerX+10,centerY+(b-20)/2,bLength);
	
	
	//printing center point
	char *centerPoint;
	centerPoint = (char *)malloc(25*sizeof(char));
	sprintf(centerPoint,"Center(%d,%d)",(int)centerX,(int)centerY);
	outtextxy(centerX-20,centerY-20,centerPoint);
	setcolor(WHITE);
	pieslice(centerX,centerY,0,360,2);
	
	getch();
	closegraph();
	return 0;
}
