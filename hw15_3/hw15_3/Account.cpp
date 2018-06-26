//***************************
// ���ϸ�: Account.cpp
// �ۼ���: ������
// �ۼ���: 2018.05.30
// ����: ���� Ŭ������ ���� �߻�, ���� ó���� �����Ѵ�.
//***************************
#include<iostream>

using namespace std;

class AccountExcetion {
public:
	virtual void ShowExceptionReason() = 0;
};

class NegativeBalanceException : public AccountExcetion {
private:
	int reqDep;
public:
	NegativeBalanceException(int money) :reqDep(money) {};
	void ShowExceptionReason() {
		cout << "��ݾ��� �ܾ׺��� Ŀ�� ��� �� �� �����ϴ�." << endl;
		cout << endl;
	}
};

class ExceedLimitException : public AccountExcetion {
private:
	int limitEx;
public:
	ExceedLimitException(int money) :limitEx(money) {};
	void ShowExceptionReason() {
		cout << "��ݾ��� �ѵ��ݾ׺��� Ŀ�� ��� �� �� �����ϴ�." << endl;
		cout << endl;
	}
};

class WrongAmmountException : public AccountExcetion {
private:
	int wrongMon;
public:
	WrongAmmountException(int money) :wrongMon(money) {};
	void ShowExceptionReason() {
		cout << "�Էµ� �ݾ��� �� ���Ǿ����ϴ�." << endl;
		cout << endl;
	}
};

class BankAccount {

private:
	int balance;
	int limit;
public:
	BankAccount(int limit) {	//������ ����
		this->balance = 0;
		this->limit = limit;
	};
	void Deposit(int money){  //�� �Ա�
		if (money < 0) {
			throw WrongAmmountException(money);
		}
			balance += money; 
	
	};
	void Withdraw(int money){ //�� ���
		if (money > balance) {
			throw NegativeBalanceException(money);
		}
		else if (money > limit) {
			throw ExceedLimitException(money);
		}
		else if (money < 0) {
			throw WrongAmmountException(money);
		}
		balance -= money;

	};
	int getBalance() {
		return balance;
	}

};


int main() {

	cout << "hw15_3: ������ " << endl << endl;
	int num;
	int money1=0,money2=0,sum1=0,sum2=0;
	int limitmoney;
	cout << "������ �ѵ��� �Է��Ͻÿ�"<<endl;
	cin >> limitmoney; cout << endl;
	BankAccount account(limitmoney);
	cout << "������ �ѵ��� " << limitmoney << "�� ���°� �����Ǿ����ϴ�." << endl;
	while (1) {
		cout << "��ȣ�� �Է��Ͻÿ� " << endl << "1:�Ա� 2:��� 3:�ܾ���ȸ 4:����" << endl;
		cout << "�Է� :";
		cin >> num;
		cout << endl;

		switch (num) {

		case 1:
			cout << "�Ա��� �ݾ��� �Է��Ͻÿ�" <<endl<<" �Ա� �ݾ� : ";
			cin >> money1; cout << endl;
			try{
				account.Deposit(money1);
				sum1 += money1;
				break;
			}
			catch (WrongAmmountException &expn) {
				expn.ShowExceptionReason();
				break;
			}
		case 2:
			cout << "����� �ݾ��� �Է��Ͻÿ�" << endl << " ��� �ݾ� : ";
			cin >> money2; cout << endl;
			try {
				account.Withdraw(money2);
				sum2 += money2;
				break;
			}
			catch (NegativeBalanceException &expn) {
				expn.ShowExceptionReason();
				break;
			}
			catch (ExceedLimitException &expn) {
				expn.ShowExceptionReason();
				break;
			}
			catch (WrongAmmountException &expn) {
				expn.ShowExceptionReason();
				break;
			}
			
			
		case 3:
			cout << "���� �����ִ� �ܾ��� " << account.getBalance() << " �Դϴ�."<<endl;
			break;
		case 4:
			cout << "�����մϴ�." << endl;
			cout << " �Ա� �Ѿ� : " << sum1 << " ��� �Ѿ� : "<< sum2 << endl;
			return -1;
			break;

		default:
			cout << " �ش� ��ȣ�� �����ϴ�. �ٽ� �Է��Ͻʽÿ�" << endl<<endl;
		}
	}
}