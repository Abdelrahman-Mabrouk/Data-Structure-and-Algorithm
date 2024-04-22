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

};
int main() {
    return 0;
}
