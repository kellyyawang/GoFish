// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;



// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);


int main()
{
    Deck d;
    Player p1("Gwyni");
    Player p2("Kelly");
    d.shuffle();
    for (int i=0;i<7;i++){
        p1.addCard(d.dealCard());
        p2.addCard(d.dealCard());
    }
    cout <<"Gwyni's hand: " << p1.showHand()+"\n";
    cout <<"Kelly's hand: " << p2.showHand();
}