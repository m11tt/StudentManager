#include<stdio.h>

#include "headers.h"

void mainMenu()    //主菜单 
{
	char choice ' ';
	do
	{ 
	switch(choice)
	printf("--------------------------------------------------\n");
	printf("|<      欢迎使用学生信息成绩管理系统(≧▽≦)       >|\n");
	printf("--------------------------------------------------\n");
	printf("\n"); 	
	printf("            ↓↓↓ <总菜单栏目> (≧▽≦*)o\n");
	printf("\n"); 
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 A.信息管理                     ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 B.成绩管理                     ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 C.统计分析                     ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 D.系统设置                     ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 E.通知公告                     ◇\n");	
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 F.退出系统                     ◇\n");	
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("\n");	
	printf("◇           (＾▽＾)请选择对应功能：             ◇\n");
	printf("\n");	
	
	scanf("%c",&choice);
	
	switch(choice){
		case'A':
		case'a':
			menuA();
			break;
		case'B':
		case'b':
			menuB();
			break;
		case'C':
		case'c':
			menuC();
			break;
		case'D':
		case'd':
			menuD();
			break;
		case'E':
		case'e':
			menuE();
			break;
		case'F':
		case'f':
			if(choice != ' ';
			{
			printf("再见！Bye~ o(*￣▽￣*)ブ"); 
			}
			break;
			
    	}
    }
    while(choice != 'F' || choice != 'f' );
	return ;
} 
	
void  menuA()      //A.学生信息管理
{
	
	int choice;
	do
	{
	printf("            ↓↓↓<A.信息管理> (≧▽≦*)o\n");
	printf("\n"); 
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 1.信息录入                     ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 2.信息查询                     ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 3.信息修改             ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 4.信息删除                     ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 5.历史记录                     ◇\n");	
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 0.返回主菜单                   ◇\n");	
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("\n");	
	printf("◇           (＾▽＾)请选择对应功能：             ◇\n");
	printf("\n");
	
	scanf("%d",&choice);
	
	switch(choice)
	{
		case'1':
			addInformation();
			break;
		case'2':
			checkInformation();
			break;
		case'3':
			changeInformation();
			break;
		case'4':
			delectInformation();
			break;
		case'5':
			historyInformation();
			break;
		case'0':
			return; 
		default:
			printf("抱歉无该功能o(TヘTo)请重新选择！！！\n"); 
	}
    }while(1);		
}

void  menuB()      //B.学生成绩管理 
{
	int choice;
	do
	{
	printf("            ↓↓↓<B.成绩管理>q(≧▽≦q)\n");
	printf("\n"); 
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 1.成绩录入                     ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 2.成绩查询                     ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 3.成绩修改             ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 4.成绩导出                     ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 0.返回主菜单                   ◇\n");	
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("\n");	
	printf("◇           （*＾-＾*）请选择对应功能：             ◇\n");
	printf("\n");
	
	scanf("%d",&choice);
	
	switch(choice)
	{
		case'1':
			addGrade();
			break;
		case'2':
			checkGrade();
			break;
		case'3':
			changeGrade();
			break;
		case'4':
			delectStudent();
			break;
		case'5':
			gradeHistory();
			break;
		case'0':
			return; 
		default:
			printf("抱歉无该功能o(TヘTo)请重新选择！！！\n"); 
	}
    }while(1);		
}

void  menuC()      //C.统计分析
{
	int choice;
	do
	{
	printf("            ↓↓↓<C.统计分析>ヾ(≧ ▽ ≦)ゝ\n");
	printf("\n"); 
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 1.成绩分析                     ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 2.学生分析                     ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 3.班级分析             ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 4.学期汇总                     ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 0.返回主菜单                   ◇\n");	
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("\n");	
	printf("◇           （*＾-＾*）请选择对应功能：             ◇\n");
	printf("\n");
	
	scanf("%d",&choice);
	
	switch(choice)
	{
		case'1':
			gradeAnalysis();
			break;
		case'2':
			studentAnalysis();
			break;
		case'3':
			classAnalysis();
			break;
		case'4':
			delectStudent();
			break;
		case'5':
			senmesterSum();
			break;
		case'0':
			return; 
		default:
			printf("抱歉无该功能o(TヘTo)请重新选择！！！\n"); 
	}
    }while(1);		
}

void  menuD()      //D.系统设置
{
	int choice;
	do
	{
	printf("            ↓↓↓<D.系统设置>ヾ(≧ ▽ ≦)ゝ\n");
	printf("\n"); 
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 1.用户管理                     ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 2.学科设置                     ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 3.年级、班级设置             ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 4.成绩标准设置                     ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 0.返回主菜单                   ◇\n");	
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("\n");	
	printf("◇           （*＾-＾*）请选择对应功能：             ◇\n");
	printf("\n");
	
	scanf("%d",&choice);
	
	switch(choice)
	{
		case'1':
			userSetting();
			break;
		case'2':
			subjectSetting();
			break;
		case'3':
			grade_classSetting();
			break;
		case'4':
			grade_standardSetting();
			break;
	
		case'0':
			return; 
		default:
			printf("抱歉无该功能o(TヘTo)请重新选择！！！\n"); 
	}
    }while(1);		
}

void  menuE()      //E.通知公告
{
	int choice;
	do
	{
	printf("            ↓↓↓<E.通知公告>ヾ(≧ ▽ ≦)ゝ\n");
	printf("\n"); 
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 1.系统通知                     ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 2.分类通知                     ◇\n");
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("◇                 0.返回主菜单                   ◇\n");	
	printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
	printf("\n");	
	printf("◇           （*＾-＾*）请选择对应功能：             ◇\n");
	printf("\n");
	
	scanf("%d",&choice);
	
	switch(choice)
	{
		case'1':
			System notice();
			break;
		case'2':
			groupedNotice();
			break;
		case'0':
			return; 
		default:
			printf("抱歉无该功能o(TヘTo)请重新选择！！！\n"); 
	}
    }while(1);		
}
