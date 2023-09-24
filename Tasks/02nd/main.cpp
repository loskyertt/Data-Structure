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
Node *reverseList(Node *head, int index)
{
    Node *pre = nullptr;
    Node *cur = head->next;

    // 遍历index个节点
    for (int i = 0; i < index; i++)
    {
        // 保存下一节点指针
        Node *temp = cur->next;
        // 反转指针
        cur->next = pre;
        // 更新pre、cur指针
        pre = cur;
        cur = temp;
    }
    // 反转后,pre指向新的头节点
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
    Node *h2 = reverseList(h1, 5);
    cout << "h2链表（逆序后）：";
    printList(h2);

    return 0;
}