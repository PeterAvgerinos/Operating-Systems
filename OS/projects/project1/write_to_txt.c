#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/stat.h>

bool file_exists (char *filename) {
  struct stat   buffer;   
  return (stat (filename, &buffer) == 0);
}

int main(int argc, char* argv[]){ 

    if (argc == 1){ 
        printf("Usage ./a.out output.txt\n");
        exit(1);
    }

    char *prompt = strdup(argv[1]);

    if (strcmp( prompt, "--help") == 0 || argc != 2){ 
        printf("Usage ./a.out output.txt\n");
        exit(1);
    }

    if (file_exists(prompt)) { 
        printf("Error: %s already exists\n", prompt);
        exit(1);
    }

    FILE *fp;
    int status;
    fp = fopen(prompt, "w");
    pid_t child = fork();


    if (child < 0){ 
        exit(1);
    }

    if (child == 0){ 
        pid_t child_id = getpid();
        fprintf(fp,"I am child %d\n", child_id);
    }
    else {
        pid_t parent_id = getppid();
        fprintf(fp,"I am parent %d\n", parent_id);
    }
    fclose(fp);

    wait(&status);
    free(prompt);

    exit(0);
}


