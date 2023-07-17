#include"apue.h"
#include <sys/wait.h>
int main(void)
{
    char    BUF[MAXLINE];
    pid_t   pid;
    int     status;

    printf("%% ");  /* be aware that we need to use %% to print out a %! */
    while(
        fgets(BUF,MAXLINE,stdin) != NULL
    )
    {
            if(BUF[strlen(BUF) - 1] == '\n')
            {
                BUF[strlen(BUF) - 1] = '\0'; /* a typical process to get a usable string*/
            }
    

        if(
            (pid = fork()) < 0
        )
        {
            err_sys("Catch a fatal error from fork");
        }
        else if (pid == 0)
        {
            execlp(BUF,BUF,(char*)0);
            err_ret("could not executae the %s",BUF);
            exit(127);
        }

        /* parent */
        if(
            (pid = waitpid(pid,&status,0)) < 0 
        ){
            err_sys("waitpid error");
        }
        printf("%% ");
    }
    exit(0);
}