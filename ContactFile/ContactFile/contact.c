#include "contact.h"

void Initcontact(struct contact* ps)
{
	//Ĭ���������Ŀռ�
	//��dataָ�����ҿ��ؿռ�ĵ�ַ
	ps->data=(struct contact *)malloc(default_capacity*sizeof(struct PeopleInfo));
	//���û�п��سɹ��ͷ��ؿ�ָ��
	if (ps->data==NULL)
	{
		return;
	}
	
	ps->capacity = default_capacity;
	ps->size = 0;

	LoadContact(ps);


}

void DetectCapacity(struct contact *ps)
{
	if (ps->size == ps->capacity)
	{
		struct contact *ptr=realloc(ps->data, (sizeof(struct PeopleInfo)*(ps->capacity + 2) ));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("���ݳɹ�\n");
		}
		else {
			printf("����ʧ��\n");

		}
		

	}
}

void Addcontact(struct contact * ps)
{
	
	//�ȼ���Ƿ���Ҫ����
	//���������������
	//���û��ʲô������
	DetectCapacity(ps);
	//���
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
	//
	//if (ps->size == MAX)
	//{
	//	printf("ͨ��¼����\n");
	//}//ָ��ָ��ṹ��Ȼ����.���ʳ�Ա����
	//else
	//{
	//	printf("������������>\n");
	//	scanf("%s", ps->data[ps->size].name);
	//	//��������Ҫ�޸ģ����봫ַ��������&
	//	//������Ҳ�ǵ�ַ��ֻ��������=��ַ
	//	printf("������age��>\n");
	//	scanf("%d", &(ps->data[ps->size].age));
	//	printf("������sex��>\n");
	//	scanf("%s", ps->data[ps->size].sex);
	//	printf("������tele��>\n");
	//	scanf("%s", ps->data[ps->size].tele);
	//	printf("������addr��>\n");
	//	scanf("%s", ps->data[ps->size].addr);

	//	ps->size++;
	//	printf("��ӳɹ�\n");

	//}
	//

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
		 printf("û�ҵ�ɾ������\n");
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
 void FreeContact(struct contact * ps)
 {
	 free(ps->data);
	 ps->data = NULL;
	 printf("�ͷſռ�ɹ�\n");
 
 }

 void SortContact(struct contact * ps)
 {
	 int i = 0;
	 for (i = 0; i < ps->size; i++)
	 {
		 struct PeopleInfo tmp = {0};
		 //ͨ������������
		 if (memcmp(ps->data[i].name, ps->data[i + 1].name,1)>0)
		 {
			 tmp = ps->data[i];
			 ps->data[i ] = ps->data[i + 1];
			 ps->data[i + 1] = tmp;

		 }
	 }
 }

 void SaveContact(struct contact * ps)
 {
	 int i;
	 FILE * pf = fopen("contact.txt", "wb");
	 //����ǿ�ָ��
	 if (pf == NULL)
	 {
		 printf("%s\n", strerror(errno));
		 return;
	 }
	 //������ǿ�ָ��

	 for(i=0;i<ps->size;i++)
		fwrite(&(ps->data[i]),sizeof(struct PeopleInfo),1,pf);
	
	 
	 printf("д��txt���\n");



	 //�ر�
	 fclose(pf);
	 pf = NULL;

	 
 }
 void LoadContact(struct contact * ps)
 {
	 int i = 0;
	 struct PeopleInfo tmp = { 0 };
	 FILE *pfRead= fopen("contact.txt","rb");

	 if (pfRead == NULL)
	 {
		 printf("InitContact:%s\n",strerror(errno));
		 return;
	 }


	//��һ���Ǵ�ŵ�buff 	 
	 while (fread(&tmp, sizeof(struct PeopleInfo), 1, pfRead))
	 {
		 //����Ƿ���Ҫ����
		 DetectCapacity(ps);

		 ps->data[ps->size] = tmp;
		 ps->size++;	

	 }
	 //�ر�
	 fclose(pfRead);
	 pfRead = NULL;


 }