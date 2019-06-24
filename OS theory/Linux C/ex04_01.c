#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int next;
    int sym;
    int mem_loc;
} instruct_node;
int memory[32];
int page_stream[320];

void rand_instrction()
{
    int i, m;
    int seed = time(NULL);
    int ins_num[320];
    memset(ins_num, 0, sizeof(ins_num));
    srand(seed);

    for (i = 0; i < 320; i++)
    {
        do
        {
            m = (rand() + rand() + rand() + rand() + rand() + rand() + rand() + rand() + rand() + rand() + rand() + rand() + rand() + rand()) % 320;
        } while (ins_num[m] == 1);
        page_stream[i] = m / 10;
        ins_num[m] = 1;
    }
}

double fifo(int memsize)
{
    double miss = 0;
    int i, j, p = 0, hit_judge;
    for (i = 0; i < 320; i++)
    {
        if (i < memsize)
        {
            for (j = 0; j < i; j++)
            {
                if (memory[j] == page_stream[i])
                {
                    hit_judge = 1;
                    break;
                }
            }
            if (hit_judge == 1)
            {
                hit_judge = 0;
                continue;
            }
            else
            {
                memory[p % memsize] = page_stream[i];
                p++;
                miss++;
            }

        }
        else
        {
            for (j = 0; j < memsize; j++)
            {
                if (memory[j] == page_stream[i])
                {
                    hit_judge = 1;
                    break;
                }
            }
            if (hit_judge == 1)
            {
                hit_judge = 0;
                continue;
            }
            else
            {
                memory[p % memsize] = page_stream[i];
                p++;
                miss++;
            }
        }
    }
    return (double)miss/(double)320;
}

double opt(int memsize)
{
    double miss = 0;
    int label, maxdist = 0, dist = 0, i, p = 0, j;
    int hit_judge = 0, outrange = 0;
    for (i = 0; i < 320; i++)
    {
        if (i < memsize)
        {
            for (j = 0; j < i; j++)
            {
                if (memory[j] == page_stream[i])
                {
                    hit_judge = 1;
                    break;
                }
            }
            if (hit_judge == 1)
            {
                hit_judge = 0;
                continue;
            }
            else
            {
                memory[p % memsize] = page_stream[i];
                miss++;
                p++;
            }
        }
        else
        {
            for (j = 0; j < memsize; j++)
            {
                if (memory[j] == page_stream[i])
                {
                    hit_judge = 1;
                    break;
                }
            }
            if (hit_judge == 1)
            {
                hit_judge = 0;
                continue;
            }
            else
            {
            	if (p < memsize)
            	{
            		memory[p] = page_stream[i];
            		miss++;
            		p++;
            		continue;
				}
                label = 0;
                maxdist = 0;
                for (j = 0; j < memsize; j++)
                {
                    do
                    {
                        dist++;
                        if ((i + dist) > 320)
                        {
                        	label = j;
                        	outrange = 1;
                        	break;
						}
                    } while(memory[j] != page_stream[i + dist]);
                    if(outrange == 1)
                    {
                    	outrange = 0;
                    	break;
					}
                    if (dist > maxdist)
                    {
                        maxdist = dist;
                        label = j;
                    }
                    dist = 0;
                }
                memory[label] = page_stream[i];
                miss++;
            }
        }
    }

    return (double)miss/(double)320;
}

double lru(int memsize)
{
    double miss = 0;
    int i, j, p = 0, hit_judge, k, label = 0;
    int age[32];
    memset(age, 0, sizeof(age));
    for (i = 0; i < 320; i++)
    {
    	for (k = 0; k < memsize; k++)
        {
            age[k]++;
        }
        if (i < memsize)
        {
            for (j = 0; j < i; j++)
            {
                if (memory[j] == page_stream[i])
                {
                    hit_judge = 1;
                    break;
                }
            }
            if (hit_judge == 1)
            {
                hit_judge = 0;
                age[j] = 0;
                continue;
            }
            else
            {
                memory[p % memsize] = page_stream[i];
                age[p % memsize] = 0;
                p++;
                miss++;
            }

        }
        else
        {
            for (j = 0; j < memsize; j++)
            {
                if (memory[j] == page_stream[i])
                {
                    hit_judge = 1;
                    break;
                }
            }
            if (hit_judge == 1)
            {
                hit_judge = 0;
                age[j] = 0;
                continue;
            }
            else
            {
            	if (p < memsize)
            	{
            		memory[p] = page_stream[i];
            		miss++;
            		p++;
            		continue;
				}
                for (k = 0; k < memsize; k++)
                {
                    if (age[label] >= age[k]) continue;
                    else label = k;
                }
                memory[label] = page_stream[i];
                age[label] = 0;
                p++;
                miss++;
            }
        }
    }

    return (double)miss/(double)320;
}

int main()
{
    double hitrate[3][29];
    int i, j, k;
    memset(memory, -1, sizeof(memory));
    rand_instrction();
    printf("%f\n\n", opt(32));

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 29; j++)
        {
            if (i == 0) hitrate[i][j] = 1 - fifo(j+4);
            if (i == 1) hitrate[i][j] = 1 - opt(j+4);
            if (i == 2) hitrate[i][j] = 1 - lru(j+4);
            memset(memory, -1, sizeof(memory));
        }
    }


    for (i = 0; i < 29; i++)
    {
        printf("memsize %d\n", i+4);
        for (j = 0; j < 3; j++)
        {
            if (j == 0) printf("FIFO = %f\n", hitrate[j][i]);
            if (j == 1) printf("OPT = %f\n", hitrate[j][i]);
            if (j == 2) printf("LRU = %f\n", hitrate[j][i]);
        }
    }


    return 0;
}
