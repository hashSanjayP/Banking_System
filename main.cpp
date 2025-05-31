#include "bank.h"
#include <fstream>
using namespace std;

void deposit(double *balance)
{
    cout << "How much you want to deposit? Enter Amount:" << endl;
    double amount;
    cin >> amount;
    *balance += amount;
    cout << "Rs. " << amount << " deposited successfully. Current Balance is " << *balance << "." << endl;
}

void withdraw(double *balance)
{
    if (*balance == 0)
    {
        cout << "Sorry! You have Rs.0 in bank you cant withdraw money!" << endl;
        return;
    }
    cout << "How much you want to withdraw today?" << endl;
    double amount;
    cin >> amount;
    if ((*balance + 1e-3) >= amount)
    {
        *balance -= amount;
        cout << "Amount of Rs. " << amount << " withdrawn successfully. Your current balance is Rs. " << *balance << endl;
        return;
    }
    else
    {
        cout << "Insufficient Balance. Current Balance is only Rs. " << *balance << "." << endl;
        withdraw(balance);
    }
}

void openingDialogue()
{
    cout<<"-----------------------------------------------------------------------------------"<<endl;
    cout << "\n\t\t\tWelcome to Sanjay's Banking System" << endl;
    cout << "\t\t\tWhat you want to do today?" << endl;
    cout << "\t1. Deposit Money\n\t2. Withdraw Money\n\t3. Check Balance\n\t0. Exit\n" << endl;
    cout<<"-----------------------------------------------------------------------------------"<<endl;
}

int main()
{
    openingDialogue();
    double balance = 0;

    ifstream file("Data.txt");

    try
    {
        if (!(file.is_open()))
        {
            throw runtime_error("File couldn't be opened.");
        }

        if (!(file >> balance))
        {
            throw runtime_error("File is empty.");

        }
            cout << "File has been read successfully. Current Balance:" << balance << endl;
            file.close();

    }
    catch (const exception &e)
    {
        cout << "Error:" << e.what() << endl;
    }
    int a;
    cin >> a;
    while (a != 0)
    {
        switch (a)
        {
        case 1:
            deposit(&balance);
            break;
        case 2:
            withdraw(&balance);
            break;
        case 3:
            cout << "Your Account has Rs. " << balance << "." << endl;
            break;
        default:
            break;
        }
        openingDialogue();
        cin >> a;
    }

    ofstream ofile("Data.txt", ios::out | ios::trunc);

    try
    {
        if (!ofile.is_open())
        {
            throw runtime_error("File couldn't be opened.");
        }

        ofile << balance;
        cout << "File has been written successfully. Current Balance:"<<balance<< endl;
        ofile.close();
    }
    catch (const exception &e)
    {
        cout << "Error:" << e.what() << endl;
    }
}
