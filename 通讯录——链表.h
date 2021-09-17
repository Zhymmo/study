#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>

enum opr
{
	EXIT,
	ADD,
	DELETE,
	SEARCH,
	CHANGE,
	SHOW,
	SORT
};

typedef struct People//结构体表示联系人
{
	char name[20];
	char tel[12];
	char sex[5] ;
	int age;
}Peo;
typedef struct Lnode //单链表，包括联系人信息和后继节点指针
{
	Peo info;
	struct L* next;
}L,*P;

void add(P c);
void show(P c);
void Sort(P c);
void Save(P c);
void Load(P c);
void Delete(P c, char* peo);
void Search(P c, char* peo);
void Change(P c, char* peo);
