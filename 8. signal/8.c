#include"apue.h"
#include<signal.h>
#include <sys/wait.h>

static void sig_int(int);   /*duel this*/

int main(void)
{
    char    BUF[MAXLINE];
    pid_t   pid;
    int     status;

    if(signal(SIGINT,sig_int) == SIG_ERR)
    {
        err_sys("signal error");
    }

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

void sig_int(int signo)
{
    printf("Interrupt!\n%%");
}