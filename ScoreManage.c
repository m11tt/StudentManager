#include<stdio.h>
#include"Functions.h"

int addGrade()
{
	printf("Hello!");
	return 0;
}
            
//2.成绩查询
int scoreQuery(void) {
    int choice;
    printf("\n?? 成绩查询\n");
    printf("1. 按学号查询\n");
    printf("2. 按班级查询\n");
    printf("3. 按科目查询\n");
    printf("0. 返回\n");
    printf("请选择: ");
    scanf("%d", &choice);
    getchar(); // 清除换行

    if (choice == 0) return 0;

    char input[50];
    printf("请输入查询条件: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // 去掉换行

    int found = 0;

    switch (choice) {
        case 1: { // 按学号
            Score* sc = scoreHead ? scoreHead->next : NULL;
            while (sc) {
                if (strcmp(sc->StudentId, input) == 0) {
                    if (!found) {
                        // 查找学生姓名
                        Student* stu = studentHead ? studentHead->next : NULL;
                        char name[50] = "未知";
                        while (stu) {
                            if (strcmp(stu->Id, input) == 0) {
                                strcpy(name, stu->Name);
                                break;
                            }
                            stu = stu->next;
                        }
                        printf("\n?? 学生 %s (%s) 的成绩:\n", name, input);
                    }
                    // 查找科目名称
                    Subject* sub = subjectHead ? subjectHead->next : NULL;
                    char subName[50] = "未知";
                    while (sub) {
                        if (strcmp(sub->Id, sc->SubjectId) == 0) {
                            strcpy(subName, sub->Name);
                            break;
                        }
                        sub = sub->next;
                    }
                    printf("   %s: %.2f 分\n", subName, sc->Score);
                    found = 1;
                }
                sc = sc->next;
            }
            break;
        }

        case 2: { // 按班级
            Student* stu = studentHead ? studentHead->next : NULL;
            while (stu) {
                if (strcmp(stu->Class, input) == 0) {
                    printf("\n--- %s (%s) ---\n", stu->Name, stu->Id);
                    Score* sc = scoreHead ? scoreHead->next : NULL;
                    int hasScore = 0;
                    while (sc) {
                        if (strcmp(sc->StudentId, stu->Id) == 0) {
                            Subject* sub = subjectHead ? subjectHead->next : NULL;
                            char subName[50] = "未知";
                            while (sub) {
                                if (strcmp(sub->Id, sc->SubjectId) == 0) {
                                    strcpy(subName, sub->Name);
                                    break;
                                }
                                sub = sub->next;
                            }
                            printf("   %s: %.2f\n", subName, sc->Score);
                            hasScore = 1;
                        }
                        sc = sc->next;
                    }
                    if (!hasScore) printf("   （无成绩记录）\n");
                    found = 1;
                }
                stu = stu->next;
            }
            break;
        }

        case 3: { // 按科目ID或名称
            Subject* sub = subjectHead ? subjectHead->next : NULL;
            char targetId[20] = "";
            // 先尝试匹配ID
            while (sub) {
                if (strcmp(sub->Id, input) == 0 || strcmp(sub->Name, input) == 0) {
                    strcpy(targetId, sub->Id);
                    break;
                }
                sub = sub->next;
            }
            if (targetId[0] == '\0') {
                printf("? 未找到科目 \"%s\"\n", input);
                system("pause");
                return -1;
            }

            Score* sc = scoreHead ? scoreHead->next : NULL;
            while (sc) {
                if (strcmp(sc->SubjectId, targetId) == 0) {
                    Student* stu = studentHead ? studentHead->next : NULL;
                    char name[50] = "未知";
                    while (stu) {
                        if (strcmp(stu->Id, sc->StudentId) == 0) {
                            strcpy(name, stu->Name);
                            break;
                        }
                        stu = stu->next;
                    }
                    printf("%s (%s): %.2f\n", name, sc->StudentId, sc->Score);
                    found = 1;
                }
                sc = sc->next;
            }
            break;
        }

        default:
            printf("? 无效选项！\n");
            system("pause");
            return -1;
    }

    if (!found) {
        printf("? 未找到相关成绩记录。\n");
    } else {
        printf("\n? 查询完成。\n");
    }
    system("pause");
    return 0;
} 

//3.成绩修改
void getCurrentDate(char* buffer) {
    strcpy(buffer, "2025-12-30"); // 你可根据需要替换为真实时间
}

int scoreModify(void) {
    if (!scoreHead || !scoreHead->next) {
        printf("??  暂无成绩数据！\n");
        system("pause");
        return -1;
    }

    char studentId[20], subjectId[20];
    printf("请输入要修改成绩的学生学号: ");
    fgets(studentId, sizeof(studentId), stdin);
    studentId[strcspn(studentId, "\n")] = 0;

    printf("请输入科目ID（如 MATH_S1）: ");
    fgets(subjectId, sizeof(subjectId), stdin);
    subjectId[strcspn(subjectId, "\n")] = 0;

    // 查找成绩节点
    Score* sc = scoreHead->next;
    while (sc) {
        if (strcmp(sc->StudentId, studentId) == 0 &&
            strcmp(sc->SubjectId, subjectId) == 0) {
            break;
        }
        sc = sc->next;
    }

    if (!sc) {
        printf("? 未找到该学生的该科目成绩！\n");
        system("pause");
        return -1;
    }

    // 显示原成绩
    printf("当前成绩: %.2f\n", sc->Score);
    float newScore;
    printf("请输入新成绩: ");
    scanf("%f", &newScore);
    getchar(); // 清除换行

    if (newScore < 0 || newScore > 100) {
        printf("? 成绩应在 0~100 之间！\n");
        system("pause");
        return -1;
    }

    // 记录日志（如果启用了 ModifyLog）
#ifdef ENABLE_LOG
    if (modifyLogHead) {
        ModifyLog* log = (ModifyLog*)malloc(sizeof(ModifyLog));
        strcpy(log->StudentId, studentId);
        strcpy(log->SubjectId, subjectId);
        log->OldScore = sc->Score;
        log->NewScore = newScore;
        getCurrentDate(log->Time);

        // 插入到日志链表头部
        log->next = modifyLogHead->next;
        modifyLogHead->next = log;
    }
#endif

    // 修改成绩
    sc->Score = newScore;
    printf("? 成绩已更新为 %.2f\n", newScore);

    system("pause");
    return 0;
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


