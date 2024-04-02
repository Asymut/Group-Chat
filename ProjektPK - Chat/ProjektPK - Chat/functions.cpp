#include "Header.h"

std::vector<std::vector<std::string>> wczytaj_baze(const std::string& dane)
{
	std::vector<std::vector<std::string>> baza_danych;
	std::string linia;
	
	std::ifstream plik(dane);
	
	if (!plik) {
		std::cerr << "Plik uzytkownicy.txt nie istnieje" << std::endl;
		return baza_danych;
	}
	
	while (std::getline(plik, linia))
	{
		std::vector<std::string> wiersz;
		std::istringstream iss(linia);
		std::string pole;
		while (iss >> pole)
		{
			wiersz.push_back(pole);

		}
		baza_danych.push_back(wiersz);
	}
	return baza_danych;
}

std::vector<Uzytkownicy> zaladuj_klasy(std::vector<std::vector<std::string>>baza_danych, std::vector<Uzytkownicy> Users)
{
	for (int i = 1; i < baza_danych.size(); i++) {
		Uzytkownicy user(std::stoi(baza_danych[i][0]), baza_danych[i][1], baza_danych[i][2], baza_danych[i][3], baza_danych[i][4], baza_danych[i][5], baza_danych[i][6], baza_danych[i][7], baza_danych[i][8], std::stoi(baza_danych[i][9]));
		Users.push_back(user);
	}
	return Users;
}

std::vector<Podst::Uzytkownicy> zaladuj_klasyP(std::vector<std::vector<std::string>>baza_danych, std::vector<Uzytkownicy> Users, std::vector<Podst::Uzytkownicy>UsersP)
{
	for (int i = 1; i < baza_danych.size(); i++) {
		if (baza_danych[i][8] == "podstawowy")
		{
			Podst userP(std::stoi(baza_danych[i][0]), baza_danych[i][1], baza_danych[i][2], baza_danych[i][3], baza_danych[i][4], baza_danych[i][5], baza_danych[i][6], baza_danych[i][7], baza_danych[i][8], std::stoi(baza_danych[i][9]));
			UsersP.push_back(userP);
		}
	}
	return UsersP;
}

std::vector<Mody::Uzytkownicy> zaladuj_klasyM(std::vector<std::vector<std::string>>baza_danych, std::vector<Uzytkownicy> Users, std::vector<Podst::Uzytkownicy>UsersM)
{
	for (int i = 1; i < baza_danych.size(); i++) {
		if (baza_danych[i][8] == "moderator")
		{
			Mody userM(std::stoi(baza_danych[i][0]), baza_danych[i][1], baza_danych[i][2], baza_danych[i][3], baza_danych[i][4], baza_danych[i][5], baza_danych[i][6], baza_danych[i][7], baza_danych[i][8], std::stoi(baza_danych[i][9]));
			UsersM.push_back(userM);
		}
	}
	return UsersM;
}

std::vector<Admini::Uzytkownicy> zaladuj_klasyA(std::vector<std::vector<std::string>>baza_danych, std::vector<Uzytkownicy> Users, std::vector<Podst::Uzytkownicy>UsersA)
{
	for (int i = 1; i < baza_danych.size(); i++) {
		if (baza_danych[i][8] == "administrator")
		{
			Admini userA(std::stoi(baza_danych[i][0]), baza_danych[i][1], baza_danych[i][2], baza_danych[i][3], baza_danych[i][4], baza_danych[i][5], baza_danych[i][6], baza_danych[i][7], baza_danych[i][8], std::stoi(baza_danych[i][9]));
			UsersA.push_back(userA);
		}
	}
	return UsersA;
}


Uzytkownicy::Uzytkownicy(int lp, std::string name, std::string surname, std::string nick, std::string password, std::string city, std::string tel, std::string mail, std::string type, int kara)
{
	nr_konta = lp;
	imie = name;
	nazwisko = surname;
	login = nick;
	haslo = password;
	miasto = city;
	nr_telefonu = tel;
	email = mail;
	rodzaj_konta = type;
	ban = kara;
}

Podst::Podst(int lp, std::string name, std::string surname, std::string nick, std::string password, std::string city, std::string tel, std::string mail, std::string type, int kara)
{
	nr_konta = lp;
	imie = name;
	nazwisko = surname;
	login = nick;
	haslo = password;
	miasto = city;
	nr_telefonu = tel;
	email = mail;
	rodzaj_konta = type;
	ban = kara;
}

Mody::Mody(int lp, std::string name, std::string surname, std::string nick, std::string password, std::string city, std::string tel, std::string mail, std::string type, int kara)
{
	nr_konta = lp;
	imie = name;
	nazwisko = surname;
	login = nick;
	haslo = password;
	miasto = city;
	nr_telefonu = tel;
	email = mail;
	rodzaj_konta = type;
	ban = kara;
}

Admini::Admini(int lp, std::string name, std::string surname, std::string nick, std::string password, std::string city, std::string tel, std::string mail, std::string type, int kara)
{
	nr_konta = lp;
	imie = name;
	nazwisko = surname;
	login = nick;
	haslo = password;
	miasto = city;
	nr_telefonu = tel;
	email = mail;
	rodzaj_konta = type;
	ban = kara;
}


int Uzytkownicy::logowanie(std::vector<Uzytkownicy> Users)
{
	std::string login, haslo;

	std::cout << "ZALOGUJ SIE: " << std::endl;
	bool re_menu = 1; int id;
	while (re_menu)
	{
		std::cout << "Podaj login do swojego konta: " << std::endl;
		std::cin >> login;

		for (int i = 0; i < Users.size(); i++)
		{
			if (login == Users[i].login)
			{
				std::cout << "Podaj haslo do swojego konta: " << std::endl;
				std::cin >> haslo;
				if (haslo == Users[i].haslo)
				{
					if (Users[i].ban == 1)
					{
						system("cls");
						std::cout << "KONTO " << Users[i].login << " JEST ZBANOWANE! " << std::endl;
					}
					else {
						system("cls");
						std::cout << "UDALO SIE ZALOGOWAC! Witaj " << Users[i].login << std::endl;
						id = Users[i].nr_konta;
						re_menu = 0;
					}
				}

			}
		}
		if (re_menu == 1)
			std::cout << "Podane dane sa nieprawidlowe!" << std::endl;

	}
	return id;
}

void Uzytkownicy::pokaz_uzytkownikow(std::vector<Uzytkownicy> Users)
{
	std::cout << "Uzytkownicy chatu grupowego: " << std::endl;
	for (int i = 0; i < Users.size(); i++) {
		std::cout << i + 1 << ". " << Users[i].login << " " << Users[i].imie << " " << Users[i].nazwisko << " " << Users[i].rodzaj_konta << std::endl;
	}
}

void Uzytkownicy::obsluga_menu(Uzytkownicy** tablica_kont, std::vector<Uzytkownicy> Users, Chat chat1)
{

	//System logowania - zapis sesji - id zalogowanego oraz rodzaj konta zalogowanego
	int id_zalogowane = Users[0].logowanie(Users);
	Users[0].biezacy_uzytkownik = id_zalogowane;
	std::string rodzaj_konta = Users[id_zalogowane - 1].rodzaj_konta;
	std::string nickname = Users[id_zalogowane - 1].login;

	bool re_menu = 1;
	int operacja;
	while (re_menu) {
		std::cout << "-------Panel sterowania------- " << std::endl;
		std::cout << " Jaka operacje chcesz wykonac: " << std::endl;
		std::cout << "--------------<>--------------" << std::endl;

		std::cout << " 1. Wejdz w chat. " << std::endl;
		std::cout << " 2. Pokaz liste uzytkownikow chatu. " << std::endl;
		std::cout << " 3. Pokaz informacje o profilu. " << std::endl;

		if (rodzaj_konta == "podstawowy")
		{
			std::cout << " 4. Wyjdz z aplikacji. " << std::endl;
			std::cin >> operacja;

			if ((operacja >= 1) and (operacja <= 4)) {
				switch (operacja)
				{
				case 1:
					chat1.wyswietl_chat();
					tablica_kont[0]->napisz_wiadomosc(nickname);
					break;
				case 2:
					tablica_kont[0]->pokaz_uzytkownikow(Users);
					break;
				case 3:
					std::cout << Users;
					break;
				case 4:
					Users[0].zapisz_klasy(Users);
					for (int i = 0; i < 3; i++) {
						delete tablica_kont[i];
					}
					delete[] tablica_kont;
					exit(0);
				default: std::cout << "Nie ma takiej opcji w menu!";
				}
				getchar(); getchar(); // umozliwia wstrzymanie wyniku i wznowienie petli po nacisnieciu enter (funkcja czeka na enter)
				system("cls");
			}
			else if ((operacja < 1) or (operacja > 4))
				std::cerr << "To nie jest liczba z przedzialu <1;4>! Bledne dane!" << std::endl; // jesli nie jest system walidacji "cerr" wyswietli komunikat 
		}

		else if (rodzaj_konta == "moderator")
		{
			std::cout << " 4. Zbanuj uzytkownika. " << std::endl;
			std::cout << " 5. Wyjdz z aplikacji. " << std::endl;
			std::cin >> operacja;

			if ((operacja >= 1) and (operacja <= 5)) {
				switch (operacja)
				{
				case 1:
					chat1.wyswietl_chat();
					tablica_kont[1]->napisz_wiadomosc(nickname);
					break;
				case 2:
					tablica_kont[1]->pokaz_uzytkownikow(Users);
					break;
				case 3:
					std::cout << Users;
					break;
				case 4:
					Users[0].ban_uzytkownika(Users);
					break;
				case 5:
					Users[0].zapisz_klasy(Users);
					for (int i = 0; i < 3; i++) {
						delete tablica_kont[i];
					}
					delete[] tablica_kont;
					exit(0);
				default: std::cout << "Nie ma takiej opcji w menu!";
				}
				getchar(); getchar();// umozliwia wstrzymanie wyniku i wznowienie petli po nacisnieciu enter (funkcja czeka na enter)
				system("cls");
			}
			else if ((operacja < 1) or (operacja > 5))
				std::cerr << "To nie jest liczba z przedzialu <1;5>! Bledne dane!" << std::endl; // jesli nie jest system walidacji "cerr" wyswietli komunikat 
		}

		else if (rodzaj_konta == "administrator") {
			std::cout << " 4. Zbanuj uzytkownika. " << std::endl;
			std::cout << " 5. Dodaj nowego uzytkownika. " << std::endl;
			std::cout << " 6. Wyjdz z aplikacji. " << std::endl;
			std::cin >> operacja;

			if ((operacja >= 1) and (operacja <= 6)) {
				switch (operacja)
				{
				case 1:
					chat1.wyswietl_chat();
					tablica_kont[2]->napisz_wiadomosc(nickname);
					break;
				case 2:
					tablica_kont[2]->pokaz_uzytkownikow(Users);
					break;
				case 3:
					std::cout << Users;
					break;
				case 4:
					Users[0].ban_uzytkownika(Users);
					break;
				case 5:
					Users[0].dodaj_uzytkownika(Users);
					break;
				case 6:
					Users[0].zapisz_klasy(Users);
					for (int i = 0; i < 3; i++) {
						delete tablica_kont[i];
					}
					delete[] tablica_kont;
					exit(0);
				default: std::cout << "Nie ma takiej opcji w menu!";
				}
				getchar(); getchar();// umozliwia wstrzymanie wyniku i wznowienie petli po nacisnieciu enter (funkcja czeka na enter)
				system("cls");
			}
			else if ((operacja < 1) or (operacja > 6))
				std::cerr << "To nie jest liczba z przedzialu <1;6>! Bledne dane!" << std::endl; // jesli nie jest system walidacji "cerr" wyswietli komunikat 
		}

		else if (std::cin.fail()) {
			std::cerr << "Podano nieprawidlowe dane wejsciowe (nie jest to liczba)" << std::endl;
			std::cin.clear(); //  cin.clear() usuwa flage bledu wejscia - to co zwrocila funkcja cin.fail
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	//ignoruje niepoprane danye wejsciowe - umozliwia ponowne dzialanie menu w petli i zapytanie o wartosc operacji
		}

	}
}

void Uzytkownicy::ban_uzytkownika(std::vector<Uzytkownicy>& Users)
{
	std::string nick;
	char wybor = 'w';
	std::cout << "Zmiana statusu konta!" << std::endl;
	std::cout << "---------<>--------- " << std::endl;

	std::cout << "Podaj nick uzytkownika, ktorego status konta chcesz zmienic: " << std::endl;
	std::cin >> nick;

	for (int i = 0; i < Users.size(); i++)
	{
		if (Users[i].login == nick)
		{
			if (Users[i].ban == 0)
			{
				if (Users[i].rodzaj_konta == "administrator")
					std::cout << "Nie mozna zbanowac konta administratora!" << std::endl;
				else
				{
					std::cout << "Czy na pewno chcesz zbanowac uzytkownika " << nick << "? (T/N)" << std::endl;
					std::cin >> wybor;
					if (wybor == 'T' or wybor == 't')
					{
						Users[i].ban = 1;
						std::cout << "Uzytkownik " << nick << " zostal zbanowany z aplikacji!";

					}

				}
			}
			else if (Users[i].ban == 1)
			{
				std::cout << "Czy na pewno chcesz odbanowac uzytkownika " << nick << "? (T/N)" << std::endl;
				std::cin >> wybor;
				if (wybor == 'T' or wybor == 't')
				{

					Users[i].ban = 0;
					std::cout << "Uzytkownik " << nick << " zostal odbanowany z aplikacji!";
				}

			}
		}


	}
}

void Uzytkownicy::dodaj_uzytkownika(std::vector<Uzytkownicy>& Users)
{
	std::string imie, nazwisko, nickname, haslo, miasto, email, rodzaj_konta;
	int nr_tel;
	std::cout << "Dodaj nowego czlonka chatu grupowego: " << std::endl;
	std::cout << "imie: ";
	std::cin >> imie;
	std::cout << "nazwisko: ";
	std::cin >> nazwisko;
	std::cout << "nickname: ";
	std::cin >> nickname;
	std::cout << "haslo: ";
	std::cin >> haslo;
	std::cout << "miasto: ";
	std::cin >> miasto;
	std::cout << "nr_telefonu: ";
	std::cin >> nr_tel;
	std::cout << "email: ";
	std::cin >> email;
	bool i = 0;
	do {
		std::cout << "rodzaj_konta: ";
		std::cin >> rodzaj_konta;
		if (rodzaj_konta != "podstawowy" && rodzaj_konta != "administrator" && rodzaj_konta != "moderator")
		{
			std::cout << "Podano nieprawidlowy typ konta!" << std::endl;
		}
		else i = 1;
	} while (i == 0);

	std::ofstream plik("pliki_txt/uzytkownicy.txt", std::ios_base::app);
	if (plik)
	{
		int liczba = Users.size() + 1;
		std::string zawartosc = std::to_string(liczba) + " " + imie + " " + nazwisko + " " + nickname + " " + haslo + " " + miasto + " " + std::to_string(nr_tel) + " " + email + " " + rodzaj_konta + " " + "0";
		plik << zawartosc << std::endl;
		plik.close();
		std::cout << "Dodano uzytkownika " << nickname << " do bazy uzytkownikow aplikacji." << std::endl;

		Uzytkownicy user(liczba, imie, nazwisko, nickname, haslo, miasto, std::to_string(nr_tel), email, rodzaj_konta, 0);
		Users.push_back(user);

	}
	else
		std::cerr << "Nie mo¿na otworzyæ pliku." << std::endl;
}

void Uzytkownicy::zapisz_klasy(std::vector<Uzytkownicy> Users)
{
	std::ofstream plik("pliki_txt/uzytkownicy.txt");
	if (plik) {
		plik << "0 imie nazwisko nickname(login) haslo miasto nr_telefonu email rodzaj_konta ban(1-zbanowane)" << std::endl;
		for (const auto& x : Users) {
			plik << x.nr_konta << " " << x.imie << " " << x.nazwisko << " " << x.login << " " << x.haslo
				<< " " << x.miasto << " " << x.nr_telefonu << " " << x.email << " " << x.rodzaj_konta << " "
				<< x.ban << std::endl;
		}
		plik.close();
	}

}


void Podst::napisz_wiadomosc(std::string nickname) {
	std::string wiadomosc; //zmienna do przechowywania biezacej wiad uzytkownika

	std::ofstream plik("pliki_txt/chat.txt", std::ios::app);

	if (plik)
	{
		while (wiadomosc != "/esc")
		{
			std::getline(std::cin, wiadomosc);
			std::cout << ANSI_COLOR_GREEN << "< " << nickname << " > " << ANSI_COLOR_WHITE << wiadomosc << std::endl;
			std::string zapis_wiadomosc = ANSI_COLOR_GREEN "< " + nickname + " > " + ANSI_COLOR_WHITE + wiadomosc;
			plik << zapis_wiadomosc << std::endl;  // Zapis wiadomosci do pliku
		}
		plik.close();
	}
	else {
		std::cerr << "Nie mozna otworzyc pliku." << std::endl;
	}
}

void Mody::napisz_wiadomosc(std::string nickname) {
	std::string wiadomosc; //zmienna do przechowywania biezacej wiad uzytkownika

	std::ofstream plik("pliki_txt/chat.txt", std::ios::app);
	if (plik)
	{
		while (wiadomosc != "/esc") {
			std::getline(std::cin, wiadomosc);
			std::cout << ANSI_COLOR_CYAN << "< " << nickname << " > " << ANSI_COLOR_WHITE << wiadomosc << std::endl;
			std::string zapis_wiadomosc = ANSI_COLOR_CYAN "< " + nickname + " > " + ANSI_COLOR_WHITE + wiadomosc;
			plik << zapis_wiadomosc << std::endl;  // Zapis wiadomosci do pliku
		}
		plik.close();
	}
	else {
		std::cerr << "Nie mozna otworzyc pliku." << std::endl;
	}
}

void Admini::napisz_wiadomosc(std::string nickname) {
	std::string wiadomosc; //zmienna do przechowywania biezacej wiad uzytkownika

	std::ofstream plik("pliki_txt/chat.txt", std::ios::app);
	if (plik)
	{
		while (wiadomosc != "/esc") {
			std::getline(std::cin, wiadomosc);
			std::cout << ANSI_COLOR_RED << "< " << nickname << " > " << ANSI_COLOR_WHITE << wiadomosc << std::endl;
			std::string zapis_wiadomosc = ANSI_COLOR_RED "< " + nickname + " > " + ANSI_COLOR_WHITE + wiadomosc;
			plik << zapis_wiadomosc << std::endl;  // Zapis wiadomosci do pliku
		}
		plik.close();
	}
	else {
		std::cerr << "Nie mozna otworzyc pliku." << std::endl;
	}
}


void Chat::wyswietl_chat()
{
	std::ifstream plik("pliki_txt/chat.txt"); // Otwarcie pliku do odczytu

	if (plik) {
		std::string linia;
		system("cls");
		while (std::getline(plik, linia)) {
			std::cout << linia << std::endl; // Wypisanie linii na ekran
		}
		plik.close(); // Zamkniêcie pliku
	}
	else {
		std::cout << "Nie mo¿na otworzyæ pliku." << std::endl;
	}	
}

std::ostream& operator<<(std::ostream& strumien, std::vector<Uzytkownicy> Users) {
	int id = Users[0].biezacy_uzytkownik-1;
	strumien << "Imie: " << Users[id].imie << std::endl;
	strumien << "Nazwisko: " << Users[id].nazwisko << std::endl;
	strumien << "Login: " << Users[id].login << std::endl;
	strumien << "Miasto: " << Users[id].miasto << std::endl;
	strumien << "Numer telefonu: " << Users[id].nr_telefonu << std::endl;
	strumien << "Email: " << Users[id].email << std::endl;
	strumien << "Rodzaj konta: " << Users[id].rodzaj_konta << std::endl;
	strumien << "Numer konta: " << Users[id].nr_konta << std::endl;
	strumien << "Status konta (1-ban): " << Users[id].ban << std::endl;
	return strumien;
}



