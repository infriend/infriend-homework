#include <stdio.h>
#include <stdlib.h>
#include <syscall.h>

int main()
{
	system("ls /home/stu2 -l");
	system("chmod u+r+w /home/stu2/text/saturday.txt");
	system("chmod g+r /home/stu2/text/saturday.txt");

	return 0;
}
