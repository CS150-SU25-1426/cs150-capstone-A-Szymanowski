#include "SushiMenu.h"

bool SushiMenu::addSushi(Sushi sushi){
    menu.push_back(sushi);
    return true;
}

bool SushiMenu::removeSushi(int num){
    int index = -1;

    for(int i = 0; i < menu.size(); i++){
        if(menu[i].getNum() == num){
            index = i;
            break;
        }
    }
        if(index >= 0){
            menu.erase(menu.begin() + index);
            return true;
    }
    return false;

}

bool SushiMenu::modifySushi(int num, const string& category, const string& newValue){
    for(int i = 0; i < menu.size(); i++){
        if(menu[i].getNum() == num){
            if(category == "name"){
                menu[i].setName(newValue);
            }else if(category == "description"){
                menu[i].setDescription(newValue);
            }else if(category == "price"){
                double price = stod(newValue);
                menu[i].setPrice(price);
            }else if(category == "pieces"){
                int piece = stoi(newValue);
                menu[i].setPiece(piece);
            }else if(category == "raw"){
                bool raw;
                raw = (newValue == "Y") ? true : false;
                menu[i].setRaw(raw);
            }else if(category == "spicy"){
                bool spicy;
                spicy = (newValue == "Y") ? true : false;
                menu[i].setSpicy(spicy);
            } else{
                return false;
            }
            return true;
        }
    }
    return false;
}

bool SushiMenu::operator==(const SushiMenu& other)const{
    return menu == other.menu;
}

ostream& operator<<(ostream& os, const SushiMenu& s){
    for(int i = 0; i < s.menu.size(); i++){
        os<<s.menu[i]<<"\n";
    }
    return os;
}