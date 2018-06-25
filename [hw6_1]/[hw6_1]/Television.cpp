//***************************
// ���ϸ�:  Television.cpp
// �ۼ���: ������
// �ۼ���: 2018.04.13
// ����: ���� ������ ���� ����Լ��� �����Ѵ�.
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

	static void getNumberOfTVs(){ //�ڷ����� ��ü ���� �����ϴ� �޼ҵ�
		cout << "�ڷ����� ��ü ��: "<< numberOfTVs <<endl;
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
	Television(const Television& copy) : price(copy.price) { // ���� ���� ����
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
int Television::numberOfTVs = 0;
int main() {
	cout << "hw6_1: ������" << endl;
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