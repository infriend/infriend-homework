#include <stdio.h>
#include <stdlib.h>
#include <syscall.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define VERYBIG 200

char gpath[VERYBIG];

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
	printf(" ] $");
}

void shell_exit()
{
	exit(0);
}

void shell_cd(char path[VERYBIG])
{
	if ((chdir(path)) == -1)
	{
		printf("cd error\n");
	}
}

void static_order_analyse(char order[VERYBIG])
{
	int i, j = 0;
	char dir[VERYBIG];
	if (order[0] == 'c' && order[1] == 'd' && order[2] == ' ')
	{
		for (i = 3; i < VERYBIG; i++)
		{
			if(order[i] == '\0') break;
			dir[j++] = order[i];
		}
		dir[j] = '\0';
		shell_cd(dir);
	}
	if (order[0] == 'e' && order[1] == 'x' && order[2] == 'i' && order[3] == 't' && order[4] == '\0')
	{
		shell_exit();
	}
	if (order[0] == 'p' && order[1] == 'a' && order[2] == 't' && order[3] == 'h' && order[4] == ' ' && order[5] == '=')
	{
		for (i = 6; i < VERYBIG; i++)
		{
			if(order[i] == '\0') break;
			dir[j++] = order[i];
		}
		dir[j] = '\0';
		for (i = 0; i <= j; i++)
		{
			gpath[i] = dir[i];
		}
	}
}

void run_execute(char order[VERYBIG])
{
	pid_t pid;
	char dir[2 * VERYBIG];
	char *envp[2], p;
	strcpy(dir, gpath);
	strcat(dir, order);
	if((access(dir, X_OK)) == -1)
	{
		printf("Not accessible");
	}
	else
	{
		pid = fork();
		if(pid < 0)
		{
			printf("fork fail");
		}
		if(pid == 0)
		{
			p = gpath;
			envp[0] = p;
			envp[1] = 0;
			execve(order, NULL, envp);
		}
	}
}
	

int main()
{
	int i;
	char ch;
	char order[VERYBIG];

	while(1)
	{
		ui();
		ch = getchar();
		for(i = 0; i < VERYBIG; i++)
		{
			if (ch == '\n') break;
			order[i] = ch;
			ch = getchar();
		}
		order[i++] = '\0';
		order[i] = 0;
		static_order_analyse(order);	
		
	}
	return 0;
}
