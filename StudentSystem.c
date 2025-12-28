#include<stdio.h>
#include"StructDefine.h"
#include"Login.h"
#include"Menus.h"
#include"Functions.h"

int main()
{
	int type = Login();
	
	switch (type)
	{
		case 1:
			AdminMenu();
			break;
		case 2:
			TeacherMenu();
			break;
		case 3:
			StudentMenu();
			break;
		default:
			printf("错误类型/(ㄒoㄒ)/~~\n"); 
	}
	return 0;
}


