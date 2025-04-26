#include<iostream>
using namespace std;

class flight
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

class airline:public flight
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
int main() 
{
    airline PIA("PIA Airlines", "PIA");
    
    flight f1("PIA123", "New York", "10:00", "12:30", "PIA", true);
    flight f2("PIA456", "Los Angeles", "14:00", "17:15", "PIA", false);
    

    PIA.display();
    
    f1.changeTime("11:00", "13:45");
    cout << "After changing time:"<<endl;
    f1.display();
    
}
