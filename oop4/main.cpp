#include <iostream>
using namespace std;

class Point {
//private: class내 접근 가능/class 외부에서 접근 불가
//public: class내외에서 모두 사용가능
//getter: private 멤버 변수를 외부로 반환
//setter: private 멤버 변수를 수정
private: //data
    int x;
    int y;
public: //function
    void setXY(int _x, int _y){
        x = _x;
        y = _y;
    }
    int getX() {return x;}
    int getY() {return y;}
    
};

int main(){
    Point pt1, pt2;
    pt1.setXY(10, 20);

    cout << pt1.getX() << ", " << pt1.getY() << endl;
    return 0;
}