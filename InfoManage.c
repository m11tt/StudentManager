#include"Functions.h"
#include<stdio.h> 
#include <stdlib.h>
#include<string.h>

//全局变量
Student* studentHead = NULL;
Score* scoreHead = NULL;
History* historyHead = NULL;

// 工具函数声明
Student* findStudent(const char* id);
void addHistory(const char* content);
void saveStudents();
void loadStudents();







//核心函数
int addInfo(void) {
    char id[9], name[30], major[20], grade[10], class[15], gender[10], phone[15];
    int age;

    printf("请输入学生信息：\n");
    printf("学号: ");
    scanf("%8s", id); getchar();

    if (findStudent(id)) {
        printf("错误：该学号已存在！\n");
        return -1;
    }

    printf("姓名: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    printf("专业: ");
    fgets(major, sizeof(major), stdin);
    major[strcspn(major, "\n")] = 0;

    printf("年级: ");
    fgets(grade, sizeof(grade), stdin);
    grade[strcspn(grade, "\n")] = 0;

    printf("班级: ");
    fgets(class, sizeof(class), stdin);
    class[strcspn(class, "\n")] = 0;

    printf("性别: ");
    fgets(gender, sizeof(gender), stdin);
    gender[strcspn(gender, "\n")] = 0;

    printf("年龄: ");
    scanf("%d", &age); getchar();

    printf("电话: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = 0;

    Student* newStu = (Student*)malloc(sizeof(Student));
    if (!newStu) {
        printf("内存分配失败！\n");
        return -1;
    }

    strcpy(newStu->Id, id);
    strcpy(newStu->Name, name);
    strcpy(newStu->Major, major);
    strcpy(newStu->Grade, grade);
    strcpy(newStu->Class, class);
    strcpy(newStu->Gender, gender);
    newStu->Age = age;
    strcpy(newStu->Phone, phone);
    newStu->next = studentHead;
    studentHead = newStu;

    char hist[200];
    sprintf(hist, "添加学生 %s (%s)", id, name);
    addHistory(hist);

    saveStudents();
    printf("添加成功！\n");
    return 0;
}

int checkInfo(void) {
    char id[9];
    printf("请输入学号: ");
    scanf("%8s", id);

    Student* stu = findStudent(id);
    if (!stu) {
        printf("未找到该学生。\n");
        return -1;
    }

    printf("\n=== 学生信息 ===\n");
    printf("学号: %s\n", stu->Id);
    printf("姓名: %s\n", stu->Name);
    printf("专业: %s\n", stu->Major);
    printf("年级: %s\n", stu->Grade);
    printf("班级: %s\n", stu->Class);
    printf("性别: %s\n", stu->Gender);
    printf("年龄: %d\n", stu->Age);
    printf("电话: %s\n", stu->Phone);

    return 0;
}

int changeInfo(void) {
    char id[9];
    printf("请输入要修改的学号: ");
    scanf("%8s", id);

    Student* stu = findStudent(id);
    if (!stu) {
        printf("未找到该学生。\n");
        return -1;
    }

    printf("当前信息:\n");
    printf("姓名: %s\n", stu->Name);
    printf("专业: %s\n", stu->Major);
    printf("年级: %s\n", stu->Grade);
    printf("班级: %s\n", stu->Class);
    printf("性别: %s\n", stu->Gender);
    printf("年龄: %d\n", stu->Age);
    printf("电话: %s\n", stu->Phone);

    char input[100];
    printf("\n请输入新信息（留空表示不变）：\n");

    printf("姓名: ");
    fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        strcpy(stu->Name, input);
        stu->Name[strcspn(stu->Name, "\n")] = 0;
    }

    printf("专业: ");
    fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        strcpy(stu->Major, input);
        stu->Major[strcspn(stu->Major, "\n")] = 0;
    }

    printf("年级: ");
    fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        strcpy(stu->Grade, input);
        stu->Grade[strcspn(stu->Grade, "\n")] = 0;
    }

    printf("班级: ");
    fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        strcpy(stu->Class, input);
        stu->Class[strcspn(stu->Class, "\n")] = 0;
    }

    printf("性别: ");
    fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        strcpy(stu->Gender, input);
        stu->Gender[strcspn(stu->Gender, "\n")] = 0;
    }

    printf("年龄: ");
    fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        sscanf(input, "%d", &stu->Age);
    }

    printf("电话: ");
    fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        strcpy(stu->Phone, input);
        stu->Phone[strcspn(stu->Phone, "\n")] = 0;
    }

    char hist[200];
    sprintf(hist, "修改学生 %s 的信息", id);
    addHistory(hist);

    saveStudents();
    printf("修改成功！\n");
    return 0;
}

int deleteInfo(void) {
    char id[9];
    printf("请输入要删除的学号: ");
    scanf("%8s", id);

    Student* prev = NULL;
    Student* curr = studentHead;

    while (curr != NULL) {
        if (strcmp(curr->Id, id) == 0) {
            if (prev == NULL) {
                studentHead = curr->next;
            }
            else {
                prev->next = curr->next;
            }

            free(curr);
            printf("删除成功！\n");

            addHistory("删除学生信息");
            return 0;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("未找到该学生。\n");
    return -1;
}

int historyInfo(void) {
    History* curr = historyHead;
    if (curr == NULL) {
        printf("暂无历史记录。\n");
        return -1;
    }

    printf("\n=== 历史记录 ===\n");
    while (curr != NULL) {
        printf("%s\n", curr->content);
        curr = curr->next;
    }
    return 0;
}






//工具
Student* findStudent(const char* id) {
    Student* curr = studentHead;
    while (curr != NULL) {
        if (strcmp(curr->Id, id) == 0) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

void addHistory(const char* content) {
    History* newHist = (History*)malloc(sizeof(History));
    if (!newHist) return;

    strcpy(newHist->content, content);
    newHist->next = historyHead;
    historyHead = newHist;
}

void saveStudents() {
    FILE* fp = fopen("students.dat", "w");
    if (!fp) return;

    Student* curr = studentHead;
    while (curr != NULL) {
        fprintf(fp, "%s %s %s %s %s %s %d %s\n",
            curr->Id, curr->Name, curr->Major, curr->Grade,
            curr->Class, curr->Gender, curr->Age, curr->Phone);
        curr = curr->next;
    }
    fclose(fp);
}

void loadStudents() {
    FILE* fp = fopen("students.dat", "r");
    if (!fp) return;

    Student* head = NULL;
    Student* tail = NULL;

    char line[200];
    while (fgets(line, sizeof(line), fp)) {
        Student* newStu = (Student*)malloc(sizeof(Student));
        sscanf(line, "%s %s %s %s %s %s %d %s",
            newStu->Id, newStu->Name, newStu->Major, newStu->Grade,
            newStu->Class, newStu->Gender, &newStu->Age, newStu->Phone);

        newStu->next = NULL;

        if (head == NULL) {
            head = tail = newStu;
        }
        else {
            tail->next = newStu;
            tail = newStu;
        }
    }

    fclose(fp);
    studentHead = head;
}
