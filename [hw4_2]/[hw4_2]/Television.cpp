//***************************
// ���ϸ�:  Television.cpp
// �ۼ���: ������
// �ۼ���: 2018.04.08
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
	string SetName(string name);
	int SetPrice(int price);
	
	Television() {
		name = "MyTV";
		price=0;
	}
	Television(string name) {
		this->name = name;
		price = 0;
	}
	Television(string name, int price) {
		this->name = name;
		this->price = price;
	}
	double getTax();

	void discount1() {
		price = price * 0.9;
	}
	void discount2(int discount) {
		price= (price - discount);
	}
	void print() {
		cout << "�𵨸�:" << name << "  ����:" << price <<endl;
	}
};
int main() {
	cout << "hw4_2: ������" << endl;
	Television tv1;
	Television tv2("LALATV");
	Television tv3("LOLOTV",1000000);

	tv1.print();
	tv2.print();
	tv3.print();

	tv3.discount2(200000);
	tv3.discount1();
	tv3.print();
}