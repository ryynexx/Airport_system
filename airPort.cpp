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
   private: 
  string flightNumber;
  string destination;
  string departureTime;
  string arrivalTime;
  string airline;
  bool available_seat;
  
  public:
  	flight(string flightno, string dest, string depttime, string arrtime, string air, bool avail)
  {
  	flightNumber=flightno;
  	destination=dest;
  	departureTime=depttime;
  	arrivalTime=arrtime;
  	airline=air;
  	available_seat=avail;
	  }	
	  
	 void input()
	  {
	  	cout<<"enter flight no:"<<endl;
	  	cin>>flightNumber;
	  	
	  	cout<<"enter destination:"<<endl;
	  	cin>>destination;
	  	
	  	cout<<"enter depart time:"<<endl;
	  	cin>>departureTime;
	  	
	  	cout<<"enter arrival time:"<<endl;
	  	cin>>arrivalTime;
	  	
	  	cout<<"enter airline:"<<endl;
	  	cin>>airline;
	  	
	  }
	  
	  bool seat()
	  {
	  	return available_seat;
	  }
	  
	  void changeTime(string departtime , string arritime)
	  {
	  	departureTime=departtime;
	  	arrivalTime=arritime;
	  }
	  
	  void display()
	  {
	  
	  	cout<<flightNumber;
	  	
	  	cout<<destination;
	  	
	  	cout<<departureTime;
	
	  	cout<<arrivalTime;
	  	
	  	cout<<airline;
	  	
	  cout <<"seat available:";
	  if(seat())
	  {
     cout<<	"yes seat is available";
	  }
	  else
	  {
	  	cout<<"no it's not'";
	  }
};


class Airline : public Flight

    
{
	private:
		
		string name;
		string code;
	flight* flights[10];
	
	public:
		
		airline(string n, string c, string f)
		{
			name=n;
			code=c;
			flight=f;
		}
		
		void input()
		{
			int n;
		flight* flights[10];
			
			cout<<"enter number of flights:";
			cin>>n;
			
			for(int i=0;i<n;i++)
			{
				cout<<"flight name:";
				cin>>flights[i].name;
				
				cout<<"flight code:";
				cin>>flights[i].code;
			}
		}
		
		void display()
		{
				for(int i=0;i<n;i++)
			{
				cout<<flights[i].name;
				
				cout<<flights[i].code;
			}
		}
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
    cout << "Booking Ticket:" << endl;
    cout << "Enter ticket number: ";
    cin >> ticket_number;

    cout << "Enter seat number: ";
    cin >> seat_number;

    cout << "Enter price: ";
    cin >> price;

    string flightNumber;
    cout << "Enter flight number: ";
    cin >> flightNumber;
    flight.setFlightNumber(flightNumber);

    cout << "Ticket booked successfully!" << endl;

}
void ticket::cancelticket()
{
    cout << "Cancelling ticket: " << ticket_number << endl;
    ticket_number = " ";
    seat_number = " ";
    price = 0;
    flight.setFlightNumber(" ");
    cout << "Ticket cancelled." << endl;
}
void ticket::display()
{
    cout << " Ticket Information:" << endl;
    cout << "Ticket Number: " << ticket_number << endl;
    cout << "Seat Number: " << seat_number << endl;
    cout << "Price: $" << price << endl;
    cout << "Flight Details:" << endl;
    flight.display();
}

};
class Baggage : public Passenger
{

};
