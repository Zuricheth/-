#include "contact.h"
void InitContact(struct Contact* ps)
{
	ps->date = (struct peoinfo*)malloc(DEFAULT_SZ * sizeof(struct peoinfo));
	if (ps->date == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->Capacity = DEFAULT_SZ;
}
CheckCapacity(struct Contact* ps)
{
	if (ps->Capacity == ps->size)
	{
		struct peoinfo* ptr=realloc(ps->date, ((ps->Capacity + 2) * sizeof(struct peoinfo)));
		if (ptr != NULL)
		{
			ps->date = ptr;
			ps->Capacity += 2;
			printf("增容成功\n");
		}
		else
		{
			printf("增容失败\n");
		}
	}
}
void  Addcontact(struct Contact* ps)
{
	//检测当前通讯录的容量
	//满了就增容，如果不满啥事不干
	CheckCapacity(ps);
		printf("请输入名字:>");
		scanf("%s", ps->date[ps->size].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->date[ps->size].age));
		printf("请输入性别:>");
		scanf("%s", ps->date[ps->size].sex);
		printf("请输入电话:>");
		scanf("%s", ps->date[ps->size].tele);
		printf("请输入住址:>");
		scanf("%s", ps->date[ps->size].addr);
		ps->size++;
		printf("添加成功\n");
}
void ShowContact(struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空格\n");
	}
	else
	{
		int i = 0;
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n", "名字", "年龄", "性别", "电话", "地址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%20s\t%4d\t%5s\t%12s\t%20s\n",
				ps->date[i].name,
				ps->date[i].age,
				ps->date[i].sex,
				ps->date[i].tele,
				ps->date[i].addr);
		}
	}
}
static int FindByName(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->date[i].name, name))
		{
			return i;
		}
	}
	return -1;
}
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	//1.查找需要删除人的位置
	//找到了返回对应元素对应的下标
	//找不到返回-1
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("要删除的人不存在");
	}
	else
	{
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;
		printf("删除成功");
	}
}
void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		printf("%20s\t%4s\t%5s\t%12s\t%20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%20s\t%4d\t%5s\t%12s\t%20s\n",
			ps->date[pos].name,
			ps->date[pos].age,
			ps->date[pos].sex,
			ps->date[pos].tele,
			ps->date[pos].addr);
	}
}
void ModifyContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改人的名字");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("要修改的人不存在");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", ps->date[pos].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->date[pos].age));
		printf("请输入性别:>");
		scanf("%s", ps->date[pos].sex);
		printf("请输入电话:>");
		scanf("%s", ps->date[pos].tele);
		printf("请输入住址:>");
		scanf("%s", ps->date[pos].addr);
		printf("修改完成\n");
	}
} 
void DestroyContact(struct Contact* ps)
{
	free(ps->date);
	ps->date = NULL;
}
