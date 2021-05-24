#ifndef ATM_H_INCLUDED
#define ATM_H_INCLUDED
#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
using namespace std;
struct nick{
    string id;
    string pass;
    int sotien;
    nick(){};
    nick(string _id, string _pass, int _sotien){
        id = _id;
        pass = _pass;
        sotien = _sotien;
    }
};
struct tien{
    int soto;
    int menhgia;
    tien(){};
    tien(int _st, int _mg){
        soto = _st;
        menhgia = _mg;
    }
};
struct ATM{
    int st10;
    int st20;
    int st50;
    int st100;
    int st200;
    int st500;
    ATM(int _st10, int _st20, int _st50, int _st100, int _st200, int _st500){
        st10 = _st10;
        st20 = _st20;
        st50 = _st50;
        st100 = _st100;
        st200 = _st200;
        st500 = _st500;
    }
};
int mgmin(ATM& atm);
char *now();
void xemlichsu();
void ruttien(ATM& atm, nick& n);
void guitien(ATM& atm, nick& n);
int login(nick& nick1, nick& nick2);


#endif // ATM_H_INCLUDED
