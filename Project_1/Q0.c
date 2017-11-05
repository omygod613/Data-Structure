/* CS261- Assignment 1 - Q. 0*/
/* Name:I-Shen Liao
 * Date:Oct. 2, 2016
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

int fooB(int* a, int* b, int c) {
    
    c= *a+ *b;
    
    *a= *b;
    
    *b=*b *2;
    
    return c;
}


void fooA(int* iptr){
    
    printf("the value of integar pointed by iptr is %d\n", * iptr);
    printf("the address pointed to by iptr %p\n", iptr);
    printf("the address of iptr itself %p\n", &iptr);
    
}

int main(){
    
    int x;  /* declare an integer x */
    
    printf("the address of x is %p\n", &x);/* print the address of x */
    
    fooA(&x);/* Call fooA() with the address of x */
    
    printf("the value of x is %d\n", x);/* print the value of x */
    
    return 0;
}
