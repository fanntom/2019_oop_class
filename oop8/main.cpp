#include <iostream>
#include <string>
#include <vector>
using namespace std;



// 1) Base type이 private: 상송 타입과 상관없이 Derived에서 접근 불가
// 2) Base type이 protected: 상속 타입과 상관없이 Derived에서 private로 선언
// 3) Base tpye이 public: 상속 타입 private/protected -> Derived에서 private
//                        상속 타입 public -> Derived에서 public
//황금률: Base class의 private를 protected로 고치고, 상속 타입은 public.
//함수 overriding: 부모클래스 method를 자식 클래스에 재정의 하는 것
//      -핵심 키워드(virtual, override)
//      - virtual: 부모클래스 method앞에 붙여줌( virtual void f(){})
//      - overrid: 자식 클래스 method에 붙여줌( void f() ovverid {})
/*
class Base {
protected: //base 타입
    virtual void f() { cout << "Base::f()" << endl; }
};

class Derived : public Base{//상속 타입
    public:
        void g() { cout << "Derived::g()" << endl; 
        Base::f();
               
        }
        void f() override { cout << "specialized" << endl; }
        //void f()
};

int main() {


    return 0;
}
*/

class Text {
private:
    string text;
public:
    Text(string _t) : text(_t) {}
    virtual string get() const {return text;}
    virtual void append(string _t) { text = text + _t; }
};

class FancyText : public Text {
private:
    string left_bracket;
    string right_bracket;
    string connector;
public:
    FancyText(string _t, string _left, string _right, string _conn) :
        Text(_t), left_bracket(_left), right_bracket(_right), connector(_conn) {}
    string get() const override{ return left_bracket + Text::get() + right_bracket; }
    void append(string _t) override{ Text::append(connector + _t); }
};

class FixedText : public Text {
public:
    FixedText() : Text("Fixed"){}
    void append(string _s) override {}
};

//다형성: 부모클래스 포인터로 자식클래스 객체를 모두 사용 가능
int main() {
    Text t1("plain");
    FancyText t2("fancy", "<<", ">>", "***");
    FixedText t3;
    cout << t1.get() << endl;
    cout << t2.get() << endl;
    cout << t3.get() << endl << endl;

    t1.append("A");
    t2.append("A");
    t3.append("A");

    cout << t1.get() << endl;
    cout << t2.get() << endl;
    cout << t3.get() << endl << endl;

    t1 = t2;
    cout << t1.get() << endl;

    Text* pT;//정적 바인딩: 자기작신 객채의 주소값을 포인터에 할당
    pT = &t1;
    cout << pT->get() << endl;
    pT->append("B");
    cout << pT->get() << endl << endl;

    pT = &t2;// 동적 바인딩: 부모클래스의 포인터로 자식클래스 주소로 저장.
             //             자식클래스의 overriding 
    cout << pT->get() << endl;
    pT->append("B");
    cout << pT->get() << endl << endl;

    
    vector<Text*> texts{new Text("Wow"),
                        new FancyText("Whoa", "(", ")", "-"),
                        new FixedText };

    for (auto elem : texts)
        cout << elem->get() << endl;


    return 0;
}