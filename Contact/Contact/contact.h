#include <stdio.h>
#include <string.h>

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 20

enum  Option
{
	exit, //0
	add,
	del,
	search,
	modify,
	show,
	sort
};

struct PeopleInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

struct contact
{
	struct PeopleInfo data[MAX];
	int size;//��¼��ǰ�Ѿ��е�Ԫ�ظ���
};

//��������
void Initcontact(struct contact * ps);
void Addcontact(struct contact * ps);
//const��Ŀ�������������͹����Ľṹ�������
void Showcontact(const struct contact * ps);
void Delcontact(struct contact * ps);
void SearchContact(const struct contact * ps);
void ModifyContact(const struct contact * ps);
