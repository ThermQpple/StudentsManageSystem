#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
float Calculate (char *s, int m) //����
{
    int i, len = strlen (s);
    float sum = 0, sum1 = 0;
    static bool flag = false;

    for (i = 0; i < m; i++)
    {
        if (s[i] == '-')
        {
            flag = true;
            continue;
        }
        sum = sum*10 + (int)s[i] - '0';
    }

    for (i = len-1; i > m; i--)
    {
        sum1 = (float)sum1/10.0 +  (int)s[i] - '0';
    }

    if (flag)
        return (float) -(sum + sum1/10.0);

    else
        return (float)  (sum + sum1/10.0);
}

float inputlnt (float min,float max)
{
    char ch, ret[1024];
    int len, k = 0, book = 0, m = -1;
    float rax;

Start_Top:
    while (ch = getch(), ch != '\r') //ֻ��������'-','.'��������
    {
        if (ch == '-' && k == 0)
        {
            putchar (ch);
            ret[k++] = ch;
            ret[k] = '\0';
        }

        else if (ch == '\b')
        {
            if (k == 0)
                continue;
            printf ("\b \b");
            k--;
            ret[k] = '\0';
        }

        else if (ch == '.' && book != 1)
        {
            book = 1;
            putchar (ch);
            ret[k++] = ch;
            ret[k] = '\0';
        }

        else if (ch >= '0' && ch <= '9')
        {
            putchar (ch);
            ret[k++] = ch;
            ret[k] = '\0';
        }

        else
            MessageBox(NULL,TEXT("���淶������"),TEXT("�������"),0);
    }
    m = strlen(ret);
    for (int i=0; i<strlen(ret); i++)
    {
        if (ret[i] == '.')
            m = i;
    }
    //���û��С���㣬��m��Ϊlen����֤���㺯������ȷ��
    rax = Calculate(ret,m);
    if (rax < min || rax > max)
    {
        MessageBox(NULL,TEXT("����������ַ�Χ��������������"),TEXT("�������"),0);
        goto Start_Top;//����
    }
    printf ("\n");
    fflush(stdin);
    return rax;
}


char* inputString(char *buffer, unsigned int bufferLen)
{
    char ch;
    int k = 0;
TOP_:
    while (ch = getch(), ch != '\r')
    {
        if (k >= bufferLen-1 && ch != '\b')
        {
            MessageBox (NULL,TEXT("�������ַ��������Ѵ����ޣ��޷��������롣����"),TEXT("overbuffer!"),0);
            fflush(stdin);
            continue;
        }
        if (ch < 0 || ch > 127)
        {
            if (k == bufferLen - 2)
            {
                MessageBox (NULL,TEXT("�������ַ��������Ѵ����ޣ��޷��������롣����"),TEXT("overbuffer!"),0);
                fflush(stdin);
                continue;
            }
            char gh = getch();
            printf ("%c%c",ch,gh);
            fflush(stdin);
            buffer[k++] = ch;
            buffer[k++] = gh;
            buffer[k] = '\0';
        }
        else if (ch == '\b')
        {
            if (k >= 2 && (buffer[k-1] < 0 || buffer[k-1] > 127) )
            {
                k -= 2;
                printf ("\b\b  \b\b");
                buffer[k] = '\0';
            }
            else if (k>0)
            {
                k--;
                printf ("\b \b");
                buffer[k] = '\0';
            }
        }
        else if (ch != '\t')
        {
            buffer[k++] = ch;
            putchar(ch);
            buffer[k] = '\0';
        }
    }
    if (k == 0)
    {
        MessageBox (NULL,TEXT("����δ���룡"),TEXT("!"),0);
        goto TOP_;
    }
    printf ("\n");
    fflush(stdin);
    return buffer;
}
char* enterspring (char *buf , int c)//c��һ����Ϊ�˺����룬����Ϊ�������룬�����*
{
    char ch;
    int k = 0;
    START_:
    while (ch = getch(),ch != '\r')
    {
        if (k>17)
        {
            MessageBox (NULL,TEXT("�������ַ��������Ѵ����ޣ��޷��������롣����"),TEXT("overbuffer!"),0);
            fflush(stdin);
            continue;
        }
        if (ch == '\b' && k > 0)
        {
            k--;
            printf ("\b \b");
            buf[k] = '\0';
        }
        else if ((ch >='a' && ch <= 'z')||(ch >= 'A' && ch <='Z')||(ch >= '0' && ch <='9'))
        {
            buf[k++] = ch;
            if (c != 1)
                putchar('*');
            else
                putchar(ch);
            buf[k] = '\0';
        }
    }
    if (c == 1)
    {
        if (k == 0)
        {
            MessageBox (NULL,TEXT("����δ����..."),TEXT("!"),0);
            goto START_;
        }
    }
    else
    {
        if (k<6)
        {
            MessageBox (NULL,TEXT("��������̫����..."),TEXT("!"),0);
            goto START_;
        }
    }
    putchar('\n');
    return buf;
}













