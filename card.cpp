//
// Created by Kelly Wang on 11/9/2019.
//
#include "card.h"
Card::Card(){           // constructor for ace of spades
    myRank=1;
    mySuit=spades;
}
Card::Card(int rank, Suit s){
    myRank=rank;
    mySuit=s;
}
string Card::toString()const{
    return (rankString(myRank) + suitString(mySuit));
}
int Card::getRank() const{    // return rank, 1..13
    return myRank;
}
bool Card::sameSuitAs(const Card& c) const{
    if(mySuit==c.mySuit){
        return true;    // true if suit same as c
    }
    else{
        return false;
    }

}
string Card::suitString(Suit s)const{
    string suitString=0;
    switch(s){
        case hearts:
            suitString="h";
            break;
        case spades:
            suitString="s";
            break;
        case diamonds:
            suitString="d";
            break;
        case clubs:
            suitString="c";
            break;
    }
    return suitString;
}
string Card::rankString(int r)const{
    string rankString=0;
    switch(r){
        case 1: rankString="A"; break;
        case 11: rankString="J"; break;
        case 12: rankString="Q"; break;
        case 13: rankString="K"; break;
    }
    if (r>1 && r<11){
        rankString=r;
    }
    return rankString;

}
bool Card::operator == (const Card& rhs)const{
    return((mySuit==rhs.mySuit) && (myRank==rhs.myRank));
}
bool Card::operator != (const Card& rhs)const{
    return((mySuit!=rhs.mySuit) || (myRank!=rhs.myRank));
}
ostream& operator << (ostream& out, const Card& c){
    out << c.toString();
    return out;
}


