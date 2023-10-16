// scheduling.cpp : 定义控制台应用程序的入口点。
// 仿真进程动态到达

#include "stdafx.h"
#include "scheduling.h"
#include "stdlib.h"
#include "time.h"

#define scanf_s scanf // 偷懒行为(O_o)

#define getstruct(type) (type *)malloc(sizeof(type));
PCB *ready = NULL, *p;
int allacp = 0;

char *genRandomString(char string[], int length) // 随机生成字符串
{
	int flag, i;
	srand((unsigned)time(NULL));
	for (i = 0; i < length - 1; i++)
	{
		flag = rand() % 3;
		switch (flag)
		{
		case 0:
			string[i] = 'A' + rand() % 26;
			break;
		case 1:
			string[i] = 'a' + rand() % 26;
			break;
		case 2:
			string[i] = '0' + rand() % 10;
			break;
		default:
			string[i] = 'x';
			break;
		}
	}
	string[length - 1] = '\0';
	return string;
}
bool sort() // 按照nice数大小入队操作
{
	PCB *first, *second;
	int insert = 0;
	if ((ready == NULL) || (p->nice > ready->nice)) // 队列为空，或者队首比当前进程优先级小
	{
		p->link = ready;
		ready = p; // 直接赋值给第一个
	}
	else // 普通情况下
	{
		first = ready;
		second = first->link;
		// first指向一个进程，second指向first的下一个进程
		while (second != NULL) // 从队首开始迭代，要么迭代到最后没找到
		{
			if (p->nice > second->nice) // 找到小于当前进程的
			{
				p->link = second;
				first->link = p;
				second = NULL;
				insert = 1; // 插入操作
			}
			else // 没找到继续迭代
			{
				first = first->link;
				second = second->link;
			}
		}
		if (insert == 0)
			first->link = p;
	}
	return (true);
}
bool input() // 正常创建进程，结构体为基础，指针操作
{
	int num;
	printf("\n请输入进程数：");
	scanf_s("%d", &num);
	for (int i = 0; i < num; i++)
	{
		printf("\n进程号:%d", i);
		p = getstruct(PCB); // 动态开辟空间
		printf("\n输入进程名:");
		scanf_s("%s", p->name, 10);
		printf("\n输入进优先数:");
		int temp;
		// scanf_s("%d", &temp, sizeof(int));
		// p->nice = temp;
		scanf_s("%d", &(p->nice), sizeof(int));
		printf("\n输入进程运行时间:");
		scanf_s("%d", &(p->ntime), sizeof(int));
		printf("\n");
		p->rtime = 0;
		p->state = 'W';
		p->link = NULL;
		sort();
		allacp++;
	}
	return (true);
}
int space() // 返回就绪队列的长度
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
bool disp(PCB *pr) // 显示信息
{
	printf("\n name \t state \t nice \t needtime \t runtime \n");
	printf(" %s\t", pr->name);
	printf(" %c\t", pr->state);
	printf(" %d\t", pr->nice);
	printf(" %d\t", pr->ntime);
	printf("         %d\t", pr->rtime);
	return (true);
}
bool check() // 打印当前运行进程以及队列信息
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
bool destory() // 进程结束后释放空间
{
	printf("进程[%s],\n", p->name);
	free(p);
	return (true);
}
bool running() // 进程运行
{
	p->rtime++;
	if (p->rtime == p->ntime)
	{
		destory();
	}
	else
	{
		p->nice--;
		p->state = 'W';
		sort();
	}
	return (true);
}

int _tmain(int argc, _TCHAR *argv[])
{
	srand(time(NULL));
	int len, h = 0;
	char ch;
	input();
	len = space();
	int choice;
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
		choice = rand() % 2;
		if (choice == 1) // 判断
		{
			int num = rand() % 10 + 1; // 新进程个数，1-10个
			printf("\n=========有%d个新进程到达=========\n", num);

			for (int x = 1; x <= num; x++)
			{
				printf("\n进程号:%d", allacp);
				p = getstruct(PCB); // 动态开辟空间
				printf("\n进程名:");
				genRandomString(p->name, rand() % 5 + 2); // 随机生成名字
				printf("%s", p->name);
				printf("\n优先数:");
				p->nice = rand() % 10 + 1; // 随机nice数
				printf("%d", p->nice);
				printf("\n进程运行时间:");
				p->ntime = rand() % 10 + 1; // 随机运行时间
				printf("%d", p->ntime);
				printf("\n");
				p->rtime = 0;
				p->state = 'W';
				p->link = NULL;
				sort();
				allacp++;
				ch = getchar();
			}
		}
		else
		{
			printf("\n");
		}
		printf("\n按任意键继续.......");
		ch = getchar();
	}
	printf("\n\n 所有进程已经运行完成！\n");
	ch = getchar();
	return 0;
}