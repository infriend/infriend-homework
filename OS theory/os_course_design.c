#include <stdio.h>
#include <stdlib.h>
#include <syscall.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#define VERYBIG 40

void my_pwd()
{
	char dirname[VERYBIG];
	if (getcwd(dirname, VERYBIG) == NULL)
		printf("getcwd error");
	else
		printf("%s", dirname);
}

void ui()
{
	char servername[VERYBIG];
	gethostname(servername, VERYBIG);
	printf("[%s@%s: ", getlogin(), servername);
	my_pwd();
	printf(" ] $ ");
}

void shell_exit()
{
	exit(0);
}

void redir(int dir, char *filename)
{
	int fid;
	if (dir == 1)
	{
		fid = open(filename, O_RDONLY);
		dup2(fid, 0);
	}
	if (dir == 2)
	{
		fid = open(filename, O_WRONLY|O_CREAT);
		dup2(fid, 1);
	}
}

void pipe_func(char *order1, char *order2, char *const *e)
{
	int fd[2];
	pid_t pid;
	pid = fork();
	if(pid > 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execve(order1, NULL, e);
		waitpid(pid, NULL, 0);
	}
	if(pid == 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		execve(order2, NULL, e);
	}
}

int main()
{
	int i, j, pipe = 0;
	char ch;
	char s[200];
	char order1[VERYBIG];
	char path[VERYBIG], gpath[VERYBIG];
	pid_t pid;

	while(1)
	{
		ui();
		//chdir("/home/infriend/my_code");
		//my_pwd();
		ch = getchar();
		i = 0;
		while(i < 200 && ch != '\n')
		{
			s[i] = ch;
			ch = getchar();
			i++;
		}
		s[i++] = '\0';
		s[i] = '\0';		

		i = 0;
		while ((s[i] != ' ') && (s[i] != '\0'))
		{
			order1[i] = s[i];
			i++;
		}
		order1[i] = '\0';
		
		j = 0;
		if (strcmp(order1, "cd") == 0)
		{
			i++;
			while (s[i]!='\0')
			{
				path[j++] = s[i++];	
			}
			path[j] = '\0';
		    chdir(path);  
		}
		else
		{
			if (strcmp(order1, "exit") == 0)
			{
				shell_exit();
			}
			else
			{
				if (strcmp(order1, "path") == 0)
				{
					i++;
					j = 0;
					while(s[i] != '\0')
					{
						gpath[j++] = s[i++];
					}
					gpath[j] = '\0';
				}
				else
				{
					strcpy(path, "PATH=");
					strcat(path, gpath);
					char *envp[] = {path, 0};
					pid = fork();
					if (pid < 0) printf("Fork error!");
					if (pid == 0)
					{	

						if (access(order1, X_OK) == 0)
						{
							i++;
							if(s[i] == '<') redir(1, &s[i+1]);
							if(s[i] == '>') redir(2, &s[i+1]);
							if(s[i] == '|') 
							{
								pipe = 1;
								i++;
								pipe_func(order1, &s[i+1],envp);
							}
							if (pipe == 0) execve(order1, NULL, envp);
						}
					}
					sleep(1);
				}
			}
		}
	}
	return 0;
}
