#include<stdio.h> 
#include<conio.h>	//	getch输入 
#include<stdlib.h> 		
#include<string.h> 				
#include<windows.h> 
#define N 50 				// 最大人数,实际请更改
#define LEN 15 				// 编号和姓名最大字符数,实际请更改
#define _CRT_SECURE_NO_WARNINGS 1	
int k,n=0,m=0;    // 	n代表当前记录的用户人数
void menu();      //	主菜单 
void out();       //	0 	 退出 
void insert();    //	1 	 插入 
void del();	      //	2 	 删除 
void modify();    //	3 	 修改 
void seek();      //	4 	 查找 
void display();   //	5 	 显示 
void save();      //	6 	 保存 
void help();      //	7 	 帮助 
void regist();    // 	注册
int  judge();     // 	判断是否注册 
void dl();        // 	登录 
int run();        // 	运行 
void other();     //	附加 		 
char regname[11]="",regpwd[9]="",regpwd2[9]=""; 		//	定义变量
char onname[11],onpwd[11];
struct computer                         //	结构体
{      
	int order;							//序号 
	char usernum[LEN+1]; 				//编号
	char username[LEN+1];   	        //姓名 
	char userid[LEN+1];     	        //身份证号 
	char usertel[LEN+1];    	        //电话
	char starttime[LEN+1];  	        //开机时间 
	float surplustime;       	        //剩余使用时间 
}com[N];		 

main()                            //	主函数
{	
	system("mode con cols=155 lines=35");		//更改小黑屏大小 cols横 lines纵
	system("color 1F");                         //更改小黑屏颜色 
	run();                                      //调用  “运行函数 ” 
} 
		
void menu()          //	主菜单 
{
	printf(" \n");
 	printf("\t\t\t\t\t*******************************************************\n");
 	printf("\t\t\t\t\t*                    网吧管理系统                     *\n");
 	printf("\t\t\t\t\t*******************************************************\n");
 	printf("\t\t\t\t\t*--------------------系统功能菜单---------------------*\n");
 	printf("\t\t\t\t\t*-----------------------------------------------------*\n");
	printf("\t\t\t\t\t*                   1.增加用户信息                    *\n");
	printf("\t\t\t\t\t*                   2.按序号删除信息                  *\n");
	printf("\t\t\t\t\t*                   3.修改用户信息                    *\n");
 	printf("\t\t\t\t\t*                   4.查询用户信息                    *\n");
 	printf("\t\t\t\t\t*                   5.显示当前信息                    *\n");
 	printf("\t\t\t\t\t*                   6.保存当前用户信息                *\n");
 	printf("\t\t\t\t\t*                   7.系统帮助                        *\n");
 	printf("\t\t\t\t\t*                   0.退出系统                        *\n");
	printf("\t\t\t\t\t-------------------------------------------------------\n");
}
void out()                             			  //0   退出系统函数 
{
	printf("\n\n\t\t\t\t\t\t感谢您的使用，再见！\n");
	exit(0);                       				   // 退出函数 
}
void insert()                                      //   1  增加用户信息函数 
{
 int i=n,j,flag;
 fflush(stdin);                                     //清空输入缓冲区 
 printf("\n\t\t\t\t\t\t\t请输入待增加的用户数:");
 scanf("\n%d",&m);
 if (m>0)
 {
 	do
 	{
 		flag = 1;
  		while (flag)
  		{
  			flag = 0;
  			fflush(stdin);
  			printf("\n\t\t\t\t\t\t\t请输入第%d位用户的编号:", i+1);
  			scanf("%s", com[i].usernum);
 			for (j=0;j<i;j++)
 			{
 				if (strcmp(com[i].usernum,com[j].usernum)==0)
 					{
 						printf("\n\t\t\t\t\t\t\t该编号已存在，请重新输入！\n");
 						flag = 1;
 						break;
 					}
 			}
 		}
 		com[i].order=i+1; 
 		fflush(stdin);
 		printf("\n\t\t\t\t\t\t\t请输入第%d 个用户的姓名:",i+1);
 		scanf("%s",&com[i].username);
 		fflush(stdin);
		printf("\n\t\t\t\t\t\t\t请输入第%d 个用户的身份证号:",i+1);
 		scanf("%s", &com[i].userid);
 		fflush(stdin);
 		printf("\n\t\t\t\t\t\t\t请输入第%d 个用户的联系电话:",i+1);
		scanf("%s", &com[i].usertel);
		fflush(stdin);
		printf("\n\t\t\t\t\t\t\t请输入第%d 个用户的开机时间:",i+1);
 		scanf("%s", &com[i].starttime);
 		fflush(stdin);
		printf("\n\t\t\t\t\t\t\t请输入第%d 个用户的剩余使用时间:", i+1);
 		scanf("%f", &com[i].surplustime); 
 		if (0==flag)
		{
 			i++;
 		}
 	} 
	while (i<n+m);
 }
 n+=m;
 printf("\n\t\t\t\t\t\t\t用户信息增加完毕！！！\n");
 system("pause");
}
void del()										   	// 2  删除用户信息函数  
{
 	int i, j, flag = 0;
 	char s1[LEN+1]; 
 	printf("\n\t\t\t\t\t\t\t请输入要删除用户的编号:");
	fflush(stdin);
	scanf("%s",s1);
	for (i=0;i<n;i++)
	{
 		if (strcmp(com[i].usernum,s1)==0)
 		{
 			flag = 1;
  			for(j=i;j<n-1;j++)        				 // 要删除用户后面的用户往前移一位
 			{       
 				com[j]=com[j+1];                  // 	删除某组内容（通过覆盖来做到删除目的） 
 				com[j].order=com[j].order-1;      // 	序号缩进 
			}
 		}
 	}
 	if (0==flag)     //查找失败
 	{                      
 		printf("\n\t\t\t\t\t\t\t该编号不存在!!!");
 	}
 	if (1==flag)//删除成功，用户人数减1
 	{
 		printf("\n\t\t\t\t\t\t\t删除成功！！！");
 		n--;
 	}
 	system("pause");
}
void modify()                   			  		 //  3   函数定义：修改用户信息         
{
 	int i,num = -1;
 	char item; 
	char  num1[LEN+1],name1[LEN+1],id1[LEN+1],telone[LEN+1],time1[LEN+1];
 	float timetwo;
	printf("\n\t\t\t\t\t\t\t请输入要要修改的用户的编号:");
 	scanf("%s",num1);
 	for (i=0;i<n;i++)
 	{
 		fflush(stdin);
 		if (strcmp(com[i].usernum,num1) == 0)      //字符串比较 
 		{ 
 			num = i;
 			printf("\n\t\t\t\t\t\t\t------------------\n");
 			printf("\n\t\t\t\t\t\t\t1.修改姓名\n");
 			printf("\n\t\t\t\t\t\t\t2.修改身份证号\n");
 			printf("\n\t\t\t\t\t\t\t3.修改联系电话\n");
 			printf("\n\t\t\t\t\t\t\t4.修改开机时间\n");
 			printf("\n\t\t\t\t\t\t\t5.修改剩余使用时间\n");
 			printf("\n\t\t\t\t\t\t\t0.返回上级菜单\n");
 			printf("\n\t\t\t\t\t\t\t------------------\n");
			while (1)
 			{
 				fflush(stdin);
 				printf("\n\t\t\t\t\t\t\t请选择子菜单编号:");
 				char item=getch();
 				switch (item)
 				{
 					case '1':
 						printf("\n\t\t\t\t\t\t\t请输入新的姓名:");
 						scanf("%s",name1 );
 						strcpy(com[num].username, name1);
 						break;
 					case '2':
 						printf("\n\t\t\t\t\t\t\t请输入新的身份证号:");
 						scanf("%s", com[num].userid);
 						break;
 					case '3':
 						printf("\n\t\t\t\t\t\t\t请输入新的联系电话:");
 						scanf("%s",telone);
  						strcpy(com[num].usertel,telone);
 						break;
 					case '4':
 						printf("\n\t\t\t\t\t\t\t请输入新的开机时间:");
 						scanf("%s", time1);
						strcpy(com[num].starttime,time1);
 						break;
 					case '5':
						printf("\n\t\t\t\t\t\t\t请输入新的剩余使用时间:");
 						scanf("%f", &timetwo);
						com[num].surplustime = timetwo;
 					    break;
 					case '0': return ; break; 
 					default:printf("\n\t\t\t\t\t\t\t请在0-5之间选择\n");
 				}	
			}
 			printf("修改完毕！请及时保存！\n");
		 }
 		else
 		{
 			printf("没有该用户编号!!!");
 		}
	 }
}
void seek()                                                      //  4  函数定义：查找用户信息    
{
 	int i,flag;
 	char s1[21];
 	char item;
	printf("\n\t\t\t\t\t\t\t");
 	system("pause");
 	system("cls");   
 	printf("\n\t\t\t\t\t\t\t----------------------\n");
 	printf("\n\t\t\t\t\t\t\t-----1.按编号查询-----\n");
 	printf("\n\t\t\t\t\t\t\t-----2.按姓名查询-----\n");
 	printf("\n\t\t\t\t\t\t\t-----3.退出本菜单-----\n");
 	printf("\n\t\t\t\t\t\t\t----------------------\n");
 	while (1)
 	{  
 		fflush(stdin);
 		printf("\n\t\t\t\t\t\t\t请选择子菜单编号:");
 		char item=getch();
 		flag = 0;
 		switch (item)
 		{
 			case '1':
 				printf("\n\t\t\t\t\t\t\t请输入要查询的用户的编号:");
 				fflush(stdin);
 				scanf("%s", s1);
 				for (i = 0; i<n; i++)
 				if (strcmp(s1,com[i].usernum)==0)
 				{
 					flag = 1;
 					printf("--------------------------------------------------------------------\n");
 					printf("用户编号:%s\t", com[i].usernum);
 					printf("用户序号:%d\t", com[i].order);
 					printf("用户姓名%s\t", com[i].username);
 					printf("身份证号:%s\t", com[i].userid);
 					printf("联系电话:%s\t", com[i].usertel);
 					printf("开机时间:%s\t", com[i].starttime);
 					printf("剩余使用时间:%.1f\t\n", com[i].surplustime);
 				}
 				if (0 == flag)
 				printf("\n\t\t\t\t\t\t\t该编号不存在！");
				break;
 			case '2':
 				printf("\n\t\t\t\t\t\t\t请输入要查询的用户的姓名:");
 				fflush(stdin);
 				scanf("%s", s1);
 				for (i = 0; i<n; i++)
 				if (strcmp(com[i].username, s1)==0)
 				{
 					flag = 1;
 					printf("--------------------------------------------------------------------\n");
 					printf("用户编号:%s\t", com[i].usernum);
 					printf("用户姓名%s\t", com[i].username);
 					printf("身份证号:%s\t", com[i].userid);
					printf("联系电话:%s\t", com[i].usertel);
 					printf("开机时间:%s\t", com[i].starttime);
 					printf("剩余使用时间:%.1f\t\n", com[i].surplustime);
 				}
 				if (0 == flag)
 				printf("\n\t\t\t\t\t\t\t该姓名不存在！\n");
				break;
 			case '3': return; break;
 				default:printf("\n\t\t\t\t\t\t输入有误请在1-3之间选择\n");
 		}
	}
}
void display()                				  												  //   5  函数定义：显示函数 
{
 int i;
 printf("\n\t\t\t\t\t\t当前共有%d位用户的信息:\n", n);
 if (0!= n)
 {
 	printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");
 	for (i=0; i<n; i++)
 	{
 		printf("用户序号:%d\t", com[i].order);
 		printf("用户编号:%s\t", com[i].usernum);
 		printf("用户姓名:%s\t", com[i].username);
 		printf("身份证号:%s\t", com[i].userid);
 		printf("联系电话:%s\t", com[i].usertel);
 		printf("开机时间:%s\t", com[i].starttime);
 		printf("剩余使用时间:%.1f\t\n", com[i].surplustime);
 	}
 }
 system("pause");
}
void save()                                														 //   6   函数定义：保存函数   
{
 	int i;
 	FILE *fp;
 	char filename[LEN+1];
 	fflush(stdin);
 	printf("请输入要保存的文件名：\n");
 	scanf("%s", filename);
 	fp = fopen(filename,"w");
 	for(i=0; i < n; i++)
 	{
 		fprintf(fp, "%s%s%d%c%.lf%.lf%.lf\n", com[i].usernum, com[i].username, com[i].userid, com[i].usertel,
 		com[i].starttime, com[i].surplustime);
 	}
 	printf("保存成功！！！\n");
 	fclose(fp);
 	system("pause");
}
void help()                               											  //  7  函数定义： 帮助函数 
{
 	printf("\n\t\t\t\t\t\t\t系统使用帮助\n");
 	printf("\n\t\t\t\t\t\t1.初次进入系统后,请先选择增加用户信息;\n");
 	printf("\n\t\t\t\t\t\t2.按照菜单提示键入数字代号;\n");
 	printf("\n\t\t\t\t\t\t3.增加用户信息后,切记保存;\n");
 	printf("\n\t\t\t\t\t\t4.用户编号可以为任意数字与字符的组合;\n");
 	printf("\n\t\t\t\t\t\t5.感谢您的使用！\n");
 	system("pause");
}
void regist()                               												//函数定义：用户注册  
{
	int reghelp=1;  //确认密码循环变量 
	char c1,c2;
	int ione=0,itwo=0;
	                                                       
	printf("\n");
    system("cls");       																 //清屏
    printf("\n\n\t\t\t\t\t\t欢迎使用网吧管理注册系统\n\n");
    while(1)
    {
     	fflush(stdin);
     	printf("\n\t\t\t\t\t\t请输入用户名[不能大于10个字符]："); 						 // 输入用户名
     	scanf("%s",regname);			 												 //	字符数组不加&，名字就代表地址 
     	if(strlen(regname)<=10)    														 // 判断用户名
     	{
     		while(1)
     		{
     			fflush(stdin);
     			printf("\n\t\t\t\t\t\t请输入密码[密码长度为八位]：");												//输入密码
     			
     			while(1) 
				{
    				c1= getch(); //用 _getch() 函数输入，字符不会显示在屏幕上
    				if (c1== '\r')//遇到回车，表明密码输入结束
					{ 
        				break; //while 循环的出口
   					}
   					else if (c1== '\b') //遇到退格，需要删除前一个星号
					{ 
       					printf("\b \b");  //退格，打一个空格，再退格，实质上是用空格覆盖掉星号
        				--ione;
   					 }
  					else
					{
        				regpwd[ione++] = c1;//将字符放入数组
        				printf("*");     
    				}
				}									  													
     			if(strlen(regpwd)==8) 												// 判断密码
     			{
     				while(reghelp)
     				{
     					printf("\n\t\t\t\t\t\t请再次输入密码!");
     					printf("\n\t\t\t\t\t\t请保持两次输入的密码一致:"); 
     					while(1)
     					{
     				  	    c2= getch(); //用 _getch() 函数输入，字符不会显示在屏幕上
    						if (c2== '\r')//遇到回车，表明密码输入结束
							{ 
        						break;     //while 循环的出口
   							}
   							else if (c2== '\b') //遇到退格，需要删除前一个星号
							{ 
       							printf("\b \b");  //退格，打一个空格，再退格，实质上是用空格覆盖掉星号
        						--itwo;
   					 		}
  							else
							{
        						regpwd2[itwo++] = c2;//将字符放入数组
        						printf("*");  
    						}
     					}
			     		if (strcmp(regpwd,regpwd2)==0)
     					{
     						printf("\n\n\t\t\t\t\t\t恭喜您注册成功！\n\n\t\t\t\t\t\t请牢记账号和密码！");
     						break;
     					}
						else
						{
							printf("\n\n\t\t\t\t\t\t对不起，您输入有误请重新注册！！\n\n"); 
						    reghelp=0;	
						}
					}
				    break;
     			}
     			else
     			{
     				printf("\n\t\t\t\t\t\t密码的长度为%d，请重新输入\n",strlen(regpwd));
     				printf("\n\n\t\t\t\t\t\t对不起，您输入有误请重新注册！！\n\n"); 
     				break;
     			}
     		}
     	    break;
     	}
     	else
     	{
     		printf("\n\t\t\t\t\t\t用户名的长度为%d，请重新输入\n\n",strlen(regname));
     	}
    }
}  
int judge()                                													//	函数定义：判断是否注册
{
     if(strcmp(regname,"")==0&&strcmp(regpwd,"")==0)
     {
     	printf("\n\t\t\t\t\t\t对不起！您当前未注册，请先注册！\n\n");
     	return 0;
     }
     else
     {
     	return 1;
     }
} 
void dl()                                  //	函数定义：用户登录
{
     int i,ithree=0;
     char c3; 
     system("cls");
     printf("\n\n\t\t\t\t\t\t\t欢迎使用网吧管理登录系统\n\n");
     for(i=1;i<=3;i++)                        //三次登录验证
     {
     	fflush(stdin);
     	printf("\n\t\t\t\t\t\t\t请输入用户名:");
     	scanf("%s",onname);
     	fflush(stdin);
     	printf("\n\t\t\t\t\t\t\t请输入密  码:");
    		while(1) 
				{
					fflush(stdin);
    				c3= getch(); //用 _getch() 函数输入，字符不会显示在屏幕上
    				if (c3== '\r')//遇到回车，表明密码输入结束
					{ 
        				break; //while 循环的出口
   					}
   					else if (c3== '\b') //遇到退格，需要删除前一个星号
					{ 
       					printf("\b \b");  //退格，打一个空格，再退格，实质上是用空格覆盖掉星号
        				--ithree;
   					 }
  					else
					{
        				onpwd[ithree++] = c3;//将字符放入数组
        				printf("*");     
    				}
				}								
     	if(strcmp(regname,onname)==0&&strcmp(regpwd,onpwd)==0)
     	{
     		printf("\n\n\t\t登录成功！欢迎使用网吧管理系统\n\n");
     		k=1;
     		system("cls");
     		break;
     	}
    	 else
     	{
     		k=0;
     		printf("\n\n\t\t对不起登录失败！请您重新登录，剩余%d次机会\n\n",3-i);
     	}
     }  
}
int run()
{
	while(1)
     { 
	 	printf("\n\t\t\t\t\t\t\t系统已准备就绪！\n");
		printf("\t\t\t\t\t\t\t");
		system("pause");
     	system("cls");
	 	printf("\t\t\t\t\t*******************************************************\n"); //输出界面 
	 	printf("\t\t\t\t\t*                欢迎使用网吧管理系统                 *\n"); 
 	 	printf("\t\t\t\t\t*-----------------------------------------------------*\n");
     	printf("\t\t\t\t\t*                     1.注册                          *\n");
     	printf("\t\t\t\t\t*                     2.登录                          *\n");
     	printf("\t\t\t\t\t*                     0.退出                          *\n");
    	printf("\t\t\t\t\t*-----------------------------------------------------*\n");
     	printf("\t\t\t\t\t\t\t请选择功能编号："); //输入功能编号
     	fflush(stdin);
     	char inputone=getch();     	//等待一个输入    
     	switch(inputone)                        //判断
     	{
     		case '1':regist();break;
     		case '2': if(judge()==1)
     		{
     			dl();
 				while(k)
				{
					printf("\t\t\t\t\t\t\t");
					system("pause");	
            		system("cls");
					menu();
					fflush(stdin);
					char inputtwo=getch();     	//等待一个输入 
					switch(inputtwo)
					{
						case '0': out(); break;                                           // 退出系统 
						case '1': insert(); break;                                        // 插入信息 插入电脑信息函数调用 
						case '2': del(); break;                                           // 删除信息 
						case '3': modify(); break;                                        // 修改信息 
						case '4': seek(); break;                                          // 查找信息
						case '5': display(); break;                                       // 显示信息 	
						case '6': save(); break;                                          // 保存	
						case '7': help(); break;                                          // 帮助	
						default: printf("\n\t\t\t\t\t\t对不起！您输入的功能编号有误，请重新输入！\n");                
					}
				}
     		}
     		break;
     		case '0':out();break;
     		default: printf("\n\t\t\t\t\t\t对不起！您输入的功能编号有误，请重新输入！\n");
    	 }
     }  		
 } 
