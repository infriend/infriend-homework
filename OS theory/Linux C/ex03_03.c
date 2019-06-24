#include <stdio.h>
#include <sys/shm.h>
#include <syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main()
{
	void *shm = NULL;
	int *shared;
	int keynum = 6666;
	int shmid;
	pid_t pid;
	time_t t1, t2;

	shmid = shmget((key_t)keynum, sizeof(int),IPC_CREAT | 0777);
	if(shmid == -1)
	{
		printf("ERROR!\n");
		exit(1);
	}

	shm = shmat(shmid, 0, 0);
	if(shm == (void *)-1)
	{
		printf("shmat failed\n");
		exit(1);
	}
	shared = (int *)shm;
	*shared = 0;

	if((pid = fork()) < 0)
	{
		printf("fork error!\n");
		exit(1);
	}	
	
	if (pid > 0)
	{
		printf("sequence 1: \n");
		*shared = 1;
		printf("observer =  %d\n", *shared);
		usleep(2000);
	}
	if (pid == 0)
	{
	//	shm = shmat(shmid, 0, 0);
	//	shared = (int *)shm;
		usleep(1000);//wait for pid>0 add count
		printf("count = %d\n", *shared);
		*shared = 0;
		exit(1);
	}
	printf("sequence1 end count = %d\n", *shared);


	*shared = 0;
	pid = fork();
	if (pid > 0)
	{
		printf("sequence 2: \n");
		usleep(1000);
		*shared = 1;
		printf("obeserver = %d\n", *shared);
		usleep(1000);
	}
	if (pid == 0)
	{
		printf("count = %d\n", *shared);
		usleep(1500);
		*shared = 0;
		printf("counter = %d\n", *shared);
		exit(1);
	}
	printf("sequence2 end count = %d\n", *shared);

	*shared = 0;
	pid = fork();
	if (pid > 0)
	{
		printf("sequence 3: \n");
		usleep(1000);
		*shared = 1;
	}
	if (pid == 0)
	{
		printf("count = %d\n", *shared);
		*shared = 0;
		exit(1);
	}
	printf("sequence3 end count = %d\n", *shared);


	return 0;
}
