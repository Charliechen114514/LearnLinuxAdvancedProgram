#include "apue.h"

int main()
{
    printf("Current UID is %d, gid is %d\n",getuid(),getgid());
    exit(0);
}