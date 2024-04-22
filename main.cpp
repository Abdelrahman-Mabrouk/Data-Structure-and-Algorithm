#include <iostream>
#include <string>
using namespace std;
class student {
    string id;
    string name;
    double gba;
public:
     student(string name, string id , double gba){
        this->name=name;
        this->id=id;
        this->gba=gba;
    }
    bool operator < (const student & x){
        if(name<x.name)return true;
        else return false;
    }
template<class T>
void  insertion_sort(T  array[],int n) {
    for (int i = 1, j; i < n; ++i) {
        int t = array[i];
        for (j = i; j > 0 && t < array[j - 1]; j--) array[j] = array[j - 1];
        array[j] = t;
    }
}
template <class T>
void  Bubble_sort(T  array[],int n) {
    for (int i = 0, j; i < n-1; ++i) {
        for (j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1])swap(array[j], array[j + 1]);
        }
    }
}

};
int main() {
   int  a[]={1,5,3,6,8,2,4};

    insertion_sort(a,7);
    Bubble_sort(a,7);

    for (int i = 0; i < 7; ++i) {
        cout<<a[i]<<" ";
    }
    return 0;
}
