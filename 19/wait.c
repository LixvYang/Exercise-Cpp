#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  int status;
  pid_t pid = fork();

  if (pid == 0) {
    sleep(1);
    return 3;
  } else {
    printf("Child PID: %d \n", pid);
    pid = fork();
    if (pid == 0) {
    sleep(1);

      exit(7); 
    } else {
      printf("Child PID: %d \n", pid);
      wait(&status);
      if (WIFEXITED(status)) {
        printf("Child send one: %d \n", WEXITSTATUS(status));
      }
      wait(&status);
      if (WIFEXITED(status)) {
        printf("Child send two: %d \n", WEXITSTATUS(status));
      }
      sleep(30);
    }
  }
  return 0;
}
