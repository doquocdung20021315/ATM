#include"ATM.h"

int main()
{
    ATM atm(0, 0, 0, 0, 0, 0);// cay ATM chua co to tien nao;
    nick nick1("0001", "1111", 0); // nick1: id = 0001, pass = 1111, so tien trong tai khoan = 0;
    nick nick2("0002", "2222", 0); // nick2: id = 0002, pass = 2222, so tien trong tai khoan = 0;
    string m;
    do{
        cout << "Nhap A de dang nhap" << endl;
        cout << "Nhap B de tat cay ATM" << endl;
        cin >> m;
        if(m == "A"){
            int a = login(nick1, nick2);
            if(a == 1){
                string cn;
                do{
                    cout << "Nhap A de gui tien" << endl;
                    cout << "Nhap B de rut tien" << endl;
                    cout << "NHap C de xem lich su" << endl;
                    cout << "Nhap D de dang xuat" << endl;
                    cin >> cn;
                    if(cn == "A"){guitien(atm, nick1);}
                    if(cn == "B"){ruttien(atm, nick1);}
                    if(cn == "C"){xemlichsu();}
                }while(cn != "D");
            }
            if(a == 2){
                string cn;
                do{
                    cout << "Nhap A de gui tien" << endl;
                    cout << "Nhap B de rut tien" << endl;
                    cout << "NHap C de xem lich su" << endl;
                    cout << "Nhap D de dang xuat" << endl;
                    cin >> cn;
                    if(cn == "A"){guitien(atm, nick2);}
                    if(cn == "B"){ruttien(atm, nick2);}
                    if(cn == "C"){xemlichsu();}
                }while(cn != "D");
            }
        }
    }while(m != "B");
    return 0;
}
