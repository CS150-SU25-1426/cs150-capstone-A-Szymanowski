#ifndef SUSHIMENU_H
#define SUSHIMENU_H

#include <vector>
#include "Sushi.h"

class SushiMenu {
    private: 
        vector<Sushi> menu;


    public:
        bool addSushi(Sushi sushi);
        bool removeSushi(int num);
        bool modifySushi(int num, const string& category, const string& newValue);

        bool operator==(const SushiMenu& other) const;
        friend ostream& operator<<(ostream& os, const SushiMenu& s);
};

#endif
