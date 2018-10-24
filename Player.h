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
    
    bool checkInInv(string item)
    {
        for (int i = 0; i < inventory.size(); i++)
        {
            if (inventory[i].first == item)
            {
                return true;
            }
        }
        return false;
    }
    
    void playerStats()
    {
        cout << "Stats" << endl;
    }
    
    void save()
    {    
      try
      {
          int count;

          sqlite::sqlite db("FarmJohnDatabase.sqlite");
          auto cur = db.get_statement();

          for (int i = 0; i < inventory.size(); i++)
          {
              //cout << "here" << endl;
              
              cur -> set_sql("SELECT count(*) "
                             "FROM UserInventory "
                             "WHERE PlayerName = ? "
                             "AND ItemName = ?");
              //cout << "here" << endl;
              cur -> prepare();
              cout << "here" << endl;
              cur -> bind(1, farmName);
              cur -> bind(2, inventory[i].first);
              cur -> step();

              int count = cur -> get_int(0);

              cur -> reset();
              //cout << "here" << endl;

              if (count == 0)
              {
                  cur -> set_sql("INSERT INTO UserInventory Values (?, ?, ?);");
                  cur -> prepare();
                  cur -> bind(1, farmName);
                  cur -> bind(2, inventory[i].first);
                  cur -> bind(3, inventory[i].second);
                  cur -> step();
              }
              else
              {
                  cur -> set_sql("UPDATE UserInventory "
                                 "SET NumInInventory = ? "
                                 "WHERE PlayerName = ? "
                                 "AND ItemName = ?");
                  cur -> prepare();
                  cur -> bind(1, inventory[i].second);
                  cur -> bind(2, farmName);
                  cur -> bind(3, inventory[i].first);
                  cur -> step();
              }

              cur -> reset();
          }
      }
      catch(sqlite::exception e)
      {
          std::cerr << e.what() << std::endl;
      }
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
    t.takeFromInv("Seeds", 2);
    t.outputInv();
    
    return 0;   
}
