#include <iostream>
using namespace std;

struct Binarytree {
    int data;
    Binarytree *lchild;
    Binarytree *rchild;
};

typedef struct node {
    Binarytree* data; // 修改为 Binarytree* 类型
    node *next;
    int length;
} Node;

Node *stacks = NULL;

void push(Binarytree* data) {
    Node *newnode = new Node();
    newnode->data = data;
    newnode->next = stacks;
    stacks = newnode;
}

void pop() {
    if (stacks != NULL) {
        Node *temp = stacks;
        stacks = stacks->next;
        delete temp;
    }
}

void print() {
    Node *current = stacks;
    while (current != NULL) {
        cout << current->data->data << ' '; // 修改为访问 data 成员
        current = current->next;
    }
    cout << endl;
}

bool isEmpty() {
    return stacks == NULL;
}

Node* getTop()
{
    return stacks;
}
void PreOrder(Binarytree* t) {
    Binarytree *p = t;
    while (p != NULL || !isEmpty()) {
        if (p != NULL) {
            push(p);
            cout << p->data << ' ';
            p = p->lchild;
        } else {
            p = stacks->data;
            pop();
            p = p->rchild;
        }
    }
}

int main() {
    Binarytree* t1 = new Binarytree;
    t1->data = 1;
    Binarytree* t2 = new Binarytree;
    t2->data = 2;
    Binarytree* t3 = new Binarytree;
    t3->data = 3;
    Binarytree* t4 = new Binarytree;
    t4->data = 4;
    t1->lchild = t2;
    t1->rchild = t3;
    t2->lchild = NULL;
    t2->rchild = NULL;
    t3->lchild = t4;
    t3->rchild = NULL;
    t4->lchild = NULL;
    t4->rchild = NULL;

    Binarytree* root = t1;
    PreOrder(root);
}