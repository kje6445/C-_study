//***************************
// 파일명:  BoundCheckIntArray.cpp
// 작성자: 김지은
// 작성일: 2018.05.16
// 내용: -연산자 오버로딩을 이해한다.
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
		os << i << "번째원소: " << array[i] << endl;
	return os;
}
istream& operator >> (istream& is, BoundCheckIntArray& array) {
	for (int i = 0; i<array.arrlen; i++) {
		cout << i << "번째원소: ";
		cin >> array[i];
	}

	return is;
}

int main(void) {
	cout << "hw11_1: 김지은" << endl << endl;
	BoundCheckIntArray arr(5);

	for (int i = 0; i<5; i++)
		arr[i] = (i + 1) * 11;

	cout << "arr 출력" << endl; // cout 연산자 중복
	cout << arr << endl << endl;

	BoundCheckIntArray cpy1 = arr;    // 복사생성자
	cout << "cpy1 출력" << endl;
	cout << cpy1 << endl << endl;

	BoundCheckIntArray cpy2(3);
	cout << "cpy2 입력" << endl;
	cin >> cpy2;    // cin 연산자 중복
	cout << "cpy2 출력" << endl;
	cout << cpy2 << endl << endl;

	BoundCheckIntArray cpy3(5);
	cpy3 = cpy2;   // 대입 연산자 중복 값이 작을 경우에는 put of bound 로 체크해 주기
	cout << "cpy3 출력" << endl;
	cout << cpy3 << endl << endl;


}
