#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include"../Headers/Core2.h"
extern int flag;//����ȫ�ֱ�����ʹ��

/*���ڼ�¼���ݣ�change���Ա�ʾѡ��1�������ֱ�������ͷ*/
struct menu2* Record_2 (struct menu2 *head,char *a,char *b,float c,float d,float e,int change)
{
    struct menu2 *p = head,*pr,*ph;//˫������
    float f = (c+d+e)/3.0;
    while (p)
    {
        if (strcmp(p->sn2,a) == 0)
        {
            MessageBox(NULL,TEXT("ѧ�Ŵ����ظ�����������..."),TEXT("!"),0);
            flag = 1;
            return head;
        }
        p = p->Next;
    }//����ѧ���ظ�
    p = head;
    ph = (struct menu2*)malloc(sizeof(struct menu2));
    if (ph==NULL)
    {
        MessageBox(NULL,TEXT("�����쳣��"),TEXT ("Sorry!"),0);
        exit (0);
    }
    if (p == NULL)
    {
        head = ph;
        ph->Previous = NULL;
        ph->Next = NULL;
    }
    else
    {
        switch (change)
        {
        case 0:
            if (f>p->TotalGrade || (f == p->TotalGrade && strcmp(a,p->sn2) <= 0))
            {
                head = ph;
                ph->Previous = NULL;
                ph->Next = p;
                p->Previous = ph;
            }
            else
            {
                while (p && f<p->TotalGrade)
                {
                    pr = p;
                    p = p->Next;
                }
                while (p && f == p->TotalGrade && strcmp(a,p->sn2) > 0)//�ɼ���ͬ����������
                {
                    pr = p;
                    p = p->Next;
                }
                if (p==NULL)
                {
                    pr->Next = ph;
                    ph->Previous = pr;
                    ph->Next = NULL;
                }
                else
                {
                    ph->Next = p;
                    ph->Previous = pr;
                    pr->Next = ph;
                    p->Previous = ph;
                }
            }
            break;
        case 1:
            if (c>p->grade1|| (c == p->grade1 && strcmp(a,p->sn2) <= 0))
            {
                head = ph;
                ph->Previous = NULL;
                ph->Next = p;
                p->Previous = ph;
            }
            else
            {
                while (p && c<p->grade1)
                {
                    pr = p;
                    p = p->Next;
                }
                while (p && c == p->grade1 && strcmp(a,p->sn2) > 0)
                {
                    pr = p;
                    p = p->Next;
                }
                if (p==NULL)
                {
                    pr->Next = ph;
                    ph->Previous = pr;
                    ph->Next = NULL;
                }
                else
                {
                    ph->Next = p;
                    ph->Previous = pr;
                    pr->Next = ph;
                    p->Previous = ph;
                }
            }
            break;
        case 2:
            if (d>p->grade2 || (d == p->grade2 && strcmp(a,p->sn2) <= 0))
            {
                head = ph;
                ph->Previous = NULL;
                ph->Next = p;
                p->Previous = ph;
            }
            else
            {
                while (p && d<p->grade2)
                {
                    pr = p;
                    p = p->Next;
                }
                while (p && d == p->grade2 && strcmp(a,p->sn2) > 0)
                {
                    pr = p;
                    p = p->Next;
                }
                if (p==NULL)
                {
                    pr->Next = ph;
                    ph->Previous = pr;
                    ph->Next = NULL;
                }
                else
                {
                    ph->Next = p;
                    ph->Previous = pr;
                    pr->Next = ph;
                    p->Previous = ph;
                }
            }
            break;
        case 3:
            if (e>p->grade3 || (e == p->grade3 && strcmp(a,p->sn2) <= 0))
            {
                head = ph;
                ph->Previous = NULL;
                ph->Next = p;
                p->Previous = ph;
            }
            else
            {
                while (p && e<p->grade3)
                {
                    pr = p;
                    p = p->Next;
                }
                while (p && e == p->grade3 && strcmp(a,p->sn2) > 0)
                {
                    pr = p;
                    p = p->Next;
                }
                if (p==NULL)
                {
                    pr->Next = ph;
                    ph->Previous = pr;
                    ph->Next = NULL;
                }
                else
                {
                    ph->Next = p;
                    ph->Previous = pr;
                    pr->Next = ph;
                    p->Previous = ph;
                }
            }
            break;
        }
    }
    strcpy(ph->sn2,a);
    strcpy(ph->name2,b);
    ph->grade1 = c;
    ph->grade2 = d;
    ph->grade3 = e;
    ph->TotalGrade = f;
    return head;
}

/*�鿴�������ݺ���*/
struct menu2* Seeit_2  (struct menu2 *head)
{
    system ("cls");
    struct menu2 *p = head;
    printf ("\n\n\n\n\t----------------------******************ѧ���ɼ��鿴*********************--------------------\n\n\n");
    printf ("\tѧ��----------����----------�����ɼ�--------Ӣ��ɼ�--------C���Գ�����Ƴɼ�--------�ܳɼ�(ƽ���ɼ�)\n\n");
    while (p)
    {
        printf ("\t%-14s%-15s%-15.1f%-18.1f%-23.1f%-15.1f",p->sn2,p->name2,p->grade1,p->grade2,p->grade3,p->TotalGrade);
        printf ("\n");
        p=p->Next;
    }
    return head;
}

/*ɾ���ڵ㺯��*/
//flag���Ա��ɾ��ʧ�������������ɾ��
struct menu2* Delete_2 (struct menu2 *head,char s[])
{
    struct menu2 *p = head;
    if (!p)
    {
        flag = 1;
        printf ("��������!\n");
        return NULL;
    }
    while (strcmp(p->sn2,s)!=0)
    {
        p = p->Next;
        if (!p)
        {
            flag = 1;
            printf ("�������ݲ����ڣ������ԣ�\n");
            return head;
        }
    }
    if (p->Previous  == NULL && p->Next == NULL)
    {
        free(p);
        p = NULL;
        return NULL;
    }
    else if (!p->Previous)
    {
        head = p->Next;
        p->Next->Previous = NULL;
    }
    else if (!p->Next)
        p->Previous->Next = NULL;
    else
    {
        p->Previous->Next = p->Next;
        p->Next->Previous = p->Previous;
    }
    free(p);
    p = NULL;
    return head;
}

/*��ѯ*/
struct menu2* Find_2 (struct menu2 *head,int change,char c[])//C���Ա�ʾ��������ѧ�ţ�ȡ����change�Ƿ�Ϊ6����4
{
    HideConsoleCursor();
    system("cls");
    struct menu2 *p = head;
    switch (change)
    {
    case 4:
        while (p)
        {
            if (strcmp(p->sn2,c)==0)
            {
                printf ("\n\n\n\n\t----------------------******************ѧ���ɼ��鿴*********************--------------------\n\n\n");
                printf ("\tѧ��----------����----------�����ɼ�--------Ӣ��ɼ�--------C���Գ�����Ƴɼ�--------�ܳɼ�(ƽ���ɼ�)\n\n");
                printf ("\t%-14s%-15s%-15.1f%-18.1f%-23.1f%-15.1f",p->sn2,p->name2,p->grade1,p->grade2,p->grade3,p->TotalGrade);
                printf ("\n");
                return p;
            }
            else
                //return Find_2(p->Next,4,c);
                p=p->Next;
        }
        printf ("��ѧ��������\n");
        break;
    case 6:
        while (p)
        {
            if (strcmp(p->name2,c)==0)
            {
                printf ("\n\n\n\n\t----------------------******************ѧ���ɼ��鿴*********************--------------------\n\n\n");
                printf ("\tѧ��----------����----------�����ɼ�--------Ӣ��ɼ�--------C���Գ�����Ƴɼ�--------�ܳɼ�(ƽ���ɼ�)\n\n");
                printf ("\t%-14s%-15s%-15.1f%-18.1f%-23.1f%-15.1f",p->sn2,p->name2,p->grade1,p->grade2,p->grade3,p->TotalGrade);
                printf ("\n");
                return p;
            }
            else
                p=p->Next;//return Find_2(p->Next,6,c);
        }
        printf ("��ѧ��������\n");
        break;
    }
    return NULL;
}

/*�鿴���Ƴɼ�*/
void SeeThesingle_2  (struct menu2 *headofit,int choice)
{
    struct menu2 *head = headofit;
    switch(choice)
    {
    case 1:
        printf ("\n\n\n\n\t----------------------******************ѧ�������ɼ��鿴*********************--------------------\n\n\n");
        printf ("\t\t\t\t\tѧ��----------����----------�����ɼ�\n\n");
        while (head)
        {
            printf ("\t\t\t\t\t%-14s%-15s%-15.1f",head->sn2,head->name2,head->grade1);
            printf ("\n");
            head = head->Next;
        }
        break;
    case 2:
        printf ("\n\n\n\n\t----------------------******************ѧ��Ӣ��ɼ��鿴*********************--------------------\n\n\n");
        printf ("\t\t\t\t\tѧ��----------����----------Ӣ��ɼ�\n\n");
        while (head)
        {
            printf ("\t\t\t\t\t%-14s%-15s%-15.1f",head->sn2,head->name2,head->grade2);
            printf ("\n");
            head = head->Next;
        }
        break;
    case 3:
        printf ("\n\n\n\n\t----------------------******************ѧ��C���Գɼ��鿴*********************--------------------\n\n\n");
        printf ("\t\t\t\t\tѧ��----------����----------C���Գɼ�\n\n");
        while (head)
        {
            printf ("\t\t\t\t\t%-14s%-15s%-15.1f",head->sn2,head->name2,head->grade3);
            printf ("\n");
            head = head->Next;
        }
        break;
    }
    printf("\n\n");
    return ;
}

/*����鿴���Ƴɼ��ӿ�*/
void EnterSee2(struct menu2 *Mainhead,struct menu2 *head1,struct menu2 *head2,struct menu2 *head3)
{
    char c;
STA:
    HideConsoleCursor();
    system("cls");
    printf ("�������������� 1 �Բ鿴ѧ�������ɼ���2 �Բ鿴ѧ����Ӣ��ɼ���3 �Բ鿴C���Գɼ���5 �Է��ز˵�,0��ˢ�µ�ǰҳ��\n");
    ShowConsoleCursor();
    while (1)
    {
        fflush(stdin);
        c = getch();
        switch(c)
        {
        case '1':
            SeeThesingle_2(head1,1);
            printf ("�����ɹ��������Լ���������\n");
            break;
        case '2':
            SeeThesingle_2(head2,2);
            printf ("�����ɹ��������Լ���������\n");
            break;
        case '3':
            SeeThesingle_2(head3,3);
            printf ("�����ɹ��������Լ���������\n");
            break;
        case '0':
            goto STA;
            break;
        case '5':
            return ;
        default:
            printf ("������������������\n");
            break;
        }
    }
    return ;
}

/*�޸�����*/
struct menu2* Change_2 (struct menu2 *head, int choice,char sn[],char s[], float grade)
{
    struct menu2 *p = head;
    float f;
    while (p && strcmp(sn,p->sn2) != 0)
        p = p->Next;
    switch (choice)
    {
    case 1:
        strcpy(p->sn2,s);
        return head;
    case 2:
        strcpy(p->name2,s);
        return head;
    case 3:
        f = (grade + p->grade2 + p->grade3)/3.0;
        p->grade1 = grade;
        p->TotalGrade = f;
        return head;
    case 4:
        f = (grade + p->grade1 + p->grade3)/3.0;
        p->grade2 = grade;
        p->TotalGrade = f;
        return head;
    case 5:
        f = (grade + p->grade2 + p->grade1)/3.0;
        p->grade3 = grade;
        p->TotalGrade = f;
        return head;
    }
    return head;
}

/*�ɼ����溯��*/
void CordReport_2(struct menu2 *mainhead,struct menu2 *head1,struct menu2 *head2,struct menu2 *head3)
{
Sta:
    HideConsoleCursor();
    system("cls");
    struct menu2 *p,*p1,*p2,*p3;
    float num1 = 0,num2 = 0,num3 = 0;
    char ch;
    printf ("----------------------******************����5�Է��ز˵�������0��ˢ��ҳ��*********************--------------------\n");
    printf ("----------------------******************����5�Է��ز˵�������0��ˢ��ҳ��*********************--------------------\n");
    printf ("\t*���������� 1 �Բ鿴ƽ���ɼ����棬2 �Բ鿴�����ɼ����棬3 �Բ鿴Ӣ��ɼ����棬4 �Բ鿴C���Գɼ�����* \n");
    while (1)
    {
        p = mainhead;
        p1 = head1;
        p2 = head2;
        p3 = head3;
        ShowConsoleCursor();
        fflush(stdin);
        ch = getch();
        num1 = 0,num2 = 0,num3 = 0;
        switch(ch)
        {
        case '0':
            goto Sta;
            break;
        case '1':
            printf ("\t\t\t\t*ƽ���ɼ�����*\n\n\t\t\t\tƽ���ɼ���90�ּ����ϵ��˷ֱ��ǣ���������ʿ��:\n");
            printf ("\t\t\t\tѧ��----------����-----------�ɼ�\n");
            while (p && p->TotalGrade >= 90)
            {
                printf ("\n\t\t\t\t%-15s%-15s%.1f",p->sn2,p->name2,p->TotalGrade);
                num1++;
                num2++;
                p = p->Next;
            }
            if (num1 == 0)  printf("\t\t\t\t���İ�û��������ʿ��");
            printf ("\n\n\t\t\t\tƽ���ɼ���60�����µ��˷ֱ��ǣ��ҿ���ʿ��:\n");
            printf ("\t\t\t\tѧ��----------����-----------�ɼ�\n");
            while (p)
            {
                if (p->TotalGrade < 60)
                {
                    printf ("\n\t\t\t\t%-15s%-15s%.1f",p->sn2,p->name2,p->TotalGrade);
                    num3++;
                }
                else num2++;
                p = p->Next;
            }
            if (num3 == 0)printf("\t\t\t\t���İ�û�йҿ���ʿ��");
            if (num2+num3 != 0)
                printf ("\n\n\t\t\t\t����ֲ�:\n\t\t\t\t60�����¹���%.0f�ˣ�ռ��%.1f%%��\n\n\t\t\t\t60�����Ϲ���%.0f�ˣ�ռ��%.1f%%��\n\n\t\t\t\t����90�����Ϲ���%.0f��,ռ��%.1f%%��\n\n",num3,(float)num3/(num2+num3)*100.0,num2,(float)num2/(num2+num3)*100.0,num1,(float)num1/(num2+num3)*100.0);
            else
                printf ("\n\n\t\t\t�������ݣ�");
            break;
        case '2':
            printf ("\t\t\t\t*�����ɼ�����*\n\n\t\t\t\t�����ɼ���90�ּ����ϵ��˷ֱ��ǣ���������ʿ��:\n");
            printf ("\t\t\t\tѧ��---------����----------�ɼ�\n");
            while (p1 && p1->grade1 >= 90)
            {
                printf ("\n\t\t\t\t%-15s%-15s%.1f",p1->sn2,p1->name2,p1->grade1);
                num1++;
                num2++;
                p1 = p1->Next;
            }
            if (num1 == 0)  printf("\t\t\t\t���İ�û��������ʿ��");
            printf ("\n\n\t\t\t\t�����ɼ���60�����µ��˷ֱ��ǣ��ҿ���ʿ��:\n");
            printf ("\t\t\t\tѧ��---------����----------�ɼ�\n");
            while (p1)
            {
                if (p1->grade1 < 60)
                {
                    printf ("\n\t\t\t\t%-15s%-15s%.1f",p1->sn2,p1->name2,p1->grade1);
                    num3++;
                }
                else num2++;
                p1 = p1->Next;
            }
            if (num3 == 0) printf("\t\t\t\t���İ�û�йҿ���ʿ��");
            if (num2+num3 != 0)
                printf ("\n\n\t\t\t\t����ֲ�:\n\t\t\t\t60�����¹���%.0f�ˣ�ռ��%.1f%%��\n\n\t\t\t\t60�����Ϲ���%.0f�ˣ�ռ��%.1f%%��\n\n\t\t\t\t����90�����Ϲ���%.0f��,ռ��%.1f%%��\n\n",num3,(float)num3/(num2+num3)*100.0,num2,(float)num2/(num2+num3)*100.0,num1,(float)num1/(num2+num3)*100.0);
            else
                printf ("\n\n\t\t\t\t�������ݣ�");
            break;
        case '3':
            printf ("\t\t\t\t*Ӣ��ɼ�����*\n\n\t\t\t\tӢ��ɼ���90�ּ����ϵ��˷ֱ��ǣ���������ʿ��:\n");
            printf ("\t\t\t\tѧ��---------����----------�ɼ�\n");
            while (p2 && p2->grade2 >= 90)
            {
                printf ("\n\t\t\t\t%-15s%-15s%.1f",p2->sn2,p2->name2,p2->grade2);
                num1++;
                num2++;
                p2 = p2->Next;
            }
            if (num1 == 0)  printf("\t\t\t\t���İ�û��������ʿ��");
            printf ("\n\n\t\t\t\tӢ��ɼ���60�����µ��˷ֱ��ǣ��ҿ���ʿ��:\n");
            printf ("\t\t\t\tѧ��---------����----------�ɼ�\n");
            while (p2)
            {
                if (p2->grade2 < 60)
                {
                    printf ("\n\t\t\t\t%-15s%-15s%.1f",p2->sn2,p2->name2,p2->grade2);
                    num3++;
                }
                else num2++;
                p2 = p2->Next;
            }
            if (num3 == 0) printf("\t\t\t\t���İ�û�йҿ���ʿ��");
            if (num2 + num3 != 0)
                printf ("\n\n\t\t\t\t����ֲ���\n\t\t\t\t60�����¹���%.0f�ˣ�ռ��%.1f%%��\n\n\t\t\t\t60�����Ϲ���%.0f�ˣ�ռ��%.1f%%��\n\n\t\t\t\t����90�����Ϲ���%.0f��,ռ��%.1f%%��\n\n",num3,(float)num3/(num2+num3)*100.0,num2,(float)num2/(num2+num3)*100.0,num1,(float)num1/(num2+num3)*100.0);
            else
                printf ("\n\n\t\t\t�������ݣ�");
            break;
        case '4':
            printf ("\t\t\t\t*C�ɼ�����*\n\n\t\t\t\tC�ɼ���90�ּ����ϵ��˷ֱ��ǣ���������ʿ��:\n");
            printf ("\t\t\t\tѧ��---------����----------�ɼ�\n");
            while (p3 && p3->grade3 >= 90)
            {
                printf ("\n\t\t\t\t%-15s%-15s%.1f",p3->sn2,p3->name2,p3->grade3);
                num1++;
                num2++;
                p3 = p3->Next;
            }
            if (num1 == 0)  printf("\t\t\t\t���İ�û��������ʿ��");
            printf ("\n\n\t\t\t\tC�ɼ���60�����µ��˷ֱ��ǣ��ҿ���ʿ��:\n");
            printf ("\t\t\t\tѧ��---------����----------�ɼ�\n");
            while (p3)
            {
                if (p3->grade3 < 60)
                {
                    printf ("\n\t\t\t\t%-15s%-15s%.1f",p3->sn2,p3->name2,p3->grade3);
                    num3++;
                }
                else num2++;
                p3 = p3->Next;
            }
            if (num3 == 0) printf("\t\t\t\t���İ�û�йҿ���ʿ��");
            if (num2 + num3 != 0)
                printf ("\n\n\t\t\t\t����ֲ���\n\t\t\t\t60�����¹���%.0f�ˣ�ռ��%.1f%%��\n\n\t\t\t\t60�����Ϲ���%.0f�ˣ�ռ��%.1f%%��\n\n\t\t\t\t����90�����Ϲ���%.0f��,ռ��%.1f%%��\n\n",num3,(float)num3/(num2+num3)*100.0,num2,(float)num2/(num2+num3)*100.0,num1,(float)num1/(num2+num3)*100.0);
            else
                printf ("\n\n\t\t\t�������ݣ�");
            break;
        case '5':
            return ;
        default:
            printf ("���������������������룡\n");
        }
    }
    return ;
}
void FreeAll_2(struct menu2 *h)
{
    struct menu2 *p;
    while (h)
    {
        p = h;
        h = h->Next;
        free(p);
        p = NULL;
    }
    return ;
}
