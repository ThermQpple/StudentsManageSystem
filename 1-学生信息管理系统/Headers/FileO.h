#ifndef FILEO_H
#define FILEO_H
/*���ͷ�ļ��ﱣ���Ŵ󲿷����ļ���д�йصĺ���*/

//ȫ�ֱ��������Լ�¼�û�������ݵ��ļ���
char filebuffer1[30],filebuffer2[30];

/*�˺�-����ṹ��*/
struct Users
{
    char accounts[13];
    char password[13];
    struct Users *next;
};

int Enter(struct Users *user);//��½����

struct Users* Readuser(struct Users *user);//��ȡ�˻���Ϣ����

//struct menul* Read1 (struct menu1 *head, char filebuffer1[]);

struct Users* ChangePass(struct Users *user);//�޸����뺯��

struct Users * Register(struct Users *user);//ע�ắ��

void  StoreUser (struct Users *user);//�洢�û��˻�����

struct menu1* Store1 (struct menu1 *head);//�洢ϵͳһ������

struct menu2* Store2 (struct menu2 *head);//�洢ϵͳ��������
#endif // FILEO_H
