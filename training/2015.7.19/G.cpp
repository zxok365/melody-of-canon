#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 505;

int posb[N], posw[N], pos0, n;
vector <int> ans;

void move(int &a) {
	ans.push_back(a);
	swap(a, pos0);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		posw[i] = n - i;
		posb[i] = n + i;
	}

	pos0 = n;
	for (int i = 1; i <= n; i++) {
		if (i & 1) {
			for (int j = 1; j <= i; j++) {
				move(posw[j]);
			}
		} else {
			for (int j = 1; j <= i; j++) {
				move(posb[j]);
			}
		}
	}
	
	int now = n & 1;
	while (1) {
		now ^= 1;
		int ok = 1;
		for (int i = 1; i <= n; i++) {
			if (posb[i] != i - 1 || posw[i] != n + n + 1 - i) {
				ok = 0;
				break;
			}
		}

		if (ok) {
			break;
		}

		if (now) {
			for (int i = 1; i <= n; i++) {
				if (posw[i] < pos0) {
					move(posw[i]);
				}
			}
		} else {
			for (int i = 1; i <= n; i++) {
				if (posb[i] > pos0) {
					move(posb[i]);
				}
			}
		}
	}

	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); i++) {
		printf("%d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');
	}

	return 0;
}

