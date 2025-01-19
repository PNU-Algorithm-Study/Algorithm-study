#include <stdio.h>
void hanoi(int k, int ox, int ux, int tx)
{
	if (k == 1)
	{
		printf("%d %d\n", ox, tx);
	}
	else
	{
		hanoi(k - 1, ox, tx, ux);
		printf("%d %d\n", ox, tx);
		hanoi(k - 1, ux, ox, tx);

	}
}
int hanoi_num(int num)
{
	if (num == 1)
		return 1;
	else
		return 2 * hanoi_num(num - 1) + 1;

}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", hanoi_num(n));
	hanoi(n,1,2,3);
	return 0;

}

