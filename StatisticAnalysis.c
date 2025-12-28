#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 单科成绩结构体（非链表，存储具体分数）
typedef struct {
    char subject[30];  // 学科名称
    float score;       // 单科成绩
} SingleScore;

// 学生成绩链表节点（链表形式，批量存储成绩）
typedef struct StudentScoreNode {
    char Id[10];// 学生学号
    char subject[30];  // 学科名称
    float score;       // 成绩
    struct StudentScoreNode* next;
} ScoreNode;

// 成绩统计结构体
typedef struct {
    float avgScore;      // 平均分
    float maxScore;      // 最高分
    float minScore;      // 最低分
    float passRate;      // 及格率(%)
    int totalStudents;   // 总人数
    int passCount;       // 及格人数
} ScoreStats;

// 学生结构体
typedef struct {
    char id[10];        // 学号
    char name[20];      // 姓名
    char className[20]; // 班级
    SingleScore scores[5];// 单科成绩数组
    int subjectCount;   // 实际科目数
} Student;

//1.成绩分析 
// 计算单科目成绩统计
ScoreStats calculateSubjectStats(SingleScore* scores, int count) {
    ScoreStats stats = {0.0f, 0.0f, 100.0f, 0.0f, 0, 0};
    if (count <= 0) return stats;

    stats.totalStudents = count;
    stats.maxScore = scores[0].score;
    stats.minScore = scores[0].score;

	int i;
    for (i = 0; i < count; i++) {
        stats.avgScore += scores[i].score;
        if (scores[i].score > stats.maxScore) {
            stats.maxScore = scores[i].score;
        }
        if (scores[i].score < stats.minScore) {
            stats.minScore = scores[i].score;
        }
        if (scores[i].score >= 60.0f) {
            stats.passCount++;
        }
    }

    stats.avgScore /= count;
    stats.passRate = (float)stats.passCount / count * 100.0f;
    return stats;
}

// 打印成绩统计报表
void printScoreReport(ScoreStats stats, char* subjectName) {
    printf("\n===== %s 成绩统计报表 =====\n", subjectName);
    printf("总人数：%d人\n", stats.totalStudents);
    printf("平均分：%.2f分\n", stats.avgScore);
    printf("最高分：%.2f分\n", stats.maxScore);
    printf("最低分：%.2f分\n", stats.minScore);
    printf("及格率：%.2f%%\n", stats.passRate);
    printf("==========================\n");
}

// 创建成绩链表节点
ScoreNode* createScoreNode(const char* stuId, const char* subject, float score) {
    ScoreNode* node = (ScoreNode*)malloc(sizeof(ScoreNode));
    if (node == NULL) return NULL;

    strcpy(node->Id, stuId);
    strcpy(node->subject, subject);
    node->score = score; 
    node->next = NULL;

    return node;
}

// 打印成绩链表
void printScoreList(ScoreNode* head) {
    if (head == NULL) {
        printf("暂无成绩记录！\n");
        return;
    }

    printf("\n===== 成绩链表汇总 =====\n");
    ScoreNode* curr = head;
    while (curr != NULL) {
        printf("学号：%s  学科：%s  成绩：%.2f\n",
               curr->Id, curr->subject, curr->score); // 正确引用score
        curr = curr->next;
    }
    printf("==========================\n");
}

int main() {
    // 1. 初始化测试单科成绩数据
    SingleScore mathScores[] = {
        {"数学", 88.5f},
        {"数学", 92.0f},
        {"数学", 65.0f},
        {"数学", 76.5f}
    };
    int scoreCount = sizeof(mathScores) / sizeof(SingleScore);

    // 2. 测试成绩统计
    ScoreStats mathStats = calculateSubjectStats(mathScores, scoreCount);
    printScoreReport(mathStats, "数学");

    // 3. 测试成绩链表
    ScoreNode* scoreHead = createScoreNode("2025001", "语文", 90.0f);
    scoreHead->next = createScoreNode("2025002", "语文", 85.5f);
    printScoreList(scoreHead);

    // 4. 释放链表内存
    ScoreNode* tempNode = NULL;
    while (scoreHead != NULL) {
        tempNode = scoreHead;
        scoreHead = scoreHead->next;
        free(tempNode);
    }

    return 0;
}

//2.学生分析
 #include <string.h>
#include "StructDefine.h"

// 学生成绩等级分布
typedef struct {
    int excellent;  // 优 [90,100]
    int good;       // 良 [80,90)
    int medium;     // 中 [70,80)
    int pass;       // 及格 [60,70)
    int fail;       // 不及格 [0,60)
} GradeDistribution;

// 分析学生成绩分布
GradeDistribution analyzeStudentGrade(Student* student, int subjectCount) {
    GradeDistribution dist = {0};
    int i;
    for (i = 0; i < subjectCount; i++) {
        float score = student->scores[i].score;
        if (score >= 90) dist.excellent++;
        else if (score >= 80) dist.good++;
        else if (score >= 70) dist.medium++;
        else if (score >= 60) dist.pass++;
        else dist.fail++;
    }
    return dist;
}

// 分析学生进步情况（与上一学期对比）
float analyzeProgress(Student* current, Student* previous, int subjectCount) {
    if (previous == NULL) return -1;  // 无历史成绩
    float currentAvg = 0, prevAvg = 0;
    int i;
    for (i = 0; i < subjectCount; i++) {
        currentAvg += current->scores[i].score;
        prevAvg += previous->scores[i].score;
    }
    currentAvg /= subjectCount;
    prevAvg /= subjectCount;
    return currentAvg - prevAvg;  // 进步分数（正数为进步，负数为退步）
}

// 生成学生个性化报告
void generateStudentReport(Student* current, Student* previous, int subjectCount) {
    printf("\n===== 学生个性化报告 =====\n");
    printf("学号：%s  姓名：%s\n", current->id, current->name);
    
    // 成绩分布
    GradeDistribution dist = analyzeStudentGrade(current, subjectCount);
    printf("\n【成绩分布】\n");
    printf("优：%d科  良：%d科  中：%d科  及格：%d科  不及格：%d科\n",
           dist.excellent, dist.good, dist.medium, dist.pass, dist.fail);
    
    // 进步情况
    float progress = analyzeProgress(current, previous, subjectCount);
    if (progress >= 0) {
        printf("\n【进步情况】与上一学期相比，平均分提升%.2f分，继续加油！\n", progress);
    } else if (progress > -1) {
        printf("\n【进步情况】无历史成绩记录\n");
    } else {
        printf("\n【进步情况】与上一学期相比，平均分下降%.2f分，需努力改进！\n", -progress);
    }
    printf("==========================\n");
}

//3.班级分析
 #include <string.h>
#include "StructDefine.h"
#include "InfoManage.c"  // 假设包含班级信息读取函数

// 班级成绩统计结构体
typedef struct {
    char classId[20];    // 班级ID
    char className[50];  // 班级名称
    float avgScore;      // 班级平均分
    float passRate;      // 班级及格率
    int rank;            // 排名
} ClassScoreStats;

// 计算班级成绩统计
ClassScoreStats calculateClassStats(Class* class, int subjectIndex) {
    ClassScoreStats stats;
    strcpy(stats.classId, class->Id);
    strcpy(stats.className, class->Name);
    
    // 计算班级指定科目平均分和及格率
    int studentCount = class->studentCount;
    float totalScore = 0;
    int passCount = 0;
    int i; 
    for (i = 0; i < studentCount; i++) {
        float score = class->students[i].scores[subjectIndex].score;
        totalScore += score;
        if (score >= 60) passCount++;
    }
    stats.avgScore = totalScore / studentCount;
    stats.passRate = (float)passCount / studentCount * 100;
    stats.rank = 0;  // 初始排名为0，后续排序后更新
    return stats;
}

// 对班级按平均分排序（降序）
void sortClassesByAvg(ClassScoreStats* classes, int classCount) {
	int i, j;
    for (i = 0; i < classCount - 1; i++) {
        for (j = 0; j < classCount - i - 1; j++) {
            if (classes[j].avgScore < classes[j+1].avgScore) {
                ClassScoreStats temp = classes[j];
                classes[j] = classes[j+1];
                classes[j+1] = temp;
            }
        }
    }
    // 分配排名
    for (i = 0; i < classCount; i++) {
        classes[i].rank = i + 1;
    }
}

// 打印班级排名及成绩分布图
void printClassAnalysis(ClassScoreStats* classes, int classCount, char* subjectName) {
    printf("\n===== 班级 %s 成绩分析 =====\n", subjectName);
    printf("排名  班级ID    班级名称    平均分  及格率\n");
    int i;
    for (i = 0; i < classCount; i++) {
        printf("%d     %s  %s  %.2f   %.2f%%\n",
               classes[i].rank,
               classes[i].classId,
               classes[i].className,
               classes[i].avgScore,
               classes[i].passRate);
    }
    
    // 简易成绩分布直方图（按平均分区间）
    printf("\n【班级平均分分布直方图】\n");
    printf("[0-60): ");
    for (i = 0; i < classCount; i++) {
        if (classes[i].avgScore < 60) printf("■");
    }
    printf("\n[60-80): ");
    for (i = 0; i < classCount; i++) {
        if (classes[i].avgScore >= 60 && classes[i].avgScore < 80) printf("■");
    }
    printf("\n[80-100]: ");
    for (i = 0; i < classCount; i++) {
        if (classes[i].avgScore >= 80) printf("■");
    }
    printf("\n==========================\n");
}

//4.学期 / 学年成绩汇总分析
#include "StructDefine.h"

// 学期/学年成绩汇总结构体
typedef struct {
    char term[20];       // 学期/学年（如"2023-2024第一学期"）
    float overallAvg;    // 整体平均分
    GradeDistribution gradeDist;  // 整体成绩等级分布
    int totalStudents;   // 总学生数
} TermSummary;

// 汇总学期成绩
TermSummary summarizeTermScores(Score* allScores, int totalScores, char* term) {
    TermSummary summary;
    strcpy(summary.term, term);
    summary.totalStudents = totalScores;
    summary.gradeDist = (GradeDistribution){0};
    summary.overallAvg = 0;

	int i;
    for (i = 0; i < totalScores; i++) {
        float score = allScores[i].Score;
        summary.overallAvg += score;
        // 统计等级分布
        if (score >= 90) summary.gradeDist.excellent++;
        else if (score >= 80) summary.gradeDist.good++;
        else if (score >= 70) summary.gradeDist.medium++;
        else if (score >= 60) summary.gradeDist.pass++;
        else summary.gradeDist.fail++;
    }
    summary.overallAvg /= totalScores;
    return summary;
}

// 打印学期/学年分析报告
void printTermReport(TermSummary summary) {
    printf("\n===== %s 成绩汇总分析 =====\n", summary.term);
    printf("总参与学生数：%d人\n", summary.totalStudents);
    printf("整体平均分：%.2f分\n", summary.overallAvg);
    printf("\n【成绩等级占比】\n");
    printf("优：%.2f%%  良：%.2f%%  中：%.2f%%  及格：%.2f%%  不及格：%.2f%%\n",
           (float)summary.gradeDist.excellent / summary.totalStudents * 100,
           (float)summary.gradeDist.good / summary.totalStudents * 100,
           (float)summary.gradeDist.medium / summary.totalStudents * 100,
           (float)summary.gradeDist.pass / summary.totalStudents * 100,
           (float)summary.gradeDist.fail / summary.totalStudents * 100);
    printf("\n【教学评估建议】\n");
    if (summary.gradeDist.fail > summary.totalStudents * 0.3) {
        printf("→ 不及格率较高（>30%），建议加强基础教学和课后辅导。\n");
    } else if (summary.overallAvg < 70) {
        printf("→ 整体平均分偏低，建议优化教学方法，增加实践环节。\n");
    } else {
        printf("→ 整体成绩良好，建议保持教学质量，关注优秀学生拔高。\n");
    }
    printf("==========================\n");
}
