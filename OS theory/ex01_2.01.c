#include <stdio.h>
#include <syscall.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char source[20];
    char destination[20];
    char sym[4] = {" > "};
    char order[40] = {"cat "};

    printf("Enter the source filename: ");
    scanf("%s", source);
    getchar();
    printf("Enter the destination filename: ");
    scanf("%s", destination);
    strcat(order, source);
    strcat(order, sym);
    strcat(order, destination);
    system(order);

    return 0;
}
