#ifndef LIST_H // 중복 전처리 방지
#define LIST_H
/*
// 구조체에 구조체를 저장함
typedef struct node     // 메인 노드(두번째 노드 부터)
{
    void *pData; 
    struct node *next;  // 노드 주소 값
}Node;
*/
typedef struct node
{
    struct node *next;
}Node;

typedef struct          // 더미 노드(첫번째 노드)
{
    Node *ptr;          // 노드 주소값
    int eleSize;
}List;

void initList(List *pList, int eleSize);
void cleanupList(List *pList);

void insertFirstNode(List *pList, const void *pData);
void insertNode(List *pList, const void *pPrevData, const void *pData);
void deleteNode(List *pList, const void *pData);

void printList(const List *pList, void (*print)(const void *)); 

#endif  
