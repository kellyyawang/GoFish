
#include <iostream>    
#include <cstdlib>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

void bookHelper(Card &card1, Card &card2, Player &p1){
    if(p1.checkHandForBook(card1,card2)){
        p1.bookCards(card1,card2);
        p1.removeCardFromHand(card1);
        p1.removeCardFromHand(card2);
        string pName=p1.getName();
        cout << pName <<" Books " ;
        cout<<p1.showBooks()<<endl;
    }
}

int main() {
    Deck d;
    Card card1;
    Card card2;
    Card foundCard;
    Player p1("Gwyni");
    Player p2("Kelly");

    int totalBookSize = p2.getBookSize() + p1.getBookSize();
    d.shuffle();
    for (int i = 0; i < 7; i++) {
        p1.addCard(d.dealCard());
        p2.addCard(d.dealCard());
    }
    cout << "Gwyni's hand: " << p1.showHand() << endl;
    cout << "Kelly's hand: " << p2.showHand() <<endl;

    Card neededCard;
    p1turn:
    while (totalBookSize <= 26) {
        if(p1.getHandSize()==0){
            break;
        }
        totalBookSize = p2.getBookSize() + p1.getBookSize();
        cout<<"total books:";
        cout<<totalBookSize<<endl;

        neededCard = p1.chooseCardFromHand();
        cout << "Gwyni: Do you have any " << neededCard.rankString(neededCard.getRank()) << "'s?" << endl;
        cout<<"Needed card: "<<neededCard<<endl;

        if (p2.sameRankInHand(neededCard)) {
            cout << "Kelly: Yeah! I have the " << neededCard.rankString(neededCard.getRank()) << endl;
            foundCard = p2.removeCardFromHand(neededCard);
            cout<<"Found card: "<<foundCard<<endl;
            p1.addCard(foundCard);
            cout << "Gwyni's Hand:" ;
            cout<<p1.showHand()<<endl;
            cout << "Kelly's Hand:" ;
            cout<<p2.showHand()<<endl;

            bookHelper(foundCard, neededCard, p1);
            goto p1turn;
        }
        else {
            cout << "Kelly: Go FISH..." << endl;
            if (d.size()>0){
                Card newCard = d.dealCard();
                p1.addCard(newCard);
                cout << "Gwyni drew a " << newCard.toString() << endl;
                cout << "Gwyni's Hand:" ;
                cout<<p1.showHand()<<endl;
                cout << "Kelly's Hand:" ;
                cout<<p2.showHand()<<endl;
            }
            else{
                goto p2turn;
            }

            bookHelper(card1, card2, p1);
            goto p2turn;
        }
        p2turn:
        if(p2.getHandSize()==0){
            break;
        }
        totalBookSize = p2.getBookSize() + p1.getBookSize();
        cout<<"total books:";
        cout <<totalBookSize<<endl;
        neededCard = p2.chooseCardFromHand();
        cout << "Kelly: Do you have any " << neededCard.rankString(neededCard.getRank()) << "'s?" << endl;
        if (p1.sameRankInHand(neededCard)) {
            cout << "Gwyni: Yeah! I have the " << neededCard.rankString(neededCard.getRank()) << endl;
            foundCard = p1.removeCardFromHand(neededCard);
            p2.addCard(foundCard);
            cout << "Gwyni's Hand:" ;
            cout<<p1.showHand()<<endl;
            cout << "Kelly's Hand:" ;
            cout<<p2.showHand()<<endl;

            bookHelper(foundCard, neededCard, p2);
            goto p2turn;
        }
        else {
            cout << "Gwyni: Go FISH..." << endl;
            if (d.size()>0){
                Card newCard = d.dealCard();
                p2.addCard(newCard);
                cout << "Kelly drew a " << newCard.toString() << endl;
                cout << "Gwyni's Hand:" ;
                cout<<p1.showHand()<<endl;
                cout << "Kelly's Hand:" ;
                cout<<p2.showHand()<<endl;
            }
            else{
                goto p1turn;
            }
            bookHelper(card1, card2, p2);
            goto p1turn;
        }
    }
    cout<< "\nGwyni's Books: " <<p1.showBooks()<<endl;
    cout << "Gwyni's # of Books:" ;
    cout<<p1.getBookSize()<<endl;
    cout<< "\nKelly's Books: "<< p2.showBooks()<<endl;
    cout << "Kelly's # of Books:" ;
    cout<<p2.getBookSize()<<endl;
    if(p1.getBookSize() > p2.getBookSize()){
        cout<< "Gwyni Won!";
    }
    else{
        cout<< "Kelly Won!";
    }
}