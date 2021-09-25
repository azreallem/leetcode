#include <iostream>
#include <vector>

using namespace std;

struct list_node{
    int val;
    list_node *next;
    list_node() : val(0), next(NULL){}
    list_node(int x) : val(x),next(NULL) {}
};

void print_l(list_node *p) {
    while (p) {
        cout << p->val << " -> ";
        if (p->next == NULL)
            cout << "NULL" <<endl;
        p = p->next;
    }
}

list_node* init_list(int size)
{
    vector<int> nums(size, 0);
    for (int j = 0; j < size; j++) {
        nums[j] = rand() % 10 + 1;
    }

    list_node *n1 = new list_node(nums[0]);
    list_node *n2 = new list_node(nums[1]);
    list_node *n3 = new list_node(nums[2]);
    list_node *n4 = new list_node(nums[3]);
    list_node *n5 = new list_node(nums[4]);
    list_node *n6 = new list_node(nums[5]);
    list_node *n7 = new list_node(nums[6]);
    list_node *n8 = new list_node(nums[7]);
    list_node *n9 = new list_node(nums[8]);
    list_node *n10 = new list_node(nums[9]);
    
    if (size >= 2)
        n1->next = n2; 
    if (size >= 3)
        n2->next = n3;
    if (size >= 4)
        n3->next = n4; 
    if (size >= 5)
        n4->next = n5;
    if (size >= 6)
        n5->next = n6; 
    if (size >= 7)
        n6->next = n7;
    if (size >= 8)
        n7->next = n8; 
    if (size >= 9)
        n8->next = n9;
    if (size >= 10)
        n9->next = n10;

    return n1;
}

/* --------------------func-------------------- */
list_node* delete_x (list_node* &p,int x) {
    while (p) {
        if (p->val == x) {
            //del head
            list_node *tmp = p;
            p = p->next;
            delete tmp;
        } else {
            break;
        }
    }
    list_node* head = p;

    while (p->next) {
        if (p->next->val == x) {
            //del p->next
            list_node *tmp = p->next;
            p->next = p->next->next;
            delete tmp;
        } else {
            p = p->next;
        }
    }

    p = head;
    return head;
}

/* --------------------main-------------------- */
int main()
{
    for (int i = 0; i < 10; i++) {
        cout << "-----------" << i << "------------" <<endl;


        // size = 1...10
        int size = rand() % 10 + 1;
        list_node *n1 = init_list(size);

        //before
        print_l(n1);

        //func
        cout << "after delete_x :" << 3 <<endl;
        delete_x(n1, 3);

        //after
        print_l(n1);

    }
    return 0;
}
