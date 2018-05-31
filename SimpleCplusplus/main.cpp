#include <iostream>

// Some old compilers allowed void main(), but this
// gets a very bad wrap online, as doesn't return anything
// int main() is the standard
class EnergyLevel {
public:
    int level;

    EnergyLevel(int initial_amount) {
        level = initial_amount;
    }
    void drain() {
        level = 0;
    }
    void increase(int amount){
        level += amount;
    }
    int getLevel(){
        return level;
    }
};
int main() {
    EnergyLevel good(5);
    // use getter function, instead of accessing variable directly
//    std::cout << "Good's energy level starts at " << good.level << std::endl;
    std::cout << "Good's energy level starts at " << good.getLevel() << std::endl;
    good.level = 10;
    std::cout << "Good's energy level is at " << good.getLevel() << std::endl;
//     bad practice to access attribute directly like below (commented out)
    // needs to be done indirectly using methods, ie setter, getter, or increase
    // in this case, or in fact getLevel as per book
//    good.level ++;
    good.increase(10);
    std::cout << "Good's energy level is up to " << good.getLevel() << std::endl;
    good.drain();
    std::cout << "Good's energy level has been drained to " << good.getLevel() << std::endl;
    return 0;
}