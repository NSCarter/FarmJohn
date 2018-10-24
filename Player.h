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
    
    /*vector<string> takeFromInv(string item)
    {
        inventory.erase(std::remove(inventory.begin(), inventory.end(), item), inventory.end());    //https://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position
        return inventory;
    }*/
    
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
    t.addToInv("Shovel",50);
    t.outputInv();
    t.addToInv("Seeds",50);
    t.outputInv();
    return 0;   
}
