#include <unistd.h>
#include <stdio.h>

int gval = 10;
int main(int argc, char const *argv[])
{
  pid_t pid;
  int lval= 20;
  gval++, lval+=5;
  pid = fork();
  if (pid == 0) {
    gval+=2, lval+=2;
  } else {
    gval-=2, lval-=2;
  }

  if (pid == 0) {
    printf("Chird Proc: [%d, %d]\n", gval, lval);
  } else {
    printf("Parent Proc: [%d, %d]\n", gval, lval);
  }
  return 0;
}
