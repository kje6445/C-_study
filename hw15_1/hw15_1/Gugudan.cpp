//***************************
// 파일명: Gugudan.cpp
// 작성자: 김지은
// 작성일: 2018.05.30
// 내용: try-catch를 이용한 예외 처리를 연습한다.
//***************************
#include<iostream>

using namespace std;

int main() {

	cout << "hw15_1: 김지은" << endl << endl;
	int a,b;
	char c ='a';
	while(1){
		cout << "양수 입력 : ";
		cin >> a;
		try {
			if (cin.fail())
				throw c;
			if ((a < 1) || (a > 9))
				throw a;

			for (int i = 1; i < 10; ++i) {
				cout <<"  " <<a << "x" << i << "=" << a * i;
			}
			cout << endl;
		}
		catch (int b) {
			cout << b << "는 잘봇 된 입력입니다. 1~9 사이의 정수만 입력하세요" << endl;
			cout << endl;
		}
		catch (char c) {
			cout << "입력 오류가 발생하여 더 이상 입력되지 않습니다. 프로그램을 종료합니다" << endl;
			return 0;
		}
	}
}