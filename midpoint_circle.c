/*   Implementation of Mid Point circle drawing algorithm
	 2015kucp1034
*/

#include<graphics.h>
#include<stdio.h>

   //   Glowing pixels in 8 Octants

void drawPixels(int x,int y,double cx,double cy,double r)
{
	putpixel(cx+x,cy+y,GREEN);
	putpixel(cy+y,cx+x,GREEN);
	putpixel(cx+x,cy-y,GREEN);
	putpixel(cy-y,cx+x,GREEN);
	putpixel(cx-x,cy+y,GREEN);
	putpixel(cy+y,cx-x,GREEN);
	putpixel(cx-x,cy-y,GREEN);
	putpixel(cy-y,cx-x,GREEN);
}

int main()
{
	/* Taking inputs */
	double cx,cy,r;
	printf("Enter the co-ordinate i.e. x and y of the center of circle and radius : ");
	scanf("%lf %lf %lf",&cx,&cy,&r);
	
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
    int x = r;
    int y = 0;
	
	//   The values of pk and pk+1
	
	int p = 3-2*r;   //   value nearly equal to 1-r
	
	while(x > y)
	{
		drawPixels(x,y,cx,cy,r);
		y=y+1;
		if(p <= 0) 
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
	
	//printing center point
	char *cp;
	cp="Center";
	outtextxy(cx-20,cy-20,cp);
	putpixel(cx,cy,BLUE);
	delay(9999);
	closegraph();
	return 0;
}
