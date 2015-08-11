#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<ctype.h>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<bitset>
#include<iomanip>
#include<complex>
#include<utility>

#define X first
#define Y second
#define REP_0(i,n) for(int i=0;i<(n);++i)
#define REP_1(i,n) for(int i=1;i<=(n);++i)
#define REP_2(i,a,b) for(int i=(a);i<(b);++i)
#define REP_3(i,a,b) for(int i=(a);i<=(b);++i)
#define REP_4(i,a,b,c) for(int i=(a);i<(b);i+=(c))
#define DOW_0(i,n) for(int i=(n)-1;-1<i;--i)
#define DOW_1(i,n) for(int i=(n);0<i;--i)
#define DOW_2(i,a,b) for(int i=(b);(a)<i;--i)
#define DOW_3(i,a,b) for(int i=(b);(a)<=i;--i)
#define FOREACH(a,b) for(typeof((b).begin()) a=(b).begin();a!=(b).end();++a)
#define RFOREACH(a,b) for(typeof((b).rbegin()) a=(b).rbegin();a!=(b).rend();++a)
#define PB push_back
#define PF push_front
#define MP make_pair
#define IS insert
#define ES erase
#define IT iterator
#define RI reserve_iterator
#define PQ priority_queue
#define LB lower_bound
#define UB upper_bound
#define ALL(x) x.begin(),x.end()

#define PI 3.1415926535897932384626433832795
#define EXP 2.7182818284590452353602874713527

using namespace std;

typedef long long LL;
typedef long double LD;
typedef double DB;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef pair<int,PII> PIII;
typedef pair<LD,int> PLDI;
typedef vector<PII> VII;

inline LL Gcd(LL x,LL y){
	LL z=0;
	while(z=x%y) x=y,y=z;
	return y;
}

int N;

int A[5001];
int B[5001];
int C[5001];

int F[6][5001][2];

int D[6];

LL exGcd(LL x,LL y,LL &a,LL &b){
	if(y==0){
		a=1,b=0;
		return x;
	}
	LL d=exGcd(y,x%y,b,a);
	b=-b-x/y*a;
	a=-a;
	if(a<0||a==0&&b<0) a+=y/d,b+=x/d;
	return d;
}

struct CRT{
	LL x,c;
	CRT(){x=1,c=0;}
	bool Union(LL xx,LL cc){
		LL nx,ny;
		LL f=exGcd(x,xx,nx,ny);
		if(nx<0) nx+=xx/f,ny+=x/f;
		if(c%f!=cc%f) return false;
		/*  nx*x-ny*xx=d */
		LL R=cc-c%xx;
		if(R<0) R+=xx;
		R/=f;
		LL fx=xx/f*x,fc=(c+nx*x*R)%fx;
		x=fx,c=fc;
		return true;
	}
};

int main(){
	while(scanf("%d",&N)==1&&N){
		memset(F,0,sizeof(F));
		REP_1(i,5*N){
			scanf("%d",A+i);
		}
		{
			int cnt=1;
			for(int i=1;i<=N;++i){
				C[cnt++]=i*2-1;
				C[cnt++]=i*2;
				C[cnt++]=2*N+i*2-1;
				C[cnt++]=2*N+i*2;
				C[cnt++]=4*N+i;
			}
			for(int i=1;i<=5*N;++i) B[C[i]]=i;
		}
		REP_1(i,5*N) if(A[i]<=5){
			int c=i,d=A[i],f=0;
			do{
				F[d][c][0]=f++;
				c=B[c];
			}while(c!=i);
			do{
				F[d][c][1]=f;
				c=B[c];
			}while(c!=i);
		}
		LL ans1=-1,ans2=-1;
		REP_1(i,N){
			REP_1(j,5) D[j]=j;
			do{
				bool flag=true;
				for(int j=1;j<=5;++j){
					if(F[j][i*5-5+D[j]][1]==0){
						flag=false;
						break;
					}
				}
				if(flag){
					CRT o;
					for(int j=1;j<=5;++j){
						if(!o.Union(F[j][i*5-5+D[j]][1],F[j][i*5-5+D[j]][0])){
							flag=false;
							break;
						}
					}
					if(flag){
						if(o.c==0) o.c=o.x;
						if(ans1==-1||o.c<ans1) ans1=o.c,ans2=i;
					}
				}
			}while(next_permutation(D+1,D+6));
		}
		if(ans1==-1){
			printf("Neverending game.\n");
		}
		else{
			printf("Player %lld wins game number %lld.\n",ans2,ans1);
		}
	}
	return 0;
}

