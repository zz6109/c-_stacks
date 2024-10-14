#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int is_regular_file(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

int count_files_in_directory(const char *directory) {
    DIR *dir;
    struct dirent *entry;
    int file_count = 0;
    char full_path[1024];

    // 디렉토리를 엽니다
    if ((dir = opendir(directory)) == NULL) {
        perror("opendir() error");
        return -1;
    }

    // 디렉토리의 각 항목을 읽습니다
    while ((entry = readdir(dir)) != NULL) {
        // 현재 디렉토리와 상위 디렉토리를 제외합니다
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // 전체 경로를 만듭니다
        snprintf(full_path, sizeof(full_path), "%s/%s", directory, entry->d_name);

        // 일반 파일인지 확인합니다
        if (is_regular_file(full_path)) {
            file_count++;
        }
    }

    if ((entry = readdir(dir)) == NULL)
    {
        
    }
    

    // 디렉토리를 닫습니다
    closedir(dir);
    return file_count;
}

int main() {
    const char *directory = "."; // 현재 디렉토리

    int count = count_files_in_directory(directory);
    if (count >= 0) {
        printf("디렉토리 '%s'에 파일이 %d개 있습니다.\n", directory, count);
    } else {
        printf("디렉토리 '%s'를 열 수 없습니다.\n", directory);
    }

    return 0;
}
