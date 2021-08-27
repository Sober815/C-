#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct Node
{
	int data;
	struct Node * pNext;
}NODE,*PNODE;


typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;

}STACK,*PSTACK;

void Init(PSTACK ps);
void Push(PSTACK ps, int val);
void traverse(PSTACK ps);
void Clear(PSTACK ps);

bool Pop(PSTACK ps ,int *val);
bool empty(PSTACK ps);

int main()
{
	int val;
	STACK s;
	Init(&s);
	//压栈规矩：先进后出，后进先出
	Push(&s, 1);
	Push(&s, 1);
	Push(&s, 2);
	traverse(&s);

	Pop(&s,&val);
	printf("弹出的值为：%d \n", val);
	//遍历栈
	traverse(&s);
	Clear(&s);
	traverse(&s);

	return 0;
}

void Init(PSTACK ps)
{
	//这里的pTop是PNODE的类型
	//sizeof也是PNODE类型
	ps->pTop = (PNODE)malloc(sizeof(NODE));

	if (ps->pTop == NULL)
	{
		printf("动态分配内存失败\n");
	}
	else
	{
		ps->pBottom = ps->pTop;
		ps->pTop->pNext = NULL;
	}
	
}

void Push(PSTACK ps, int val)
{
	PNODE r;
	//压栈的时候应该先开辟空间
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	//用新开辟的空间把val接受到数据域
	pNew->data = val;
	//用r暂时储存现在ptop所在的位置
	r = ps->pTop;
	//用ptop指向新开辟的内存
	ps->pTop = pNew;
	
	//新开辟的内存又指向r（原来ptop的位置）
	pNew->pNext = r;

	printf("压栈成功\n");

}

bool empty(PSTACK ps)
{
	if (ps->pBottom == ps->pTop)
		return true;
	else
		return false;
}

void traverse(PSTACK ps)
{
	PNODE p;
	if (empty(ps))
	{
		printf("栈为空，不能遍历\n");
		exit(-1);
	}
	else
	{
		p = ps->pTop;

		while (p!=ps->pBottom)
		{
			printf("%d ", p->data);
			p=p->pNext;
		}
		printf("\n");
		return;
	}


}

bool Pop(PSTACK ps, int *val)
{
	if (empty(ps))
	{
		printf("弹出失败，栈为空\n");
	}

	//出栈的时候要求是要释放空间的
	PNODE p;
	//记录下栈顶的位置，之后p用来释放
	p = ps->pTop;
	//用val记录下data的位置
	*val = ps->pTop->data;
	//ps->ptop 指向下一个位置
	ps->pTop = ps->pTop->pNext;

	free(p);
	p = NULL;

	return true;
}

void Clear(PSTACK ps)
{
	PNODE p,q;
	p = ps->pTop;
	q = NULL;
	while (p != ps->pBottom)
	{
		q = p->pNext;
		//第一个的ps->ptop在这里释放
		//以免空间有浪费
		free(p);
		p = NULL;
		//这里是使栈顶变成原来的p->pNext 的位置
		p = q;
	}
	ps->pTop = ps->pBottom;
}