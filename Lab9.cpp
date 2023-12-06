// Lab9.cpp
//

#include <iostream>
#include <clocale>
#include <string>
using namespace std;
// Объект – счет в банке. Известны номер счета, фамилия владельца, 
// остаток на счете, тип счета (накопительный, депозит и т.п.), 
// годовой процент начислений, дата последней операции со счетом. 
// Выдать список счетов, ос-таток на которых меньше заданной суммы.
//!Известна информация об одном объекте.
// Написать программу для ввода данных о нескольких объектах и
// обработку информации согласно варианту задания.
struct BankAccount {
    size_t accountNumber;
    string surname;
    double accountBalance;
    int accountType;
    double annualInterestRate;
    string dateOfLastAccountTransaction;
};


int numberOfAccs() {
    int banks_accs;
    cout << "Введите кол-во счетов в банке: ";
    cin >> banks_accs;
    if (banks_accs <= 0) {
        cout << "Введено 0";
        exit(1);
    }
    return banks_accs;
}


BankAccount* makeaccounts(int banks_accs) {
    BankAccount* database = new BankAccount[banks_accs];
    for (int i = 0; i != banks_accs; i++) {
        cout << "ВВОД НОМЕР " << i + 1 << "\n";
        cout << "Фамилия: ";
        cin >> database[i].surname;
        cout << "Номер счёта: ";
        cin >> database[i].accountNumber;
        cout << "Тип счёта: ";
        cin >> database[i].accountType;
        cout << "Введите баланс: ";
        cin >> database[i].accountBalance;
        cout << "Годовой процент: ";
        cin >> database[i].annualInterestRate;
        cout << "Дата последней транкзации: ";
        cin >> database[i].dateOfLastAccountTransaction;
    }
    return database;
}


void print_data(BankAccount* database, int banks_accs) {
    cout << "--------------------ВЫВОД ИНФОРМАЦИИ--------------------" << "\n";
    for (int i = 0; i != banks_accs; i++) {
        cout << "ВЫВОД ИНФОРМАЦИИ КЛИЕНТА №" << database[i].surname << "\n";
        cout << "Номер счёта: " << database[i].accountNumber << "\n";
        cout << "Баланс: " << database[i].accountBalance << "\n";
        cout << "Годовой процент: " << database[i].annualInterestRate << "\n";
        cout << "Тип аккаунта: " << database[i].accountType << "\n";
        cout << "Дата последней транкцзации: " << database[i].dateOfLastAccountTransaction << "\n";
    }
    cout << "--------------------КОНЕЦ ВЫВОДА ИНФОРМАЦИИ--------------------" << "\n";
}


void solution(BankAccount* database, int banks_accs) {
    int usersum;
    cout << "Введите вашу сумму: ";
    cin >> usersum;
    for (int i = 0; i != banks_accs; i++) {
        if (database[i].accountBalance < usersum) {
            cout << database[i].surname << ", Счёт номер: " << i << "\n";
        }
    }
}


int main()
{
    int userchoise;
    setlocale(LC_ALL, "ru");
    int number = numberOfAccs();
    BankAccount* database = makeaccounts(number);
    print_data(database, number);
    solution(database, number);
}
