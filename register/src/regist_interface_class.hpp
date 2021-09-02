#ifndef _INTERFACE_HPP_
#define _INTERFACE_HPP_

#include "regist_user_class.hpp"
#include <fstream>
#include <cassert>
class interface {
    private:
        void registration() {
            user new_user;
            cin >> new_user;
            assert(new_user.getsex() == "m"|| new_user.getsex() == "M"||new_user.getsex() == "W" || new_user.getsex() == "w" );
            ifstream old_user(new_user.getusername() + ".txt");
            if (old_user){
                cout <<"The account already exists\n";
                exit(1);
            }
            else {
                string filename = new_user.getusername() + ".txt";
                ofstream n_pass(filename);
                n_pass << new_user.getname() << "\n"
                       << new_user.getsurname() << "\n" 
                       << new_user.getage() << "\n"
                       << new_user.getsex() << "\n"
                       << new_user.getusername() << "\n"
                       << new_user.getpassword() << "\n";
                n_pass.close();
            }        
        }
        void login() {
            string sign_username;
            string sign_password;
            cout << "\n|Username:\t"; cin >> sign_username;
            cout << "\n|Password:\t"; cin >> sign_password;
            ifstream us_name(sign_username + ".txt");
            if (!us_name){
                cout<<"Your account not found\n";
            }
            else {
                string pass;
                string message;
                int count = 0;
                while(getline(us_name, pass)){
                    switch (count %6){
                        case 5:
                            if (sign_password == pass){
                                cout<< "You are successfully logged in.\nYou can send a message:\t";
                                cin>>message;
                                cout<<"\n\t*********\t"<<message<<"\t*********\n\n";
                            }
                            else {
                                cout<<"\nWrong password\n";
                                exit(1);
                            }
                    }
                    ++count;
                }
            }
        }
    public:
        
        void start() {
            int answer;
            cout<<"*****************************************************************************************\n";
            cout<<"\t|\t1. Registration:\t"<<"|\t2. Login:\t"<<"|\t3. Exit.\t\t|\n";
            cout<<"*****************************************************************************************\n\n\n"; 
            cout<<"|\t Enter your chouse number -->\t|\t"; cin>>answer;
            switch(answer){
                case 1:
                    registration();
                    break;
                case 2:
                    login();
                    break;
                case 3:
                    cout<<"FINISHED\n";
                    exit(0);
                default:
                    cout<<"Error\n";
                    exit(1);
             }
            start();
        }
};

#endif