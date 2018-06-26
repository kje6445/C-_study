//***************************
// 파일명: Stack.cpp
// 작성자: 김지은
// 작성일: 2018.05.30
// 내용: try-catch를 이용한 예외 처리를 연습한다.
//***************************
#include<iostream>

using namespace std;


class Stack
{
	int sta[10];
	int index;
public:
	Stack()
	{
		index = 0;
		for (int i = 0; i < 10; i++)
			sta[i] = 0;
	}
	void push(int a)
	{
		if (index >= 10)
			throw a;
		sta[index] = a;
		index++;
	}
	void pop()
	{
		if (index <= 0)
			throw -1;
		index--;
		sta[index] = 0;

	}
	void display()
	{
		cout << "------------------------------------------------------------------" << endl;
		for (int i = 0; i < index; i++)
		{
			cout << "스택" << "[" << i << "]" << "에 저장된값은 :" << sta[i] << endl;
		}
	}
};
int main()
{
	Stack s;

	cout << "hw15_2 : 김지은" << endl;

	try {

		s.push(3);
		s.display();
		s.push(4);
		s.display();
		s.pop();
		s.display();
		s.pop();
		s.display();
		s.pop();
		return 0;
	}
	catch (int a) {
		cout << "Stack Underflow" << endl;

	}
}
