#include <iostream>
#include "coins.h"

using namespace std;

constexpr int CENTS_FOR_CHIPS = 149;
constexpr int AMOUNT = 405;

int main()
{
    Coins piggyBank = Coins(50, 50, 50, 50);
    Coins pocket = Coins(8, 3, 6, 8);

    cout << "Initial piggy bank: " << piggyBank << endl;
    cout << "Initial pocket: " << pocket << endl << endl;

    cout << "Bought chips using pocket " << endl;
    Coins chips = pocket.extract_exact_change(coins_required_for_cents(CENTS_FOR_CHIPS));
    cout << "Coins required for chips: " << chips << endl;
    cout << "Pocket after paying for chips: " << pocket << endl << endl;
    
    cout << "Transferring money to pocket" << endl;
    Coins trans = piggyBank.extract_exact_change(coins_required_for_cents(AMOUNT));
    cout << "Coins for transfer: " << trans << endl;
    pocket.deposit_coins(trans);
    cout << "Pocket: " << pocket << endl;
    cout << "Piggy bank: " << piggyBank << endl << endl;

    cout << "Transferring sofa change to piggy bank" << endl;
    Coins sofa = Coins(10, 10, 10, 10);
    piggyBank.deposit_coins(sofa);
    cout << "Sofa: " << sofa << endl;
    cout << "Piggy bank: " << piggyBank << endl << endl;

    cout << "Piggy bank total: ";
    print_cents(piggyBank.total_value_in_cents(), cout);


}
