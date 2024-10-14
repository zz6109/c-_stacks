#include "list.h"
#include <iostream>


List::List()
{
    // (*this).ptr = (int*)malloc(sizeof(Node));    // dummy
    this->ptr = new Node;
    // List 구조체의 노드 주소 값을 8바이트로 할당
    this->ptr->next = NULL;
    // List 구조체가 가리키고 있는 첫번째 노드의 다음 노드에 NULL할당
}

List::~List()   // heep 영역 초기화
{
    Node *p = this->ptr;
    // List 구조체가 가리키고 있는 노드 주소 값을 포인터 p에 대입

    while (p )  // p가 NULL이 될때 까지
    {
        Node *tmp = p;
        // p를 tmp에 대입 
        p = p->next;
        // 다음 노드 주소 값을 p에 대입
        delete(tmp);
        // 저장된 p(Node *tmp)의 주소 값을 free 시킴
    }
    
}

void List::insertFirstNode(int data)
{
    // Node *p = malloc(sizeof(Node));
    Node *p = new Node();
    // 포인터 p에 8바이트 메모리 할당(p는 첫번째 노드다)
    (*p).data = data;
    // 입력 값을 노드 데이터에 저장
    (*p).next = this->ptr->next;
    // List 구조체가 가리키고 있는 첫번째 노드의 다음 노드(두번째 노드)의 할당된 메모리 주소 값을 두번째 노드에 저장 
    this->ptr->next = p;
    // List 구조체가 가리키고 있는 첫번째 노드의 다음 노드(두번째 노드)에 p(할당된 메모리 주소)값을 저장
}

void List::insertNode(int prevData, int data)
{
    Node *ptr = this->ptr->next;
    // 현재 노드 주소를 ptr에 대입
    while (ptr ) // ptr이 NULL이 될때 까지
    {
        if (ptr->data == prevData)  // 현재 노드의 데이터와 prevData가 같을 경우
        {
            break;
        }
        ptr = (*ptr).next;          // 다음 노드의 주소 값을 ptr에 대입
    }
    if (ptr)    // ptr 이 NULL이 아니면
    {
        // Node *p = malloc(sizeof(Node)); 
        Node *p = new Node();
        // 새 노드를 동적 할당
        (*p).data = data;               
        // 새 노드의 데이터에 저장
        (*p).next = (*ptr).next;
        // 새 노드의 다음 주소를 현재 노드의 다음 주소로 설정
        (*ptr).next = p;
        // 현재 노드의 다음 주소를 새 노드 주소로 설정
    }
}

void List::deleteNode(int data)
{
    Node *ptr1 = this->ptr->next;
    Node *ptr2 = this->ptr;

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

void List::printList()
{
    Node *ptr = this->ptr->next;
    std::cout << "[";
    while (ptr)
    {
        std::cout << ptr->data << ((ptr->next) ? ", " : "]");
        ptr = ptr->next;
    }
    std::cout << std::endl;
    
}
