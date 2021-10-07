#include "kutils.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// print an error message and exit
void die(const char* fmt, ...) {
  va_list arg;

  va_start(arg, fmt);
  vfprintf(stderr, fmt, arg);
  if (fmt && fmt[strlen(fmt) - 1] == ':') {
    fputc(' ', stderr);
    perror(NULL);
  } else {
    fputc('\n', stderr);
  }
  va_end(arg);

  exit(EXIT_FAILURE);
}

// malloc with error-checking
void* safe_malloc(size_t size) {
  void* ptr = malloc(size);
  if (!ptr) {
#ifdef DEBUG

    fprintf(stderr, "[DEBUG] malloc: ");
    perror(NULL);

#else

    die("malloc:");

#endif // DEBUG
  }

  return ptr;
}

// calloc with error-checking
void* safe_calloc(size_t nmemb, size_t size) {
  void* ptr = calloc(nmemb, size);
  if(!ptr) {
#ifdef DEBUG

    fprintf(stderr, "[DEBUG] calloc: ");
    perror(NULL);

#else

    die("calloc:");

#endif // DEBUG
  }

  return ptr;
}
