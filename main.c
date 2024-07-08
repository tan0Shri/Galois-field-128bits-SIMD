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

//Function for taking input from stdin
void readBytes(unsigned char *data, int num){
    for(int i=0;i<num;i++)
        scanf("%02hhx", &data[i]);
    if(num<16){
	for(int i=num;i<16;i++)
	    data[i] = 00;
	}		
}
//Function for printing the results into stdout
void printBytes(unsigned char *data, int num) {
    int i, count = 0;
    bool leading_zero_printed = false;  // Flag to track if leading zeros have been printed

    for (i = num - 1; i >= 0; i--) {
        // Check if the current byte is non-zero or if we've already printed a non-zero byte
        if (data[i] != 0 || i == 0 || leading_zero_printed) {
            printf("%02hhx ", data[i]);
            leading_zero_printed = true;  // Set the flag once a non-zero byte is printed
            count += 1;
        }
    }
    printf(": %d bytes\n",count);
}


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





