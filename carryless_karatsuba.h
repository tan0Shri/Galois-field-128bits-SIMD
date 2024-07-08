//Function for computing carryless karatsuba multiplication
void KaratsubaMul( unsigned char *a, unsigned char *b, unsigned char *c){
    __m128i TMP1,TMP2,TMP3,TMP4,T,H,temp1,temp2;

    T = _mm_loadu_si128((__m128i*)a);
    H = _mm_loadu_si128((__m128i*)b);

    TMP1 = _mm_clmulepi64_si128(T, H, 0x00); //A0*B0
    TMP4 = _mm_clmulepi64_si128(T, H, 0x11); //A1*B1
        
    temp1 = _mm_xor_si128(T, _mm_srli_si128(T, 8)); //(A0+A1)
    temp2 = _mm_xor_si128(H, _mm_srli_si128(H, 8)); //(B0+B1)
        
        
    TMP2 = _mm_clmulepi64_si128(temp1, temp2, 0x00); // (A0+A1)*(B0+B1)
    TMP3 = _mm_xor_si128(TMP2, TMP4);
    TMP3 = _mm_xor_si128(TMP3, TMP1); // (A0+A1)*(B0+B1) - A0*B0 - A1*B1

    TMP2 = _mm_slli_si128(TMP3, 8);
    TMP3 = _mm_srli_si128(TMP3, 8);
    TMP1 = _mm_xor_si128(TMP2, TMP1);
    TMP4 = _mm_xor_si128(TMP4, TMP3);

    _mm_storeu_si128(((__m128i*)c), TMP1); 
    _mm_storeu_si128(((__m128i*)c+1), TMP4); 
}
