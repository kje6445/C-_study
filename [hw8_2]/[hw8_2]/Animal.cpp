//***************************
// ���ϸ�: Animal.cpp
// �ۼ���: ������
// �ۼ���: 2018.5.6
// ����: �߻�Ŭ������ �������� ������ �����Ѵ�.
//***************************
#include<iostream>
#include<string>
using namespace std;

class  Animal {
private:
	string name;
public:
	Animal(string name) {
		this->name = name;
	};
	void getterName(string name) {
		this->name = name;
	}
	virtual void Sound() const {
	}
	virtual void newYear(){
	}
	virtual void newSpeed(){
	}
	virtual void print() const {
	}
	void ShowName() const {
		cout << name << endl;
	}
	void ShowName2() const {
		cout << name <<" ";
	}
};

class Dog : public Animal {
private:
	double speed;
public:
	Dog(string name, double speed) :Animal(name) {
		this->speed = speed;
	};
	virtual void Sound() const {
		cout << "�۸�  ";
		ShowName();
	}
	virtual void ShowInfo() const {
		ShowName2();
		cout << "�ü�"<<speed<<"km"<<endl;
	}
	virtual void  newSpeed(int num) {
		speed += num;
	}
	virtual void print() const {
	}
};

class Person : public  Animal {
private:
	int year;
public:
	Person(string name, int year) :Animal(name) {
		this->year = year;
	}

	virtual void Sound() const {
		cout << "�ȳ�  ";
		ShowName();
	};
	virtual void ShowInfo() const {
		ShowName2();
		cout << year << "��" << endl;
	}
	virtual void newYear(int num) {
		year += num;
	}
	virtual void print() const {
	}
};

int main(void) {
	cout << "hw8_2: ������" << endl;
	cout << "" << endl;
	Dog *dog1 = new Dog("������",13.5);
	Dog *dog2 = new Dog("������", 12.5);
	Person *person1 = new Person("ȫ�浿",20);
	Person *person2 = new Person("�ڱ浿", 25);
	
	dog1->ShowInfo();
	dog2->ShowInfo();
	person1->ShowInfo();
	person2->ShowInfo();
	cout << "" << endl;

	dog1->Sound();
	dog2->Sound();
	person1->Sound();
	person2->Sound();
	cout << "" << endl;
	for (int i = 1; i < 3; i++) {
		cout << "------------" << i << "�� ��-----------" << endl;
		dog1->newSpeed(5);
		dog2-> newSpeed(5);
		person1->newYear(1);
		person2->newYear(1);

		dog1->ShowInfo();
		dog2->ShowInfo();
		person1->ShowInfo();
		person2->ShowInfo();
		cout << "" << endl;
		cout << "" << endl;
	}
}