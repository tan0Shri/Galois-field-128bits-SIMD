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
