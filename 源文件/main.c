#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include"../Headers/ShowMap.h"
#include"../Headers/FileO.h"
#include"../Headers/Core1.h"
#include"../Headers/Core2.h"
#include"../Headers/Input.h"
int flag;//����ϵͳ���Ķ��ر��ظ�����֤
/*struct menu1* Record_1 (struct menu1 *head,char *a,char *b,char *c,char *d);
struct menu1* Seeit_1  (struct menu1 *head);
struct menu1* Delete_1 (struct menu1 *head);
struct menu1* Find_1   (struct menu1 *head,char sp);
struct menu1* Change_1 (struct menu1 *head);
struct menu2* Record_2 (struct menu2 *head,char *a,char *b,float c,float d,float e,int change);
struct menu2* Seeit_2  (struct menu2 *head);*/

/*�����˳���������˳���½�Ľӿں���*/
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
    SetConsoleTitle ("ѧ������ϵͳ");

    heart();
    MessageBox(NULL,TEXT("��ӭ��ʹ��ѧ������ϵͳ4.0,\n �����3.0�汾�������˽ϴ�ĸı�\n1:�����Ż���һЩ�Ű�����\n2:�����Ż����˻������ĺ�����\n3:�޸���ˢ�¿�������\n4:�޸��˼�������֪����bug\n5:������ϵͳ����\n6:������Ż��˳�������"),TEXT("Hello!"),0);
    /*��Ҫ�õ��Ķ���*/
    struct menu1 *head = NULL;
    struct menu2 *head1 = NULL,*head2 = NULL,*head3 = NULL,*mainhead = NULL;
    struct Users *user = NULL;
    char Sn2[52], Name2[52], temp[52], name1[52], sn1[52], chat1[52], dor1[52];
    float Grade1,Grade2,Grade3,f;
    char c,ch,cp;

    int book;

Menu0:
    {
        //��ȡ�û��˺�����
        user = Readuser(user);
        while(1)
        {
            ShowMap0();
            fflush(stdin);
            ch = getch();
            switch(ch)
            {
            case '1':
                if (Enter(user))
                {
                    head = Read1(head);
                    FILE *file2 = fopen(filebuffer2,"rb+");
                    if (file2 == NULL)      goto Menu1;
                    cp = fgetc(file2);
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
                printf ("\t\t\t\t\tBye!�ڴ������´�ʹ��\n\n\n");
                MessageBox(NULL,TEXT("��л��ʹ�ñ�����"),TEXT("Bye!"),0);
                Exit(user,head,mainhead,head1,head2,head3);
                exit(0);
                break;
            default:
                MessageBox(NULL,TEXT("������������������..."),TEXT("!"),0);
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
                printf ("\t\t\t\t\tBye!�ڴ������´�ʹ��\n\n\n");
                MessageBox(NULL,TEXT("��л��ʹ�ñ�����"),TEXT("Bye!"),0);
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
                printf ("������������������\n");

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
                printf ("������ѧ����ѧ��      ");
                strcpy(sn1,inputString(sn1,52));
                printf ("������ѧ��������      ");
                strcpy(name1,inputString(name1,52));
                printf ("������ѧ������ϵ�绰  ");
                strcpy(chat1,inputString(chat1,52));
                printf ("������ѧ���������    ");
                strcpy(dor1,inputString(dor1,52));
                head=Record_1(head,sn1,name1,chat1,dor1);
                printf ("���β�����ɣ������Լ�������˵��ϵİ���\n");
                break;
            case '2' :
                head = EnterDelete_1(head);
                ShowMap2();
                printf ("���β�����ɣ������Լ�������˵��ϵİ���\n");
                break;
            case '3' :
                ShowSeeit_1();
                Seeit_1 (head);
                printf ("\n�밴�����������һ��");
                getch();
                ShowMap2 ();
                break;
            case '4' :
                Find_1(head,ch);
                printf ("\n�밴���������...");
                getch();
                ShowMap2();
                printf ("���β�����ɣ������Լ�������˵��ϵİ���\n");
                break;
            case '5' :
                ShowSeeit_1();
                Seeit_1 (head);
                head = Change_1(head);
                ShowMap2 ();
                printf ("���β�����ɣ������Լ�������˵��ϵİ���\n");
                break;
            case '6' :
                Find_1(head,ch);
                printf ("\n�밴���������...");
                getch();
                ShowMap2();
                printf ("���β�����ɣ������Լ�������˵��ϵİ���\n");
                break;
            case '7' :
                Store1(head);
                printf ("���β�����ɣ������Լ�������˵��ϵİ���\n");
                break;
            case '8' :
                goto Menu1;
                break;
            case '9' :
                system ("cls");
                printf ("\t\t\t\t\tBye!�ڴ������´�ʹ��\n\n\n");
                MessageBox(NULL,TEXT("��л��ʹ�ñ�����"),TEXT("Bye!"),0);
                Exit(user,head,mainhead,head1,head2,head3);
                exit(0);
                break;
            case '0' :
                ShowMap2();
                break;
            default  :
                printf ("������������������\n");

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
                printf ("�������¼��ѧ����ѧ�� ");
                strcpy(Sn2,inputString(Sn2,52));
                printf ("���������������  ");
                strcpy(Name2,inputString(Name2,52));
                printf ("��¼������ĸߵ���ѧ�ɼ�  ");
                Grade1 = inputlnt(0,100);
                printf ("��¼������Ĵ�ѧӢ��ɼ�  ");
                Grade2 = inputlnt(0,100);
                printf ("��¼�������C���Գ�����Ƴɼ�(��Ϊ���Զ���������ƽ���ɼ�)  ");
                Grade3 = inputlnt(0,100);
                flag = 0;
                mainhead = Record_2 (mainhead,Sn2,Name2,Grade1,Grade2,Grade3,0);
                if (!flag)
                {
                    head1 = Record_2 (head1,Sn2,Name2,Grade1,Grade2,Grade3,1);
                    head2 = Record_2 (head2,Sn2,Name2,Grade1,Grade2,Grade3,2);
                    head3 = Record_2 (head3,Sn2,Name2,Grade1,Grade2,Grade3,3);
                }
                printf ("���β�����ɣ������Լ�������˵��ϵİ���\n");
                break;
            case '2' :
                while (1)
                {
                    Seeit_2(mainhead);
                    printf ("���������� 1 �Խ���ɾ����2 ��ȫ��ɾ����0 �Է��ز˵�\n");
                    c = getch();
                    if (c == '1')
                    {
                        printf ("����������Ҫɾ��ѧ�����ݵ�ѧ��ѧ��  ");
                        strcpy(Sn2,inputString(Sn2,52));
                        flag = 0;
                        mainhead = Delete_2(mainhead,Sn2);
                        if (!flag)
                        {
                            head1 = Delete_2(head1,Sn2);
                            head2 = Delete_2(head2,Sn2);
                            head3 = Delete_2(head3,Sn2);
                            printf ("�����ɹ��� ");
                        }
                        printf ("���β����������밴���������...");
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
                printf ("���β�����ɣ������Լ�������˵��ϵİ���\n");
                break;
            case '3' :
                Seeit_2 (mainhead);
                printf ("\n�밴�����������һ��");
                getch();
                ShowMap3 ();
                break;
            case '4' :
                printf ("��������Ҫ�鿴ѧ����ѧ�� ");
                strcpy(Sn2,inputString(Sn2,52));
                Find_2 (mainhead,4,Sn2);
                ShowConsoleCursor();
                printf ("�밴���������...");
                getch();
                ShowMap3();
                printf ("���β�����ɣ������Լ�������˵��ϵİ���\n");
                break;
            case '5' :
                Seeit_2 (mainhead);
                printf ("\n��������Ҫ�޸�ѧ����ѧ�� ");
                strcpy(Sn2,inputString(Sn2,52));
                while (Find_2(mainhead,4,Sn2))
                {
                    ShowConsoleCursor();
                    printf ("\n���������� 1 �Ը���ѧ�ţ�2 �Ը���������3 �Ը��ĸ����ɼ���4 �Ը���Ӣ��ɼ���5 �Ը���C���Գɼ���0 �Խ������� \n");
                    book = 0;
                    c = getch();
                    switch(c)
                    {
                    case '1':
                        printf ("��������ѧ�ţ�");
                        strcpy(temp,inputString(temp,52));
                        mainhead = Change_2(mainhead,1,Sn2,temp,0);
                        head1 = Change_2(head1,1,Sn2,temp,0);
                        head2 = Change_2(head2,1,Sn2,temp,0);
                        head3 = Change_2(head3,1,Sn2,temp,0);
                        strcpy (Sn2,temp);
                        break;
                    case '2':
                        printf ("��������������");
                        strcpy(temp,inputString(temp,52));
                        mainhead = Change_2(mainhead,2,Sn2,temp,0);
                        head1 = Change_2(head1,2,Sn2,temp,0);
                        head2 = Change_2(head2,2,Sn2,temp,0);
                        head3 = Change_2(head3,2,Sn2,temp,0);
                        break;
                    case '3':
                        printf ("�������¸����ɼ���");
                        f = inputlnt(0,100);
                        mainhead = Change_2(mainhead,3,Sn2,temp,f);
                        head1 = Change_2(head1,3,Sn2,temp,f);
                        head2 = Change_2(head2,3,Sn2,temp,f);
                        head3 = Change_2(head3,3,Sn2,temp,f);
                        break;
                    case '4':
                        printf ("��������Ӣ��ɼ���");
                        f = inputlnt(0,100);
                        mainhead = Change_2(mainhead,4,Sn2,temp,f);
                        head1 = Change_2(head1,4,Sn2,temp,f);
                        head2 = Change_2(head2,4,Sn2,temp,f);
                        head3 = Change_2(head3,4,Sn2,temp,f);
                        break;
                    case '5':
                        printf ("��������C���Գɼ���");
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
                printf ("���������������...");
                fflush(stdin);
                getch();
                ShowMap3();
                break;
            case '6' :
                printf ("��������Ҫ�鿴ѧ�������� ");
                strcpy(Name2,inputString(Name2,52));
                Find_2 (mainhead,6,Name2);
                ShowConsoleCursor();
                printf ("�밴���������...");
                getch();
                ShowMap3();
                printf ("���β�����ɣ������Լ�������˵��ϵİ���\n");
                break;
            case '7' :
                Store2(mainhead);
                printf ("���β�����ɣ������Լ�������˵��ϵİ���\n");
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
                printf ("\t\t\t\t\tBye!�ڴ������´�ʹ��\n\n\n");
                MessageBox(NULL,TEXT("��л��ʹ�ñ�����"),TEXT("Bye!"),0);
                Exit(user,head,mainhead,head1,head2,head3);
                exit(0);
                break;
            case 'B' :
                system ("cls");
                printf ("\t\t\t\t\tBye!�ڴ������´�ʹ��\n\n\n");
                MessageBox(NULL,TEXT("��л��ʹ�ñ�����"),TEXT("Bye!"),0);
                Exit(user,head,mainhead,head1,head2,head3);
                exit(0);
                break;
            default  :
                printf ("������������������\n");

            }
        }
    }
    return 0;
}


