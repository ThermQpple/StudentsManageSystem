#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include"../Headers/ShowMap.h"
#include"../Headers/FileO.h"
#include"../Headers/Core1.h"
#include"../Headers/Core2.h"
#include"../Headers/Input.h"
int flag;//用于系统二的多重表重复性验证
/*struct menu1* Record_1 (struct menu1 *head,char *a,char *b,char *c,char *d);
struct menu1* Seeit_1  (struct menu1 *head);
struct menu1* Delete_1 (struct menu1 *head);
struct menu1* Find_1   (struct menu1 *head,char sp);
struct menu1* Change_1 (struct menu1 *head);
struct menu2* Record_2 (struct menu2 *head,char *a,char *b,float c,float d,float e,int change);
struct menu2* Seeit_2  (struct menu2 *head);*/

/*用于退出程序或者退出登陆的接口函数*/
void Exit (struct Users *h,struct menu1 *h1,struct menu2 *h2,struct menu2 *h3,struct menu2 *h4,struct menu2 *h5)
{
    Store1(h1);
    Store2(h2);
    StoreUser(h);
    FreeAll_1(h1);
    FreeAll_2(h2);
    FreeAll_2(h3);
    FreeAll_2(h4);
    FreeAll_2(h5);
    memset(filebuffer1,'\0',sizeof(filebuffer1));
    memset(filebuffer2,'\0',sizeof(filebuffer2));
}

int main()
{
    SetConsoleTitle ("学生管理系统");

    heart();
    MessageBox(NULL,TEXT("欢迎您使用学生管理系统4.0,\n 相较于3.0版本我们做了较大的改变\n1:我们优化了一些排版问题\n2:我们优化了人机交互的合理性\n3:修复了刷新卡屏问题\n4:修复了几个您不知到的bug\n5:完善了系统功能\n6:极大的优化了程序性能"),TEXT("Hello!"),0);
    /*需要用到的定义*/
    struct menu1 *head = NULL;//信息管理系统表头
    struct menu2 *head1 = NULL,*head2 = NULL,*head3 = NULL,*mainhead = NULL;//表示高数成绩、英语成绩、c成绩和总成绩表头
    struct Users *user = NULL;//用户账号密码表头
    char Sn2[52], Name2[52], temp[52], name1[52], sn1[52], chat1[52], dor1[52];
    float Grade1,Grade2,Grade3,f;
    char c,ch,cp;

    int book;

Menu0:
    {
        //读取用户账号密码
        user = Readuser(user);
        while(1)
        {
            ShowMap0();
            fflush(stdin);
            ch = getch();
            switch(ch)
            {
            case '1':
                if (Enter(user))//成功登陆的话
                {
                    head = Read1(head);
                    FILE *file2 = fopen(filebuffer2,"rb+");
                    if (file2 == NULL)      goto Menu1;
                    cp = fgetc(file2);//预防文件为空的情况
                    if (cp == EOF)
                    {
                        fclose(file2);
                        goto Menu1;
                    }
                    ungetc(cp,file2);
                    while (!feof(file2))
                    {
                        int f = fscanf (file2,"%s %s %f %f %f",Sn2,Name2,&Grade1,&Grade2,&Grade3);
                        if (f != EOF)
                        {
                            mainhead = Record_2 (mainhead,Sn2,Name2,Grade1,Grade2,Grade3,0);
                            head1 = Record_2 (head1,Sn2,Name2,Grade1,Grade2,Grade3,1);
                            head2 = Record_2 (head2,Sn2,Name2,Grade1,Grade2,Grade3,2);
                            head3 = Record_2 (head3,Sn2,Name2,Grade1,Grade2,Grade3,3);
                        }
                    }
                    fclose(file2);
                    goto Menu1;
                }
                break;

            case '2':
                user = Register(user);
                break;
            case '0':
                system ("cls");
                printf ("\t\t\t\t\tBye!期待您的下次使用\n\n\n");
                MessageBox(NULL,TEXT("感谢您使用本程序"),TEXT("Bye!"),0);
                Exit(user,head,mainhead,head1,head2,head3);
                exit(0);
                break;
            default:
                MessageBox(NULL,TEXT("输入有误，请重新输入..."),TEXT("!"),0);
            }
        }
    }
Menu1:
    {
        ShowMap1();
        while (1)
        {
            fflush(stdin);
            ch = getch();
            switch(ch)
            {
            case '1' :
                goto Menu2;
                break;
            case '2' :
                goto Menu3;
                break;
            case '3' :
                user = ChangePass(user);
                ShowMap1();
                break;
            case '4' :
                Exit(user,head,mainhead,head1,head2,head3);
                user = head = mainhead = head1 = head2 = head3 = NULL;
                goto Menu0;
                break;
            case '5':
                system ("cls");
                printf ("\t\t\t\t\tBye!期待您的下次使用\n\n\n");
                MessageBox(NULL,TEXT("感谢您使用本程序"),TEXT("Bye!"),0);
                Exit(user,head,mainhead,head1,head2,head3);
                exit(0);
                break;
            case '6':
                ShowRegard();
                ShowMap1();
                break;
            case '0' :
                ShowHelp();
                ShowMap1();
                break;
            default  :
                printf ("输入有误，请重新输入\n");

            }
        }
    }
Menu2:
    {
        ShowMap2 ();
        while (1)
        {
            fflush(stdin);
            ch = getch();
            switch(ch)
            {
                memset(sn1,'\0',sizeof(sn1));
                memset(name1,'\0',sizeof(name1));
                memset(chat1,'\0',sizeof(chat1));
                memset(dor1,'\0',sizeof(dor1));
            case '1' :
                printf ("请输入学生的学号      ");
                strcpy(sn1,inputString(sn1,52));
                printf ("请输入学生的姓名      ");
                strcpy(name1,inputString(name1,52));
                printf ("请输入学生的联系电话  ");
                strcpy(chat1,inputString(chat1,52));
                printf ("请输入学生的宿舍号    ");
                strcpy(dor1,inputString(dor1,52));
                head=Record_1(head,sn1,name1,chat1,dor1);
                printf ("本次操作完成，您可以继续输入菜单上的按键\n");
                break;
            case '2' :
                head = EnterDelete_1(head);
                ShowMap2();
                printf ("本次操作完成，您可以继续输入菜单上的按键\n");
                break;
            case '3' :
                ShowSeeit_1();
                Seeit_1 (head);
                printf ("\n请按任意键返回上一级");
                getch();
                ShowMap2 ();
                break;
            case '4' :
                Find_1(head,ch);
                printf ("\n请按任意键返回...");
                getch();
                ShowMap2();
                printf ("本次操作完成，您可以继续输入菜单上的按键\n");
                break;
            case '5' :
                ShowSeeit_1();
                Seeit_1 (head);
                head = Change_1(head);
                ShowMap2 ();
                printf ("本次操作完成，您可以继续输入菜单上的按键\n");
                break;
            case '6' :
                Find_1(head,ch);
                printf ("\n请按任意键返回...");
                getch();
                ShowMap2();
                printf ("本次操作完成，您可以继续输入菜单上的按键\n");
                break;
            case '7' :
                Store1(head);
                printf ("本次操作完成，您可以继续输入菜单上的按键\n");
                break;
            case '8' :
                goto Menu1;
                break;
            case '9' :
                system ("cls");
                printf ("\t\t\t\t\tBye!期待您的下次使用\n\n\n");
                MessageBox(NULL,TEXT("感谢您使用本程序"),TEXT("Bye!"),0);
                Exit(user,head,mainhead,head1,head2,head3);
                exit(0);
                break;
            case '0' :
                ShowMap2();
                break;
            default  :
                printf ("输入有误，请重新输入\n");

            }
        }
    }
Menu3:
    {
        ShowMap3 ();
        while (1)
        {
            memset(Sn2,'\0',sizeof(Sn2));
            memset(Name2,'\0',sizeof(Name2));
            fflush(stdin);
            ch = getch();
            switch(ch)
            {
            case '1' :
                printf ("请输入待录入学生的学号 ");
                strcpy(Sn2,inputString(Sn2,52));
                printf ("请输入该生的姓名  ");
                strcpy(Name2,inputString(Name2,52));
                printf ("请录入该生的高等数学成绩  ");
                Grade1 = inputlnt(0,100);
                printf ("请录入该生的大学英语成绩  ");
                Grade2 = inputlnt(0,100);
                printf ("请录入该生的C语言程序设计成绩(将为您自动计算三科平均成绩)  ");
                Grade3 = inputlnt(0,100);
                flag = 0;
                mainhead = Record_2 (mainhead,Sn2,Name2,Grade1,Grade2,Grade3,0);
                if (!flag)
                {
                    head1 = Record_2 (head1,Sn2,Name2,Grade1,Grade2,Grade3,1);
                    head2 = Record_2 (head2,Sn2,Name2,Grade1,Grade2,Grade3,2);
                    head3 = Record_2 (head3,Sn2,Name2,Grade1,Grade2,Grade3,3);
                }
                printf ("本次操作完成，您可以继续输入菜单上的按键\n");
                break;
            case '2' :
                while (1)
                {
                    Seeit_2(mainhead);
                    printf ("您可以输入 1 以进行删除，2 以全部删除，0 以返回菜单\n");
                    c = getch();
                    if (c == '1')
                    {
                        printf ("请输入您想要删除学生数据的学生学号  ");
                        strcpy(Sn2,inputString(Sn2,52));
                        flag = 0;
                        mainhead = Delete_2(mainhead,Sn2);
                        if (!flag)
                        {
                            head1 = Delete_2(head1,Sn2);
                            head2 = Delete_2(head2,Sn2);
                            head3 = Delete_2(head3,Sn2);
                            printf ("操作成功！ ");
                        }
                        printf ("本次操作结束，请按任意键继续...");
                        getch();
                    }
                    else if (c == '2')
                    {
                        FreeAll_2(mainhead);
                        FreeAll_2(head1);
                        FreeAll_2(head2);
                        FreeAll_2(head3);
                        mainhead = NULL;
                        head1 = NULL;
                        head2 = NULL;
                        head3 = NULL;
                    }
                    else if (c == '0')
                        break;
                }
                ShowMap3();
                printf ("本次操作完成，您可以继续输入菜单上的按键\n");
                break;
            case '3' :
                Seeit_2 (mainhead);
                printf ("\n请按任意键返回上一级");
                getch();
                ShowMap3 ();
                break;
            case '4' :
                printf ("请输入您要查看学生的学号 ");
                strcpy(Sn2,inputString(Sn2,52));
                Find_2 (mainhead,4,Sn2);
                ShowConsoleCursor();
                printf ("请按任意键继续...");
                getch();
                ShowMap3();
                printf ("本次操作完成，您可以继续输入菜单上的按键\n");
                break;
            case '5' :
                Seeit_2 (mainhead);
                printf ("\n请输入您要修改学生的学号 ");
                strcpy(Sn2,inputString(Sn2,52));
                while (Find_2(mainhead,4,Sn2))
                {
                    ShowConsoleCursor();
                    printf ("\n您可以输入 1 以更改学号，2 以更改姓名，3 以更改高数成绩，4 以更改英语成绩，5 以更改C语言成绩，0 以结束操作 \n");
                    book = 0;
                    c = getch();
                    switch(c)
                    {
                    case '1':
                        printf ("请输入新学号！");
                        strcpy(temp,inputString(temp,52));
                        mainhead = Change_2(mainhead,1,Sn2,temp,0);
                        head1 = Change_2(head1,1,Sn2,temp,0);
                        head2 = Change_2(head2,1,Sn2,temp,0);
                        head3 = Change_2(head3,1,Sn2,temp,0);
                        strcpy (Sn2,temp);
                        break;
                    case '2':
                        printf ("请输入新姓名！");
                        strcpy(temp,inputString(temp,52));
                        mainhead = Change_2(mainhead,2,Sn2,temp,0);
                        head1 = Change_2(head1,2,Sn2,temp,0);
                        head2 = Change_2(head2,2,Sn2,temp,0);
                        head3 = Change_2(head3,2,Sn2,temp,0);
                        break;
                    case '3':
                        printf ("请输入新高数成绩！");
                        f = inputlnt(0,100);
                        mainhead = Change_2(mainhead,3,Sn2,temp,f);
                        head1 = Change_2(head1,3,Sn2,temp,f);
                        head2 = Change_2(head2,3,Sn2,temp,f);
                        head3 = Change_2(head3,3,Sn2,temp,f);
                        break;
                    case '4':
                        printf ("请输入新英语成绩！");
                        f = inputlnt(0,100);
                        mainhead = Change_2(mainhead,4,Sn2,temp,f);
                        head1 = Change_2(head1,4,Sn2,temp,f);
                        head2 = Change_2(head2,4,Sn2,temp,f);
                        head3 = Change_2(head3,4,Sn2,temp,f);
                        break;
                    case '5':
                        printf ("请输入新C语言成绩！");
                        f = inputlnt(0,100);
                        mainhead = Change_2(mainhead,5,Sn2,temp,f);
                        head1 = Change_2(head1,5,Sn2,temp,f);
                        head2 = Change_2(head2,5,Sn2,temp,f);
                        head3 = Change_2(head3,5,Sn2,temp,f);
                        break;
                    case '0':
                        book = 1;
                        break;
                    }
                    if (book)
                        break;

                }
                printf ("请输入任意键返回...");
                fflush(stdin);
                getch();
                ShowMap3();
                break;
            case '6' :
                printf ("请输入您要查看学生的姓名 ");
                strcpy(Name2,inputString(Name2,52));
                Find_2 (mainhead,6,Name2);
                ShowConsoleCursor();
                printf ("请按任意键继续...");
                getch();
                ShowMap3();
                printf ("本次操作完成，您可以继续输入菜单上的按键\n");
                break;
            case '7' :
                Store2(mainhead);
                printf ("本次操作完成，您可以继续输入菜单上的按键\n");
                break;
            case '8' :
                CordReport_2(mainhead,head1,head2,head3);
                ShowMap3();
                break;
            case '9' :
                EnterSee2(mainhead,head1,head2,head3);
                ShowMap3();
                break;
            case '0' :
                ShowMap3();
                break;
            case 'a' :
                goto Menu1;
                break;
            case 'A' :
                goto Menu1;
                break;
            case 'b' :
                system ("cls");
                printf ("\t\t\t\t\tBye!期待您的下次使用\n\n\n");
                MessageBox(NULL,TEXT("感谢您使用本程序"),TEXT("Bye!"),0);
                Exit(user,head,mainhead,head1,head2,head3);
                exit(0);
                break;
            case 'B' :
                system ("cls");
                printf ("\t\t\t\t\tBye!期待您的下次使用\n\n\n");
                MessageBox(NULL,TEXT("感谢您使用本程序"),TEXT("Bye!"),0);
                Exit(user,head,mainhead,head1,head2,head3);
                exit(0);
                break;
            default  :
                printf ("输入有误，请重新输入\n");

            }
        }
    }
    return 0;
}


