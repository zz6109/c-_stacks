#ifndef LIST_H // 중복 전처리 방지
#define LIST_H

class Node
{
friend class List;

private:
    int data;
    Node &next;

    Node(int data, Node *next);
    ~Node();

    Node(const Node& rhs);
    Node& operator=(const Node& rhs);
public:

};

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
