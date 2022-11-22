#include <stdio.h>

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		char a[30], b[30];
		scanf("%s %s", a, b);
		int n = 0, m = 0;
		for (int i = 0; i < 30; i++) {
			if (a[i] == '\0') break;
			else {
				n++;
			}
		}
		for (int i = 0; i < 30; i++) {
			if (b[i] == '\0') break;
			else {
				m++;
			}
		}
		bool judge = false;
		for (int i = 0; i <= n - m + 1; i++) {
			for (int j = i, z = 0; j <= n && z <= m; j++, z++) {
				if (a[j] != b[z]) break;
				if (z + 1 == m) judge = true;
			}
		}
		if (!judge) printf("no\n");
		else printf("yes\n");
	}
	return 0;
}