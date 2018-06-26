//***************************
// ���ϸ�:  BoundCheckIntArray.cpp
// �ۼ���: ������
// �ۼ���: 2018.05.16
// ����: -������ �����ε��� �����Ѵ�.
//***************************
#include<iostream>
#include<string>

using namespace std;

class BoundCheckIntArray
{
private:
	int * arr;
	int arrlen;



public:
	BoundCheckIntArray(int len) :arrlen(len)
	{
		arr = new int[len];
	}

	int& operator[] (int idx)
	{
		if (idx<0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}

		return arr[idx];
	}

	int operator[] (int idx) const
	{
		if (idx<0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}

		return arr[idx];
	}
	int GetArrLen() const
	{
		return arrlen;
	}


	~BoundCheckIntArray()
	{
		delete[]arr;
	}
	friend ostream& operator<<(ostream& os, BoundCheckIntArray& array);
	friend istream& operator >> (istream& is, BoundCheckIntArray& array);

	BoundCheckIntArray& operator=(BoundCheckIntArray& ref) {
		if (ref.arrlen <= GetArrLen()) {
			//arrlen = ref.arrlen;
			for (int i = 0; i < GetArrLen(); i++)
				arr[i] = ref[i];
			return *this;
		}
		else {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
	}
};
ostream& operator<<(ostream& os, BoundCheckIntArray& array) {
	for (int i = 0; i<array.arrlen; i++)
		os << i << "��°����: " << array[i] << endl;
	return os;
}
istream& operator >> (istream& is, BoundCheckIntArray& array) {
	for (int i = 0; i<array.arrlen; i++) {
		cout << i << "��°����: ";
		cin >> array[i];
	}

	return is;
}

int main(void) {
	cout << "hw11_1: ������" << endl << endl;
	BoundCheckIntArray arr(5);

	for (int i = 0; i<5; i++)
		arr[i] = (i + 1) * 11;

	cout << "arr ���" << endl; // cout ������ �ߺ�
	cout << arr << endl << endl;

	BoundCheckIntArray cpy1 = arr;    // ���������
	cout << "cpy1 ���" << endl;
	cout << cpy1 << endl << endl;

	BoundCheckIntArray cpy2(3);
	cout << "cpy2 �Է�" << endl;
	cin >> cpy2;    // cin ������ �ߺ�
	cout << "cpy2 ���" << endl;
	cout << cpy2 << endl << endl;

	BoundCheckIntArray cpy3(5);
	cpy3 = cpy2;   // ���� ������ �ߺ� ���� ���� ��쿡�� put of bound �� üũ�� �ֱ�
	cout << "cpy3 ���" << endl;
	cout << cpy3 << endl << endl;


}
