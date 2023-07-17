#include"apue.h"

#define BUFFSIZE 8192

int main(void)
{
    int     n;
    char    buf[BUFFSIZE];

    while(
        (n = read(STDIN_FILENO,buf,BUFFSIZE)) > 0
    )
    {
        if(write(STDOUT_FILENO, buf, n) != 0)
            err_sys("Write Error");
    }

    if( n < 0 )
    {
        err_sys("read error");
    }

    exit(0);
}