#include<stdio.h>
#include<string.h>

#include"StructDefine.h"
#include"Functions.h"
#include"Menus.h"
#include <stdlib.h>

User* userHead = NULL;
User* userTail = NULL;	

//创建User新节点
User* CreateNewUser( const char* id, const char* password, int type) 
{
	User* node = malloc(sizeof(User));
	
	if(node == NULL)
	return node;
	
	//储存数据 
	strcpy(node->Id, id);
	strcpy(node->PassWord, password);
	node->Type = type; 
	node->next = NULL;
	
	return node;
}

//导入用户数据
void ImportUsers(void)
{
	//导入数据 
	FILE* file = fopen("UserInfo.txt","r");
	if (file == NULL) 
	{	
		printf("文件导入失败！！！\n");
		return;
	}
	
	char id[9], password[9];
	int type;
	
	while(fscanf(file, "%8[^,],%8[^,],%d\n", id, password, &type) == 3)
	{
		User* node = CreateNewUser(id, password,type);
	 
		//插入尾部
		if(userHead == NULL)
		{
			userHead = userTail = node;
		 } 
		else
		{
			userTail->next = node;
			userTail = node;
		}
	}
	fclose(file);
	return;
} 

//登录 
int Login()
{
	ImportUsers();
	
	char id[9], password[9];
	int type;
	
	int num = 3;
	
	printf("--------------------------------------------------\n");	
	printf("|             ↓↓↓ <用户登录> (≧▽≦*)o             |\n");
	printf("--------------------------------------------------\n");
	printf("\n"); 
			 
	while(num > 0)
	{	
		//用户输入 
		printf("用户名：");
		scanf("%8s",id);
		printf("密码：");
		scanf("%8s",password);
	
		//查找对应
		User* current = userHead; 
		while( current != NULL)
		{
			if(strcmp(id, current->Id) == 0 && strcmp(password, current->PassWord) == 0)
			{
				printf("登录成功！！！\n");
				system("cls");
				return current->Type;
			}
			current = current->next;
		}
		
			num--; //！！！ 
			if(num > 0)
			{
				printf("密码错误/(ㄒoㄒ)/~~ 剩余%d次机会！！！\n",num);
			}
			else
			{
				printf("登录失败 ≧﹏ ≦\n");
				system("cls");
			}
	}
}
