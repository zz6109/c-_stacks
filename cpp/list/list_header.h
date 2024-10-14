#ifndef LIST_H // 중복 전처리 방지
#define LIST_H

// 구조체에 구조체를 저장함
// struct Node // 메인 노드(두번째 노드 부터)
// {
//     int data;          // 노드 데이터
//     struct Node *next; // 노드 주소 값
// };

class List // 더미 노드(첫번째 노드)
{
     class Node // 메인 노드(두번째 노드 부터)
    {
    public:
        int data;          // 노드 데이터
        Node *next; // 노드 주소 값
    };
    
private:

    Node *ptr; 

public:
    List();
    ~List();

    void insertFirstNode(int data);
    void insertNode(int prevData, int data);
    void deleteNode(int data);

    void printList();

};

#endif
