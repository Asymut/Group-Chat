#pragma once
#ifndef Header_h
#define Header_h
#define ANSI_COLOR_RED "\x1b[31m"	//zdefiniowane kolory
#define ANSI_COLOR_WHITE "\x1b[0m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>  // biblioteka dla stringstream 
#include <cstdlib> // biblioteka funkcji wbudowanych sys Windows

// klasa Chat - Zawiera zmienne dla chatu. Zawiera metody, ktore definiuja dzialanie i opcje chatu - obsluguja chaty na serwerze.
class Chat
{
	//int ilosc_chatow;
public:
	//metoda klasy Chat ladujaca z archiwum (pliku txt) chat z dotychczasowymi wiadomosciami i wyswietlajaca go uzytkownikowi
	void wyswietl_chat();
};

// klasa Uzytkownicy - Zawiera zmienne dla pojedynczych uzytkownikow. Deklaruje metody wirtualne dla oblslugi menu i opcji dla poszczegolnych typow kont klas pochodnych.
class Uzytkownicy
{
public:
		//zmienne klasy Uzytkownicy zawierajace dane uzytkownikow aplikacji
	std::string imie, nazwisko, login, miasto, nr_telefonu, email, rodzaj_konta;
	int nr_konta, ban, biezacy_uzytkownik;
		//konstruktor
	Uzytkownicy(int = 0, std::string="imie", std::string="nazwisko", std::string = "login", std::string = "haslo", std::string = "miasto", std::string = "111111111", std::string="email", std::string = "rodzaj", int=0);
		//metoda obslugujaca system logowania do serwisu (walidacji danych logowania, sprawdzenia statusu konta) oraz ladowania menu.
	int logowanie(std::vector<Uzytkownicy> Users);
		//Funkcjonalnosc nr2 - metoda umozliwiajca wglad w liste uczestnikow chatu
	void pokaz_uzytkownikow(std::vector<Uzytkownicy> Users);
		//Glowna metoda - odpowiada za wyswietlanie i obsluge menu (w zaleznosci od typu zalogowanego konta) - wywoluje funkcjonalnosci programu.
	void obsluga_menu(Uzytkownicy** tablica_kont, std::vector<Uzytkownicy> Users, Chat chat1);
		//Funkcjonalnosc nr4 (mody, admini) - metoda umozliwiajaca zmiane statusu konta (zbanowanie/odbanowanie uzytkownika).
	void ban_uzytkownika(std::vector<Uzytkownicy> &Users);
		//Funkcjonalnosc nr5 (admini) - umozliwia dodanie, do bazy danych i chatu, nowego czlonka konwersacji - utworzenie nowego konta dowolnego typu.
	void dodaj_uzytkownika(std::vector<Uzytkownicy> &Users);
		//Metoda zapisujaca baze danych uzytkownikow i aktualne zmiany w sesji podczas wylaczania programu.
	void zapisz_klasy(std::vector<Uzytkownicy> Users);
				//wirtualna metoda obslugujaca menu i opcje dla poszczegolnego typu konta
				//virtual void menu() { std::cout << "domyslny" << std::endl; }
		//Funkcjonalnosc nr1 - wirtualna metoda deklarujaca mozliwosc napisania wiadomosc dla poszczegolnych typow kont - zdefiniowana inaczej dla roznych typow kont. 
	virtual void napisz_wiadomosc(std::string nickname) {std::cout << "domyslny" << std::endl;}
	
protected:
	std::string haslo;
		//funkcja zaprzyjazniona z klasa - wypelnia wektor zawierajacy obiekty tej klasy, poszczegolnymi danymi uzytkownikow z bazy danych (pliku tekstowego).
	friend std::vector<Uzytkownicy> zaladuj_klasy();

		/*Funkcjonalnosc nr3 - umozliwia podejrzenie informacji odnosnie swojego konta(info o aktualnie zalogowanym uzytkowniku) - zastosowane jest przeciazenie operatoror,
		aby przy pomocy operatora strumienia wyjsciowego wyswietlic wszystkie pozadane dane o zalogowanym uzytkowniku.*/
	friend std::ostream& operator<<(std::ostream& strumien, std::vector<Uzytkownicy> Users);
	
};

// Klasa dla uzytkownikow podstawowych - dziedziczy po klasie Uzytkownicy
class Podst :public Uzytkownicy
{
public:
	//konstruktor
	Podst(int = 0, std::string = "imie", std::string = "nazwisko", std::string = "login", std::string = "haslo", std::string = "miasto", std::string = "111111111", std::string = "email", std::string = "rodzaj", int = 0);
	//void menu() { std::cout << " MENU Podst" << std::endl;}
	//metoda odpowiadajaca za obsluge wysylania i zapisu wiadomosci przez uzytkownikow podstawowych
	void napisz_wiadomosc(std::string nickname);
};

// Klasa dla moderatorow - dziedziczy po klasie Uzytkownicy
class Mody :public Uzytkownicy
{
public:
	//konstruktor
	Mody(int = 0, std::string = "imie", std::string = "nazwisko", std::string = "login", std::string = "haslo", std::string = "miasto", std::string = "111111111", std::string = "email", std::string = "rodzaj", int = 0);
	//void menu() {std::cout << " MENU MODOW" << std::endl;}
	//metoda odpowiadajaca za obsluge wysylania i zapisu wiadomosci przez moderatorow
	void napisz_wiadomosc(std::string nickname);
};

// Klasa dla administratorow - dziedziczy po klasie Uzytkownicy
class Admini :public Uzytkownicy
{
public:
	//konstruktor
	Admini(int = 0, std::string = "imie", std::string = "nazwisko", std::string = "login", std::string = "haslo", std::string = "miasto", std::string = "111111111", std::string = "email", std::string = "rodzaj", int = 0);
	//void menu() {std::cout << " MENU ADMINOW" << std::endl;}
	//metoda odpowiadajaca za obsluge wysylania i zapisu wiadomosci przez administratorow
	void napisz_wiadomosc(std::string nickname);
};

	
	//funkcja tworzaca wektor wektorow z wyluskanymi danymi z bazy danych uzytkownikow z pliku txt
	std::vector<std::vector<std::string>> wczytaj_baze(const std::string& dane);

	//Funkcja ktora uzupelnia dane dla elementow klasy Uzytkownicy (kont seriwsu), zwraca wektory zawierajacy obiekty klasy Uzytkownicy - uzytkownikow serwisu
	std::vector<Uzytkownicy> zaladuj_klasy(std::vector<std::vector<std::string>>baza_danych, std::vector<Uzytkownicy> Users);

	//Funkcja ktora zwraca wektor, zawieraajcy podstaowych uzytkownikow
	std::vector<Podst::Uzytkownicy> zaladuj_klasyP(std::vector<std::vector<std::string>>baza_danych, std::vector<Uzytkownicy> Users, std::vector<Podst::Uzytkownicy>UsersP);

	//Funkcja ktora zwraca wektor, zawieraajcy moderatorow
	std::vector<Mody::Uzytkownicy> zaladuj_klasyM(std::vector<std::vector<std::string>>baza_danych, std::vector<Uzytkownicy> Users, std::vector<Podst::Uzytkownicy>UsersM);

	//Funkcja ktora zwraca wektor, zawieraajcy administratorow
	std::vector<Admini::Uzytkownicy> zaladuj_klasyA(std::vector<std::vector<std::string>>baza_danych, std::vector<Uzytkownicy> Users, std::vector<Podst::Uzytkownicy>UsersA);

#endif
