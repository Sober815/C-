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
//	//һ��Ҫ��"",�������������
//	FILE * pf=fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		//printf("%s\n", strerror(errno));
//		return 0;
//	}
//	
//	//fsacnf(pf, "%n %f %s\n", &(s.n), &(s.f), s.arr);
//
//	//�Ը�ʽ����ʽд�ļ�
//	//������s�ĳ�ʼ������д����txt�ļ�
//	fprintf(pf, "%d %f %s",s.n,s.f,s.arr );
//
//	//�ر�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//
//}

//int main()
//{
//	struct S s = { 0 };
//	//һ��Ҫ��"",�������������
//
//	//�������fsacnf ,Ҫ��r
//	FILE * pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		//printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//��ʽ����������
//	//�����ִ���txt�ļ���������ݵ�s.n,s.f,s.arr
//	//ԭ����������ĳ�ʼ���ǽ����������0�ġ�
//	//���������Ժ�ͻ���ı�����ȡ���������ı����0��ֵ
//	fscanf(pf, "%d %f %s", &(s.n), &(s.f), s.arr);
//	//��s��ʾ����Ļ����
//	printf("%d %f %s\n", s.n, s.f, s.arr);
//
//	//�ر�
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
//	struct stu s = {"����",20,30.9f};
//
//	//�Զ����Ƶ���ʽд
//	FILE * pf=fopen("test.txt","wb");
//
//	fwrite(&s,sizeof(stu),1,pf);
//	
//	//д���Ժ�͹���
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}
//
//int main()
//{
//	//struct stu s = { "����",20,30.9f };
//	stu tmp = { 0 };
//	//�Զ����Ƶ���ʽд
//	FILE * pf = fopen("test.txt", "r");
//
//	fread(&tmp, sizeof(stu), 1, pf);
//
//	//д���Ժ�͹���
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

