void FastReduction(unsigned char *data, unsigned char *result){
    __m128i X0,X1,X2,X3,A,B,C,D,temp,E1,E0,F1,F0,G1,G0,H1,H0,H;
	
    // Load data into SSE registers
    X0 = _mm_loadl_epi64((__m128i*)(data));
    X1 = _mm_loadl_epi64((__m128i*)(data+8));
    X2 = _mm_loadl_epi64((__m128i*)(data+16));
    X3 = _mm_loadl_epi64((__m128i*)(data+24));
    
    // Step 1: Shift X3 by 63, 62, and 57 bits to the right
    A = _mm_srli_epi64(X3, 63);
    B = _mm_srli_epi64(X3, 62);
    C = _mm_srli_epi64(X3, 57);
    
    // Step 2: XOR A, B, and C with X2 to compute D
    D = _mm_xor_si128(_mm_xor_si128(_mm_xor_si128(X2, A), B), C);
    
    // Step 3: Shift [X3:D] by 1, 2, and 7 bits to the left
    E1 = _mm_or_si128(_mm_slli_epi64(X3, 1), _mm_srli_epi64(D, 63));
    E0 = _mm_slli_epi64(D,1);
    	
    F1 = _mm_or_si128(_mm_slli_epi64(X3, 2), _mm_srli_epi64(D, 62));
    F0 = _mm_slli_epi64(D,2);
    	
    G1 = _mm_or_si128(_mm_slli_epi64(X3, 7), _mm_srli_epi64(D, 57));
    G0 = _mm_slli_epi64(D,7);
    	
    // Step 4: XOR [E1:E0], [F1:F0], and [G1:G0] with each other and [X3:D] to compute [H1:H0]
    //[H1 : H0 ] = [ X3 ⊕ E1 ⊕ F1 ⊕ G1 : D ⊕ E0 ⊕ F0 ⊕ G0 ]
    H1 = _mm_xor_si128(_mm_xor_si128(_mm_xor_si128(X3, E1), F1), G1);
    H0 = _mm_xor_si128(_mm_xor_si128(_mm_xor_si128(D, E0), F0), G0);
    
    // Compute the final result: [X1 ⊕ H1 : X0 ⊕ H0]
    H1 = _mm_xor_si128(X1, H1);
    H0 = _mm_xor_si128(X0, H0);
    	
    // Combine [H1:H0] to a single 128-bit register
    H = _mm_unpacklo_epi64(H0, H1);

    // Store the result
    _mm_storeu_si128((__m128i*)result, H);		
}

