#include<stdio.h> 
#include<conio.h>	//	getch���� 
#include<stdlib.h> 		
#include<string.h> 				
#include<windows.h> 
#define N 50 				// �������,ʵ�������
#define LEN 15 				// ��ź���������ַ���,ʵ�������
#define _CRT_SECURE_NO_WARNINGS 1	
int k,n=0,m=0;    // 	n����ǰ��¼���û�����
void menu();      //	���˵� 
void out();       //	0 	 �˳� 
void insert();    //	1 	 ���� 
void del();	      //	2 	 ɾ�� 
void modify();    //	3 	 �޸� 
void seek();      //	4 	 ���� 
void display();   //	5 	 ��ʾ 
void save();      //	6 	 ���� 
void help();      //	7 	 ���� 
void regist();    // 	ע��
int  judge();     // 	�ж��Ƿ�ע�� 
void dl();        // 	��¼ 
int run();        // 	���� 
void other();     //	���� 		 
char regname[11]="",regpwd[9]="",regpwd2[9]=""; 		//	�������
char onname[11],onpwd[11];
struct computer                         //	�ṹ��
{      
	int order;							//��� 
	char usernum[LEN+1]; 				//���
	char username[LEN+1];   	        //���� 
	char userid[LEN+1];     	        //���֤�� 
	char usertel[LEN+1];    	        //�绰
	char starttime[LEN+1];  	        //����ʱ�� 
	float surplustime;       	        //ʣ��ʹ��ʱ�� 
}com[N];		 

main()                            //	������
{	
	system("mode con cols=155 lines=35");		//����С������С cols�� lines��
	system("color 1F");                         //����С������ɫ 
	run();                                      //����  �����к��� �� 
} 
		
void menu()          //	���˵� 
{
	printf(" \n");
 	printf("\t\t\t\t\t*******************************************************\n");
 	printf("\t\t\t\t\t*                    ���ɹ���ϵͳ                     *\n");
 	printf("\t\t\t\t\t*******************************************************\n");
 	printf("\t\t\t\t\t*--------------------ϵͳ���ܲ˵�---------------------*\n");
 	printf("\t\t\t\t\t*-----------------------------------------------------*\n");
	printf("\t\t\t\t\t*                   1.�����û���Ϣ                    *\n");
	printf("\t\t\t\t\t*                   2.�����ɾ����Ϣ                  *\n");
	printf("\t\t\t\t\t*                   3.�޸��û���Ϣ                    *\n");
 	printf("\t\t\t\t\t*                   4.��ѯ�û���Ϣ                    *\n");
 	printf("\t\t\t\t\t*                   5.��ʾ��ǰ��Ϣ                    *\n");
 	printf("\t\t\t\t\t*                   6.���浱ǰ�û���Ϣ                *\n");
 	printf("\t\t\t\t\t*                   7.ϵͳ����                        *\n");
 	printf("\t\t\t\t\t*                   0.�˳�ϵͳ                        *\n");
	printf("\t\t\t\t\t-------------------------------------------------------\n");
}
void out()                             			  //0   �˳�ϵͳ���� 
{
	printf("\n\n\t\t\t\t\t\t��л����ʹ�ã��ټ���\n");
	exit(0);                       				   // �˳����� 
}
void insert()                                      //   1  �����û���Ϣ���� 
{
 int i=n,j,flag;
 fflush(stdin);                                     //������뻺���� 
 printf("\n\t\t\t\t\t\t\t����������ӵ��û���:");
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
  			printf("\n\t\t\t\t\t\t\t�������%dλ�û��ı��:", i+1);
  			scanf("%s", com[i].usernum);
 			for (j=0;j<i;j++)
 			{
 				if (strcmp(com[i].usernum,com[j].usernum)==0)
 					{
 						printf("\n\t\t\t\t\t\t\t�ñ���Ѵ��ڣ����������룡\n");
 						flag = 1;
 						break;
 					}
 			}
 		}
 		com[i].order=i+1; 
 		fflush(stdin);
 		printf("\n\t\t\t\t\t\t\t�������%d ���û�������:",i+1);
 		scanf("%s",&com[i].username);
 		fflush(stdin);
		printf("\n\t\t\t\t\t\t\t�������%d ���û������֤��:",i+1);
 		scanf("%s", &com[i].userid);
 		fflush(stdin);
 		printf("\n\t\t\t\t\t\t\t�������%d ���û�����ϵ�绰:",i+1);
		scanf("%s", &com[i].usertel);
		fflush(stdin);
		printf("\n\t\t\t\t\t\t\t�������%d ���û��Ŀ���ʱ��:",i+1);
 		scanf("%s", &com[i].starttime);
 		fflush(stdin);
		printf("\n\t\t\t\t\t\t\t�������%d ���û���ʣ��ʹ��ʱ��:", i+1);
 		scanf("%f", &com[i].surplustime); 
 		if (0==flag)
		{
 			i++;
 		}
 	} 
	while (i<n+m);
 }
 n+=m;
 printf("\n\t\t\t\t\t\t\t�û���Ϣ������ϣ�����\n");
 system("pause");
}
void del()										   	// 2  ɾ���û���Ϣ����  
{
 	int i, j, flag = 0;
 	char s1[LEN+1]; 
 	printf("\n\t\t\t\t\t\t\t������Ҫɾ���û��ı��:");
	fflush(stdin);
	scanf("%s",s1);
	for (i=0;i<n;i++)
	{
 		if (strcmp(com[i].usernum,s1)==0)
 		{
 			flag = 1;
  			for(j=i;j<n-1;j++)        				 // Ҫɾ���û�������û���ǰ��һλ
 			{       
 				com[j]=com[j+1];                  // 	ɾ��ĳ�����ݣ�ͨ������������ɾ��Ŀ�ģ� 
 				com[j].order=com[j].order-1;      // 	������� 
			}
 		}
 	}
 	if (0==flag)     //����ʧ��
 	{                      
 		printf("\n\t\t\t\t\t\t\t�ñ�Ų�����!!!");
 	}
 	if (1==flag)//ɾ���ɹ����û�������1
 	{
 		printf("\n\t\t\t\t\t\t\tɾ���ɹ�������");
 		n--;
 	}
 	system("pause");
}
void modify()                   			  		 //  3   �������壺�޸��û���Ϣ         
{
 	int i,num = -1;
 	char item; 
	char  num1[LEN+1],name1[LEN+1],id1[LEN+1],telone[LEN+1],time1[LEN+1];
 	float timetwo;
	printf("\n\t\t\t\t\t\t\t������ҪҪ�޸ĵ��û��ı��:");
 	scanf("%s",num1);
 	for (i=0;i<n;i++)
 	{
 		fflush(stdin);
 		if (strcmp(com[i].usernum,num1) == 0)      //�ַ����Ƚ� 
 		{ 
 			num = i;
 			printf("\n\t\t\t\t\t\t\t------------------\n");
 			printf("\n\t\t\t\t\t\t\t1.�޸�����\n");
 			printf("\n\t\t\t\t\t\t\t2.�޸����֤��\n");
 			printf("\n\t\t\t\t\t\t\t3.�޸���ϵ�绰\n");
 			printf("\n\t\t\t\t\t\t\t4.�޸Ŀ���ʱ��\n");
 			printf("\n\t\t\t\t\t\t\t5.�޸�ʣ��ʹ��ʱ��\n");
 			printf("\n\t\t\t\t\t\t\t0.�����ϼ��˵�\n");
 			printf("\n\t\t\t\t\t\t\t------------------\n");
			while (1)
 			{
 				fflush(stdin);
 				printf("\n\t\t\t\t\t\t\t��ѡ���Ӳ˵����:");
 				char item=getch();
 				switch (item)
 				{
 					case '1':
 						printf("\n\t\t\t\t\t\t\t�������µ�����:");
 						scanf("%s",name1 );
 						strcpy(com[num].username, name1);
 						break;
 					case '2':
 						printf("\n\t\t\t\t\t\t\t�������µ����֤��:");
 						scanf("%s", com[num].userid);
 						break;
 					case '3':
 						printf("\n\t\t\t\t\t\t\t�������µ���ϵ�绰:");
 						scanf("%s",telone);
  						strcpy(com[num].usertel,telone);
 						break;
 					case '4':
 						printf("\n\t\t\t\t\t\t\t�������µĿ���ʱ��:");
 						scanf("%s", time1);
						strcpy(com[num].starttime,time1);
 						break;
 					case '5':
						printf("\n\t\t\t\t\t\t\t�������µ�ʣ��ʹ��ʱ��:");
 						scanf("%f", &timetwo);
						com[num].surplustime = timetwo;
 					    break;
 					case '0': return ; break; 
 					default:printf("\n\t\t\t\t\t\t\t����0-5֮��ѡ��\n");
 				}	
			}
 			printf("�޸���ϣ��뼰ʱ���棡\n");
		 }
 		else
 		{
 			printf("û�и��û����!!!");
 		}
	 }
}
void seek()                                                      //  4  �������壺�����û���Ϣ    
{
 	int i,flag;
 	char s1[21];
 	char item;
	printf("\n\t\t\t\t\t\t\t");
 	system("pause");
 	system("cls");   
 	printf("\n\t\t\t\t\t\t\t----------------------\n");
 	printf("\n\t\t\t\t\t\t\t-----1.����Ų�ѯ-----\n");
 	printf("\n\t\t\t\t\t\t\t-----2.��������ѯ-----\n");
 	printf("\n\t\t\t\t\t\t\t-----3.�˳����˵�-----\n");
 	printf("\n\t\t\t\t\t\t\t----------------------\n");
 	while (1)
 	{  
 		fflush(stdin);
 		printf("\n\t\t\t\t\t\t\t��ѡ���Ӳ˵����:");
 		char item=getch();
 		flag = 0;
 		switch (item)
 		{
 			case '1':
 				printf("\n\t\t\t\t\t\t\t������Ҫ��ѯ���û��ı��:");
 				fflush(stdin);
 				scanf("%s", s1);
 				for (i = 0; i<n; i++)
 				if (strcmp(s1,com[i].usernum)==0)
 				{
 					flag = 1;
 					printf("--------------------------------------------------------------------\n");
 					printf("�û����:%s\t", com[i].usernum);
 					printf("�û����:%d\t", com[i].order);
 					printf("�û�����%s\t", com[i].username);
 					printf("���֤��:%s\t", com[i].userid);
 					printf("��ϵ�绰:%s\t", com[i].usertel);
 					printf("����ʱ��:%s\t", com[i].starttime);
 					printf("ʣ��ʹ��ʱ��:%.1f\t\n", com[i].surplustime);
 				}
 				if (0 == flag)
 				printf("\n\t\t\t\t\t\t\t�ñ�Ų����ڣ�");
				break;
 			case '2':
 				printf("\n\t\t\t\t\t\t\t������Ҫ��ѯ���û�������:");
 				fflush(stdin);
 				scanf("%s", s1);
 				for (i = 0; i<n; i++)
 				if (strcmp(com[i].username, s1)==0)
 				{
 					flag = 1;
 					printf("--------------------------------------------------------------------\n");
 					printf("�û����:%s\t", com[i].usernum);
 					printf("�û�����%s\t", com[i].username);
 					printf("���֤��:%s\t", com[i].userid);
					printf("��ϵ�绰:%s\t", com[i].usertel);
 					printf("����ʱ��:%s\t", com[i].starttime);
 					printf("ʣ��ʹ��ʱ��:%.1f\t\n", com[i].surplustime);
 				}
 				if (0 == flag)
 				printf("\n\t\t\t\t\t\t\t�����������ڣ�\n");
				break;
 			case '3': return; break;
 				default:printf("\n\t\t\t\t\t\t������������1-3֮��ѡ��\n");
 		}
	}
}
void display()                				  												  //   5  �������壺��ʾ���� 
{
 int i;
 printf("\n\t\t\t\t\t\t��ǰ����%dλ�û�����Ϣ:\n", n);
 if (0!= n)
 {
 	printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");
 	for (i=0; i<n; i++)
 	{
 		printf("�û����:%d\t", com[i].order);
 		printf("�û����:%s\t", com[i].usernum);
 		printf("�û�����:%s\t", com[i].username);
 		printf("���֤��:%s\t", com[i].userid);
 		printf("��ϵ�绰:%s\t", com[i].usertel);
 		printf("����ʱ��:%s\t", com[i].starttime);
 		printf("ʣ��ʹ��ʱ��:%.1f\t\n", com[i].surplustime);
 	}
 }
 system("pause");
}
void save()                                														 //   6   �������壺���溯��   
{
 	int i;
 	FILE *fp;
 	char filename[LEN+1];
 	fflush(stdin);
 	printf("������Ҫ������ļ�����\n");
 	scanf("%s", filename);
 	fp = fopen(filename,"w");
 	for(i=0; i < n; i++)
 	{
 		fprintf(fp, "%s%s%d%c%.lf%.lf%.lf\n", com[i].usernum, com[i].username, com[i].userid, com[i].usertel,
 		com[i].starttime, com[i].surplustime);
 	}
 	printf("����ɹ�������\n");
 	fclose(fp);
 	system("pause");
}
void help()                               											  //  7  �������壺 �������� 
{
 	printf("\n\t\t\t\t\t\t\tϵͳʹ�ð���\n");
 	printf("\n\t\t\t\t\t\t1.���ν���ϵͳ��,����ѡ�������û���Ϣ;\n");
 	printf("\n\t\t\t\t\t\t2.���ղ˵���ʾ�������ִ���;\n");
 	printf("\n\t\t\t\t\t\t3.�����û���Ϣ��,�мǱ���;\n");
 	printf("\n\t\t\t\t\t\t4.�û���ſ���Ϊ�����������ַ������;\n");
 	printf("\n\t\t\t\t\t\t5.��л����ʹ�ã�\n");
 	system("pause");
}
void regist()                               												//�������壺�û�ע��  
{
	int reghelp=1;  //ȷ������ѭ������ 
	char c1,c2;
	int ione=0,itwo=0;
	                                                       
	printf("\n");
    system("cls");       																 //����
    printf("\n\n\t\t\t\t\t\t��ӭʹ�����ɹ���ע��ϵͳ\n\n");
    while(1)
    {
     	fflush(stdin);
     	printf("\n\t\t\t\t\t\t�������û���[���ܴ���10���ַ�]��"); 						 // �����û���
     	scanf("%s",regname);			 												 //	�ַ����鲻��&�����־ʹ����ַ 
     	if(strlen(regname)<=10)    														 // �ж��û���
     	{
     		while(1)
     		{
     			fflush(stdin);
     			printf("\n\t\t\t\t\t\t����������[���볤��Ϊ��λ]��");												//��������
     			
     			while(1) 
				{
    				c1= getch(); //�� _getch() �������룬�ַ�������ʾ����Ļ��
    				if (c1== '\r')//�����س������������������
					{ 
        				break; //while ѭ���ĳ���
   					}
   					else if (c1== '\b') //�����˸���Ҫɾ��ǰһ���Ǻ�
					{ 
       					printf("\b \b");  //�˸񣬴�һ���ո����˸�ʵ�������ÿո񸲸ǵ��Ǻ�
        				--ione;
   					 }
  					else
					{
        				regpwd[ione++] = c1;//���ַ���������
        				printf("*");     
    				}
				}									  													
     			if(strlen(regpwd)==8) 												// �ж�����
     			{
     				while(reghelp)
     				{
     					printf("\n\t\t\t\t\t\t���ٴ���������!");
     					printf("\n\t\t\t\t\t\t�뱣���������������һ��:"); 
     					while(1)
     					{
     				  	    c2= getch(); //�� _getch() �������룬�ַ�������ʾ����Ļ��
    						if (c2== '\r')//�����س������������������
							{ 
        						break;     //while ѭ���ĳ���
   							}
   							else if (c2== '\b') //�����˸���Ҫɾ��ǰһ���Ǻ�
							{ 
       							printf("\b \b");  //�˸񣬴�һ���ո����˸�ʵ�������ÿո񸲸ǵ��Ǻ�
        						--itwo;
   					 		}
  							else
							{
        						regpwd2[itwo++] = c2;//���ַ���������
        						printf("*");  
    						}
     					}
			     		if (strcmp(regpwd,regpwd2)==0)
     					{
     						printf("\n\n\t\t\t\t\t\t��ϲ��ע��ɹ���\n\n\t\t\t\t\t\t���μ��˺ź����룡");
     						break;
     					}
						else
						{
							printf("\n\n\t\t\t\t\t\t�Բ�������������������ע�ᣡ��\n\n"); 
						    reghelp=0;	
						}
					}
				    break;
     			}
     			else
     			{
     				printf("\n\t\t\t\t\t\t����ĳ���Ϊ%d������������\n",strlen(regpwd));
     				printf("\n\n\t\t\t\t\t\t�Բ�������������������ע�ᣡ��\n\n"); 
     				break;
     			}
     		}
     	    break;
     	}
     	else
     	{
     		printf("\n\t\t\t\t\t\t�û����ĳ���Ϊ%d������������\n\n",strlen(regname));
     	}
    }
}  
int judge()                                													//	�������壺�ж��Ƿ�ע��
{
     if(strcmp(regname,"")==0&&strcmp(regpwd,"")==0)
     {
     	printf("\n\t\t\t\t\t\t�Բ�������ǰδע�ᣬ����ע�ᣡ\n\n");
     	return 0;
     }
     else
     {
     	return 1;
     }
} 
void dl()                                  //	�������壺�û���¼
{
     int i,ithree=0;
     char c3; 
     system("cls");
     printf("\n\n\t\t\t\t\t\t\t��ӭʹ�����ɹ����¼ϵͳ\n\n");
     for(i=1;i<=3;i++)                        //���ε�¼��֤
     {
     	fflush(stdin);
     	printf("\n\t\t\t\t\t\t\t�������û���:");
     	scanf("%s",onname);
     	fflush(stdin);
     	printf("\n\t\t\t\t\t\t\t��������  ��:");
    		while(1) 
				{
					fflush(stdin);
    				c3= getch(); //�� _getch() �������룬�ַ�������ʾ����Ļ��
    				if (c3== '\r')//�����س������������������
					{ 
        				break; //while ѭ���ĳ���
   					}
   					else if (c3== '\b') //�����˸���Ҫɾ��ǰһ���Ǻ�
					{ 
       					printf("\b \b");  //�˸񣬴�һ���ո����˸�ʵ�������ÿո񸲸ǵ��Ǻ�
        				--ithree;
   					 }
  					else
					{
        				onpwd[ithree++] = c3;//���ַ���������
        				printf("*");     
    				}
				}								
     	if(strcmp(regname,onname)==0&&strcmp(regpwd,onpwd)==0)
     	{
     		printf("\n\n\t\t��¼�ɹ�����ӭʹ�����ɹ���ϵͳ\n\n");
     		k=1;
     		system("cls");
     		break;
     	}
    	 else
     	{
     		k=0;
     		printf("\n\n\t\t�Բ����¼ʧ�ܣ��������µ�¼��ʣ��%d�λ���\n\n",3-i);
     	}
     }  
}
int run()
{
	while(1)
     { 
	 	printf("\n\t\t\t\t\t\t\tϵͳ��׼��������\n");
		printf("\t\t\t\t\t\t\t");
		system("pause");
     	system("cls");
	 	printf("\t\t\t\t\t*******************************************************\n"); //������� 
	 	printf("\t\t\t\t\t*                ��ӭʹ�����ɹ���ϵͳ                 *\n"); 
 	 	printf("\t\t\t\t\t*-----------------------------------------------------*\n");
     	printf("\t\t\t\t\t*                     1.ע��                          *\n");
     	printf("\t\t\t\t\t*                     2.��¼                          *\n");
     	printf("\t\t\t\t\t*                     0.�˳�                          *\n");
    	printf("\t\t\t\t\t*-----------------------------------------------------*\n");
     	printf("\t\t\t\t\t\t\t��ѡ���ܱ�ţ�"); //���빦�ܱ��
     	fflush(stdin);
     	char inputone=getch();     	//�ȴ�һ������    
     	switch(inputone)                        //�ж�
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
					char inputtwo=getch();     	//�ȴ�һ������ 
					switch(inputtwo)
					{
						case '0': out(); break;                                           // �˳�ϵͳ 
						case '1': insert(); break;                                        // ������Ϣ ���������Ϣ�������� 
						case '2': del(); break;                                           // ɾ����Ϣ 
						case '3': modify(); break;                                        // �޸���Ϣ 
						case '4': seek(); break;                                          // ������Ϣ
						case '5': display(); break;                                       // ��ʾ��Ϣ 	
						case '6': save(); break;                                          // ����	
						case '7': help(); break;                                          // ����	
						default: printf("\n\t\t\t\t\t\t�Բ���������Ĺ��ܱ���������������룡\n");                
					}
				}
     		}
     		break;
     		case '0':out();break;
     		default: printf("\n\t\t\t\t\t\t�Բ���������Ĺ��ܱ���������������룡\n");
    	 }
     }  		
 } 
