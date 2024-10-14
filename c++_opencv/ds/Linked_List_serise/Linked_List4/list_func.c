#include "list_header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

void initList(List *pList, int eleSize)
{
    (*pList).ptr = malloc(sizeof(Node)/* + eleSize*/);    // dummy  노드는 데이터 저장공간 x
    // List 구조체의 노드 주소 값을 8바이트로 할당
    assert(pList->ptr );
    pList->ptr->next = NULL;
    pList->eleSize = eleSize;
    // List 구조체가 가리키고 있는 첫번째 노드의 다음 노드에 NULL할당
}

void cleanupList(List *pList)   // heep 영역 초기화
{
    Node *p = pList->ptr;
    // List 구조체가 가리키고 있는 노드 주소 값을 포인터 p에 대입

    while (p )  // p가 NULL이 될때 까지
    {
        Node *tmp = p;
        // p를 tmp에 대입 
        p = p->next;
        // 다음 노드 주소 값을 p에 대입
        free(tmp);
        // 저장된 p(Node *tmp)의 주소 값을 free 시킴
    }
    
}

void insertFirstNode(List *pList, const void *pData)
{
    Node *p = malloc(sizeof(Node)+ pList->eleSize); // 변경됨
    assert(pList->ptr );
    // (*p).data = data;
    memcpy(p+1, pData, pList->eleSize); // 추가됨

    (*p).next = pList->ptr->next;
 
    pList->ptr->next = p;
}

void insertNode(List *pList, const void *pPrevData, const void *pData)
{
    Node *ptr = pList->ptr->next;
    // 현재 노드 주소를 ptr에 대입
    while (ptr ) // ptr이 NULL이 될때 까지
    {
        if (memcmp(ptr+1, pPrevData, pList->eleSize) == 0)  // 현재 노드의 데이터와 prevData가 같을 경우, 변경됨
        {
            break;
        }
        ptr = (*ptr).next;          // 다음 노드의 주소 값을 ptr에 대입
    }
    if (ptr)    // ptr 이 NULL이 아니면
    {
        Node *p = malloc(sizeof(Node)+ pList->eleSize); 
        assert(p );
        // (*p).data = data;               
        memcpy(p+1, pData, pList->eleSize); // 추가됨
        (*p).next = (*ptr).next;

        (*ptr).next = p;

    }
}

void deleteNode(List *pList, const void *pData)
{
    Node *ptr1 = pList->ptr->next;
    Node *ptr2 = pList->ptr;

    while (ptr1)
    {
        if (memcmp(ptr1+1, pData, pList->eleSize) == 0) // 변경됨
        {
            break;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

    }
    if (ptr1)
    {
        ptr2->next = ptr1->next;
        free(ptr1);
    }
    
}

void printList(const List *pList, void (*print)(const void *))
{
    Node *p = pList->ptr->next;
    printf("[");
    while (p)
    {
        // printf("%d,", p->data);
        (*print)(p+1);      // print(p+1);
        printf((p->next) ? "," : "]\n");
        p = p->next;
    }
    
}
