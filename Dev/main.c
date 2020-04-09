#include <stdio.h>
#define MAX_NAME_LEN    20 //최대 이름 크기 정의
#define MAX_ID_LEN         30 //최대 ID 길이 정의
typedef struct _Bank Bank;//Bank 타입명 정의
struct _Bank //구조체 _Bank 정의
{
    char name[MAX_NAME_LEN];//성명
    char id[MAX_ID_LEN]; //계좌번호
    int balance; //잔액
};
 
Bank banks[3] = { 0 };//3명의 계좌를 기억할 배열 선언
 
void new_acc();//계좌 정보 입력 함수
void run();//메뉴 선택에 따라 상호 작용


int main()
{
    
    new_acc();//3명의 계좌 정보를 입력받음
    run();//메뉴 선택에 따라 상호 작용
    return 0;
}
void new_acc()
{
	printf("사용자가 없습니다 사용자 등록을 시작합니다! (3명)\n\n");
	 
    int i = 0;
    for (i = 0; i < 3; i++)//n명의 계좌 정보를 순차적으로 입력받음
    {
        printf("사용자%d의 이름:", i + 1);
        scanf_s("%s", banks[i].name);
        printf("사용자%d의 계좌:", i + 1);
        scanf_s("%s", banks[i].id);
        printf("사용자%d의 잔액:", i + 1);
        scanf_s("%d", &(banks[i].balance));
    }
}
 
int select_menu();//메뉴 선택
void show_balance();//잔액 조회
void save();//입금
void draw();//출금
void view_list();//사용자 정보 출 
void run()
{
    int key = 0;
    while ((key = select_menu()) != 5)//선택한 메뉴가 4가 아니면 반복
    {
        switch (key)//선택한 키에 따라 수행
        {
        case 1: show_balance(); break;//1일 때 조회
        case 2: save(); break; //2일 때 입금
        case 3: draw(); break; //2일 때 출금
        case 4: view_list(); break; 
        default: printf("잘못된 숫자를 입력하셨습니다.\n"); break;//잘못 선택
        }
    }
}

void  view_list()
{
    int i = 0;
    for (i = 0; i < 3; i++)//n명의 계좌 정보를 순차적으로 입력받음
    {
        printf("\n사용자%d의 이름:%s\n", i+1,banks[i].name);
        printf("사용자%d의 계좌:%s\n", i + 1,banks[i].id);
        printf("사용자%d의 잔액:%d\n", i + 1,banks[i].balance);
    }
}
 
int select_menu()
{
    int key = 0;
    printf("메뉴를 선택하세요.<잔액조회(1), 저축(2), 인출(3),사용자 정보출력(4),종료(5)>:");    
    scanf_s("%d", &key);
    return key;
}
void show_balance()
{
    int num = 0;
    printf("사용자 번호를 선택하세요(1~3):");
    scanf_s("%d", &num);
    if ((num < 1) || (num>3))//유효하지 않은 번호일 때
    {
        printf("잘못 선택하였습니다.\n");
        return;
    }
    //계좌 정보 출력
    printf("%s님의 계좌번호 : %s입니다.\n", banks[num - 1].name, banks[num - 1].id);
    printf("%s님의 현재 잔약 : %d원 입니다.\n", banks[num - 1].name, banks[num - 1].balance);
}
void save()
{
    int num = 0;
    int value=0;
    printf("사용자 번호를 선택하세요(1~3):");
    scanf_s("%d", &num);
    if ((num < 1) || (num>3))//유효하지 않은 번호일 때
    {
        printf("잘못 선택하였습니다.\n");
        return;
    }
    
    printf("%s님의 저축 금액 입력:", banks[num - 1].name);
    scanf_s("%d", &value);
    banks[num - 1].balance += value;//저축 금액을 잔고에 더함
}
void draw()
{
    int num = 0;
    int value = 0;
    printf("사용자 번호를 선택하세요(1~3):");
    scanf_s("%d", &num);
    if ((num < 1) || (num>3))//유효하지 않은 번호일 때
    {
        printf("잘못 선택하였습니다.\n");
        return;
    }
 
    printf("%s님의 인출 금액 입력:", banks[num - 1].name);
    scanf_s("%d", &value);
    if (value > banks[num - 1].balance)//잔액보다 인출 요청 금액이 클 때
    {
        printf("잔액이 부족합니다.\n");    
    }
    else
    {
        banks[num - 1].balance -= value;//잔고에서 인출 금액을 뺌
    }
}
