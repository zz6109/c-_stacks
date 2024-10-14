#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "report_program_struct.h"

// ui 출력함수
void print_ui(void);
// ui내에서 옵션 선택 함수
void ui_select(void);
// 일반파일 구분 함수
int is_regular_file(const char *path);
// 디렉토리 내 파일 갯수 세기 함수
int count_files_in_directory(const char *directory);
// 파일 입력 함수
void info_input(char *file_name);
// 시스템 코드 전역변수 선언
struct system code;

int main(void)
{
    int choice;
    code.exit = 0;
    while (code.exit == 0)
    {
        print_ui();
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
        {
            // 각 메뉴 함수 만들기
        }
        else if (choice == 2)
        {
            /* code */
        }
        else if (choice == 3)
        {
            /* code */
        }
        else if (choice == 4)
        {
            /* code */
        }
        else if (choice == 5)
        {
            /* code */
        }
        else
        {
            /* code */
        }
        
        
        
        

       
    }
}

void print_ui(void)
{
    printf("-------------------------------------------------------------\n");
    printf("                성적 입출력 및 평균산출 프로그램\n");
    printf("-------------------------------------------------------------\n");
    printf("\n\n");
    printf("    1. 학생 정보 및 성적 입력\n");
    printf("\n");
    printf("    2. 학생 정보 및 성적 목록 확인\n");
    printf("\n");
    printf("    3. 저장된 학생의 평균 성적 출력\n");
    printf("\n");
    printf("    4. 등급별 학생 확인\n");
    printf("\n");
    printf("    5. 프로그램 종료\n");
    printf("\n");
    printf("-------------------------------------------------------------\n");
}

void ui_select(void)
{
    int intput_index;
    int input;
    char file_title[20];
    int i = 1;
    const char *directory = "students_info/";
    int count = count_files_in_directory(directory);

    while (1)
    {
        scanf("%d", &intput_index);
        if (intput_index == 1)
        {
            printf("학생의 정보를 입력해주세요.\n");
            char filename[256];
            if (count == 0)
            {
                snprintf(filename, sizeof(filename), "students_info/info1.txt");
            }
            else
            {
                snprintf(filename, sizeof(filename), "students_info/info%d.txt", count + 1);
            }

            info_input(filename);

            printf("메인 메뉴로 나가시려면 ctrl+d를 입력해주세요.");
            scanf("%d", &input);
            if (input == EOF)
            {
                break;
            }
        }
        else if (intput_index == 2)
        {
            printf("저장된 학생들의 전체목록\n");
            break;
        }
        else if (intput_index == 3)
        {
            printf("학생의 이름이나 학번을 입력해주세요.\n");
            break;
        }
        else if (intput_index == 4)
        {
            printf("등급을 입력해주세요.(A, B, C, D, F)\n");
            break;
        }
        else if (intput_index == 5)
        {
            printf("프로그램을 종료합니다.\n");
            code.exit = 1;
            break;
        }
        else
        {
            printf("1~5까지의 정수만을 입력해주세요\n");
        }
    }
}

int is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

int count_files_in_directory(const char *directory)
{
    DIR *dir;
    struct dirent *entry;
    struct files cnt;
    cnt.file_count = 0;
    char full_path[1024];

    if ((dir = opendir(directory)) == NULL)
    {
        perror("opendir() error");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", directory, entry->d_name);

        if (is_regular_file(full_path))
        {
            cnt.file_count++;
        }
    }

    closedir(dir);
    return cnt.file_count;
}

void info_input(char *file_name)
{
    FILE *fp;
    int ch, i;
    char word[10][20];
    struct students_info info;

    fp = fopen(file_name, "w");
    if (fp == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
    }

    printf("학번, 이름을 입력해주세요: ");
    scanf("%d%s", &info.student_num, info.student_name);

    printf("국어, 영어, 수학, 사회, 과학 점수를 입력해주세요: ");
    scanf("%d%d%d%d%d", &info.kor_score, &info.eng_score, &info.mth_score, &info.soc_score, &info.sci_score);

    info.total_score = info.kor_score + info.eng_score + info.mth_score + info.soc_score + info.sci_score;
    info.avg_score = info.total_score / 5;
    if (info.avg_score >= 90)
    {
        info.rank = 'A';
    }
    else if (info.avg_score >= 80)
    {
        info.rank = 'B';
    }
    else if (info.avg_score >= 70)
    {
        info.rank = 'C';
    }
    else if (info.avg_score >= 60)
    {
        info.rank = 'D';
    }
    else
    {
        info.rank = 'F';
    }

    fprintf(fp, "%5d%5s\n%3d%3d%3d%3d%3d\n%5c\n", info.student_num, info.student_name, info.kor_score, info.eng_score, info.mth_score, info.soc_score, info.sci_score, info.rank);

    fclose(fp);
}
