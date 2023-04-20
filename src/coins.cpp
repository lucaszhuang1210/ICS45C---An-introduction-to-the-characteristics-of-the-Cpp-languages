#include "coins.h"
#include <iostream>

using namespace std;

// all the definitions for class 'Coins'
Coins::Coins(int q, int d, int n, int p)
    :quarters(q),dimes(d),nickels(n),pennies(p)
{
}

void Coins::deposit_coins(Coins& coins)
{
    quarters += coins.quarters;
    dimes += coins.dimes;
    nickels += coins.nickels;
    pennies += coins.pennies;

    coins.quarters = 0;
    coins.dimes = 0;
    coins.nickels = 0;
    coins.pennies = 0;
}

bool Coins::has_exact_change_for_coins(Coins const& coins) const
{
    return (quarters >= coins.quarters) && (dimes >= coins.dimes) && (nickels>=coins.nickels) && (pennies>=coins.pennies);
}

void Coins::print(ostream & out) const
{
    out << quarters << " quarters, "
        << dimes << " dimes, "
        << nickels << " nickels, "
        << pennies << " pennies";
}

Coins Coins::extract_exact_change(Coins const& coins)
{
    if(!has_exact_change_for_coins(coins))
    {
        return Coins(0, 0, 0, 0);
    }else{
        quarters -= coins.quarters;
        dimes -= coins.dimes;
        nickels -= coins.nickels;
        pennies -= coins.pennies;

        return coins;
    }
}

int Coins::total_value_in_cents() const
{
    return quarters*25 + dimes*10 + nickels*5 + pennies;
}





// all the definitions outside of class 'Coins'
ostream & operator <<(ostream & out, Coins const& coins)
{
    coins.print(out);
    return out;
}

Coins coins_required_for_cents(int amount_in_cents)
{
    int q, d, n, p;
    q = amount_in_cents / CENTS_PER_QUARTER;
    amount_in_cents = amount_in_cents % CENTS_PER_QUARTER;

    d = amount_in_cents / CENTS_PER_DIME;
    amount_in_cents = amount_in_cents % CENTS_PER_DIME;

    n = amount_in_cents / CENTS_PER_NICKEL;
    amount_in_cents = amount_in_cents % CENTS_PER_NICKEL;
    
    p = amount_in_cents;

    return Coins(q, d, n, p);
}

void print_cents(int cents, ostream& out=cout)
{
    out << "$" << cents/100.0 << endl;
}
