# Galois-field-128-bits-
-----------Multiplication in GF(2^128) field-------------

Implemented :
  1. (carryless_karatsuba.h): a carry-less Karatsuba multiplication algorithm  using carry-less multiplication instructions (called PCLMULQDQ) for multiplyting two binary polynomials of degree 127 (i.e, two 128 bits binary numbers) and
  2. (FastReduction.h): Fast reduction algorithm for reducing a binary polynomial of degree 254 (basically the carry-less multiplication result of above), modulo the x^128+x^7+x^2+x+1 (which deﬁnes the ﬁnite ﬁeld of the Galois Counter Mode)) in GF(2^128) field.

* To refer to the documentation or details of the two algorithms I have implemented, please consult the file named "1-s2.0-S002001901000092X-main.pdf".
* I have implemented the two algorithms using SIMD instructions (Intel intrinsics).
* Compilation flags: gcc -o main main.c -msse -mpclmul
* Note, provide 16 bytes long hex numbers as inputs for elements of field GF(2^128). 

     
