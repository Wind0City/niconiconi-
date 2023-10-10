//#define _CRT_SECURE_NO_WARNINGS
struct pcb
{
	char name[10];
	char state;
	int nice;
	int ntime;
	int rtime;
	struct pcb * link;
};
typedef struct pcb PCB;