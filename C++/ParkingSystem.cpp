#include<iostream>
#include<vector>

using namespace std;

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        number[0] = big;
        number[1] = medium;
        number[2] = small;
    }
    
    bool addCar(int carType) {
        if(number[carType - 1] == 0){
            return false;
        }
        number[carType - 1]--;
        return true;
    }

private:
    int number[3];
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */