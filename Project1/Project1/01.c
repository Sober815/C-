
//#include <stdio.h>


//int main()
//{
//	char arr1[] = "bit";
//	char arr2[] = "++++";
//	strcpy(arr2, arr1);  //��ar1�ķ�ȥarr2 ,char* strcpy
//	printf("%s\n", arr2);
//	
//	return 0;
//	
//}


//memset memory �ڴ�   set ����

// void * memset (void *ptr,int value , size_t num);
//��ptr �����ǰnum��ֵ����Ϊvalue
//int main()
//{
//	char arr[] = "hello world ";
//	memset(arr, '*', 5);
//	printf("%s\n", arr);
//	return  0;
//}

//int get_max(int x,int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//
//int main()
//{
//	int a=20;
//	int b=10;
//	int c = get_max(a, b);
//	printf("%d\n", c);
//
//
//	return 0;
//
//}
//
//
//�����������
//void swap1(int  x, int  y)
//{
//	int temp = 0;
//	temp = x;
//	x= y;
//	y = temp;
//
//}

//void swap2(int*  x, int* y)
//{
//	int temp = 0;
//	temp = *x;
//	*x = *y;
//	*y = temp;
//
//}
//
//int main()
//{
//	int a=10;
//	int b=2;
//	printf("%d,%d\n", a, b);
//	/*swap1(a, b);*/
//	swap2(&a, &b);
//	printf("a=%d,b=%d", a, b);
//	return 0;
//
//}


//int main()
//{
//	int a = 110;
//	int* pa=&a;
//	*pa = 20;
//	printf("a=%d", a);
//	return 0;
//
//}

//�������ͷŻ�1 .���������ͷ���0
//int is_prime(int n)
//{
//	//2->N-1
//	int j;
//
//	for (j = 2; j < n - 1; j++)
//	{
//		if (n%j == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int main()
//{
//	int i;
//	for (i = 100; i < 200; i++) 
//	{
//		if (is_prime(i) == 1)
//			printf("%d\n", i);
//	
//	
//	}
//}
//��������귵��1
//int is_leap_year(int x)
//{
//	if ((x % 4 == 0&& x%100!=0)||( x %400==0))
//		return 1;
//	else
//		return 0;
//
//
//}
//
//int main()
//{
//
//	int year;
//	for (year = 1000; year < 2000; year++)
//	{
//		if (is_leap_year(year) == 1)
//		{
//			printf("%d\t", year);
//		}
//
//	}
//	return 0; 
//
//}

//�����������в��Ҿ����ĳ����
//int binary_search(int arr[], int n)
//{
//	int j = 0;
//	for (j = 0; j < n;j++)
//	{
//		if (arr[j] == n)
//			return arr[j];
//	}
//	return -1;
//}

//
//int binary_search(int arr[], int n,int size)
//{
//	int left = 0;
//	int right = size - 1;
//	
//	//���ֲ��ҷ�
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < n)
//		{
//			left = mid + 1;
//
//		}
//		else if (arr[mid] > n)
//		{
//			right = mid;
//
//		}
//		else
//		{
//			return arr[mid];
//		}
//	}
//	
//	return -1;
//	 
//
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,9 };
//	//printf("arr[]��С:%d", sizeof(arr));
//	//printf("arr[]����:%d", sizeof(arr)/sizeof(arr[0]));
//	int size = (sizeof(arr) / sizeof(arr[0]));
//	int k = 7;
//	int ret=binary_search(arr, k,size);
//	if (ret == -1)
//	{
//		printf("û�ҵ�����\n");
//
//	}
//	else
//	{
//		printf("���ҵ���%d", ret);
//	}
//
//	return 0;
//}

//����һ�κ����Ժ�ÿ�μ�1

//void Add(int* p)
//{
//	(*p)++;
//}
//
//int main()
//{
//	int num=0;
//	Add(&num);//Ҫ�ı������ֵ��ʱ��͵ô���ַ
//	printf("%d", num);
//	Add(&num);//Ҫ�ı������ֵ��ʱ��͵ô���ַ
//	printf("%d", num);
//
//
//} 

#include <stdio.h>

//void print(int n)
//{
//	if (n > 9)
//	{
//		print(n/10);
//		
//	}
//	printf("%d", n%10);
//
//}
//
//int main()
//{
//	unsigned int num=0;
//	scanf("%d", &num);
//	print(num);
//	return 0;
//}

//дһ�������ַ����ȵĺ���
//ģ��ʵ����strlen 
//int my_strlen(char *arr)
//{
//	int count=0;
//	while (*arr != '\0')
//	{
//		count++;//������һ
//		arr++; //��ַָ��ڶ���Ԫ�صĵ�ַ
//	}
//	return count;
//}
//�õݹ鷽��ʵ�֣����ñ�������
//int my_strlen(char* arr)
//{
//	if (*arr != '\0')
//		return 1 + my_strlen(arr+1);
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	char arr[] = "bit"; //�������һ����\0
//	int a=my_strlen(arr);//�������arr�����һ��Ԫ�ص��׵�ַ
//	printf("%d", a);
//	return 0;
//}

//��׳�
//int Fac(int n)
//{
//	int i;
//	int res = 1;
//	for (i = 1; i <=n; i++)
//	{
//		res *= i;
//	}
//	return res;
//}

//int Fac(int n)
//{
//	if(n>1)
//	{	
//		return n*Fac(n - 1);
//	}
//	else
//	{
//		return 1;
//	}
//	
//	
//}
//
//int main()
//{
//	int n=0;
//	int res = 0;;
//	scanf("%d", &n);
//	res = Fac(n);
//	printf("%d", res);
//	return 0;
//}
//int Fib(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return Fib(n - 1) + Fib(n - 2);
//	}
//}
//ѭ��
//int Fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n >=3)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//
//int main()
//{
//	int n;
//	int ret;
//	scanf("%d",  &n);
//	ret = Fib(n);
//	printf("%d\n",ret);
//	
//	return 0; 
// }

//int main()
//{
//	//sizeof����arr���ڿռ�Ĵ�С,��\0��
//	//strlen��arr�ַ����ĳ��ȣ�����\0
//
//	int arr[] = { 0,1,2,3,4,5,6		};
//	printf("1=%d", sizeof(arr) / sizeof(arr[0]));//�ܴ�С����һ��Ԫ�ش�С�͵ø���
//	
//
//}

//int main()
//{	
//	int i;
//	int arr[] = { 0,1,2,3,4,5,6,7 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < len; i++)
//	{
//		printf("arr[%d]�ĵ�ַ��%p\n", i, &arr[i]);
//	}
//	return 0;
//}
//void bubble_sort(int arr[],int size)
//{
//	int i;
//	//ȷ��ð�����������
//	for (i = 0; i < size; i++)
//	{
//		int j;
//		//ȷ��ÿһ��ð������
//		for (j = 0; j < size - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp;
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//
//}
//
//
//int main()
//{	
//	int i;
//	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr,size);
//	//printf()
//	for (i = 0; i < size; i++)
//	{
//		printf("arr[%d]=%d",i, arr[i]);
//	}
//	
//}
	
