//By Niamh

////Add error checking
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Player.cpp"
using namespace std;

void buy(John &t, vector<pair<string, int>> list)
{
    int choice, cost, amount;
    
    for (int i = 0; i < list.size(); i++)
    {
        cout << i+1 << ". " << list[i].first << ": " << list[i].second << " gold" << endl;
    }
    cout << "Choose an item: ";
    cin >> choice;
    cout << endl;
    
    if (choice > list.size())
    {
        cout << "Not an option" << endl << endl;
        buy(t, list);
    }
    
    cout << "How many would you like to buy? ";
    cin >> amount;
    cout << endl;
    
    cost = list[choice-1].second;
    cost *= amount;
    
    if (t.getGold() < cost)
    {
       cout << "You do not have enough gold" << endl << endl;
    }
    
    t.addToInv(list[choice-1].first, amount);
    t.subtractGold(cost);
}

void buyMenu(John &t)
{
    typedef vector<pair<string, int>>  List;
    
    List cropsList = {{"Carrots", 10}, {"Potatoes", 20}, {"Cabbage", 10}};
    List bushesList = {{"Strawberries",100}, {"Blackberries",110}, {"Gooseberries", 120}};
    List treesList = {{"Apple", 200}};
    List defenceList = {{"Scarecrow", 250}};
    int choice;
    
    cout << "1. Crops" << endl;
    cout << "2. Bushes" << endl;
    cout << "3. Trees" << endl;
    cout << "4. Defence" << endl;
    cout << "Choose an option: ";
    cin >> choice;
    cout << endl;
    switch(choice)
    {
        case 1:
            buy(t, cropsList);
            break;
        case 2:
            buy(t, bushesList);
            break;
        case 3:
            buy(t, treesList);
            break;
        case 4:
            buy(t, defenceList);
            break;
        default:
            cout << "Not an option" << endl << endl;
            buyMenu(t);
            break;
    }       
}

void sell(John &t, vector<pair<string, int>> list)
{
    int choice, cost, amount;
    
    for (int i = 0; i < list.size(); i++)
    {
        cout << i+1 << ". " << list[i].first << ": " << list[i].second << " gold" << endl;
    }
    cout << "Choose an item: ";
    cin >> choice;
    cout << endl;
    
    if (choice > list.size())
    {
        cout << "Not an option" << endl << endl;
        sell(t, list);
    }
    
    cout << "How many would you like to buy? ";
    cin >> amount;
    cout << endl;
    
    vector<pair<string, int>> inventory = t.getInventory();
    
    for (int i = 0; i < inventory.size(); i++)
    {
        if (inventory[i].first == list[choice-1].first)
        {
            if (inventory[i].second < amount)
            {
                cout << "You don't have enough to sell" << endl << endl;
            }
            break;
        }
    }
    
    t.takeFromInv(list[choice-1].first, amount);
    
    cost = list[choice-1].second;
    cost *= amount;
    
    t.addGold(cost);
}

void sellMenu(John &t)
{
    typedef vector<pair<string, int>>  List;
    
    List cropsList = {{"Carrots", 20}, {"Potatoes", 40}, {"Cabbage", 60}};
    List bushesList = {{"Strawberries", 10}, {"Blackberries", 11}, {"Gooseberries", 12}};
    List treesList = {{"Apple", 200}};
    int choice;
    
    cout << "1. Crops" << endl;
    cout << "2. Bushes" << endl;
    cout << "3. Trees" << endl;
    cout << "Choose an option: ";
    cin >> choice;
    cout << endl;
    
    switch(choice)
    {
        case 1:
            sell(t, cropsList);
            break;
        case 2:
            sell(t, bushesList);
            break;
        case 3:
            sell(t, treesList);
            break;
        default:
            cout << "Not an option" << endl << endl;
            sellMenu(t);
            break;
    } 
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
    else if (choice == 2)
    {
        sellMenu(t);
    }
    else
    {
        cout << "Not an option" << endl << endl;
        menu(t);
    }
}

int main()
{
    John t;
    
    t.outputGold();
    t.addToInv("Carrots", 5);
    t.outputInv();

    menu(t);
    
    t.outputInv();
    
    return 0;
}
