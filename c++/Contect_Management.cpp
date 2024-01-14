#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string phoneNo,name,address,description,search;
    fstream file;
    public:
    void addContact();
    void showAll();
    void searchContact();
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
    case '2':
        obj.showAll();
        break;
    case '3':
        obj.searchContact();
        break;
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
    cin>>phoneNo;
    
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
    file<<phoneNo<<',';
    file<<name<<',';
    file<<address<<',';
    file<<description<<"\n"; //in csv file the shift next cell/or next space use ","
    file.close();

}
/*void temp :: addContact()
{
    cout<<"Enter phone Number ::";
    getline(cin,phoneNo);
    cout<<"Enter Name :: \n";
    getline(cin,name);
    cout<<"Enter Address :: \n";
    getline(cin,address);
    cout<<"Enter Description ::\n ";
    getline(cin,description);

    file.open("data.csv",ios :: out | ios :: app);
    file<<phoneNo<<","<<name<<","<<address<<","<<description<<"\n"; //in csv file the shift next cell/or next space use ","
    file.close();

}*/
void temp:: showAll(){
    
    file.open("data.csv",ios :: in); //file will open 

    getline(file,phoneNo,',');//after opening it will read up to "," and store it related variable
    getline(file,name,',');
    getline(file,address,',');
    getline(file,description,'\n');
    while(!file.eof()){
        cout<<"Phone Number :: "<<phoneNo<<endl;
        cout<<"Phone Name :: "<<name<<endl; // file main loop chalaungaa,data fetch karungaa and display karungaa relative variable main
        cout<<"Phone Address :: "<<address<<endl;
        cout<<"Phone description :: "<<description<<endl<<endl;

        getline(file,phoneNo,',');
        getline(file,name,',');
        getline(file,address,',');
        getline(file,description,'\n');
    }
    file.close();
}
void temp:: searchContact(){

    cout<<"Enter Phone Number :: ";
    getline(cin,search);

    file.open("data.csv",ios :: in);

    getline(file,phoneNo,',');
    getline(file,name,',');
    getline(file,address,',');
    getline(file,description,'\n');
    while(!file.eof()){
        if(phoneNo == search){
        cout<<"Phone Number :: "<<phoneNo<<endl;
        cout<<"Phone Name :: "<<name<<endl; //this is a display command if search match
        cout<<"Phone Address :: "<<address<<endl;
        cout<<"Phone description :: "<<description<<endl<<endl;
        }
        getline(file,phoneNo,',');
        getline(file,name,','); //if not match the againg take and compare 
        getline(file,address,',');
        getline(file,description,'\n');
    }
    file.close();
}