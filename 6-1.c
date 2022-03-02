// A function that uses a structure to determine the distance and rectangle
#include<stdio.h>
#include<math.h>

int main(void)
{
	int betx;
	int bety;

	double distance;
	int area;
// Create structure of x and y
	struct point{
		int x;
		int y;
	};

	struct point pt1 = {10, 20};
	struct point pt2 = {30, 40};

	betx = (pt2.x)-(pt1.x);
	bety = (pt2.y)-(pt1.y);
// To use the sqrt function, include math.h	
	distance = sqrt(betx*betx + bety*bety);
	area = betx * bety;

	printf("distance = %f\n", distance);
	printf("area = %d\n", area);

	return 0;
}
