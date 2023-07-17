#include<sys/types.h>
#include "apue.h"

int main(void)
{
    if(lseek(STDIN_FILENO,0,SEEK_CUR) == -1)
        printf("Failed seeking!");
    else
        printf("seek able!");

    exit(0);
}