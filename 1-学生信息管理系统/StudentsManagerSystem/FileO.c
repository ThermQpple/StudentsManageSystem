#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include<unistd.h>
#include <windows.h>
#include"../Headers/FileO.h"
#include"../Headers/Core1.h"
#include"../Headers/Core2.h"

/*���ļ��ж�ȡ��Ϣ���ݺ����ӿ�*/
struct menul* Read1 (struct menu1 *head)
{
    char a [520];
    char b [52];
    char c [20];
    char d [520];//˳���ʾѧ��������ϵ����
    FILE* file1;
    file1=fopen (filebuffer1,"rb+");
    if (file1==NULL)
    {
        return head;
    }
    char cp = fgetc(file1);
    if (cp == EOF)
        return head;
    ungetc(cp,file1);
    while (!feof(file1))
    {
        int f = fscanf (file1,"%s%s%s%s",a,b,c,d);
        if (f!=EOF)
            head=Record_1 (head,a,b,c,d);
    }
    fclose (file1);
    return head;
}

/*�洢������Ϣ�����ӿ�*/
struct menu1* Store1 (struct menu1 *head)
{
    if (!head)
        return NULL;
    FILE *file1;
    file1 = fopen (filebuffer1,"wb+");
    struct menu1 *queue[1000];
    int first = 0,tail = 0;
    queue[tail++] = head;//���ṹ����
    if (file1==NULL)
        return head;
    while(first < tail)
    {
        if (queue[first]->left)  queue[tail++] = queue[first]->left;
        if (queue[first]->right) queue[tail++] = queue[first]->right;
        fprintf(file1,"%s %s %s %s\n",queue[first]->sn,queue[first]->name,queue[first]->chat,queue[first]->dor);
        first++;
    }
    fclose(file1);
    return head;
}

/*�洢�ɼ���Ϣ�����ӿ�*/
struct menu2* Store2 (struct menu2 *head)
{
    if (!head)
        return NULL;
    FILE *file2 = fopen(filebuffer2,"wb+");
    struct menu2 *p = head;
    if (file2==NULL)
    {
        return head;
    }
    while (p)
    {
        fprintf (file2,"%s %s %.1f %.1f %.1f\n",p->sn2,p->name2,p->grade1,p->grade2,p->grade3);
        p = p->Next;
    }
    fclose(file2);
    return head;
}

/*ע�ắ���ӿ�*/
struct Users * Register(struct Users *user)
{
    struct Users *u = user,*ur = user,*uh;
    char act[19];
    char pass[19];
    char p1[19];
    char ch;
TOP_:

    HideConsoleCursor();
    system("cls");
    printf ("        --------------------******************ע���˺�*********************--------------------------\n");
    printf ("        --------------------******************ע���˺�*********************--------------------------\n");
    printf ("        --------------------******************ע���˺�*********************--------------------------\n\n\n");
    printf ("                             ���������� 1 �Խ���ע�ᣬ���������������Է���...\n\n");
    fflush(stdin);
    ch = getch();
    if (ch == '1')
    {
        printf ("�����������˺� ");
        enterspring(act,1);
        while(u)
        {
            if (strcmp(u->accounts,act) == 0)
            {
                MessageBox(NULL,TEXT("�˺��Ѿ�����..."),TEXT("!"),0);
                return user;
            }
            ur = u;
            u = u->next;
        }
        uh = (struct Users*)malloc(sizeof(struct Users));
        if (uh == NULL) return user;
        printf ("�������������� ");
        enterspring(pass,2);
        printf ("���ٴ������������� ");
        if(strcmp(pass,enterspring(p1,2)) != 0)
        {
            printf ("�����������벻һ�£�����������.\n�����������...");
            getch();
            goto TOP_;
        }
        strcpy(uh->accounts,act);
        strcpy(uh->password,pass);
        uh->next = NULL;
        if (user == NULL)   user = uh;
        else    ur->next = uh;
    }
    else
        return user;
    printf ("ע��ɹ����������ص�½ҳ�棡...");
    Sleep(200);
    return user;
}

/*��½�����ӿ�*/
int Enter(struct Users *user)
{

    char act[19],pass[19];
    char ch,gh;
    //extern char;
TOP_:
    HideConsoleCursor();
    system("cls");
    printf ("    ------------------------******************��½ϵͳ*********************------------------------\n");
    printf ("    ------------------------******************��½ϵͳ*********************------------------------\n");
    printf ("    ------------------------******************��½ϵͳ*********************------------------------\n\n\n");
    printf ("                             ���������� 1 �Խ����½������������Է���...\n\n");
    fflush(stdin);
    ch = getch();
    if (ch == '1')
    {
        printf ("\n�����������˺� ");
        enterspring(act,1);
        if (user == NULL)
        {
            MessageBox(NULL,TEXT("�˺���Ϣ������..."),TEXT("!"),0);
            return 0;
        }
        struct Users *p = user;
        while (p && strcmp(p->accounts,act) != 0)
        {
            p = p->next;
        }
        if (p == NULL)
        {
            MessageBox(NULL,TEXT("�˺���Ϣ������..."),TEXT("!"),0);
            return 0;
        }
        printf ("\n�������������� ");
        while(strcmp(p->password,enterspring(pass,2)) != 0)
        {
            printf ("�������,���������� 1 �Լ����������룬0 ��ˢ��ҳ�����µ�½ \n");
            fflush(stdin);
            gh = getch();
            if (gh == '1')
            {
                printf ("\n�������������� ");
                continue;
            }
            else if (gh == '0')
                goto TOP_;
        }
    }
    else
        return 0;
    /*���Դ�������û����������ļ��е�����*/
    strcpy(filebuffer1,act);
    strcpy(filebuffer2,act);
    strcat(filebuffer1,"_IF.txt");
    strcat(filebuffer2,"_GD.txt");
    return 1;
}

/*��ȡ�û��˻���Ϣ*/
struct Users* Readuser(struct Users *user)
{
    struct Users *ph, *pc = user;
    FILE *p = fopen("Users.txt","rb+");
    if (p == NULL)
        return NULL;
    char act[19],pass[19];
    while (!feof(p))
    {
        int f = fscanf(p,"%s %s",act,pass);
        if (f != EOF)
        {
            ph = (struct Users*)malloc(sizeof(struct Users));
            strcpy(ph->accounts,act);
            strcpy(ph->password,pass);
            ph->next = NULL;
            if (user == NULL)
            {
                user = ph;
                pc = user;
            }
            else
            {
                pc->next = ph;
                pc = pc->next;
            }
        }
    }
    fclose(p);
    return user;
}

/*�洢�û��˻���Ϣ����ʵ��*/
void  StoreUser (struct Users *user)
{
    struct Users *p1;

    FILE *p = fopen("Users.txt","wb+");
    if (!p)
    {
        printf ("�����û���Ϣʧ��...");
        return ;
    }
    //printf ("%s %s",user->accounts,user->password);
    while (user)
    {
        p1= user;
        fprintf (p,"%s %s\n",user->accounts,user->password);
        user = user -> next;
        free(p1);
    }
    fclose(p);
    return ;
}

/*�޸��û��˺����뺯��*/
struct Users* ChangePass(struct Users *user)
{
    char act[19],ch,pass[19],pass1[19],pass2[19];
    int len = strlen(filebuffer1),i;
    struct Users *p = user;
    /*������ǰ�˻���*/
    for (i=0; i<len; i++)
    {
        if (filebuffer1[i] == '_')
            break;
        act[i] = filebuffer1[i];
    }
    act[i] = '\0';//�����Ա��
    while (p && strcmp(p->accounts,act) != 0)
    {
        p = p->next;
    }
TOP_:
    HideConsoleCursor();
    system("cls");
    printf ("   --------------------******************�޸�����*********************------------------------\n");
    printf ("   --------------------******************�޸�����*********************------------------------\n");
    printf ("   --------------------******************�޸�����*********************------------------------\n\n\n");
    printf ("                        ���������� 1 �Կ�ʼ�޸Ĳ�����0 �Է���...\n");
    fflush(stdin);
    ch = getch();
    if (ch == '1')
    {

        printf ("\n������ԭ����  ");
        while(p && strcmp(p->password,enterspring(pass,2)) != 0)
        {
            char gh;
            printf ("�������,���������� 1 �Լ����������룬0 ��ˢ��ҳ�� ");
            fflush(stdin);
            gh = getch();
            if (gh == '1')
            {
                printf ("\n����������ԭ���� ");
                continue;
            }
            else if (gh == '0')
                goto TOP_;
        }
        printf ("���������������� ");
        enterspring(pass1,2);
        printf ("���ٴ������������� ");
        if(strcmp(pass1,enterspring(pass2,2)) != 0)
        {
            printf ("�����������벻һ�£�����������.\n�����������...");
            getch();
            goto TOP_;
        }
        strcpy(p->password,pass1);
    }
    if (ch == '0')
        return user;
    printf ("�޸�����ɹ����밴���������...");
    getch();
    return user;
}
