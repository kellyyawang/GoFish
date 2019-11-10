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
Card Player::chooseCardFromHand() const {
    int rIndex=rand() % myHand.size();
    Card temp=myHand.at(rIndex);
    return temp;
}
bool Player::cardInHand(Card c) const {
    for(int i=0; i<myHand.size(); i++){
        if (c==myHand.at(i)){
            return true;
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c) {
    Card null;
    for (auto i =myHand.begin();i!=myHand.end();i++) {
        if (*i == c) {
            myHand.erase(i);
            return c;
        }
    }
    return null;
}

string Player::showHand() const {
    string hand = "";
    Card card;
    for (auto i =myHand.begin();i!=myHand.end();i++){
        card=*i;
        hand += card.toString() + ", ";
    }
    return hand;
}

string Player::showBooks() const {
    string books = "";
    Card card;
    for (auto i =myBook.begin();i!=myBook.end();i++){
        card=*i;
        books += card.toString() + ", ";
    }
    return books;
}

int Player::getHandSize() const {
    int count = 0;
    for (auto i =myHand.begin();i!=myHand.end();i++){
        count++;
    }
    return count;
}

int Player::getBookSize() const {
    int count = 0;
    for (auto i =myBook.begin();i!=myBook.end();i++){
        count++;
    }
    return count;
}
bool Player::sameRankInHand(Card c) const {
    for (auto i =myHand.begin();i!=myHand.end();i++){
        if ((*i).getRank()==c.getRank()){
            return true;
        }
    }
    return false;
}



