#include <stdio.h>

// typedef struct
// {
// 	int x;
// 	int y;
// } points;

// void	check(points *a)
// {
// 	a->x = 20;
// 	a->y = 223;
// }

// int main()
// {
// 	points	*a;
// 	points	b;
// 	b.x = 30;
// 	b.y = 40;
// 	a->x = 10;
// 	a->y = 11;
// 	printf("%p %p\n", a, *a);
// 	// printf("%d %d\n", a.x, a.y);
// 	// check(a);
// 	// printf("%d %d\n", a.x, a.y);
// }

int main()
{
	int *p;
	int a;

	a = 5;
	// p = &a;
	printf("%p\n", p);
	p = &a;
	printf("%p\n", p);
}