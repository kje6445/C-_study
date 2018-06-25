//***************************
// 파일명: Animal.cpp
// 작성자: 김지은
// 작성일: 2018.5.6
// 내용: 추상클래스와 다형성의 개념을 이해한다.
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
		cout << "멍멍  ";
		ShowName();
	}
};

class Person: public  Animal{

public:
	Person(string name) :Animal(name) {
	}
	virtual void Sound() const {
		cout << "안녕  ";
		ShowName();
	};
};

int main(void) {
	cout << "hw8_1: 김지은" << endl;
	cout << "" << endl;
	Dog *dog = new Dog("진돌이");
	dog->Sound();
	delete dog;
		
	Person *person = new Person("홍길동");
	person->Sound();
	delete person;
}