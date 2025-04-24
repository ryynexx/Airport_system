#include <iostream>
#include<vector>
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
    protected:
    int id;
    string name;
    double salary;
    int contact;
    string role;
    vector<string> tasks; 
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
    int id;
    int   contact;
    double salary;
    string name; 
    string role;

    cout << "Enter Employee ID: ";
    cin >> id;
    set_id(id);

    cout << "Enter Name: ";
    cin.ignore();  
    getline(cin, name);
    set_name(name);

    cout << "Enter Salary: ";
    cin >> salary;
    set_salary(salary);

    cout << "Enter Contact Number: ";
    cin >> contact;
    set_contact(contact);

    cout << "Enter Role: ";
    cin.ignore();
    getline(cin, role);
    set_role(role);

    cout << "The data of the employee added successfully ."<<endl;
}
void staff::assign_task(string task)
{
   
    tasks.push_back(task); // add task to the list 
    cout << "Task assigned to " << get_name() << ": " << task << endl;
}


void staff::delete_data()
{
    set_id(0);
    set_name("");
    set_salary(0);
    set_contact(0);
    set_role("");
    cout << "The data of the  stuff is deleted."<<endl;
}

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
