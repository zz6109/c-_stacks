#include <stdio.h>
//#include <stdlib.h>

// 함수 선언
void showMainMenu();
void menu1();
void menu2();

int main() {
    int choice;
    int exit = 0;

    while (!exit) {
        showMainMenu();
        printf("Please select an option: ");
        scanf("%d", &choice);
        getchar();  // 버퍼 비우기

        if (choice == 1) {
            menu1();
        } else if (choice == 2) {
            menu2();
        } else if (choice == 3) {
            exit = 1;
        } else {
            printf("Invalid choice. Please select again.\n");
        }
    }

    printf("Exiting program. Goodbye!\n");
    return 0;
}

// 메인 메뉴 표시 함수
void showMainMenu() {
    printf("\nMain Menu\n");
    printf("1. Menu 1\n");
    printf("2. Menu 2\n");
    printf("3. Exit\n");
}

// 메뉴 1 함수
void menu1() {
    printf("You are in Menu 1\n");
    printf("Press Enter to return to the main menu...\n");
    //getchar();  // 엔터 키 대기
}

// 메뉴 2 함수
void menu2() {
    printf("You are in Menu 2\n");
    printf("Press Enter to return to the main menu...\n");
    getchar();  // 엔터 키 대기
}
