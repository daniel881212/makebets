/*
 * Author: Daniel Chen
 * Date: Feb. 6, 2019 
 * Purpose: Plays a game of craps with the user.
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROLL 6
#define MIN_BET 5
#define TRUE 1
#define FALSE 0

/* function prototypes */
int getWallet( void );
int makeBet( int );
int doAgain( void );
void goodbye( int );
int playRound( void );
int rollForPoint( int );
int rollDice( void );
int rollDie( void );

int main() {
    int wallet;
    int bet;

    srand( (unsigned) time( NULL ) );
    
    wallet = getWallet();

    do {
        bet = makeBet( wallet );
        if( playRound() ) {
            printf( "You win :-)\n" );
            wallet += bet;
        }
        else {
            printf( "You lose :-(\n" );
            wallet -= bet;
        }
    } while( wallet >= MIN_BET && doAgain() );
    
    goodbye( wallet );

    return 0;
}

/*
 * Prompts the user for the amount of money they have to play with - assumed to be
 * measured in whole dollars.  Rejects values that are not at least MIN_BET in size
 * and prompts for another value until a value of size MIN_BET dollars or greater
 * is entered.
 * Returns: amount of money entered by user (a positive, integer dollar value)
 */
int getWallet( void ) {

    double money;
    printf("Please enter the amount of money you want to bet: ");
    scanf("%lf", &money);

    while (money < MIN_BET){
        printf("Please enter enough money you want to bet: ");
        scanf("%lf", &money);
    }
        
    return money;
}

/*
 * Prompts user to make a bet (minimum value $MIN_BET, maximum value $wallet)
 * Keeps prompting user until a value of at least $MIN_BET but no more than $wallet
 * is entered.
 * Parameter: wallet - the amount in the user's wallet
 * Returns: user's bet (minimum $MIN_BET)
 */
int makeBet( int wallet ) {

    printf("Please make a bet: ");
    scanf("%d", &bet);

    while (bet < MIN_BET || bet > wallet){
        printf("Please enter a valid bet: ");
        scanf("%d", &bet);
    }
    return bet;
}

/*
 * Ask user if they want to play again.
 * Returns: true if user wants to play again, false otherwise.
 */
int doAgain( void ) {

    int num;

    printf("Do you wanna play again asshole? Press 1 to continue playing.");
    scanf("%d", num);
    while (num == 1){
        return TRUE;
    }
    
    return FALSE;
}

/*
 * Prints goodbye message to user based on whether or not they
 * went broke while playing the game.  Tells the user they're broke
 * if they have less than MIN_BET in their wallet, otherwise tells
 * them how much they have in their wallet.
 * Parameter: wallet - amount of money in wallet
 */
void goodbye( int wallet ) {

    if ( wallet < MIN_BET ){
        printf("You are now a broke muthafakka");
    }
    else {
        printf("You have %.2f dollars left in yo broke ass wallet", wallet);
    }
    return;
}

/* 
 * Plays a single round of craps with the user.
 * Returns: true if user won round, false otherwise.
 */
int playRound( void ) {

    return TRUE;
}

/*
 * Repeatedly rolls dice until either the point value or the value 7 is rolled.
 * Parameter: point - the current point value
 * Returns: true if user rolled point value before rolling a 7 (user won round), 
 * false otherwise (user lost round)
 */
int rollForPoint(void){
    
}

/*
 * Rolls a pair of dice.
 * Returns: sum of face values rolled
 */
int rollDice (void){
    return rollDie() + rollDie();
}

/*
 * Rolls a single die.
 * Returns: face value rolled
 */
int rollDie (void){
    return rand()%6 + 1;
}


