//***************************
// 파일명: MyArray.cpp
// 작성자: 김지은
// 작성일: 2018.05.23
// 내용: 템플릿을 이해한다.
//***************************
#include<iostream>

using namespace std;
template <typename T>
class MyArray {
private:
	T *dataT;
	int size;   // 배열의 현재 크기
	int maxSize;   // 배열의 최대 크기
public:
	MyArray(int maxSize = 10) {// 배열의 크기를 설정하고 동적 메모리 할당
		this->size = 0;
		this->maxSize = maxSize;
		this->dataT = new T[size];
		if (size > maxSize) {
			this->dataT = new T[maxSize];
		}
	};
	~MyArray() {  // 동적 메모리 반환
		delete[] dataT;
	};
	T& operator[](T  index) {
		return dataT[index];
	}
	void pushBack(T value) { // 배열 끝에 데이터 추가
		if(size < 10) {
			dataT[size] = value;
			size++;
		}
		else {
			cout << "배열이 꽉찼습니다." << endl;
			size = 10;
		}
		
	};
	void popBack() {  // 배열 끝의 데이터 삭제
		if (size < 10) {
			dataT[size] = 0;
			size--;
		}
		else {
			cout << "배열의 크기를 초과하였습니다" << endl;
		}
	};
	int getAt(int index) { // 배열의 요소 반환
		return dataT[index];
	};
	void setAt(int  index, T  value) {// 배열의 i변째 요소 value로 변경
		this->dataT[index] = value;
	};
	int getSize() const {// 배열의 크기 반환
		return size;
	};
	void showAll() {
		cout << "dataT의 배열의 값 : ";
		for (int i = 0; i < size; i++) {
			cout << dataT[i]<<" ";
			
		}
		cout << endl;
	}// 모든 값 출력

};

int main() {

	cout << "hw13_3: 김지은" << endl << endl;

	MyArray<int> arr;
	int value;
	cout << "값을 입력하세요" << endl << endl;
	for (int i = 0; i < 3; ++i) {
		cin >> value;
		arr.pushBack(value);
	}
	cout << "배열 출력" << endl;
	arr.showAll();

	cout << "두번째 인수값: " << arr.getAt(1) << endl << endl;
	cout << "두번째 인수값을 20으로 변경" << endl;
	arr.setAt(1, 20);
	cout << "배열의 내용 차례대로 출력" << endl << endl;
	arr.showAll();
	cout << "마지막 요소 삭제" << endl << endl;
	arr.popBack();
	cout << "배열의 내용 차례대로 출력" << endl;
	arr.showAll();
}