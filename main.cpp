شكلي كد هخلي كله ماب
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
    bool operator <= (const student & x){
        if(name<=x.name)return true;
        else return false;
    }
}

//<!------------------ Get Data From File ---------------------------------!>
void read_file(string Name_file , vector <student> &ListOFStudent){
    fstream file(Name_file,ios::in);
    string line;
    int NumberOFStudent,i=0,count=0;
    getline(file,line);
    NumberOFStudent=line[0]-'0';
    while (getline(file,line)){
        student x;
        if(count==0) {
            ListOFStudent.push_back(x) ;
            ListOFStudent[i].name=line;
            count++;
        }
        else if(count==1) {
            ListOFStudent[i].id = line;
            count++;
        }

        else if(count==2) {
            ListOFStudent[i].gba = line;
            count++;
        }

        if(count==3)count=0,i++;
    }
}

//<!------------------ Insertion Sort ---------------------------------!>
template<class T>
void  insertion_sort( vector<T>&array, int n, bool flag) {
        for (int i = 1, j; i < n; ++i) {
            student t;
            t = array[i];;
            for (j = i; j > 0 &&( flag ?t.gba < array[j - 1].gba : t.name < array[j - 1].name) ; j--) array[j] = array[j - 1];
            array[j] = t;
        }
    }


//<!------------------ Bubbel Sort ---------------------------------!>
template <class T>
void  Bubble_sort(vector<T>&array,int n,bool flag) {
        for (int i = 0, j; i < n - 1; ++i) {
            for (j = 0; j < n - i - 1; j++) {
                if (flag) {
                    if (array[j].name > array[j + 1].name)swap(array[j], array[j + 1]);
                } else {
                    if (array[j].gba > array[j + 1].gba)swap(array[j], array[j + 1]);
                }
            }
        }
    }


//<!------------------ Merge Sort ---------------------------------!>
template <class T>
void merge(T array[],int left,int mid,int right,int flag) {
    int SizeOFRight =  right-mid;
    int SizeOFLeft = mid-left+1;
    T *leftArray = new T[SizeOFLeft], *rightArray = new T[SizeOFRight];
    for (int i = 0; i < SizeOFLeft; ++i) {
        leftArray[i] = array[left + i];
    }
    for (int i = 0; i < SizeOFRight; ++i) {
        rightArray[i] = array[mid + i + 1];
    }
    int l = 0, r = 0;
    int k = left;
    while (l < SizeOFLeft && r < SizeOFRight) {
        if (flag ?(leftArray[l].gba) <= (rightArray[r].gba) : (leftArray[l]) <= (rightArray[r])) {
            array[k] = leftArray[l];
            l++;
        } else {
            array[k] = rightArray[r];
            r++;
        }
        k++;
    }
    while (l < SizeOFLeft) {
        array[k] = leftArray[l];
        l++, k++;
    }
    while (r < SizeOFRight) {
        array[k] = rightArray[r];
        r++, k++;
    }

    delete []leftArray;
    delete []rightArray;
}
template <class T>
void Merge_sort(T array[],int left ,int right,int flag) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        Merge_sort(array, left, mid,flag);
        Merge_sort(array, mid + 1, right,flag);
        merge(array, left, mid, right,flag);
    }
}

//<!------------------ Count Sort ---------------------------------!>
template <class T>
void Count_sort( vector<T> &array,int n,int flag){
    int temp[5]={0};
    T a[n];
    for (int i = 0; i <n ; ++i) {
        temp[int(array[i].gba)]++;
        a[i]=array[i];
    }
    for (int i = 1; i < 5; ++i) {
        temp[i]=temp[i]+temp[i-1];
    }
    for (int i = n-1; i >= 0; --i) {
        a[--temp[int(array[i].gba)]].gba=(array[i].gba);
    }

    for (int i = 0; i < n; ++i) {
        array[i]=a[i];
    }
cout<<endl;
}

int main() {
      vector <student> ListOFStudent;
      cout<<"DO You Want Sorting BY GBA OR NAME?"<<endl;
      cout<<"if you want GBA enter 0 else enter 1"<<endl;
      bool flag;
      cin>>flag;
    read_file("data_of_student.txt",ListOFStudent,flag);

     for (int i = 0; i < ListOFStudent.size(); ++i) {
        cout<<ListOFStudent[i].name<<" "<<ListOFStudent[i].id<<" "<<ListOFStudent[i].gba<<endl;
    }
    return 0;
}
