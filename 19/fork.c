#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  pid_t pid;
  int gval = atoi(argv[1]);
  printf("global gval: %d \n", gval);
  pid = fork();
  if (pid == 0) {
    // Child process
    gval-=20;
  } else {
    // Parent process
    gval+=20;
  }

  if (pid == 0) {
    // Child process
    printf("Chird Proc: [%d]\n", gval);
  } else {
    // Parent process
    printf("Parent Proc: [%d]\n", gval);
  }
  return 0;
}