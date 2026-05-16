#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int execute_command(char *args[]) {
  if (strcmp(args[0], "exit") == 0) {
    return -1;
  }
  pid_t pid = fork();
  if (pid == 0) {
    execvp(args[0], args);
  } else {
    waitpid(pid, NULL, 0);
  }
  return 0;
}

#endif
