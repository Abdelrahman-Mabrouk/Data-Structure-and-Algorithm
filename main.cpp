#include <iostream>
#include "Linked-List"
using namespace std;
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
