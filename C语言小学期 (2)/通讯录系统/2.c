/*通讯录系统
要求：完成对若干人通讯信息的管理，且数据保存到文件中。
主要功能：
①添加：增加一个或几个人的通信录信息；
②删除：删除一输入的通信录信息；
③查询：根据输入的姓名查找通信录信息；
④修改：根据输入的姓名修改通信录信息；
⑤显示：输出所有通信录信息；*/



#include<stdio.h>/* 标准输入输出函数库 */
#include<string.h>/* 字符串函数库 */
#include<stdlib.h>/* 标准函数库 */
#include <conio.h> /* 屏幕操作函数库 */


/*所需调用的函数*/
void Menu();
int Add();
int Del();
int Query();
void Modify();
void Show();
void Delname();
void Deltel();
int Quename();
int Quetel();
void WritetoText();
void Read();
int sum();


typedef struct     /*结构体：联系人*/
{
	char name[20];                 /*姓名*/
	int sex;//1-女  2-男           /*性别*/            
	char tel[20];                  /*电话*/
	int group;//1-家人  2-朋友  3-同学  4-黑名单    /*分组*/
}Contact; 
static int n = 0;
Contact people[10];

int main()
{
	int m;
	system("date /T");
	system("time /T");
	Menu();
	scanf("%d", &m);
	printf("\n");
	while(m)
	{
		//system("cls");
		switch (m)
		{
		case 0:exit(0);      break;
		case 1:n = Add(people); 		break;
		case 2:n = Del(people); 	    break;
		case 3:Query(people);		break;
		case 4:Modify(people);	break;
		case 5:Show(people);	    break;
		case 6:WritetoText(people); break;
		case 7:Read(people);      break;
		case 8:sum(people);       break;
		}
		//Show();
		Menu();//执行完后显示菜单 
		scanf("%d", &m);
	}
}


void Menu()
{
	printf("\n\t\t\t-------welcome-------\n");
	printf("\t1:添加");
	printf("\t2:删除");
	printf("\t3:查询");
	printf("\t4:修改");
	printf("\t5:显示");
	printf("\t6:保存记录");
	printf("\t7:读取记录");
	printf("\t8:统计记录");
	printf("\t0:退出\n");
	printf("请选择数字0-8：");
}


int Add()
{
	int i = 0;
	char result=0;
	while(result!='n' && result!='N')
	{
		printf("\n请输入people[%d]的信息：\n", i+n);
		printf("name:");
		getchar(); 
		gets(people[i+n].name);
		printf("tel:");
		gets(people[i+n].tel);
		printf("sex(1-女,2-男):");
		scanf("%d", &people[i+n].sex);
		printf("group（1-家人  2-朋友  3-同学  4-黑名单）:");
		scanf("%d", &people[i+n].group);
		getchar();
		printf("\ncontinue input?(Y/N)");
		scanf("%c",&result);
		i++;
	}
	//system("cls");
	return n + i;
}


int sum()
{
	int a = 0, b = 0, i;
	for (i = 0; i < n; i++)
	{
		if (people[i].sex == 2) //比较函数
			a++;
	}
	b = i - a;
	printf("\t\t通讯录总人数为%d个，\n\t\t    其中男孩有%d个。\n", i, a);
	printf("\t\t    其中女孩有%d个。\n", b);
	return(n);
	system("pause");
}


int Del()
{	
	int j;
	//system("cls");
	printf("\t1:按姓名查找\n");
	printf("\t2:按电话查找\n");
	printf("请选择1-2：");
	scanf("%d", &j);
	switch(j)
	{
		//姓名删除
		case 1:
		{
			char name[20];
			printf("请输入删除的联系人姓名\n");
			getchar();
			gets(name);
			Delname(name);
			printf("删除成功！");
		}break;
		//手机号删除
		case 2:
		{
			char phone[20];
			printf("请输入删除的联系人手机号\n");
			getchar();
			gets(phone);
			Deltel(phone);
			printf("删除成功！");
		}
	}
	return n;
}


int Query()
{
	int i;
	int j;
	//system("cls");
	printf("\t1:按姓名查找\n");
	printf("\t2:按电话查找\n");
	printf("请选择1-2：");
	scanf("%d", &j);
	switch (j) 
	{
		//姓名查询
		case 1:
		{
			char name[20];
			printf("name：");
			getchar();
			gets(name);
			i = Quename(name);
		}break;
		//手机号查询
		case 2:
		{
			char phone[20];
			printf("tel：");
			getchar();
			gets(phone);
			i = Quetel(phone);
		}break;
	}
	printf("\n");
	printf("people[%d].name：%s\n", i, people[i].name);
	printf("people[%d].tel：%s\n", i, people[i].tel);
	printf("people[%d].sex(1-女,2-男)：%d\n", i, people[i].sex);
	printf("people[%d].group（1-家人  2-朋友  3-同学  4-黑名单）：%d\n\n", i, people[i].group);
	return i;
}


void Modify()
{
	int i, j, x;
	//system("cls");
	i = Query();
	printf("i = %d\n", i);
	printf("确定修改以上联系人吗？\n（1-修改，0-退出） ：");
	scanf("%d", &x);
	printf("\n");
	if (x == 1)
	{
		printf("\t1:姓名\n");
		printf("\t2:性别\n");
		printf("\t3:电话\n");
		printf("\t4:分组\n");
		printf("请选择1-4：");
		scanf("%d", &j);
		printf("\n");
		switch (j)
		{
		case 1:
		{
			printf("请输入新值：");
			getchar();
			gets(people[i].name);
			printf("修改成功\n");
		}break;
		case 2:
		{
			printf("请输入新值(1-女,2-男)：");
			scanf("%d",&people[i].sex);
			printf("修改成功\n");
		}break;
		case 3:
		{
			printf("请输入新值：");
			getchar();
			gets(people[i].tel);
			printf("修改成功\n");
		}break;
		case 4:
		{
			printf("请输入新值（1-家人  2-朋友  3-同学  4-黑名单）：");
			scanf("%d", &people[i].group);
			printf("修改成功/n");
		}break;
		}
	}
}


void Show()
{
	int j;
	//system("cls");
	printf("\t%-5s%-15s%-15s%-20s%-8s\n", "num", "name", "tel", "sex(0-男，1-女)", "group(1-家人,2-朋友,3-同学,4-黑名单)");
	for(j=0; j<10; j++)
	{
		printf("\t%-5d%-15s%-15s%-20d%-8d\n", j+1, people[j].name, people[j].tel, people[j].sex, people[j].group);
	}
}


void Delname(char name[20])
{
	int i;
	int j;
	for(i=0;i<10;i++)
	{
		if (strcmp(name, people[i].name) == 0)
		{
			printf("%d",i);
			break;
		}
	}
	for (j=i;j<n+1;j++)
	{
		people[j] = people[j+1];
	
	}
	n = n-1;
	printf("\n");
}


void Deltel(char phone[20])
{
	int i;
	int j;
	for (i=0;i<10;i++)
	{
		if (strcmp(phone, people[i].tel) == 0)
		{
			printf("%d",i);
			break;
		}
	}
	for (j=i;j<n+1; j++)
	{
		people[j] = people[j+1];	
	}
	n = n-1;
	printf("\n");
}


int Quename(char name[20])
{
	int i;
	int j ;
	for (i = 0; i < 10; i++)
	{
		if (strcmp(name, people[i].name) == 0)
		{
			j = i;
			return j;
			break;
		}
			
	}
	printf("暂无该联系人！");
	return 0;
}


int Quetel(char phone[20])
{
	int i;
	int j;
	for (i = 0; i<10; i++)
	{
		if (strcmp(phone, people[i].tel) == 0)
		{
			j = i;
			return j;
			break;
		}
	}
	printf("暂无该联系人！");
	return 0;
}


void WritetoText(Contact people[])
{
	int i = 0;
	FILE* fp;
	char filename[20];
	printf("\t保存到文件\n");
	printf("\t请输入所保存的文件名:");
	scanf("%s", filename);
	if((fp = fopen(filename, "w+")) == NULL)
	{
		printf("\t无法打开文件\n");
		system("pause");
		return;
	}
	fprintf(fp,"\t%-10s%-15s%-10s%-20s%-8s\n", "num", "name", "tel", "sex(0-男，1-女)", "group(1-家人,2-朋友,3-同学,4-黑名单)");
		while (i < n)
	{	
		fprintf(fp,"\t  %-15d%-15s%-15s%-20d%-8d\n",i+1, people[i].name, people[i].tel, people[i].sex, people[i].group);
		i++;
	}
	fclose(fp);
	printf("保存成功!\n");
}


void Read(Contact people[])
{
	FILE* fp;
	int i;
	char filename[20];
	printf("输入要读入的文件名:");
	scanf("%s",filename);
	if((fp = fopen(filename,"r+")) == NULL)
	{
		printf("找不到该文件!\n",filename);
		system("pause");
	}
	//n = 0;
	// fseek(fp,0L,SEEK_SET); 
	for (i = 0; i < 10 && !feof(fp); i++)
	{
		fscanf(fp, "\t%-5d%-15s%-15s%-20d%-8d\n", i+1, people[i].name, people[i].tel, &people[i].sex, &people[i].group);
	}
	fclose(fp);
	printf("读取成功，文件中的所有信息已经读入!\n" ,filename);
}