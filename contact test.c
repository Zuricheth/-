#include "contact.h"
void menu()
{
	printf("**********************************************\n");
	printf("*******1.add        2.del             ********\n");
	printf("*******3.search     3.modify          ********\n");
	printf("*******5.show       6.sort            ********\n");
	printf("*******0.exit                         ********\n");
	printf("**********************************************\n");
}
int main()
{
	int input = 0;
	//创建通讯录
	int size = 0;
	struct Contact con;//con就是通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			Addcontact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			break;
		case EXIT:
			DestroyContact(&con);
			printf("退出程序");
			break;
		default:
			printf("选择错误，请合法输入");
			break;
		}
	} while (input);
	return 0;
}
