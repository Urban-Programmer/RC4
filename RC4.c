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
    -- key
*/


//Global Vars
// char *crypt;
// char *salt;
// char *input_path;
// char *output_path;
// char *key;




void decrypt(const unsigned char *input_path, const char *output_path, const char *key){
    FILE* outfile = fopen(output_path, "wb");
    FILE* infile = fopen(input_path, "rb");

    //Error Handling if they're NULL
    if (infile == NULL){
        printf("Cannot open input file\n");
        return;
    }
    if (outfile == NULL){
        printf("Cannot open output file\n");
        return;
    }
    if (key == NULL){
        printf("No Key entered... exiting\n");
        return;
    }

    int key_len = strlen(key);
    RC4_KEY rc4_key;
    RC4_set_key(&rc4_key, key_len, key);

    unsigned char buffer[4096];
    int num_bytes;
    while ((num_bytes = fread(buffer, 1, sizeof(buffer), infile)) > 0) {
        RC4(&rc4_key, num_bytes, buffer, buffer);
        fwrite(buffer, 1, num_bytes, outfile);
    }

    fclose(infile);
    fclose(outfile);


}

char byteEncrypt(char* output_path){
    unsigned char key[] = "mysecretkey";
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



// char *input_path, char *output_path, char* salt, char* key
void encrypt (const char* output_path, const char* input_path, const char* key){
        
    FILE* outfile = fopen(output_path, "wb");
    FILE* infile = fopen(input_path, "rb");

    //Error Handling if they're NULL
    if (infile == NULL){
        printf("Cannot open input file\n");
        return;
    }
    if (outfile == NULL){
        printf("Cannot open output file\n");
        return;
    }
    if (key == NULL){
        printf("No Key entered... exiting\n");
        return;
    }

    // Initialize the RC4 key context with the key 
    int key_len = strlen(key);
    RC4_KEY rc4_key;
    RC4_set_key(&rc4_key, key_len, key);

    // Encrypt each byte of the input file using RC4 and write to output file
    unsigned char inbuf;
    unsigned char outbuf;
    size_t bytes_read = fread(&inbuf, 1, sizeof(inbuf), infile);
    while (bytes_read > 0) {
        RC4(&rc4_key, 1, &inbuf, &outbuf);
        fwrite(&outbuf, 1, sizeof(outbuf), outfile);
        bytes_read = fread(&inbuf, 1, sizeof(inbuf), infile);
    }

    // Cleanup
    fclose(infile);
    fclose(outfile);

}



int main(int argc, char *argv[]) {

    // Test Script:
    // ./test option salt ../AWS-Fuse/example2.txt ../AWS-Fuse/


    //Variable Assignment
    char *crypt = argv[1];
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


    //Encrypt Byte

    //encrypt(output_path, input_path, key);
    decrypt(input_path, output_path, key);



    
    printf("Arg: %d\n", argc);


    exit(0);
}