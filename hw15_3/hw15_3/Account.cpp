//***************************
// 파일명: Account.cpp
// 작성자: 김지은
// 작성일: 2018.05.30
// 내용: 예외 클래스와 예외 발생, 예외 처리를 연습한다.
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
		cout << "출금액이 잔액보다 커서 출금 할 수 없습니다." << endl;
		cout << endl;
	}
};

class ExceedLimitException : public AccountExcetion {
private:
	int limitEx;
public:
	ExceedLimitException(int money) :limitEx(money) {};
	void ShowExceptionReason() {
		cout << "출금액이 한도금액보다 커서 출금 할 수 없습니다." << endl;
		cout << endl;
	}
};

class WrongAmmountException : public AccountExcetion {
private:
	int wrongMon;
public:
	WrongAmmountException(int money) :wrongMon(money) {};
	void ShowExceptionReason() {
		cout << "입력된 금액이 잘 못되었습니다." << endl;
		cout << endl;
	}
};

class BankAccount {

private:
	int balance;
	int limit;
public:
	BankAccount(int limit) {	//생성자 생성
		this->balance = 0;
		this->limit = limit;
	};
	void Deposit(int money){  //돈 입금
		if (money < 0) {
			throw WrongAmmountException(money);
		}
			balance += money; 
	
	};
	void Withdraw(int money){ //돈 출금
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

	cout << "hw15_3: 김지은 " << endl << endl;
	int num;
	int money1=0,money2=0,sum1=0,sum2=0;
	int limitmoney;
	cout << "계좌의 한도를 입력하시오"<<endl;
	cin >> limitmoney; cout << endl;
	BankAccount account(limitmoney);
	cout << "게좌의 한도가 " << limitmoney << "인 계좌가 생성되었습니다." << endl;
	while (1) {
		cout << "번호를 입력하시오 " << endl << "1:입금 2:출금 3:잔액조회 4:종료" << endl;
		cout << "입력 :";
		cin >> num;
		cout << endl;

		switch (num) {

		case 1:
			cout << "입금할 금액을 입력하시오" <<endl<<" 입금 금액 : ";
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
			cout << "출금할 금액을 입력하시오" << endl << " 출금 금액 : ";
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
			cout << "지금 남아있는 잔액은 " << account.getBalance() << " 입니다."<<endl;
			break;
		case 4:
			cout << "종료합니다." << endl;
			cout << " 입금 총액 : " << sum1 << " 출금 총액 : "<< sum2 << endl;
			return -1;
			break;

		default:
			cout << " 해당 번호가 없습니다. 다시 입력하십시오" << endl<<endl;
		}
	}
}