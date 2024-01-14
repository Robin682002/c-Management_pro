#include <iostream>
#include <fstream> //for accessing file this file hadder file
using namespace std;

class temp
{
private:
    string userName, Email, password;
    string searchName, searchPass, searchEmail;
    fstream file; //file name variable to ensure the file opening and closing

public:
    void login()
    {
        cout << "\nEnter Your User Name :: ";
        getline(cin, userName);
        cout << "Enter Your Email Address :: ";
        getline(cin, Email);
        cout << "Enter Your Password :: ";
        getline(cin, password);

        file.open("loginData.txt", ios ::out | ios ::app); // sending the data in the  file we are opning file using we are writing the data so using ios :: out in append mode  .open operator  
        file << userName << "*" << Email << "*" << password << endl; //the variable which are collected sending this in file oit stores in file ltke (JohnDoe*john.doe@example.com*password123)
        file.close();
    }

    void signUP()
    {

        cout << "----------LOGIN---------" << endl;
        cout << "Enter Your User Name :: " << endl;
        getline(cin, searchName); // we are taking getline because it's taking white spaces also 
        cout << "Enter Your Password :: " << endl;
        getline(cin, searchPass);

        file.open("loginData.txt", ios ::in); //in mode we r reading the file 
        getline(file, userName, '*'); //we r taking the data from file and storing it it those (username, email,pass) variable
        getline(file, Email, '*');  
        getline(file, password, '\n');
        while (!file.eof()) //eof = end of file uo to the end
        {
            if (userName == searchName)
            {
                if (password == searchPass)
                {
                    cout << "\nAccount Login Succesfull...!";
                    cout << "\nUsername :: " << userName << endl;
                    cout << "\nEmail :: " << Email << endl;
                }
                else
                {
                    cout << "Password is Incorrect...!";
                }
            }
            getline(file, userName, '*');
            getline(file, Email, '*');
            getline(file, password, '\n');
        }
        file.close();
    }
    void forgot()
    {
        cout << "\nEnter Your UserName :: ";
        getline(cin, searchName);
        cout << "\nEnter Your Email Address :: ";
        getline(cin, searchEmail);

        file.open("loginData.txt", ios ::in);
        getline(file, userName, '*');
        getline(file, Email, '*');
        getline(file, password, '\n');
        while (!file.eof())
        {
            if (userName == searchName)
            {
                if (Email == searchEmail)
                {
                    cout << "\nAccount Found...!" << endl;
                    cout << "Your Password :: " << password << endl;
                }
                else
                {
                    cout << "Not found...!\n";
                }
            }
            else
            {
                cout << "\nNot fount...!\n";
            }
            getline(file, userName, '*');
            getline(file, Email, '*');
            getline(file, password, '\n');
        }
        file.close();
    }
    }obj;

    int main()
    {
        char choice;
        cout << "\n1- Login";
        cout << "\n2- Sign-Up";
        cout << "\n3- Forgot Password";
        cout << "\n4- Exit";
        cout << "\nEnter Your Choice :: ";
        cin >> choice; // chose your statement

        switch (choice)
        {
        case '1':
            cin.ignore();
            obj.login();
            break;
        case '2':
            cin.ignore();
            obj.signUP();
            break;
        case '3':
            cin.ignore();
            obj.forgot();
            break;
        case '4':
            return 0;
            break;
        defualt:
            cout << "Invalid Selection...!";
        }
    }

    // here void temp is my class and I am calling the function singup, login all which are in my class
    
    /*void temp :: signUP(){
        cout<<"\nEnter Your User Name :: ";
        getline(cin,userName);
        cout<<"Enter Your Email Address :: ";
        getline(cin,Email);
        cout<<"Enter Your Password :: ";
        getline(cin,password);

        file.open("loginData.txt",ios :: out | ios :: app);
        file<<userName<<"*"<<Email<<"*"<<password<<endl;
        file.close();
    }
    void temp :: login(){

        cout<<"----------LOGIN---------"<<endl;
        cout<<"Enter Your User Name :: "<<endl;
        getline(cin,searchName);
        cout<<"Enter Your Password :: "<<endl;
        getline(cin,searchPass);

        file.open("loginData.txt",ios :: in);
        getline(file,userName,'*');
        getline(file,Email,'*');
        getline(file,password,'\n');
        while(!file.eof()){
            if(userName == searchName){
                if(password == searchPass){
                    cout<<"\nAccount Login Succesfull...!";
                    cout<<"\nUsername :: "<<userName<<endl;
                    cout<<"\nEmail :: "<<Email<<endl;
                }else{
                    cout<<"Password is Incorrect...!";
                }
            }
        getline(file,userName,'*');
        getline(file,Email,'*');
        getline(file,password,'\n');
        }
        file.close();
    }
    void temp :: forgot(){
        cout<<"\nEnter Your UserName :: ";
        getline(cin,searchName);
        cout<<"\nEnter Your Email Address :: ";
        getline(cin,searchEmail);

        file.open("loginData.txt",ios :: in);
        getline(file,userName,'*');
        getline(file,Email,'*');
        getline(file,password,'\n');
        while(!file.eof()){
            if(userName == searchName){
                if(Email == searchEmail){
                    cout<<"\nAccount Found...!"<<endl;
                    cout<<"Your Password :: "<<password<<endl;
                }else{
                    cout<<"Not found...!\n";
                }
            }else{
                cout<<"\nNot fount...!\n";
            }
        getline(file,userName,'*');
        getline(file,Email,'*');
        getline(file,password,'\n');
        }
       file.close();
    }*/