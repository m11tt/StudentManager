//1.成绩分析 
#include <stdio.h>
#include <string.h>
#include "StructDefine.h"

int gradeAnalysis(void) {
    if (!scoreHead || !scoreHead->next) {
        printf("??  暂无成绩数据！\n");
        return -1;
    }

    Subject* sub = subjectHead ? subjectHead->next : NULL;
    if (!sub) {
        printf("??  请先设置学科信息！\n");
        return -1;
    }

    while (sub) {
        float total = 0, max = -1, min = 101;
        int count = 0, passCount = 0;

        Score* sc = scoreHead->next;
        while (sc) {
            if (strcmp(sc->SubjectId, sub->Id) == 0) {
                float s = sc->Score;
                total += s;
                if (s > max) max = s;
                if (s < min) min = s;
                if (s >= 60) passCount++;
                count++;
            }
            sc = sc->next;
        }

        if (count == 0) {
            printf("?? 科目《%s》暂无成绩记录。\n", sub->Name);
        } else {
            float avg = total / count;
            float passRate = (float)passCount / count * 100;
            printf("\n?? 科目《%s》成绩统计：\n", sub->Name);
            printf("   平均分：%.2f\n", avg);
            printf("   最高分：%.2f\n", max);
            printf("   最低分：%.2f\n", min);
            printf("   及格率：%.2f%% (%d/%d)\n", passRate, passCount, count);
        }
        sub = sub->next;
    }

    printf("\n? 成绩分析完成。\n");
    system("pause");
    return 0;
}

//2.学生分析
int studentAnalysis(void) {
    if (!studentHead || !studentHead->next) {
        printf("??  暂无学生信息！\n");
        return -1;
    }
    if (!scoreHead || !scoreHead->next) {
        printf("??  暂无成绩数据！\n");
        return -1;
    }

    Student* stu = studentHead->next;
    while (stu) {
        float total = 0;
        int count = 0;
        float max = -1, min = 101;
        int passCount = 0;

        Score* sc = scoreHead->next;
        while (sc) {
            if (strcmp(sc->StudentId, stu->Id) == 0) {
                float s = sc->Score;
                total += s;
                if (s > max) max = s;
                if (s < min) min = s;
                if (s >= 60) passCount++;
                count++;
            }
            sc = sc->next;
        }

        if (count == 0) {
            printf("?? %s（%s）：暂无成绩记录\n", stu->Name, stu->Id);
        } else {
            float avg = total / count;
            float passRate = (float)passCount / count * 100;
            const char* level;
            if (avg >= 90) level = "优秀";
            else if (avg >= 80) level = "良好";
            else if (avg >= 70) level = "中等";
            else if (avg >= 60) level = "及格";
            else level = "待提高";

            printf("\n?? 学生个性化报告：\n");
            printf("   姓名：%s（学号：%s）\n", stu->Name, stu->Id);
            printf("   班级：%s | 专业：%s\n", stu->Class, stu->Major);
            printf("   平均分：%.2f | 综合评价：%s\n", avg, level);
            printf("   最高分：%.2f | 最低分：%.2f\n", max, min);
            printf("   及格率：%.2f%%\n", passRate);
        }
        stu = stu->next;
    }

    printf("\n? 学生分析完成。\n");
    system("pause");
    return 0;
}

//3.班级分析
int classAnalysis(void) {
    if (!studentHead || !studentHead->next) {
        printf("??  暂无学生信息！\n");
        return -1;
    }
    if (!scoreHead || !scoreHead->next) {
        printf("??  暂无成绩数据！\n");
        return -1;
    }

    char classes[100][15] = {0};
    int classCount = 0;

    Student* stu = studentHead->next;
    while (stu) {
        int found = 0;
        for (int i = 0; i < classCount; i++) {
            if (strcmp(classes[i], stu->Class) == 0) {
                found = 1;
                break;
            }
        }
        if (!found && strlen(stu->Class) > 0) {
            strcpy(classes[classCount++], stu->Class);
        }
        stu = stu->next;
    }

    if (classCount == 0) {
        printf("??  未发现有效班级信息。\n");
        return -1;
    }

    printf("\n?? 班级成绩对比分析：\n");
    printf("班级\t\t平均分\t及格率\t总人数\n");
    printf("----------------------------------------\n");

    typedef struct {
        char name[15];
        float avg;
        float passRate;
        int totalStu;
    } ClassStat;
    ClassStat stats[100];
    int statIdx = 0;

    for (int i = 0; i < classCount; i++) {
        float totalScore = 0;
        int totalRecords = 0, passRecords = 0, stuInClass = 0;

        stu = studentHead->next;
        while (stu) {
            if (strcmp(stu->Class, classes[i]) == 0) {
                stuInClass++;
                Score* sc = scoreHead->next;
                while (sc) {
                    if (strcmp(sc->StudentId, stu->Id) == 0) {
                        totalScore += sc->Score;
                        totalRecords++;
                        if (sc->Score >= 60) passRecords++;
                    }
                    sc = sc->next;
                }
            }
            stu = stu->next;
        }

        if (totalRecords == 0) continue;

        float avg = totalScore / totalRecords;
        float passRate = (float)passRecords / totalRecords * 100;

        strcpy(stats[statIdx].name, classes[i]);
        stats[statIdx].avg = avg;
        stats[statIdx].passRate = passRate;
        stats[statIdx].totalStu = stuInClass;
        statIdx++;
    }

    // 按平均分排序
    for (int i = 0; i < statIdx - 1; i++) {
        for (int j = i + 1; j < statIdx; j++) {
            if (stats[i].avg < stats[j].avg) {
                ClassStat tmp = stats[i];
                stats[i] = stats[j];
                stats[j] = tmp;
            }
        }
    }

    for (int i = 0; i < statIdx; i++) {
        printf("%-12s\t%.2f\t%.1f%%\t%d\n",
               stats[i].name, stats[i].avg, stats[i].passRate, stats[i].totalStu);
    }

    printf("\n? 班级分析完成（按平均分排名）。\n");
    system("pause");
    return 0;
}

//4.学期学年汇总
int senmesterSum(void) {
    if (!scoreHead || !scoreHead->next) {
        printf("??  暂无成绩数据！\n");
        return -1;
    }

    char semesters[50][20] = {0};
    int semCount = 0;

    Score* sc = scoreHead->next;
    while (sc) {
        char sem[20] = {0};
        char* p = strchr(sc->SubjectId, '_');
        if (p) {
            strcpy(sem, p + 1);
        } else {
            strcpy(sem, "ALL");
        }

        int found = 0;
        for (int i = 0; i < semCount; i++) {
            if (strcmp(semesters[i], sem) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(semesters[semCount++], sem);
        }
        sc = sc->next;
    }

    printf("\n?? 学期/学年成绩汇总：\n");
    for (int i = 0; i < semCount; i++) {
        float total = 0;
        int count = 0, pass = 0;
        sc = scoreHead->next;
        while (sc) {
            char sem[20] = {0};
            char* p = strchr(sc->SubjectId, '_');
            if (p) strcpy(sem, p + 1);
            else strcpy(sem, "ALL");

            if (strcmp(sem, semesters[i]) == 0) {
                total += sc->Score;
                count++;
                if (sc->Score >= 60) pass++;
            }
            sc = sc->next;
        }

        if (count > 0) {
            float avg = total / count;
            float passRate = (float)pass / count * 100;
            printf("\n学期【%s】：\n", semesters[i]);
            printf("   总记录数：%d\n", count);
            printf("   平均分：%.2f\n", avg);
            printf("   及格率：%.2f%%\n", passRate);
        }
    }

    printf("\n? 学期汇总完成。\n");
    system("pause");
    return 0;
}

