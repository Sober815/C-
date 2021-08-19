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
	int size;//记录当前已经有的元素个数
};

//声明函数
void Initcontact(struct contact * ps);
void Addcontact(struct contact * ps);
//const的目的用来保护传送过来的结构体的内容
void Showcontact(const struct contact * ps);
void Delcontact(struct contact * ps);
void SearchContact(const struct contact * ps);
void ModifyContact(const struct contact * ps);
