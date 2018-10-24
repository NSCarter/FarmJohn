//By Niamh

////Add error checking

#include <iostream>
#include <string>
#include <array>
#include "Player.cpp"
using namespace std;

void cropsMenu(John &t)
{
    string cropsList[5] = {"Carrots", "Potatoes", "Cabbage", "d", "e"}; //10, 20, 30
    int choice;
    
    for (int i = 0; i < 5; i++)
    {
        cout << i+1 << ". " << cropsList[i] << endl;
    }
    cout << "Choose an item: ";
    cin >> choice;
    cout << endl;
    t.addToInv(cropsList[choice-1]);
    
    switch(choice)
    {
        case 1:
            t.subtractGold(10);
            break;
        case 2:
            t.subtractGold(20);
            break;
        case 3:
            t.subtractGold(30);
    }
}

void bushesMenu(John &t)
{
    string cropsList[5] = {"Strawberries", "Blackberries", "Gooseberries", "a", "a"}; //100, 110, 120
    int choice;
    
    for (int i = 0; i < 5; i++)
    {
        cout << i+1 << ". " << cropsList[i] << endl;
    }
    cout << "Choose an item: ";
    cin >> choice;
    cout << endl;
    t.addToInv(cropsList[choice-1]);
    
    switch(choice)
    {
        case 1:
            t.subtractGold(100);
            break;
        case 2:
            t.subtractGold(110);
            break;
        case 3:
            t.subtractGold(120);
    }
}

void treesMenu(John &t)
{
    string cropsList[5] = {"Apple", "a", "a", "a", "a"}; //200
    int choice;
    
    for (int i = 0; i < 5; i++)
    {
        cout << i+1 << ". " << cropsList[i] << endl;
    }
    cout << "Choose an item: ";
    cin >> choice;
    cout << endl;
    t.addToInv(cropsList[choice-1]);
    
    switch(choice)
    {
        case 1:
            t.subtractGold(10);
            break;
        case 2:
            t.subtractGold(20);
            break;
        case 3:
            t.subtractGold(30);
    }
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
    t.addToInv(cropsList[choice-1]);
    t.subtractGold(50);
}

void defenceMenu(John &t)
{
    string cropsList[5] = {"Scarecrow", "a", "a", "a", "a"}; //250
    int choice;
    
    for (int i = 0; i < 5; i++)
    {
        cout << i+1 << ". " << cropsList[i] << endl;
    }
    cout << "Choose an item: ";
    cin >> choice;
    cout << endl;
    t.addToInv(cropsList[choice-1]);
    
    switch(choice)
    {
        case 1:
            t.subtractGold(250);
            break;
    }
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

void sellMenu(John &t)
{
    string item;
    
    t.outputInv();
    cout << "Choose an item to sell: ";
    cin >> item;
    t.takeFromInv(item);
    t.addGold(50);
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
    
    t.outputGold();
    t.outputInv();

    menu(t);
    
    t.outputInv();
    
    return 0;
}
