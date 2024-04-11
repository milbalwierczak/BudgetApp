#include "UserManager.h"

void UserManager::registerUser()
{
    User user = setNewUserData();

    users.push_back(user);

    userFile.addUserToFile(user);

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

int UserManager::getLoggedUserId()
{
    return loggedUserId;
}

void UserManager::logInUser()
{
    User user;
    string login = "", password = "";

    cout << "Enter login: ";
    login = Utils::readLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if ((*itr).login == login)
        {
            for (int numberOfRemainingAttempts = 3; numberOfRemainingAttempts > 0; numberOfRemainingAttempts--)
            {
                cout << "Enter password. Attempts left: " << numberOfRemainingAttempts << ": ";
                password = Utils::readLine();

                if ((*itr).password == password)
                {
                    cout << endl << "You logged in successfully." << endl << endl;
                    system("pause");
                    loggedUserId =(*itr).id;
                    return;
                }
            }
            cout << "You entered wrong password 3 times. Logging-in interrupted" << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "There is no user with this login" << endl << endl;
    system("pause");
    return;
}
 /*
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
*/
bool UserManager::isUserLoggedIn()
{
    if(loggedUserId > 0)
        return true;
    else
        return false;
}

void UserManager::logoutUser()
{
    loggedUserId = 0;
    return;
}


