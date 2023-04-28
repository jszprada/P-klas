#include<iostream>

using namespace std;

template <class T>
class Kontener{
    public:    
    int rozmiar_, licznik_;
    T tabla_[6];
    Kontener(){
    rozmiar_ = 6;
    licznik_ = 0;
        }
    void dodaj(T wartosc){
        if(licznik_ >= rozmiar_) return;
        tabla_[licznik_++] = wartosc;
        }
    void usun(int index){
        if(index < 0 or index >= licznik_) return;
        tabla_[index] = tabla_[--licznik_];
        }
};
class Zwierze{
    string nazwa_, id_;
    float waga_;
    int rurodzenia_;
    public:
    Zwierze(){}
    Zwierze(string nazwa, float waga, int rurodzenia, string id):nazwa_(nazwa), waga_(waga), rurodzenia_(rurodzenia), id_(id){
        }
    void wyswietl(){
        cout<<nazwa_<<" "<<waga_<<" "<<rurodzenia_<<" "<<id_<<" ";
        }
    int getRurodzenia(){ 
        return rurodzenia_;
        }
    int getWaga(){ 
        return waga_; 
        }
};

class Budynek{
    string nazwa_;
    float gpsX_, gpsY_, wysokosc_;
    public:
    Budynek(){}
    Budynek(string nazwa, float gpsX, float gpsY, float wysokosc):nazwa_(nazwa), gpsX_(gpsX), gpsY_(gpsY), wysokosc_(wysokosc){
        }
    void wyswietl(){
        cout<<nazwa_<<" "<<gpsX_<<" "<<gpsY_<<" "<<wysokosc_<<" ";
        }
    float sumaXY(){ 
        return gpsX_ + gpsY_; 
        }
};
bool spr(string wartosc){
    for(int i = 0; i < wartosc.size(); i++){
    if(wartosc[i]==' ') return true;
    }    
    return false;
}
bool sprx(float gpsX){
   if(gpsX >= -90.0 and gpsX <=90.0) return true;
   else
   return false;
}
bool spry(float gpsY){
    if(gpsY >= -180.0 and gpsY <= 180.0) return true;
    else
    return false;
}
bool spru(int rurodzenia ){
    return(rurodzenia > 0 and rurodzenia < 2021)? true : false;
}

int main()
{
Kontener<Zwierze> zwierzeKontener;
Kontener<Budynek> budynekKontener;
    
string nazwa, id;
float waga;
int rurodzenia;
for(int i = 0; i < 4; i++){
    do{
    cin>>nazwa;
    }while(spr(nazwa));
    do{
        cin>>waga;
    }while(waga<=0);
    do{
        cin>>rurodzenia;
    }while(!spru(rurodzenia));
    cin>>id;
    zwierzeKontener.dodaj(Zwierze(nazwa, waga, rurodzenia, id));
}
float gpsX, gpsY, wysokosc;
for(int i = 0; i < 4; i++){
    do{
        cin>>nazwa;
    }while(spr(nazwa));
    do{
        cin>>gpsX;
    }while(!sprx(gpsX));
    do{
        cin>>gpsY;
    }while(!spry(gpsY));
    do{
        cin>>wysokosc;
    }while(wysokosc<=0);
    
    budynekKontener.dodaj(Budynek(nazwa, gpsX, gpsY, wysokosc));
}
int index;
    cin>>index;
zwierzeKontener.usun(index);
    
for(int i = 0; i < zwierzeKontener.licznik_; i++){
    for(int k = i+1; k < zwierzeKontener.licznik_; k++){
        if(zwierzeKontener.tabla_[i].getRurodzenia() < zwierzeKontener.tabla_[k].getRurodzenia() or (zwierzeKontener.tabla_[i].getRurodzenia() == zwierzeKontener.tabla_[k].getRurodzenia() and zwierzeKontener.tabla_[i].getWaga() > zwierzeKontener.tabla_[k].getWaga()))
        {
                swap(zwierzeKontener.tabla_[i], zwierzeKontener.tabla_[k]);
        }
    }
}
    
for(int i = 0; i < budynekKontener.licznik_; i++){
    for(int k = i+1; k < budynekKontener.licznik_; k++){
        if(budynekKontener.tabla_[i].sumaXY() > budynekKontener.tabla_[k].sumaXY())
        {
                swap(budynekKontener.tabla_[i], budynekKontener.tabla_[k]);
        }
    }
}
    
for(int i = 0; i < zwierzeKontener.licznik_; i++){
    zwierzeKontener.tabla_[i].wyswietl();   
    }
for(int i = 0; i < budynekKontener.licznik_; i++){
    budynekKontener.tabla_[i].wyswietl();   
    }
    return 0;
}