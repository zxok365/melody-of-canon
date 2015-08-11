#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

char s[10][50];
char ans[10][50];
char equal[20];
int num[50];

int make(int x) {
	int sum = 0;
	while (x != 0) {
		if ((x&1) == 1) sum += 500;
			else sum += 250;
		x >>= 1;
	}
	return sum;
}

void prepare() {
	for (int i = 0; i < 26; i++) num[i] = make(i + 65);
}

void make(int st1, int ed1, int start) {
	for (int i = ed1; i <= ed1 + 4; i ++) 
		for (int j = start; j <= start + 7; j ++) ans[i][j] = s[st1 + i - ed1][j];
	for (int i = 1; i < ed1; i ++) 
		for (int j = start; j <= start + 7; j ++) ans[i][j]='.';
	for (int i = ed1 + 5; i <= 7; i ++) 
		for (int j = start; j <= start + 7; j ++) ans[i][j]='.';
}

int main() {
	prepare();
	for (int i = 1; i <= 7; i ++) ans[i][18]='\0';
	int test;
	scanf("%d", &test);
	int tot = 0;
	while (test--) {
		tot ++;
		int st1, st2, ed1, ed2;
		for (int i = 1; i <= 7; i++) scanf("%s", s[i]);
		if (s[1][3] == '/') {
			st1 = 1;
			st2 = 3;
		} else if (s[1][13] == '/') {
			st1 = 3;
			st2 = 1;
		} else {
			st1 = 2;
			st2 = 2;
		}
		int left_w = 0;
		int right_w = 0;
		int k = 1;
		while (s[st1+3][k] >= 'A' && s[st1+3][k] <= 'Z') {
			left_w += num[s[st1+3][k] - 'A'];
			k++;
		}
		k = 11;
		while (s[st2+3][k] >= 'A' && s[st2+3][k] <= 'Z') {
			right_w += num[s[st2+3][k] - 'A'];
			k++;
		}
		if (left_w < right_w) {
			ed1 = 1;
			ed2 = 3;
		} else if (left_w > right_w) {
			ed1 = 3;
			ed2 = 1;
		} else {
			ed1 = 2;
			ed2 = 2;
		}
		printf("Case %d:\n", tot);
		if (st1 == ed1 && st2 == ed2) puts("The figure is correct.");
			else {
				make(st1, ed1, 0);
				make(st2, ed2, 10);
				for (int i = 1; i <= 7; i++) ans[i][8] = ans[i][9] = '|';
				for (int i = 1; i <= 7; i++) puts(ans[i]);
			}
		scanf("%s", s[1]);
	}
	return 0;
}
