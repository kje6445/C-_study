//***************************
// 파일명:  Television.cpp
// 작성자: 김지은
// 작성일: 2018.04.13
// 내용: 정적 변수와 정적 멤버함수를 이해한다.
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
	static int numberOfTVs;

public:
	string GetName();
	int GetPirce();

	static void getNumberOfTVs(){ //텔레비전 객체 수를 리턴하는 메소드
		cout << "텔레비젼 객체 수: "<< numberOfTVs <<endl;
	}
	void SetName(string name) {
		this->name = name;
	};
	void SetPrice(int price) {
		this->price = price;
	};

	Television(){
		name = "MyTV";
		price = 0;
		++numberOfTVs;
	}

	Television(string name) {
		this->name = name;
		price = 0;
		++numberOfTVs;
	}
	Television(string name, int price) {
		this->name = name;
		this->price = price;
		++numberOfTVs;
	}
	Television(const Television& copy) : price(copy.price) { // 깊은 복사 실행
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
int Television::numberOfTVs = 0;
int main() {
	cout << "hw6_1: 김지은" << endl;
	Television::getNumberOfTVs();
	Television tv1;
	Television tv2("Samsung");
	Television tv3("LG", 200000);

	tv2.SetPrice(100000);
	tv1.print();
	tv2.print();
	tv3.print();
	Television::getNumberOfTVs();

	return 0;
}