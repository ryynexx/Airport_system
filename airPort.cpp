#include<iostream>

using namespace std;

class staff
{
    protected:
    int id;
    string name;
    double salary;
    int contact;
    string role;
    public:
    staff(); //default constructor.
    staff(int id,string name,double salary,int contact,string role);  //parameterized constructor 
    virtual ~staff();  //destructor.
    
    //setters
    void set_id(int id);
    void set_name(string name);
    void set_salary(double salary);
    void set_contact(int contact);
    void set_role(string role);
    //getters
    int get_id() const;
    string get_name() const;
    double get_salary() const;
    int  get_contact() const;
    string get_role()  const;
    //functions
    virtual void add_emp();
     //virtual void remove_emp();
    //virtual void update_emp();
    virtual void delete_data();
    virtual void assign_task(string task);
    virtual void print_data()const;   


};

//functions defined outside the class
staff::staff()
{
    id = 0;
    name = "";
    salary = 0.0;
    contact=0;
    role="";
}
staff::staff(int id, string name, double salary, int contact,string role)
{
    set_id(id);
    set_name(name);
    set_salary(salary);
    set_contact(contact);
    set_role(role);
}
staff::~staff()
{
    cout << "staff destroyed!" << endl;
}

void staff::set_id(int id)
{
    this->id = id;
}
void staff::set_name(string name)
{
    this->name = name;
}
void staff::set_salary(double salary)
{
    this->salary = salary;
}
void staff::set_contact(int contact)
{
     this->contact=contact;
}
void staff::set_role(string role)
{
     this->role=role;
}
int staff::get_id() const
{
    return id;
}
string staff::get_name()const
{
    return name;
}
double  staff::get_salary()const
{
    return salary;
}
int  staff::get_contact()const
{
    return contact;
}
string staff::get_role()const
{
    return role;
}
void staff::add_emp()
{

}
void staff::assign_task(string task)
{
     
}
void staff::delete_data()
{

}



//now i make the class of the ticket
class ticket
{
    private:
    string ticket_number;
    string seat_number;
    Flight flight;
    double price;
    public:
    
    ticket();
    ticket(string ticket_number,string seat_number,double price,Flight flight);
    virtual ~ticket();

  
    //setters
    void setticket_number(string ticket_number);
    void setseat_number(string seat_number);
    void setprice(double price);
    void setFlight(Flight flight);
    
    //getters
    string getticket_number();
    string getseat_number();
    double getprice();
    Flight  getFlight();

    virtual void bookticket();
    virtual void cancelticket();
    virtual void display();



};
ticket::ticket()
{
    ticket_number=" ";
    seat_number=" ";
    price=0;
    flight=flight;

}
ticket::ticket(string ticket_number,string seat_number,double price,Flight flight)
{
    setticket_number(ticket_number);
    setseat_number(seat_number);
    setprice(price);
    setFlight(flight);
}
ticket::~ticket()
{
    cout<<"this is the destructor of the class ticket"<<endl;
}
 void ticket::setticket_number(string ticket_number)
 {
    this->ticket_number=ticket_number;
 }
void ticket::setseat_number(string setseat_number)
{
     this->seat_number=seat_number;
}
void ticket::setprice(double price)
{
     this->price=price;
}
void ticket::setFlight(Flight flight)
{
     this->flight=fligth;
}
string ticket::getticket_number()
{
    return ticket_number;
}
string ticket::getseat_number()
{
     return seat_number;
}
double ticket::getprice()
{
     return price;
}
Flight ticket::getFlight()
{
     return flight;
}
void ticket::bookticket()
{

}
void ticket::cancelticket()
{

}
void ticket::display()
{
    
}

