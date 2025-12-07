#ifndef MY_STDIO_H
#define MY_STDIO_H

#include <unistd.h>
#include <stdlib.h>

#define EOF (-1)
#define BUFSIZE 1024

typedef struct _iobuf {
    int cnt;
    char *ptr;
    char *base;
    int flag;
    int fd;
} FILE;

enum _flags {
    _READ  = 01,
    _WRITE = 02,
    _UNBUF = 04,
    _EOF   = 010,
    _ERR   = 020
};

#endif

