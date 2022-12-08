#include <iostream>
#include <string>;
#include <iomanip>
using namespace std;

struct Phone {
	double price, screenSize = 0;
	string brand, model, color = "";
	int storage = 0;
	bool dualSim = false;
	int countFromThisPhone = 0;
};

bool isNumber(string& value) {
	if (stod(value)) {
		return true;
	}
	else {
		return false;
	}
	/*try {
		stoi(value);
		return true;
	}
	catch (...) {
		return false;
	}*/
}


struct PhonesList {
	Phone phones[100];
	int size = 0;

	Phone get(int index) {
		return phones[index];
	}

	Phone add(Phone phone) {
		phones[size] = phone;
		size++;
		return phone;
	}

	Phone remove() {
		size--;
		Phone phone = phones[size];
		return phone;
	}
};



void phoneFromInput(PhonesList& list);
void sortingMenu(PhonesList& list);
void phonesFromInput(PhonesList& list);

// Functions
void menu(Phone phones[100], PhonesList& list);
void addPhoneMenu(Phone phones[100], PhonesList& list);
void showPhones(PhonesList& list);
void searchAndPrint(PhonesList list);
void editPhoneMenu(PhonesList& list);
void fetchPhones(PhonesList& list);


//void sortingMenu(PhonesList list);




// Main Function
int main() {
	Phone phones[100] = {};
	PhonesList list = {};
	cout << "" << setw(42) << setfill('-') << "\n" << "|        Добре дошли в програмата       |\n|    за продажба на мобилни телефони    |\n" << setw(41) << setfill('-') << "" << endl << endl;


	Phone phone[100];
	phone[0].brand = "Huawei";
	phone[0].model = "P30 Lite";
	phone[0].color = "Black";
	phone[0].price = 300;
	phone[0].storage = 8;
	phone[0].screenSize = 5.5;
	phone[0].dualSim = true;
	phone[0].countFromThisPhone = 1000;
	list.add(phone[0]);

	phone[1].brand = "Nokia";
	phone[1].model = "5800";
	phone[1].color = "Red";
	phone[1].price = 120;
	phone[1].storage = 8;
	phone[1].screenSize = 5.5;
	phone[1].dualSim = false;
	phone[1].countFromThisPhone = 1000;
	list.add(phone[1]);

	phone[2].brand = "Iphone";
	phone[2].model = "13 Pro Max";
	phone[2].color = "Black";
	phone[2].price = 1300;
	phone[2].storage = 8;
	phone[2].screenSize = 5.5;
	phone[2].dualSim = true;
	phone[2].countFromThisPhone = 1000;
	list.add(phone[2]);

	phone[4].brand = "Iphone";
	phone[4].model = "12";
	phone[4].color = "Black";
	phone[4].price = 250;
	phone[4].storage = 4;
	phone[4].screenSize = 5.5;
	phone[4].dualSim = true;
	phone[4].countFromThisPhone = 1000;
	list.add(phone[4]);

	phone[3].brand = "Motorola";
	phone[3].model = "Neshto si";
	phone[3].color = "Black";
	phone[3].price = 100;
	phone[3].storage = 2;
	phone[3].screenSize = 5.5;
	phone[3].dualSim = true;
	phone[3].countFromThisPhone = 1000;
	list.add(phone[3]);
	menu(phones, list);
}

// Главно менюл
void menu(Phone phones[100], PhonesList& list) {
	system("cls");




	//cout << "" << setw(42) << setfill('-') << "\n" << "|        Добре дошли в програмата       |\n|    за продажба на мобилни телефони    |\n" << setw(41) << setfill('-') << "" << endl << endl;
	int menuNumber = 0;
	char chooice = 'x';


	do {
		cout << "1) Добавяне на нови мобилни телефони" << endl; // 
		cout << "2) Извеждане на екрана" << endl; // 
		cout << "3) Търсене и извеждане на екрана" << endl; //
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
			system("cls");
			addPhoneMenu(phones, list);
			break;
		case 2:
			system("cls");
			showPhones(list);
			break;
		case 3:
			system("cls");
			searchAndPrint(list);
			break;
		case 4:
			system("cls");
			sortingMenu(list);
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			system("cls");
			editPhoneMenu(list);
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
	} while (chooice != 'y');
}


// Меню за добавяне на телефони
void addPhoneMenu(Phone phones[100], PhonesList& list) {
	int menuNumber = 0;
	char chooice = 'x';


	cout << "1) Добавяне на един нов мобилен телефон" << endl;
	cout << "2) Добавяне на списък от мобилни телефони.Въвежда се цяло число n и след него n на брой нови мобилни телефони" << endl;
	cout << "3) Изход" << endl;

	cout << "Моля изберете опция от менюто: ";
	do {
		cin >> menuNumber;
		switch (menuNumber)
		{
		case 1:
			phoneFromInput(list);
			menu(phones, list);
			break;
		case 2:
			phonesFromInput(list);
			menu(phones, list);
			break;
		case 3:
			cout << "Вие напуснахте фунцкията!" << endl;
			chooice = 'y';
			menu(phones, list);
			break;
		default:
			cout << "Моля въведете число [1 - 2]" << endl;
			return;
		}
	} while (chooice != 'y');
}


// Показване на наличните телефони в "базата данни" - Мисля 100% готова
void showPhones(PhonesList& list) {
	if (list.size == 0) {
		cout << "Базата данни е празна!" << endl << endl;
	}
	else {
		cout << setfill(' ') << setw(4) << left << "No" << setw(20) << "| МАРКА |"
			<< setw(18) << "| МОДЕЛ |"
			<< setw(18) << "| ЦВЯТ |"
			<< setw(18) << "| ЦЕНА |"
			<< setw(18) << "| ПАМЕТ |"
			<< setw(20) << "| ДИСПЕЛЙ |"
			<< setw(14) << "| DUAL SIM |"
			<< setw(15) << "| БРОЙ |"
			<< endl;
		for (int i = 0; i < list.size; i++) {
			cout << setfill(' ') << left << setw(4) << i + 1 << "| "
				<< setw(13) << list.phones[i].brand << "| "
				<< setw(11) << list.phones[i].model << left << "| "
				<< setw(12) << left << list.phones[i].color << "| "
				<< setw(12) << list.phones[i].price << "| "
				<< setw(3) << left << list.phones[i].storage << left << " GB" << setw(5) << "" << "| "
				<< setw(11) << list.phones[i].screenSize << "| "
				<< setw(14) << (list.phones[i].dualSim ? "Да" : "Не") << "| "
				<< setw(12) << list.phones[i].countFromThisPhone
				<< endl;
		}
		cout << endl;
	}
}


// Показва телефоните с най-малко памет и телефоните, които поддържат DualSIM - мисля 100% готова
void searchAndPrint(PhonesList list) {
	int indexOfMinStoragePhone = 0;
	int menuNumber = 0;
	char chooice = 'x';
	int n = 0;

	cout << "1) Извеждане на мобилни телефони с най - малка памет" << endl;
	cout << "2) Извеждане на мобилни телефони, работещи с две сим карти" << endl;
	cout << "3) Назад" << endl;
	cout << "Моля изберете функция: ";
	do {
		cin >> menuNumber;
		switch (menuNumber)
		{
		case 1:


			cout << "Телефоните, с най-малко памет: " << endl;
			cout << setfill(' ') << setw(4) << left << "No" << setw(20) << "| МАРКА |"
				<< setw(18) << "| МОДЕЛ |"
				<< setw(18) << "| ЦВЯТ |"
				<< setw(18) << "| ЦЕНА |"
				<< setw(18) << "| ПАМЕТ |"
				<< setw(20) << "| ДИСПЕЛЙ |"
				<< setw(14) << "| DUAL SIM |"
				<< setw(15) << "| БРОЙ |"
				<< endl;

			for (int i = 0; i < list.size; i++) {
				if (list.phones[i].storage < list.phones[indexOfMinStoragePhone].storage) {
					indexOfMinStoragePhone = i;
				}
			}

			for (int i = 0; i <= list.size; i++) {
				if (list.phones[indexOfMinStoragePhone].storage == list.phones[i].storage) {
					cout << setfill(' ') << left << setw(4) << /*?*/ n + 1 << "| "
						<< setw(13) << list.phones[i].brand << "| "
						<< setw(11) << list.phones[i].model << left << "| "
						<< setw(12) << left << list.phones[i].color << "| "
						<< setw(12) << list.phones[i].price << "| "
						<< setw(3) << left << list.phones[i].storage << left << " GB" << setw(5) << "" << "| "
						<< setw(11) << list.phones[i].screenSize << "| "
						<< setw(14) << (list.phones[i].dualSim ? "Да" : "Не") << "| "
						<< setw(12) << list.phones[i].countFromThisPhone
						<< endl;
					n++;
				}
			}
			cout << endl;
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
			for (int i = 0; i < list.size; i++) {
				if (list.phones[i].dualSim == true) {
					cout << setfill(' ') << left << setw(4) << /*?*/ n + 1 << "| "
						<< setw(13) << list.phones[i].brand << "| "
						<< setw(11) << list.phones[i].model << left << "| "
						<< setw(12) << left << list.phones[i].color << "| "
						<< setw(12) << list.phones[i].price << "| "
						<< setw(3) << left << list.phones[i].storage << left << " GB" << setw(5) << "" << "| "
						<< setw(11) << list.phones[i].screenSize << "| "
						<< setw(14) << (list.phones[i].dualSim ? "Да" : "Не") << "| "
						<< setw(12) << list.phones[i].countFromThisPhone
						<< endl;
					n++;
				}
			}
			cout << endl;
			break;
		case 3:
			cout << "Вие напуснахте функцията!" << endl;
			break;
		default:
			cout << "Грешка!" << endl;
			return;
		}
	} while (chooice != 'y');
}


// Въвеждане на телефон !!!! ПРОВЕРКА ЗА ЦЕНА, ПАМЕТ, РАЗМЕР НА ЕКРАНА И БРОЙ ТЕЛЕФОНИ
void phoneFromInput(PhonesList& list) {
	if (list.size < 100) {
		string brand, model, color = "";
		double price = 0.0;
		/*string priceStr = "";*/
		double screenSize = 0.0;
		int storage = 0;
		bool dualSim = false;
		int countFromThisPhone = 0;

		Phone phone[100];
		cout << "Въведете марка на телефона: ";
		cin >> brand;
		cout << "Въведете модел на телефона: ";
		cin.ignore(10, '\n');
		getline(cin, model);
		cout << "Въведете цвят на телефона: ";
		cin >> color;
		cout << "Въведете цена на телефона: ";
		cin >> price;

		/*while (true)
		{
			cout << "Въведете цена на телефона: ";
			cin >> priceStr;
			if (isNumber(priceStr)) {
				price = stod(priceStr);
				break;
			}
			else {
				break;
			}

		}*/


		cout << "Въведете вградената памет в (GB): ";
		cin >> storage;
		cout << "Въведете в размер на екрана в (screenSize): ";
		cin >> screenSize;

		while (true) {
			cout << "Въведете може ли да работи с две SIM карти (yes/no): ";
			string dualSimStr;
			cin >> dualSimStr;
			if (dualSimStr == "yes") {
				dualSim = true;
				break;
			}
			else if (dualSimStr == "no") {
				dualSim = false;
				break;
			}
		}
		cout << "Въведете бройка от този телефон: ";
		cin >> countFromThisPhone;

		phone[list.size].brand = brand;
		phone[list.size].model = model;
		phone[list.size].color = color;
		phone[list.size].price = price;
		phone[list.size].storage = storage;
		phone[list.size].screenSize = screenSize;
		phone[list.size].dualSim = dualSim;
		phone[list.size].countFromThisPhone = countFromThisPhone;
		list.add(phone[list.size]);
	}
	else {
		cout << "Няма достатъчно място в склада!" << endl;
	}
}


// Въвеждане на телефони
void phonesFromInput(PhonesList& list) {
	int n;
	cout << "Въведете колко телефона, желаете да добавите: ";
	cin >> n;
	cout << endl;
	string brand, model, color = "";
	double price = 0.0;
	double screenSize = 0.0;
	int storage = 0;
	bool dualSim = false;
	int countFromThisPhone = 0;

	for (int i = 0; i < n; i++) {
		cout << "Въвеждане на данни за телефон № " << i + 1 << endl;
		Phone phone[100];
		cout << "Въведете марка на телефона: ";
		cin >> brand;
		cout << "Въведете модел на телефона: ";
		cin >> model;
		cout << "Въведете цвят на телефона: ";
		cin >> color;
		cout << "Въведете цена на телефона: ";
		cin >> price;
		cout << "Въведете вградената памет в (GB): ";
		cin >> storage;
		cout << "Въведете в размер на екрана в (screenSize): ";
		cin >> screenSize;

		while (true) {
			cout << "Въведете може ли да работи с две SIM карти (yes/no): ";
			string dualSimStr;
			cin >> dualSimStr;
			if (dualSimStr == "yes") {
				dualSim = true;
				break;
			}
			else if (dualSimStr == "no") {
				dualSim = false;
				break;
			}
		}
		cout << "Въведете бройка от този телефон: ";
		cin >> countFromThisPhone;

		phone[list.size].brand = brand;
		phone[list.size].model = model;
		phone[list.size].color = color;
		phone[list.size].price = price;
		phone[list.size].storage = storage;
		phone[list.size].screenSize = screenSize;
		phone[list.size].dualSim = dualSim;
		phone[list.size].countFromThisPhone = countFromThisPhone;
		list.add(phone[list.size]);
		cout << endl;
	}
}


// Сортиране на телефони по низходящ ред на цената
void sortingMenu(PhonesList& list) {
	Phone tmp;
	for (int i = 0; i < list.size; i++) {
		for (int j = i + 1; j < list.size; j++) {
			if (list.phones[i].price > list.phones[j].price) {
				tmp = list.phones[i];
				list.phones[i] = list.phones[j];
				list.phones[j] = tmp;
			}
		}
	}
}


// Корекция на даден телефон
void editPhoneMenu(PhonesList& list) {
	PhonesList listOfPhones = list;

	string searchBrand = "";
	string searchModel = "";
	cout << "Въведете марката на телефона, който желаете да редактирате: ";
	cin >> searchBrand;
	cout << "Въведете модел на телефона: ";
	cin.ignore();
	getline(cin, searchModel);

	int index = 0;

	// Входните данни ги прави на малки букви
	for (int i = 0; i < searchBrand.length(); i++) {
		if (searchBrand[i] >= 'A' && searchBrand[i] <= 'Z') {
			searchBrand[i] = searchBrand[i] + 32;
		}
	}

	for (int i = 0; i < searchModel.length(); i++) {
		if (searchModel[i] >= 'A' && searchModel[i] <= 'Z') {
			searchModel[i] = searchModel[i] + 32;
		}
	}

	for (int i = 0; i < list.size; i++) {
		for (int j = 0; j < (listOfPhones.phones[i].brand).length(); j++) {
			if (listOfPhones.phones[i].brand[j] >= 'A' && listOfPhones.phones[i].brand[j] <= 'Z') {
				listOfPhones.phones[i].brand[j] = listOfPhones.phones[i].brand[j] + 32;
			}
		}

		for (int j = 0; j < (listOfPhones.phones[i].model).length(); j++) {
			if (listOfPhones.phones[i].model[j] >= 'A' && listOfPhones.phones[i].model[j] <= 'Z') {
				listOfPhones.phones[i].model[j] = listOfPhones.phones[i].model[j] + 32;
			}
		}

		if (searchBrand == listOfPhones.phones[i].brand && searchModel == listOfPhones.phones[i].model) {
			if (listOfPhones.phones[i].countFromThisPhone > 0) {

			index = i;
			string brand, model, color = "";
			double price = 0.0;
			/*string priceStr = "";*/
			double screenSize = 0.0;
			int storage = 0;
			bool dualSim = false;
			int countFromThisPhone = 0;

			Phone phone[100];
			cout << "Въведете марка на телефона: ";
			cin >> brand;
			cout << "Въведете модел на телефона: ";
			cin.ignore(10, '\n');
			getline(cin, model);
			cout << "Въведете цвят на телефона: ";
			cin >> color;
			cout << "Въведете цена на телефона: ";
			cin >> price;
			cout << "Въведете вградената памет в (GB): ";
			cin >> storage;
			cout << "Въведете в размер на екрана в (screenSize): ";
			cin >> screenSize;

			while (true) {
				cout << "Въведете може ли да работи с две SIM карти (yes/no): ";
				string dualSimStr;
				cin >> dualSimStr;
				if (dualSimStr == "yes") {
					dualSim = true;
					break;
				}
				else if (dualSimStr == "no") {
					dualSim = false;
					break;
				}
			}
			cout << "Въведете бройка от този телефон: ";
			cin >> countFromThisPhone;

			list.phones[index].brand = brand;
			list.phones[index].model = model;
			list.phones[index].color = color;
			list.phones[index].price = price;
			list.phones[index].storage = storage;
			list.phones[index].screenSize = screenSize;
			list.phones[index].dualSim = dualSim;
			list.phones[index].countFromThisPhone = countFromThisPhone;
			}
			else {
				break;
			}
		}
		else {
			cout << "Не съществува такъв телефон в базата данни!" << endl;
		}
	}


}


// Одит  на телефони 
void fetchPhones(PhonesList& list) {

}