#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// class ParkingSystem
// {
// public:
//     int big, medium, small;
//     ParkingSystem(int big, int medium, int small)
//     {
//         this->big = big;
//         this->medium = medium;
//         this->small = small;
//     }

//     bool addCar(int carType)
//     {
//         switch (carType)
//         {
//         case 1:
//         {
//             if (big == 0)
//                 return false;
//             else
//                 big--;
//             break;
//         }

//         case 2:
//         {
//             if (medium == 0)
//                 return false;
//             else
//                 medium--;
//             break;
//         }

//         case 3:
//         {
//             if (small == 0)
//                 return false;
//             else
//                 small--;
//             break;
//         }
//         }
//         return true;
//     }
// };

class ParkingSystem
{
public:
    vector<int> space{0, 0, 0};
    ParkingSystem(int big, int medium, int small)
    {
        this->space[0] = big;
        this->space[1] = medium;
        this->space[2] = small;
    }

    bool addCar(int carType)
    {
        if (space[carType - 1] == 0)
            return false;
        else
            space[carType - 1]--;
            return true;
    }
};
int main()
{
    int small = 0, medium = 1, big = 1;
    ParkingSystem *temp = new ParkingSystem(big, medium, small);
    temp->addCar(1);
    temp->addCar(2);
    temp->addCar(3);
    temp->addCar(1);
}