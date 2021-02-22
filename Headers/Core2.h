#ifndef CORE2_H
#define CORE2_H
/*这个头文件里存储着与系统二相关的核心操作*/
struct menu2
{
    char sn2  [52];
    char name2[52];
    float grade1;
    float grade2;
    float grade3;
    float TotalGrade;
    struct menu2 *Next;
    struct menu2 *Previous;
};

void FreeAll_2(struct menu2 *h);

struct menu2* Record_2 (struct menu2 *head,char *a,char *b,float c,float d,float e,int change);

struct menu2* Seeit_2  (struct menu2 *head);

void SeeThesingle_2  (struct menu2 *head,int choice);

struct menu2* Delete_2 (struct menu2 *head,char s[]);

struct menu2* Find_2 (struct menu2 *head,int change,char c[]);

void EnterSee2(struct menu2 *mainhead,struct menu2 *head1,struct menu2 *head2,struct menu2 *head3);

struct menu2* Change_2 (struct menu2 *head , int choice ,char sn[],char s[] , float grade);

void CordReport_2(struct menu2 *mainhead,struct menu2 *head1,struct menu2 *head2,struct menu2 *head3);
#endif // CORE2_H
