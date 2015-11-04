#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct A {
    int a;
    virtual ~A() {}
};

struct B : A {
    B(int x) { a = x; }
};

struct CompA {
    bool operator()(const A& lhs, const A& rhs) const {
        return lhs.a < rhs.a;
    }
};

template <class T, class comp>
void my_sort(vector<T>& arr, comp less) {
    for(int i=0; i<arr.size(); i++) {
        for(int j=i+1; j<arr.size(); j++) {
//            if(arr[j] < arr[i]) swap(arr[i], arr[j]);   //error: no match for 'operator<'
            if(less(arr[j], arr[i])) swap(arr[i], arr[j]);
        }
    }
}

int main() {
    cout << "Hello, World!" << endl;

    vector<B> b1 = {6, 4, 8, 1, 2}, b2 = b1;
    sort(begin(b1), end(b1), CompA());
    my_sort<B>(b2, CompA());

    for(auto& i : b1) cout << i.a << " "; cout << endl;
    for(auto& i : b2) cout << i.a << " "; cout << endl;

    return 0;
}