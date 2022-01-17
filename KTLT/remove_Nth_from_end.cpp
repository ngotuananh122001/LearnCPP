#include <iostream>
using namespace std;

struct ListNode {
    int x;
    ListNode* next;

    ListNode(int _x) {
        x = _x;
    }
};


ListNode* removeNthFromEnd(ListNode* head, int n) {
        // precondition : n >= 1
        if (!head->next) {
            delete head;
            return NULL;
        }

        // Now, list has at least two elements
        ListNode* a = head;
        ListNode* b = head;
        ListNode* tmp;
        // Di chuyen b di n element
        // Do đó, sau a là vị trí của phần tử thứ n từ b trở về trước
        for (int i = 1; i <= n; i++) {
            if (b->next == NULL) {
                if (i==n) {
                    tmp = head;
                    head = head->next;
                    delete tmp;
                    return head;
                }
            }

            b = b->next;
        }

        // Cùng di chuyển a, b 1 bước cho tới khi b chạm vào phàn tử cuối
        // Khi đó sau a là vị trí phần tử thứ n từ cuối.
        while (b->next) {
            a = a->next;
            b = b->next;
        }

        // Xóa phần từ thứ N từ cuối
        tmp = a->next;
        a->next = tmp->next;
        delete tmp;

        return head;
}

void PrintList(ListNode* head) {
    while (head) {
        cout << head->x << " ";
        head = head->next;
    }
}
int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);

    ListNode* head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    cout << "Truoc khi xoa: ";
    PrintList(head);

    cout << endl;

    int n = 3;
    cout << "Sau khi xoa phan tu thu n=" << n << " tu cuoi: ";
    head = removeNthFromEnd(head,n);
    PrintList(head);


    return 0;
}
