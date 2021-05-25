#include <stdio.h>
#include<algorithm>
#define ture 1
#define false 0
#define MAXI 1000
typedef int keytype;
typedef char infotype;
typedef struct rectype
{
	keytype key;
	infotype data;
};
typedef struct
{
	keytype key;
	int link;

}idxtype;
int idxsearch(idxtype I[], int b, rectype R[], int n, keytype k)
{
	int s = n / b;
	int low = 0, high = b - 1, mid, i;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (I[mid].key >= k)
			high = mid - 1;
		else
			low = mid + 1;
	}
	i = I[high + 1].link;
	while (i <= I[high + 1].link + s - 1 && R[i].key != k)
		i++;
	if (i <= I[high + 1].link + s - 1)
		return i + 1;
	else
		return 0;
}
int main()
{
	int a[] = { 8,14,6,9,10,22,34,18,19,31,40,38,54,66,46,71,78,68,80,85,100,94,88,96,87 };
	rectype R[25];
	int i;
	for (i = 0; i < 25; i++)
		R[i].key = a[i];
	idxtype I[5];
	int tem[5];
	for (i = 0; i < 5; i++)
	{
		I[i].link = i * 5;
		I[i].key = 0;
	}
	for (i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			tem[j] = a[i * 5 + j];
			if (tem[j] > I[i].key)
				I[i].key = tem[j];
		}
	}
	printf("所查找元素在第%d位\n", idxsearch(I, 5, R, 25,46));
}