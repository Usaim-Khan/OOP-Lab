#include <iostream>
#include <string>
#include <vector>
#include "CarType.h"
using namespace std;

ostream& operator<<(ostream& c, const vector<CarType>& cars)
{
    c<<"_____________________________________________________"<<endl<<endl;
    c << "----------SALES RECEIPT----------" <<endl<<endl;

    for (int i=0;i<cars.size();i++) {
        c << "Car name: " << cars[i].getvehiclename() << endl << endl;
        c << "Car model: " << cars[i].getmodel() << endl << endl;
        c << "Car color: " << cars[i].getcolor() <<  endl << endl;
        c << "Owner name: "<<cars[i].C1.getcustomer_name()<<endl<<endl;
        c << "Owner number: "<<cars[i].C1.getcontact()<<endl<<endl;
        c << "Owner NIC: "<<cars[i].C1.getCNIC()<<endl<<endl;
        c << "Car price: "<<cars[i].getprice_sold()<<endl<<endl;
    }

    return c;
}

istream& operator>>(istream& c, vector<CarType>& cars)
{
       string vname, vcolor, vfuel,cname,con,cnic;
       int cmodel, cseat, vengine;
       long long int cprice,cprice_sold;

      cout << "Enter car name: ";
      getline(c >> ws, vname);

      cout << "Enter car model: ";
      c >> cmodel;

      cout << "Enter car color: ";
      getline(c >> ws, vcolor);

      cout << "Enter car number of seats: ";
      c >> cseat;
      
      cout << "Enter car engine size: ";
      c >> vengine;
      
      cout << "Enter car fuel type: ";
      getline(c >> ws, vfuel);
      

      cout << "Enter car price: ";
      c >> cprice;

      CarType add(cprice,cmodel,vengine,vcolor,vname,vfuel,cprice_sold,cname,con,cnic,cseat);
      cars.push_back(add);


    return c;
}

CarType::CarType()
{

}

CarType:: CarType(long long int price,int model,int engineSize,string color,string vehicle_name,string fuelType,long long int price_sold,string customer_name,string contact,string CNIC,int no_of_seats):VehicleType(price,model,engineSize,color, vehicle_name, fuelType, price_sold), C1( customer_name, contact, CNIC)
{
 this->no_of_seats=no_of_seats;
}

int CarType::getseats()const
{
 return no_of_seats;
}

void CarType:: setseats(int no_of_seats)
{
  this->no_of_seats = no_of_seats;
}

void CarType::add_details()
{
  int num;
    cout << "How many cars do you want to add: ";
    cin >> num;

    for (int i = 0; i < num; i++) 
    {  
        cin>>car;
        cout<<"_____________________________________________________"<<endl;
        cout<<"Car has been added to you showroom."<<endl;
        cout<<"_____________________________________________________"<<endl;
    }

}

void CarType:: printdata(int i)const
{
      cout<<"_____________________________________________________"<<endl;
      cout<<i+1<<"- Car name: "<<car[i].getvehiclename()<<endl;
      cout<<i+1<<"- Car model: "<<car[i].getmodel()<<endl;
      cout<<i+1<<"- Car color: "<<car[i].getcolor()<<endl;
      cout<<i+1<<"- No. of seats in a car: "<<car[i].getseats()<<endl;
      cout<<i+1<<"- Car engine size: "<<car[i].getengineSize()<<endl;
      cout<<i+1<<"- Car fuel type: "<<car[i].getfuelType()<<endl;
      cout<<i+1<<"- Car price: "<<car[i].getprice()<<endl;
      

}

void CarType::Sale_details()
{
 int num,count=0;
 string cname,choice,cnumber,cnic;
 long long int sold_price;

 string search_name;
 int search_price;

 cout<<"Enter car name to sale: ";
 getline(cin>>ws,search_name);

 for (int i=0;i<car.size();i++)
  {
    if (car[i].getvehiclename()==search_name )
     {
      count++;
      printdata(i);
     }
  }

  if (count==0)
   {
    cout<<"No car available regarding your search. "<<endl;
   }
   if(count!=0)
   {
  cout<<endl;
  cout<<"_____________________________________________________"<<endl;
  cout<<"Which car number do you want to remove: ";
  cin>>num;
  cout<<endl;

 cout<<"_____Owner Details_____"<<endl;

 cout<<"Enter owner name: ";
 getline(cin>>ws,cname);
 C1.setcustomer_name(cname);

 cout<<"Enter owner contact number: ";
 getline(cin>>ws,cnumber);
 C1.setcontact(cnumber);

 cout<<"Enter owner CNIC number: ";
 getline(cin>>ws,cnic);
 C1.setCNIC(cnic);

 cout<<"Enter price at which car has been sold: ";
 cin>>sold_price;
 setprice_sold(sold_price);

  car_sold.push_back(CarType(car[num-1].getprice(),car[num-1].getmodel(),car[num-1].getengineSize(),car[num-1].getcolor(),car[num-1].getvehiclename(),car[num-1].getfuelType(),getprice_sold(),cname,cnumber,cnic,car[num-1].getseats()));
  

  car.erase(car.begin() + num-1);

  cout<<"Do you want to print the sale recipts: ";
  getline(cin>>ws,choice);

  if (choice=="yes" || choice=="y")
  {
    cout<<car_sold;
  }

  else if (choice=="no" || choice=="n")
  {
    cout<<"Have a nice day..."<<endl;
  }
   }   
}

void CarType::Search()
{
 string search_name;
 int search_price;

 cout<<"Enter car name to search: ";
 getline(cin>>ws,search_name);

 for (int i=0;i<car.size();i++)
  {
    if (car[i].getvehiclename()==search_name)
     {
      cout<<"_____________________________________________________"<<endl;
      cout<<i+1<<"- Car name: "<<car[i].getvehiclename()<<endl;
      cout<<i+1<<"- Car model: "<<car[i].getmodel()<<endl;
      cout<<i+1<<"- Car color: "<<car[i].getcolor()<<endl;
      cout<<i+1<<"- No. of seats in a car: "<<car[i].getseats()<<endl;
      cout<<i+1<<"- Car engine size: "<<car[i].getengineSize()<<endl;
      cout<<i+1<<"- Car fuel type: "<<car[i].getfuelType()<<endl;
      cout<<i+1<<"- Car price: "<<car[i].getprice()<<endl;
      cout<<"_____________________________________________________"<<endl;
     }
    else if(car[i].getvehiclename()==search_name)
    {
      cout<<"No car available"<<endl;
      break;
    } 
  }
}

void CarType::Account()
{  string car_account;
   int count=0,num;
   

   cout<<"1- Check car account details."<<endl;
   cout<<"2- Total car sold."<<endl;
   cout<<"Enter an option: ";
   cin>>num;
   cout<<"_____________________________________________________"<<endl<<endl;
  if (num==1)
  {

    cout << "Enter a car name to check its account details: ";
    getline(cin >>ws, car_account);
    cout<<"_____________________________________________________"<<endl<<endl;

    for (int i=0;i<car_sold.size();i++) {
        if (car_sold[i].getvehiclename() == car_account) 
        {
            count++;

            cout << "Car Name: " << car_sold[i].getvehiclename() <<endl;
            cout<<"_____________________________________________________"<<endl;
            cout << "Price at which is sold: " << car_sold[i].getprice_sold()<<endl;
            cout<<"_____________________________________________________"<<endl;

            if(car_sold[i].getprice_sold()-car_sold[i].getprice()>0)
             {
            cout<<"Your profit in this car is of RS. "<<car_sold[i].getprice_sold()-car_sold[i].getprice()<<endl;
             }
            else if(car_sold[i].getprice_sold()-car_sold[i].getprice()<0)
            {
            cout<<"Your loss in this car is of RS. "<<car_sold[i].getprice_sold()-car_sold[i].getprice()<<endl;
            } 

            
        }
    }

    if (count==0) 
    {
        cout << "No account details found for this car"<<endl;
    }
  }

  else if (num==2)
   {
    int num1=0;
     for(int i=0;i<car_sold.size();i++)
     {
      num1=increment();
     }
     
     cout<<num1<<" cars have been sold."<<endl;
   } 
}
