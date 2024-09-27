//#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#define endl '\n'
using namespace std;
string txt = ".txt";
string Filename(string& name)
{
    cout << "Username: ";
    cin >> name;
    return name+txt;
}

void SignUp(string user)
{
    user = Filename(user);
    ifstream checkFile(user);
    if (checkFile.is_open()) {
        cout << "User already exists!" << endl;
        checkFile.close();
        return;
    }

    string password;
    cout << "Password: ";
    cin >> password;
    ofstream UserFile(user);
    UserFile << password;
    UserFile.close();
}
bool Login(string& user)
{
    cout << "[Press * to Menu] ";
    string userfile;
    cout<<"Enter username: ";
    cin>>user;
    userfile=user+".txt";
    
    ifstream ReadFile(userfile);
    if(!ReadFile.is_open()) {
        if(userfile=="*.txt")
            return false;
        else{
        cout << "User does not exist!" << endl;
        ReadFile.close();
        return false;
        }
    }
    cin.ignore();
    string pass;
    getline(ReadFile, pass);
    ReadFile.close();

    string password;
    cout << "Password: ";
    cin >> password;

    if(password==pass)
        return true;
    else
    {
        cout << "NO" << endl;
        int pos = userfile.find(".");
        userfile = userfile.substr(0, pos);
        Login(user);
    }
}
void ReadDiary(const string& user)
{
    cout<<"user = " <<user<<"\n";
    ifstream MyReadFile(user); //ios::in
    
    if(MyReadFile.is_open()){ string myText;
    //cin.ignore();
    while(getline (MyReadFile, myText))
    {
        for(auto x:myText)
        {
            cout << char(x-2);
        }
    }
    }
    MyReadFile.close();
   // exit(0);
}
void WriteDiary(const string& user)
{
    cout << "Start typing from here: " << endl;
    string userfile=user+"1.txt";
    ofstream MyFile(userfile); //ios::out
    if(MyFile.is_open()){ string input;
    cin.ignore();
    while(getline(cin, input))
    {
        if(input=="*")
            break;
        for(auto x: input)
        {
            MyFile << char(x+2);
        }
        break;
        MyFile << endl;
    }
    }
    MyFile.close();

    char yes;
    cout << "Read your file? (y/n) : ";
    cin >> yes;
    if(yes == 'y')
        ReadDiary(userfile);
    else
        exit(0);
}
string HomePage(string username)
{
    while(true)
    {
        int option;
        cout << "Press 1 to Sign up" << endl;
        cout << "Press 2 to Log in" << endl;
        cout << "Press otherwise to Exit" << endl;
        cout << "Your choice - ";
        cin >> option;

        username = "*";
        if(option==1)
            SignUp(username);
        else if(option==2)
        {
            bool login;
            login = Login(username);
            if(login==false)
            {
                if(username=="*")
                    return username;
                //cout << "NO" << endl;
                else{
                //int pos = username.find(".");
                username = "error"; //username.substr(0, pos);
                }
            }
            else
            {
                WriteDiary(username);
                exit(0);
            }
        }
        else
            break;
    }
    return username;
}
int main()
{
    string username; // = "neo"; Login(username);
    username = HomePage(username);
    return 0;
}
