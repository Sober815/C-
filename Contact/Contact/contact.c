#include "contact.h"

void Initcontact(struct contact* ps)
{
	memset(ps->data,0,sizeof(ps->data));
	ps->size = 0;



}


void Addcontact(struct contact * ps)
{
	
	
	if (ps->size == MAX)
	{
		printf("ͨ��¼����\n");
	}//ָ��ָ��ṹ��Ȼ����.���ʳ�Ա����
	else
	{
		printf("������������>\n");
		scanf("%s", ps->data[ps->size].name);
		//��������Ҫ�޸ģ����봫ַ��������&
		//������Ҳ�ǵ�ַ��ֻ��������=��ַ
		printf("������age��>\n");
		scanf("%d", &(ps->data[ps->size].age));
		printf("������sex��>\n");
		scanf("%s", ps->data[ps->size].sex);
		printf("������tele��>\n");
		scanf("%s", ps->data[ps->size].tele);
		printf("������addr��>\n");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("��ӳɹ�\n");

	}
	

}

void Showcontact(const struct contact * ps)
{
	if (ps->size == 0)
	{
		printf("ͨ��¼Ϊ��\n");

	}
	else
	{
		printf("%s\t %s\t %s\t %s\t %s\n", "name", "age", "sex", "tele", "addr");
		int i;
		for (i = 0; i < ps->size; i++)
		{
			//���������������int������������
			printf("%s\t %d\t %s\t %s\t %s\n",
				ps->data[i].name, 
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele, 
				ps->data[i].addr);

		}
	}
	

}
 static int FindbyName(const struct contact *ps, char name[MAX_NAME])
{
	 
	 int i = 0;
	 for (i = 0; i < ps->size; i++)
	 {
		 if (strcmp(ps->data[i].name, name) == 0)
		 {
			 return i;
		 }
	 }

	 return -1;


}
 void Delcontact(struct contact * ps)
 {
	 //��ͨ�����ֲ���ɾ��������
	 char name[MAX_NAME];
	 printf("������Ҫɾ���˵�����\n");
	 scanf("%s", &name);
	 int pos = FindbyName(ps, name);

	 if (pos == -1)
	 {
		 printf("û�ҵ�ɾ������");
	 }
	 else
	 {
		 //ɾ���ú��渲��ǰһ���ķ���
		 int j;
		 //size-1 
		 //�����1 2 3 4 5 6 7 8
		 // 4��Ҫɾ�����Ǹ���ps->size-1�����һ��7
		 //�������Ҫ����8->7��λ��
		 for (j = pos; j < ps->size - 1; j++)
		 {
			 //ȫ�����
			 (ps->data[j]) = (ps->data[j + 1]);

		 }

		 ps->size--;
	 }
 }
 void SearchContact(const struct contact * ps)
 {
 
	 //��ͨ�����ֲ���
	 char name[MAX_NAME];
	 printf("������Ҫ�����˵�����\n");
	 scanf("%s", &name);
	 int pos = FindbyName(ps, name);
	 if (pos == -1)
	 {
		 printf("û�������");
	 }
	 else
	 {
		 printf("%s\t %s\t %s\t %s\t %s\n", "name", "age", "sex", "tele", "addr");
		
			 //���������������int������������
			 printf("%s\t %d\t %s\t %s\t %s\n",
				 ps->data[pos].name,
				 ps->data[pos].age,
				 ps->data[pos].sex,
				 ps->data[pos].tele,
				 ps->data[pos].addr);		 

	 }
 }

 void ModifyContact(const struct contact * ps)
 {
	 //x�޸Ĳ�������
	 char name[MAX_NAME];
	 printf("������Ҫ�޸��˵�����\n");
	 scanf("%s", &name);
	 int pos = FindbyName(ps, name);
	 if (pos == -1)
	 {
		 printf("û�������\n");

	 }
	 else
	 {
		 printf("�������޸ĺ�������>\n");
		 scanf("%s", ps->data[pos].name);
		 //��������Ҫ�޸ģ����봫ַ��������&
		 //������Ҳ�ǵ�ַ��ֻ��������=��ַ
		 printf("�������޸ĺ�age��>\n");
		 scanf("%d", &(ps->data[pos].age));
		 printf("�������޸ĺ�sex��>\n");
		 scanf("%s", ps->data[pos].sex);
		 printf("�������޸ĺ�tele��>\n");
		 scanf("%s", ps->data[pos].tele);
		 printf("�������޸ĺ�addr��>\n");
		 scanf("%s", ps->data[pos].addr);

		
		 printf("�޸ĳɹ�\n");
	 }

 }