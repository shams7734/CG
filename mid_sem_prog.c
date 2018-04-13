#include<stdio.h>
#include<string.h>
#include<graphics.h>

void drawPixelsForCircle(int x,int y,double cx,double cy,double r)
{

	putpixel(cy+y,cx+x,GREEN);
	putpixel(cy-y,cx+x,GREEN);
	putpixel(cy+y,cx-x,GREEN);
	putpixel(cy-y,cx-x,GREEN);
}

void drawPixels(double cx,double cy,int x,int y)
{
	putpixel(cx+x,cy+y,RED);
	putpixel(cx+x,cy-y,RED);
	putpixel(cx-x,cy+y,RED);
	putpixel(cx-x,cy-y,RED);
}

int main()
{
	int gd = DETECT, gm;
	gm=VGAMAX;
	double a;
	double cx,cy,r;
	printf("Enter the radius of the circle and value of cx and cy\n ");
	scanf("%d %lf %lf",&r,&cx,&cy);
	printf("Enter the value of a of ellipse\n ");
	scanf("%d",&a);
	
	initgraph(&gd, &gm, NULL);
	
	//  for ellipse
	
	/* Taking inputs */
	double cx,cy,radiusH,radiusV;
	printf("Enter the radius of the horizontal axis of the ellipse : ");
	scanf("%lf",&radiusH);
	printf("Enter the radius of the vertical axis of the ellipse : ");
	scanf("%lf",&radiusV);
	
	/* Main Algorithm */
	
	/* Region 1 */
	double a=radiusH,b=radiusV;
	int x = 0,y = b;
	
	double perimeter = b*b - (2*a*a*b) + (a*a)/4.0;
	while(x*b*b < y*a*a)
	{
		drawPixels(cx,cy,x,y);
		x++;
		if(perimeter < 0) perimeter = perimeter + b*b*(2*x+1);
		else
		{
			x--;
			perimeter = perimeter + b*b*(2*x+1) - 2*a*a*y;
		}
	}
	
	
	
	//  for circle
	
	int x = 0,y = r;
	
	// for next value  (x,y+1) or (x-1,y+1)
	
	int p = 1-r;   // value nearly equal to 1
	while(y > x)
	{
		drawPixelsForCircle(x,y,cx,cy,r);
		y=y+1;
		if(p >= 0) 
		{
		 p = p + 2*y + 1;
		}
		else
		{
			x=x-1;
			p = p + 2*y - 2*x + 1;
		}
		if(x < y) 
			break;
	}
	
	putpixel(cx,cy,WHITE);
		
	delay(9999);
	closegraph();	
	
}
