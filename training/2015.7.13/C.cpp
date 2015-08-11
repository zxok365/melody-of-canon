#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;
const int maxn=210;

int s[maxn][maxn];
int n;
int main() {
	cin>>n;
	int nn=n*2+1;
	int i,j;
	for(i=0;i<nn;++i)
	{
		for(j=0;j<nn;++j)
		{
			if(i==j)s[i][j]=0;
			else if(i+j<=nn)s[i][j]=i+j;
			else s[i][j]=i+j-nn;
			printf("%d",s[i][j]);
			if(j!=nn-1)putchar(' ');
		}
		putchar('\n');
	}
	
	
	
}
