//
// Created by Kelly Wang on 11/9/2019.
//
#include "player.h"
#include <cstdlib>
using namespace std;
Player::Player(){
    myName="YourName";
}
void Player::addCard(Card c){
    myHand.push_back(c);
}
void Player::bookCards(Card c1, Card c2){
    myBook.push_back(c1);
    myBook.push_back(c2);
    removeCardFromHand(c1);
    removeCardFromHand(c2);
}
bool Player::checkHandForBook(Card &c1, Card &c2) {
    for(auto i=myHand.begin();i !=myHand.begin();i++){
        for(auto j=i+1; j!=myHand.begin();j++){
            if( (*i).getRank() == (*j).getRank()){
                c1=*i;
                c2=*j;
                return true;
            }
        }
    }
    return false;
}



