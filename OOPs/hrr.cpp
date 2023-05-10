#include <iostream>
using namespace std;
class human{
    protected:
    int height;
    public:
    int age;
    int weight;


    public:
    int getAge(){
        return this->age;
    }
    void  setWeight(int w){
        this-> weight =w;
    }
    void setHeight(int h){
        this->height= h;
    }


};
class male : protected human{

    public:
    string color;

    void sleep(){
        cout<<"Male is sleeping "<<endl;
    }
    int getHeight(){
      return   this ->height;
    }
    
};
int main(){
    male hr;
    
    cout<<hr.getHeight()<<endl;





    // hr.setWeight(25);
    // cout<< hr.weight<<endl;
    // hr.sleep();
}