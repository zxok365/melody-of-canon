#include <cstdio>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
const double eps = 1e-8;
const int maxn = 1000;
const int maxf = maxn * 10;
inline int Sign(double a) {
	return a < -eps ? -1 : a > eps;
}
inline double Sqr(double a) {
	return a * a;
}
inline double Sqrt(double a) {
	return a <= 0 ? 0 : sqrt(a);
}
struct Point {
	double x, y, z;
	Point() {
	}
	Point(double x, double y, double z) : x(x), y(y), z(z) {
	}
	void Input() {
		scanf("%lf %lf %lf", &x, &y, &z);
	}
	double Length() const {
		return Sqrt(Sqr(x) + Sqr(y) + Sqr(z));
	}
	Point Unit() const;
};
bool operator == (const Point &a, const Point &b) {
	return !Sign(a.x - b.x) && !Sign(a.y - b.y) && !Sign(a.z - b.z);
}
bool operator < (const Point &a, const Point &b) {
	int s1 = Sign(a.x - b.x);
	int s2 = Sign(a.y - b.y);
	int s3 = Sign(a.z - b.z);
	return s1 ? s1 < 0 : s2 ? s2 < 0 : s3 < 0;
}
Point operator + (const Point &a, const Point &b) {
	return Point(a.x + b.x, a.y + b.y, a.z + b.z);
}
Point operator - (const Point &a, const Point &b) {
	return Point(a.x - b.x, a.y - b.y, a.z - b.z);
}
Point operator * (const Point &a, const double &b) {
	return Point(a.x * b, a.y * b, a.z * b);
}
Point operator / (const Point &a, const double &b) {
	return Point(a.x / b, a.y / b, a.z / b);
}
Point Point::Unit() const {
	return *this / Length();
}
Point Det(const Point &a, const Point &b) {
	return Point(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}
double Dot(const Point &a, const Point &b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
double Mix(const Point &a, const Point &b, const Point &c) {
	return Dot(a, Det(b, c));
}
double Dist(const Point &a, const Point &b, const Point &c) {
	return Det(a - c, b - c).Length() / (a - b).Length();
}
double Area(const Point &a, const Point &b, const Point &c) {
	return Det(b - a, c - a).Length() / 2;
}
double Volume(const Point &a, const Point &b, const Point &c, const Point &d) {
	return Mix(b - a, c - a, d - a) / 6;
}
int face[maxf][3];
Point posi[maxn], normal[maxf];
int mark[maxn][maxn];
int n,lf;
void Init() {
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
		posi[i].Input();
	sort(posi, posi + n);
	n = unique(posi, posi + n) - posi;
}
void Add_Face(int a, int b, int c) {
	face[lf][0] = a;
	face[lf][1] = b;
	face[lf][2] = c;
	lf++;
}
bool Find_Tetrahedron() {
	int i, j;
	for (i = 2; i + 1 < n; i++) 
		if (Sign(Dist(posi[0], posi[1], posi[i]))) {
			swap(posi[2], posi[i]);
			for (j = i + 1; j < n; j++) 
				if (Sign(Volume(posi[0], posi[1], posi[2], posi[j]))) {
					swap(posi[3], posi[j]);
					lf = 0;
					Add_Face(0, 1, 2);
					Add_Face(0, 2, 1);
					return 1;
				}
		}
	return 0;
}
void Add_Point(int v) {
	static int cnt = 0;
	cnt ++;
	int i, a, b, c, _lf = 0;
	for (i = 0; i < lf ; i ++) {
		a = face[i][0];
		b = face[i][1];
		c = face[i][2];
		if (Sign(Volume(posi[v], posi[a], posi[b], posi[c])) < 0)
				mark[a][b] = mark[b][a] = mark[a][c] = mark[c][a] = mark[b][c] = mark[c][b] = cnt;
		else
			memcpy(face[_lf++], face[i], sizeof face[i]);
	}
	lf = _lf;
	for (i = 0; i < _lf; i++){
		a = face[i][0];
		b = face[i][1];
		c = face[i][2];
		if (mark[a][b] == cnt) Add_Face(b, a, v);
		if (mark[b][c] == cnt) Add_Face(c, b, v);
		if (mark[c][a] == cnt) Add_Face(a, c, v);
	}
}

void Work(){
	int ans = 0;
	random_shuffle(posi, posi + n);
	int i, j;
	if (Find_Tetrahedron()){
		for (i = 0 ;i < n; i++)
			for (j = 0; j< n; j++)
				mark[i][j] = 0;
		for (i = 3; i < n; i++)
			Add_Point(i);
		for (i = 0 ; i< lf; i++)
			normal[i] = Det(posi[face[i][1]] - posi[face[i][0]], posi[face[i][2]] - posi[face[i][0]]).Unit();
		sort(normal, normal + lf);
		ans = unique(normal, normal + lf) - normal;
	}
//	printf("%d\n", ans);
/*	for (int i = 0; i < ans; i++)
		cout << normal[i].x << ' ' << normal[i].y << ' ' << normal[i].z << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0;j  < n ;j++)
			cout << mark[i][j];
		cout << endl;
	}*/
	double tot_ans = 0;
	for (int i = 0 ; i < lf; i++)
	{
		double now_ans = Area(posi[face[i][0]], posi[face[i][1]], posi[face[i][2]]);
		tot_ans = tot_ans + now_ans;
		//cout << face[i][0] << ' ' << face[i][1] << ' ' << face[i][2] << endl;
	}
	printf("%.5f\n", tot_ans);
//	for (int l = 0; l <= lf; l++)
//	{
	//	for (int i = 0; i < n; i ++)
	//		for (int j = i + 1; j < n; j++)
	//		for (int k = j + 1; k < n; k++)
	//			double now_ans = Area(posi[i], posi[j], posi[k]);
}

int main(){
	srand(time(0));
	int t, i;
	Init();
	Work();
}
