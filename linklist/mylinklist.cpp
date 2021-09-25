class MyLinkedList {

private:
    struct list_node {
        int val;
        list_node *next;
        list_node () : val(0), next(nullptr) {}
        list_node (int x) : val(x), next(nullptr) {}
    };
    list_node *head;

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new list_node();
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        list_node *p = head;
        
        // find index's location
        for (; index >= 0; index--) {
            p = p->next;
            if (!p)
                return -1;
        }
        return p->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new       node  will be the first node of the linked list. */
    void addAtHead(int val) {
        list_node *p = new list_node(val);
        p->next = head->next;
        head->next = p;
    }


    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        list_node *pnew = new list_node(val);
        list_node *p = head;

        // find last's location - 1
        while (p->next)
            p = p->next;
        p->next = pnew;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length      of   linked list, the node will be appended to the end of linked list. If index is greater than the length,     the      node will not be inserted. */
    void addAtIndex(int index, int val) {
        list_node *p = head;
        list_node *pnew = new list_node(val);

        // find at insert's location - 1
        for (; index > 0; index--) {
            p = p->next;
            if (!p)
                return;
        }

        //insert in location of p->next
        list_node *tmp = p->next;
        p->next = pnew;
        pnew->next = tmp;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (!head->next)
            return;
        list_node *p = head;

        // find at delete's location - 1
        for (; index > 0; index--) {
            p = p->next;
            if (!p->next)
                return;
        }

        //delete in location of p->next
        list_node *tmp = p->next;
        p->next = p->next->next;
        delete tmp;
    }

    void print_list () {
        list_node *p = head->next;
        while (p) {
           cout << p->val << '\t';
           p = p->next;
        }
        cout << endl;
    }
};
