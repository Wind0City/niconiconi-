// scheduling.cpp : 定义控制台应用程序的入口点。
// 时间片轮转调度

#include "stdafx.h"
#include "scheduling.h"
#include "stdlib.h"

#define scanf_s scanf // 偷懒行为(O_o)

int timep;

#define getstruct(type) (type *)malloc(sizeof(type));
PCB *ready = NULL, *p;

bool sort()//入队改为先来先进
{
	PCB *first, *second;
	int insert = 0;
	if (ready == NULL)
	{
		p->link = ready;
		ready = p;
	}
	else
	{
		first = ready;
		while (first->link!=NULL)
		{
			first=first->link;
		}
		first->link=p;//迭代到最后即可
	}
	return (true);
}
bool input()
{
	int num;
	printf("\n请输入进程数:");
	scanf_s("%d", &num);
	printf("\n请输入时间片大小:");
	scanf_s("%d", &timep);
	for (int i = 0; i < num; i++)
	{
		printf("\n进程号:%d", i);
		p = getstruct(PCB);
		printf("\n输入进程名:");
		scanf_s("%s", p->name, 10);
		//printf("\n输入进优先数:");
	/* 	int temp;
		// scanf_s("%d", &temp, sizeof(int));
		// p->nice = temp;
		scanf_s("%d", &(p->nice), sizeof(int)); */
		printf("\n输入进程运行时间:");
		scanf_s("%d", &(p->ntime), sizeof(int));
		printf("\n");
		p->rtime = 0;
		p->state = 'W';
		p->link = NULL;
		sort();
	}
	return (true);
}
int space()
{
	int i = 0;
	PCB *pr = ready;
	while (pr != NULL)
	{
		i++;
		pr = pr->link;
	}
	return (i);
}
bool disp(PCB *pr)
{
	printf("\n name \t state \t needtime \t runtime \n");
	printf(" %s\t", pr->name);
	printf(" %c\t", pr->state);
	printf(" %d\t", pr->ntime);
	printf("         %d\t", pr->rtime);
	return (true);
}
bool check()
{
	PCB *pr;
	printf("\n ****当前运行的进程是：%s", p->name);
	disp(p);
	pr = ready;
	if (pr != NULL)
	{
		printf("\n****当前就绪队列状态为：");
	}
	else
	{
		printf("\n****当前就绪队列状态为空\n");
	}
	while (pr != NULL)
	{
		disp(pr);
		pr = pr->link;
	}
	return (true);
}
bool destory()
{
	printf("进程[%s],\n", p->name);
	free(p);
	return (true);
}
bool running()
{
	p->rtime+=timep;//运行方式不同
	if (p->rtime >= p->ntime)//判断方式也不同
	{
		destory();
	}
	else
	{
		p->state = 'W';
		sort();
	}
	return (true);
}

int _tmain(int argc, _TCHAR *argv[])
{
	int len, h = 0;
	char ch;
	input();
	len = space();
	while ((len != 0) && (ready != NULL))
	{
		ch = getchar();
		h++;
		printf("\n The execute number:%d \n", h);
		p = ready;
		ready = p->link;
		p->link = NULL;
		p->state = 'R';
		check();
		running();
		printf("\n按任意键继续.......");
		ch = getchar();
	}
	printf("\n\n 所有进程已经运行完成！\n");
	ch = getchar();
	return 0;
}