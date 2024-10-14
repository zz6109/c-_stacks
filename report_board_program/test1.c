#include <stdio.h>
#include "report_program_struct.h"
// 인터페이스에서 메뉴에 들어 갔다가 메인 화면으로 다시 나올수 있는 프로그램 짜보기
// 전역변수
struct system code;

void print_ui(void);
void select_ui(void);

int main(void)
{

    code.exit = 0;

    while (code.exit >= 0)
    {
        print_ui();
        printf("1,2 중에 입력해주세요.\n");
        select_ui();
    }
}

void print_ui(void)
{
    printf("-------------------------------------------------------------\n");
    printf("                성적 입출력 및 평균산출 프로그램\n");
    printf("-------------------------------------------------------------\n");
    printf("\n\n");
    printf("    1. 입력된 학생 정보 확인\n");
    printf("\n");
    printf("    2. 프로그램 종료\n");
    printf("\n");
    printf("-------------------------------------------------------------\n");
}

void select_ui(void)
{
    int input;
    scanf("%d", &input);
    getchar();
    if (input = 1)
    {
        while (code.exit = 0)
        {
            printf("입력된 학생의 정보는 ?개 입니다.\n 정보를 조회하시려면 학생의 번호를 입력해주세요.\n 메인 메뉴로 나가시려면 ctrl+d를 입력해주세요.\n");
            scanf("%d", &input);
            if (input = EOF)
            {
                code.exit = 1;
                break;
            }
            else if (input = 1)
            {
                printf("1번 학생의 정보를 조회합니다.\n");
            }
        }
    }
    else if (input = 2)
    {
        printf("프로그램을 종료합니다.\n");
        code.exit = -1;
        
    }
    else
    {
        printf("1과 2중에서만 입력해주세요.\n");
    }
}