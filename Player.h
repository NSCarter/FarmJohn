#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class John 
{
  private:
    int gold, mapSize;
    string farmName;
    vector<string> inventory;
    
  public:
    John()
    {
        gold = 500;
        mapSize = 10;
        inventory = {"Shovel", "Hand", "Seeds"};
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
    
    vector<string> addToInv(string item)
    {
        inventory.emplace_back(item);
        return inventory;
    }
    
    vector<string> takeFromInv(string item)
    {
        inventory.erase(std::remove(inventory.begin(), inventory.end(), item), inventory.end());    //https://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position
        return inventory;
    }
    
    void outputInv()
    {
        for (string i : inventory)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};

#endif
/*
int main()
{
    John t;
    t.takeFromInv("Seeds");
    t.outputInv();
    return 0;   
}
*/
