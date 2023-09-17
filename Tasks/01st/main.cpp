#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

// 创建带附加头结点的非递减有序单链表
Node *createList(int arr[], int n)
{
    Node *head = new Node(); // 头结点
    head->next = nullptr;
    for (int i = 0; i < n; i++)
    {
        Node *p = new Node();
        p->data = arr[i];
        p->next = head->next; // 插入到头结点之后
        head->next = p;       // 更新头结点的指针域
    }
    return head;
}

// 合并两个有序链表为一个非递增有序链表
Node *mergeList(Node *ha, Node *hb)
{
    Node *hc = new Node(); // 创建c链表的头结点
    hc->next = nullptr;
    Node *pa = ha->next;
    Node *pb = hb->next;
    while (pa && pb)
    {
        if (pa->data <= pb->data)
        {
            ha->next = pa->next; // 将pa从ha中摘下来
            pa->next = hc->next;
            hc->next = pa;
            pa = ha->next;
        }
        else
        {
            hb->next = pb->next; // 将pb从hb中摘下来
            pb->next = hc->next;
            hc->next = pb;
            pb = hb->next;
        }
    }
    if (pa)
    {
        ha->next = nullptr; // 断开ha与其余结点的连接
        while (pa)
        {
            Node *q = pa->next; // 保存pa的下一个结点
            pa->next = hc->next;
            hc->next = pa;
            pa = q;
        }
    }
    if (pb)
    {
        hb->next = nullptr; // 断开hb与其余结点的连接
        while (pb)
        {
            Node *q = pb->next; // 保存pb的下一个结点
            pb->next = hc->next;
            hc->next = pb;
            pb = q;
        }
    }
    return hc;
}

// 打印链表
void printList(Node *head)
{
    Node *p = head->next; // 跳过头节点
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 测试代码
int main()
{
    int arr_a[] = {9, 7, 5, 3, 3, 2, 1};
    int arr_b[] = {10, 8, 8, 6, 4, 2};
    Node *ha = createList(arr_a, 7);
    Node *hb = createList(arr_b, 6);
    cout << "ha: ";
    printList(ha);
    cout << "hb: ";
    printList(hb);

    Node *hc = mergeList(ha, hb);
    cout << "hc: ";
    printList(hc);

    return 0;
}
