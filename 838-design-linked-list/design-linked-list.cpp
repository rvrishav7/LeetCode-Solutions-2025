struct Node {
    int val;
    Node *prev;
    Node *next;

    Node(int val) {
        this->val = val;
        prev = nullptr;
        next = nullptr;
    }
};

class MyLinkedList {
public:
    int size;
    Node *head;
    Node *tail;

    MyLinkedList() {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    int get(int index) {
        if (index < 0 || index >= size)
            return -1;

        Node *temp = head;

        while (index--)
            temp = temp->next;

        return temp->val;
    }

    void addAtHead(int val) {
        Node *tmp = new Node(val);

        if (!head) {
            head = tail = tmp;
        } else {
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
        }

        size++;
    }

    void addAtTail(int val) {
        Node *tmp = new Node(val);

        if (!tail) {
            head = tail = tmp;
        } else {
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }

        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size)
            return;

        // Insert at beginning
        if (index == 0) {
            addAtHead(val);
            return;
        }

        // Insert at end
        if (index == size) {
            addAtTail(val);
            return;
        }

        Node *temp = head;

        // Move temp to node currently at index
        for (int i = 0; i < index; i++)
            temp = temp->next;

        Node *curr = new Node(val);

        curr->next = temp;
        curr->prev = temp->prev;

        temp->prev->next = curr;
        temp->prev = curr;

        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;

        Node *temp = head;

        // Delete head
        if (index == 0) {
            head = head->next;

            if (head)
                head->prev = nullptr;
            else
                tail = nullptr;

            delete temp;
            size--;
            return;
        }

        // Delete tail
        if (index == size - 1) {
            temp = tail;

            tail = tail->prev;
            tail->next = nullptr;

            delete temp;
            size--;
            return;
        }

        // Find node
        for (int i = 0; i < index; i++)
            temp = temp->next;

        // Remove temp
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
        size--;
    }
};