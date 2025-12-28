#include<stdio.h>
#include<stdlib.h> 

#include "StructDefine.h"
#include "Menus.h"
#include "Functions.h"

void AdminMenu()
{
	system("cls");
	
	char choice;
	do
	{ 
	
		printf("--------------------------------------------------\n");
		printf("|<      欢迎使用学生信息成绩管理系统(≧▽≦)       >|\n");
		printf("--------------------------------------------------\n");
		printf("\n"); 	
		printf("            ↓↓↓ <总菜单栏目> (≧▽≦*)o\n");
		printf("\n"); 
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇                 A.信息管理                     ◇\n");
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇                 B.系统设置                     ◇\n");
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇                 E.退出系统                     ◇\n");	
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("\n");	
		printf("◇           (＾▽＾)请选择对应功能：             ◇\n");
		printf("\n");	
		
		scanf(" %c",&choice);
		
		switch(choice){
			case'A':
			case'a':
				InfoManage();
				break;
			case'B':
			case'b':
				SystemSetting();
				break;
			case'E':
			case'e':
				printf("再见！Bye~ o(*￣▽￣*)ブ\n"); 
				break;		
			default:
				printf("抱歉无该功能o(TヘTo)请重新选择！！！\n"); 
				return;
	    	}
	} while(1);
	return ;
}

void TeacherMenu()
{
	system("cls");
	
	char choice;
	do
	{ 
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
		printf("◇                 E.退出系统                     ◇\n");	
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("\n");	
		printf("◇           (＾▽＾)请选择对应功能：             ◇\n");
		printf("\n");	
		
		scanf(" %c",&choice);
		
		switch(choice){
			case'A':
			case'a':
				InfoManage();
				break;
			case'B':
			case'b':
				ScoreManage();
				break;
			case'C':
			case'c':
				StatisticAnalysis();
				break;
			case'D':
			case'd':
				SystemSetting();
				break;
			case'E':
			case'e':
				printf("再见！Bye~ o(*￣▽￣*)ブ\n"); 
				break;		
	    	}
    } while(choice != ' ');
	return ;
}

void StudentMenu()
{
	system("cls");
	
	char choice;
	do
	{ 
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
		printf("◇                 E.退出系统                     ◇\n");	
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("\n");	
		printf("◇           (＾▽＾)请选择对应功能：             ◇\n");
		printf("\n");	
		
		scanf(" %c",&choice);
		
		switch(choice){
			case'A':
			case'a':
				InfoManage();
				break;
			case'B':
			case'b':
				ScoreManage();
				break;
			case'C':
			case'c':
				StatisticAnalysis();
				break;
			case'E':
			case'e':
				printf("再见！Bye~ o(*￣▽￣*)ブ\n"); 
				break;		
	    	}
    } while(choice != ' ');
	return ;
}

	
void InfoManage()      //A.学生信息管理
{
	system("cls");
	
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
	
		scanf(" %d",&choice);
	
		switch(choice)
		{
			case 1:
				addInfo();
				break;
			case 2:
				checkInfo();
				break;
			case 3:
				changeInfo();
				break;
			case 4:
				deleteInfo();
				break;
				case 5:
				historyInfo();
				break;
			case 0:
				return; 
			default:
				printf("抱歉无该功能o(TヘTo)请重新选择！！！\n"); 
		}
	
 	   } while(1);	
	return;	
}

void ScoreManage()      //B.学生成绩管理 
{
	system("cls");
	
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
		printf("◇                 5.历史成绩                     ◇\n");
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇                 0.返回主菜单                   ◇\n");	
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("\n");	
		printf("◇           （*＾-＾*）请选择对应功能：             ◇\n");
		printf("\n");
	
		scanf(" %d",&choice);
		
		switch(choice)
		{
			case 1:
				addGrade();
				break;
			case 2:
				checkGrade();
				break;
			case 3:
				changeGrade();
				break;
			case 4:
				gradeExport();
				break;
			case 5:
				gradeHistory();
				break;
			case 0:
				return;
			default:
				printf("抱歉无该功能o(TヘTo)请重新选择！！！\n"); 
		}
    }while(1);	
	return;	
}

void StatisticAnalysis()      //C.统计分析
{
	system("cls");
	
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
		
		scanf(" %d",&choice);
		
		switch(choice)
		{
			case 1:
				gradeAnalysis();
				break;
			case 2:
				studentAnalysis();
				break;
			case 3:
				classAnalysis();
				break;
			case 4:
				senmesterSum();
				break;
			case 0:
				return; 
			default:
				printf("抱歉无该功能o(TヘTo)请重新选择！！！\n"); 
		}
	    }while(1);		
}

void SystemSetting()      //D.系统设置
{
	system("cls");
	
	int choice;
	do
	{
		printf("            ↓↓↓<D.系统设置>ヾ(≧ ▽ ≦)ゝ\n");
		printf("\n"); 
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇                 1.学科设置                     ◇\n");
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇                 2.年级目录                     ◇\n");
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇                 3.班级设置                     ◇\n");
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇                 4.成绩标准设置                     ◇\n");
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("◇                 0.返回主菜单                   ◇\n");	
		printf("◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n");
		printf("\n");	
		printf("◇           （*＾-＾*）请选择对应功能：             ◇\n");
		printf("\n");
		
		scanf(" %d",&choice);
		
		switch(choice)
		{
			case 1:
				SubjectSetting();
				break;
			case 2:
				ShowGrade();
				break;
			case 3:
				ClassSetting();
				break;
			case 4:
				StandardSetting();
				break;
			case 0:
				return; 
			default:
				printf("抱歉无该功能o(TヘTo)请重新选择！！！\n"); 
		}
	    }while(1);		
}
