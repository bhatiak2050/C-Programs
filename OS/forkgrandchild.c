#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void main()
{
    int pid,cpid;
    pid = fork();
    if(pid==0)
    {
        cpid = fork();
        if(cpid==0)
        {
            printf("Iam grandchild in if\n");
            printf("grandchild =  %d\n",pid);
            printf("Child_ID = %d\n",getpid());
            printf("Parent_ID = %d\n\n",getppid());
            // execlp("ps", "ps", (char*)NULL);
        }
        else
        {
            printf("Iam child in else before wait\n");
            wait(0);
            printf("Iam child in else after wait\n");
            printf("child = %d\n",pid);
            printf("Child_ID =%d\n",getpid());
            printf("Parent_ID = %d\n\n",getppid());
        }
    }
    else
    {
        printf("Iam Parent in else before wait\n");
        wait(0);
        printf("Iam Parent in else after wait\n");
        printf("Child_ID = %d\n",pid);
        printf("Main program ID = %d\n",getpid());
        printf("Parent_ID = %d\n",getppid());
    }
}