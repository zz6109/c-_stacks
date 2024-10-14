#include "list_header.h"

int main(void)
{
    List list;
    initList(&list);    // List 구조체 초기화

    insertFirstNode(&list, 4);
    printList(&list);               // 4
    insertFirstNode(&list, 3);
    printList(&list);               // 3, 4
    insertFirstNode(&list, 1);
    printList(&list);               // 1, 3, 4

    insertNode(&list, 1, 2);
    printList(&list);               // 1, 2, 3, 4

    deleteNode(&list, 3);
    printList(&list);               // 1, 2, 4

    cleanupList(&list);             // empty

    return 0;
}
