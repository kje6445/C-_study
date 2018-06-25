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
		cout << "멍멍  ";
		ShowName();
	}
	virtual void ShowInfo() const {
		ShowName2();
		cout << "시속"<<speed<<"km"<<endl;
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
		cout << "안녕  ";
		ShowName();
	};
	virtual void ShowInfo() const {
		ShowName2();
		cout << year << "세" << endl;
	}
	virtual void newYear(int num) {
		year += num;
	}
	virtual void print() const {
	}
};

int main(void) {
	cout << "hw8_2: 김지은" << endl;
	cout << "" << endl;
	Dog *dog1 = new Dog("진돌이",13.5);
	Dog *dog2 = new Dog("진순이", 12.5);
	Person *person1 = new Person("홍길동",20);
	Person *person2 = new Person("박길동", 25);
	
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
		cout << "------------" << i << "년 후-----------" << endl;
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