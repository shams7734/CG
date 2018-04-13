#include<stdio.h>
#include<graphics.h>

void boundaryfill_polygon(int x,int y,int fg_color,int bg_color)
{
    if(getpixel(x,y)!=bg_color && getpixel(x,y)!=fg_color)
    {
        putpixel(x,y,fg_color);
        boundaryfill_polygon(x+1,y,fg_color,bg_color);
        boundaryfill_polygon(x,y+1,fg_color,bg_color);
        boundaryfill_polygon(x-1,y,fg_color,bg_color);
        boundaryfill_polygon(x,y-1,fg_color,bg_color);
    }
}

int main()
{
	int gd = DETECT, gm;
	gm=VGAMAX;
	
	int x,y,radius;
	printf("Enter the center of the circle\n");
	scanf("%d %d",&x,&y);
	printf("Enter the radius of the cirlce\n");
	scanf("%d",&radius);
	initgraph(&gd, &gm, NULL);
	
	circle(x,y,radius);
	boundaryfill_polygon(x,y,4,15);
	delay(9999);
		
    closegraph();
}
