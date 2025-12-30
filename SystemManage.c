#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"StructDefine.h"
#include"Functions.h" 


//1.学科设置 

//导入学科数据
Subject* subHead = NULL;
Subject* subTail = NULL;

void ImportSub()
{

	//导入数据 
	FILE* file = fopen("SubjectInfo.txt","r");
	if (file == NULL) 
	{	
		printf("文件导入失败！！！\n");
		return;
	}
	
	char id[5], name[30];
	
	while(fscanf(file, "%4[^,],%29[^\n]", id, name) == 2)
	{
		Subject* node = CreateNewSub(id, name);
	 
		//插入尾部
		if(subHead == NULL)
		{
			subHead = subTail =node;
		 } 
		else
		{
			subTail->next = node;
			subTail = node;
		}
	}
	fclose(file);
	return;
} 
 
//创建Subject新节点
Subject* CreateNewSub(const char* id, const char* name) 
{
	Subject* node = malloc(sizeof(Subject));
	
	if(node == NULL)
	return node;
	
	//储存数据 
	strcpy(node->Id, id);
	strcpy(node->Name , name);
	
	node->next = NULL;
	
	return node;
}


//保存学科新数据 
void SaveSub()
{
	FILE* file = fopen("SubjectInfo.txt", "w");
	if(file == NULL)
	{
		printf("无法保存数据，请重试！\n");
		return;
	}
	
	Subject* current = subHead;
	while(current != NULL)
	{
		fprintf(file, "%s,%s\n", current->Id, current->Name);
		current = current->next;
	}
	fclose(file);
	printf("数据更新成功(☆▽☆)\n");
	getchar();
	getchar();
	
	return;
 } 

//学科设置菜单 
int SubjectSetting()
{
	ImportSub();
	 
	int choice;
	//选择功能
	do
	{
		system("cls");
		
		printf("            ↓↓↓<1.学科设置>ヾ(≧ ▽ ≦)ゝ\n");
		printf("\n"); 
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇                 1.学科目录                     ◇\n");
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇                 2.增加学科                     ◇\n");
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇                 3.删除学科                     ◇\n");
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇                 4.修改学科                     ◇\n");
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇                 0.返回主菜单                   ◇\n");	
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("\n");	
		printf("◇           （*＾-＾*）请选择对应功能：          ◇\n");
		printf("\n");
		
		scanf(" %d",&choice);
		
		switch(choice)
		{
			case 1:
				ShowSub();
				break;
			case 2:
				AddSub();
				break;
			case 3:
				DeleteSub();
				break;
			case 4:
				ChangeSub();
				break;
			case 0:
				return 0; 
			default:
				printf("抱歉无该功能o(TヘTo)请重新选择！！！\n"); 
		}
	    }while(1);	
	return 0;
}    
 
//1.1学科目录
void ShowSub()
{ 
	system("cls");
	
	if(subHead == NULL)
	{
		printf("显示失败！\n");
		return;
	}
	
	Subject* current = subHead;
	while( current != NULL)
	{
		printf("%s %s\n", current->Id, current->Name);
		current = current->next;
	}
	
	printf("按回车键返回（*＾-＾*）\n");
	getchar();
	getchar();
	
	return;
}

//1.2增加学科
void AddSub()
{	
	//输入信息 
	char id[5], name[30];
	printf("请输入新增学科id\n");
	scanf("%4s", id);
	printf("请输入新增学科名称\n");
	scanf("%29s", name);
	
	//创建新节点 
	Subject* newSub = CreateNewSub(id, name); 
	
	//插入链表尾部
	if(subHead == NULL)
	{
		subHead = subTail = newSub;
	}
	else
	{
	subTail->next = newSub;
	subTail = newSub; 
	newSub->next = NULL;
	}
	
	SaveSub();
	
	return;
} 

//1.3删除学科
void DeleteSub()
{
	if(subHead == NULL){
		return;
	}
	
	//输入信息 
	char id[5], name[30];
	printf("请输入要删除的学科id:\n");
	scanf("%4s", id);
	printf("请输入要删除的学科名称：\n");
	scanf("%29s", name);
	
	//在链表查找 并删除 
	int flag = 0;
	Subject* temp = NULL;
	
	if(strcmp(subHead->Id, id) == 0 && strcmp(subHead->Name, name) == 0)
	{
		temp = subHead;
		subHead = subHead->next;
		
		if(subHead == NULL)
			subTail = NULL;
			
		flag = 1;
		free(temp);
		SaveSub();
	}
	else
	{
		Subject* current = subHead;
		while(current != NULL && current->next != NULL)
		{
			if(strcmp(current->next->Id, id) == 0 && strcmp(current->next->Name, name) == 0)
			{
				temp = current->next;
				current->next = temp->next;
				
				if(temp == subTail)
					subTail = current;
					
				flag = 1;
				free(temp);
				SaveSub();
				break;
			}
			current = current->next;
		} 
	}
	
	if(flag == 0)
		printf("未找到该学科！！！\n"); 
    
	return; 
} 

//1.4 修改学科
void ChangeSub()
{
	if(subHead == NULL){
		return;
	}
	
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 1.修改学科id                      ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 2.增加学科                     ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇           （*＾-＾*）请选择对应功能：             ◇\n");
	printf("\n");
	
	int choice;
	scanf("%d",&choice);
	
	char id[5], newId[5];
	char name[30], newName[30];
	
	//输入信息 
	if(choice == 1)
	{
		printf("请输入要修改的id：\n");
		scanf("%4s", id);
		printf("请输入新的id：\n");
		scanf("%4s",newId);
	}
	else if(choice == 2)
	{
		printf("请输入要修改的学科名称：\n");
		scanf("%29s", name);
		printf("请输入新的学科名称：\n");
		scanf("%29s",newName);
	}
	
	//在链表查找并修改 
	int flag = 0;
	Subject* current = subHead; 
	while(current != NULL)
	{
		if( choice == 1 && strcmp(current->Id, id) == 0)
		{
			strcpy(current->Id, newId);
			flag = 1;
			break;
		}
		else if( choice == 2 && strcmp(current->Name, name) == 0)
		{
			strcpy(current->Name, newName);
			flag = 1;
			break;
		}
		else
		{
			current = current->next;
		}
	} 
	
	if(flag == 1)
		SaveSub();
	
	return; 
} 
 
  
//2.年级目录 
void ShowGrade()
{
	system("cls");
	
	printf("            ↓↓↓<2.年级目录>ヾ(≧ ▽ ≦)ゝ\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                    大一(2025级)                      ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                    大二(2024级)                      ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                    大三(2023级)                      ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                    大四(2022级)                      ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");	
	printf("◇                    大二(2021级)                      ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                    大三(2023级)                      ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                    大四(2022级)                      ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");	
	return; 
} 


//3.班级设置
 
//导入班级数据

Class* classHead = NULL;
Class* classTail = NULL;

void ImportClass()
{

	//导入数据 
	FILE* file = fopen("ClassInfo.txt","r");
	if (file == NULL) 
	{	
		printf("文件导入失败！！！\n");
		return;
	}
	
	char id[9], name[30];
	
	while(fscanf(file, "%8[^,],%29[^\n]", id, name) == 2)
	{
		Class* node = CreateNewClass(id, name);
	 
		//插入尾部
		if(classHead == NULL)
		{
			classHead = classTail = node;
		 } 
		else
		{
			classTail->next = node;
			classTail = node;
		}
	}
	fclose(file);
	return;
} 
 
//创建Class新节点
Class* CreateNewClass(const char* id, const char* name) 
{
	Class* node = malloc(sizeof(Class));
	
	if(node == NULL)
	return node;
	
	//储存数据 
	strcpy(node->Id,id);
	strcpy(node->Name, name);
	
	node->next = NULL;
	
	return node;
}



//保存班级新数据 
void SaveClass()
{
	FILE* file = fopen("ClassInfo.txt", "w");
	if(file == NULL)
	{
		printf("无法保存数据，请重试！\n");
		return;
	}
	
	Class* current = classHead;
	while(current != NULL)
	{
		fprintf(file, "%s,%s\n", current->Id, current->Name);
		current = current->next;
	}
	fclose(file);
	printf("数据更新成功(☆▽☆)\n");
	
	return;
 } 

int ClassSetting()
{
	ImportClass();

	int choice;
	//选择功能
	do
	{
		system("cls");
		
		printf("            ↓↓↓<3.班级设置>ヾ(≧ ▽ ≦)ゝ\n");
		printf("\n"); 
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇                 1.班级目录                     ◇\n");
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇                 2.增加班级                     ◇\n");
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇                 3.删除班级                     ◇\n");
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇                 4.修改班级                     ◇\n");
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇                 0.返回主菜单                   ◇\n");	
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("\n");	
		printf("◇           （*＾-＾*）请选择对应功能：          ◇\n");
		printf("\n");
		
		scanf(" %d",&choice);
		
		switch(choice)
		{
			case 1:
				ShowClass();
				break;
			case 2:
				AddClass();
				break;
			case 3:
				DeleteClass();
				break;
			case 4:
				ChangeClass();
				break;
			case 0:
				return 0; 
			default:
				printf("抱歉无该功能o(TヘTo)请重新选择！！！\n"); 
		}
	    }while(1);	
	return 0;
}   

//3.1班级目录
void ShowClass()
{
	if(classHead == NULL){
		printf("显示失败！\n");
		return;
	}
	
	Class* current = classHead;
	while( current != NULL)
	{
		printf("%s,%s\n", current->Id, current->Name);
		current = current->next;
	}
	
	printf("按回车键返回（*＾-＾*）\n");
	getchar();
	getchar();
	
	return;
} 
  
//3.2增加班级
void AddClass()
{
	//输入信息 
	char id[9], name[30];
	printf("请输入新增学科id：\n");
	scanf("%8s", id);
	printf("请输入新增学科名称：\n");
	scanf("%29s", name);
	
	//创建新节点 
	Class* newClass = CreateNewClass(id, name); 
	
	//插入链表尾部
	if(classHead == NULL)
	{
		classHead = classTail = newClass;
	}
	else
	{
	classTail->next = newClass; 
	classTail = newClass; 
	}
	
	SaveClass();
	
	return;	
} 

//3.3删除班级
void DeleteClass()
{
	if(classHead == NULL){
		return;
	}
	
	//输入信息 
	char id[9], name[30];
	printf("请输入要删除的班级id:\n");
	scanf("%8s", id);
	printf("请输入要删除的班级名称:\n");
	scanf("%29s", name);
	
	//在链表查找 并删除 
	int flag = 0;
	Class* temp = NULL;
	
	if(strcmp(classHead->Id, id) == 0 && strcmp(classHead->Name, name) == 0)
	{
		temp = classHead;
		classHead = classHead->next;
		
		if(classHead == NULL)
			classTail = NULL;
			
		flag = 1;
		free(temp);
		SaveClass();		
	}
	else
	{
		Class* current = classHead;
		while(current != NULL && current->next != NULL)
		{
			if(strcmp(current->next->Id, id) == 0 && strcmp(current->next->Name, name) == 0)
			{
				temp = current->next;
				current->next = current->next->next;
				
				if(temp == classTail)
					classTail = current;
					
				flag = 1;
				free(temp);
				SaveClass();
				break;
			}
			current = current->next;
		} 
	}
	
	if(flag == 0)
		printf("未找到该班级！！！\n");
	
	return; 
} 

//3.4修改班级
void ChangeClass()
{
	if(classHead == NULL){
		return;
	}
	
	char id[9], newId[9];
	char name[30], newName[30];
	
	int choice;
	
	do
	{
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇                 1.班级id                       ◇\n");
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇                 2.班级名称                     ◇\n");
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇           （*＾-＾*）请选择对应功能：             ◇\n");
		printf("\n");
		
		scanf("%d",&choice);
		//输入信息 
		if(choice == 1)
		{
			printf("请输入要修改的id：\n");
			scanf("%8s", id);
			printf("请输入新的id：\n");
			scanf("%8s",newId);
			break;
		}
		else if(choice == 2)
		{
			printf("请输入要修改的学科名字：\n");
			scanf("%29s", name);
			printf("请输入新的学科名字：\n");
			scanf("%29s",newName);
			break;
		}
		else
		{
			printf("抱歉无该功能o(TヘTo)请重新选择！！！\n");
		 } 
   	}while(1);
   
   
	//在链表查找并修改 
	int flag = 0;
	Class* current = classHead; 
	while(current != NULL)
	{
		if( choice == 1 && strcmp(current->Id, id) == 0)
		{
			strcpy(current->Id, newId);
			flag = 1;
			break;
		}
		else if( choice == 2 && strcmp(current->Name, name) == 0)
		{
			strcpy(current->Name, newName);
			flag = 1;
			break;
		}
		else
		{
			current = current->next;
		}
	} 
	if(flag == 1)
		SaveClass();
	
	return; 
} 


//4.成绩标准设置
void StandardSetting()
{
	system("cls");
	
	printf("            ↓↓↓ <分数标准> (≧▽≦*)o\n");
	printf("\n"); 
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                  优    [90,100]                    ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                  良    [80,90)                     ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                  中    [70,80)                     ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 及格   [60,70)                     ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                不及格  [0,60)                      ◇\n");	
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("\n");		
	
	return;
} 
  


















