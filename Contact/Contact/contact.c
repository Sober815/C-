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
		printf("通信录已满\n");
	}//指针指向结构体然后在.访问成员变量
	else
	{
		printf("请输入姓名：>\n");
		scanf("%s", ps->data[ps->size].name);
		//这里由于要修改，必须传址，所以用&
		//而其他也是地址，只是数组名=地址
		printf("请输入age：>\n");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入sex：>\n");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入tele：>\n");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入addr：>\n");
		scanf("%s", ps->data[ps->size].addr);

		ps->size++;
		printf("添加成功\n");

	}
	

}

void Showcontact(const struct contact * ps)
{
	if (ps->size == 0)
	{
		printf("通信录为空\n");

	}
	else
	{
		printf("%s\t %s\t %s\t %s\t %s\n", "name", "age", "sex", "tele", "addr");
		int i;
		for (i = 0; i < ps->size; i++)
		{
			//留意这里的年龄是int，而不是数组
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
	 //先通过名字查找删除的名字
	 char name[MAX_NAME];
	 printf("请输入要删除人的名字\n");
	 scanf("%s", &name);
	 int pos = FindbyName(ps, name);

	 if (pos == -1)
	 {
		 printf("没找到删除的人");
	 }
	 else
	 {
		 //删除用后面覆盖前一个的方法
		 int j;
		 //size-1 
		 //是如果1 2 3 4 5 6 7 8
		 // 4是要删除的那个，ps->size-1到最后一个7
		 //我们最后要求是8->7的位置
		 for (j = pos; j < ps->size - 1; j++)
		 {
			 //全部替代
			 (ps->data[j]) = (ps->data[j + 1]);

		 }

		 ps->size--;
	 }
 }
 void SearchContact(const struct contact * ps)
 {
 
	 //先通过名字查找
	 char name[MAX_NAME];
	 printf("请输入要查找人的名字\n");
	 scanf("%s", &name);
	 int pos = FindbyName(ps, name);
	 if (pos == -1)
	 {
		 printf("没有这个人");
	 }
	 else
	 {
		 printf("%s\t %s\t %s\t %s\t %s\n", "name", "age", "sex", "tele", "addr");
		
			 //留意这里的年龄是int，而不是数组
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
	 //x修改查人人名
	 char name[MAX_NAME];
	 printf("请输入要修改人的名字\n");
	 scanf("%s", &name);
	 int pos = FindbyName(ps, name);
	 if (pos == -1)
	 {
		 printf("没有这个人\n");

	 }
	 else
	 {
		 printf("请输入修改后姓名：>\n");
		 scanf("%s", ps->data[pos].name);
		 //这里由于要修改，必须传址，所以用&
		 //而其他也是地址，只是数组名=地址
		 printf("请输入修改后age：>\n");
		 scanf("%d", &(ps->data[pos].age));
		 printf("请输入修改后sex：>\n");
		 scanf("%s", ps->data[pos].sex);
		 printf("请输入修改后tele：>\n");
		 scanf("%s", ps->data[pos].tele);
		 printf("请输入修改后addr：>\n");
		 scanf("%s", ps->data[pos].addr);

		
		 printf("修改成功\n");
	 }

 }