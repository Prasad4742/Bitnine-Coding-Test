int F(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    int a = 0, b = 1, c = 2, d;
    for (int i = 3; i <= n; i++) {
        d = c + a;
        a = b;
        b = c;
        c = d;
    }
    return c;
}
