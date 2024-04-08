#include "UserManager.h"

void UserManager::registerUser()
{
    User user = setNewUserData();

    users.push_back(user);

    //plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Account created succesfully" << endl << endl;
    system("pause");
}

User UserManager::setNewUserData()
{
    User user;

    user.id = getNewUserId();

    do
    {
        cout << "Set login: ";
        user.login = Utils::readLine();
    }
    while (ifLoginExists(user.login) == true);

    cout << "Set password: ";
    user.password = Utils::readLine();

    cout << "Set first name: ";
    user.firstName = Utils::readLine();

    cout << "Set last name: ";
    user.lastName = Utils::readLine();

    return user;
}


int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().id + 1;
}

bool UserManager::ifLoginExists(string login)
{
    for (size_t i = 0; i < users.size(); i++)
    {
        if(users[i].login == login)
        {
            cout << endl << "User with given login already exists" << endl;
            return true;
        }
    }
    return false;
}


void UserManager::listAllUsers()
{
    for (size_t i = 0; i < users.size(); i++)
    {
        cout << users[i].id << endl;
        cout << users[i].login << endl;
        cout << users[i].password << endl;
        cout << users[i].firstName << endl;
        cout << users[i].lastName << endl;
    }
    system("pause");
}
/*
void UzytkownikMenedzer::ustawIdZalogowanegoUzytkownika(int id)
{
    if (id>=0)
        idZalogowanegoUzytkownika = id;
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if ((*itr).pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if ((*itr).pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika =(*itr).pobierzId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if ((*itr).pobierzId() == idZalogowanegoUzytkownika)
        {
            (*itr).ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

void UzytkownikMenedzer::wylogowanieUzytkownika()
{
    ustawIdZalogowanegoUzytkownika(0);
    return;
}

bool UzytkownikMenedzer::czyUzytkownikJestZalogowany()
{
    if(idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}

*/
