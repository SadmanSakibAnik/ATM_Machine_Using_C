#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class atm
{
private:
    char username[25];
    int password;
    int balance;

public:
    char* usernames()
    {

        return username;
    }

    int passwords()
    {

        return password;
    }

    void getData()
    {
        cin.ignore();
        cout << "\nEnter username: ";

        cin.getline(username, 25);
        cout << "\nEnter 4-digit password: ";

        cin >> password;
        cin.ignore();
        cout << "\nEnter initial balance: ";

        cin >> balance;
        cin.ignore();
    }



// Function displaying the data
    void showData()
    {
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
        cout << "Balance: " << balance << endl;
    }

// Member Functions
    int adduser();
    int viewallusers();
    int deleteuser(char*);
    int searchspecificuser(char*, int);
    void updateuserasdeposit(char*);
    void updateuseraswithdraw(char*);
    int searchallusertodisplay(char*);

};


// ATM User
void atmUser()
{
    atm a;

    char uname[25];
    int pass, ch, ch1, ch2, found = 0;

mainmenu:
    system("clear");

    cout << "***********************************************************************"<<endl;
    cout << "*/////////////////////////////////////////////////////////////////////*"<<endl;
    cout << "*////*************************************************************////*"<<endl;
    cout << "*////*                                                           *////*"<<endl;
    cout << "*////*                                                           *////*"<<endl;
    cout << "*////*   ################ Welcome to BUBT ATM ################   *////*"<<endl;
    cout << "*////*                                                           *////*"<<endl;
    cout << "*////*                                                           *////*"<<endl;
    cout << "*////*************************************************************////*"<<endl;
    cout << "*/////////////////////////////////////////////////////////////////////*"<<endl;
    cout << "***********************************************************************"<<endl;
    cout << "\nLogin as :"<<endl<<endl<<"\t1. Admin "<<endl
         << "\t2. User "<<endl<<"\t3. Exit "<<endl<<endl<<"\tPlease Select your Choice: ";

    cin >> ch;

    switch (ch)
    {
    case 1:
rerun:
        system("clear");
        cout << "\nPress 1 to, log in: " << endl;
        cout << "still, Haven't sign up? to login, please enter 2 to sign up:" << endl;
        int check;
        cin >> check;
        if(check == 2)
        {
            ofstream registration;
            registration.open("adminProfile.txt", ios::out | ios::app);
            string name, pass;
            cout << "\nEnter User Name : ";
            cin >> name;
            cout << "\nEnter Password : ";
            cin >> pass;

            registration << name << "\n";
            registration << pass << "\n";

            registration.close();

            check = 1;
        }


        if(check == 1)
        {
            cout<<endl;
            cout<<endl;
            cout << "\t\t<------ Enter details to login as Admin ------>\t\t"<<endl;
            cout<<endl;
            cout << "\nEnter User name: "<<endl;
            string userName;
            cin >>userName;
            cout << "\nEnter password: "<<endl;
            string pass;
            cin >> pass;

            bool auth = false;
            bool gotUserName = false;
            bool gotPass = false;
            ifstream authentication ("adminProfile.txt");
            string str;
            while(getline(authentication, str))
            {
                if(str == userName) gotUserName = true;
                if(str == pass) gotPass = true;
            }
            authentication.close();

            if(gotUserName && gotPass) auth = true;
            if (auth)
            {
admin:
                cout<<endl;
                cout<<endl;
                cout << "=====================================================\n";
                cout << "~~~~~~~~~~~~~~~~ Welcome to Admin Menu ~~~~~~~~~~~~~~\n";
                cout << "=====================================================\n";
                cout<<endl;
                cout<<endl;
                cout<<endl;
                cout << "\t1. Add User"<<endl
                     << "\t2. Delete User "<<endl
                     << "\t3. View All User "<<endl
                     << "\t4. Exit"<<endl;
                cout << "\nSelect onet : "<<endl;
                cin >> ch1;
                cout<<endl;
                cout<<endl;
                switch (ch1)
                {
                case 1:
                    a.adduser();
                    goto admin;

                case 2:
                    cout<<endl;
                    cout << "\nEnter the Username to be deleted : ";
                    cout<<endl;
                    cin.ignore();
                    cin.getline(uname, 25);
                    a.deleteuser(uname);
                    goto admin;

                case 3:
                    a.viewallusers();
                    goto admin;

                case 4:
                    break;
                }
            }
            else
            {
                cout << "\nDetails are incorrect ! Please try again\n";

                goto rerun;
            }
            goto mainmenu;
        }


    case 2:
        system("clear");
        cout<<endl;
        cout<<endl;
        cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\t\t"<<endl;
        cout << "\t\t<------ Enter details to login as User ------>\t\t"<<endl;
        cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\t\t"<<endl;
        cout<<endl;
        cin.ignore();
        cout<<endl;
        cout << "\tEnter username: ";
        cin.getline(uname, 25);
        cout<<endl;
        cout << "\tEnter password: ";

        cin >> pass;
        found = a.searchspecificuser(uname, pass);

        if (found)
        {
user:
            cout << "\t\t==============================="<<endl;
            cout << "\t\t******** Welcome "<< uname << " ********"<<endl;
            cout << "\t\t==============================="<<endl;
            cout << "\tWelcome to User Menu"<<endl;
            cout << "\t1. Deposit"<<endl
                 << "\t2. Withdraw"<<endl
                 << "\t3. View Account"<<endl
                 << "\t4. Exit"<<endl<<endl<<"Enter your choice: "<<endl;
            cin >> ch2;

            switch (ch2)
            {
            case 1:
                a.updateuserasdeposit(uname);
                goto user;
            case 2:
                a.updateuseraswithdraw(uname);
                goto user;
            case 3:
                a.searchallusertodisplay(uname);
                goto user;
            case 4:
                cout << "Thank you"<<endl<<endl;
                break;
            }
        }
        else
        {
            cout << "\nNo account found with username :(\nHit ENTER to continue...." << uname <<endl;
            cin.get();
        }
        goto mainmenu;

    case 3:
        cout<<endl;
        cout<<endl;
        cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout << "\t========= Thank you for banking with BUBT ATM =========\n";
        cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<endl;
        cin.get();
        break;
    }
}


// Function to add user
int atm::adduser()
{
    atm a;

    ofstream file;

// Open file in write mode
    file.open("aaa.txt",ios::out | ios::app);
    if (!file)
    {
        cout << "Error in creating "
             << "file.." << endl;
        return 0;
    }

// Read from user
    a.getData();

// Write into file
    file.write((char*)&a, sizeof(a));

// Close the file
    file.close();

    return 0;
}

// View Users
int atm::viewallusers()
{

    atm a;

    ifstream file1;

// Open file in read mode
    file1.open("aaa.txt", ios::in);
    if (!file1)
    {
        cout << "Error in opening file..";
        return 0;
    }

// Read data from file
    file1.read((char*)&a, sizeof(a));
    while (!file1.eof())
    {

// Display data on monitor
        a.showData();
        file1.read((char*)&a, sizeof(a));
    }

// Close the file
    file1.close();
    return 0;
}

// Function to delete the user
int atm::deleteuser(char* uname)
{

    atm a;

    fstream original, temp;
    original.open("aaa.txt", ios::in);
    if (!original)
    {
        cout << "\nfile not found";
        return 0;
    }
    else
    {
        temp.open("temp.txt",ios::out | ios::app);
        original.read((char*)&a, sizeof(a));

// Till end of file is reached
        while (!original.eof())
        {

            if (!strcmp(a.usernames(),uname))
            {
                cout << "data found and deleted "<< a.username << endl;
            }
            else
            {
                temp.write((char*)&a,sizeof(a));
            }

            original.read((char*)&a,sizeof(a));
        }

        original.close();
        temp.close();
        remove("aaa.txt");
        rename("temp.txt", "aaa.txt");
        a.viewallusers();
    }
    return 0;
}


// Search user
int atm::searchspecificuser(char* uname, int pass)
{
    atm a;
    fstream f;

// Open the file
    f.open("aaa.txt", ios::in);
    if (!f)
    {
        cout << "Error in opening file..";
        return 0;
    }

// Read data from file
    f.read((char*)&a, sizeof(a));
    while (!f.eof())
    {

        if (!strcmp(a.usernames(), uname))
        {
            if (a.passwords() == pass)
            {
                return 1;
            }
        }
        f.read((char*)&a, sizeof(a));
    }

// Close the file
    f.close();
    return 0;
}

// depositing money
void atm::updateuserasdeposit(char* uname)
{

    atm a;
    fstream file, temp;
    file.open("aaa.txt",ios::in | ios::out | ios::ate);
    temp.open("temp.txt",ios::out | ios::app);
    file.seekg(0);
    file.read((char*)&a, sizeof(a));

// Till end of the file
    while (!file.eof())
    {
        if (!strcmp(a.usernames(), uname))
        {
            int b;

            cout << "\nEnter amount to deposit: ";
            cin >> b;
            a.balance = a.balance + b;
            cout << "\nBalance is: "<< a.balance <<endl;
            temp.write((char*)&a, sizeof(a));
        }
        else
        {
            temp.write((char*)&a, sizeof(a));
        }
        file.read((char*)&a, sizeof(a));
    }
    file.close();
    temp.close();
    remove("aaa.txt");
    rename("temp.txt", "aaa.txt");
}

// depositing withdrawing money
void atm::updateuseraswithdraw(char* uname)
{

    atm a;
    fstream file, temp;
    file.open("aaa.txt",ios::in | ios::out | ios::ate);
    temp.open("temp.txt",ios::out | ios::app);
    file.seekg(0);
    file.read((char*)&a, sizeof(a));

// Till end of file is reached
    while (!file.eof())
    {
        if (!strcmp(a.usernames(), uname))
        {
            int b;
            cout << "\nEnter amount to withdraw: ";
            cin >> b;
            if (a.balance < b)
            {
                cout<< "\nInsufficient balance to withdraw\n";
            }
            else
            {
                a.balance = a.balance - b;
                temp.write((char*)&a,sizeof(a));
                cout << "\nBalance is: "<< a.balance <<endl;
            }
        }
        else
        {
            temp.write((char*)&a,sizeof(a));
        }
        file.read((char*)&a, sizeof(a));
    }

// Close the file
    file.close();
    temp.close();
    remove("aaa.txt");
    rename("temp.txt", "aaa.txt");
}

// Search specific user
int atm::searchallusertodisplay(char* uname)
{
    atm a;
    fstream file1;

// Open the file
    file1.open("aaa.txt", ios::in);
    if (!file1)
    {
        cout << "Error in opening file..";
        return 0;
    }

// Read data from file
    file1.read((char*)&a, sizeof(a));
    while (!file1.eof())
    {
        if (!strcmp(a.usernames(), uname))
        {
            a.showData();
            return 0;
        }
        file1.read((char*)&a, sizeof(a));
    }


// Close the file
    file1.close();
    return 0;
}



int main()
{
// Function Call
    atmUser();

    return 0;
}
