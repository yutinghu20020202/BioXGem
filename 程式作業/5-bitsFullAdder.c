int full_adder_c(int a, int b ,int c) {
    int temp = a + b + c;
    if(temp >= 2) return 1;
    return 0;
}

int full_adder_x(int a, int b, int c) {
    int temp = a + b + c;
    if(temp == 2 || temp == 0) return 0;
    return 1;
}