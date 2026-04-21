#include <iostream>
#include <string>
#include <vector>
#include "BikeType.h"
using namespace std;

ostream& operator<<(std::ostream& c, const vector<BikeType>& bikes)
{
    c<<"_____________________________________________________"<<endl<<endl;
    c << "----------SALES RECEIPT----------" << endl<<endl;

    for (int i=0;i<bikes.size();i++) 
    {
        c << "Bike name: " << bikes[i].getvehiclename() <<endl <<endl;
        c << "Bike model: " << bikes[i].getmodel() <<endl <<endl;
        c << "Bike color: " << bikes[i].getcolor() <<endl << endl << endl;
        c << "Owner name: "<<bikes[i].C2.getcustomer_name()<<endl<<endl;
        c << "Owner number: "<<bikes[i].C2.getcontact()<<endl<<endl;
        c << "Owner NIC: "<<bikes[i].C2.getCNIC()<<endl<<endl;
        c << "Bike price: "<<bikes[i].getprice_sold()<<endl<<endl;
    }
    return c;
}

istream& operator>>(istream& c, vector<BikeType>& bikes)
 {
      string vname, vcolor, vfuel,cname,con,cnic;
       int cmodel, vengine;
       long long int cprice,cprice_sold;

      cout << "Enter bike name: ";
      getline(c >> ws, vname);

      cout << "Enter bike model: ";
      c >> cmodel;

      cout << "Enter bike color: ";
      getline(c >> ws, vcolor);
      
      cout << "Enter bike engine size: ";
      c >> vengine;
      
      cout << "Enter bike fuel type: ";
      getline(c >> ws, vfuel);
      
      cout << "Enter bike price: ";
      c >> cprice;

      BikeType add(cprice,cmodel,vengine,vcolor,vname,vfuel,cprice_sold,cname,con,cnic);
      bikes.push_back(add);

      return c;
 }

BikeType::BikeType()
{

}

BikeType:: BikeType(long long int price,int model,int engineSize,string color,string vehicle_name,string fuelType,long long int price_sold,string customer_name,string contact,string CNIC):VehicleType(price,model,engineSize,color, vehicle_name, fuelType, price_sold), C2( customer_name, contact, CNIC)
{
 
}

void BikeType::add_details()
{
  int num;
    cout << "How many bikes do you want to add: ";
    cin >> num;

    for (int i = 0; i < num; i++) 
    {
      cin>>bike;
      cout<<"_____________________________________________________"<<endl;
      cout<<"Bikes has been added to you showroom."<<endl;
      cout<<"_____________________________________________________"<<endl;
    }

}

void BikeType:: printdata(int i)const
{
     
      cout<<"_____________________________________________________"<<endl;
      cout<<i+1<<"- Bike name: "<<bike[i].getvehiclename()<<endl;
      cout<<i+1<<"- Bike model: "<<bike[i].getmodel()<<endl;
      cout<<i+1<<"- Bike color: "<<bike[i].getcolor()<<endl;
      cout<<i+1<<"- Bike engine size: "<<bike[i].getengineSize()<<endl;
      cout<<i+1<<"- Bike fuel type: "<<bike[i].getfuelType()<<endl;
      cout<<i+1<<"- Bike price: "<<bike[i].getprice()<<endl;
      

}

void BikeType::Sale_details()
{
 int num,count=0;
 string cname,choice,cnumber,cnic;
 long long int sold_price;

 string search_name;
 int search_price;

 cout<<"Enter bike name to sale: ";
 getline(cin>>ws,search_name);

 for (int i=0;i<bike.size();i++)
  {
    if (bike[i].getvehiclename()==search_name )
     {
      count++;
      printdata(i);
     }
  }

  if (count==0)
   {
    cout<<"No bike available regarding your search. "<<endl;
   }
  if(count!=0)
   { 

  cout<<endl;
  cout<<"_____________________________________________________"<<endl;

  cout<<"Which bike number do you want to remove: ";
  cin>>num;

 cout<<"_____Owner Details_____"<<endl;

 cout<<"Enter owner name: ";
 getline(cin>>ws,cname);
 C2.setcustomer_name(cname);

 cout<<"Enter owner contact number: ";
 getline(cin>>ws,cnumber);
 C2.setcontact(cnumber);

 cout<<"Enter owner CNIC number: ";
 getline(cin>>ws,cnic);
 C2.setCNIC(cnic);

 cout<<"Enter price at which bike has been sold: ";
 cin>>sold_price;
 setprice_sold(sold_price);

  bike_sold.push_back(BikeType(bike[num-1].getprice(),bike[num-1].getmodel(),bike[num-1].getengineSize(),bike[num-1].getcolor(),bike[num-1].getvehiclename(),bike[num-1].getfuelType(),getprice_sold(),cname,cnumber,cnic));

  bike.erase(bike.begin() + num-1);

  cout<<"Do you want to print the sale recipts: ";
  getline(cin>>ws,choice);

  if (choice=="yes" || choice=="y")
  {
    cout<<bike_sold;
  }

  else if (choice=="no" || choice=="n")
  {
    cout<<"Have a nice day..."<<endl;
  }
   } 
    
}

void BikeType::Search()
{
 string search_name;
 int search_price;

 cout<<"Enter Bike name to search: ";
 getline(cin>>ws,search_name);

 for (int i=0;i<bike.size();i++)
  {
    if (bike[i].getvehiclename()==search_name)
     {
      cout<<"_____________________________________________________"<<endl;
      cout<<i+1<<"- Bike name: "<<bike[i].getvehiclename()<<endl;
      cout<<i+1<<"- Bike model: "<<bike[i].getmodel()<<endl;
      cout<<i+1<<"- Bike color: "<<bike[i].getcolor()<<endl;
      cout<<i+1<<"- Bike engine size: "<<bike[i].getengineSize()<<endl;
      cout<<i+1<<"- Bike fuel type: "<<bike[i].getfuelType()<<endl;
      cout<<i+1<<"- Bike price: "<<bike[i].getprice()<<endl;
      cout<<"_____________________________________________________"<<endl;
     }
    else if(bike[i].getvehiclename()==search_name)
    {
      cout<<"No bike available"<<endl;
      break;
    } 
  }
}

void BikeType::Account()
{  string bike_account;
   int count=0,num;
   

   cout<<"1- Check bike account details."<<endl;
   cout<<"2- Total bike sold."<<endl;
   cout<<"Enter an option: ";
   cin>>num;
   cout<<"_____________________________________________________"<<endl<<endl;

  if (num==1)
  {

   cout << "Enter a bike name to check its account details: ";
    getline(cin >>ws, bike_account);
   cout<<"_____________________________________________________"<<endl<<endl;

    for (int i=0;i<bike_sold.size();i++) {
        if (bike_sold[i].getvehiclename() == bike_account) 
        {
            count++;

            cout << "Bike Name: " << bike_sold[i].getvehiclename() <<endl;
            cout<<"_____________________________________________________"<<endl;
            cout << "Price at which is sold: " << bike_sold[i].getprice_sold()<<endl;
            cout<<"_____________________________________________________"<<endl;

            if(bike_sold[i].getprice_sold()-bike_sold[i].getprice()>0)
             {
                cout<<"Your profit in this bike is of RS. "<<bike_sold[i].getprice_sold()-bike_sold[i].getprice()<<endl;
             }
            else if(bike_sold[i].getprice_sold()-bike_sold[i].getprice()<0)
            {
                 cout<<"Your loss in this bike is of RS. "<<bike_sold[i].getprice_sold()-bike_sold[i].getprice()<<endl;
            } 

            
        }
    }

    if (count==0) 
    {
        cout << "No account details found for this bike."<<endl;
    }
  }

  else if (num==2)
   {
    int num1=0;
     for(int i=0;i<bike_sold.size();i++)
     {
      num1=increment();
     }

     cout<<num1<<" bikes have been sold."<<endl;
     cout<<"_____________________________________________________"<<endl<<endl;
   } 
}
