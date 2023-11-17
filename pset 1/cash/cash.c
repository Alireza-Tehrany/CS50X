
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask how many cents the customer is owed
    int cents;
    do
    {
        cents = get_int("How much cents do you have?");
    }
    while (cents < 0);

    // Calculate the number of quarters to give the customer
    int quarters = 0;
    while (cents >= 25)
    {
        cents = cents - 25;
        quarters++;
    }

    // Calculate the number of dimes to give the customer
    int dimes = 0;
    while (cents >= 10)
    {
        cents = cents - 10;
        dimes++;
    }

    // Calculate the number of nickels to give the customer
    int nickels = 0;
    while (cents >= 5)
    {
        cents = cents - 5;
        nickels++;
    }

    // Calculate the number of pennies to give the customer
    int pennies = 0;
    while (cents >= 1)
    {
        cents = cents - 1;
        pennies++;
    }

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}
