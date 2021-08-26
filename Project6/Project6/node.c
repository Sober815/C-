#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
	int data; //数据域
	struct Node * pNext;//指针域
}Node,*PNode;  //Node 指的是struct Node *PNode 等价 struct Node *


//要求返回值是一个地址
//所以是一个结构体指针类型作为返回
PNode create_list(void)
{
	int length;
	int val;//临时存储节点数据

	
	//分配了一个不存放数据的头节点
	PNode pHead = (PNode)malloc(sizeof(Node));

	PNode pTail=pHead;
	pTail->pNext = NULL;


	if (pHead == NULL)
	{
		printf("开辟空间失败\n");
		exit(-1);//程序中断，返回-1
	}
	//输入开辟空间的大小
	printf("请输入你要几个节点\n");
	scanf("%d", &length);
	for (int i = 0; i < length; i++)
	{
		printf("请输入第%d个节点的数据", i + 1);
		//scanf这里面不要留空格

		scanf("%d", &val);
		PNode pNew= (PNode)malloc(sizeof(Node));
		if (pNew == NULL)
		{
			printf("分配内存失败\n");
			exit(-1);
		}
		pNew->data = val;
		//连接着下一个
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
		printf("遍历失败\n");
		exit(-1);
	}
	//把头结点跳过
	//头结点是随机值，p是首节点，存放的是有效数据
	PNode p = pHead->pNext;
	while (p != NULL)
	{


		printf("%d ", p->data);
		p = p->pNext;

	}
	//循环结束
	printf("\n");
	return;


}

bool is_empty(PNode pHead)
{
	//头结点的后面一个为空，就是空
	if (pHead->pNext == NULL)
		return true;
	else
		return false;
}
int length_list(PNode pHead)
{
	int length = 0;
	//p是首节点
	PNode p = pHead->pNext;
	while (p != NULL)
	{
		//p指向下一个节点
		p=p->pNext;
		//然后长度+1
		length++;
	}
	return length;
}

void sort_list(PNode pHead)
{
	int i, j, t;
	int length = length_list(pHead);
	
	//首节点
	PNode p ,q;
	for (i = 0,p= pHead->pNext; i < length - 1; i++,p=p->pNext)
	{
		for (j = i + 1,q=p->pNext; j < length; j++,q=q->pNext)
		{
			//降序，由大到小
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

	//如果你想插入进去头结点不能为空，不然链表都没形成没办法插进去
	//i<pos-1是想把i带到插入点的前一个位置
	while (p!=NULL&&i<pos-1)
	{
		p = p->pNext;
		i++;
	}
	if (i > pos - 1 || p == NULL)
		return false;
	PNode pNew = (PNode)malloc(sizeof(Node));

	//用新的结构体指向数据域
	 pNew->data = val;
	 PNode q;
	 q=p->pNext ;
	 p->pNext = pNew;
	 pNew->pNext = q;

	 printf("插入成功\n");
	 return true;

}

bool delete_list(PNode pHead,int pos,int *val)
{
	int i = 0;
	PNode p = pHead;

	//如果你想插入进去头结点不能为空，不然链表都没形成没办法插进去
	//i<pos-1是想把i带到插入点的前一个位置
	while (p->pNext != NULL && i < pos - 1)
	{
		p = p->pNext;
		i++;
	}
	if (i > pos - 1 || p->pNext == NULL)
		return false;

	//删除的思想是，链表直接从开始那个，跳过一个

	PNode q=p->pNext;
	//把删除的那个值返回
	//必须用指针装起来，才可以在函数跑完的时候不被销毁
	*val = q->data;

	p->pNext = p->pNext->pNext;

	//释放指针，防止变成野指针
	free(q);
	q = NULL;

	printf("删除成功\n");
	return true;

}


int main()
{
	PNode pHead = NULL;//头指针是空指针
	int val;
	
	//创建一个链表，把链表的首地址赋给pHead
	pHead=create_list();
	//遍历一个链表
	traverse_list(pHead);
	if (is_empty(pHead))
	{
		printf("链表为空\n");
	}
	else
	{
		printf("链表不为空\n");
	}

	printf("链表的长度为%d \n", length_list(pHead));

	sort_list(pHead);
	traverse_list(pHead);

	insert_list(pHead, 3, 20);
	traverse_list(pHead);
	if (delete_list(pHead, 1, &val))
	{
		printf("删除成功，删除的值为%d\n", val);
	}
	else
	{
		printf("删除失败\n");
	}
	traverse_list(pHead);

	return 0;

}

