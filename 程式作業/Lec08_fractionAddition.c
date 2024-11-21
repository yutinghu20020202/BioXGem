#include <stdio.h>

int GCD (int a, int b){
     if (a%b == 0){ 
        return b;
    }else {
        return GCD (b, a%b);
    }
}
                
void fraction_adder(int a_numerator, int a_denominator, int b_numerator,
              int b_denominator, int *c_numerator_ptr, int *c_denominator_ptr){
                
                int denominator = a_denominator * b_denominator;
                int numerator = (a_numerator * b_denominator) + (b_numerator * a_denominator);

                int result = GCD (numerator, denominator);
                //int result = GCD (c_numerator_ptr, c_denominator_ptr);*c_numerator跟c_numerator的type不一樣

                *c_numerator_ptr = numerator / result;
                *c_denominator_ptr = denominator / result;

}




int main() {
  int a_numerator, a_denominator, b_numerator, b_denominator;
  scanf("%d%d%d%d", &a_numerator, &a_denominator, &b_numerator, &b_denominator);
  int c_numerator, c_denominator;
  fraction_adder(a_numerator, a_denominator, b_numerator, b_denominator, &c_numerator,
           &c_denominator);
  printf("%d/%d\n", c_numerator, c_denominator);
}