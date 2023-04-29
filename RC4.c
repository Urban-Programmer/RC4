#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/rc4.h>


/*
    Program should take the following inputs from user:
    -- decrypt or encrypt 
    -- salt?
    -- input file
    -- output file
*/



// Will probably move these functions to their seperate files
void salt(){
    //Salt must occur before encryption

}


// char *input_path, char *output_path, char* salt, 
void RC4(){ 
    unsigned char key[] = "Hello";
    unsigned char plaintext[] = "Hello World!";
    unsigned char cipher[sizeof(plaintext)];

    int key_len = strlen(key);
    int plaintext_len = strlen(plaintext);

    //RC4 Key creation
    RC4_KEY rc4_key;
    RC4_set_key(&rc4_key, key_len, key);

    // Cipher Text
    RC4(&rc4_key, plaintext_len, plaintext, cipher);

    printf("Encrypted data: ");
    for (int i = 0; i < plaintext_len; i++) {
        printf("%02x", cipher[i]);
    }
    printf("\n");
    printf("Decrypted data: %s\n", plaintext);

 
}


int main(int argc, char *argv[]) {

    // Test Script:
    // ./test option salt ../AWS-Fuse/example2.txt ../AWS-Fuse/


    //Variable Assignment
    char *option = argv[1];
    char *salt = argv[2];
    char *input_path = argv[3];
    char *output_path = argv[4];
    char *key = argv[5];
    

    //Above Variables will require error checking @ some point in time
    FILE *output_file = fopen(output_path,"w");

    //instead this should encrypt the file
    char* test = "heyo!";


    //
    fwrite(test, 1, strlen(test), output_file);
    fclose(output_file);

    RC4();



    
    printf("Arg: %d\n", argc);


    exit(0);
}