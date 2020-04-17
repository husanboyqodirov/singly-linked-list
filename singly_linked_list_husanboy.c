#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
    Student: 20182653 Husanboy
    Class: Data Structure and Algorithm
*/

//defining simple linked list
typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
}listNode;

//define head as the structure to indicate the beginning of the list
typedef struct {
    listNode* head;
}linkedList_h;

//empty list generation
linkedList_h* createLinkedList() {
    linkedList_h* L;
    L = (linkedList_h*)malloc(sizeof(linkedList_h));
    L->head = NULL;
    return L;
}

//insert a node in the middle
void insertNode(linkedList_h* L, listNode* pre, element x) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = x;
    if (L->head == NULL) {
        newNode->link = NULL;
        L->head = newNode;
    }
    else if (pre == NULL) {
        newNode->link = L->head;
        L->head = newNode;
    }
    else {
        newNode->link = pre->link;
        pre->link = newNode;
    }
}

//insert as first node
void insertFirstNode(linkedList_h* L, element x) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = x;
    newNode->link = L->head;
    L->head = newNode;
}

//insert as last node
void insertLastNode(linkedList_h* L, element x) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = x;
    newNode->link = NULL;
    if (L->head == NULL) {
        L->head = newNode;
    }
    else {
        listNode* temp = L->head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

//search node 
listNode* searchNode(linkedList_h* L, element x) {
    listNode* temp = L->head;

    while (temp != NULL) {
        if (temp->data == x)
            return temp;
        else {
            temp = temp->link;
        }
        return temp;
    }
}

//delete node 
void deleteNode(linkedList_h* L, listNode* p) {
    listNode* pre;
    if (L->head == NULL)
        return;
    if (p == NULL)
        return;
    if (L->head == p) {
        L->head = p->link;
        free(p);
    }
    else {
        pre = L->head;
        while (pre->link != p) {
            pre = pre->link;
            if (pre == NULL)
                return;
        }
        pre->link = p->link;
        free(p);
    }
}

//display list
void printList(linkedList_h* L) {
    listNode* p;
    printf("L = (");
    p = L->head;
    while (p != NULL) {
        printf("%d", p->data);
        p = p->link;
        if (p != NULL) printf(", ");
    }
    printf(")\n");
}

//main function, program entry point
int main()
{
    linkedList_h* L;
    listNode* p;

    L = createLinkedList();
    printf("\n(1) created an empty list\n");
    printList(L);
    getchar();

    printf("(2) inserted nodes [10], [30], [70] in the list\n");
    insertLastNode(L, 10);
    insertLastNode(L, 30);
    insertLastNode(L, 70);
    printList(L);
    getchar();

    printf("(3) searching a node [30] in the list\n");
    p = searchNode(L, 30);

    if (p == NULL)
        printf("couldn't find it\n");
    else
        printf("found [%d]\n", p->data);
    getchar();

    printf("(4) inserted a node [50] after node [30] in the list\n");
    insertNode(L, p, 50);
    printList(L);
    getchar();

    printf("(5) deleted a node [70] from the list\n");
    p = searchNode(L, 70);
    deleteNode(L, p);
    printList(L);
    getchar();

    return 0;
}
