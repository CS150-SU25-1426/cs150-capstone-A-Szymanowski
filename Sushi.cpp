#include <iomanip>
#include "Sushi.h"

Sushi::Sushi(int num, string name, string description, double price, int piece, bool raw, bool spicy){
    this->num = num;
    this->name = name;
    this->description = description;
    this->price = price;
    this->piece = piece;
    this->raw = raw;
    this->spicy = spicy;
}

bool Sushi::operator==(const Sushi& other) const{
    return num == other.num && name == other.name && description == other.description 
        && price == other.price && piece == other.piece && raw == other.raw && spicy == other.spicy;
}

ostream& operator<<(ostream& os, const Sushi& s){
    os<<"Sushi #"<<s.num <<": "<< s.name <<"("<<s.piece<<
    "pieces) ["<<s.description<<". Raw: "<<(s.raw? "Yes" : "No")
    <<", Spicy: "<<(s.spicy ? "Yes" : "No")<<"] Price: $"<<
    fixed<<setprecision(2)<<s.price;

    return os;
}