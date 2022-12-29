#include <iostream>
using namespace std;

//template<class T1,class T2>
//T1 add(T1 t1, T2 t2) {
//    cout << "(" << sizeof(T1) << "," << sizeof(T2) << ")" << '\t';
//    return t1 + t2;
//}
//
//template<class T1,int T2>
//int add1(T1 t1) {
//    return t1 + T2;
//}
//
//template<class T_ID,class T_score,int num>
//class student {
//private:
//    T_ID student[num];
//    T_score score[num];
//public:
//  student1() {
//        for (int i = 0; i < num; i++) {
//            student[i] = i;
//            score[i] = 100 - i;
//        }
//    }
//    T_ID topstudent{
//        return student[0];
//    }
//        int belownum(T_score score) {
//        return 0;
//    }
//    T_ID topstudent();
//    int belownum(T_score score);
//};
//
//template<class T_ID,class T_score,int num>
//int student<T_ID, T_score, num>::belownum(T_score score) {
//    return 0;
//}
//
//template<class T_ID, class T_score, int num>
//T_ID student<T_ID, T_score, num>::topstudent() {
//    return student[0];
//}
//
//class namestring{
//public:
//    char string[20];
//    
//};



template<class T>
class stack {
private:
    int size;
    int top;
    T* space;
public:
    stack(int = 10);
    ~stack() {
        delete[]space;
    }
    bool push(const T &);
    T pop();
    bool isempty() const {
        return top == size;
    }
    bool isfull() const {
        return top == 0;
    }
};

template<class T>
stack<T>::stack(int size) {
    this->size = size;
    space = new T[size];
    top = size;
}
template<class T>
bool stack<T>::push(const T& element) {
    if (!isfull())
    {
        space[--top] = element;
        return true;
    }
    return false;
}
template<class T>
T stack<T>::pop() {
    return space[top++];
}

int main()
{
    //cout << add<double>(8, 9) << endl;
    //cout << add(8, 9) << endl;
    //cout << add1<int,9>(8) << endl;
    //cout << add(8.0, 9.0) << endl;
    //cout << add(8, 9.0) << endl;
    //cout << add(8.0, 9) << endl;
    //cout << add('A', 'A' - '0') << endl;
    //cout << add(long double(8), 9) << endl;
    //student<namestring, float, 100>s1;
    //student<long, int, 100>s2;
    //cout << "the highest score is: "<<  s1.topstudent().string<< endl;
    //cout << "the lowest score is: " << s1.belownum(100) << endl;
    //cout << "the highest score is: " << s2.topstudent()<< endl;

    stack<char>s1(4);
    s1.push('x');
    s1.push('y');
    s1.push('z');
    s1.push('u');
    s1.push('v');
    while (!s1.isempty())
    {
        cout << s1.pop() << endl;
    }
    return 0;
}


