//***************************
// ���ϸ�: Gugudan.cpp
// �ۼ���: ������
// �ۼ���: 2018.05.30
// ����: try-catch�� �̿��� ���� ó���� �����Ѵ�.
//***************************
#include<iostream>

using namespace std;

int main() {

	cout << "hw15_1: ������" << endl << endl;
	int a,b;
	char c ='a';
	while(1){
		cout << "��� �Է� : ";
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
			cout << b << "�� �ߺ� �� �Է��Դϴ�. 1~9 ������ ������ �Է��ϼ���" << endl;
			cout << endl;
		}
		catch (char c) {
			cout << "�Է� ������ �߻��Ͽ� �� �̻� �Էµ��� �ʽ��ϴ�. ���α׷��� �����մϴ�" << endl;
			return 0;
		}
	}
}