//***************************
// ���ϸ�: Box.cpp
// �ۼ���: ������
// �ۼ���: 2018.04.04
// ����: Ŭ���� ���Ǹ� �����Ѵ�.
//***************************
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

class Box {
private:
	double height;//����
	double width;//�ʺ�
	double length;//����
	bool empty;//����ִ��� ����Ȯ��
public:
	Box(double height, double width, double length, bool empty) { //������ ����
		this->height = height;
		this->width = width;
		this->length = length;
		this->empty = empty;
	}
	Box() {	//������ ����
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
	cout << "hw4_1:������" << endl;
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
			cout << "�ڽ� : " << "1";
			cout << " ���Ǵ� : ";
			cout << b1.getVolume() << endl;
			max = b1.getVolume();
			n = 1;
		}
		else if (i == 2) {
			cout << "�ڽ� : " << "2";
			cout << " ���Ǵ� : ";
			cout << b2.getVolume() << endl;
			if (max < b2.getVolume()) {
				max = b2.getVolume();
				n = 2;
			}
		}
		else {
			cout << "�ڽ� : " << "3";
			cout << " ���Ǵ� : ";
			cout << b3.getVolume() << endl;
			if (max < b3.getVolume()) {
				max = b3.getVolume();
				n = 3;
			}
		}
	}
	cout << "========================================" << endl;
	cout << "�ڽ�" << n;
	cout << "�� ���ǰ� ���� Ů�ϴ�:" << max << endl;
}
