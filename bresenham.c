/*  Implementation of Bresenham's Line drawing algorithm.
	User needs to enter only the co-ordinates of point i.e x1,y1 and x2,y2 .
	ID : 2015kucp1034
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int x1,y1,x2,y2,dx,dy;
	int p,x,y;
	float m;
	
	printf("Enter the co-ordinates of first point x1 , y1 \n");
	scanf("%d %d",&x1,&y1);
	printf("Enter the co-ordinates of second point x2 , y2 \n");
	scanf("%d %d",&x2,&y2);

	dx = (x2 - x1);
	dy = (y2 - y1);
	
	m=(float)dy/dx;
	
	if( m < 1 )
	{
		printf("The value of m is %.3f\n",m);
		p = 2 * (dy) - (dx);

		x = x1;
		y = y1;
	
		printf("The intermediate points are\n");
		while(x < x2)
		{
			if(p < 0)
			{
				x=x+1;
				y=y;
				printf("( %d , %d )\n",x,y);
				p = p + 2 * (dy);
			}
			else
			{
				x=x+1;
				y=y+1;
				printf("( %d , %d )\n",x,y);
				p = p + 2 * (dy - dx);
			}
		}
	}
	
	else if( m > 1 )
	{
		printf("The value of m is %.3f\n",m);
		
		p = 2 * (dx) - (dy);

		x = x1;
		y = y1;
	
		printf("The intermediate points are\n");
		while(y < y2)
		{
			if(p < 0)
			{
				x=x;
				y=y+1;
				printf("( %d , %d )\n",x,y);
				p = p + 2 * (dx);
			}
			else
			{
				x=x+1;
				y=y+1;
				printf("( %d , %d )\n",x,y);
				p = p + 2 * (dx - dy);
			}
		}
		
	}
	
	else if( m == 1 )
	{
		printf("The value of m is %.3f\n",m);
		x = x1;
		y = y1;
	
		printf("The intermediate points are\n");
		while(y < y2)
		{
			x=x+1;
			y=y+1;
			printf("( %d , %d )\n",x,y);

		}
	} 
	
	
}
