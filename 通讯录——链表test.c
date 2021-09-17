#include"contact.h"
menu()
{
	printf("*****          通讯录          *****\n");
	printf("*****1.add             2.delete*****\n");
	printf("*****3.search          4.change*****\n");
	printf("*****5.show            6.sort  *****\n");
	printf("*****0.exit                    *****\n");
}
int main()
{
	int input = 0;
	P c = (P)malloc(sizeof(L));
	if (c == NULL)
	{
		return 0;
	}
	c->next = NULL;//建立头节点并且初始化,将文件信息录入
	Load(c);
	do
	{
		menu();
		printf("请输入->\n");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add(c);
			printf("添加成功\n");
			break;
		case DELETE:
			printf("输入要删除的联系人->\n");
			char peo[20] = "\0";
			scanf("%s", peo);
			Delete(c,peo);
			break;
		case SEARCH:
			printf("输入要查找的联系人->\n");
			peo[20] = "\0";
			scanf("%s", peo);
			Search(c, peo);
			break;
		case CHANGE:
			printf("输入要查找的联系人->\n");
			peo[20] = "\0";
			scanf("%s", peo);
			Change(c, peo);
			break;
		case SHOW:
			show(c);
			break;
		case SORT:
			Sort(c);
			break;
		case EXIT:
			Save(c);
			printf("退出程序\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
			
	} while (input);
}
