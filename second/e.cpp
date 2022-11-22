#include <stdio.h>

int main() {
	int n, m; scanf("%d %d", &n, &m);
	int a[1000005];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	while (m--) {
		int x; scanf("%d", &x);
		int l = 0, r = n - 1;
		while (l < r) {
			int m = (l + r) >> 1;
			if (a[m] < x) l = m + 1;
			else r = m;
		}
		if (a[l] != x) printf("-1 ");
		else printf("%d ", l + 1);
	}
	return 0;
}