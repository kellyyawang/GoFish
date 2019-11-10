//
// Created by gdoug on 11/9/2019.
//

#include "deck.h"

Deck::Deck() {
    int startIndex=0;
    int stopIndex=13;
    myIndex=0;
    for (int i = 0; i<4; i++){
        int deckIndex = 1;
        for (int j = startIndex; j < stopIndex; j++){
            myCards[j]=Card(deckIndex,Card::Suit(i));
//cout<<j<<"="<<myCards[j].toString()<<endl;
            deckIndex++;
        }
        startIndex+=13;
        stopIndex+=13;

    }
}

void Deck::shuffle() {
    Card shuffled[SIZE];
    for(int j = 0; j<SIZE; j++) {
        int randomNum = rand() % SIZE;
        while (myCards[randomNum]==Card(15,Card::Suit(0))) { //find valid card
            randomNum = rand()%SIZE;
        }
            shuffled[j]=myCards[randomNum]; //put a random card into the shuffled deck
            myCards[randomNum]=Card(15,Card::Suit(0)); //set to invalid card so it wont be chosen again
        }
    for(int i = 0; i<SIZE; i++){
        myCards[i]=shuffled[i]; //bring all the shuffled cards into original deck
        //cout<<i<<"="<<myCards[i].toString()<<endl;
    }
}

Card Deck::dealCard() {
    if (size()==0){
        return Card(15,Card::Suit(0)); //return invalid card as failed
    }
    Card dealed = myCards[myIndex];
    myIndex++;
    return dealed; //deal a card, update index
}

int Deck::size() const {
    int size = 0;
    for (int i = myIndex; i<SIZE; i++){ //counts from index to end
        size++;
    }
    return size;
}

