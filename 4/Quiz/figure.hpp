#include <string>
#include <iostream>
using namespace std;

namespace figure{

    //You can add member function in this class
    class BasePoint{
        public:
            BasePoint(int px, int py):x(px),y(py){}
            virtual ~BasePoint(){}
            virtual void info(){
                cout<<"figure: "<<type<<endl;
                cout<<"position x:"<<x<<" y:"<<y<<endl;
            }
        protected:
            int x,y;
            string getType(){
                return type;
            }
            void setType(string input){
                type=input;
                return;
            }
        private:
            string type;
    };
    //Fill your code here
    class Figure1P: public BasePoint{
    public:
        Figure1P(int px, int py, int p1):
            BasePoint(px,py), p1(p1){}
        void info(){
            cout<<"figure: "<<getType()<<endl;
            cout<<"position x:"<<x<<" y:"<<y<<endl;
            cout<<"property 1: p1="<<p1<<endl;
        }
    protected:
        int p1;
        void setP1(int p1){
            this->p1=p1;
            return;
        }
    };

    class Figure2P: public Figure1P{
    public:
        Figure2P(int px, int py, int p1, int p2):
            Figure1P(px,py,p1),p2(p2){}
        void info(){
            cout<<"figure: "<<getType()<<endl;
            cout<<"position x:"<<x<<" y:"<<y<<endl;
            cout<<"property 1: p1="<<p1<<endl;
            cout<<"property 2: p2="<<p2<<endl;
        }
    protected:
        int p2;
        void setP2(int p2){
            this->p2=p2;
            return;
        }
    };

    class Square: public Figure1P{
    public:
        Square(int px, int py, int p1):
            Figure1P(px,py,p1){
                setType("square");
            }
        void info(){
            cout<<"figure: "<<getType()<<endl;
            cout<<"position x:"<<x<<" y:"<<y<<endl;
            cout<<"property 1: p1="<<p1<<endl;
            cout<<"area: "<<area()<<endl;
        }
    protected:
        int area(){
            return p1*p1;
        }
    };

    class Rectangle: public Figure2P{
    public:
        Rectangle(int px, int py, int p1, int p2):
            Figure2P(px,py,p1,p2){
                setType("rectangle");
            }
        void info(){
            cout<<"figure: "<<getType()<<endl;
            cout<<"position x:"<<x<<" y:"<<y<<endl;
            cout<<"property 1: p1="<<p1<<endl;
            cout<<"property 2: p2="<<p2<<endl;
            cout<<"area: "<<area()<<endl;
        }
    protected:
        int area(){
            return p1*p2;
        }
    };
}
