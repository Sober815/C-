#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

//struct S
//{
//	int n;
//	float f;
//	char arr[10];
//};

//int main()
//{
//	struct S s = { 10, 3.14f, "hello" };
//	//一定要用"",‘’会出现问题
//	FILE * pf=fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		//printf("%s\n", strerror(errno));
//		return 0;
//	}
//	
//	//fsacnf(pf, "%n %f %s\n", &(s.n), &(s.f), s.arr);
//
//	//以格式化形式写文件
//	//将上面s的初始化数据写进了txt文件
//	fprintf(pf, "%d %f %s",s.n,s.f,s.arr );
//
//	//关闭
//	fclose(pf);
//	pf = NULL;
//	return 0;
//
//}

//int main()
//{
//	struct S s = { 0 };
//	//一定要用"",‘’会出现问题
//
//	//这里配合fsacnf ,要用r
//	FILE * pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		//printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//格式化输入数据
//	//读出现存在txt文件里面的内容到s.n,s.f,s.arr
//	//原来这个函数的初始化是将这三个变成0的。
//	//后来读完以后就会从文本中提取出来的来改变这个0的值
//	fscanf(pf, "%d %f %s", &(s.n), &(s.f), s.arr);
//	//将s显示在屏幕上面
//	printf("%d %f %s\n", s.n, s.f, s.arr);
//
//	//关闭
//	fclose(pf);
//	pf = NULL;
//	return 0;
//
//}


//typedef struct stu
//{
//	char name[20];
//	int age;
//	float score;
//
//}stu;

//int main()
//{
//	struct stu s = {"张三",20,30.9f};
//
//	//以二进制的形式写
//	FILE * pf=fopen("test.txt","wb");
//
//	fwrite(&s,sizeof(stu),1,pf);
//	
//	//写完以后就关了
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
//int main()
//{
//	//struct stu s = { "张三",20,30.9f };
//	stu tmp = { 0 };
//	//以二进制的形式写
//	FILE * pf = fopen("test.txt", "r");
//
//	fread(&tmp, sizeof(stu), 1, pf);
//
//	//写完以后就关了
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

