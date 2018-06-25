//***************************
// ���ϸ�: Point.cpp
// �ۼ���: ������
// �ۼ���: 2018.04.18
// ����: ��� ������ �����Ѵ�.
//***************************
#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::cin;
using namespace std;

class Point {
	int x, y;
public:
	Point(int x, int y) {
		this->x = x; this->y = y;
	}
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};

class ColorPoint : protected Point {
private:
	string color;
public:
	ColorPoint() :Point(0,0) {
		this->color = "BLACK";
	}
	ColorPoint(int  x, int y) :Point(x, y) {
		this->color = "BLACK";
	}
	void setColor(string color) {
		this->color = color;
	};
	void setPoint(int x, int y){
		move(x, y);
	};
	void show(){
		cout << color<< "������ "<< "(" << getX() << "," << getY()<< ")�� " << "��ġ�� ���Դϴ�." << endl;
	}
};
int main() {
	cout << "hw7_1: ������" << endl;
	ColorPoint zeroPoint; // BLACK�� (0, 0) ��ġ�� ��
	zeroPoint.show(); // zeroPoint�� ����Ѵ�.
	
	ColorPoint cp(5, 5);
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show(); // cp�� ����Ѵ�.
}