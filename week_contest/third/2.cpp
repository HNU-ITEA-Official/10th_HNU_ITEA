#include <stdio.h>

int main() {
    int m, n; scanf("%d %d", &m, &n);
    int n1[205], n2[205];
    for (int i = 0; i < m; i++) scanf("%d", &n1[i]);
    for (int i = 0; i < n; i++) scanf("%d", &n2[i]);
    int ans[500] = {0};
    int i = 0, j = 0, z = 0;
    for (; i < m && j < n;) {
        if (n1[i] < n2[j]) ans[z++] = n1[i++];
        else ans[z++] = n2[j++];
    }
    while (i < m) ans[z++] = n1[i++];
    while (j < n) ans[z++] = n2[j++];
    for (int w = 0; w < z; w++) {
        printf("%d ", ans[w]);
    }
    return 0;
}