#include <iostream>
using namespace std;
template<class T>
class SinleLinkedList {
public:
    struct node {
        T value;
        node *next = nullptr;
    };
    node *Head, *Tail;
    int size;

    SinleLinkedList() {
        Head = Tail = nullptr;
        size = 0;
    }


    void insertAtHead(T element) {
        if (isEmpty()) {
            node *newnode = new node();
            newnode->value = element;
            Head = Tail = newnode;
            size++;
        } else {
            node *newnode = new node();
            newnode->value = element;
            newnode->next = Head;
            Head = newnode;
            size++;
        }
    };

    void insertAtTail(T element) {
        if (isEmpty()) {
            node *newnode = new node();
            newnode->value = element;
            Head = Tail = newnode;
            size++;
        } else {
            node *newnode = new node();
            newnode->value = element;
            Tail->next = newnode;
            Tail = newnode;
            size++;
        }
    };

    void insertAt(T element, int index) {
        if (index > size || index < 0)cout << "invalid index" << endl;
        else {
            if (index == 0) { insertAtHead(element); }
            else if (index == size) { insertAtTail(element); }
            else {
                node *current = Head;
                for (int i = 0; i < index - 1; ++i) {
                    current = current->next;
                }
                node *newnode = new node();
                newnode->value = element;
                newnode->next = current->next;
                current->next = newnode;
                size++;
            }
        }
    };

    void removeAtHead() {
        if (isEmpty())return;
        else {
            node *current = Head;
            Head = Head->next;
            delete current;
            size--;
        }
    };

    void removeAtTail() {
        if (isEmpty())return;
        else {
            node *current = Head;
            for (int i = 0; i < size - 2; ++i) {
                current = current->next;
            }
            Tail = current;
            current = current->next;
            delete current;
            size--;
        }
    };

    void removeAt(int index) {
        if (index > size || index < 0)cout << "invalid index" << endl;
        else {
            if (index == 0) { removeAtHead(); }
            else if (index == size - 1) { removeAtTail(); }
            else {
                node *current = Head->next;
                node *prev = Head;
                for (int i = 0; i < index-1 ; ++i) {
                    current = current->next;
                    prev=prev->next;
                }
                prev->next = current->next;
                delete current;
                size--;
            }
        }
    };

    T retrieveAt(int index) {
        if (index > size || index < 0)cout << "invalid index" << endl;
        else {
            node *current = Head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
            return current->value;
        }

    };

    void replaceAt(T newElement, int index) {
        if (index >= size || index < 0)cout << "invalid index" << endl;
        else {
            node *current = Head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
            current->value = newElement;
        }

    };


    bool isExist(T element) {
        node *current = Head;
        for (int i = 0; i < size; ++i) {
            if (current->value == element)break;
            else current = current->next;
        }
        if (current == nullptr) {
            return false;
        }
        else {
            return true;
        }
    }


    bool isItemAtEqual(T element, int index) {
        if (index > size || index < 0)cout << "invalid index" << endl;
        else {
            node *current = Head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
            if (current->value == element)return true;
            else return false;
        }
    };

    void Swap(T firstItemIdx, T secondItemIdx) {
        if (firstItemIdx > size || firstItemIdx < 0 || secondItemIdx > size || secondItemIdx < 0)
            cout << size << " " << firstItemIdx << " " << secondItemIdx << "invalid index" << endl;
        else {
            node *current1 = Head;
            node *current2 = Head;
            for (int i = 0; i < firstItemIdx; ++i) {
                current1 = current1->next;
            }
            for (int i = 0; i < secondItemIdx; ++i) {
                current2 = current2->next;
            }
            swap(current1->value, current2->value);
        }
    }; // swap two nodes without swapping
    bool isEmpty() {
        if (size == 0)return true;
        else return false;
    };

    int linkedListSize() {
        return size;
    };

    void clear() {
        if(isEmpty())return;
        node *current = Head->next;
        node * prev =Head;
        int i;
        for ( i = 0; i < size; ++i) {
            delete prev;
            prev=current;
            current = current->next;

        }
        size=0;
    };

    void print() {
        node *current = Head;
        for (int i = 0; i < size; ++i) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;

    };
};
template<class T>
class DoubleLinkedList {
public:
    struct node {
        T value;
        node *next = nullptr;
        node *prev = nullptr;
    };
    node *Head, *Tail;
    int size;

    DoubleLinkedList() {
        Head = Tail = nullptr;
        size = 0;
    }

    void insertAtHead(T element) {
        if (isEmpty()) {
            node *newnode = new node();
            newnode->value = element;
            Head = Tail = newnode;
            size++;
        } else {
            node *newnode = new node();
            newnode->value = element;
            newnode->next = Head;
            Head->prev=newnode;
            Head = newnode;
            size++;
        }
    };

    void insertAtTail(T element) {
        if (isEmpty()) {
            node *newnode = new node();
            newnode->value = element;
            Head = Tail = newnode;
            size++;
        } else {
            node *newnode = new node();
            newnode->value = element;
            Tail->next = newnode;
            newnode->prev=Tail;
            Tail = newnode;
            size++;
        }
    };

    void insertAt(T element, int index) {
        if (index > size || index < 0)cout << "invalid index" << endl;
        else {
            if (index == 0) { insertAtHead(element); }
            else if (index == size) { insertAtTail(element); }
            else {
                node *current = Head;
                for (int i = 0; i < index - 1; ++i) {
                    current = current->next;
                }
                node *newnode = new node();
                newnode->value = element;
                newnode->next = current->next;
                newnode->prev=current;
                current->next = newnode;
                size++;
            }
        }
    };

    void removeAtHead() {
        if (isEmpty())return;
        else {
            node *current = Head;
            Head = Head->next;
            Head->prev= nullptr;
            delete current;
            size--;
        }
    };

    void removeAtTail() {
        if (isEmpty())return;
        else {
            node *current = Tail;
            Tail = Tail->prev;
            Tail->next= nullptr;
            delete current;
            size--;
        }
    };

    void removeAt(int index) {
        if (index > size || index < 0)cout << "invalid index" << endl;
        else {
            if (index == 0) { removeAtHead(); }
            else if (index == size - 1) { removeAtTail(); }
            else {
                node *current = Head;
                node *prev = Head;
                for (int i = 0; i < index ; ++i) {
                    current = current->next;
                }
                prev=current->prev;
                prev->next = current->next;
                prev->next->prev=prev;
                delete current;
                size--;
            }
        }
    };

    T retrieveAt(int index) {
        if (index > size || index < 0)cout << "invalid index" << endl;
        else {
            node *current = Head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
            return current->value;
        }

    };

    void replaceAt(T newElement, int index) {
        if (index >= size || index < 0)cout << "invalid index" << endl;
        else {
            node *current = Head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
            current->value = newElement;
        }

    };


    bool isExist(T element) {
        node *current = Head;
        for (int i = 0; i < size; ++i) {
            if (current->value == element)break;
            else current = current->next;
        }
        if (current == nullptr) {
            return false;
        }
        else {
            return true;
        }
    }


    bool isItemAtEqual(T element, int index) {
        if (index > size || index < 0)cout << "invalid index" << endl;
        else {
            node *current = Head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
            if (current->value == element)return true;
            else return false;
        }
    };

    void Swap(T firstItemIdx, T secondItemIdx) {
        if (firstItemIdx > size || firstItemIdx < 0 || secondItemIdx > size || secondItemIdx < 0)
            cout << size << " " << firstItemIdx << " " << secondItemIdx << "invalid index" << endl;
        else {
            node *current1 = Head;
            node *current2 = Head;
            for (int i = 0; i < firstItemIdx; ++i) {
                current1 = current1->next;
            }
            for (int i = 0; i < secondItemIdx; ++i) {
                current2 = current2->next;
            }
            swap(current1->value, current2->value);
        }
    };
    bool isEmpty() {
        if (size == 0)return true;
        else return false;
    };

    int linkedListSize() {
        return size;
    };

    void clear() {
        node *current = Head->next;
        node * prev =Head;
        for (int i = 0; i < size; ++i) {
            delete prev;
            prev=current;
            current = current->next;

        }

    };

    void print() {
        node *current = Head;
        for (int i = 0; i < size; ++i) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;

    };
};

template<class T>
class CircularLinkedList {
public:
    struct node {
        T value;
        node *next = nullptr;
    };
    node *Head, *Tail;
    int size;

    CircularLinkedList() {
        Head = Tail = nullptr;
        size = 0;
    }


    void insertAtHead(T element) {
        if (isEmpty()) {
            node *newnode = new node();
            newnode->value = element;
            Head = Tail = newnode;
            size++;
        } else {
            node *newnode = new node();
            newnode->value = element;
            newnode->next = Head;
            Head = newnode;
            size++;
        }
    };

    void insertAtTail(T element) {
        if (isEmpty()) {
            node *newnode = new node();
            newnode->value = element;
            Head = Tail = newnode;
            size++;
        } else {
            node *newnode = new node();
            newnode->value = element;
            Tail->next = newnode;
            Tail = newnode;
            Tail->next=Head;
            size++;
        }
    };

    void insertAt(T element, int index) {
        if (index > size || index < 0)cout << "invalid index" << endl;
        else {
            if (index == 0) { insertAtHead(element); }
            else if (index == size) { insertAtTail(element); }
            else {
                node *current = Head;
                for (int i = 0; i < index - 1; ++i) {
                    current = current->next;
                }
                node *newnode = new node();
                newnode->value = element;
                newnode->next = current->next;
                current->next = newnode;
                size++;
            }
        }
    };

    void removeAtHead() {
        if (isEmpty())return;
        else {
            node *current = Head;
            Head = Head->next;
            delete current;
            size--;
        }
    };

    void removeAtTail() {
        if (isEmpty())return;
        else {
            node *current = Head;
            for (int i = 0; i < size - 2; ++i) {
                current = current->next;
            }
            Tail = current;
            current = current->next;
            Tail->next=Head;
            delete current;
            size--;
        }
    };

    void removeAt(int index) {
        if (index > size || index < 0)cout << "invalid index" << endl;
        else {
            if (index == 0) { removeAtHead(); }
            else if (index == size - 1) { removeAtTail(); }
            else {
                node *current = Head->next;
                node *prev = Head;
                for (int i = 0; i < index-1 ; ++i) {
                    current = current->next;
                    prev=prev->next;
                }
                prev->next = current->next;
                delete current;
                size--;
            }
        }
    };

    T retrieveAt(int index) {
        if (index > size || index < 0)cout << "invalid index" << endl;
        else {
            node *current = Head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
            return current->value;
        }

    };

    void replaceAt(T newElement, int index) {
        if (index >= size || index < 0)cout << "invalid index" << endl;
        else {
            node *current = Head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
            current->value = newElement;
        }

    };


    bool isExist(T element) {
        node *current = Head;
        for (int i = 0; i < size; ++i) {
            if (current->value == element)break;
            else current = current->next;
        }
        if (current == nullptr) {
            return false;
        }
        else {
            return true;
        }
    }


    bool isItemAtEqual(T element, int index) {
        if (index > size || index < 0)cout << "invalid index" << endl;
        else {
            node *current = Head;
            for (int i = 0; i < index; ++i) {
                current = current->next;
            }
            if (current->value == element)return true;
            else return false;
        }
    };

    void Swap(T firstItemIdx, T secondItemIdx) {
        if (firstItemIdx > size || firstItemIdx < 0 || secondItemIdx > size || secondItemIdx < 0)
            cout << size << " " << firstItemIdx << " " << secondItemIdx << "invalid index" << endl;
        else {
            node *current1 = Head;
            node *current2 = Head;
            for (int i = 0; i < firstItemIdx; ++i) {
                current1 = current1->next;
            }
            for (int i = 0; i < secondItemIdx; ++i) {
                current2 = current2->next;
            }
            swap(current1->value, current2->value);
        }
    }; // swap two nodes without swapping
    bool isEmpty() {
        if (size == 0)return true;
        else return false;
    };

    int linkedListSize() {
        return size;
    };

    void clear() {
        if(isEmpty())return;
        node *current = Head->next;
        node * prev =Head;
        int i;
        for ( i = 0; i < size; ++i) {
            delete prev;
            prev=current;
            current = current->next;

        }
        size=0;
    };

    void print() {
        node *current = Head;
        for (int i = 0; i < size; ++i) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;

    };
};

int main() {
    CircularLinkedList<int> s;
    s.insertAtHead(10);
    s.print();
    s.insertAtHead(20);
    s.insertAtHead(50);
    s.print();
    s.insertAtTail(30);
    s.print();
    s.insertAt(40,2);
    s.print();
    s.Swap(2,4);
    s.print();
    s.removeAt(2);//-----------------
    s.print();
    s.replaceAt(70,2);
    s.print();
    cout<<s.retrieveAt(2)<<endl;
    cout<<s.isExist(20)<<endl;
    cout<<s.isItemAtEqual(70,2)<<endl;
    s.removeAtHead();
    s.print();
    s.removeAtTail();
    s.print();
    s.clear();
    s.print();
    s.insertAtTail(10);
    s.print();

}
