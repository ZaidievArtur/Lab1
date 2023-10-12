
#ifndef LAB1ALGOR_LINKEDLIST_H
#define LAB1ALGOR_LINKEDLIST_H


template<typename T>
class List {
private:
    class Node {
    public:
        const T data;
        Node *next;

        explicit Node(const T &data_) :
                data(data_),
                next(nullptr) {}
    };

    Node *head = new Node();
    int length = 0;

public:
    List() :
            head(nullptr) {}

    void add(const T &data) {
        if (isEmpty()) head = new Node(data);
        else if (data < head->data) {
            Node *newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        } else {
            Node *current = head;
            while (current->next != nullptr && current->data < current->next->data) {
                current = current->next;
            }
            Node *newNode = new Node(data);
            newNode->next = current->next;
            current->next = newNode;
        }
        length++;
    }

    bool isEmpty() {
        return (head == nullptr);
    }

    int getLength() {
        return length;
    }


    T *get(int *counter) {
        if (length == 0) return nullptr;

        T *list = new T [length];

        Node *current = head;
        for (int index = 0; index < length; index++) {
            list[index] = current->data;
            current = current->next;
        }

        *counter = length;

        return list;
    }

};

#endif //LAB1ALGOR_LINKEDLIST_H
