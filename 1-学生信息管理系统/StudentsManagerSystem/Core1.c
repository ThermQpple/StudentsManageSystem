#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include"../Headers/Core1.h"
//extern char filebuffer1[88],filebuffer2[88];

static int maxx(int x,int y)
{
    return x>y?x:y;
}

/*���Լ���߶ȵĺ���*/
static int high(struct menu1 *p)
{
    if (p == NULL)
        return -1;
    else
        return p->height;
}

/*LL����ת*/
struct menu1* singleft(struct menu1 *k2)  //����  LL
{
    struct menu1 *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k1->height = maxx(high(k1->left),high(k1->right))+1;
    k2->height = maxx(high(k2->left),high(k2->right))+1;
    return k1;
}

/*RR����ת*/
struct menu1* singright(struct menu1 *k2)  //�ҵ��� RR
{
    struct menu1 *k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    k1->height = maxx(high(k1->left),high(k1->right))+1;
    k2->height = maxx(high(k2->left),high(k2->right))+1;
    return k1;
}

struct menu1* doubleleft(struct menu1 *k3)   //��˫�� LR ���Ĳ��� LRL(�����ҵ�������������)
{
    k3->left = singright(k3->left);
    return singleft(k3);
}

struct menu1* doubleright(struct menu1 *k3)  //��˫�� RL ���Ĳ��� RLR
{
    k3->right = singleft(k3->right);
    return singright(k3);
}

/*���Լ�¼ϵͳһ���ݵĺ�������δ�������ļ��У����õݹ�ʵ��*/
struct menu1* Record_1 (struct menu1 *ph,char a[],char b[],char c[],char d[])
{
    if (ph == NULL)
    {
        ph = (struct menu1*)malloc(sizeof(struct menu1));
        if (ph == NULL)
        {
            MessageBox(NULL,TEXT("�����쳣����"),TEXT("sorry!"),0);
            exit(0);
        }
        strcpy(ph->sn,a);
        strcpy(ph->name,b);
        strcpy(ph->chat,c);
        strcpy(ph->dor,d);
        ph->height = 0;
        ph->left=NULL;
        ph->right=NULL;
    }
    else if (strcmp(a,ph->sn)<0)
    {
        ph->left = Record_1(ph->left,a,b,c,d);
        if (high(ph->left)-high(ph->right) == 2)
        {
            if (strcmp(a,ph->left->sn)<0)
                ph = singleft(ph);
            else
                ph = doubleleft(ph);
        }
    }
    else if (strcmp(a,ph->sn)>0)
    {
        ph->right = Record_1(ph->right,a,b,c,d);
        if (high(ph->right)-high(ph->left) == 2)
        {
            if (strcmp(a,ph->right->sn)>0)
                ph = singright(ph);
            else
                ph = doubleright(ph);
        }
    }
    else if(strcmp(a,ph->sn) == 0)//����ѧ���ظ�
    {
        printf ("�������ѧ�����ظ�!������鲢���²��� ");
        return ph;
    }
    ph->height = max(high(ph->left),high(ph->right))+1;
    return ph;
}

/*�鿴��Ϣ���������*/
struct menu1* Seeit_1 (struct menu1 *head)
{
    struct menu1 *p = head;
    if (p)
    {
        Seeit_1(p->left);
        printf ("\t\t     %-19s%-22s%-27s%-16s",p->sn,p->name,p->chat,p->dor);
        printf ("\n");
        Seeit_1(p->right);
    }
    return head;
}

/*ɾ���ڵ㺯�����ݹ�ʵ��*/
struct menu1* Delete_1 (struct menu1 *p,char x[])
{
    if (!p)
        printf ("��ѧ��������!\n");
    else
    {
        if (strcmp(x,p->sn)<0)
        {
            p->left = Delete_1(p->left,x);
            if (abs(high(p->left)-high(p->right))==2)
            {
                if (high(p->left->left)>high(p->left->right))
                    p = singleft(p);
                else
                    p = doubleleft(p);
            }
        }
        else if (strcmp(x,p->sn)>0)
        {
            p->right = Delete_1(p->right,x);
            if (abs(high(p->left)-high(p->right))==2)
            {
                if (high(p->right->left)<high(p->right->right))
                    p = singright(p);
                else
                    p = doubleright(p);
            }
        }
        else
        {
            struct menu1 *ph;
            if (p->left&&p->right)/*�����ҵ��ϸߵ������з��ϵĽڵ�������������Լ�����ת�Ŀ���*/
            {
                if (high(p->left)>=high(p->right))
                {
                    ph = p->left;
                    while (ph->right)//�����������ڵ����
                        ph = ph->right;
                    strcpy(p->sn, ph->sn);
                    strcpy(p->name, ph->name);
                    strcpy(p->dor, ph->dor);
                    strcpy(p->chat, ph->chat);
                    p->left = Delete_1(p->left,ph->sn);
                }
                else
                {
                    ph = p->right;
                    while (ph->left)//�����������½ڵ����
                        ph = ph->left;
                    strcpy(p->sn, ph->sn);
                    strcpy(p->name, ph->name);
                    strcpy(p->dor, ph->dor);
                    strcpy(p->chat, ph->chat);
                    p->right = Delete_1(p->right,ph->sn);
                }
            }
            else
            {
                struct menu1 *ph = p;
                if (p->left == NULL)
                    p = p->right;
                else if (p->right == NULL)
                    p = p->left;
                free(ph);
                ph = NULL;
            }
        }
    }
    return p;
}

/*��ѯ����*/
struct menu1* Find_1 (struct menu1 *head,char sp)//sp���Ա�ʾѡ��
{
    char s[52];
    struct menu1 *p=head,*queue[1000];
    int hea = 0, tail = 0;
    queue[tail++] = head;
    if (p==NULL)
    {
        printf ("��������\n");
        return p;
    }
    switch(sp)
    {
    case '4':
        printf ("�����������ѧ��  ");
        strcpy(s,inputString(s,52));
        HideConsoleCursor();
        system("cls");
        while (strcmp(p->sn,s)!=0)
        {
            if (strcmp(s,p->sn)<0)
                p=p->left;
            else if (strcmp(s,p->sn)>0)
                p=p->right;
            if (p==NULL)
            {
                printf ("�Բ��𣬸���������\n");
                return p;
            }
        }
        printf ("\t----------------------******************ѧ����Ϣ�鿴*********************--------------------\n");
        printf ("\t-------------ѧ��---------------����------------------��ϵ��ʽ-------------------�����-----\n\n");
        printf ("\t\t     %-19s%-22s%-27s%-16s\n",p->sn,p->name,p->chat,p->dor);
        return p;
    case '6':
        printf ("���������������  ");
        strcpy(s,inputString(s,52));
        HideConsoleCursor();
        system("cls");
        while (hea < tail && strcmp(queue[hea]->name,s) != 0)
        {
            if (queue[hea]->left)
                queue[tail++] = queue[hea]->left;
            if (queue[hea]->right)
                queue[tail++] = queue[hea]->right;
            hea++;
        }
        if (hea == tail)
        {

            printf ("�Բ��𣬸���������\n");
            return NULL;

        }
        else p = queue[hea];
        printf ("\t----------------------******************ѧ����Ϣ�鿴*********************--------------------\n");
        printf ("\t-------------ѧ��---------------����------------------��ϵ��ʽ-------------------�����-----\n");
        printf ("\t\t     %-19s%-22s%-27s%-16s\n",p->sn,p->name,p->chat,p->dor);
        return p;
    }
}

/*�޸����ݺ���*/
struct menu1* Change_1 (struct menu1 *head)
{
    char sn1[52],ck;
    struct menu1 *p,*h = head;
    printf ("����Ҫ��������Ҫ�޸ĵ�ѧ����ѧ��\n");
    p = Find_1(head,'4');
    if (p == NULL)
    {
        printf ("�밴���������");
        getch();
        return head;
    }
    while (1)
    {
        printf ("���������� 1 ���޸�ѧ�ţ����� 2 ���޸����������� 3 ���޸���ϵ��ʽ������ 4 ���޸�����ţ����� 0 ���˳����β���\n");
        ck = getch();
        switch (ck)
        {
        case '0':
            return head;
        case '1':
            printf ("��������ѧ�� ");
            strcpy(p->sn,inputString(sn1,52));
            printf ("�����ɹ������������\n");
            break;
        case '2':
            printf ("������������ ");
            strcpy(p->sn,inputString(sn1,52));
            printf ("�����ɹ������������\n");
            break;
        case '3':
            printf ("����������ϵ��ʽ ");
            strcpy(p->sn,inputString(sn1,52));
            printf ("�����ɹ������������\n");
            break;
        case '4':
            printf ("������������� ");
            strcpy(p->sn,inputString(sn1,52));
            printf ("�����ɹ������������\n");
            break;
        default:
            printf ("�����������������������\n");
            break;
        }
    }

}

/*ɾ�������Ľӿڣ�����ɾ������*/
struct menu1* EnterDelete_1(struct menu1 *head)
{
    char sn1[52],c;
    while (1)
    {
        ShowSeeit_1();
        Seeit_1(head);
        printf ("���������� 1 �Լ���ɾ����2 ��ȫ��ɾ����0 �Է��ز˵�\n");
        c = getch();
        switch (c)
        {
        case '1':
            printf ("����������Ҫɾ��ѧ����ѧ�� ");
            strcpy(sn1,inputString(sn1,52));
            head = Delete_1 (head,sn1);
            printf ("���β������������������������... ");
            getch();
            break;
        case '2':
            FreeAll_1(head);
            head = NULL;
            break;
        case '0':
            return head;
        default:
            printf ("������������������\n");
            break;
        }
    }
    return head;
}

/*Free*/
void FreeAll_1(struct menu1 *head)
{
    if (head && head->left)
        FreeAll_1(head->left);
    if (head)
    {
        free(head);
        head = NULL;
    }
    if (head && head->right)
        FreeAll_1(head->right);
    return;
}
