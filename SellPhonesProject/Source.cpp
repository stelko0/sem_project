#include <iostream>
#include <string>;
#include <iomanip>
using namespace std;

struct Phone {
	double price, inch = 0;
	string brand, model, color = "";
	int rom = 0;
	bool dualSim = false;
	int countFromThisPhone = 0;
};

// Functions
void menu(Phone phones[100], int &n);
void addPhone(Phone phones[100], int& n);
void showPhones(Phone phones[100], int& n);
void searchAndPrint(Phone phones[100], int& n);



// Main Function
int main() {
	int n = 0;
	Phone phones[100] = {};
	menu(phones, n);
}

// Menu Funcion
void menu(Phone phones[100], int &n) {
	// telefonite sa samo za proba
	/*phones[0].brand = "Huawei";
	phones[0].model = "P30";
	phones[0].color = "Black";
	phones[0].price = 300;
	phones[0].rom = 8;
	phones[0].inch = 5.5;
	phones[0].dualSim = true;
	phones[0].countFromThisPhone = 1000;


	phones[1].brand = "Iphone";
	phones[1].model = "11";
	phones[1].color = "Gold";
	phones[1].price = 1300;
	phones[1].rom = 16;
	phones[1].inch = 6.5;
	phones[1].dualSim = true;
	phones[1].countFromThisPhone = 100;


	phones[2].brand = "Samsung";
	phones[2].model = "Galaxy";
	phones[2].color = "White";
	phones[2].price = 150;
	phones[2].rom = 4;
	phones[2].inch = 5;
	phones[2].dualSim = false;
	phones[2].countFromThisPhone = 2;

	phones[3].brand = "Lenovo";
	phones[3].model = "K6";
	phones[3].color = "White";
	phones[3].price = 150;
	phones[3].rom = 4;
	phones[3].inch = 5;
	phones[3].dualSim = false;
	phones[3].countFromThisPhone = 2;
	n = 4
	*/

	cout << "" << setw(42) << setfill('-') << "\n" << "|        Добре дошли в програмата       |\n|    за продажба на мобилни телефони    |\n" << setw(41) << setfill('-') << "" << endl << endl;
	int menuNumber = -1;
	char chooice = 'x';
	// n e samo za proba


	do {
		cout << "1) Добавяне на нови мобилни телефони" << endl;
		cout << "2) Извеждане на екрана" << endl;
		cout << "3) Търсене и извеждане на екрана" << endl;
		cout << "4) Подреждане на основния масив с мобилни телефони, без да се извежда на екрана" << endl;
		cout << "5) Управление на файл" << endl;

		// Допълнително първо (+ базова задача)
		cout << "6) Одит на мобилни телефони в наличност в под меню" << endl;
		cout << "7) Корекция на данни за даден телефон" << endl;
		cout << "8) Продажба на мобилни телефони" << endl;
		cout << "9) Данните в програмата да могат да се запазят в файл (двоичен) между две стратирания на програмата" << endl;
		cout << "10) Изход от програмата" << endl;
		cout << endl;
		cout << "Моля изберете опция от менюто: ";
		cin >> menuNumber;
		cout << endl;
		switch (menuNumber) {
		case 1:
			addPhone(phones, n);
			break;
		case 2:
			showPhones(phones, n);
			break;
		case 3:
			searchAndPrint(phones, n);
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			cout << "Вие напуснахте програмата!" << endl;
			chooice = 'y';
			break;
		default:
			cout << "Моля въведете число [1 - 10]" << endl;
			break;
		}
	} while (chooice == 'x');
}

void addPhone(Phone phones[100], int &n) {
	cout << "N: " << n << endl;
	int menuNumber = -1;
	char chooice = 'x';
	string dualSim = "";

	int totalPhones = 0;
	int nPhones = 0;

	cout << "1) Добавяне на един нов мобилен телефон" << endl;
	cout << "2) Добавяне на списък от мобилни телефони.Въвежда се цяло число n и след него n на брой нови мобилни телефони" << endl;
	cout << "3) Изход" << endl;

	cout << "Моля изберете опция от менюто: ";
	do {
		cin >> menuNumber;
		switch (menuNumber)
		{
		case 1:
			chooice = 'y';
			cout << "* Вие влезнахте в -> [Добавяне на един нов мобилен телефон]" << endl;
			cout << "Въведете марка на телефона: ";
			cin >> phones[n].brand;
			cout << "Въведете модел на телефона: ";
			cin >> phones[n].model;
			cout << "Въведете цвят на телефона: ";
			cin >> phones[n].color;
			cout << "Въведете цена на телефона : ";
			cin >> phones[n].price;
			cout << "Въведете вградената памет в (GB): ";
			cin >> phones[n].rom;
			cout << "Въведете в размер на екрана в (inch): ";
			cin >> phones[n].inch;
			cout << "Въведете може ли да работи с две SIM карти (yes/no): ";
			cin >> dualSim;
			cout << "Въведете бройка от този телефон: ";
			cin >> phones[n].countFromThisPhone;

			if (dualSim == "yes") {
				phones[n].dualSim = true;
			}
			else if (dualSim == "no") {
				phones[n].dualSim = false;
			}
			else {
				cout << "Моля въведете [yes/no]";
				cin >> dualSim;
			}
			n++;
			break;
		case 2:
			cout << "Вие влезнахте в -> [Добавяне на списък от мобилни телефони.Въвежда се цяло число n и след него n на брой нови мобилни телефони]" << endl;
			cout << "Въведете колко телефона желаете да добавите: ";
			cin >> nPhones;
			cout << n;
			totalPhones = n + nPhones;
			           
			for (int i = n; i < totalPhones; i++) {
				cout << "Въведете марка на телефона: ";
				cin >> phones[n].brand;
				cout << "Въведете модел на телефона: ";
				cin >> phones[n].model;
				cout << "Въведете цвят на телефона: ";
				cin >> phones[n].color;
				cout << "Въведете цена на телефона : ";
				cin >> phones[n].price;
				cout << "Въведете вградената памет в (GB): ";
				cin >> phones[n].rom;
				cout << "Въведете в размер на екрана в (inch): ";
				cin >> phones[n].inch;
				cout << "Въведете може ли да работи с две SIM карти (yes/no): ";
				cin >> dualSim;
				cout << "Въведете бройка от този телефон: ";
				cin >> phones[n].countFromThisPhone;

				if (dualSim == "yes") {
					phones[n].dualSim = true;
				}
				else if (dualSim == "no") {
					phones[n].dualSim = false;
				}
				else {
					cout << "Моля въведете [yes/no]";
					cin >> dualSim;
				}
				n++;
				cout << n;
			}
			menu(phones, n);
			break;
		case 3:
			cout << "Вие напуснахте фунцкията!" << endl;
			chooice = 'y';
			menu(phones, n);
			break;
		default:
			cout << "Моля въведете число [1 - 2]" << endl;
			return;
		}
	} while (chooice == 'x');
}

void showPhones(Phone phones[100], int& n) {
	cout << n << endl;
	cout << setfill(' ') << setw(4) << left << "No" << setw(20) << "| МАРКА |"
		<< setw(18) << "| МОДЕЛ |"
		<< setw(18) << "| ЦВЯТ |"
		<< setw(18) << "| ЦЕНА |"
		<< setw(18) << "| ПАМЕТ |"
		<< setw(20) << "| ДИСПЕЛЙ |"
		<< setw(14) << "| DUAL SIM |"
		<< setw(15) << "| БРОЙ |"
		<< endl;
	for (int i = 0; i < n; i++) {
		cout << setfill(' ') << left << setw(4) << i + 1 << "| "
			<< setw(13) << phones[i].brand << "| "
			<< setw(11) << phones[i].model << left << "| "
			<< setw(12) << left << phones[i].color << "| "
			<< setw(12) << phones[i].price << "| "
			<< setw(3) << left << phones[i].rom << left << " GB" << setw(5) << "" << "| "
			<< setw(11) << phones[i].inch << "| "
			<< setw(14) << (phones[i].dualSim ? "Да" : "Не") << "| "
			<< setw(12) << phones[i].countFromThisPhone
			<< endl;
	}
	cout << endl;
}

// Мислене на алгоритъм за най-малко памет
void searchAndPrint(Phone phones[100], int& n) {
	int menuNumber = -1;
	char chooice = 'x';
	cout << "1) Извеждане на мобилни телефони с най - малка памет" << endl;	cout << "2) Извеждане на мобилни телефони, работещи с две сим карти" << endl;	cout << "3) Назад" << endl;
	int smallerROM = 0;
	cout << "Моля изберете функция: ";
	do {
		cin >> menuNumber;
		switch (menuNumber)
		{
		case 1:
			chooice = 'y';
			for (int i = 0; i < n; i++) {
				if (phones[smallerROM].rom > phones[i].rom) {
					smallerROM = i;
				}
				cout << phones[smallerROM].brand;
			}
			break;

		case 2:
			chooice = 'y';
			cout << "Телефоните, които поддържат Dual SIM" << endl;
			cout << setfill(' ') << setw(4) << left << "No" << setw(20) << "| МАРКА |"
				<< setw(18) << "| МОДЕЛ |"
				<< setw(18) << "| ЦВЯТ |"
				<< setw(18) << "| ЦЕНА |"
				<< setw(18) << "| ПАМЕТ |"
				<< setw(20) << "| ДИСПЕЛЙ |"
				<< setw(14) << "| DUAL SIM |"
				<< setw(15) << "| БРОЙ |"
				<< endl;
			for (int i = 0; i < n; i++) {
				if (phones[i].dualSim == true) {
					cout << setfill(' ') << left << setw(4) << i + 1 << "| "
						<< setw(13) << phones[i].brand << "| "
						<< setw(11) << phones[i].model << left << "| "
						<< setw(12) << left << phones[i].color << "| "
						<< setw(12) << phones[i].price << "| "
						<< setw(3) << left << phones[i].rom << left << " GB" << setw(5) << "" << "| "
						<< setw(11) << phones[i].inch << "| "
						<< setw(14) << (phones[i].dualSim ? "Да" : "Не") << "| "
						<< setw(12) << phones[i].countFromThisPhone
						<< endl;
				}
			}
			cout << endl;
			break;
		case 3:
			cout << "Вие напуснахте функцията!" << endl;
			menu(phones, n);
			break;
		default:
			cout << "Грешка!" << endl;
			return;
		}
	} while (chooice == 'x');

}

