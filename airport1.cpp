#include <iostream>
#include <vector>
using namespace std;

// Base class representing an Airport
class Airport
{
    protected:
        string name;
        string location;
        int code;
    public:
        Airport(){}
        ~Airport(){}
         // Parameterized constructor
        Airport(string n, string loc, int c)
        {
            name = n;
            location = loc;
            code = c;
        }

         // Setters
        void setname(string name)
        {
            this->name = name;
        }  
        void setLocation(string location)
        {
            this->location = location;
        }  
        void setCode(int code)
        {
            this->code = code;
        }
        
        
        // Getters
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

        // Copy constructor
        Airport(const Airport &other)
        {
            name = other.name;
            location = other.location;
            code = other.code;
            cout << "Airport copy constructor called.\n";
        }

         // Virtual function for polymorphism
        virtual void display()
        {
            cout<<"Airport: "<<name<<"\n";
            cout<<"Location: "<<location<<"\n";
            cout<<"Airport code: "<<code<<"\n";
        }
};

// Flight class inherits from Airport
class Flight : public Airport
{
   protected: 
    string flightNumber;
    string destination;
    string departureTime;
    string arrivalTime;
    int total_seats;
    int booked_seats;

  
  public:
     Flight() {};
     virtual ~Flight() {};

     // Constructor that also initializes Airport
     Flight(string flightno, string dest, string depttime, string arrtime, int t_seats, int b_seats, string airportName, string airportLocation, int airportCode)
: Airport(airportName, airportLocation, airportCode), flightNumber(flightno),destination(dest),departureTime(depttime),arrivalTime(arrtime),total_seats(t_seats),booked_seats(b_seats)
{}

	  
    // Input flight data
	 void input()
	  {
	  	cout<<"Enter Flight No. "<<endl;
        cin.ignore();
	  	getline(cin, flightNumber);
	  	
	  	cout<<"Enter destination:"<<endl;
          cin.ignore();
	  	getline(cin, destination);
	  	
	  	cout<<"Enter Departure time:"<<endl;
          cin.ignore();
	  	getline(cin, departureTime);
	  	
	  	cout<<"Enter arrival time:"<<endl;
          cin.ignore();
	  	getline(cin, arrivalTime);
	  }
    
      // Getters
      string getflightnum()
      {
        return flightNumber;
      } 

      string getdestination()
      {
        return destination;
      } 

      string getdeparture()
      {
        return departureTime;
      } 

      string getarrival()
      {
        return arrivalTime;
      }

      int gettotalseats()
      {
        return total_seats;
      } 

      int getbookedseats()
      {
        return booked_seats;
      } 

      // Check if seat is available
	  bool is_seatavailable()
	  {
	  	return booked_seats<total_seats;
	  }
	  // Change flight timings
	  void changeTime(string departtime , string arritime)
	  {
	  	departureTime = departtime;
	  	arrivalTime = arritime;
	  }

	  // Override display for polymorphism
	   void display()
	  {
        Airport::display();
	    cout<<"\nFlight Details\n\n";
	  	cout<<"Flight Number : "<<flightNumber<<endl;
	  	
	  	cout<<"Destination : "<<destination<<endl;
	  	
	  	cout<<"Departure Time : "<<departureTime<<endl;
	
	  	cout<<"Arrival Time : "<<arrivalTime<<endl;
	  	
	  	
          if (is_seatavailable())
          {
              cout << "Seat is Available." << endl;
          }
          else
          {
              cout << "No seats available" << endl;
          }
        }
    };

    // Airline class demonstrating aggregation of Flights
    class Airline
    {
        private:
            string airline_name;
            string airline_code;
            Flight* flights; // Array of flights (aggregation)
            int num_flights;

        public: 
            Airline(){};
            ~Airline()
            {
                delete[] flights;
            }
            // Constructor with flight array
            Airline(string name, string code, int n, Flight* flights_list )
            {
                airline_name = name;
                airline_code = code; 
                num_flights = n;
                flights = new Flight[n];
                for(int i= 0 ; i<n; i++)
                {
                    flights[i] = flights_list[i];
                }
            }
            
             // Add a new flight to airline
            void addflight(const Flight &newflight)
            {
                Flight* newflights;
                newflights = new Flight[num_flights+1];
                for(int i=0; i<num_flights; i++)
                {
                    newflights[i] = flights[i];
                }
                delete flights;
                flights = newflights;
                num_flights++;
                newflights[num_flights] = newflight;
                flights = newflights;

            }

            // Remove a flight from airline
            void removeflight( Flight &cancelflight)
            {
                for(int i= 0 ; i<num_flights; i++)
                {
                    if(flights[i].getflightnum() == cancelflight.getflightnum())
                    {
                        for(int j= i; j<num_flights-1; j++)
                        {
                            flights[j] = flights[j+1];
                        }
                    num_flights--;
                    break;
                    }
                else
                    cout<<"Flight not found";
                }
            }

             // Display airline details
            void display()
            {
                cout<<"Airline : "<<airline_name<<endl;
                cout<<"Airline Code : "<<airline_code<<endl;
                cout<<"Number of Flights : "<<num_flights<<endl;
                for(int i =0; i<num_flights;i++)
                {
                    flights->display();
                }
            }
    };

    // Staff class (inherits Airport)
    class Staff : public Airport
    {
        private:
            int emp_id;
            string emp_name;
            double salary;
            int emp_contact;
            string role;
            vector<string> tasks; 
        public:
            Staff(){};
            Staff(string air_name, string loc, int code, int id, string name, double sal, int cont,string r) : Airport(air_name,loc,code), emp_id(id), emp_name(name), salary(sal), emp_contact(cont), role(r) {};
            virtual ~Staff()
            {
                cout<<"Staff destroyed\n";
            }

            // Display assigned tasks
            void viewtasks()
            {
                for(int i=0; i<tasks.size(); i++)
                {
                    cout<<"Assigned tasks: \n";
                    cout<<tasks[i]<<endl;
                }
            }
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
        void remove_task();
        void assign_task(const string task);


    // Display staff info
        void display()
        {
            Airport :: display();

            cout<<"\nEmployee Details : \n\n";
            cout<<"Name : "<<emp_name<<endl;
            cout<<"ID : "<<emp_id<<endl;
            cout<<"Contact No. "<<emp_contact<<endl;
            cout<<"Salary : "<<salary<<endl;
            cout<<"Role : "<<role<<endl;
            viewtasks();
        }   
    };
void Staff::set_id(int id)
{
    emp_id = id;
}
void Staff::set_name(string name)
{
    emp_name = name;
}
void Staff::set_salary(double salary)
{
    this->salary = salary;
}
void Staff::set_contact(int contact)
{
    emp_contact=contact;
}
void Staff::set_role(string role)
{
     this->role=role;
}
int Staff::get_id() const
{
    return emp_id;
}
string Staff::get_name()const
{
    return emp_name;
}
double Staff::get_salary()const
{
    return salary;
}
int Staff::get_contact()const
{
    return emp_contact;
}
string Staff::get_role()const
{
    return role;
}
void Staff::assign_task(const string task)
{
   
    tasks.push_back(task); // add task to the list 
    cout << "Task assigned to " << get_name() << ": " << task << endl;
}
void Staff::remove_task()
{
    tasks.pop_back();
    cout << tasks.back() << "/Task Removed"<<endl;
}

// Forward declaration
class Baggage;

// Passenger class inherits Airport, has a list of Baggage (composition)
class Passenger : public Airport
{
protected:
    string name;
    int id;
    int contact;
    string passportnumber;
    vector<Baggage> baggageList;

public:
    Passenger() {}
    virtual ~Passenger() {}

    Passenger(string airname, string loc, int code,
              string pname, int pid, int cont, string pass_no)
        : Airport(airname, loc, code), name(pname), id(pid), contact(cont), passportnumber(pass_no) {}

    string get_name() { return name; }
    int get_id() { return id; }
    int get_contact() { return contact; }
    string get_passport() { return passportnumber; }

    // New: Register passenger
    void registerPassenger()
    {
        cout << "Registering Passenger...\n";
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Contact Number: ";
        cin >> contact;
        cout << "Enter Passport Number: ";
        cin >> passportnumber;
        cout << "Passenger registered successfully.\n";
    }

    // New: Check-in method
    void checkIn()
    {
        cout << "Checking in passenger: " << name << "\n";
        cout << "Passport: " << passportnumber << "\n";
        cout << "Contact: " << contact << "\n";
        cout << "Check-in completed successfully.\n";
    }
    friend class Baggage; // Declared as a friend

    void addBaggage(const Baggage &b)
    {
        baggageList.push_back(b);
        cout << "Baggage added for passenger: " << name << endl;
    }

    void showBaggage()
    {
        cout << "Baggage details for passenger: " << name << endl;
        for (size_t i = 0; i < baggageList.size(); ++i) 
        {
            baggageList[i].display();
            cout << "----------------------\n";
        }
        
    }

    virtual void display()
    {
        Airport::display();
        cout << "\nPassenger Details:\n";
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Contact: " << contact << endl;
        cout << "Passport Number: " << passportnumber << endl;
    }
};
// Baggage class used by Passenger (composition)
class Baggage
{
private:
    int baggageID;
    double weight;
    string type;
    string status;

public:
    Baggage() {}
    ~Baggage() {}

    Baggage(int id, double w, string t) : baggageID(id), weight(w), type(t) {}

    // Getters
    int getID() const { return baggageID; }
    double getWeight() const { return weight; }
    string getType() const { return type; }

    void display()
    {
        cout << "Baggage ID: " << baggageID << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Type: " << type << endl;
    }

    void tagBaggageToPassenger(Passenger &p)
    {
        cout << "Tagging baggage to passenger ID: " << p.id << ", Name: " << p.name << endl;
    }

    void checkSecurity()
    {
        cout << "Security check in progress for baggage ID: " << baggageID << "...\n";
        // Simulate security check (this could be made dynamic later)
        cout << "Baggage ID: " << baggageID << " passed security check.\n";
    }

    void trackBaggage()
    {
        cout << "Tracking baggage ID: " << baggageID << endl;
        cout << "Current status: " << status << endl;
    }

    void updateStatus(const string &new_status)
    {
        status = new_status;
        cout << "Status of baggage ID " << baggageID << " updated to: " << status << endl;
    }


};

// Ticket class inherits Passenger and includes Flight (composition)
class Ticket : public Passenger
{
    private:
        string ticket_number;
        string seat_number;
        Flight flight;
        double price;
        string ticket_class;
    public:
        Ticket(){};
        virtual ~Ticket(){cout<<"Ticket destroyed";};
        Ticket(string airname, string loc, int code, string p_name, int p_id, int p_cont, string pass_num, string t_num, string s_num, const Flight f, double p, string t_class)
         : Passenger(airname, loc, code, p_name, p_id, p_cont, pass_num),ticket_number(t_num), seat_number(s_num), flight(f), price(p), ticket_class(t_class) {}

         // Getters
        string get_ticket_num()
        {
            return ticket_number;
        }

        string get_seat_num()
        {
            return seat_number;
        }

        Flight get_flight()
        {
            return flight;
        }

        double get_price()
        {
            return price;
        }

        string get_ticket_class()
        {
            return ticket_class;
        }
         // Ticket operations
        void BookTicket()
        {
            if (flight.is_seatavailable())
            {
                cout << "Ticket " << ticket_number << " booked successfully for flight " << flight.getflightnum() << endl;
            }
            else
            {
                cout << "Cannot book ticket. No seats available for flight " << flight.getflightnum() << endl;
            }
        }

        void CancelTicket()
        {
            cout << "Ticket " << ticket_number << " has been cancelled for passenger " << name << "." << endl;
        }

        void display() 
        {
            Passenger::display();
            cout << "\nTicket Information:\n";
            cout << "Ticket Number: " << ticket_number << endl;
            cout << "Seat Number: " << seat_number << endl;
            cout << "Class: " << ticket_class << endl;
            cout << "Price: $" << price << endl;
            cout << "\nFlight Details:\n";
            flight.display();
        }
};

int main()
{
    // 1. Create base Airport object
    Airport a1("JFK International", "New York", 101);
    a1.display();
    cout << "--------------------------\n";

    // 2. Create Flights using Flight constructor
    Flight f1("AA101", "Los Angeles", "08:00 AM", "11:30 AM", 150, 100, "JFK International", "New York", 101);
    Flight f2("AA202", "Miami", "02:00 PM", "05:00 PM", 200, 180, "JFK International", "New York", 101);
    f1.display();
    cout << "--------------------------\n";

    // 3. Create Airline using composition
    Flight flightArray[2] = {f1, f2};
    Airline airline("American Airlines", "AA", 2, flightArray);
    airline.display();
    cout << "--------------------------\n";

    // 4. Add a new flight using aggregation
    Flight f3("AA303", "Chicago", "06:00 PM", "08:30 PM", 180, 175, "JFK International", "New York", 101);
    airline.addflight(f3);

    // 5. Remove flight by value (aggregation)
    airline.removeflight(f2);
    airline.display();
    cout << "--------------------------\n";

    // 6. Create Staff object, assign and remove task
    Staff staff("JFK International", "New York", 101, 501, "Emily Smith", 50000.0, 1234567890, "Security");
    staff.assign_task("Inspect carry-on luggage");
    staff.assign_task("Guide passengers to gate");
    staff.remove_task();
    staff.display();
    cout << "--------------------------\n";

    // 7. Create Passenger and check-in
    Passenger p1("JFK International", "New York", 101, "John Doe", 301, 987654321, "P998877");
    p1.checkIn();
    p1.display();
    cout << "--------------------------\n";

    // 8. Add Baggage (composition), update status, show baggage
    Baggage b1(1, 25.0, "Checked-in");
    b1.tagBaggageToPassenger(p1);
    b1.checkSecurity();
    b1.updateStatus("Loaded");
    p1.addBaggage(b1);
    p1.showBaggage();
    cout << "--------------------------\n";

    // 9. Create Ticket (uses composition of Passenger + Flight)
    Ticket t1("JFK International", "New York", 101, "John Doe", 301, 987654321, "P998877",
              "TK123", "12A", f1, 350.0, "Economy");

    // Book and cancel ticket
    t1.BookTicket();
    t1.display();
    t1.CancelTicket();
    cout << "--------------------------\n";

    // 10. Demonstrate Polymorphism using Airport pointer
    Airport* ptr;

    ptr = &a1;
    ptr->display();  // base display

    ptr = &f1;
    ptr->display();  // overridden in Flight

    ptr = &staff;
    ptr->display();  // overridden in Staff

    ptr = &p1;
    ptr->display();  // overridden in Passenger

    ptr = &t1;
    ptr->display();  // overridden in Ticket

    cout << "--------------------------\n";

    return 0;
}
