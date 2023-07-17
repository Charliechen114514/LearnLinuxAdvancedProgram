#include "apue.h"
#include<fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
    int fd;
    if(
        (fd = creat("file.hole",FILE_MODE)) < 0
    ){
        err_sys("create error\n");
    }

    if(
        write(fd,buf1,10) != 10
        ){
            err_sys("Fetch error in writing buf1\n");
        }
    /*Caution for offset now == 10*/

    if(
        lseek(fd,40,SEEK_SET) == -1
    ){
        err_sys("lseek error");
    }

    if(write(fd,buf2,10) != 10){
        err_sys("Fetch error in writing buf2\n");
    }
    /*Caution for offset now == 10*/
    /* NOW IS 50 */
    exit(0);
}   