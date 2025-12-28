#ifndef STRUCT_DEFINE_H
#define STRUCT_DEFINE_H

typedef struct User
{
	char Id[9];
	char PassWord[9];
	int Type;
	struct User* next;
}User;

typedef struct Student
{
	char Id[9];
    char Name[30];            //姓名 
    char Major[20];           //专业
    char Grade[10];
    char Class[15];
    char Gender[10];           //性别
    int Age;                  //年龄
    char Phone[15];           //电话
    struct Student* next;            //指向下一个学生的指针
}Student;

typedef struct Subject
{
    char Name[30];         //学科名
    char Id[30];
    struct Subject* next;     //指向下一个学科的指针
}Subject;

typedef struct Score
{
    char StudentId[9];               //学号
    char SubjectId[30];
	float Score; 
    struct Score* next;                     //指向下一个学生的指针
}Score;

typedef struct Class
{
	char Id[9];
	char Name[30];
	struct Class* next;
}Class;


#endif 
