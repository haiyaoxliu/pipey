#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int WRITE = 1;
  int READ = 0;
  int f, r;
  int p1[2];
  int p2[2];

  pipe(p1);
  pipe(p2);
  srand(time(NULL));
  f = fork();


  if(f) {

    close(p1[READ]);
    close(p2[WRITE]);

    r = rand() % 10;
    write(p1[WRITE], &r, sizeof(int));

    printf("[parent] sending: %d\n", r);

    read(p2[READ], &r, sizeof(int));
    printf("[parent] received: %d\n", r);
    
  }

  if(!f) {

    close(p1[WRITE]);
    close(p2[READ]);

    read(p1[READ], &r, sizeof(int));

    printf("[child] doing maths on: %d\n", r);
    r = (r * rand()) % 10;

    write(p2[WRITE], &r, sizeof(int));
    
  }


  return 0;
}
