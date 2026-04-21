#include "TruckType.h "
#include "BikeType.h"
#include "CarType.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()

{
   int option; 
   string login;
   string id="786";
    TruckType t1; 
    CarType c1;
    BikeType b1;

  cout<<"_____________________________________________________"<<endl<<endl;
  cout<<"           Vehicle Sales Management System           "<<endl<<endl;
  cout<<"_____________________________________________________"<<endl<<endl;
do
{

   cout<<"Enter your login ID: ";
   getline(cin>>ws,login);
   if(login!=id)
   cout<<"Invalid login ID. "<<endl;

}while(login!=id);

  if (login==id)
   {
    cout<<"You have been logged in successfully."<<endl<<endl;;
    
    while(option != 5)
  {
    cout<<"_____________________________________________________"<<endl<<endl;
    cout<<"_______Menu_______"<<endl<<endl;
    cout<<"1- Add vehicle details."<<endl;
    cout<<"2- Sale vehicle."<<endl;
    cout<<"3- Search vehicle details."<<endl;
    cout<<"4- Account details."<<endl;
    cout<<"5- Exit."<<endl;
    cout<<"Choose an option: ";
    cin>>option;
    cout<<"_____________________________________________________"<<endl<<endl;

    if (option==1)
     {
      int choose;

      cout<<"1- Add car details. "<<endl;
      cout<<"2- Add bike details. "<<endl;
      cout<<"3- Add truck details. "<<endl;
      cout<<"Choose an option: ";
      cin>>choose;
      cout<<"_____________________________________________________"<<endl<<endl;

      if (choose==1)
       {
         c1.add_details();
       }
      else if (choose==2)
       {
        b1.add_details();
       }
      else if (choose==3)
       {
        t1.add_details();
       } 
     }

    else if (option==2)
     {
      int choose;

      cout<<"1- Sale car. "<<endl;
      cout<<"2- Sale bike. "<<endl;
      cout<<"3- Sale truck. "<<endl;
      cout<<"Choose an option: ";
      cin>>choose;
      cout<<"_____________________________________________________"<<endl<<endl;

      if (choose==1)
       {
        c1.Sale_details();
       }
      else if (choose==2)
       {
        b1.Sale_details();
       }
      else if (choose==3)
       {
        t1.Sale_details();
       } 
     } 

    else if (option==3)
     {
       int choose;

      cout<<"1- Search car details. "<<endl;
      cout<<"2- Search bike details. "<<endl;
      cout<<"3- Search truck details. "<<endl;
      cout<<"Choose an option: ";
      cin>>choose;
      cout<<"_____________________________________________________"<<endl<<endl;

      if (choose==1)
       {
        c1.Search();
       }
      else if (choose==2)
       {
        b1.Search();
       }
      else if (choose==3)
       {
        t1.Search();
       }
     } 

    else if (option==4)
     {
      
       int choose;

      cout<<"1- Car account details. "<<endl;
      cout<<"2- Bike account details. "<<endl;
      cout<<"3- Truck account details. "<<endl;
      cout<<"Choose an option: ";
      cin>>choose;
      cout<<"_____________________________________________________"<<endl<<endl;

      if (choose==1)
       {
        c1.Account();  
       }
      else if (choose==2)
       {
        b1.Account();
       }
      else if (choose==3)
       {
        t1.Account();
       }
     } 

    else if (option==5)
     {
      cout << "******  **   **  ******\n";
      cout << "**  **   ** **   **   \n";
      cout << "******    ***    ******\n";
      cout << "**  **    ***    **   \n";
      cout << "******    ***    ******\n";
      cout<<"_____________________________________________________"<<endl;
     } 

  }

   }


}