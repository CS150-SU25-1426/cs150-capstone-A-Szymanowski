#include <iostream>
#include "Sushi.h"
using namespace std;

int main() {
    Sushi sushi1 = {1, "California Roll", "Imitation crab, avocado and cucumber", 6.95, 8, true, false};
    Sushi sushi2 = {1, "California Roll", "Imitation crab, avocado and cucumber", 6.95, 8, true, false};
    Sushi sushi3 = {3, "Alaskan Roll", "Fresh salmon on top of calfornia roll", 13.95, 8, true, false};

    cout<<sushi1<<"\n";
    cout<<sushi2<<"\n";
    cout<<sushi3<<"\n\n";

    cout<<"Is sushi #1 the same as sushi #2 ? "<<(sushi1 == sushi2 ? "Yes" : "No")<<"\n";
    cout<<"Is sushi #1 the same as sushi #3 ? "<<(sushi1 == sushi3 ? "Yes" : "No")<<"\n";

    return 0;
}