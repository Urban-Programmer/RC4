#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

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

void decrypt(){
    //Decrypt AES

}

void encrypt(){
    //Implement AES

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



    
    printf("Arg: %d\n", argc);


    exit(0);
}