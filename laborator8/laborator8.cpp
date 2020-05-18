// laborator8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Repo.h"
#include"RepositoryFile.h"
#include"RepositoryFileCSV.h"
#include"RepositoryFileHTML.h"
#include"Comanda.h"
#include "Mancare.h"
#include"Shopping.h"
#include"Functions.h"
#include"Service.h"
#include"User.h"
#include"UserInterface.h"
using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    cout << "In ce tip de fisier doriti sa lucrati: " << endl;
    cout << "1. CSV" << endl;
    cout << "2. HTML" << endl;
    cout << endl;
    int op;
    cin >> op;
    if (op == 1)
    {
        Repo<User>* user_repo = new RepositoryCSV<User>("users.csv");
        ((RepositoryCSV<User>*) user_repo)->loadFromFile();
        Repo<Mancare>* food_repo = new RepositoryCSV<Mancare>("mancare.csv");
        ((RepositoryCSV<Mancare>*) food_repo)->loadFromFile();
        Repo<Shopping>* shopping_repo = new RepositoryCSV<Shopping>("shopping.csv");
        ((RepositoryCSV<Shopping>*) shopping_repo)->loadFromFile();
        Service service(food_repo, shopping_repo, user_repo);
        UI ui(service);
        ui.run();   
    }
    if (op == 2)
    {
        Repo<User>* user_repo = new RepositoryHTML<User>("users1.html");
        ((RepositoryHTML<User>*) user_repo)->loadFromFile();
        Repo<Mancare>* food_repo = new RepositoryHTML<Mancare>("mancare1.html");
        ((RepositoryHTML<Mancare>*) food_repo)->loadFromFile();
        Repo<Shopping>* shopping_repo = new RepositoryHTML<Shopping>("shopping1.html");
        ((RepositoryHTML<Shopping>*) shopping_repo)->loadFromFile();
        Service service(food_repo, shopping_repo, user_repo);
        UI ui(service);
        ui.run();
    }
    if (op != 1 && op != 2)
        cout << "Optiune inexistenta ";
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
