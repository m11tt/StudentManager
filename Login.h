#ifndef LOGIN_H
#define LOGIN_H

#include"StructDefine.h"

User* CreateNewuser( const char* id, const char* password);
void ImportUsers(void);
int Login();

#endif
