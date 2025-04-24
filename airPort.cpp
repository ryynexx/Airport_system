#include <iostream>
using namespace std;
class Airport
{
    protected:
        string name;
        string location;
        int code;
    public:
        Airport(){}
        ~Airport(){}
        Airport(string n, string loc, int c)
        {
            name = n;
            location = loc;
            code = c;
        }
        void setname(string name)
        {
            this->name = name;
        }  
        void setname(string location)
        {
            this->location = location;
        }  
        void setname(int code)
        {
            this->code = code;
        }      
        string getname()
        {
            return name;
        }
        string getlocation()
        {
            return location;
        }
        int getcode()
        {
            return code;
        }
        void display()
        {
            cout<<"Airport: "<<name<<"\n";
            cout<<"Location: "<<location<<"\n";
            cout<<"Airport code: "<<code<<"\n";
        }
};

class Flight : public Airport
{

};
class Airline : public Flight
{

};
class Staff : public Airport
{

};
class Passenger : public Airport
{
    protected:
        string name;
        int id;
        int contact;
        string passportnumber;
        Ticket ticket;
    public:
        Passenger(){}
        ~Passenger(){}
        Passenger(string n, string loc, int c, string p_n, int id, int con, string p_no, )
};
class Ticket : public Passenger
{
    
};
class Baggage : public Passenger
{

};
