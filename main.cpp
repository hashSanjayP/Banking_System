#include "bank.h"
#include <fstream>
using namespace std;

void deposit(double *balance){
    cout<<"How much you want to deposit? Enter Amount:"<<endl;
            double amount;
            cin>>amount;
            *balance+=amount;
            cout<<"Rs. "<<amount<<" deposited successfully. Current Balance is "<<*balance<<"."<<endl;
}

void withdraw(double *balance){
    if(*balance==0){
        cout<<"Sorry! You have Rs.0 in bank you cant withdraw money!"<<endl;
        return ;
    }
    cout<<"How much you want to withdraw today?"<<endl;
    double amount;
        cin>>amount;
    if((*balance+1e-3)>=amount){
        *balance-=amount;
        cout<<"Amount of Rs. "<<amount<<" withdrawn successfully. Your current balance is Rs. "<<*balance<<endl;
        return ;
    }else{
        cout<<"Insufficient Balance. Current Balance is only Rs. "<<*balance<<"."<<endl;
        withdraw(balance);
    }

}

void openingDialogue(){
    cout<<"Welcome to Sanjay's Banking System"<<endl;
    cout<<"What you want to do today?"<<endl;
    cout<<"\t1. Deposit Money"<<endl<<"\t2. Withdraw Money"<<endl<<"\t3. Check Balance"<<endl;
}

int main(){
    openingDialogue();

    fstream file("Data.txt", ios::in | ios::app);

    if(file.is_open()){
        
    }
    int a;
    double balance=0;
    while(cin>>a){
        switch (a)
        {
        case 1:
            deposit(&balance);
            break;
        case 2:
        withdraw(&balance);
        break;
        case 3:
        cout<<"Your Account has Rs. "<<balance <<"."<<endl;
        break;
        default:
            break;
        }
    }
}
