#include <iostream>

#ifndef SUSHI_H
#define SUSHI_H

using namespace std;

class Sushi{
    private:
        int num;
        string name;
        string description;
        double price;
        int piece;
        bool raw;
        bool spicy;

    public:
        Sushi(string name, string description, double price, int piece, bool raw, bool spicy);

        int getNum() const {return num;}
        string getName() const {return name;}
        string getDescription() const {return description;}
        double getPrice() const {return price;}
        int getPiece() const {return piece;}
        bool getRaw() const {return raw;}
        bool getSpicy() const {return spicy;}

        void setNum(int num) {this->num = num;}
        void setName(string name) {this->name = name;}
        void setDescription(string description) {this->description = description;}
        void setPrice(double price) {this->price = price;}
        void setPiece(int piece) {this->piece = piece;}
        void setRaw(bool raw) {this->raw = raw;}
        void setSpicy(bool spicy) {this->spicy = spicy;}

        bool operator==(const Sushi& other) const;
        friend ostream& operator<<(ostream& os, const Sushi& s);
};

#endif