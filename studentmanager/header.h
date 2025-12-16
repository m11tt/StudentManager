#ifndef HEADERS_H
#define HEADERS_H

#include<stdio.h>
#include<stdlib.h>

typedef struct Student
{
    char name[10];            //年龄
    char id[8];               //学号
    char major[20];           //专业
    char gender[6];           //性别
    int age;                  //年龄
    char phone[11];           //电话
    Student* next;            //指向下一个学生的指针
}Student;

typedef struct Score
{
    char studentId[8];               //学号
    char courseName[30];             //课程名称
    float score;                     //成绩
    Score* next;                     //指向下一个学生的指针
}Score;

void vainMenu();              //主菜单 

void menuA();                 //菜单A.学生信息管理
void menuB();                 //菜单B.学生成绩管理
void menuC();                 //菜单C.成绩统计分析
void menuD();                 //菜单D.系统设置
void menuE();                 //菜单E.֪ͨ通知公告

void addInfo();               //¼��ѧ��������Ϣ 
void delectStudent();         //ɾ��ѧ����Ϣ 
void checkInfo();             //��ѯѧ����Ϣ 
void changeInfo();            //�޸�ѧ����Ϣ 
void deleteInfo();            //ɾ��ѧ����Ϣ 
void historyInfo();           //ѧ����Ϣ��ʷ��¼ 

void addGrade();              //¼��ɼ� 
void checkGrade();            //�ɼ���ѯ 
void changeGrade();           //�ɼ��޸� 
void gradeExport();              //�ɼ�����
 
void gradeAnalysis();         //�ɼ����� 
void studentAnalysis();       //ѧ������ 
void classAnalysis();         //�༶���� 
void senmesterSum();          //ѧ�ڡ�ѧ�����
 
void userSetting();           //�û����� 
void subjectSetting();        //ѧ������ 
void grade_classSetting();    //�꼶���༶���� 
void grade_standardSetting(); //�ɼ���׼���� 

void systemNotice();          //ϵͳ֪ͨ 
void groupedNotice();         //����֪ͨ 
#endif


