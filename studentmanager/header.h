#ifndef HEADERS_H
#define HEADERS_H

#include<stdio.h>

void mainMenu();              //���˵� 

void menuA();                 //A.ѧ����Ϣ���� 
void menuB();                 //B.ѧ���ɼ����� 
void menuC();                 //C.ͳ�Ʒ��� 
void menuD();                 //D.ϵͳ���� 
void menuE();                 //E.֪ͨ���� 

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
