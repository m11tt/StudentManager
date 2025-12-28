#include<stdio.h>
#include"Functions.h"

int addGrade()
{
	printf("Hello!");
	return 0;
}
            
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Student {
    char id[10];       // 学号
    char name[20];     // 姓名
    char className[20];// 班级
    struct Student* next;
} Student;

typedef struct Score {
    char studentId[10];// 学生学号
    char subject[30];  // 学科名称
    float score;       // 成绩
    struct Score* next;
} Score;

typedef struct ModifyRecord {
    char studentId[10];// 学生学号
    char subject[30];  // 学科
    float oldScore;    // 旧成绩
    float newScore;    // 新成绩
    char time[20];     // 修改时间
    struct ModifyRecord* next;
} ModifyRecord;

// 全局链表头指针
Student* stuHead = NULL;
Score* scoreHead = NULL;
ModifyRecord* recordHead = NULL;

//2.成绩查询 
// 按学生查询成绩
void queryByStudent() {
    char id[10];
    printf("请输入学生学号: ");
    scanf("%s", id);

    int found = 0;
    Score* p = scoreHead;
    printf("\n====== %s 成绩查询结果 ======\n", id);
    while (p != NULL) {
        if (strcmp(p->studentId, id) == 0) {
            printf("%s: %.1f\n", p->subject, p->score);
            found = 1;
        }
        p = p->next;
    }
    if (!found) {
        printf("未找到该学生的成绩记录\n");
    }
}

// 按班级查询成绩
void queryByClass() {
    char className[20];
    printf("请输入班级名称: ");
    scanf("%s", className);

    int found = 0;
    Student* stu = stuHead;
    printf("\n====== %s 班级成绩查询结果 ======\n", className);
    while (stu != NULL) {
        if (strcmp(stu->className, className) == 0) {
            printf("\n%s %s 的成绩:\n", stu->id, stu->name);
            Score* p = scoreHead;
            while (p != NULL) {
                if (strcmp(p->studentId, stu->id) == 0) {
                    printf("%s: %.1f\n", p->subject, p->score);
                    found = 1;
                }
                p = p->next;
            }
        }
        stu = stu->next;
    }
    if (!found) {
        printf("未找到该班级的成绩记录\n");
    }
}

// 按学科查询成绩
void queryBySubject() {
    char subject[30];
    printf("请输入学科名称: ");
    scanf("%s", subject);

    int found = 0;
    Score* p = scoreHead;
    printf("\n====== %s 学科成绩查询结果 ======\n", subject);
    while (p != NULL) {
        if (strcmp(p->subject, subject) == 0) {
            // 查找学生姓名
            Student* stu = stuHead;
            while (stu != NULL && strcmp(stu->id, p->studentId) != 0) {
                stu = stu->next;
            }
            if (stu != NULL) {
                printf("%s %s: %.1f\n", stu->id, stu->name, p->score);
                found = 1;
            }
        }
        p = p->next;
    }
    if (!found) {
        printf("未找到该学科的成绩记录\n");
    }
}

// 成绩查询菜单
void queryScoreMenu() {
    int choice;
    while (1) {
        printf("\n====== 成绩查询 ======\n");
        printf("1. 按学生查询\n");
        printf("2. 按班级查询\n");
        printf("3. 按学科查询\n");
        printf("4. 返回上一级\n");
        printf("请选择: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                queryByStudent();
                break;
            case 2:
                queryByClass();
                break;
            case 3:
                queryBySubject();
                break;
            case 4:
                return;
            default:
                printf("无效选择，请重新输入\n");
        }
    }
}

//3.成绩修改 
// 记录修改历史
void recordModify(const char* studentId, const char* subject, float oldScore, float newScore) {
    ModifyRecord* newRecord = (ModifyRecord*)malloc(sizeof(ModifyRecord));
    strcpy(newRecord->studentId, studentId);
    strcpy(newRecord->subject, subject);
    newRecord->oldScore = oldScore;
    newRecord->newScore = newScore;

    // 获取当前时间
    time_t t;
    time(&t);
    strftime(newRecord->time, 20, "%Y-%m-%d %H:%M", localtime(&t));

    // 插入链表头部
    newRecord->next = recordHead;
    recordHead = newRecord;

    // 保存修改历史到文件
    FILE* fp = fopen("ModifyHistory.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%s %s %s %.1f %.1f\n", 
                newRecord->time, studentId, subject, oldScore, newScore);
        fclose(fp);
    }
}

// 修改成绩
void modifyScore() {
    char studentId[10], subject[30];
    float newScore;

    printf("请输入要修改成绩的学生学号: ");
    scanf("%s", studentId);
    printf("请输入要修改的学科: ");
    scanf("%s", subject);

    Score* p = scoreHead;
    while (p != NULL) {
        if (strcmp(p->studentId, studentId) == 0 && strcmp(p->subject, subject) == 0) {
            printf("当前成绩: %.1f\n", p->score);
            printf("请输入新成绩: ");
            scanf("%f", &newScore);

            // 记录修改历史
            recordModify(studentId, subject, p->score, newScore);
            
            // 更新成绩
            p->score = newScore;
            printf("成绩修改成功\n");
            
            // 保存成绩到文件
            FILE* fp = fopen("Score.txt", "w");
            if (fp != NULL) {
                Score* saveP = scoreHead;
                while (saveP != NULL) {
                    fprintf(fp, "%s %s %.1f\n", saveP->studentId, saveP->subject, saveP->score);
                    saveP = saveP->next;
                }
                fclose(fp);
            }
            return;
        }
        p = p->next;
    }
    printf("未找到该学生的该学科成绩记录\n");
}

// 查看修改历史
void viewModifyHistory() {
    if (recordHead == NULL) {
        printf("暂无修改历史记录\n");
        return;
    }

    printf("\n====== 成绩修改历史 ======\n");
    ModifyRecord* p = recordHead;
    while (p != NULL) {
        printf("[%s] %s %s: %.1f -> %.1f\n", 
                p->time, p->studentId, p->subject, p->oldScore, p->newScore);
        p = p->next;
    }
}

int gradeExport()
{
	printf("Hello!");
	return 0;
}

int gradeHistory()
{
	printf("Hello!");
	return 0;	
}  

