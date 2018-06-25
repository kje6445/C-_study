//***************************
// 파일명:  Television.cpp
// 작성자: 김지은
// 작성일: 2018.04.11
// 내용: 생성자를 이해한다.
//***************************

#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::cin;
using namespace std;

class Television {
private:
	string name;
	int price;
public:
	string GetName();
	int GetPirce();
	void SetName(string name) {
		this->name = name;
	};
	void SetPrice(int price) {
		this->price = price;
	};

	Television() {
		name = "MyTV";
		price = 0;
	}

	Television(const Television& copy) : price(copy.price){ // 깊은 복사 실행
		name = string(copy.name);
	}

	double getTax();

	void discount1() {
		price = price * 0.9;
	}
	void discount2(int discount) {
		price = (price - discount);
	}
	void print() {
		cout << "모델명:" << name << "  가격:" << price << endl;
	}
};
int main() {
	cout << "hw5_1: 김지은" << endl;
	Television tv1;
	Television tv2 = tv1;
	tv1.print();
	tv2.print();

	tv2.SetName("YourTV");
	tv1.print();
	tv2.print();


}