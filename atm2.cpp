#include<iostream>
#include<string.h>
using namespace std;

class User
{
private:

string name;
int num1;

public:

User()
{
    name = "";
    num1 = 000000;
}

User(string a)
{
    name = a;
    num1 = 32144;
}

int getNum()
{
    return num1;
}

string getName()
{
    return name;
}

void setName(string a)
{
    name = a;
}

void setNum(int a)
{
    num1 = a;
}

};

class ATM
{

private:
int pin;
bool flag;

protected:
int balance;
string acc;
string type;
User* u1;
int limit;
int track;
int limit2;
int track2;

public:

ATM()
{
    u1 = NULL;
    balance = 0;
    acc = "";
    pin = 1234;
    flag = 0;
    type = "";
    limit = 0;
    track = 0;
    limit2 = 0;
    track2 = 0;
}

void setFlag()
{
    flag = !flag;
}

bool getFlag()
{
    return flag;
}

int getPin()
{
    return pin;
}

void setUser(User& u)
{
    u1 = &u;
    u1->setName(u.getName());
    u1->setNum(u.getNum());
    acc = "abc123";
}

virtual int getBalance(){ return balance; }

virtual void details() 
{
    int x;
    cout<<"Name: "<<u1->getName()<<endl<<"Account Type: "<<type<<endl<<"Account Number: "<<acc<<endl<<"Mobile Number: "<<u1->getNum()<<endl<<"Balance: "<<balance<<endl;
    cout<<"\nPress 1 to continue\n";
    cin>>x;
    if (x == 1)
        system("CLS");
}

virtual void withdraw() 
{

    int amount;
    int count;
    cout<<"Select amount to withdraw:\n1. 500\t2.1000\n3.5000\t4.10000\n5.25000\t6.Other\n";
    cin>>count;

    switch(count)
    {
        case 1:
            amount = 500;
            break;
        case 2:
            amount = 1000;
            break;
        case 3:
            amount = 5000;
            break;
        case 4:
            amount = 10000;
            break;
        case 5:
            amount = 25000;
            break;
        case 6:
        {
            cout<<"Enter Amount:\n";
            cin>>amount;
        }
        default:
            return;
            break;
    }

    if (amount > balance)
    {
        cout<<"Insufficient funds"<<endl;
        return;
    }
    
    if (amount > limit)
    {
        cout<<"Transaction Limit exceeded\n";
        return;
    }

    track += amount;
    if (track > 30000)
    {
        cout<<"One time transaction limit reached. Kindly withdraw after re-entering your atm card\n";
        return;
    }

    balance -= amount;
    cout<<"Transaction successful. Would you like a receipt?\n1.Yes\t2.No"<<endl;
    int receipt;
    cin>>receipt;
    system("CLS");
    if (receipt == 1)
    {
        cout<<"\nName: "<<u1->getName()<<"\nAccount: "<<acc<<"\nAmount: "<<amount<<"\nBalance: "<<balance<<endl;
        cout<<"\nPress 1 to continue\n";
        cin>>receipt;
        if (receipt == 1)
            system("CLS");
    }
    
}


void setPin()
{
    int pin2;
    cout<<"Enter new pin: "<<endl;
    cin>>pin2;
    pin = pin2;
    cout<<"Change successful. New Pin is: "<<pin<<endl;
    cout<<"\nPress 1 to continue\n";
    cin>>pin2;
    if (pin2 == 1)
        system("CLS");
}

virtual void transfer()
{
    string acc2, name2;
    int amount2;
    int pin2;
    int pick;
    string bank_type, bank;

    cout<<"Select Type of Transfer:\n1.Within Bank\t2.Inter-Bank\n";
    cin>>pick;
    if (pick >= 3)
        return;

    if (pick == 2)
    {
        bank_type = "Inter-Bank";
        cout<<"Enter Bank Name: \n";
        cin>>bank;
        if (bank[0] == '7')
            return;
    }

    cout<<"Enter Account Number to transfer to:\n";
    cin>>acc2;
    if (acc2[0] == '7')
        return;
    cout<<"Enter Name of account holder:\n";
    cin>>name2;
    if (name2[0] == '7')
        return;
    cout<<"Enter Amount:\n";
    cin>>amount2;
    if (amount2 == 7)
        return;
    cout<<"Re-enter pin:\n";
    cin>>pin2;
    if (pin2 == 7)
        return;

    if (pin2 != pin)
    {
        cout<<"Incorrect pin. Transaction cancelled\n";
        return;
    }

    if (amount2 > balance)
    {
        cout<<"Insufficient funds"<<endl;
        return;
    }
    
    if (amount2 > limit2)
    {
        cout<<"Transaction Limit exceeded\n";
        return;
    }

    track2 += amount2;
    if (track2 > 100000)
    {
        cout<<"One time transaction limit reached. Kindly withdraw after re-entering your atm card\n";
        return;
    }

    balance -= amount2;
    cout<<"Transaction successful. Would you like a receipt?\n1.Yes\t2.No"<<endl;
    int receipt;
    cin>>receipt;
    if (receipt == 1)
    {
        cout<<"\nTransaction Type: "<<bank_type<<"\nBank Name: "<<bank<<"\nRecepient Name: "<<name2<<"\nRecipient Account: "<<acc2<<"\nAmount: "<<amount2<<"\nBalance: "<<balance<<endl;
        cout<<"\nPress 1 to continue\n";
        cin>>receipt;
        if (receipt == 1)
            system("CLS");
    }
    
}
};

class Current : public ATM
{
public:

Current()
{
    type = "Current";
    balance = 100000;
    acc = "2h38r4r7g3d";
    limit = 75000;
    limit2 = 150000;
}

};

class Savings : public ATM
{
public:

Savings()
{
    type = "Saving";
    balance = 500000;
    acc = "a9873hd27dg42";
    limit = 250000;
    limit2 = 300000;
}

};

class Default : public ATM
{
public:

Default()
{
    type = "Default";
    balance = 200000;
    acc = "vfd564fdv5sv48";
    limit = 100000;
    limit2 = 175000;
}

};

int main()
{
    User p1("Ayaan");
    ATM a1;

    int code;
    cout<<"Enter your pin number\n";
    cin>>code;
    system("CLS");
    int attempts = 0;

    while(code != a1.getPin())
    {
        if (attempts >= 3)
        {
            cout<<"Too many failed attempts. Try again later\n";
            return 0;
        }
        cout<<"Enter correct pin\n";
        cin>>code;
        system("CLS");
        attempts++;
    }

    if (code == a1.getPin())
    {
        a1.setUser(p1);
        a1.setFlag();
    }

    int input;
    int input2 = -1;
    int withdraw;

    cout<<"Select Account:\n1. Current\n2. Savings\n3. Default\n";
    cin>>input2;
    system("CLS");
    ATM* account;

    if (input2 == 1)
        account = new Current;
    
    else if (input2 == 2)
        account = new Savings;
    
    else if (input2 == 3)
        account = new Default;
    
    else 
        return 0;
    
    account->setUser(p1);
    while (input != -1)
    {
        int x = 0;
        cout<<"\nWhat action would you like to perform?"<<endl<<"Check balance: 1"<<endl<<"Withdraw Cash: 2"<<endl;
        cout<<"View Details: 3"<<endl<<"Change ATM Pin: 4"<<endl<<"Transfer: 5"<<endl<<"Exit: 6\nReturn to Menu: 7\n"<<endl;
        cin>>input;
        system("CLS");

        switch(input)
        {
            case 1:
                cout<<"Your balance is: "<<account->getBalance()<<endl;
                cout<<"\nPress 1 to continue\n";
                cin>>x;
                if (x == 1)
                    system("CLS");
                break;
            case 2:
                account->withdraw();
                break;
            case 3:
                account->details();
                break;
            case 4:
                a1.setPin();
                break;
            case 5:
                account->transfer();
                break;
            case 6:
                input = -1;
                break;
            case 7:
                break;
            default:
                input = -1;
                break;
        }
    }

return 0;
}  



    


