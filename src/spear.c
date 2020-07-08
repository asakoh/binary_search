#include <stdio.h>

int n;
int k;
int A[100000];
int p(int x) {
    int i, sum = 0;
    for (i = 0; i < n; i++) {
        sum = sum + A[i] / x;
    }
    return k > sum; //槍が作れなくなると1を返す
}


int main() {
    int i, lb, ub;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int max = 0;
    for (i = 0; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    lb = 0;
    ub = max+1;

    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (p(mid)) {
            ub = mid;
        }
        else {
            lb = mid;
        }
    }
    printf("%d\n", lb);
    return 0;
}