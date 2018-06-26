//***************************
// ���ϸ�: Stack.cpp
// �ۼ���: ������
// �ۼ���: 2018.05.30
// ����: try-catch�� �̿��� ���� ó���� �����Ѵ�.
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
			cout << "����" << "[" << i << "]" << "�� ����Ȱ��� :" << sta[i] << endl;
		}
	}
};
int main()
{
	Stack s;

	cout << "hw15_2 : ������" << endl;

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
