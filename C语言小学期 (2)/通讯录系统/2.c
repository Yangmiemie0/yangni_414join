/*ͨѶ¼ϵͳ
Ҫ����ɶ�������ͨѶ��Ϣ�Ĺ��������ݱ��浽�ļ��С�
��Ҫ���ܣ�
����ӣ�����һ���򼸸��˵�ͨ��¼��Ϣ��
��ɾ����ɾ��һ�����ͨ��¼��Ϣ��
�۲�ѯ�������������������ͨ��¼��Ϣ��
���޸ģ���������������޸�ͨ��¼��Ϣ��
����ʾ���������ͨ��¼��Ϣ��*/



#include<stdio.h>/* ��׼������������� */
#include<string.h>/* �ַ��������� */
#include<stdlib.h>/* ��׼������ */
#include <conio.h> /* ��Ļ���������� */


/*������õĺ���*/
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


typedef struct     /*�ṹ�壺��ϵ��*/
{
	char name[20];                 /*����*/
	int sex;//1-Ů  2-��           /*�Ա�*/            
	char tel[20];                  /*�绰*/
	int group;//1-����  2-����  3-ͬѧ  4-������    /*����*/
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
		Menu();//ִ�������ʾ�˵� 
		scanf("%d", &m);
	}
}


void Menu()
{
	printf("\n\t\t\t-------welcome-------\n");
	printf("\t1:���");
	printf("\t2:ɾ��");
	printf("\t3:��ѯ");
	printf("\t4:�޸�");
	printf("\t5:��ʾ");
	printf("\t6:�����¼");
	printf("\t7:��ȡ��¼");
	printf("\t8:ͳ�Ƽ�¼");
	printf("\t0:�˳�\n");
	printf("��ѡ������0-8��");
}


int Add()
{
	int i = 0;
	char result=0;
	while(result!='n' && result!='N')
	{
		printf("\n������people[%d]����Ϣ��\n", i+n);
		printf("name:");
		getchar(); 
		gets(people[i+n].name);
		printf("tel:");
		gets(people[i+n].tel);
		printf("sex(1-Ů,2-��):");
		scanf("%d", &people[i+n].sex);
		printf("group��1-����  2-����  3-ͬѧ  4-��������:");
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
		if (people[i].sex == 2) //�ȽϺ���
			a++;
	}
	b = i - a;
	printf("\t\tͨѶ¼������Ϊ%d����\n\t\t    �����к���%d����\n", i, a);
	printf("\t\t    ����Ů����%d����\n", b);
	return(n);
	system("pause");
}


int Del()
{	
	int j;
	//system("cls");
	printf("\t1:����������\n");
	printf("\t2:���绰����\n");
	printf("��ѡ��1-2��");
	scanf("%d", &j);
	switch(j)
	{
		//����ɾ��
		case 1:
		{
			char name[20];
			printf("������ɾ������ϵ������\n");
			getchar();
			gets(name);
			Delname(name);
			printf("ɾ���ɹ���");
		}break;
		//�ֻ���ɾ��
		case 2:
		{
			char phone[20];
			printf("������ɾ������ϵ���ֻ���\n");
			getchar();
			gets(phone);
			Deltel(phone);
			printf("ɾ���ɹ���");
		}
	}
	return n;
}


int Query()
{
	int i;
	int j;
	//system("cls");
	printf("\t1:����������\n");
	printf("\t2:���绰����\n");
	printf("��ѡ��1-2��");
	scanf("%d", &j);
	switch (j) 
	{
		//������ѯ
		case 1:
		{
			char name[20];
			printf("name��");
			getchar();
			gets(name);
			i = Quename(name);
		}break;
		//�ֻ��Ų�ѯ
		case 2:
		{
			char phone[20];
			printf("tel��");
			getchar();
			gets(phone);
			i = Quetel(phone);
		}break;
	}
	printf("\n");
	printf("people[%d].name��%s\n", i, people[i].name);
	printf("people[%d].tel��%s\n", i, people[i].tel);
	printf("people[%d].sex(1-Ů,2-��)��%d\n", i, people[i].sex);
	printf("people[%d].group��1-����  2-����  3-ͬѧ  4-����������%d\n\n", i, people[i].group);
	return i;
}


void Modify()
{
	int i, j, x;
	//system("cls");
	i = Query();
	printf("i = %d\n", i);
	printf("ȷ���޸�������ϵ����\n��1-�޸ģ�0-�˳��� ��");
	scanf("%d", &x);
	printf("\n");
	if (x == 1)
	{
		printf("\t1:����\n");
		printf("\t2:�Ա�\n");
		printf("\t3:�绰\n");
		printf("\t4:����\n");
		printf("��ѡ��1-4��");
		scanf("%d", &j);
		printf("\n");
		switch (j)
		{
		case 1:
		{
			printf("��������ֵ��");
			getchar();
			gets(people[i].name);
			printf("�޸ĳɹ�\n");
		}break;
		case 2:
		{
			printf("��������ֵ(1-Ů,2-��)��");
			scanf("%d",&people[i].sex);
			printf("�޸ĳɹ�\n");
		}break;
		case 3:
		{
			printf("��������ֵ��");
			getchar();
			gets(people[i].tel);
			printf("�޸ĳɹ�\n");
		}break;
		case 4:
		{
			printf("��������ֵ��1-����  2-����  3-ͬѧ  4-����������");
			scanf("%d", &people[i].group);
			printf("�޸ĳɹ�/n");
		}break;
		}
	}
}


void Show()
{
	int j;
	//system("cls");
	printf("\t%-5s%-15s%-15s%-20s%-8s\n", "num", "name", "tel", "sex(0-�У�1-Ů)", "group(1-����,2-����,3-ͬѧ,4-������)");
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
	printf("���޸���ϵ�ˣ�");
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
	printf("���޸���ϵ�ˣ�");
	return 0;
}


void WritetoText(Contact people[])
{
	int i = 0;
	FILE* fp;
	char filename[20];
	printf("\t���浽�ļ�\n");
	printf("\t��������������ļ���:");
	scanf("%s", filename);
	if((fp = fopen(filename, "w+")) == NULL)
	{
		printf("\t�޷����ļ�\n");
		system("pause");
		return;
	}
	fprintf(fp,"\t%-10s%-15s%-10s%-20s%-8s\n", "num", "name", "tel", "sex(0-�У�1-Ů)", "group(1-����,2-����,3-ͬѧ,4-������)");
		while (i < n)
	{	
		fprintf(fp,"\t  %-15d%-15s%-15s%-20d%-8d\n",i+1, people[i].name, people[i].tel, people[i].sex, people[i].group);
		i++;
	}
	fclose(fp);
	printf("����ɹ�!\n");
}


void Read(Contact people[])
{
	FILE* fp;
	int i;
	char filename[20];
	printf("����Ҫ������ļ���:");
	scanf("%s",filename);
	if((fp = fopen(filename,"r+")) == NULL)
	{
		printf("�Ҳ������ļ�!\n",filename);
		system("pause");
	}
	//n = 0;
	// fseek(fp,0L,SEEK_SET); 
	for (i = 0; i < 10 && !feof(fp); i++)
	{
		fscanf(fp, "\t%-5d%-15s%-15s%-20d%-8d\n", i+1, people[i].name, people[i].tel, &people[i].sex, &people[i].group);
	}
	fclose(fp);
	printf("��ȡ�ɹ����ļ��е�������Ϣ�Ѿ�����!\n" ,filename);
}