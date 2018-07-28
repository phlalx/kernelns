#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER 100

void die() {
  perror("error");
  exit(1);
}

int son() {
  pid_t id = getpid();
  printf("my pid is %d\n", id);
  char buffer[BUFFER] = { 0 };
  if (getcwd(buffer, BUFFER) == 0) {
    die();
  }
  printf("my working dir is %s\n", buffer);
  return 0;
}

int main() {
  if (chroot("jail") || chdir("/") || unshare(CLONE_NEWPID)) {
    die();
  }
  pid_t id;
  switch (id = fork()) {
    case 0:
      son();
      break;
    case -1:
      exit(-1);
    default:
      printf("My son's pid is %d\n", id);
      wait(NULL);
  }

}
