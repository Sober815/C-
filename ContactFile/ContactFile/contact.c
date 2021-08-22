#include "contact.h"

void Initcontact(struct contact* ps)
{
	//默认是三个的空间
	//用data指针来找开拓空间的地址
	ps->data=(struct contact *)malloc(default_capacity*sizeof(struct PeopleInfo));
	//如果没有开拓成功就返回空指针
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
			printf("扩容成功\n");
		}
		else {
			printf("扩容失败\n");

		}
		

	}
}

void Addcontact(struct contact * ps)
{
	
	//先检测是否需要扩容
	//如果满了增加容量
	//如果没满什么都不干
	DetectCapacity(ps);
	//添加
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
	//
	//if (ps->size == MAX)
	//{
	//	printf("通信录已满\n");
	//}//指针指向结构体然后在.访问成员变量
	//else
	//{
	//	printf("请输入姓名：>\n");
	//	scanf("%s", ps->data[ps->size].name);
	//	//这里由于要修改，必须传址，所以用&
	//	//而其他也是地址，只是数组名=地址
	//	printf("请输入age：>\n");
	//	scanf("%d", &(ps->data[ps->size].age));
	//	printf("请输入sex：>\n");
	//	scanf("%s", ps->data[ps->size].sex);
	//	printf("请输入tele：>\n");
	//	scanf("%s", ps->data[ps->size].tele);
	//	printf("请输入addr：>\n");
	//	scanf("%s", ps->data[ps->size].addr);

	//	ps->size++;
	//	printf("添加成功\n");

	//}
	//

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
		 printf("没找到删除的人\n");
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
 void FreeContact(struct contact * ps)
 {
	 free(ps->data);
	 ps->data = NULL;
	 printf("释放空间成功\n");
 
 }

 void SortContact(struct contact * ps)
 {
	 int i = 0;
	 for (i = 0; i < ps->size; i++)
	 {
		 struct PeopleInfo tmp = {0};
		 //通过姓名来排序
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
	 //如果是空指针
	 if (pf == NULL)
	 {
		 printf("%s\n", strerror(errno));
		 return;
	 }
	 //如果不是空指针

	 for(i=0;i<ps->size;i++)
		fwrite(&(ps->data[i]),sizeof(struct PeopleInfo),1,pf);
	
	 
	 printf("写入txt完成\n");



	 //关闭
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


	//第一个是存放的buff 	 
	 while (fread(&tmp, sizeof(struct PeopleInfo), 1, pfRead))
	 {
		 //检测是否需要扩容
		 DetectCapacity(ps);

		 ps->data[ps->size] = tmp;
		 ps->size++;	

	 }
	 //关闭
	 fclose(pfRead);
	 pfRead = NULL;


 }