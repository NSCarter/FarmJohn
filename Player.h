#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#include "libsqlite.hpp"
#ifndef PLAYER_H
#define PLAYER_H

class John 
{
  private:
    int gold, mapSize;
    string farmName;
    vector<pair<string, int>>  inventory;
    
  /*void save()
  {
      string sqliteFile = "ExportedFarmJohn.sqlite"; 
      
      sqlite::sqlite db (sqliteFile);
      auto cur = db.get_statement();
  }*/
    
  public:
    John()
    {
        gold = 500;
        mapSize = 10;
        inventory = {{"Shovel",1}};
    }
    
    void outputGold()
    {
        cout << gold << " gold" << endl;
    }
    
    int addGold(int amount)
    {
      gold += amount;
      outputGold();
      return gold;
    }
    
    int subtractGold(int amount)
    {
        gold -= amount;
        outputGold();
        return gold;
    }
    
    string setFarmName(string name)
    {
        farmName = name;
        return farmName;
    }
    
    void addToInv(string item, int quantity)
    {
        bool found = false;
        
        for (int i = 0; i < inventory.size(); i++)
        {
            if(inventory[i].first == item)
            {
              inventory[i].second += quantity;
              found = true;
            }
        }
        
        if (found == false)
        {
            inventory.emplace_back(item, quantity);
        }
    }
    
    void takeFromInv(string item, int quantity)
    {
        for (int i = 0; i < inventory.size(); i++)
        {
            if (inventory[i].first == item)
            {
                if (inventory[i].second -= quantity > 0)
                {
                    inventory[i].second -= quantity;
                }
                else
                {
                    inventory.erase(inventory.begin() + i);
                }
                break;
            }
        }
    }
    
    void outputInv()
    {
        for (int i = 0; i < inventory.size(); i++)
        {
            cout << i+1 << ". " << inventory[i].first << ": " << inventory[i].second << endl;
        }
    }
    
    void playerStats()
    {
        cout << "Stats" << endl;
    }
};

#endif

int main()
{
    John t;
    t.outputInv();
    cout << endl;
    //t.addToInv("Shovel",50);
    //t.outputInv();
    t.addToInv("Seeds",50);
    t.outputInv();
    cout << endl;
    //t.takeFromInv("Shovel",1);
    //cout << endl;
    t.takeFromInv("Seeds",15);
    t.outputInv();
    return 0;   
}
