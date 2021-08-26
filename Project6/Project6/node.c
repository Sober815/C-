#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
	int data; //������
	struct Node * pNext;//ָ����
}Node,*PNode;  //Node ָ����struct Node *PNode �ȼ� struct Node *


//Ҫ�󷵻�ֵ��һ����ַ
//������һ���ṹ��ָ��������Ϊ����
PNode create_list(void)
{
	int length;
	int val;//��ʱ�洢�ڵ�����

	
	//������һ����������ݵ�ͷ�ڵ�
	PNode pHead = (PNode)malloc(sizeof(Node));

	PNode pTail=pHead;
	pTail->pNext = NULL;


	if (pHead == NULL)
	{
		printf("���ٿռ�ʧ��\n");
		exit(-1);//�����жϣ�����-1
	}
	//���뿪�ٿռ�Ĵ�С
	printf("��������Ҫ�����ڵ�\n");
	scanf("%d", &length);
	for (int i = 0; i < length; i++)
	{
		printf("�������%d���ڵ������", i + 1);
		//scanf�����治Ҫ���ո�

		scanf("%d", &val);
		PNode pNew= (PNode)malloc(sizeof(Node));
		if (pNew == NULL)
		{
			printf("�����ڴ�ʧ��\n");
			exit(-1);
		}
		pNew->data = val;
		//��������һ��
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
		

	}
	return pHead ;
}



void traverse_list(PNode pHead)
{
	if (pHead == NULL)
	{
		printf("����ʧ��\n");
		exit(-1);
	}
	//��ͷ�������
	//ͷ��������ֵ��p���׽ڵ㣬��ŵ�����Ч����
	PNode p = pHead->pNext;
	while (p != NULL)
	{


		printf("%d ", p->data);
		p = p->pNext;

	}
	//ѭ������
	printf("\n");
	return;


}

bool is_empty(PNode pHead)
{
	//ͷ���ĺ���һ��Ϊ�գ����ǿ�
	if (pHead->pNext == NULL)
		return true;
	else
		return false;
}
int length_list(PNode pHead)
{
	int length = 0;
	//p���׽ڵ�
	PNode p = pHead->pNext;
	while (p != NULL)
	{
		//pָ����һ���ڵ�
		p=p->pNext;
		//Ȼ�󳤶�+1
		length++;
	}
	return length;
}

void sort_list(PNode pHead)
{
	int i, j, t;
	int length = length_list(pHead);
	
	//�׽ڵ�
	PNode p ,q;
	for (i = 0,p= pHead->pNext; i < length - 1; i++,p=p->pNext)
	{
		for (j = i + 1,q=p->pNext; j < length; j++,q=q->pNext)
		{
			//�����ɴ�С
			if (p->data < q->data)
			{
				t = p->data;//t = i;
				p->data = q->data;//i = j;
				q->data = t;//j = t;
			}
	
		}
	}

}

bool insert_list(PNode pHead,int pos,int val)
{
	int i=0;
	PNode p = pHead;

	//�����������ȥͷ��㲻��Ϊ�գ���Ȼ����û�γ�û�취���ȥ
	//i<pos-1�����i����������ǰһ��λ��
	while (p!=NULL&&i<pos-1)
	{
		p = p->pNext;
		i++;
	}
	if (i > pos - 1 || p == NULL)
		return false;
	PNode pNew = (PNode)malloc(sizeof(Node));

	//���µĽṹ��ָ��������
	 pNew->data = val;
	 PNode q;
	 q=p->pNext ;
	 p->pNext = pNew;
	 pNew->pNext = q;

	 printf("����ɹ�\n");
	 return true;

}

bool delete_list(PNode pHead,int pos,int *val)
{
	int i = 0;
	PNode p = pHead;

	//�����������ȥͷ��㲻��Ϊ�գ���Ȼ����û�γ�û�취���ȥ
	//i<pos-1�����i����������ǰһ��λ��
	while (p->pNext != NULL && i < pos - 1)
	{
		p = p->pNext;
		i++;
	}
	if (i > pos - 1 || p->pNext == NULL)
		return false;

	//ɾ����˼���ǣ�����ֱ�Ӵӿ�ʼ�Ǹ�������һ��

	PNode q=p->pNext;
	//��ɾ�����Ǹ�ֵ����
	//������ָ��װ�������ſ����ں��������ʱ�򲻱�����
	*val = q->data;

	p->pNext = p->pNext->pNext;

	//�ͷ�ָ�룬��ֹ���Ұָ��
	free(q);
	q = NULL;

	printf("ɾ���ɹ�\n");
	return true;

}


int main()
{
	PNode pHead = NULL;//ͷָ���ǿ�ָ��
	int val;
	
	//����һ��������������׵�ַ����pHead
	pHead=create_list();
	//����һ������
	traverse_list(pHead);
	if (is_empty(pHead))
	{
		printf("����Ϊ��\n");
	}
	else
	{
		printf("����Ϊ��\n");
	}

	printf("����ĳ���Ϊ%d \n", length_list(pHead));

	sort_list(pHead);
	traverse_list(pHead);

	insert_list(pHead, 3, 20);
	traverse_list(pHead);
	if (delete_list(pHead, 1, &val))
	{
		printf("ɾ���ɹ���ɾ����ֵΪ%d\n", val);
	}
	else
	{
		printf("ɾ��ʧ��\n");
	}
	traverse_list(pHead);

	return 0;

}

