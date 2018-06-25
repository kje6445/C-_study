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
	virtual void Sound() const{
	}
	void ShowName() const {
		cout << name << endl;
	}
};

class Dog: public Animal {
public:
	Dog(string name):Animal(name){
	};
	virtual void Sound() const {
		cout << "�۸�  ";
		ShowName();
	}
};

class Person: public  Animal{

public:
	Person(string name) :Animal(name) {
	}
	virtual void Sound() const {
		cout << "�ȳ�  ";
		ShowName();
	};
};

int main(void) {
	cout << "hw8_1: ������" << endl;
	cout << "" << endl;
	Dog *dog = new Dog("������");
	dog->Sound();
	delete dog;
		
	Person *person = new Person("ȫ�浿");
	person->Sound();
	delete person;
}