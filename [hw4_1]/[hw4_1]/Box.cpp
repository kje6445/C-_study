//***************************
// 파일명: Box.cpp
// 작성자: 김지은
// 작성일: 2018.04.04
// 내용: 클래스 정의를 이해한다.
//***************************
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

class Box {
private:
	double height;//높이
	double width;//너비
	double length;//길이
	bool empty;//비어있는지 여부확인
public:
	Box(double height, double width, double length, bool empty) { //생성자 생성
		this->height = height;
		this->width = width;
		this->length = length;
		this->empty = empty;
	}
	Box() {	//생성자 생성
		height = 5.0;
		width = 5.0;
		length = 5.0;
	}
	double GetHeight() const;
	double GetWidth() const;
	double GetLength() const;
	void SetHeight(double height) {
		this->height = height;
	};
	void SetWidth(double width) {
		this->width = width;
	}
	void SetLength(double length) {
		this->length = length;
	};
	double getVolume() {
		return  height * width*length;
	}

};
int main() {
	cout << "hw4_1:김지은" << endl;
	cout << "========================================" << endl;
	int i = 1;
	double max = 0;
	int n = 0;
	Box b1(3.5, 4.4, 5.0, false), b2, b3;
	b3.SetHeight(4.0);
	b3.SetLength(5.0);
	b3.SetWidth(2.4);
	for (int i = 1; i < 4; ++i) {
		if (i == 1) {
			cout << "박스 : " << "1";
			cout << " 부피는 : ";
			cout << b1.getVolume() << endl;
			max = b1.getVolume();
			n = 1;
		}
		else if (i == 2) {
			cout << "박스 : " << "2";
			cout << " 부피는 : ";
			cout << b2.getVolume() << endl;
			if (max < b2.getVolume()) {
				max = b2.getVolume();
				n = 2;
			}
		}
		else {
			cout << "박스 : " << "3";
			cout << " 부피는 : ";
			cout << b3.getVolume() << endl;
			if (max < b3.getVolume()) {
				max = b3.getVolume();
				n = 3;
			}
		}
	}
	cout << "========================================" << endl;
	cout << "박스" << n;
	cout << "의 부피가 가장 큽니다:" << max << endl;
}
