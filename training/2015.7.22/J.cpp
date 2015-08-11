#include<iostream>
#include<cstdio>
using namespace std;
int now;
int a, b, c;
void move(int kk){
	if (kk == 3 || kk == -3) c--;
	if (kk == 2 || kk == -2) b--;
	if (kk == 1 || kk == -1) a--;
	now = now + kk;
//	printf("%d %d %d %d %d\n",a, b, c, kk, now);
	printf(" %d", now);
	
}

void move3_1(){
	int k = (c - 1)/ 3;
	move(3);
	for (int i = 1; i <= k; i++) move(3);
	move(-2);
	for (int i = 1; i <= k; i++) move(-3);
	move(1);
	for (int i = 1; i <= k; i++) move(3);
	move(2);
}

void move3_2(){
	int k = (c - 2) / 3;
	move(3);
	for (int i = 1; i <= k; i++) move(3);
	move(-1);
	for (int i = 1; i <= k; i++) move(-3);
	move(-1);
	for (int i = 1; i <= k; i++) move(3);
	move(3);
}


void move2_0(){
	int k = b / 2;
	for (int i = 1; i <= k; i++) move(2);
	move(1);
	for (int i = 1; i <= k; i++) move(-2);
}

void move2_1(){
	int k = b / 2;
	move(2);
	for (int i = 1; i <= k; i++) move(2);
	move(-1);
	for (int i = 1; i <= k; i++) move(-2);
}

void move12(){
	while (a > 1) move(1);
	if (b % 2 == 0) move2_0(); else move2_1();
}

int main(){
	int test_case;
	scanf("%d",&test_case);
	for (int time = 1; time <= test_case; time++)
	{
		scanf("%d%d%d", &a, &b, &c);
		now = 0;
		printf("%d", now);
		if (c % 3 == 1)
		{
			move3_1();
			move12();
		}
		else if (c % 3 == 2)
		{
			move3_2();
			move12();
		}
		else
		{
			move3_1();
			while (a > 1) move(1);
			int k = b / 2;
			if (b % 2 == 0){
				for (int i = 1; i <= k; i++) move(2);
				move(3);
				move(-2);
				move(1);
				move(-3);
				for (int i = 1; i < k; i++) move(-2);
			} else
			{
				for (int i = 1; i <= k; i++) move(2);
				move(3);
				move(-1);
				move(2);
				move(-3);
				for (int i = 1; i <= k; i++) move(-2);
			}
		}
	//	printf("\n%d %d %d\n", a, b, c);
		printf("\n");
	}
	return 0;
}
