#include <ctype.h>
#include <stdio.h>
#include <string.h>

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

    if (strcmp(args[0], "exit") == 0) {
      break;
    }

    for (int i = 0; args[i] != NULL; i++) {
      printf("args[%d]: %s\n", i, args[i]);
    }
  }
  return 0;
}
