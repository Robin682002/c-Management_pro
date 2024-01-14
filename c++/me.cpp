#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class temp{
    string Number,name,address,description,search;
    fstream file;
    public:
    void addContact();
    //void showAll();
    //void searchContact();
}obj;

int main(){

   char choice;

   cout<<"1 --> Add Contact "<<endl;
   cout<<"2 --> Show All Contact "<<endl;
   cout<<"3 --> Search Contact "<<endl;
   cout<<"0 --> exit "<<endl;
   cin>>choice;

    switch (choice)
    {
    case '1':
        obj.addContact();
        break;
   /* case '2':
        obj.showAll();
        break;
    case '3':
        obj.searchContact();
        break;*/
    case '0':
        return 0;
        break;
    default:
            cout<<"Invalid Selection ...!";
        break;
    }

    return 0;
}
void temp :: addContact()
{
    cout<<"Enter phone Number ::";
    cin>>Number;
    
    cout<<"Enter Name :: ";
    getline(cin,name);
    cin>>name;
    cout<<"Enter Address :: ";
    //getline(cin,address);
    cin>>address;
    cout<<"Enter Description ::";
   // getline(cin,description);
    cin>>description;

    file.open("data.csv",ios :: out | ios :: app);
    file<<Number<<',';
    file<<name<<',';
    file<<address<<',';
    file<<description<<"\n"; //in csv file the shift next cell/or next space use ","
    file.close();

}