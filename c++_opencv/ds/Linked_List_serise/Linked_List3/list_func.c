#include "list_header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

static Node *createNode(int data, Node *next)   // 여기서만 사용가능 메인에서 접근 불가
{
    Node *p = malloc(sizeof(Node));
    assert(p ); // NULL이 아니면 생략으로 p하고 한칸띄어줌
    p->data = data;
    p->next = next;

    return p;
}

void initList(List *pList)
{
    // (*pList).ptr = malloc(sizeof(Node));    // dummy
    
    pList->ptr = createNode(-1, NULL);
    
}

void cleanupList(List *pList)   // heep 영역 초기화
{
    Node *p = pList->ptr;
    

    while (p )  
    {
        Node *tmp = p;

        p = p->next;
        free(tmp);
    }
    
}

void insertFirstNode(List *pList, int data)
{
    // Node *p = malloc(sizeof(Node));
    
    // (*p).data = data;
    
    // (*p).next = pList->ptr->next;
    
    // pList->ptr->next = p;

    pList->ptr->next = createNode(data, pList->ptr->next);
    
}

void insertNode(List *pList, int prevData, int data)
{
    Node *ptr = pList->ptr->next;
    
    while (ptr ) 
    {
        if (ptr->data == prevData) 
        {
            break;
        }
        ptr = (*ptr).next;         
    }
    if (ptr)    
    {
        // Node *p = malloc(sizeof(Node)); 
        
        // (*p).data = data;               
        // (*p).next = (*ptr).next;
        
        // (*ptr).next = p;
        ptr->next = createNode(data, ptr->next);
    }
}

void deleteNode(List *pList, int data)
{
    Node *ptr1 = pList->ptr->next;
    Node *ptr2 = pList->ptr;

    while (ptr1)
    {
        if (ptr1->data == data)
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

void printList(List *pList)
{
    Node *p = pList->ptr->next;
    printf("[");
    while (p)
    {
        printf("%d", p->data);
        printf( (p->next) ? "," : "]\n");
        
        p = p->next;
    }
    
}
