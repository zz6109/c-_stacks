#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int is_regular_file(const char *path);
int has_txt_extension(const char *filename);
void info_input(int file_num);
int file_exists_in_directory(void);

int main()
{
    file_exists_in_directory();
}

int file_exists_in_directory(void)
{
    DIR *dir;
    struct dirent *entry;
    int file_num = 0;
    char filename[20];
    char full_path[1024];
    const char *directory = "students_info/";

    // 디렉토리를 엽니다
    if ((dir = opendir("students_info/")) == NULL)
    {
        perror("opendir() error");
        return 0;
    }

    if ((entry = readdir(dir)) != NULL)
    {
        // 디렉토리의 각 항목을 읽습니다
        while ((entry = readdir(dir)) != NULL)
        {
            snprintf(full_path, sizeof(full_path), "%s/%s", directory, entry->d_name);
            // 일반 파일인지 확인함
            if (is_regular_file(full_path))
            {
                file_num++;
                sprintf(filename, "info%d.txt", file_num);
                if (strcmp(entry->d_name, filename) == 0)
                {
                    // 파일을 찾았음
                    info_input(1 + file_num);
                    closedir(dir);
                    return 1;
                }
            }
        }
    }
    else if ((entry = readdir(dir)) == NULL)
    {
        info_input(1);
    }

    // 디렉토리를 닫고 0을 반환합니다
    closedir(dir);
    return 0;
}

void info_input(int file_num)
{
    FILE *fp;
    int ch, i;
    char word[10][20];
    char file_title[50];
    sprintf(file_title, "students_info/info%d.txt", file_num);

    fp = fopen(file_title, "w");
    if (fp == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
    }

    for (i = 0; i < 1; i++)
    {
        printf("파일에 입력할 문자 : ");
        // scanf("%19s", &word[i]);
        if (scanf("%19s", word[i]) == EOF)
        {
            break;
        }
        fprintf(fp, "%s\n", word[i]);
    }

    fclose(fp);
}

// 특정 경로가 일반 파일인지 확인하는 함수
int is_regular_file(const char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

// 문자열이 지정된 확장자로 끝나는지 확인하는 함수
int has_txt_extension(const char *filename)
{
    const char *ext = strrchr(filename, '.');
    return ext != NULL && strcmp(ext, ".txt") == 0;
}
