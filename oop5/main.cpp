#include <iostream>
#include <vector>
using namespace std;
//생성자(constructor): 객체 선언시에 1회 호출 - 맴버 변수 초기화
//                     1) 항수명이 클래스 이름과 동일, return type이 없음
//                     2) 생성자를 만들지 않으면 - default 생성자 자동 생성
//                          default constructor: Account(){}
//                     3) 생성자를 만들면 - default 생성자 생성되지 않음
//                     4) Initialization list 사용 권장(상속, 다형성 떄 필수)
class Account {
private://data 클래스 내부에서만 접근 가능
    string name;
    string id;
    double balance;
public://method 클래스 내/외부에서 모두 접근 가능
    Account(string _name, string _id, double _bal) :
        name(_name), id(_id), balance(_bal) {
        if (balance < 0)
            balance = 0;
        }

    Account() : name("xxx"), id("0000"), balance(0) {} // initialization list <- 추천
    /*Account() {
        name = "xxx";
        id = "0000";
        balance = 0;
    }
    */
    void deposit(double _amt) {
        balance += _amt;
    }

    bool withdraw(double _amt) {
        if(balance - _amt < 0)
            return false;
        balance -= _amt;
        return true;
    }
    void print() {
        cout << name << '\t' << id << '\t' << balance << endl;
    }

};


int main(){
    Account acc1;
    Account acc2("홍길동", "1002", 5000);
    acc1.print();
    acc2.print();

    acc1.deposit(10000);
    acc1.print();

    if (!acc1.withdraw(20000))
        cout << "잔액이 부족합니다." << endl;
    
    acc1.print();

    acc1.withdraw(5400);
    acc1.print();

    vector<Account> vec;
    vec.push_back(acc1);
    vec.push_back(acc2);
    for(auto elem : vec)
        elem.print();

    return 0;
}