#include "executor.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define SHELL_NAME "hysilen"

int main() {
  size_t line_size = 1024;
  char line[line_size];

  while (1) {
    printf("%s> ", SHELL_NAME);
    if (fgets(line, line_size, stdin) == NULL) {
      break;
    };

    line[strcspn(line, "\n")] = '\0';

    char *p = line;
    char *args[64];
    int argc = 0;

    while (*p != '\0') {
      while (isspace((unsigned char)*p)) {
        p++;
      }

      if (*p == '\0') {
        break;
      }

      args[argc++] = p;

      while (*p != '\0' && !isspace((unsigned char)*p)) {
        p++;
      }

      if (*p != '\0') {
        *p++ = '\0';
      }
    }
    args[argc] = NULL;
    if (argc == 0) {
      printf("Please enter a command.\n");
    } else if (execute_command(args) < 0) {
      break;
    }
  }
  return 0;
}
