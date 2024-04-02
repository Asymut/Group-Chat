#include "Header.h"

int main()
{	//struktura wektora w wektorze do ktorej ladowany jest plik tekstowy z uzytkownikami aplikacji, nastepnie cala baza jest ladowana do wektora zawierajacego obiekty Users, klasy Uzytkownicy
	std::vector<std::vector<std::string>> baza_danych = wczytaj_baze("pliki_txt/uzytkownicy.txt");
	std::vector<Uzytkownicy> Users = zaladuj_klasy(baza_danych, Users);

	//Tworzy strukture danych - 3 wektory zawierajace obiekty klas pochodnych od klasy Uzytkownicy - z podzialem uzytkownikow, ze wzgledu na typ ich konta
	std::vector<Podst::Uzytkownicy> UsersP = zaladuj_klasyP(baza_danych, Users, UsersP);
	std::vector<Mody::Uzytkownicy> UsersM = zaladuj_klasyM(baza_danych, Users, UsersM);
	std::vector<Admini::Uzytkownicy> UsersA = zaladuj_klasyA(baza_danych, Users, UsersA);

	std::cout << "Witaj w serwisie internetowym Alterra! " <<std::endl;
	std::cout << "------------------<>------------------ " <<std::endl;

	//Tworzy dynamicznie tablice wskaznikow do obiektow typu Uzytkownicy o rozmiarze 3 - wskazuja obiekty roznych klas dziedziczacych z klasy Uzytkownicy (wskazujac na typ konta) - Polimorficzne wskazniki
	Uzytkownicy** tablica_kont = new Uzytkownicy * [3];

	//Inicjalizuja elementy tablicy tablica_kont poprzez dynamiczne utworzenie nowych obiektów typów Podst, Mody i Admini.
	tablica_kont[0] = new Podst();
	tablica_kont[1] = new Mody();
	tablica_kont[2] = new Admini();

	//Obsluga chatu1 - Tworzy pierwszy chat spolecznosciowy (obiekt klasy Chat)
	Chat chat1;
	
	//Menu programu - aktywuje metode klasy Uzytkownicy odpowiedzialna za obsluge menu w zaleznosci od biezacego typu uzytkownika
	 Users[0].obsluga_menu(tablica_kont, Users, chat1);
	return 0;
}