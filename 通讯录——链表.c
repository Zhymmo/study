#include"contact.h"
P Search_Peo(P c, char* peo)
{
	P q=c->next;//搜索指针指向首元结点
	P pre = c;
	while (q)//搜索到q指向空节点，也说明查无此人
	{
		if (strcmp(&(q->info.name),peo) == 0)
			return pre;
		else
			pre = q;
			q = q->next;
	}
	printf("查无此人\n");
	return NULL;
}
void add(P c)//读取头节点
{
	P c1 = (P)malloc(sizeof(L));
	if (c1 == NULL)
	{
		printf("%d", strerror(errno));
	}
	c1->next = NULL;//建立新的节点，用尾插法插入到链表中
	printf("请输入姓名\n");
	scanf("%s", &(c1->info.name));
	printf("请输入电话\n");
	scanf("%s", &(c1->info.tel));
	printf("请输入性别\n");
	scanf("%s", &(c1->info.sex));
	printf("请输入年龄\n");
	scanf("%d", &(c1->info.age));
	P pre = c;//前驱节点,指向头节点
	P q = c->next;//搜索节点，指向首元结点
	while (q)//循环到q指向空地址
	{
		pre = q;
		q = q->next;//前驱节点和搜索节点向后移，直到q指向空
	}
	pre->next = c1;

}
void show(P c)
{
	c = c->next;
	printf("%-20s\t%-12s\t%5s\t%-4s\n","姓名","电话","性别","年龄");
	while (c)
	{
		printf("%-20s\t%-12s\t%5s\t%-4d\n", c->info.name, c->info.tel, c->info.sex, c->info.age);
		c = c->next;
	}

}
void Delete(P c, char* peo)
{
	//1.搜索要删除人所在节点2.删除并释放空间3.前节点连上后继节点。
	P pre=Search_Peo(c, peo);//函数返回那个人所在节点的前继节点地址
	if (pre == NULL)
		return 0;
	P del = pre->next;
	pre->next = del->next;
	free(del);
	del = NULL;
	printf("删除成功\n");
}
void Search(P c, char* peo)
{
	P show = Search_Peo(c, peo);
	if (show == NULL)
		return;
	show = show->next;
	printf("%-20s\t%-12s\t%5s\t%-4d\n", show->info.name, show->info.tel, show->info.sex, show->info.age);

}
void Change(P c, char* peo)
{
	P ch = Search_Peo(c, peo);
	if (ch == NULL)
		return 0;
	ch = ch->next;
	printf("请输入姓名\n");
	scanf("%s", &(ch->info.name));
	printf("请输入电话\n");
	scanf("%s", &(ch->info.tel));
	printf("请输入性别\n");
	scanf("%s", &(ch->info.sex));
	printf("请输入年龄\n");
	scanf("%d", &(ch->info.age));
	printf("修改成功\n");
}
void Swap(P qpre, P q1, P q2)
{
	q1->next = q2->next;
	q2->next = q1;
	qpre->next = q2;
}
void Sort(P c)
{//1.计算链表c节点个数
	P q1 = c->next;//搜索节点指向首元结点
	int len = 0;
	while (q1)//一直搜索到q指向空
	{
		len++;
		q1 = q1->next;
	}
	if (len <= 1)
		return;

	while (--len)//冒泡循环len-1次
	{
		P qpre = c;
		q1 = c->next;
		P q2 = q1->next;
		for (int i = 0; i < len; i++)
		{
			if (strcmp(q1->info.name, q2->info.name) > 0)
				Swap(qpre,q1, q2);

				qpre = q1;
				q1 = q2;
				q2 = q2->next;

		}
	}
	printf("排序成功\n");
}
void Save(P c)
{
	c = c->next;
	FILE* sa = fopen("contact.tst", "wb");
	if (sa == NULL)
	{
		perror("open contact.tst fault");
		return;
	}

	while (c)
	{
		fwrite(&(c->info), sizeof(Peo), 1, sa);
		c = c->next;
	}
	fclose(sa);
	sa = NULL;
}
void Load(P c)
{
	Peo tmp = { 0 };
	FILE* lo=fopen("contact.tst", "rb");
	if (lo == NULL)
	{
		perror("load fail");
		return;
	}
	while (fread(&tmp, sizeof(Peo), 1, lo))
	{

		P c1 = (P)malloc(sizeof(L));
		if (c1 == NULL)
		{
			printf("%d", strerror(errno));
		}
		c1->next = NULL;//建立新的节点，用尾插法插入到链表中
		c1->info = tmp;
		P pre = c;//前驱节点,指向头节点
		P q = c->next;//搜索节点，指向首元结点
		while (q)//循环到q指向空地址
		{
			pre = q;
			q = q->next;//前驱节点和搜索节点向后移，直到q指向空
		}
		pre->next = c1;
	}
}
