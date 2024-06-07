#include <stdio.h>

int main(void)
{
	int a[][3] = {{1,2,3},
		    {4,5,6},
		    {7,8,9}};
	int *pa[] = {a[0], a[1], a[2]};
	int *p = a[0];

	int i;
	for (i = 0; i <3; i++)
		printf("%d %d %d\n", a[i][2-i], *a[i], *(*(a+i)+i));
	putchar('\n');

	for (i = 0; i<3; i++)
		printf("%d %d\n", *pa[i], p[i]);
	putchar('\n');

	return 0;
}

/* 
   3 = a[0][0], 1 =*a[0],1 = a[0][0]
  5 = a[1][1], 4 = *a[1] = a[1][0], a[1][1] = 5
  7 = a[2][0], 7 = *a[2] = a[2][0], a[2][2] = 9


  11 42 73
  *pa[0] = a[0] = a[0][0] = 1, p[0] = a[0][0] = 1;
  *pa[1] = a[1] = a[1][0] = 4, p[1] = p[0][1] = 2;
  *pa[2] = a[2] = a[2][0] = 7, p[2] = p[0][2] = 3;
  *pa[0] == {1,2,3} == 1, {{O}, {}, {}}
  p[0] == {1,2,3} == {[1 (O), 2(1), 3(2)}
 */

