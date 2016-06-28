#include <iostream>
#include <string>
#include <bits/stdc++.h>
#define WIDTH_OF_OOP_CHECK 60
/*add the header if you need*/
using namespace std;

//Abstract base class for Dessert Item hierarchy

int inout(float input){
    return (int)(input+0.5);
}

class DessertItem
{
private:
//Name of the DessertItem object
    string name;

public:
    DessertItem(){}
    DessertItem(string name):name(name){}
//Empty virtual destructor for DessertItem class
    virtual ~DessertItem(){}
//returns Name of DessertItem
    string getName(){ return name;}
    virtual string getDetails() = 0;
    virtual double getCost() = 0;
};

class IceCream : public DessertItem
{
public:
    IceCream(string name, double cost): DessertItem(name),cost(cost){}
    /* Write about IceCream Constructor
       IceCream(string name, double cost):DessertItem(name),cost(cost)
    */
    virtual string getDetails(){return "";}
    virtual double getCost(){return cost;}
    /* Write about IceCream other member functions*/
private:
    double cost;
};

class Topping : public IceCream
{
public:
    Topping(string iceCreamName, double iceCreamCost,
            string toppingName, double toppingCost):
        IceCream(toppingName+" Sundae with "+iceCreamName,iceCreamCost+toppingCost),
        toppingName(toppingName),toppingCost(toppingCost){}
    /* Write about Topping Constructor
       Topping(string iceCreamName, double iceCreamCost,
	string toppingName, double toppingCost)
    */
    string getToppingName(){return toppingName;}
    double getToppingCost(){return toppingCost;}
    virtual string getDetails(){return "";}
    /* Write about Topping other member functions*/
private:
    string toppingName;
    double toppingCost;
};

class Cookie : public DessertItem
{
public:
    Cookie(string name, int number, double pricePerDozen):
        DessertItem(name),number(number),pricePerDozen(pricePerDozen){}
    /* Write about Cookie Constructor
       Cookie(string name, int number, double pricePerDozen)
    */
    int getNumber(){return number;}
    double getPricePerDozen(){return pricePerDozen;}
    virtual string getDetails(){
        string output;
        ostringstream output_ss;
        output_ss<<"("<<number<<" "<<"dozen(s) * "<<pricePerDozen<<"/dozen)";
        output=output_ss.str()+"\n";
        return output;
    }
    virtual double getCost(){return number*pricePerDozen;}
    /* Write about Cookie other member functions*/

private:
//Number of dozens of Cookie
    int number;
    double pricePerDozen;
};

class Candy : public DessertItem
{
public:
    Candy(string name, double weight, double pricePerGram):
        DessertItem(name),weight(weight),pricePerGram(pricePerGram){}
    /* Write here about Candy Constructor
       Candy(string name, double weight, double pricePerGram)
    */
    virtual string getDetails(){
        string output;
        ostringstream output_ss;
        output_ss<<"("<<weight<<" "<<"gram(s) * "<<pricePerGram<<"/gram)";
        output=output_ss.str()+"\n";
        return output;
    }
    virtual double getCost(){return weight*pricePerGram;}
    double getWeight(){return weight;}
    double getPricePerGram(){return pricePerGram;}
    /* Write about Candy other member functions*/
private:
//Weight of Candy
    double weight;
    double pricePerGram;
};



class Checkout {
public:
    friend ostream &operator<<(std::ostream &, Checkout &);
    void enterItem(DessertItem * item){itemList.push_back(item);}
    void removeItem(DessertItem * item){itemList.remove(item);}
    int numberOfItems(){return itemList.size();}
    void clear(){itemList.clear();}

    /* Write about Checkout member functions
    1. "enterItem" function to add the element into the list
    2. "removeItem" function to remove the elemtent from the list
    3. calculate the total cost and tax in the list
    4. "numberOfItems" for number of Item in the list
    5. "clear" clear all Items from list
    */
private:
    list<DessertItem*> itemList;
};

ostream &operator<<(ostream &output, Checkout &checkout){
/*Overloaded operator that output a receipt for the current list of items*/
    int siz=checkout.numberOfItems();
    float sum=0;
    float tax=0;
    output<<"Welcome to OOP's shop\n";
    output<<"-----------------------------\n\n";
    output<<"Number of items: "<<checkout.itemList.size()<<"\n\n";
    list<DessertItem*>::iterator cnt=checkout.itemList.begin();
    for(;cnt!=checkout.itemList.end();++cnt){
        output<<setw(WIDTH_OF_OOP_CHECK-10)<<left<<(*cnt)->getName();
        output<<setw(10)<<right<<inout((*cnt)->getCost());
        output<<"\n"<<(*cnt)->getDetails();
        sum+=(*cnt)->getCost();
    }
    tax=(sum*0.05);
    output<<"\n"<<"-----------------------------\n";
    output<<setw(WIDTH_OF_OOP_CHECK-10)<<left<<"Cost"<<setw(10)<<right<<inout(sum)<<"\n";
    output<<setw(WIDTH_OF_OOP_CHECK-10)<<left<<"Tax"<<setw(10)<<right<<inout(tax)<<"\n";
    output<<"\n"<<setw(WIDTH_OF_OOP_CHECK-10)<<left<<"Total cost"<<setw(10)<<right;
    output<<inout(sum+tax)<<"\n";
    output.clear();
    return output;
}
