#include <iostream>
#include <string>

using namespace std;

const int MAX_TRANSACTIONS = 100;

int main() {
    int totalTransactions;
    string dates[MAX_TRANSACTIONS];
    double amounts[MAX_TRANSACTIONS];
    string descriptions[MAX_TRANSACTIONS];

    cout << "How many transactions do you want to enter (max " << MAX_TRANSACTIONS << ")? ";
    cin >> totalTransactions;

    if (totalTransactions < 1 || totalTransactions > MAX_TRANSACTIONS) {
        cout << "Invalid number of transactions. Please run the program again." << endl;
        return 1;
    }

    for (int i = 0; i < totalTransactions; ++i) {
        cout << "\nTransaction #" << (i + 1) << endl;
        cout << "Enter date (YYYY-MM-DD): ";
        cin >> dates[i];

        cout << "Enter amount (positive for deposit, negative for withdrawal): ";
        cin >> amounts[i];

        cout << "Enter short description: ";
        cin >> ws;
        getline(cin, descriptions[i]);
    }

    double netBalance = 0;
    double totalWithdrawals = 0;

    for (int i = 0; i < totalTransactions; ++i) {
        netBalance += amounts[i];
        if (amounts[i] < 0) {
            totalWithdrawals += amounts[i];
        }
    }

    cout << "\n========== Summary ==========" << endl;

    cout << "Net Balance: $";
    double val_nb = netBalance;
    bool is_negative_nb = false;
    if (val_nb < 0) {
        is_negative_nb = true;
        val_nb = -val_nb;
    }

    long long scaled_val_nb = static_cast<long long>(val_nb * 100.0 + 0.5);
    long long integer_part_nb = scaled_val_nb / 100;
    int fractional_part_nb = static_cast<int>(scaled_val_nb % 100);

    if (is_negative_nb) {
        cout << "-";
    }
    cout << integer_part_nb << ".";
    if (fractional_part_nb < 10) {
        cout << "0";
    }
    cout << fractional_part_nb << endl;

    cout << "Total Withdrawals: $";
    double val_tw = totalWithdrawals;
    bool is_negative_tw = false;
    if (val_tw < 0) {
        is_negative_tw = true;
        val_tw = -val_tw;
    }

    long long scaled_val_tw = static_cast<long long>(val_tw * 100.0 + 0.5);
    long long integer_part_tw = scaled_val_tw / 100;
    int fractional_part_tw = static_cast<int>(scaled_val_tw % 100);

    if (is_negative_tw) {
        cout << "-";
    }
    cout << integer_part_tw << ".";
    if (fractional_part_tw < 10) {
        cout << "0";
    }
    cout << fractional_part_tw << endl;

    return 0;
}