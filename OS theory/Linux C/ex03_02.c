#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <syscall.h>
#include <string.h>

//not completed
int main()
{
    int fd[2];
    pid_t pid;
    char buf1[40];
    char buf2[40];

    if(pipe(fd) < 0)
    {
        printf("pipe error!");
        exit(1);
    }
    if((pid = fork()) < 0)
    {
        printf("fork error!");
        exit(1);
    }
    if(pid > 0) printf("I am father!");
    else
    {
        if(pid == 0)
        {
            printf("sonp1 Enter the string1: \n");
            scanf("%s", buf1);
            write(fd[1], buf1, strlen(buf1));
            exit(0);
        }
        if(pid > 0)
        {
            read(fd[0], buf1, 40);
            for (int i = 0; i < 40; ++i)
            {
                if(buf1[i] == '\0') break;
                buf1[i] += 32;
            }
            printf("father print the string from son1: %s", buf1);
            //output the string1

           if((pid = fork()) < 0)
           {
               printf("fork error!");
                exit(1);
           }
            if(pid == 0)
            {
                printf("sonp2 Enter the string2\n");
                scanf("%s", buf2);
                write(fd[1], buf2, strlen(buf2));
            }
            if(pid > 0)
            {
                read(fd[0], buf2, 40);
                for (int i = 0; i < 40; ++i)
                {
                    if(buf2[i] == '\0') break;
                    buf2[i] -= 32;
                }
                printf("father print the string from son2: %s", buf2);
            }
        }
    }
    return 0;
}
