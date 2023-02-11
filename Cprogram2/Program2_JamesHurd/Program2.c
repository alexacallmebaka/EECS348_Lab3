/*
 * Program2.c
 *
 *  Created on: Feb 11, 2023
 *      Author: james
 */

#include <stdio.h>

//"denominations" of our coins.
const int denoms[5] = {8, 7, 6, 3, 2};

/*
 * print all possible "change" that can be made.
 * total is the amount we are given.
 * wallet is how much of each "coin" we have.
 * index is which coin we want to make change of.
 */
void make_change(int total, int wallet[5], int index) { //{{{1

  //base case: we have used every coin in the current change.
  if (index > 4) {
    //if there is nothing left to break up, we have made a valid change.
    if (total == 0) {
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", wallet[0], wallet[1], wallet[2], wallet[3], wallet[4]);
    }
    return;
  }

  //current denomination of coin we are using.
  int denom = denoms[index];

  //the upper bound of that coin that we can use.
  int max = total/denom;

  //loop through each possibility for that coin.
  for(int i=max; i>=0; --i) {

    //how many points that we have scored in this denomination.
    int pts = i*denom;

    //the amount of points left the make change with.
    int rem = total-pts;

    //add that amount to our wallet.
    wallet[index] = i;

    //make change with what we have left in next-lowest coin denomination.
    make_change(rem, wallet, index+1);
  }
} //1}}}

int main() { //{{{1

int input;

while (1)
{

printf("Enter an NFL score: ");
scanf("%d", &input);

if (input <= 1)
  break;

int wallet[5];

//this is just a change-making problem, so we make change!
make_change(input, wallet, 0);

}

printf("See you space cowboy...\n");
return 0;
}//1}}}


