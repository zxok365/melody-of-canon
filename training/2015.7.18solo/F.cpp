#include<iostream>
#include<cstdio>
using namespace std;
int x, a, b, c;
int main(){
	scanf("%d%d%d", &a, &b, &c);
	x = 0;
	for (int i = 0;i <= 64; i++)
	{
		x = x ^ (a + i * c);
		printf("%6d :", i);
		printf("%6d ", x);
		int t = x;
 for (int i = 1; i <= 15; i++)
		{
			printf("%c", t % 2 ? 'X' : '-');
			t /= 2;
		}
		printf("\n");
	}	
	return 0;
}
