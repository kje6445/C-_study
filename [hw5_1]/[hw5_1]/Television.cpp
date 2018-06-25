//***************************
// ���ϸ�:  Television.cpp
// �ۼ���: ������
// �ۼ���: 2018.04.11
// ����: �����ڸ� �����Ѵ�.
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

	Television(const Television& copy) : price(copy.price){ // ���� ���� ����
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
		cout << "�𵨸�:" << name << "  ����:" << price << endl;
	}
};
int main() {
	cout << "hw5_1: ������" << endl;
	Television tv1;
	Television tv2 = tv1;
	tv1.print();
	tv2.print();

	tv2.SetName("YourTV");
	tv1.print();
	tv2.print();


}