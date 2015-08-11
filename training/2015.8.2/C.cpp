#include <cstdio>
#include <iostream>

using namespace std;

char s[1000005];

int main() {
	while (scanf("%s", s) == 1) {
		int n = strlen(s);
		int len = 0;
		for (int cur = 0; cur < n; cur ++) {
			if (s[cur] >= '0' && s[cur] <= '9') {
				int chara = get(cur, cur + 1);
				if (is_letter(chara)) {
					if ((Caps ^ Shift) == 1) ans[len++] = Big(chara);
						else ans[len++] = Small(chara);
				} else 
			} else {
			}
		}
	}
	return 0;
}
