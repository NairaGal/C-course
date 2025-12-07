#include "my_stdio.h"

int _flushbuf(int c, FILE *fp)
{
    int num_written;

    if ((fp->flag & _WRITE) == 0)
        return EOF;

    if (fp->base == NULL && !(fp->flag & _UNBUF)) {
        fp->base = malloc(BUFSIZE);
        if (fp->base == NULL) {
            fp->flag |= _ERR;
            return EOF;
        }
    }

    int bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZE;

    if (fp->base != NULL) {
        num_written = write(fp->fd, fp->base, fp->ptr - fp->base);
        if (num_written < 0) {
            fp->flag |= _ERR;
            return EOF;
        }
    }

    fp->ptr = fp->base;
    fp->cnt = bufsize - 1;

    *fp->ptr++ = c;

    return c;
}

int fflush(FILE *fp)
{
    if (fp == NULL)
        return 0;

    if (!(fp->flag & _WRITE))
        return EOF;

    if (fp->base == NULL)
        return 0;

    int len = fp->ptr - fp->base;

    if (write(fp->fd, fp->base, len) != len) {
        fp->flag |= _ERR;
        return EOF;
    }

    fp->ptr = fp->base;
    fp->cnt = (fp->flag & _UNBUF) ? 1 : BUFSIZE;

    return 0;
}

int fclose(FILE *fp)
{
    int result = 0;

    if (fp->flag & _WRITE)
        result = fflush(fp);

    if (fp->base != NULL)
        free(fp->base);

    if (close(fp->fd) < 0)
        result = EOF;

    fp->cnt  = 0;
    fp->ptr  = NULL;
    fp->base = NULL;
    fp->flag = 0;
    fp->fd   = -1;

    return result;
}

