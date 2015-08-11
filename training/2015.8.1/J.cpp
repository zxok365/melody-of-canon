#include<iostream>
#include<cstdio>
using namespace std;
int n, a, b, nown;
int main(){
	scanf("%d%d%d", &n, &a, &b);
	int nown = 0, nowa = 0,	nowb = 0;
	while (nown < n){
		int k = min(a + nowa, b + nowb);
		if (k == a + nowa) { nown++; nowa = a + nowa;}
		if (k == b + nowb) { nown++; nowb = b + nowb;}
	}
	int k = max(nowa, nowb);
	if (k > nowb) nown++, nowb = nowb + b;
	if (k > nowa) nown++, nowa = nowa + a;
	printf("%d %d\n",nown, max(nowa, nowb));
}
