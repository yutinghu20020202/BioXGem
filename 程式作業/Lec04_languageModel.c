    #include<stdio.h>

    int main () {
        double a1, a2, a3, a4, a5;
        scanf("%lf %lf %lf %lf %lf", &a1, &a2, &a3, &a4, &a5);
        double result = a1*a2*a3*a4*a5;
        printf("%.15lf\n", result);
        return 0;
    }