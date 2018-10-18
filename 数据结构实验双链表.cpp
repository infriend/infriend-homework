#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct worker)
struct worker
{
	long num;
	char name[10];
	float salary;
  float bonus;
	float expense;
	float real_sal;
	int rank;
	struct worker *next;
	struct worker *former;
};
int n;


struct worker *creat()
{
	struct worker *head;
	struct worker *p1,*p2;
	FILE *fp1;
	fp1=fopen("workers.txt","w");
	n = 0;
	p1 = (struct worker *)malloc(LEN);
	p2 = p1;
	p1 = (struct worker *)malloc(LEN);
	printf("请输入工人信息，0,0为停止输入\n");
	printf("NUM ");
	scanf("%ld",&p1->num);
	printf("NAME ");
	scanf("%s",&p1->name);
	printf("SALARY ");
	scanf("%f",&p1->salary);
	printf("BONUS ");
	scanf("%f",&p1->bonus);
	printf("EXPENSE ");
	scanf("%f",&p1->expense);
	p1->real_sal = 0;
	fprintf(fp1,"%ld %s %.2f %.2f %.2f %.2f ",p1->num,p1->name,p1->salary,p1->bonus,p1->expense,p1->real_sal);
	head = p2;
	while (p1->num!=0)
	{
		n = n+1;
		p1->former = p2;
		p2->next = p1;
		p2 = p1;
		p1 = (struct worker *)malloc(LEN);
		printf("NUM ");
	    scanf("%ld",&p1->num);
	    printf("NAME ");
	    scanf("%s",&p1->name);
	    printf("SALARY ");
	    scanf("%f",&p1->salary);
	    printf("BONUS ");
	    scanf("%f",&p1->bonus);
	    printf("EXPENSE ");
	    scanf("%f",&p1->expense);
	    p1->real_sal = 0;
		fprintf(fp1,"%ld %s %.2f %.2f %.2f %.2f ",p1->num,p1->name,p1->salary,p1->bonus,p1->expense,p1->real_sal);
    }
    p2->next = NULL;
    fclose(fp1);
    return (head);
}

struct worker *creat1()
{
	struct worker *head;
	struct worker *p1,*p2;
	FILE *fp1;
	fp1 = fopen("workers.txt","r");
	n = 0;
	p1 = (struct worker *)malloc(LEN);
	p2 = p1;
	p1 = (struct worker *)malloc(LEN);
	p1->real_sal = 0;
	fscanf(fp1,"%ld%s%f%f%f%f",&p1->num,&p1->name,&p1->salary,&p1->bonus,&p1->expense,&p1->real_sal);
	head = p2;
	while (p1->num!=0)
	{
		n = n+1;
	    p2->next = p1;
	    p1->former = p2;
		p2 = p1;
		p1 = (struct worker *)malloc(LEN);
		p1->real_sal = 0;
		fscanf(fp1,"%ld%s%f%f%f%f",&p1->num,&p1->name,&p1->salary,&p1->bonus,&p1->expense,&p1->real_sal);
    }
    p2->next = NULL;
    fclose(fp1);
    return (head);
}

void print(struct worker *head)
{
	struct worker *p;
	FILE *fp;
	fp=fopen("workers.txt","r");
	printf("\n此表中共有%d个记录:\n",n);
	p = head->next;
	if (head->next!=NULL)
	{
		do
		{
			printf("%ld  %s  %5.2f  %5.2f  %5.2f  %5.2f\n", p->num, p->name, p->salary, p->bonus, p->expense,p->real_sal);
			p=p->next;
        } while (p!=NULL);
    }
    fclose(fp);
}


void total(struct worker *head)
{
	struct worker *p;
	float total_salary = 0, total_bonus = 0, total_expense = 0, total_realsa = 0;
	p = head->next;
	if (head->next!=NULL)
	{
		do
		{
			total_salary += p->salary;
			total_bonus += p->bonus;
			total_expense += p->expense;
			total_realsa += p->real_sal;
			p=p->next;
    	} while (p!=NULL);
    printf("┌─────┬─────┬─────┬─────┐\n");
    	printf("│总工资    │ 总补贴   │ 总水电   │ 总实发   │\n");
    	printf("├─────┼─────┼─────┼─────┤\n");
    	printf("│%.2f   │%.2f    │%.2f    │%.2f   │\n", total_salary, total_bonus, total_expense, total_realsa);
    	printf("└─────┴─────┴─────┴─────┘\n");
    }
}


struct worker *del(struct worker *head, long num)
{
	struct worker *p1,*p2;
    if (head->next==NULL)
    {
    	printf ("\nlist null!\n");
	    goto end;
	}
    p2 = head;
    p1 = p2->next;
    while (num!=p1->num && p1!=NULL)
    {
    	p2 = p1;
	    p1 = p1->next;
	}
    if (num==p1->num)
    {
    	if (p1==head->next)
		{
			head->next = p1->next;
			(p1->next)->former = head;
			free(p1);
		}
	    else if (p1->next==NULL)
	         {
	         	p2->next = p1->next;;
	         	free(p1);
			 }
			 else
		     {
				p2->next = p1->next;
				(p1->next)->former = p2;
				free(p1);
		 	 }
	    printf("delete:%ld\n",num);
	    n=n-1;
	}
	else printf("%ld 不存在!\n",num);
	printf("已删除，请注意保存。");
    end:
	return(head);
}




struct worker *sort(struct worker *head)
{
	struct worker *p1, *p2, temp;
	int i,j;
	p1 = head->next;
	p2 = head;
	if (head->next==NULL) printf("\nErorr!\n");
	else
	{
		for (i=0;i<n-1;i++)
		{
			p1 = head->next;
	        p2 = head;
			for (j=0;j<n-i-1;j++)
			{
				p2 = p1;
				p1 = p1->next;
				printf("%daf\n", i);
				if (p1==NULL) break;
				if (p2->real_sal<p1->real_sal)
			    {
				    temp = *p1;
				    *p1 = *p2;
				    *p2 = temp;				    
                    p1->next = p2->next;
                    p2->former = p1->former;
                    p2->next = p1;
                    p1->former = p2;
			    }
			}
		}
    }
    i = 1;
    p1 = head->next;
    while (p1!=NULL)
    {
    	p1->rank = i++;
    	printf("%ld,%s,%.2f,%.2f,%.2f, %.2f, %d\n", p1->num, p1->name, p1->salary, p1->bonus, p1->expense, p1->real_sal, p1->rank);
    	p1 = p1->next;
    }
    return head;
}

struct worker *insert(struct worker *head)
{
	struct worker *p1, *p2, *p3;
	printf("输入插入项工号，姓名，基本工资，补贴，水电费");
	printf("\n");
	p3 = (struct worker *)malloc(LEN);
	printf("NUM ");
	scanf("%ld",&p3->num);
	printf("NAME ");
	scanf("%s",&p3->name);
	printf("SALARY ");
	scanf("%f",&p3->salary);
	printf("BONUS ");
	scanf("%f",&p3->bonus);
	printf("EXPENSE ");
	scanf("%f",&p3->expense);
	p3->real_sal = p3->salary + p3->bonus - p3->real_sal;
	p1 = head->next;
	p2 = head;
	if (p3->num<p1->num)
	{
		p3->next = p1;
		head->next = p3;
	}
	else
	{
		while (p3->num>p1->num)
	    {
		    p2 = p1;
		    p1 = p1->next;
		    if (p1==NULL) break;
		    if (p1->num>p3->num)
		    {
			    p3->next = p1;
			    p3->former = p2;
			    p1->former = p3;
			    p2->next = p3;
			}
	    }
	    if (p1==NULL)

		{
		    p3->next = NULL;
		    p3->former = p2;
			p2->next = p3;
		}
	}
	return head;
}




void search(struct worker *head, long num)
{
	struct worker *p1;
	if (head->next==NULL) printf("\n为空，无法查!\n");
    else
    {
    	p1 = head->next;
		while (num!=p1->num && p1->next!=NULL)
		{
		    p1=p1->next;
		}
    if (num==p1->num) printf("%4ld %6s  %.2f  %.2f  %.2f  %.2f\n",p1->num,p1->name,p1->salary,p1->bonus,p1->expense,p1->real_sal);
    else printf("NO DATA!");
    }
}

void realsa(struct worker *head)
{
	struct worker *p;
	if (head->next==NULL) printf("\nErorr.\n");
	else
	{
		p = head->next;
		while (p!=NULL)
		{
			p->real_sal = p->salary + p->bonus - p->expense;
			printf("%f",p->real_sal);
			p = p->next;
		}
	}
	printf("Caculate over.");
}

void save(struct worker *head)
{
	FILE *fp;
	struct worker *p;
	fp = fopen("workers.txt", "w");
	p = head->next;
	if (p==NULL) printf("Erorr");
	else
	{
	    printf("Ab");
		fprintf(fp,"%ld %s %.2f %.2f %.2f %.2f ",p->num,p->name,p->salary,p->bonus,p->expense,p->real_sal);

		while (p->next!=NULL)
		{
		    p = p->next;
			fprintf(fp,"%ld %s %.2f %.2f %.2f %.2f ",p->num,p->name,p->salary,p->bonus,p->expense,p->real_sal);
			printf("A");
		}

		fprintf(fp,"0 0 0 0 0 0");
	}
	fclose(fp);
}

int main()
{
	struct worker *head;
    long del_num, s_num;
	int c;

    while (c!=9)
    {
    	printf("      工人工资管理\n");
		printf("        1.创建链表\n");
		printf("        2.工号查找\n");
		printf("        3.条目插入\n");
		printf("        4.条目删除\n");
		printf("        5.求实发工资\n");
		printf("        6.工资排序\n");
		printf("        7.各项工资总额\n"); 
		printf("        8.保存\n");
		printf("        9.退出\n"); 
		printf("        10.打印");
		printf("     请输入功能选项(1..9)\n  ");
        scanf("%d", &c);
        switch(c)
	    {
		case 1:
  	        head = creat();
  	        print(head);
  	        break;
        case 2:
            head = creat1();
            printf("\n请输入需要查找的工号:"); 
            scanf("%ld", &s_num);
            search(head, s_num);
            break;
        case 3:
            head = creat1();
            print(head);
            head = insert(head);
            print(head);
            break;
        case 4:
            head=creat1();
            print(head);
            printf("\n请输入删除学生的学号:");
            scanf("%ld",&del_num);
            head = del(head, del_num);
            print(head);
            break;
        case 5:
            head = creat1();
            realsa(head);
			break;
        case 6:
        	head = creat1();
		    sort(head);
			break;
        case 7:
        	head = creat1();
		    total(head);
			break;
        case 8:
		    save(head);
			break;
		case 9:
		    printf("正在关闭系统...");
			exit(0);break;
		case 10: print(head);break;
		default: printf("指令错误！\n");
        }
    }
    return 0;
}


