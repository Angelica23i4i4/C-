#include <iostream>
using namespace std;

//��������� ���, �� �������� ����� ������ �� ������
struct Node {
    int value;
    struct Node* next = nullptr;
} Node;


void push(Node** head, int data) {
    Node* tmp = new Node();
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}


int pop(Node** head) {
    Node* prev = NULL;
    int val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    delete prev;
    return val;
}


Node* getByIndex(Node* head, int n) {
    int counter = 0;
    Node* tmp;
    while (counter < n && head->next != nullptr) {
        head = head->next;

        counter++;
    }
    return head;
}

Node* getLast(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    while (head->next != null) {
        head = head->next;
    }
    return head;
}

void pushBack(Node* head, int value) {.
    Node* last = getLast(head);
    Node* tmp = new Node();//(Node*)malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;
    last->next = tmp;
}

int popBack(Node** head) {
    Node* pFwd = NULL;  //������� ����
    Node* pBwd = NULL;  //���������� ����
    //�������� NULL
    if (!head) {
        exit(-1);
    }
    //������ ����
    if (!(*head)) {
        exit(-1);
    }

    pFwd = *head;
    while (pFwd->next) {
        pBwd = pFwd;
        pFwd = pFwd->next;
    }

    if (pBwd == NULL) {
        delete *head;
        *head = NULL;
    }
    else {
        delete pFwd->next;
        pBwd->next = NULL;
    }
}


void insert(Node* head, unsigned n, int val) {
    unsigned i = 0;
    Node* tmp = NULL;
    //������� ������ �������. ���� ����� �� ������� ������, �� ������� �� �����,
    //������ ������������� �� �����, ��������� ������� � �����
    while (i < n && head->next) {
        head = head->next;
        i++;
    }
    tmp = new Node()->next;
    tmp->value = val;
    //���� ��� �� ��������� �������, �� next ������������ �� ��������� ����
    if (head->next) {
        tmp->next = head->next;
        //����� �� NULL
    }
    else {
        tmp->next = NULL;
    }
    head->next = tmp;
}

int deleteNth(Node** head, int n) {
    if (n == 0) {
        return pop(head);
    }
    else {
        Node* prev = getNth(*head, n - 1);
        Node* elm = prev->next;
        int val = elm->value;

        prev->next = elm->next;
        delete elm;
        return val;
    }
}

void printLinkedList(const Node* head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void fromArray(Node** head, int* arr, size_t size) {
    size_t i = size - 1;
    if (arr == NULL || size == 0) {
        return;
    }
    do {
        push(head, arr[i]);
    } while (i-- != 0);
}


int main()
{
    Node* head = NULL;
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    //������ ������ �� �������
    fromArray(&head, arr, 10);

    printLinkedList(head);
    //��������� ���� �� ��������� 333 ����� 4-�� �������� (������ �����)
    insert(head, 4, 333);
    printLinkedList(head);

    pushBack(head, 11);
    pushBack(head, 12);
    pushBack(head, 13);
    pushBack(head, 14);
    printLinkedList(head);

    printf("%d\n", pop(&head));
    printf("%d\n", popBack(&head));

    printLinkedList(head);
    //������� ����� ������� (���������� � ����)
    deleteNth(&head, 4);
    printLinkedList(head);


    return 0;
}
