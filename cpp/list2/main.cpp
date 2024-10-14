#include "list.h"

int main(void)
{
    List list;
    // list.initList();    // List 구조체 초기화

    list.insertFirstNode(4);
    list.printList();               // 4
    list.insertFirstNode(3);
    list.printList();               // 3, 4
    list.insertFirstNode(1);
    list.printList();               // 1, 3, 4

    list.insertNode(1, 2);
    list.printList();               // 1, 2, 3, 4

    list.deleteNode(3);
    list.printList();               // 1, 2, 4

    // list.cleanupList();             // empty

    return 0;
}
