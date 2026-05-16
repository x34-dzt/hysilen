#include "executor.h"
#include "linenoise.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define SHELL_NAME "hysilen"

int main() {
  while (1) {
    char *line = linenoise("hysilen> ");
    if (line == NULL)
      break;
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
      free(line);
      break;
    }
    free(line);
  }
  return 0;
}
