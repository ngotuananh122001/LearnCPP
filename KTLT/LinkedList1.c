#include <iostream>
using namespace std;

// ref, now is node pointer
typedef struct node* ref;

// Loại cấu trúc tự trỏ
// bên trong nó chứa, một con trỏ, chỉ
// tới phần tử có cấu trúc tương tự
struct node {
    int key;
    ref next;
};

// @create a node with input value: k
// @return address of new node
ref getNode(int k) {
    ref p = new node;
    if (!p) {
        cout << "Error, memory!";
        exit(0);
    }
    p->key = k;
    p->next = nullptr;
    return p;
}

/* @add node in first pos of link-listed
*  @return: void
*  @nhận 2 tham chiếu tới head và tail để câp nhật chúng
    khi có node mới được tạo ra
*/
void addFirst(ref &head, ref &tail, int k) {
    ref p = getNode(k);

    if (head==nullptr) {
        head = tail = p;
    } else {
        p->next = head;
        head = p;
    }
}

/* @add node in last pos of link-listed
*  @return: void
*  @nhận 2 tham chiếu tới head và tail để câp nhật chúng
    khi có node mới được tạo ra
*/
void addLast(ref &head, ref &tail, int k) {
    ref p = getNode(k);
    if (head == nullptr) {
        head = tail = p;
    } else {
        tail->next = p;
        tail = p;
    }
}

/* @Thêm node vào trước vị trí chỉ bởi con trỏ q trong danh sách
     với O(1)
*  @return: void
*  @
   @
*/
void addBefore(ref q, int k) {
    ref p = new node;
    if (p == nullptr) {
        cout << "Not enough memory";
        exit(0);
    }

    *p = *q;
    q->key = k;
    q->next = p;
}

/*  @Duyet danh sach
*/
void printList(ref head) {
    ref p;
    if (head==nullptr) {
        cout << "Danh sach rong" << endl;
        return;
    }

    for (p=head; p; p = p->next) {
        cout << p->key << " ";
    }
    cout << endl;
}

/*  @Xoa phan tu dau tien cua danh sach
`   @
*/
void delFirst(ref &head, ref &tail) {
    if (head == nullptr) return;

    // co duy nhat mot phan tu (khac null)
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }

    ref p = head;
    head = head->next;
    delete p;
}

/* @Xoa phan tu cuoi danh sach */
void delLast(ref &head, ref &tail) {
    // Có 0 phần tử
    if (head == nullptr)
        return;

    // Có 1 phần tử
    if(head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }

    // Có từ 2 phần tử trở lên
    // find the second last node
    ref p = head;
    for (; p->next != tail; p = p->next);
    // now, p is second last node
    delete tail;
    p->next = nullptr;
    tail = p;
}

/*  Destroy a link-listed
*/
void destroyList(ref &head, ref &tail) {
    ref p;
    while (head) {
        p = head;
        head = head->next;
        delete p;
    }

    tail = nullptr;
}

int main() {
    ref head = nullptr, tail = nullptr;

    int k;
    // take input untill receive 0 value
    while (1) {
        cout << "Enter a integer number (0 to quit): ";
        cin >> k;
        if (k == 0) break;
        addFirst(head, tail, k);
    }

    cout << "Danh sach hien tai: "; printList(head);

    cout << "Xoa first. "; delFirst(head,tail); printList(head);
    cout << "Xoa last. "; delLast(head,tail); printList(head);


    return 0;
}
