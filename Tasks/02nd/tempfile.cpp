#include <iostream>

using namespace std;

struct Node
{
    Node *next;
    int data;
};

// 尾插法创建链表
Node *createList(int *arr, int size)
{
    Node *head = new Node();
    head->next = nullptr;
    for (int i = 0; i < size; i++)
    {
        Node *temp = new Node();
        temp->data = arr[i];
        temp->next = head->next;
        head->next = temp;
    }

    return head;
}

// 反转链表
Node *reverseList(Node *head)
{
    Node *pre = nullptr;
    Node *cur = head->next;
    while (cur)
    {
        Node *temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    head->next = pre;

    return head;
}

// 打印链表
void printList(Node *head)
{
    Node *current = head->next;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    Node *h1 = createList(arr, 5); // 原链表
    cout << "h1链表（原链表）：";
    printList(h1);
    Node *h2 = reverseList(h1);
    cout << "h2链表（现链表）：";
    printList(h2);

    return 0;
}