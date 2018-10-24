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
    t.subtractGold(50);
    
}

void bushesMenu(John &t)
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
    t.subtractGold(50);
}

void treesMenu(John &t)
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
    t.subtractGold(50);
}

void toolsMenu(John &t)
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
    t.subtractGold(50);
}

void defenceMenu(John &t)
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
    t.subtractGold(50);
}

void buyMenu(John &t)
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
        cropsMenu(t);
    }
    else if (choice == 2)
    {
        bushesMenu(t);
    }
    else if (choice == 3)
    {
        treesMenu(t);
    }
    else if (choice == 4)
    {
        toolsMenu(t);
    }
    else
    {
        defenceMenu(t);
    }
}

void sellMenu()
{
   cout << "Choose an item to sell: " << endl; 
}

void menu(John &t)
{
    int choice;
    cout << "1. Buy" << endl;
    cout << "2. Sell" << endl;
    cout << "Choose an option: ";
    cin >> choice;
    cout << endl;
    if (choice == 1)
    {
        buyMenu(t);
    }
    else
    {
        sellMenu(t);
    }
}

int main()
{
    John t;

    menu(t);
    
    
    return 0;
}
