#include <iostream>
#include <string>


class Cashbox {
private:
	int money;
public: 
	Cashbox() :money(0) {}

	int CurrentMoney() {
		return money;
	}

	void CashIn(int money) {
		this->money += money;
	}

	void CashOut(int money) {
		if (money > this->money) {
			std::cerr << "Недостаточно средств в кассе.\n";
			return;
		}
		this->money -= money;
	}

	int Exchange(int ticket, int money) {
		if (money < ticket) {
			std::cerr << "Недостаточно средств для оплаты чека.\n";
			return money;
		}
		if (this->money < money - ticket) {
			std::cerr << "Недостаточно средств на кассе для сдачи.\n";
			return money;
		}
		this->money += ticket;
		return money - ticket;
	}
};


int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	Cashbox C1;
	Cashbox C2;
	
	C1.CashIn(1000);
	
	std::cout << "В первой кассе есть: " << C1.CurrentMoney() << std::endl;
	std::cout << "Во второй кассе есть: " << C2.CurrentMoney() << std::endl;

	C1.CashOut(2000);
	std::cout << "В первой кассе есть: " << C1.CurrentMoney() << std::endl;
	C1.CashOut(200);
	std::cout << "В первой кассе есть: " << C1.CurrentMoney() << std::endl;

	C2.CashOut(10);
	std::cout << "Во второй кассе есть: " << C2.CurrentMoney() << std::endl;
	C2.CashOut(0);
	std::cout << "Во второй кассе есть: " << C2.CurrentMoney() << std::endl;

	std::cout << "---\n";

	int change = 0;
	std::cout << "Во второй кассе есть: " << C2.CurrentMoney() << std::endl;
	change = C2.Exchange(100, 20);
	std::cout << "Во второй кассе есть: " << C2.CurrentMoney() << std::endl;
	std::cout << "Сдача: " << change << std::endl;

	std::cout << "Во второй кассе есть: " << C2.CurrentMoney() << std::endl;
	change = C2.Exchange(100, 120);
	std::cout << "Во второй кассе есть: " << C2.CurrentMoney() << std::endl;
	std::cout << "Сдача: " << change << std::endl;

	std::cout << "Во второй кассе есть: " << C2.CurrentMoney() << std::endl;
	change = C2.Exchange(100, 100);
	std::cout << "Во второй кассе есть: " << C2.CurrentMoney() << std::endl;
	std::cout << "Сдача: " << change << std::endl;

	std::cout << "Во второй кассе есть: " << C2.CurrentMoney() << std::endl;
	change = C2.Exchange(10, 20);
	std::cout << "Во второй кассе есть: " << C2.CurrentMoney() << std::endl;
	std::cout << "Сдача: " << change << std::endl;


	return 0;
}