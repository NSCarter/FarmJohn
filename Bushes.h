#include <iostream>
using namespace std;

class Bushes 
{
    private:
        int space, growTime, berryGrowth;
    
    public:
        Bushes()
        {
            space = 1;
            growTime = 1;
            berryGrowth = 1;
        }
    
        void dugUp(int x, int y)
        {
            cout << "Bush at " << x << " " << y << " has been dug up."<< endl;
        }
};

int main()
{
    return 0;
}
