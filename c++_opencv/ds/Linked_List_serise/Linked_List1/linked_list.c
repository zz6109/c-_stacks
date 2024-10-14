#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List

typedef struct node
{
    int data;          // 데이터 값
    struct node *next; // 노드 포인터
} Node;

int main(void)
{
    Node *ptr;
    ptr = malloc(sizeof(Node)); // 구조체의 주소 저장

    (*ptr).data = 1;
    (*ptr).next = malloc(sizeof(Node));

    (*ptr).next->data = 3;
    (*ptr).next->next = malloc(sizeof(Node));

    (*ptr).next->next->data = 4;
    (*ptr).next->next->next = NULL;

    // 삽입
    {
        Node *p;
        p = malloc(sizeof(Node));
        (*p).data = 2;
        (*p).next = (*ptr).next;
        (*ptr).next = p;
    }

    // 삭제
    {
        Node *p;
        p = ptr->next->next;
        ptr->next->next = p->next;
        free(p);

    }

    // 값 출력
    {
        Node *p;
        p = ptr;
        while (p != NULL)
        {
            printf("%d", (*p).data);
            p = (*p).next;
        }
        printf("\n");
        return 0;
    }

    // 노드 삭제
    {
        Node *p;
        p = ptr;
        while (p)
        {
            Node *tmp = p;
            p = (*p).next;
            free(tmp);
        }
    }
    return 0;
}
