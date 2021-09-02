#ifndef _USER_HPP_
#define _USER_HPP_

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class user{
    private:
            string surename;
            string name;
            int age;
            string sex;
            string username;
            string password;
    public:

    // void setsurname(string _surename){
    //     surename = _surename;
    // }
    // void setname(string _name){
    //         name = _name;
    // }
    // void setage(int _age){
    //         age = _age;
    // }
    // void setsex(string _sex){
    //     sex = _sex;
    // }
    // void setusrename(string _username){
    //     username = _username;
    // }
    // void setpassword(string _password){
    //         password = _password;
    // }

    string getsurname(){
        return surename;
    }
    string getname(){
        return name;
    }
    int getage(){
        return age;
    }
    string getsex(){
        return sex;
    }
    string getusername(){
        return username;
    }
    string getpassword(){
        return password;
    }

    // friend ostream& operator<<(ostream& out, const user& output){    //function overload
    //     out << "surname\t\t"<<output.surename
    //         << "name\t\t"<<output.name
    //         << "age\t\t"<<output.age
    //         << "sex\t\t"<<output.sex
    //         << "username\t\t"<<output.username
    //         << "password\t\t"<<output.password;
    //     return out;
    // }
    friend istream& operator>>(istream& in,  user& input){
            cout<< "|Surname:\t\t"; in >> input.surename;
            cout<< "|Name:\t\t"; in >> input.name;
            cout<< "|Age:\t\t"; in >> input.age;
            cout<< "|Gender *M* or *W*:\t\t"; in >> input.sex;
            cout<< "|Username:\t\t"; in >>input.username;
            cout<< "|Password:\t\t"; in >> input.password;
        return in;
    }

};

#endif