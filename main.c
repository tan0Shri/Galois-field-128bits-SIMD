#include<wmmintrin.h>
#include<stdio.h>
#include<stdbool.h>

#define align __attribute__ ((aligned (16)))

#if !defined (ALIGN16)
    # if defined (__GNUC__)
        # define ALIGN16 __attribute__ ( (aligned (16)))
    # else
        # define ALIGN16 __declspec (align (16))
    # endif
#endif

#include "carryless_karatsuba.h"
#include "FastReduction.h"
#include "utilities.h"

int main(){
    int n,m;
    printf("Enter size of the two numbers (no. of bytes): ");
    scanf("%d %d",&n,&m);
 	
    ALIGN16 unsigned char a[16], b[16];
    printf("Enter two hex numbers: ");
    readBytes(a,n);
    readBytes(b,m);

    ALIGN16 unsigned char multiplication[32];
    ALIGN16 unsigned char reduction[16];	
	
    printf("\nInputs:\n");
    printBytes(a,16);
    printBytes(b,16);
    printf("\n");
    
    KaratsubaMul(a,b,multiplication);
    printf("Hex Multiplication Result: \n");
    printBytes(multiplication,32);
    printf("\n");
    
    FastReduction(multiplication,reduction);
    printf("Fast Reduction result:\n");
    printBytes(reduction,16);
    printf("\n");
    
    
    return 0;
	
}





