#include"ATM.h"
int mgmin(ATM& atm){
    if(atm.st10 != 0){return 10;}
    if(atm.st20 != 0){return 20;}
    if(atm.st50 != 0){return 50;}
    if(atm.st100 != 0){return 100;}
    if(atm.st200 != 0){return 200;}
    if(atm.st500 != 0){return 500;}
    return 0;
}
char *now(){
    time_t n = time('\0');
    char *timenow = ctime(&n);
    return timenow;
}
void xemlichsu(){
    ifstream lsgt("C:/BTL/lichsuguitien.txt");
    string gt;
    while(getline(lsgt, gt)){
        cout << gt << endl;
    }
    ifstream lsrt("C:/BTL/lichsuruttien.txt");
    string rt;
    while(getline(lsrt, rt)){
        cout << rt << endl;
    }
}
void ruttien(ATM& atm, nick& n){
    cout << "So tien nho nhat co the rut duoc tu cay ATM hien tai la " << mgmin(atm) << ".000 VND" << endl;
    cout << "Nhap so tien ban muon rut (VD: 10.000 VND -> Nhap 10)" << endl;
    int t;
    cin >> t;
    if(t == 0){
        return;
    }
    if(t > n.sotien){
        cout << "So tien ban muon rut lon hon so tien hien co trong tai khoan cua ban" << endl;
        cout << "Ban khong the rut so tien nay" << endl;
        return;
    }
    int t500 = 0;
    if(t != 0 && atm.st500 != 0){
        if(t <= atm.st500*500){
            t500 = t / 500;
            t = t % 500;
        }else{
            t500 = atm.st500;
            t = t - atm.st500*500;
        }
    }
    int t200 = 0;
    if(t != 0 && atm.st200 != 0){
        if(t <= atm.st200*200){
            t200 = t / 200;
            t = t % 200;
        }else{
            t200 = atm.st200;
            t = t - atm.st200*200;
        }
    }
    int t100 = 0;
    if(t != 0 && atm.st100 != 0){
        if(t <= atm.st100*100){
            t100 = t / 100;
            t = t % 100;
        }else{
            t100 = atm.st100;
            t = t - atm.st100*100;
        }
    }
    int t50 = 0;
    if(t != 0 && atm.st50 != 0){
        if(t <= atm.st50*50){
            t50 = t / 50;
            t = t % 50;
        }else{
            t50 = atm.st50;
            t = t - atm.st50*50;
        }
    }
    int t20 = 0;
    if(t != 0 && atm.st20 != 0){
        if(t <= atm.st20*20){
            t20 = t / 20;
            t = t % 20;
        }else{
            t20 = atm.st20;
            t = t - atm.st20*20;
        }
    }
    int t10 = 0;
    if(t != 0 && atm.st10 != 0){
        if(t <= atm.st10*10){
            t10 = t / 10;
            t = t % 10;
        }else{
            t10 = atm.st10;
            t = t - atm.st10*10;
        }
    }
    if(t == 0){
        atm.st500 = atm.st500 - t500;
        atm.st200 = atm.st200 - t200;
        atm.st100 = atm.st100 - t100;
        atm.st50 = atm.st50 - t50;
        atm.st20 = atm.st20 - t20;
        atm.st10 = atm.st10 - t10;
        n.sotien = n.sotien - t500*500 - t200*200 - t100*100 - t50*50 - t20*20 - t10*10;
        ofstream lsrt("C:/BTL/lichsuruttien.txt");
        lsrt << now() << "Tai khoan " << n.id << " da rut:" << endl;
        if(t500 != 0){lsrt << "+ " << t500 << " to 500.000 VND" << endl;}
        if(t200 != 0){lsrt << "+ " << t200 << " to 200.000 VND" << endl;}
        if(t100 != 0){lsrt << "+ " << t100 << " to 100.000 VND" << endl;}
        if(t50 != 0){lsrt << "+ " << t50 << " to 50.000 VND" << endl;}
        if(t20 != 0){lsrt << "+ " << t20 << " to 20.000 VND" << endl;}
        if(t10 != 0){lsrt << "+ " << t10 << " to 10.000 VND" << endl;}
    }else{
        cout << "cay ATM khong the dua so tien nay cho ban" << endl;
    }
}
void guitien(ATM& atm, nick& n){
    tien a;
    cout << "Nhap so tien muon gui (VD: 1 to 10.000 VND -> Nhap 1 10)" << endl;
    cin >> a.soto >> a.menhgia;
    n.sotien = n.sotien + a.soto * a.menhgia;
    ofstream lsgt("C:/BTL/lichsuguitien.txt");
    lsgt << now() << "Tai khoan " << n.id << " da gui " << a.soto << " to " << a.menhgia << ".000 VND" << endl;
    if(a.menhgia == 10){atm.st10 = atm.st10 + a.soto;}
    if(a.menhgia == 20){atm.st20 = atm.st20 + a.soto;}
    if(a.menhgia == 50){atm.st50 = atm.st50 + a.soto;}
    if(a.menhgia == 100){atm.st100 = atm.st100 + a.soto;}
    if(a.menhgia == 200){atm.st200 = atm.st200 + a.soto;}
    if(a.menhgia == 500){atm.st500 = atm.st500 + a.soto;}
}
int login(nick& nick1, nick& nick2){
    string id, pass;
    int c = -1;
    do{
        c++;
        if(c > 5){
            cout << "The cua ban da bi khoa" << endl;
            return 0;
        }
        cout << "Nhap id va pass" << endl;
        cin >> id >> pass;
    }while((id != nick1.id || pass != nick1.pass)&&(id != nick2.id || pass != nick2.pass));
    if(id == nick1.id && pass == nick1.pass) return 1;
    if(id == nick2.id && pass == nick2.pass) return 2;
}
