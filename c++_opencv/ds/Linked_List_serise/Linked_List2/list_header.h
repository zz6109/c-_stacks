#ifndef LIST_H // 중복 전처리 방지
#define LIST_H

// 구조체에 구조체를 저장함
typedef struct node     // 메인 노드(두번째 노드 부터)
{
    int data;           // 노드 데이터
    struct node *next;  // 노드 주소 값
}Node;

typedef struct          // 더미 노드(첫번째 노드)
{
    Node *ptr;          // 노드 주소값
}List;

void initList(List *pList);
void cleanupList(List *pList);

void insertFirstNode(List *pList, int data);
void insertNode(List *pList, int prevData, int data);
void deleteNode(List *pList, int data);

void printList(List *pList); 

#endif  
