#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>
main ()
{
    int status;
    int pid1=-1,pid2=-1,pid3=-1;
    pid1=fork();
    if (pid1 == 0) printf("pid1=0,my process id is %d\n",getpid());
    else if (pid1 > 0)
    {
        printf("pid1>0,my process id is %d\n",getpid());
        pid2=fork( );
        if (pid2 == 0) printf("pid2=0, my process id is %d\n",getpid());
        else if (pid2 > 0) printf(" pid2>0, my process id is %d\n",getpid());
    }
    pid3=fork();
    if (pid3 == 0) printf("pid3=0,pid1=%d,pid2=%d, my process id is %d\n",pid1,pid2,getpid());
    else  if (pid3 > 0) printf("pid3>0, pid1=%d,pid2=%d, my process id is %d\n",pid1,pid2,getpid());
    wait(&status);
    exit(0);
 }
