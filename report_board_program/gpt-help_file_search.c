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

    if ((dir = opendir(directory)) == NULL) {
        perror("opendir() error");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", directory, entry->d_name);

        if (is_regular_file(full_path)) {
            file_count++;
        }
    }

    closedir(dir);
    return file_count;
}

void create_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("fopen() error");
        exit(EXIT_FAILURE);
    }
    fclose(file);
}

int main() {
    const char *directory = "students_info/";
    int count = count_files_in_directory(directory);
    if (count < 0) 
    {
        printf("디렉토리 '%s'를 열 수 없습니다.\n", directory);
        return EXIT_FAILURE;
    }

    char filename[256];
    if (count == 0) 
    {
        snprintf(filename, sizeof(filename), "students_info/info1.txt");
    } 
    else 
    {
        snprintf(filename, sizeof(filename), "students_info/info%d.txt", count + 1);
    }

    create_file(filename);
    printf("파일 '%s'이(가) 생성되었습니다.\n", filename);

    return EXIT_SUCCESS;
}
