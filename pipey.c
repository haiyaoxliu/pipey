#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

int main(int argc, char *argv[]){ 
  
  int pid; 
  int p[2];   /* pipe "p" */
  int q[2];   /* pipe "q" */
  int a; 
  int b; 
  
  /* Create Pipe. Pipe P is used to transfer information  
     from the parent process to the child process */
  a = pipe(p);
  if(a == -1) 
    { 
      fprintf(stderr, "Pipe Failed.\n"); 
      return EXIT_FAILURE; 
    } 
          
  /* Create second pipe. Pipe Q is used to transfer information 
     from the child process to the parent process. */
  b = pipe(q); 
  if(b == -1) 
    { 
      fprintf(stderr, "Pipe Failed.\n"); 
      return EXIT_FAILURE; 
    } 
          
  /* Create child process */
  pid = fork(); 
  
  switch(pid){ 
          
  case -1: /* fork failed */
    perror("main: fork"); 
    exit(1); 
                 
    /* Child process will execute a loop, waiting for command
        from the parent process. Child executes the command. Child
        returns a response to the parent */
  case 0: /* Child process */
    printf("Child process ID: %d\n", pid);
    break;
    /* do some things */
  
    /* Parent process will execute a loop, asking user for a one
        line command. Parent sends command to child for execution.
        Parent waits for the response of the child. Parent finally
        reports the result (displayed on screen). */
  default: /* Parent process */
    printf("Parent process ID: %d\n", pid);
    break;
    /* do some things */
  } 
  getchar();
  return 0; 
}
