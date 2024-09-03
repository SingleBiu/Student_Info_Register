#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 6  //Max number of student

struct student_info
{
    char number[11];
    char name[20];
    char id[18];
    float chinese;
    float math;
    float eng;
    float total;
}stu[N];

int menu();

int login();

void Admission_check(struct student_info stu[]);

void Add_info(struct student_info stu[]);

int Search(struct student_info stu[]);
void search_system(struct student_info stu[]);
void search_system_chinese(struct student_info stu[]);
void search_system_math(struct student_info stu[]);
void search_system_eng(struct student_info stu[]);
void search_system_total(struct student_info stu[]);
void search_system_total_range(struct student_info stu[],int temp1);
void search_system_chinese_range(struct student_info stu[],int temp1);
void search_system_math_range(struct student_info stu[],int temp1);
void search_system_eng_range(struct student_info stu[],int temp1);

void del_info(struct student_info stu[]);

void alter_menu(struct student_info stu[]);
void alter_number(struct student_info stu[],int temp);
void alter_name(struct student_info stu[],int temp);
void alter_id(struct student_info stu[],int temp);
void alter_score_chinese(struct student_info stu[],int temp);
void alter_score_math(struct student_info stu[],int temp);
void alter_score_eng(struct student_info stu[],int temp);

void Rank_menu();
void Rank_total(struct student_info stu[]);
void Rank_total_low_to_high(struct student_info stu[]);
void Rank_chinese(struct student_info stu[]);
void Rank_chinese_low_to_high(struct student_info stu[]);
void Rank_math(struct student_info stu[]);
void Rank_math_low_to_high(struct student_info stu[]);
void Rank_eng(struct student_info stu[]);
void Rank_eng_low_to_high(struct student_info stu[]);

int main()
{
    if(login()!=0)
    return 0;
    menu();
    return 0;
}

int menu()
{
    int x;
    printf("---------------------------------------------\n");
    printf("--------1.Admission   check         ---------\n");
    printf("--------2.Add    student information---------\n");
    printf("--------3.Search student information---------\n");
    printf("--------4.Delete student information---------\n");
    printf("--------5.Rank   student information---------\n");
    printf("--------6.Alter  student information---------\n");
    printf("---------------------------------------------\n");
    printf(" Select:");
    scanf("%d",&x);
    system("cls");
    switch(x)
    {
        case 1:Admission_check(stu);system("pause");break;
        case 2:Add_info(stu);system("pause");break;
        case 3:Search(stu);system("pause");break;
        case 4:del_info(stu);system("pause");break;
        case 5:Rank_menu();break;
		case 6:alter_menu(stu);break;
    
		default:printf("System exit\n");system("pause");return 0;break;
    }
    return 0;
}

void Rank_menu()
{
	int x;
	printf("----------------------------------------------\n");
    printf("--------1.Rank Total    (high to low)---------\n");
    printf("--------2.Rank chinese  (high to low)---------\n");
    printf("--------3.Rank math     (high to low)---------\n");
    printf("--------4.Rank english  (high to low)---------\n");
    printf("----------------------------------------------\n");
    printf("--------5.Rank Total    (low to high)---------\n");
    printf("--------6.Rank chinese  (low to high)---------\n");
    printf("--------7.Rank math     (low to high)---------\n");
    printf("--------8.Rank english  (low to high)---------\n");
    printf("----------------------------------------------\n");
	printf("--------0.Back to menu               ---------\n");
    printf("----------------------------------------------\n");
	scanf("%d",&x);
	switch(x)
	{
    	case 1:system("cls");Rank_total(stu);break;
    	case 2:system("cls");Rank_chinese(stu);break;
        case 3:system("cls");Rank_math(stu);break;
        case 4:system("cls");Rank_eng(stu);break;
        case 5:system("cls");Rank_total_low_to_high(stu);break;
        case 6:system("cls");Rank_chinese_low_to_high(stu);break;
        case 7:system("cls");Rank_math_low_to_high(stu);break;
        case 8:system("cls");Rank_eng_low_to_high(stu);break;
    	case 0:system("cls");menu();break;
	}
}

void Rank_chinese(struct student_info stu[])
{
	int i,j,flag,temp;
    FILE *f;
    if((f=fopen("stu.txt","r"))==NULL)
    {
        printf("File can not be open");
    }
    i=1;
    while(!feof(f))
	{
		fscanf(f,"%s %s %s %f %f %f %f",stu[i].number,stu[i].name,stu[i].id,&stu[i].chinese,&stu[i].math,&stu[i].eng,&stu[i].total);
		i++;
	}
    fclose(f);
    temp=i-1;
	for(i=1;i<temp;i++)
    {
        flag=1;
        for(j=0;j<temp-i;j++)
            if(stu[j+1].chinese>stu[j].chinese) //high to low
            {
                flag=0;
                stu[0]=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=stu[0];
            }
            if(flag)
                break;
    }
    for(i=1;i<temp;i++)
		{
		    printf("\nNo.%d",i);
			printf("\nNumber:%s Name:%s ID:%s Chinese:%f Math:%f English:%f Total:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
		}
    if(i==temp)
		{
            printf("\nNo more information\n");
		}
			printf("\nRank compelete\n\n");
            system("pause");
            system("cls");
            Rank_menu();
}

void Rank_chinese_low_to_high(struct student_info stu[])
{
	int i,j,flag,temp;
    FILE *f;
    if((f=fopen("stu.txt","r"))==NULL)
    {
        printf("File can not be open");
    }
    i=1;
    while(!feof(f))
	{
		fscanf(f,"%s %s %s %f %f %f %f",stu[i].number,stu[i].name,stu[i].id,&stu[i].chinese,&stu[i].math,&stu[i].eng,&stu[i].total);
		i++;
	}
    fclose(f);
    temp=i-1;
	for(i=1;i<temp;i++)
    {
        flag=1;
        for(j=0;j<temp-i;j++)
            if(stu[j+1].chinese<stu[j].chinese)
            {
                flag=0;
                stu[0]=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=stu[0];
            }
            if(flag)
                break;
    }
    for(i=1;i<temp;i++)
		{
		    printf("\nNo.%d",i);
			printf("\nNumber:%s Name:%s ID:%s Chinese:%f Math:%f English:%f Total:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
		}
    if(i==temp)
		{
            printf("\nNo more information\n");
		}
			printf("\nRank compelete\n\n");
            system("pause");
            system("cls");
            Rank_menu();
}

void Rank_math(struct student_info stu[])
{
	int i,j,flag,temp;
    FILE *f;
    if((f=fopen("stu.txt","r"))==NULL)
    {
        printf("File can not be open");
    }
    i=1;
    while(!feof(f))
	{
		fscanf(f,"%s %s %s %f %f %f %f",stu[i].number,stu[i].name,stu[i].id,&stu[i].chinese,&stu[i].math,&stu[i].eng,&stu[i].total);
		i++;
	}
    fclose(f);
    temp=i-1;
	for(i=1;i<temp;i++)
    {
        flag=1;
        for(j=0;j<temp-i;j++)
            if(stu[j+1].math>stu[j].math) //high to low
            {
                flag=0;
                stu[0]=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=stu[0];
            }
            if(flag)
                break;
    }
    for(i=1;i<temp;i++)
		{
		    printf("\nNo.%d",i);
			printf("\nNumber:%s Name:%s ID:%s Chinese:%f Math:%f English:%f Total:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
		}
    if(i==temp)
		{
            printf("\nNo more information\n");
		}
			printf("\nRank compelete\n\n");
            system("pause");
            system("cls");
            Rank_menu();
}

void Rank_math_low_to_high(struct student_info stu[])
{
	int i,j,flag,temp;
    FILE *f;
    if((f=fopen("stu.txt","r"))==NULL)
    {
        printf("File can not be open");
    }
    i=1;
    while(!feof(f))
	{
		fscanf(f,"%s %s %s %f %f %f %f",stu[i].number,stu[i].name,stu[i].id,&stu[i].chinese,&stu[i].math,&stu[i].eng,&stu[i].total);
		i++;
	}
    fclose(f);
    temp=i-1;
	for(i=1;i<temp;i++)
    {
        flag=1;
        for(j=0;j<temp-i;j++)
            if(stu[j+1].math<stu[j].math)
            {
                flag=0;
                stu[0]=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=stu[0];
            }
            if(flag)
                break;
    }
    for(i=1;i<temp;i++)
		{
		    printf("\nNo.%d",i);
			printf("\nNumber:%s Name:%s ID:%s Chinese:%f Math:%f English:%f Total:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
		}
    if(i==temp)
		{
            printf("\nNo more information\n");
		}
			printf("\nRank compelete\n\n");
            system("pause");
            system("cls");
            Rank_menu();
}

void Rank_eng(struct student_info stu[])
{
	int i,j,flag,temp;
    FILE *f;
    if((f=fopen("stu.txt","r"))==NULL)
    {
        printf("File can not be open");
    }
    i=1;
    while(!feof(f))
	{
		fscanf(f,"%s %s %s %f %f %f %f",stu[i].number,stu[i].name,stu[i].id,&stu[i].chinese,&stu[i].math,&stu[i].eng,&stu[i].total);
		i++;
	}
    fclose(f);
    temp=i-1;
	for(i=1;i<temp;i++)
    {
        flag=1;
        for(j=0;j<temp-i;j++)
            if(stu[j+1].eng>stu[j].eng) //high to low
            {
                flag=0;
                stu[0]=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=stu[0];
            }
            if(flag)
                break;
    }
    for(i=1;i<temp;i++)
		{
		    printf("\nNo.%d",i);
			printf("\nNumber:%s Name:%s ID:%s Chinese:%f Math:%f English:%f Total:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
		}
    if(i==temp)
		{
            printf("\nNo more information\n");
		}
			printf("\nRank compelete\n\n");
            system("pause");
            system("cls");
            Rank_menu();
}

void Rank_eng_low_to_high(struct student_info stu[])
{
	int i,j,flag,temp;
    FILE *f;
    if((f=fopen("stu.txt","r"))==NULL)
    {
        printf("File can not be open");
    }
    i=1;
    while(!feof(f))
	{
		fscanf(f,"%s %s %s %f %f %f %f",stu[i].number,stu[i].name,stu[i].id,&stu[i].chinese,&stu[i].math,&stu[i].eng,&stu[i].total);
		i++;
	}
    fclose(f);
    temp=i-1;
	for(i=1;i<temp;i++)
    {
        flag=1;
        for(j=0;j<temp-i;j++)
            if(stu[j+1].eng<stu[j].eng) 
            {
                flag=0;
                stu[0]=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=stu[0];
            }
            if(flag)
                break;
    }
    for(i=1;i<temp;i++)
		{
		    printf("\nNo.%d",i);
			printf("\nNumber:%s Name:%s ID:%s Chinese:%f Math:%f English:%f Total:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
		}
    if(i==temp)
		{
            printf("\nNo more information\n");
		}
			printf("\nRank compelete\n\n");
            system("pause");
            system("cls");
            Rank_menu();
}

void Rank_total(struct student_info stu[])
{
    int i,j,flag,temp;
    FILE *f;
    if((f=fopen("stu.txt","r"))==NULL)
    {
        printf("File can not be open");
    }
    i=1;
    while(!feof(f))
	{
		fscanf(f,"%s %s %s %f %f %f %f",stu[i].number,stu[i].name,stu[i].id,&stu[i].chinese,&stu[i].math,&stu[i].eng,&stu[i].total);
		i++;
	}
    fclose(f);
    temp=i-1;
	for(i=1;i<temp;i++)
    {
        flag=1;
        for(j=0;j<temp-i;j++)
            if(stu[j+1].total>stu[j].total)      //high to low
            {
                flag=0;
                stu[0]=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=stu[0];
            }
            if(flag)
                break;
    }
    for(i=1;i<temp;i++)
		{
            printf("\nNo.%d",i);
			printf("\nNumber:%s Name:%s ID:%s Chinese:%f Math:%f English:%f Total:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
		}
    if(i==temp)
		{
            printf("\nNo more information\n");
		}
			printf("\nRank compelete\n\n");
            system("pause");
            system("cls");
            Rank_menu();
}

void Rank_total_low_to_high(struct student_info stu[])
{
    int i,j,flag,temp;
    FILE *f;
    if((f=fopen("stu.txt","r"))==NULL)
    {
        printf("File can not be open");
    }
    i=1;
    while(!feof(f))
	{
		fscanf(f,"%s %s %s %f %f %f %f",stu[i].number,stu[i].name,stu[i].id,&stu[i].chinese,&stu[i].math,&stu[i].eng,&stu[i].total);
		i++;
	}
    fclose(f);
    temp=i-1;
	for(i=1;i<temp;i++)
    {
        flag=1;
        for(j=0;j<temp-i;j++)
            if(stu[j+1].total<stu[j].total)      //high to low
            {
                flag=0;
                stu[0]=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=stu[0];
            }
            if(flag)
                break;
    }
    for(i=1;i<temp;i++)
		{
		    printf("\nNo.%d",i);
			printf("\nNumber:%s Name:%s ID:%s Chinese:%f Math:%f English:%f Total:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
		}
    if(i==temp)
		{
            printf("\nNo more information\n");
		}
			printf("\nRank compelete\n\n");
            system("pause");
            system("cls");
            Rank_menu();
}

int login()
{
	FILE *f;
    int flag=0;
    char admin[20];
    char password[8];
    char textstring[20];
    printf("Please input username(Default:admin):");
    scanf("%s",admin);
    printf("\nPlease input password(Default:123):");
    scanf("%s",password);
    strcat(admin,password);
    while(1)
    {
        if((f=fopen("user.txt","r+"))==NULL)
        {
            printf("Failed to open user.txt\n");
            break;
        }
    fgets(textstring,20,f);
    if(strcmp(textstring,admin)==0)
        {
            printf("Login success\n");
            break;
        }
    else 
        {
            printf("Login fail\n");
            flag=1;
            break;
        }
    fclose(f);
    }
    printf("Login end\n");
    system("pause");
    system("cls");
    return flag;
}

void Admission_check(struct student_info stu[])
{
    int i=0;
    char textstring[20];
    FILE *f1;
    FILE *f;
    printf("Please input the name/id to check\n");
    scanf("%s",textstring);
    if((f1=fopen("accept.txt","r+"))==NULL)
        {
            printf("File can not be opened");
            system("pause");
        }
        while(!feof(f1))
		{
			fscanf(f1,"%s %s",stu[i].name,stu[i].id);
            i++;
        }
		fclose(f1);
		i=0;
		while(1)
		{
			if(strcmp(stu[i].id,textstring)==0||strcmp(stu[i].name,textstring)==0)
		    {
				printf("Accept.txt found: Name:%s\nID:%s\n",stu[i].name,stu[i].id);
                printf("\nAllow coverage\n");
                break;
			}
			if(i==N)  
			{
		    	printf("No information\n");
				system("pause");
				system("cls");
	    		menu();
			}
            i++;
		}
        printf("\nAccept check compelete\n\n");
		if((f=fopen("stu.txt","a"))==NULL)
		{
             printf("stu.txt can not be opened");
             system("pause");
		}
        printf("Please input the number:\n");
        scanf("%s",stu[i].number);
        printf("Please input the chinese math english score:\n");
        scanf("%f%f%f",&stu[i].chinese,&stu[i].math,&stu[i].eng);
        stu[i].total=stu[i].chinese+stu[i].math+stu[i].eng;
		fscanf(f,"%s %s %s %f %f %f %f",stu[i].number,stu[i].name,stu[i].id,&stu[i].chinese,&stu[i].math,&stu[i].eng,&stu[i].total);
		fclose(f);
    system("pause");
	system("cls");
    menu();
}

void Add_info(struct student_info stu[])
{
    
    int i=0;
    FILE *f1;
    if((f1=fopen("stu.txt","a"))==NULL)
    {
        printf("File can not be opened");
        system("pause");
    }
    else
    {        
        while(1)
        {
            printf("Please input the number(exit input:quit)\n");
            scanf("%s",stu[i].number);
            if(strcmp(stu[i].number,"quit")==0)break;
            printf("Please input the name \n");
            scanf("%s",stu[i].name);
            printf("Please input the id \n");
            scanf("%s",stu[i].id);
            printf("Please input the chinese math english score\n");
            scanf("%f%f%f",&stu[i].chinese,&stu[i].math,&stu[i].eng);
            stu[i].total=stu[i].chinese+stu[i].math+stu[i].eng;
            fprintf(f1,"%s %s %s %f %f %f %f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
            i++;
        }
    }
    fclose(f1);
	system("pause");
	system("cls");
    menu();
}

int Search(struct student_info stu[])
{
	FILE *f;
    int x,j=0,temp1;
	printf("----------------------------------------------\n");
    printf("--------1.Search  number/name/id     ---------\n");
    printf("--------2.Search  chinese            ---------\n");
    printf("--------3.Search  math               ---------\n");
    printf("--------4.Search  english            ---------\n");
    printf("--------5.Search  total              ---------\n");
	printf("--------6.Search  chinese (range)    ---------\n");
	printf("--------7.Search  math    (range)    ---------\n");
	printf("--------8.Search  math    (range)    ---------\n");
	printf("--------9.Search  total   (range)    ---------\n");
	printf("--------0.Back to menu               ---------\n");
    printf("--------Press any key to exit system ---------\n");
	printf("----------------------------------------------\n");
    printf("Please choose:");
	scanf("%d",&x);
    while(1)
    {
        if((f=fopen("stu.txt","r"))==NULL)
        {
            printf("stu.txt can not be opened");
            break;
        }
		while(!feof(f))
		{
			fscanf(f,"%s %s %s %f %f %f %f",stu[j].number,stu[j].name,stu[j].id,&stu[j].chinese,&stu[j].math,&stu[j].eng,&stu[j].total);
			j++;
		}
		temp1=j-1;
        switch(x)
		{
		        case 1:search_system(stu);Search(stu);break;
				case 2:search_system_chinese(stu);Search(stu);break;
                case 3:search_system_math(stu);Search(stu);break;
                case 4:search_system_eng(stu);Search(stu);break;
                case 5:search_system_total(stu);Search(stu);break;
				case 6:search_system_chinese_range(stu,temp1);Search(stu);break;
				case 7:search_system_math_range(stu,temp1);Search(stu);break;
				case 8:search_system_eng_range(stu,temp1);Search(stu);break;
				case 9:search_system_total_range(stu,temp1);Search(stu);break;
				case 0:system("cls");menu();break;
				default:return 0;
        }
        fclose(f);
    }
    return 0;
}

void search_system_chinese(struct student_info stu[])
{
	int i=0;
	float score;
	system("cls");
	printf("Please input the chinese score that you want to search:");
    scanf("%f",&score);
	system("cls");
    for(i=0;i<N;i++)
        if(stu[i].chinese==score)
		    {
				printf("\nNumber:%s\nName:%s\nID:%s\nChinese:%f\nMath:%f\nEnglish:%f\nTotal:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
			}
        if(i==N)
			{
                printf("\nNo more information\n");
			}
			printf("\nSearch compelete\n\n");
    system("pause");
	system("cls");
}

void search_system_math(struct student_info stu[])
{
	int i=0;
	float score;
	system("cls");
	printf("Please input the math score that you want to search:");
    scanf("%f",&score);
	system("cls");
    for(i=0;i<N;i++)
        if(stu[i].math==score)
		    {
				printf("\nNumber:%s\nName:%s\nID:%s\nChinese:%f\nMath:%f\nEnglish:%f\nTotal:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
			}
        if(i==N)
			{
                printf("\nNo more information\n");
			}
			printf("\nSearch compelete\n\n");
    system("pause");
	system("cls");
}

void search_system_eng(struct student_info stu[])
{
	int i=0;
	float score;
	system("cls");
	printf("Please input the english score that you want to search:");
    scanf("%f",&score);
	system("cls");
    for(i=0;i<N;i++)
        if(stu[i].eng==score)
		    {
				printf("\nNumber:%s\nName:%s\nID:%s\nChinese:%f\nMath:%f\nEnglish:%f\nTotal:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
			}
        if(i==N)
			{
                printf("\nNo more information\n");
			}
			printf("\nSearch compelete\n\n");
    system("pause");
	system("cls");
}

void search_system_total(struct student_info stu[])
{
	int i=0;
	float score;
	system("cls");
	printf("Please input the english score that you want to search:");
    scanf("%f",&score);
	system("cls");
    for(i=0;i<N;i++)
        if(stu[i].total==score)
		    {
				printf("\nNumber:%s\nName:%s\nID:%s\nChinese:%f\nMath:%f\nEnglish:%f\nTotal:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
			}
        if(i==N)
			{
                printf("\nNo more information\n");
			}
			printf("\nSearch compelete\n\n");
    system("pause");
	system("cls");
}

void search_system_total_range(struct student_info stu[],int temp1)
{
	int i=0;
	float score_1,score_2,s;
	system("cls");
	printf("Please input the range(score_1<score_2) after input press enter :\n");
    scanf("%f",&score_1);
	getchar();
    scanf("%f",&score_2);
	system("cls");
    for(i=0;i<temp1;i++)
        if(score_1<=stu[i].total&&stu[i].total<=score_2)
		    {
				printf("\nNumber:%s\nName:%s\nID:%s\nChinese:%f\nMath:%f\nEnglish:%f\nTotal:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
				break;
			}
        if(i==temp1)
			{
                printf("\nNo more information\n");
			}
			printf("\nSearch compelete\n\n");
    system("pause");
	system("cls");
}

void search_system_chinese_range(struct student_info stu[],int temp1)
{
	int i=0;
	float score_1,score_2,s;
	system("cls");
	printf("Please input the range(score_1<score_2) after input press enter :\n");
    scanf("%f",&score_1);
	getchar();
    scanf("%f",&score_2);
	system("cls");
    for(i=0;i<temp1;i++)
        if(score_1<=stu[i].chinese&&stu[i].chinese<=score_2)
		    {
				printf("\nNumber:%s\nName:%s\nID:%s\nChinese:%f\nMath:%f\nEnglish:%f\nTotal:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
				break;
			}
        if(i==temp1)
			{
                printf("\nNo more information\n");
			}
			printf("\nSearch compelete\n\n");
    system("pause");
	system("cls");
}

void search_system_math_range(struct student_info stu[],int temp1)
{
	int i=0;
	float score_1,score_2,s;
	system("cls");
	printf("Please input the range(score_1<score_2) after input press enter :\n");
    scanf("%f",&score_1);
	getchar();
    scanf("%f",&score_2);
	system("cls");
    for(i=0;i<temp1;i++)
        if(score_1<=stu[i].math&&stu[i].math<=score_2)
		    {
				printf("\nNumber:%s\nName:%s\nID:%s\nChinese:%f\nMath:%f\nEnglish:%f\nTotal:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
				break;
			}
        if(i==temp1)
			{
                printf("\nNo more information\n");
			}
			printf("\nSearch compelete\n\n");
    system("pause");
	system("cls");
}

void search_system_eng_range(struct student_info stu[],int temp1)
{
	int i=0;
	float score_1,score_2,s;
	system("cls");
	printf("Please input the range(score_1<score_2) after input press enter :\n");
    scanf("%f",&score_1);
	getchar();
    scanf("%f",&score_2);
	system("cls");
    for(i=0;i<temp1;i++)
        if(score_1<=stu[i].eng&&stu[i].eng<=score_2)
		    {
				printf("\nNumber:%s\nName:%s\nID:%s\nChinese:%f\nMath:%f\nEnglish:%f\nTotal:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
				break;
			}
        if(i==temp1)
			{
                printf("\nNo more information\n");
			}
			printf("\nSearch compelete\n\n");
    system("pause");
	system("cls");
}

void search_system(struct student_info stu[])
{
	int i;
    char textstring[20];
	system("cls");
	printf("Please input the number/name/id that you want to search:");
    scanf("%s",textstring);
	system("cls");
    for(i=0;i<N;i++)
        if(strcmp(stu[i].id,textstring)==0||strcmp(stu[i].name,textstring)==0||strcmp(stu[i].number,textstring)==0)
		    {
				printf("\nNumber:%s\nName:%s\nID:%s\nChinese:%f\nMath:%f\nEnglish:%f\nTotal:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
			}
        if(i==N)
			{
                printf("\nNo more information\n");
			}
			printf("\nSearch compelete\n\n");
}

void del_info(struct student_info stu[])
{
    FILE *f;
	int i=0,temp,x;
    char textstring[20];
	printf("Please input the infomation that you want to delete(number or id):");
    scanf("%s",textstring);	
	if((f=fopen("stu.txt","r+"))==NULL)
        {
            printf("stu.txt can not be opened");
            system("pause");
			menu();
        }
	while(!feof(f))
		{
			fscanf(f,"%s %s %s %f %f %f %f",stu[i].number,stu[i].name,stu[i].id,&stu[i].chinese,&stu[i].math,&stu[i].eng,&stu[i].total);
			i++;
		}
	fclose(f);
	temp=i-1;
	i=0;
	while(1)
	{
		if(i==temp+1)
		{    
            printf("No such information\n");
			system("pause");
			system("cls");
			menu();
		}
        if(strcmp(stu[i].id,textstring)==0||(strcmp(stu[i].number,textstring)==0))
		{
			printf("\nNumber:%s\nName:%s\nID:%s\nChinese:%f\nMath:%f\nEnglish:%f\nTotal:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
			break;
		}
		i++;
	}
	printf("Delete this infomation? (1.Delete   2.Back to menu)\n");
	scanf("%d",&x);
	switch(x)
	{
	case 1:break;
	case 2:menu();break;
	}
	while(i!=temp)
	{
		stu[i]=stu[i+1];
		i++;
	}
    temp-=1;
	i=0;
	if((f=fopen("stu.txt","w"))==NULL)
        {
            printf("stu.txt can not be opened");
            system("pause");
			menu();
        }
	while(i!=temp)
		{
			fprintf(f,"%s %s %s %f %f %f %f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);  
			i++;
		}
	fclose(f);
	printf("Delete compelete");
    system("pause");
	system("cls");
	menu();
}

void alter_menu(struct student_info stu[])
{
	FILE *f;
    int x,j=1,temp;
	printf("----------------------------------------------------\n");
    printf("--------1.Alter number                     ---------\n");
    printf("--------2.Alter name                       ---------\n");
	printf("--------3.Alter ID                         ---------\n");
	printf("--------4.Alter chinese score (use number) ---------\n");
    printf("--------5.Alter math    score (use number) ---------\n");
	printf("--------6.Alter english score (use number) ---------\n");
    printf("--------0.Back to menu                     ---------\n");
	printf("----------------------------------------------------\n");
    printf("You are suppose to use ID/number to Search\n");
    printf("Please choose:");
	scanf("%d",&x);
    while(1)
    {
        if((f=fopen("stu.txt","r+"))==NULL)
        {
            printf("stu.txt can not be opened");
            break;
        }
		while(!feof(f))
		{
			fscanf(f,"%s %s %s %f %f %f %f",stu[j].number,stu[j].name,stu[j].id,&stu[j].chinese,&stu[j].math,&stu[j].eng,&stu[j].total);
			j++;
		}
		fclose(f);
		temp=j-1;
        switch(x)
		{
		    case 1:alter_number(stu,temp);break;
		    case 2:alter_name(stu,temp);break;
    		case 3:alter_id(stu,temp);break;
			case 4:alter_score_chinese(stu,temp);break;
            case 5:alter_score_math(stu,temp);break;
			case 6:alter_score_eng(stu,temp);break;

			case 0:system("cls");menu();break;
        }
        
    }
}

void alter_score_chinese(struct student_info stu[],int temp)
{   
	FILE *f1;
	int i;
    char textstring[20];
	system("cls");
	printf("Please input the number to search the information:");
    scanf("%s",textstring);
	system("cls");
    for(i=1;i<N;i++)
	{
        if(strcmp(stu[i].number,textstring)==0)
		    {
				printf("\nNumber:%s\nName:%s\nID:%s\nChinese:%f\nMath:%f\nEnglish:%f\nTotal:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
				stu[0]=stu[i];
				for(;i<N;i++)
					stu[i]=stu[i+1];
				break;
			}
        if(i==N)
			{
                printf("\nNo more information\n\n");
				system("pause");
			}
	}			
	printf("\nSearch compelete\n\n");
	system("pause");
	system("cls");
	printf("Please input the chinese score \n");
    scanf("%f",&stu[0].chinese);
	stu[0].total=stu[0].chinese+stu[0].math+stu[0].eng;
	if((f1=fopen("stu.txt","w"))==NULL)
    {
        printf("File can not be opened");
        system("pause");
		alter_menu(stu);
    }
	for(i=0;i<temp-1;i++)
	fprintf(f1,"%s %s %s %f %f %f %f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
    fclose(f1);
	printf("\nAlter compelete\n");
	printf("\nNumber:%s\nName:%s\nID:%s\nChinese:%f\nMath:%f\nEnglish:%f\nTotal:%f\n",stu[0].number,stu[0].name,stu[0].id,stu[0].chinese,stu[0].math,stu[0].eng,stu[0].total);
	system("pause");
	system("cls");
    alter_menu(stu);
}

void alter_score_math(struct student_info stu[],int temp)
{   
	FILE *f1;
	int i;
    char textstring[20];
	system("cls");
	printf("Please input the number to search the information:");
    scanf("%s",textstring);
	system("cls");
    for(i=1;i<N;i++)
	{
        if(strcmp(stu[i].number,textstring)==0)
		    {
				printf("\nNumber:%s\nName:%s\nID:%s\nChinese:%f\nMath:%f\nEnglish:%f\nTotal:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
				stu[0]=stu[i];
				for(;i<N;i++)
					stu[i]=stu[i+1];
				break;
			}
        if(i==N)
			{
                printf("\nNo more information\n\n");
				system("pause");
			}
	}			
	printf("\nSearch compelete\n\n");
	system("pause");
	system("cls");
	printf("Please input the math score \n");
    scanf("%f",&stu[0].math);
	stu[0].total=stu[0].chinese+stu[0].math+stu[0].eng;
	if((f1=fopen("stu.txt","w"))==NULL)
    {
        printf("File can not be opened");
        system("pause");
		alter_menu(stu);
    }
	for(i=0;i<temp-1;i++)
	fprintf(f1,"%s %s %s %f %f %f %f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
    fclose(f1);
	printf("\nAlter compelete\n");
	printf("\nNumber:%s\nName:%s\nID:%s\nChinese:%f\nMath:%f\nEnglish:%f\nTotal:%f\n",stu[0].number,stu[0].name,stu[0].id,stu[0].chinese,stu[0].math,stu[0].eng,stu[0].total);
	system("pause");
	system("cls");
    alter_menu(stu);
}

void alter_score_eng(struct student_info stu[],int temp)
{   
	FILE *f1;
	int i;
    char textstring[20];
	system("cls");
	printf("Please input the number to search the information:");
    scanf("%s",textstring);
	system("cls");
    for(i=1;i<N;i++)
	{
        if(strcmp(stu[i].number,textstring)==0)
		    {
				printf("\nNumber:%s\nName:%s\nID:%s\nChinese:%f\nMath:%f\nEnglish:%f\nTotal:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
				stu[0]=stu[i];
				for(;i<N;i++)
					stu[i]=stu[i+1];
				break;
			}
        if(i==N)
			{
                printf("\nNo more information\n\n");
				system("pause");
			}
	}			
	printf("\nSearch compelete\n\n");
	system("pause");
	system("cls");
	printf("Please input the english score \n");
    scanf("%f",&stu[0].eng);
	stu[0].total=stu[0].chinese+stu[0].math+stu[0].eng;
	if((f1=fopen("stu.txt","w"))==NULL)
    {
        printf("File can not be opened");
        system("pause");
		alter_menu(stu);
    }
	for(i=0;i<temp-1;i++)
	fprintf(f1,"%s %s %s %f %f %f %f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
    fclose(f1);
	printf("\nAlter compelete\n");
	printf("\nNumber:%s\nName:%s\nID:%s\nChinese:%f\nMath:%f\nEnglish:%f\nTotal:%f\n",stu[0].number,stu[0].name,stu[0].id,stu[0].chinese,stu[0].math,stu[0].eng,stu[0].total);
	system("pause");
	system("cls");
    alter_menu(stu);
}

void alter_name(struct student_info stu[],int temp)
{   
	FILE *f1;
	int i;
    char textstring[20];
	system("cls");
	printf("Please input the name that you want to alter:");
    scanf("%s",textstring);
	system("cls");
    for(i=1;i<N;i++)
	{
        if(strcmp(stu[i].name,textstring)==0)
		    {
				printf("\nNumber:%s\nName:%s\nID:%s\nChinese:%f\nMath:%f\nEnglish:%f\nTotal:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
				stu[0]=stu[i];
				for(;i<N;i++)
					stu[i]=stu[i+1];
				break;
			}
        if(i==N)
			{
                printf("\nNo more information\n");
				system("pause");
				alter_menu(stu);
			}
	}			
	printf("\nSearch compelete\n\n");
    if((f1=fopen("stu.txt","w"))==NULL)
    {
        printf("File can not be opened");
        system("pause");
    }
    else
    {   
		printf("Please input the name \n");
        scanf("%s",stu[0].name);      
    }
	for(i=0;i<temp-1;i++)
	fprintf(f1,"%s %s %s %f %f %f %f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
    fclose(f1);
	printf("\nAlter compelete\n");
	printf("\nNumber:%s\nName:%s\nID:%s\nChinese:%f\nMath:%f\nEnglish:%f\nTotal:%f\n",stu[0].number,stu[0].name,stu[0].id,stu[0].chinese,stu[0].math,stu[0].eng,stu[0].total);
	system("pause");
	system("cls");
    alter_menu(stu);
}

void alter_id(struct student_info stu[],int temp)
{   
	FILE *f1;
	int i;
    char textstring[20];
	system("cls");
	printf("Please input the id that you want to alter:");
    scanf("%s",textstring);
	system("cls");
    for(i=1;i<N;i++)
	{
        if(strcmp(stu[i].id,textstring)==0)
		    {
				printf("\nNumber:%s\nName:%s\nID:%s\nChinese:%f\nMath:%f\nEnglish:%f\nTotal:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
				stu[0]=stu[i];
				for(;i<N;i++)
					stu[i]=stu[i+1];
				break;
			}
        if(i==N)
			{
                printf("\nNo more information\n");
				system("pause");
				alter_menu(stu);
			}
	}			
	printf("\nSearch compelete\n\n");
    if((f1=fopen("stu.txt","w"))==NULL)
    {
        printf("File can not be opened");
        system("pause");
    }
    else
    {   
		printf("Please input the id\n");
        scanf("%s",stu[0].id);      
    }
	for(i=0;i<temp-1;i++)
	fprintf(f1,"%s %s %s %f %f %f %f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
    fclose(f1);
	printf("\nAlter compelete\n");
	printf("\nNumber:%s\nName:%s\nID:%s\nChinese:%f\nMath:%f\nEnglish:%f\nTotal:%f\n",stu[0].number,stu[0].name,stu[0].id,stu[0].chinese,stu[0].math,stu[0].eng,stu[0].total);
	system("pause");
	system("cls");
    alter_menu(stu);
}

void alter_number(struct student_info stu[],int temp)
{   
	FILE *f1;
	int i;
    char textstring[20];
	system("cls");
	printf("Please input the number that you want to alter:");
    scanf("%s",textstring);
	system("cls");
    for(i=1;i<N;i++)
	{
        if(strcmp(stu[i].id,textstring)==0)
		    {
				printf("\nNumber:%s\nName:%s\nID:%s\nChinese:%f\nMath:%f\nEnglish:%f\nTotal:%f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
				stu[0]=stu[i];
				for(;i<N;i++)
					stu[i]=stu[i+1];
				break;
			}
        if(i==N)
			{
                printf("\nNo more information\n");
				system("pause");
				alter_menu(stu);
			}
	}			
	printf("\nSearch compelete\n\n");
    if((f1=fopen("stu.txt","w"))==NULL)
    {
        printf("File can not be opened");
        system("pause");
    }
    else
    {   
		printf("Please input the number\n");
        scanf("%s",stu[0].id);      
    }
	for(i=0;i<temp-1;i++)
	fprintf(f1,"%s %s %s %f %f %f %f\n",stu[i].number,stu[i].name,stu[i].id,stu[i].chinese,stu[i].math,stu[i].eng,stu[i].total);
    fclose(f1);
	printf("\nAlter compelete\n");
	printf("\nNumber:%s\nName:%s\nID:%s\nChinese:%f\nMath:%f\nEnglish:%f\nTotal:%f\n",stu[0].number,stu[0].name,stu[0].id,stu[0].chinese,stu[0].math,stu[0].eng,stu[0].total);
	system("pause");
	system("cls");
    alter_menu(stu);
}

