// Nicholson-COSC1436-Program3.cpp 
// this program is meant to calculate the order summary of spools 
//

#include <iostream>
#include <iomanip>
using namespace std;

float numSpools;	// NUMBER OF SPOOLS ORDERING
int stockSpools = 50;	// NUMBER OF SPOOLS IN STOCK
char y;  // DETERMINES IF YOU WILL HAVE SPECIAL SHIPPING COST
float findShipping(int, int, int = 15); // FUNCTION USED TO FIND THE SHIPPING PRICE
									// 15 IS FOR THE SHIPPING COST WITHOUT SPECIAL CHARGES
int specialShipping = 20; // FUNCTION USED TO FIND THE SPECIAL CHARGES
						// SPECIAL SHIPPING CHARGE IS 20
const int SPOOLPRICE = 150;// AMOUNT PER SPOOL WITHOUT SHIPPING COST OR SPECIAL CHARGES 
double getSubtotal(int, int, int);// THIS WILL ALLOW THE PROGRAM TO CALCULATE
								// THE SUBTOTAL OF WHAT IT WOULD COST FOR THE SPOOL BEFORE SHIPPING


int main()// IN THIS MAIN FUNCTION WE WILL DISPLAY THE ORDER, SUBTOTAL,SHIPPING COST 
{		// AND AND IF NEEDED SPECIAL CHARGES // IT WILL DISPLAY AMOUNT ON BACK ORDER AS WELL

float special;// FLOAT VARIABLE USED TO DISPLAY SPECIAL PRICE
char choice; // ALLOWS FOR THE CUSTOMER TO CHOOSE YES OR NO
int miscSpools; // DISPLAYS BACKORDER SPOOLS 

cout << "How many spools were ordered? ";
cin >> numSpools;	
cout << "How many spools are in stock? "; 
cin >> stockSpools;
cout << "Are special shipping charges required? (y or n):"; 
cin >> choice; 
	if (choice == 'y' || choice == 'Y') 
	{									
		cout << "Enter an amount needed for special shipping charges: " << specialShipping << endl;
		special = findShipping(numSpools, stockSpools, specialShipping);
		// CALLS TO FUNCTION findShipping TO CALCULATE SHIPPING CHARGES FOR SPECIAL SHIPPING
	}
	else 
	{	
		special = findShipping(numSpools, stockSpools); // CALLS TO FUNCTION findShipping TO DISPLAY
	}													//  PRICE WITHOUT SPECIAL CHARGES
cout << endl;

miscSpools = numSpools - stockSpools; // CALCULATES THE AMOUNT OF SPOOLS IN BACK ORDER IF 
											// AMOUNT ORDERED EXCEEDS AMOUNT IN STOCK
cout << "ORDER SUMMARY" << endl;
cout << "==============" << endl;// DISPLAYS ORDER SUMMARY
cout << setw(2) << endl;
cout << "Items ordered: " << numSpools << endl; 
cout << "Ready to Ship: "; 
	if (numSpools <= stockSpools)
	{
		cout << numSpools << endl;		//IF/ELSE STATEMENT IS USED TO HELP THE 
	}								// PROGRAM DETERMINE IF IT NEEDS TO DISPLAY THE AMOUNT ON BACKORDER
	else
		cout << stockSpools << endl;

	if (stockSpools <= numSpools)	
	{
		cout << "On backorder: "<< setw(3) << miscSpools << endl;
		// DISPLAYS BACK ORDER NUMBER IF IT NEEDS TO
		cout << endl;
	}
cout << endl;
cout << setw(2) << fixed << showpoint << setprecision(2);
cout << "Subtotal: " << setw(5) << fixed << showpoint << '$' << setw(8) << getSubtotal(numSpools, stockSpools, SPOOLPRICE) << endl;
cout << "Shipping: " << setw(5) << fixed << showpoint << '$' << setw(8) << special << endl;
cout << "Total Due: " << setw(4) << fixed << showpoint << '$' << setw(8) << (special + getSubtotal(numSpools, stockSpools, SPOOLPRICE)) << endl;

	return 0;
}
//***************************************************
 // THIS FUNCTION WILL FIND AND RETURN THE SHIPPING 
 // AND HANDLING COST FOR SPOOLS CUSTOMER ORDERED 
//***************************************************
float findShipping(int spools, int stock, int cost)
{

	if (spools > stock)
	{

		return (cost * stock); 
	}
	else
	{
		return (spools * cost); //returns cost of spools 
	}
}
//********************************************************
// THIS FUNCTION WILL CALCULATE THE SUBTOTAL SHIPPING COST
// THIS FUNCTION GETS CALLED BY THE MAIN FUNCTION 
// *******************************************************
double getSubtotal(int spools, int stock, int cost)
{
	if (spools > stock)
		// RETURNS THE SUBTOTAL 
	{

		return double(stock * cost);    
	}
	else
	{
		return double(spools * cost);
	}

}
