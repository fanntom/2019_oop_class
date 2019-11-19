#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point() : x(0), y(0) {}
    Point(int _x, int _y) : x(_x), y(_y) {}
    void setXY(int _x, int _y);
    int getX() const;
    int getY() const;
    Point operator+(const Point& pt);
    //pt1 = pt2 = pt3
    Point operator=(const Point& pt);
};

    void Point::setXY(int _x, int _y) {
        this->x = _x;
        this->y = _y;
    }
    int Point::getX() const { return this-> x; }
    int Point::getY() const { return this-> y; }
    Point Point::operator+(const Point& pt) {
        Point result(this->x + pt.getX(), this->y + pt.getY());
        return result;
    }
    //pt1 = pt2 = pt3
    Point Point::operator=(const Point& pt) {
        this->x = pt.getX();
        this->y = pt.getY();
        return (*this);
    }

//pass by reference: 객체를 함수의 인자로 전달할 때 pass by  ref . 사용 권정
//const: 함수 내부에 객체의 맴버 변수가 바뀌지 않을 경우 const 삽입
//        -> 이때, 객체의 const method만 사용가능(method 이름 const {  })
void print_pt(const Point& pt) {
    cout <<pt.getX() << ", " << pt.getY() << endl;
}

//연산자 오버로딩: +, -, *, ==, >=, 등을 객채에 대해 재저으이
//  1)class 외부: operator+(좌측피연산자, 우측 피연산자)
//  2)class 내부: operator+(우측 피연산자) pt2 + pt3 -> pt2.+(pt3)
// pt1 + pt2 --> +(pt1,pt2)
//Point operator+(const Point pt1, const Point pt2) {
 //   Point result(pt1.getX() + pt2.getX(), pt1.getY() + pt2.getY());
  //  return result;
//}
//cout << pt1 --< <<(cout, pt1)
//cout << pt1 << pt2;
// (cout << pt1)--> cout << pt2
ostream& operator<<(ostream& cout, const Point& pt) {
    cout << pt.getX() << ", " <<pt.getY() << endl;
    return cout;
}

int main() {
    Point pt1(1, 2);
    print_pt(pt1);
    
    //객체 poiner 단순화 문법: (*pPt) --> pPt->
    Point* pPt = &pt1;
    cout << (*pPt).getX() << ", " << (*pPt).getY() << endl;
    cout << pPt->getX() << ", " << pPt->getY() << endl;
    cout << endl;

    Point* list = new Point[5];
    for (int i = 0; i < 5; i++)
        cout << list[i].getX() << ", " << list[1].getY() << endl;
    cout << endl;
    delete[] list;
    Point pt2(20, 20);
    Point pt3(200, 300);
    pt1 = pt2 + pt3;
    cout << pt1 << endl;
    cout << pt2 << endl;
    cout << pt3 << endl;
    cout << endl;

    return 0;
}