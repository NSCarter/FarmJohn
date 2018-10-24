//Add error checking

#include <iostream>
#include <string>
#include <array>
#include "Player.h"
using namespace std;

void cropsMenu()
{
    string cropsList[5] = {"a", "a", "a", "a", "a"};
    int choice;
    
    for (int i = 0; i < 5; i++)
    {
        cout << i+1 << ". " << cropsList[i] << endl;
    }
    cout << "Choose an item: ";
    cin >> choice;
    cout << endl;
    
}

void bushesMenu()
{
    string cropsList[5] = {"a", "a", "a", "a", "a"};
    int choice;
    
    for (int i = 0; i < 5; i++)
    {
        cout << i+1 << ". " << cropsList[i] << endl;
    }
    cout << "Choose an item: ";
    cin >> choice;
    cout << endl;
}

void treesMenu()
{
    string cropsList[5] = {"a", "a", "a", "a", "a"};
    int choice;
    
    for (int i = 0; i < 5; i++)
    {
        cout << i+1 << ". " << cropsList[i] << endl;
    }
    cout << "Choose an item: ";
    cin >> choice;
    cout << endl;
}

void toolsMenu()
{
    string cropsList[5] = {"a", "a", "a", "a", "a"};
    int choice;
    
    for (int i = 0; i < 5; i++)
    {
        cout << i+1 << ". " << cropsList[i] << endl;
    }
    cout << "Choose an item: ";
    cin >> choice;
    cout << endl;
}

void defenceMenu()
{
    string cropsList[5] = {"a", "a", "a", "a", "a"};
    int choice;
    
    for (int i = 0; i < 5; i++)
    {
        cout << i+1 << ". " << cropsList[i] << endl;
    }
    cout << "Choose an item: ";
    cin >> choice;
    cout << endl;
}

void buyMenu()
{
    int choice;
    cout << "1. Crops" << endl;
    cout << "2. Bushes" << endl;
    cout << "3. Trees" << endl;
    cout << "4. Tools" <<endl;
    cout << "5. Defence" << endl;
    cout << "Choose an option: ";
    cin >> choice;
    cout << endl;
    if (choice == 1)
    {
        cropsMenu();
    }
    else if (choice == 2)
    {
        bushesMenu();
    }
    else if (choice == 3)
    {
        treesMenu();
    }
    else if (choice == 4)
    {
        toolsMenu();
    }
    else
    {
        defenceMenu();
    }
}

void sellMenu()
{
   cout << "Choose an item to sell: " << endl; 
}

void menu()
{
    int choice;
    cout << "1. Buy" << endl;
    cout << "2. Sell" << endl;
    cout << "Choose an option: ";
    cin >> choice;
    cout << endl;
    if (choice == 1)
    {
        buyMenu();
    }
    else
    {
        sellMenu();
    }
}

int main()
{
    menu();
    
    
    return 0;
}
