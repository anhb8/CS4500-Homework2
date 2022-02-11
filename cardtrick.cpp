/******************************************************************************
Programming language: C++ 
Name: Patricia Linder & Alina Nguyen 
Date: 02/03/2022
Class: CS4500
Description: The program uses a pseudo-random number generator to shuffle an abbreviated deck of cards with 21 cards. 
The user picks a card from a deck of 21 cards and the program tell the user which card it is. 
Central data structures: Arrays
External files: None

*******************************************************************************/
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;

void buildDeck(int deck[], const int size);
void dealOutCards(int deck[], int play[][3]);
void pickUpCards(int deck[], int play[][3], int column);
void findSecretCard(int deck[]);
void revealSecretCard(int card);

int main(void){
    int column = 0, i = 0;
    int count = 0;
    string playAgain;
    int deck[52] = {0};
    int doTrick[7][3] = {0};
    srand(time(0));
    do{
        buildDeck(deck, 52);
        cout << endl << "Pick a card and make sure to remember it: \n";
        
        //card trick for loop
        for(i = 0; i < 3; i++){
            //deal out 21 cards
            dealOutCards(deck, doTrick);
            
            //Ask user to enter the column contains their card 
            cout << endl <<"Is your card in column 0, 1, or 2? ";
            cin >> column;
            while(column < 0 || column > 2) {
                cout << "Error: Invalid column. Please enter column from 0-2: ";
                cin >> column;
            }
            pickUpCards(deck, doTrick, column);
        }
        //find and reveal secret card
        findSecretCard(deck);
        //ask if user wants to play again
        cout << "\nWould you like to play again, yes(y) or no(n)? ";
        cin >> playAgain;
        
        
            // If the user input is invalid, keep displaying the error message until the input is valid
            while (playAgain != "y" && playAgain != "Y" && playAgain != "n" && playAgain != "N") {
                cout <<"Error: Invalid input. Please enter Y/y for YES, N/n for NO: ";
                cin >> playAgain;
            }
     count+=1;       
    }while(playAgain == "y" || playAgain == "Y");
    cout << "\nThanks for playing!\n";
    cout <<"You played this game " << count << " times";
    return 0;
}

void buildDeck(int deck[], const int size){
    int used[52] = {0};
    int card = 0, i = 0;
    for(i = 0; i < 52; i++){
        do{
            card = rand() % 52;
        }while(used[card] == 1);
        used[card]++;
        deck[i] = card;
    }
    return;
}

void dealOutCards(int deck[],int play[][3]){
    int row = 0, col = 0, card = 0;
    for (row = 0; row < 7; row++){
        play[row][col] = deck[card];
        for (col = 0; col < 3; col++){
            play[row][col] = deck[card];
            card++;
        }
    }
    cout << "\n Column 0                Column 1              Column 2\n";
    cout << "_______________________________________________________\n";
    for(int row = 0; row < 7; row++){
        for(int col = 0; col < 3; col++){
            revealSecretCard(play[row][col]);
        }
        cout << endl;
    }
    return;
}

void pickUpCards(int deck[], int play[][3], int column){
    int card = 0, row = 0;
    for (row =0 ; row < 3; row++){
        int pickUpColumn = (column + row + 2) % 3;
        for(int cardInColumn = 0; cardInColumn < 7; cardInColumn++){
            deck[card++] = play[cardInColumn][pickUpColumn];
        }
    }
    return;
}

void findSecretCard(int deck[]){
    int card = 0;
    for(card = 0; card < 10; card++){
        cout.width(5);
    }
    cout << endl <<"Your secret card is: ";
    revealSecretCard(deck[card]);
    cout << endl;
    return;
}

void revealSecretCard(int card){
    int rank = 0;
    int suit = 0;
    rank = card % 13, suit = (card - rank) / 13;
    //rank of the card
    if (rank == 0)
        cout << right << setw(7) << " Ace";
    else if (rank == 9)
        cout << right << setw(7) << " 10";
    else if (rank == 10)
        cout << right << setw(7) << " Jack";
    else if (rank == 11)
        cout << right << setw(7) << " Queen";
    else if (rank == 12)
        cout << right << setw(7) << " King";
    else
        cout << setw(6) << " " << rank;
    cout << " of";
    //suit of the card
    if (suit == 0)
         cout << left << setw(10) << " Clubs ";
    else if (suit == 1)
        cout << left << setw(10) << " Diamonds ";
    else if (suit == 2)
        cout << left << setw(10) << " Hearts ";
    else
        cout << left << setw(10) << " Spades ";
    return;
}





