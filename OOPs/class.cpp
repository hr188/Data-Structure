#include <iostream>
using namespace std;
class hero {
    
    public:
    int health;
    hero(){
        cout<<"constructor is called"<<endl;
    }
    hero(int health ){
        this -> health = health;
    }

    int gethealth(){
        return health;
    }
    int sethealth(int h){
       this -> health=h;
    }

};
int main(){
    hero hr;
    cout<<"adress of hr is : "<<&hr<<endl;
    cout<<"size is : " << sizeof(hr)<<endl;    
    hr.sethealth(25);
    cout<<hr.health<<endl;
    hero ah;
    ah.health = hr.health;
    cout<<ah.health;

}