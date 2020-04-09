#include <stdio.h>
#define MAX_NAME_LEN    20 //�ִ� �̸� ũ�� ����
#define MAX_ID_LEN         30 //�ִ� ID ���� ����
typedef struct _Bank Bank;//Bank Ÿ�Ը� ����
struct _Bank //����ü _Bank ����
{
    char name[MAX_NAME_LEN];//����
    char id[MAX_ID_LEN]; //���¹�ȣ
    int balance; //�ܾ�
};
 
Bank banks[3] = { 0 };//3���� ���¸� ����� �迭 ����
 
void new_acc();//���� ���� �Է� �Լ�
void run();//�޴� ���ÿ� ���� ��ȣ �ۿ�


int main()
{
    
    new_acc();//3���� ���� ������ �Է¹���
    run();//�޴� ���ÿ� ���� ��ȣ �ۿ�
    return 0;
}
void new_acc()
{
	printf("����ڰ� �����ϴ� ����� ����� �����մϴ�! (3��)\n\n");
	 
    int i = 0;
    for (i = 0; i < 3; i++)//n���� ���� ������ ���������� �Է¹���
    {
        printf("�����%d�� �̸�:", i + 1);
        scanf_s("%s", banks[i].name);
        printf("�����%d�� ����:", i + 1);
        scanf_s("%s", banks[i].id);
        printf("�����%d�� �ܾ�:", i + 1);
        scanf_s("%d", &(banks[i].balance));
    }
}
 
int select_menu();//�޴� ����
void show_balance();//�ܾ� ��ȸ
void save();//�Ա�
void draw();//���
void view_list();//����� ���� �� 
void run()
{
    int key = 0;
    while ((key = select_menu()) != 5)//������ �޴��� 4�� �ƴϸ� �ݺ�
    {
        switch (key)//������ Ű�� ���� ����
        {
        case 1: show_balance(); break;//1�� �� ��ȸ
        case 2: save(); break; //2�� �� �Ա�
        case 3: draw(); break; //2�� �� ���
        case 4: view_list(); break; 
        default: printf("�߸��� ���ڸ� �Է��ϼ̽��ϴ�.\n"); break;//�߸� ����
        }
    }
}

void  view_list()
{
    int i = 0;
    for (i = 0; i < 3; i++)//n���� ���� ������ ���������� �Է¹���
    {
        printf("\n�����%d�� �̸�:%s\n", i+1,banks[i].name);
        printf("�����%d�� ����:%s\n", i + 1,banks[i].id);
        printf("�����%d�� �ܾ�:%d\n", i + 1,banks[i].balance);
    }
}
 
int select_menu()
{
    int key = 0;
    printf("�޴��� �����ϼ���.<�ܾ���ȸ(1), ����(2), ����(3),����� �������(4),����(5)>:");    
    scanf_s("%d", &key);
    return key;
}
void show_balance()
{
    int num = 0;
    printf("����� ��ȣ�� �����ϼ���(1~3):");
    scanf_s("%d", &num);
    if ((num < 1) || (num>3))//��ȿ���� ���� ��ȣ�� ��
    {
        printf("�߸� �����Ͽ����ϴ�.\n");
        return;
    }
    //���� ���� ���
    printf("%s���� ���¹�ȣ : %s�Դϴ�.\n", banks[num - 1].name, banks[num - 1].id);
    printf("%s���� ���� �ܾ� : %d�� �Դϴ�.\n", banks[num - 1].name, banks[num - 1].balance);
}
void save()
{
    int num = 0;
    int value=0;
    printf("����� ��ȣ�� �����ϼ���(1~3):");
    scanf_s("%d", &num);
    if ((num < 1) || (num>3))//��ȿ���� ���� ��ȣ�� ��
    {
        printf("�߸� �����Ͽ����ϴ�.\n");
        return;
    }
    
    printf("%s���� ���� �ݾ� �Է�:", banks[num - 1].name);
    scanf_s("%d", &value);
    banks[num - 1].balance += value;//���� �ݾ��� �ܰ� ����
}
void draw()
{
    int num = 0;
    int value = 0;
    printf("����� ��ȣ�� �����ϼ���(1~3):");
    scanf_s("%d", &num);
    if ((num < 1) || (num>3))//��ȿ���� ���� ��ȣ�� ��
    {
        printf("�߸� �����Ͽ����ϴ�.\n");
        return;
    }
 
    printf("%s���� ���� �ݾ� �Է�:", banks[num - 1].name);
    scanf_s("%d", &value);
    if (value > banks[num - 1].balance)//�ܾ׺��� ���� ��û �ݾ��� Ŭ ��
    {
        printf("�ܾ��� �����մϴ�.\n");    
    }
    else
    {
        banks[num - 1].balance -= value;//�ܰ��� ���� �ݾ��� ��
    }
}
