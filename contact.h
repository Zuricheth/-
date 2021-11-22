#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFAULT_SZ 3
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
 struct peoinfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
//通讯录类型
struct Contact
{
	struct peoinfo *date;
	int size;//记录已有信息的元素
	int Capacity;
};
void InitContact(struct Contact* ps);
void Addcontact(struct Contact* ps);
void ShowContact(struct Contact* ps);
void DelContact(struct Contact* ps);
void SearchContact(struct Contact* ps);
void ModifyContact(struct Contact* ps);
void DestroyContact(struct Contact* ps);
