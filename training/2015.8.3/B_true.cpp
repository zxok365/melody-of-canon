#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n;
int N;
int f[21111];
bool bo[21111];
vector<int> move[21111];
vector<int> a,b;
int nxt[21111];
int now_delta;
int now[21111];
int oppo[21111];
long long m[21111], r[21111];
int cnt;
long long MM;

void clear(){
	cnt = 0;
}


void add(int p, int q){
	m[++cnt] = p;
	r[cnt] = q;
}




long long gcd(long long p, long long q){
	return (q == 0 ? p : gcd(q, p % q));
}

inline void euclid(const long long  &a, const long long &b, long long &x, long long &y){
	if (b == 0){
		x = 1;
		y = 0;
	} else {
		euclid(b, a % b, x, y);
		x -= a / b * y;
		swap(x, y);
	}
}


long long multiplyMod(long long a, long long b, long long p){
	long long t = (a * b - (long long )((long double)a / p * b + 1e-3) * p) % p;
	return t < 0 ? t + p : t;
}
inline bool crt(int n ,long long r[], long long m[], long long &remainder, long long &modular)
{
	remainder = modular = 1;
	for (int i = 1; i <= n; i++)
	{
		long long x, y;
		euclid(modular, m[i], x, y);
		long long divisor = gcd(modular, m[i]);
		if ((r[i] - remainder) % divisor){
			return false;
		}
		x *= (r[i] - remainder) / divisor;
		remainder += multiplyMod(modular,x, modular * (m[i] / divisor));
		modular *= m[i] / divisor;
		((remainder %= modular) += modular) %= modular;
	}
	return true;
}
int main(){
	while (1){
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 1; i <= 5 * n; i++)
			scanf("%d", &f[i]);
		for (int i = 0; i < n; i++)
		{
			nxt[i * 5 + 1] = 2 * i + 1;
			nxt[i * 5 + 2] = 2 * i + 2;
			nxt[i * 5 + 3] = 2 * i + 1 + 2 * n;
			nxt[i * 5 + 4] = 2 * i + 2 + 2 * n;
			nxt[i * 5 + 5] = i + 1 + 4 * n;
			for (int j = 1; j <= 5; j++)
				now[i * 5 + j] = i + 1;
		}
		N = 5 * n;
		for (int i = 1; i <= N; i++) oppo[i] = 0;
		for (int i = 1; i <= N; i++)
			oppo[nxt[i]] = i;

		for (int i = 1; i <= N; i++) bo[i] = false, move[i].clear();
		for (int t = 1; t <= N; t++)
		{
			int pp = t;
			while (bo[pp] == false){
				bo[pp] = true;
				move[t].push_back(pp);
				pp = oppo[pp];
			}
		}
	

		long long tot_ans = -1;
		int now_player = 0;
		for (int t = 1; t <= n; t++)
		{
			bool bo = true;
			clear();
			for (int i = 1;i <= N;i++)
			{
				a.clear();
				b.clear();
				int len = move[i].size();
				for (int j = 0; j < len; j++)
				{
					if (now[move[i][j]] == t) b.push_back(j);
					if (f[move[i][j]] <= 5) a.push_back(j);
				}
				if (a.size() != b.size())
				{
					bo = false;
					break;
				}
				
				if (a.size() == 0) continue;
				int now_size = a.size();
				int ttt = 0;
				int now_delta = 10000000;
				for (int j = 0; j < now_size; j++)
				{
					int delta = (b[j] + len - a[0]) % len;
					bo = true;
					for (int k = 1; k < now_size; k++)
					{
						int another = (j + k) % now_size;
						if (delta != (b[another] + len - a[k]) % len){
							bo = false;
							break;
						}
					}
					if (bo == true)
					{
						ttt ++;
						now_delta = min(now_delta,(b[j] + len - a[0]) % len);
						//break;
					}
				}
				if (ttt == 0)
				{
					bo = false;
					break;
				}
				bo = true;
				add(len / ttt, now_delta);
			}
			if (!bo) continue;
			long long now_ans = 0;
			if (cnt == 0 || !crt(cnt, r, m, now_ans, MM)){
				bo = false;
				continue;
			} else
			{
				if (now_ans == 0) now_ans += MM;
				if (now_ans < tot_ans || tot_ans == -1){
					now_player = t;
					tot_ans = now_ans;
				}
			}
		}
		if (now_player != 0)
		{
			printf("Player %d wins game number ", now_player);
			cout << tot_ans << '.' << endl;
		}
		else
			printf("Neverending game.\n");
	}

}
