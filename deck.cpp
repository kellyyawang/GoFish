//
// Created by gdoug on 11/9/2019.
//

#include "deck.h"

Deck::Deck() {
    int startIndex=1;
    int stopIndex=14;
    for (int i = 0; i<4; i++){
        int deckIndex = 1;
        for (int j = startIndex; j < stopIndex; j++){
            myCards[j]=Card(deckIndex,Card::Suit(i));
            cout<<deckIndex<<". "<<myCards[deckIndex].toString()<<endl;
            deckIndex++;
        }
        startIndex+=14;
        stopIndex+=14;
    }
}

void Deck::shuffle() {
    Card shuffled[SIZE];
    for(int j = 0; j<SIZE; j++) {
        int randomNum = rand() % size();
        shuffled[j]=myCards[randomNum];
    }
    for(int i = 0; i<size(); i++){
        myCards[i]=shuffled[i];
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

