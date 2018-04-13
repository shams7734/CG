/* 2015kucp1034
   Shams Ali  
   To implement Sutherland line clipping algorithm.
   User needs to input the value two points and the co-ordinates of window.
*/

#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include <stdbool.h>

typedef int OutCode;

const int INSIDE = 0; 
const int LEFT = 1;   
const int RIGHT = 2;  
const int BOTTOM = 4; 
const int TOP = 8;    

double xmin,xmax,ymin,ymax;

OutCode ComputeOutCode(double x, double y)
{
	OutCode code;

	code = INSIDE;          

	if (x < xmin)           
		code |= LEFT;
	else if (x > xmax)      
		code |= RIGHT;
	if (y < ymin)           
		code |= BOTTOM;
	else if (y > ymax)      
		code |= TOP;

	return code;
}

void sutherland(double x0, double y0, double x1, double y1)
{
	
	OutCode outcode0 = ComputeOutCode(x0, y0);
	OutCode outcode1 = ComputeOutCode(x1, y1);
	bool accept = false;

	while (1) {
		if (outcode0==0 && outcode1==0) { 
			accept = true;
			break;
		} else if (outcode0 & outcode1) { 
			break;
		} else {
			
			double x, y;

			OutCode outcodeOut = outcode0 ? outcode0 : outcode1;
			// Finding out the intersection point 
			if (outcodeOut & TOP) {           // point is above the clip rectangle
				x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
				y = ymax;
			} else if (outcodeOut & BOTTOM) { // point is below the clip rectangle
				x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
				y = ymin;
			} else if (outcodeOut & RIGHT) {  // point is to the right of clip rectangle
				y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
				x = xmax;
			} else if (outcodeOut & LEFT) {   // point is to the left of clip rectangle
				y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
				x = xmin;
			}


			if (outcodeOut == outcode0) {
				x0 = x;
				y0 = y;
				outcode0 = ComputeOutCode(x0, y0);
			} else {
				x1 = x;
				y1 = y;
				outcode1 = ComputeOutCode(x1, y1);
			}
		}
	}
	if (accept) {
		printf("Line accepted from ( %lf,%lf ) to ( %lf,%lf )\n",x0,y0,x1,y1);
		setcolor(RED);
		line(x0, y0, x1, y1);
		delay(5000);
		setcolor(BLUE);
		pieslice(x0,y0,0,360,2);
		setcolor(BLUE);
		pieslice(x1,y1,0,360,2);
				
	}
	else
		printf("Line Rejected\n");
}

int main()
{
	int gd = DETECT, gm;
	gm=VGAMAX;
    double x_0,y_0,x_1,y_1;
    printf("Enter the value of x_0,y_0,x_1,y_1\n");
    scanf("%lf %lf %lf %lf",&x_0,&y_0,&x_1,&y_1);
    printf("Enter the value of window size x_min,y_min,x_max,y_max\n");
    scanf("%lf %lf %lf %lf",&xmin,&ymin,&xmax,&ymax);
   
    initgraph(&gd, &gm, NULL);
    rectangle(xmin, ymin, xmax, ymax);
    sutherland(x_0,y_0,x_1,y_1);
    setcolor(BLUE);
    line(x_0,y_0,x_1,y_1);
    delay(9999);
    closegraph();
    return 0;
}
