//***************************
// ���ϸ�: MyArray.cpp
// �ۼ���: ������
// �ۼ���: 2018.05.23
// ����: ���ø��� �����Ѵ�.
//***************************
#include<iostream>

using namespace std;
template <typename T>
class MyArray {
private:
	T *dataT;
	int size;   // �迭�� ���� ũ��
	int maxSize;   // �迭�� �ִ� ũ��
public:
	MyArray(int maxSize = 10) {// �迭�� ũ�⸦ �����ϰ� ���� �޸� �Ҵ�
		this->size = 0;
		this->maxSize = maxSize;
		this->dataT = new T[size];
		if (size > maxSize) {
			this->dataT = new T[maxSize];
		}
	};
	~MyArray() {  // ���� �޸� ��ȯ
		delete[] dataT;
	};
	T& operator[](T  index) {
		return dataT[index];
	}
	void pushBack(T value) { // �迭 ���� ������ �߰�
		if(size < 10) {
			dataT[size] = value;
			size++;
		}
		else {
			cout << "�迭�� ��á���ϴ�." << endl;
			size = 10;
		}
		
	};
	void popBack() {  // �迭 ���� ������ ����
		if (size < 10) {
			dataT[size] = 0;
			size--;
		}
		else {
			cout << "�迭�� ũ�⸦ �ʰ��Ͽ����ϴ�" << endl;
		}
	};
	int getAt(int index) { // �迭�� ��� ��ȯ
		return dataT[index];
	};
	void setAt(int  index, T  value) {// �迭�� i��° ��� value�� ����
		this->dataT[index] = value;
	};
	int getSize() const {// �迭�� ũ�� ��ȯ
		return size;
	};
	void showAll() {
		cout << "dataT�� �迭�� �� : ";
		for (int i = 0; i < size; i++) {
			cout << dataT[i]<<" ";
			
		}
		cout << endl;
	}// ��� �� ���

};

int main() {

	cout << "hw13_3: ������" << endl << endl;

	MyArray<int> arr;
	int value;
	cout << "���� �Է��ϼ���" << endl << endl;
	for (int i = 0; i < 3; ++i) {
		cin >> value;
		arr.pushBack(value);
	}
	cout << "�迭 ���" << endl;
	arr.showAll();

	cout << "�ι�° �μ���: " << arr.getAt(1) << endl << endl;
	cout << "�ι�° �μ����� 20���� ����" << endl;
	arr.setAt(1, 20);
	cout << "�迭�� ���� ���ʴ�� ���" << endl << endl;
	arr.showAll();
	cout << "������ ��� ����" << endl << endl;
	arr.popBack();
	cout << "�迭�� ���� ���ʴ�� ���" << endl;
	arr.showAll();
}