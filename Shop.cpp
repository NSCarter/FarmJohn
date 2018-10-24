//By Niamh

////Add error checking

#include <iostream>
#include <string>
#include <array>
#include <sstream>
#include "Player.cpp"
using namespace std;

void cropsBuyMenu(John &t)
{
    string itemList[3][2] = {{"Carrots", "10"}, {"Potatoes", "20"}, {"Cabbage", "10"}};
    int choice, cost;
    
    for (int i = 0; i < 3; i++)
    {
        cout << i+1 << ". " << itemList[i][0] << ": " << itemList[i][1] << " gold" << endl;
    }
    cout << "Choose an item: ";
    cin >> choice;
    cout << endl;
    t.addToInv(itemList[choice-1][0]);
    
    cost = std::stoi(itemList[choice-1][1]); //https://stackoverflow.com/questions/194465/how-to-parse-a-string-to-an-int-in-c
    t.subtractGold(cost);
}

void bushesBuyMenu(John &t)
{
    string itemList[3][2] = {{"Strawberries","100"}, {"Blackberries","110"}, {"Gooseberries", "120"}};
    int choice, cost;
    
    for (int i = 0; i < 3; i++)
    {
        cout << i+1 << ". " << itemList[i][0] << ": " << itemList[i][1] << " gold" << endl;
    }
    cout << "Choose an item: ";
    cin >> choice;
    cout << endl;
    t.addToInv(itemList[choice-1][0]);
    
    cost = std::stoi(itemList[choice-1][1]);
    t.subtractGold(cost);
}

void treesBuyMenu(John &t)
{
    string itemList[1][2] = {{"Apple", "200"}};
    int choice, cost;
    
    for (int i = 0; i < 1; i++)
    {
        cout << i+1 << ". " << itemList[i][0] << ": " << itemList[i][1] << " gold" << endl;
    }
    cout << "Choose an item: ";
    cin >> choice;
    cout << endl;
    t.addToInv(itemList[choice-1][0]);
    
    cost = std::stoi(itemList[choice-1][1]);
    t.subtractGold(cost);
}

void toolsBuyMenu(John &t)
{
    string itemList[5] = {"aa", "aa", "aa", "aa", "aa"};
    int choice, cost;
    
    for (int i = 0; i < 5; i++)
    {
        cout << i+1 << ". " << itemList[i] << endl;
    }
    cout << "Choose an item: ";
    cin >> choice;
    cout << endl;
    t.addToInv(itemList[choice-1]);
    
    //cost = std::stoi(itemList[choice-1][1]);
    //t.subtractGold(cost);
}

void defenceBuyMenu(John &t)
{
    string itemList[1][2] = {{"Scarecrow", "250"}};
    int choice, cost;
    
    for (int i = 0; i < 5; i++)
    {
        cout << i+1 << ". " << itemList[i][0] << ": " << itemList[i][1] << " gold" << endl;
    }
    cout << "Choose an item: ";
    cin >> choice;
    cout << endl;
    t.addToInv(itemList[choice-1][0]);
    
    cost = std::stoi(itemList[choice-1][1]);
    t.subtractGold(cost);
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
    switch(choice)
    {
        case 1:
            cropsBuyMenu(t);
            break;
        case 2:
            bushesBuyMenu(t);
            break;
        case 3:
            treesBuyMenu(t);
            break;
        case 4:
            toolsBuyMenu(t);
            break;
        case 5:
            defenceBuyMenu(t);
            break;
    }       
}

void cropsSellMenu(John &t)
{
    string itemList[3][2] = {{"Carrots", "20"}, {"Potatoes", "40"}, {"Cabbage", "60"}}; //10, 20, 30
    int choice, cost;
    
    for (int i = 0; i < 3; i++)
    {
        cout << i+1 << ". " << itemList[i][0] << ": " << itemList[i][1] << " gold" << endl;
    }
    cout << "Choose an item: ";
    cin >> choice;
    cout << endl;
    t.takeFromInv(itemList[choice-1][0]);
    
    cost = std::stoi(itemList[choice-1][1]);
    t.addGold(cost);
}

void bushesSellMenu(John &t)
{
    string itemList[3][2] = {{"Strawberries", "10"}, {"Blackberries", "11"}, {"Gooseberries", "12"}};//10, 11, 12
    int choice, cost;
    
    for (int i = 0; i < 3; i++)
    {
        cout << i+1 << ". " << itemList[i][0] << ": " << itemList[i][1] << " gold" << endl;
    }
    cout << "Choose an item: ";
    cin >> choice;
    cout << endl;
    t.takeFromInv(itemList[choice-1][0]);
    
    cost = std::stoi(itemList[choice-1][1]);
    t.addGold(cost);
}

void treesSellMenu(John &t)
{
    string itemList[1][2] = {{"Apple", "200"}};
    int choice, cost;
    
    for (int i = 0; i < 1; i++)
    {
        cout << i+1 << ". " << itemList[i][0] << ": " << itemList[i][1] << " gold" << endl;
    }
    cout << "Choose an item: ";
    cin >> choice;
    cout << endl;
    t.takeFromInv(itemList[choice-1][0]);
    
    cost = std::stoi(itemList[choice-1][1]);
    t.addGold(cost);
}

void sellMenu(John &t)
{
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
            cropsSellMenu(t);
            break;
        case 2:
            bushesSellMenu(t);
            break;
        case 3:
            treesSellMenu(t);
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
