#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//A
extern Student* studentHead;
extern Score* scoreHead;
extern History* historyHead;

int addInfo(void);
                     
int checkInfo(void);

int changeInfo(void);
  
int deleteInfo(void);
         
int historyInfo(void);  
       
//B
int addGrade(void);

//成绩查询
int checkGrade(void); 
int scoreQuery(void);

//成绩修改
int changeGrade(void);  
void getCurrentDate(char* buffer);
int scoreModify(void);

int gradeExport(void); 

int gradeHistory(void);

//C     
int gradeAnalysis(void);

int studentAnalysis(void);
        
int classAnalysis(void);
      
int senmesterSum(void); 
     
//D
//学科设置 
int SubjectSetting(void); 
Subject* CreateNewSub(const char* id, const char* name);
void ImportSub(void);
void SaveSub();
void ShowSub(void);
void AddSub(void);
void DeleteSub(void);
void ChangeSub(void);

//年级管理 
void ShowGrade(void);

//班级管理  
int ClassSetting();
Class* CreateNewClass(const char* id, const char* name);
void ImportClass(void);
void SaveClass();
void ShowClass();
void AddClass();
void DeleteClass();
void ChangeClass();


//成绩标准 
void StandardSetting(); 

#endif


