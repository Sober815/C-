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
	//ѹջ��أ��Ƚ����������ȳ�
	Push(&s, 1);
	Push(&s, 1);
	Push(&s, 2);
	traverse(&s);

	Pop(&s,&val);
	printf("������ֵΪ��%d \n", val);
	//����ջ
	traverse(&s);
	Clear(&s);
	traverse(&s);

	return 0;
}

void Init(PSTACK ps)
{
	//�����pTop��PNODE������
	//sizeofҲ��PNODE����
	ps->pTop = (PNODE)malloc(sizeof(NODE));

	if (ps->pTop == NULL)
	{
		printf("��̬�����ڴ�ʧ��\n");
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
	//ѹջ��ʱ��Ӧ���ȿ��ٿռ�
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	//���¿��ٵĿռ��val���ܵ�������
	pNew->data = val;
	//��r��ʱ��������ptop���ڵ�λ��
	r = ps->pTop;
	//��ptopָ���¿��ٵ��ڴ�
	ps->pTop = pNew;
	
	//�¿��ٵ��ڴ���ָ��r��ԭ��ptop��λ�ã�
	pNew->pNext = r;

	printf("ѹջ�ɹ�\n");

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
		printf("ջΪ�գ����ܱ���\n");
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
		printf("����ʧ�ܣ�ջΪ��\n");
	}

	//��ջ��ʱ��Ҫ����Ҫ�ͷſռ��
	PNODE p;
	//��¼��ջ����λ�ã�֮��p�����ͷ�
	p = ps->pTop;
	//��val��¼��data��λ��
	*val = ps->pTop->data;
	//ps->ptop ָ����һ��λ��
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
		//��һ����ps->ptop�������ͷ�
		//����ռ����˷�
		free(p);
		p = NULL;
		//������ʹջ�����ԭ����p->pNext ��λ��
		p = q;
	}
	ps->pTop = ps->pBottom;
}