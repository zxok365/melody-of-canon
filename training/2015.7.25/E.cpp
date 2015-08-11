#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#define ULL unsigned long long
using namespace std;
const int MAG = 31;
struct cube
{
	int a[25], step;
	cube()
	{
		a[1] = a[2] = a[3] = a[4] = 1;
		a[5] = a[6] = a[11] = a[12] = 2;
		a[7] = a[8] = a[13] = a[14] = 3;
		a[9] = a[10] = a[15] = a[16] = 4;
		a[17] = a[18] = a[19] = a[20] = 5;
		a[21] = a[22] = a[23] = a[24] = 6;
		step = 0;
	}
	ULL hash()
	{
		ULL res = 0;
		for (int i = 1; i <= 24; ++ i) res = res * MAG + a[i];
		return res;
	}
};
int Up[25] = {0, 1, 2, 12, 6, 5, 17, 13, 7, 3, 10, 11, 18, 14, 8, 4, 16, 15, 9, 19, 20, 21, 22, 23, 24};
int Lp[25] = {0, 21, 2, 23, 4, 11, 5, 1, 8, 9, 10, 12, 6, 3, 14, 15, 16, 7, 18, 13, 20, 17, 22, 19, 24};
int Fp[25] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 22, 21, 11, 12, 13, 14, 19, 17, 20, 18, 16, 15, 23, 24};
int rUp[25], rLp[25], rFp[25];
cube U(cube &A)
{
	cube B;
	for (int i = 1; i <= 24; ++ i) B.a[Up[i]] = A.a[i];
	B.step = A.step + 1;
	return B;
}
cube rU(cube &A)
{
	cube tmp = U(A);
	tmp = U(tmp);
	tmp = U(tmp);
	return tmp;
}
cube L(cube &A)
{
	cube B;
	for (int i = 1; i <= 24; ++ i) B.a[Lp[i]] = A.a[i];
	B.step = A.step + 1;
	return B;
}
cube rL(cube &A)
{
	cube tmp = L(A);
	tmp = L(tmp);
	tmp = L(tmp);
	return tmp;
}
cube F(cube &A)
{
	cube B;
	for (int i = 1; i <= 24; ++ i) B.a[Fp[i]] = A.a[i];
	B.step = A.step + 1;
	return B;
}
cube rF(cube &A)
{
	cube tmp = F(A);
	tmp = F(tmp);
	tmp = F(tmp);
	return tmp;
}
const int MOD = 1e6 + 7;
vector<ULL> M[MOD];
bool find(vector<ULL> &M, ULL x)
{
	for (int i = 0; i < M.size(); ++ i) if (M[i] == x) return 1;
	return 0;
}
int Ap[25] = {0, 11, 5, 12, 6, 19, 17, 13, 7, 3, 1, 20, 18, 14, 8, 4, 2, 15, 9, 16, 10, 22, 24, 21, 23};
int Bp[25] = {0, 2, 4, 1, 3, 24, 23, 5, 6, 7, 8, 22, 21, 11, 12, 13, 14, 19, 17, 20, 18, 16, 15, 10, 9};
int Cp[25] = {0, 21, 22, 23, 24, 11, 5, 1, 2, 10, 16, 12, 6, 3, 4, 9, 15, 7, 8, 13, 14, 17, 18, 19, 20};
cube A(cube &a)
{
	cube b;
	for (int i = 1; i <= 24; ++ i) b.a[Ap[i]] = a.a[i];
	b.step = a.step;
	return b;
}
cube B(cube &a)
{
	cube b;
	for (int i = 1; i <= 24; ++ i) b.a[Bp[i]] = a.a[i];
	b.step = a.step;
	return b;
}
cube C(cube &a)
{
	cube b;
	for (int i = 1; i <= 24; ++ i) b.a[Cp[i]] = a.a[i];
	b.step = a.step;
	return b;
}
ULL HASH(cube &a)
{
	ULL tmp = a.hash();

	a = A(a); tmp = min(tmp, a.hash());
	a = A(a); tmp = min(tmp, a.hash());
	a = A(a); tmp = min(tmp, a.hash());
	a = A(a); tmp = min(tmp, a.hash());

	a = B(a); tmp = min(tmp, a.hash());

	a = A(a); tmp = min(tmp, a.hash());
	a = A(a); tmp = min(tmp, a.hash());
	a = A(a); tmp = min(tmp, a.hash());
	a = A(a); tmp = min(tmp, a.hash());

	a = B(a); tmp = min(tmp, a.hash());

	a = A(a); tmp = min(tmp, a.hash());
	a = A(a); tmp = min(tmp, a.hash());
	a = A(a); tmp = min(tmp, a.hash());
	a = A(a); tmp = min(tmp, a.hash());

	a = B(a); tmp = min(tmp, a.hash());

	a = A(a); tmp = min(tmp, a.hash());
	a = A(a); tmp = min(tmp, a.hash());
	a = A(a); tmp = min(tmp, a.hash());
	a = A(a); tmp = min(tmp, a.hash());

	a = B(a); tmp = min(tmp, a.hash());
	
	a = C(a); tmp = min(tmp, a.hash());

	a = A(a); tmp = min(tmp, a.hash());
	a = A(a); tmp = min(tmp, a.hash());
	a = A(a); tmp = min(tmp, a.hash());
	a = A(a); tmp = min(tmp, a.hash());
	
	a = C(a); tmp = min(tmp, a.hash());
	a = C(a); tmp = min(tmp, a.hash());

	a = A(a); tmp = min(tmp, a.hash());
	a = A(a); tmp = min(tmp, a.hash());
	a = A(a); tmp = min(tmp, a.hash());
	a = A(a); tmp = min(tmp, a.hash());
	
	return tmp;
}
queue<cube> q;
void insert(cube &tmp)
{
	ULL k = HASH(tmp);
	if (!find(M[k % MOD], k))
	{
		q.push(tmp);
		M[k % MOD].push_back(k);
	}
}
int main()
{
	//for (int z = 1; z <= 10000; ++ z)
	{
	int i, j, l;
	ULL k;
	cube a = cube();
	k = HASH(a);
	M[k % MOD].push_back(k);
	q.push(a);
	j = 0;
	while (!q.empty())
	{
		cube p = q.front(); q.pop();
		j = max(j, p.step);
		//if (p.step >= 4) continue;
		cube tmp = U(p);
		insert(tmp);
		tmp = L(p);
		insert(tmp);
		tmp = F(p);
		insert(tmp);
		tmp = rU(p);
		insert(tmp);
		tmp = rL(p);
		insert(tmp);
		tmp = rF(p);
		insert(tmp);
	}
	int ans = 0;
	for (i = 0; i < MOD; ++ i) ans += M[i].size();
	//printf("%d   %d\n", ans, j);
	}
}

