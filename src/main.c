#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 100


void simple_shell(){
    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    while(1){
        printf("myShell>");
        fflush(stdout);

        // Read input including newline
        if(!fgets(input, MAX_INPUT, stdin)){
            break;
        }
        // Output without the newline
        input[strcspn(input, "\n")] = '\0';
        /*removes the newline character (\n) from a string read by fgets() 
            by replacing it with a null terminator (\0).*/

        // Tokenize input into arguments
        int arg_count = 0;
        char * token = strtok(input, " ");
        while(token != NULL){
            args[arg_count++] = token;
            token = strtok(NULL , " "); // continue tokenizing the same string that was passed in the first call.
        }
        args[arg_count] = NULL;

        //str1 == str2 (This checks if str1 and str2 point to the same memory address, not if the contents are the same.)
        if(arg_count > 0 && strcmp(args[0],"exit")){
            break;
        }
        pid_t pid = fork();
        if(pid < 0){ // Fork Failed
            perror("fork failed");
        }else if(pid == 0){ //Child Process
            execvp(args[0], args);
            perror("exec failed");
            exit(1);
        }else{ // Parent Process
            waitpid(pid, NULL, 0 );
        }
    }
}

int main()
{
    simple_shell();
}
