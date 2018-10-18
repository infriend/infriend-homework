/*
设计和实现一个“学生成绩记录薄”，满足以下要求：
1.系统以菜单方式工作；
2.使用链表或结构数组对不同班级的学生成绩信息进行管理和维护；
3.使用二进制文件在磁盘上保存学生记录信息；（可选）
4.链表中各结点或结构数组中各元素包括“学号、班级、姓名、语文、数学、外语、计算机、总分”字段；
5.实现如下基本功能：
(1)列出指定班级的所有学生的成绩单complete
(2)录入学生记录  （新增学生的信息，将它添加到链表中）complete
(3)查找学生      （查找指定学号的学生，显示该学生的学号、班级、姓名、所有课程成绩）complete
(4)删除学生      （删除指定学号的学生）complete
(5)计算总分和平均分      （计算每位学生四门课程的总分）complete
(5)排序   （对指定班级的所有学生按总分由高到低的方式排序并输出）complete
(6)计算指定班级各门课程的平均分  （计算并输出某班级学生每门课程的平均分）complete
(7)查询所有存在不及格课程的学生，并输出这些学生信息；complete
(8)将学生记录保存到文件存盘 （可选，将链表或结构数组的数据以文件的形式存盘）complete
(9)从文件中读入学生记录    （可选，将原来已经存盘的文件读入内存，进行管理）complete
*/
#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct student)

struct student
{
    int num;
    char gumi;
    char name[10];
    float chinese;
    float math;
    float english;
    float computer;
    float total;
    float aver;
    int rank;
    struct student *next;
};
int n = 0;

struct student *creat(void)
{
    struct student *p1, *p2, *head;
    FILE *fp;
    fp = fopen("student.dat", "wb");
    p1 = (struct student *)malloc(LEN);
    p2 = p1;
    printf("Please enter the student information:\n");
    printf("ATTENTION: NUM 0 means operatation is over\n");
    printf("NUM: ");
    scanf("%d", &p1->num);
    getchar();
    printf("CLASS: ");
    scanf("%c", &p1->gumi);
    printf("NAME: ");
    scanf("%s", &p1->name);
    printf("CHINESE: ");
    scanf("%f", &p1->chinese);
    printf("MATH: ");
    scanf("%f", &p1->math);
    printf("ENGLISH: ");
    scanf("%f", &p1->english);
    printf("COMPUTER: ");
    scanf("%f", &p1->computer);
    p1->total = 0;
    p1->aver = 0;
    head = NULL;
    while (p1->num!=0)
    {
        n += 1;
        if (n==1) head = p1;
        else
        {
            p2->next = p1;
            p2 = p1;
        }
        fwrite(p1, LEN, 1, fp);
        p1 = (struct student *)malloc(LEN);
        printf("NUM: ");
        scanf("%d", &p1->num);
        getchar();
        printf("CLASS: ");
        scanf("%c", &p1->gumi);
        printf("NAME: ");
        scanf("%s", &p1->name);
        printf("CHINESE: ");
        scanf("%f", &p1->chinese);
        printf("MATH: ");
        scanf("%f", &p1->math);
        printf("ENGLISH: ");
        scanf("%f", &p1->english);
        printf("COMPUTER: ");
        scanf("%f", &p1->computer);
		p1->total = 0;
        p1->aver = 0;
        //按此逻辑NUM 0 也会写进文件
    }
    p2->next = NULL;
    free(p1);
    fclose(fp);

    return head;
}

void print(struct student *head)
{
    struct student *p;
    p = head;
    printf("NUM  CLASS  NAME  CHINESE  MATH  ENGLISH  ENGLISH  COMPUTER  AVERAGE TOTAL\n");
    while (p!=NULL)
    {
        printf("%d   %c    %s   %4.2f   %4.2f   %4.2f   %4.2f   %4.2f   %4.2f\n", p->num, p->gumi, p->name, p->chinese, p->math, p->english, p->computer, p->aver, p->total);
        p = p->next;
    }
}

struct student *read(void)//function 10
{
    struct student *p1, *p2, *head;
    FILE *fp;
    n = 0;
    fp = fopen("student.dat", "rb");
    p1 = (struct student *)malloc(LEN);
    if (!feof(fp))
    {
        fread(p1, LEN, 1, fp);
        head = p1;
        n = 0;
        while (1)
        {
            p2 = p1;
    		p1 = (struct student *)malloc(LEN);
            fread(p1, LEN, 1, fp);
            n++;
            p2->next = p1;
            if(feof(fp)) break;
        }
        p2->next = NULL;
    }
    else
    {
        head = NULL;
        free(p1);
    }
    fclose(fp);
    printf("%d records\n", n);
    return head;
}
//注意虽然二进制格式化输入可以保存指针地址值，然而重新读取后各数据分配得到的是新的内存地址，因此指针不可保存

void add(struct student *head)//功能2添加学生信息
{
    struct student *p1, *p2;
    p1 = head;
    while (p1->next!=NULL)
    {
        p1 = p1->next;
    }
    p2 = (struct student *)malloc(LEN);
    printf("NUM: ");
    scanf("%d", &p2->num);
    getchar();
    printf("CLASS: ");
    scanf("%c", &p2->gumi);
    printf("NAME: ");
    scanf("%s", &p2->name);
    printf("CHINESE: ");
    scanf("%f", &p2->chinese);
    printf("MATH: ");
    scanf("%f", &p2->math);
    printf("ENGLISH: ");
    scanf("%f", &p2->english);
    printf("COMPUTER: ");
    scanf("%f", &p2->computer);
    p1->next = p2;
    p2->next = NULL;
    n += 1;
}

void search(struct student *head, int e)//功能3
{
    struct student *p;
    p = head;
    while (p->num!=e&&p!=NULL)
    {
        p = p->next;
    }
    if (p==NULL) printf("Not found");
    else
    {
        printf("NUM   CLASS   NAME  CHINESE  MATH  ENGLISH  ENGLISH  COMPUTER  AVERAGE TOTAL\n");
        printf("%3d %c %5s %4.2f %4.2f %4.2f %4.2f %4.2f %4.2f", p->num, p->gumi, p->name, p->chinese, p->math, p->english, p->computer, p->aver, p->total);
    }
}

struct student *del(struct student *head, int e)//function 4
{
    struct student *p1, *p2;
    p1 = head;
    if (p1==NULL) printf("No data!\n");
    else
    {
        if(p1->num==e)
        {
            p2 = p1->next;
            free(p1);
            head = p2;
        }
        else
        {
        while (p1!=NULL&&p1->next->num!=e)
        {
            p1 = p1->next;
        }
        p2 = p1->next;
        p1->next = p2->next;
        free(p2);
        }
        n -= 1;
    }
    return head;
}

void calcu(struct student *head)//function 5
{
    struct student *p1;
    p1 = head;
    while (p1!=NULL)
    {
        p1->total = p1->chinese + p1->math + p1->english + p1->computer;
        p1->aver = p1->total/4;
        p1 = p1->next;
    }
    printf("Calculating process over");
}

void average(struct student *p, char c)//function 7
{
    float chinese = 0, math = 0, english = 0, computer = 0;
    while (p!=NULL)
    {
        if (p->gumi==c)
        {
            chinese += p->chinese;
            math += p->math;
            english += p->english;
            computer += p->computer;
        }
        p = p->next;
    }
    printf("Average score of %c     Chinese     Math    English    Computer\n", c);
    printf("                       %4.2f       %4.2f     %4.2f     %4.2f", chinese, math, english, computer);
}

void fail(struct student *head)//function 8
{
    struct student *p;
    p = head;
    while (p!=NULL)
    {
        if (p->chinese<60||p->english<60||p->english<60||p->computer<60)
        {
            printf("NUM   CLASS   NAME  CHINESE  MATH  ENGLISH  ENGLISH  COMPUTER  AVERAGE TOTAL\n");
            printf("%3d %c %5s %4.2f %4.2f %4.2f %4.2f %4.2f %4.2f", p->num, p->gumi, p->name, p->chinese, p->math, p->english, p->computer, p->aver, p->total);
        }
        p = p->next;
    }
}

void list(struct student *p, char c)//function 1
{
    if (p==NULL) printf("Erorr!");
    else
    {
        printf("NUM   CLASS   NAME  CHINESE  MATH  ENGLISH  ENGLISH  COMPUTER  AVERAGE TOTAL\n");
        while (p!=NULL)
        {
            if (p->gumi==c)
            {
                printf("%3d %c %5s %4.2f %4.2f %4.2f %4.2f %4.2f %4.2f", p->num, p->gumi, p->name, p->chinese, p->math, p->english, p->computer, p->aver, p->total);
            }
            p = p->next;
        }
    }
}

void save(struct student *p)//function 9
{
    FILE *fp;
    fp = fopen("student.dat", "wb");
    if (p==NULL) printf("Erorr\n");
    while (p!=NULL)
    {
        fwrite(p, LEN, 1, fp);
        p = p->next;
    }
    fclose(fp);
    printf("Save processing finished!\n");
}

void sort(struct student *head)//unable
{
	int i, j;
    struct student temp, *p1, *p2;
    for (i=0;i<n-1;i++)
    {
        p1 = head;
        for (j=0;j<n-i-1;j++)
        {
            p2 = p1;
            p1 = p2->next;
            if (p1->total>p2->total)
            {
                temp = *p1;
                *p1 = *p2;
                *p2 = temp;
                p1->next = p2->next;
                p2->next = p1;
            }
        }
    }
}

int main()
{
    int i, e;
    char c;
    struct student *head;

    printf("    WELCOME!You can use the function by entering number.\n");
    while (1)
    {
        printf("    *********************************************************\n");
        printf("    *            STUDENT GRADE RECORDING SYSTEM             *\n");
        printf("    *********************************************************\n");
        printf("    *  1.initialize the record                              *\n");
        printf("    *  2.print the student grades by class                  *\n");
        printf("    *  3.add student grade                                  *\n");
        printf("    *  4.search the student by number                       *\n");
        printf("    *  5.delete the student by number                       *\n");
        printf("    *  6.calculate the total score and average score        *\n");
        printf("    *  7.sort the grades                                    *\n");
        printf("    *  8.print the average score by class                   *\n");
        printf("    *  9.print all the students who have failing grade      *\n");
        printf("    *  10.save the information                              *\n");
        printf("    *  11.print the list                                    *\n");
        printf("    *  12.read the record from the file                     *\n");
        printf("    *  0. exit the system                                   *\n");
        printf("    *********************************************************\n");
        printf("    tips: Remember to save the record after the operatation.\n");
        printf("Function: ");
        scanf("%d", &i);
        getchar();


        switch(i)
        {
            case 1:
            {
                head = creat();
                break;
            }
            case 2:
            {
                printf("You'd like to print class: ");
                scanf("%c", &c);
                getchar();
                list(head, c);
                break;
            }
            case 3:
            {
                add(head);
                break;
            }
            case 4:
            {
                printf("Enter the studnet number you'd like to search\n");
                printf("NUM: ");
                scanf("%d", &e);
                search(head, e);
                break;
            }
            case 5:
            {
                printf("Enter the studnet number you'd like to delete");
                printf("NUM: ");
                scanf("%d", &e);
                head = del(head, e);
                break;
            }
            case 6:
            {
                calcu(head);
                break;
            }
            case 7:
            {
                sort(head);
                break;
            }
            case 8:
            {
                printf("Enter the class you'd like to print.\n");
                printf("Class: ");
                scanf("%c", &c);
                getchar();
                average(head, c);
                break;
            }
            case 9:
            {
                fail(head);
                break;
            }
            case 10:
            {
                save(head);
                //printf("Saving process over!\n");
                break;
            }
            case 11:
            {
                print(head);
                break;
            }
            case 12:
            {
                head = read();
                break;
            }
            case 0:
            {
                exit(0);
                break;
            }
        }
    }

    return 0;
}
