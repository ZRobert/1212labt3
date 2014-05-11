/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Filename: labtest3.cpp
//Author: Robert Payne
//Date: 04/26/2012
//Lab Section: L15
//Purpose:  This program reads monthly sales data in from a file
//          for five products. It stores it to a 2 dimensional
//          array and then outputs the data along with the
//          maximum product sold over the year.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int monthlyProductSales[5][12];     //stores the data from the file [product][month]
    int product;                        //for loop iterator
    int month;                          //for loop iterator
    int maxProduct =0;                  //saves the subscript for the max product; initializes it to the first element
    int maxMonth =0;                    //saves the subscript for the max month; initializes it to the first element
    int totalFirstProduct = 0;          //sum of all the first product sold over the year
    int totalFirstMonth = 0;            //sum of all of the first month's product sales
    ifstream salesData;                 //output file data type for the file

    salesData.open("C:\\sales.txt");        //opens the file

    //loop for reading the data from the file into the array
    for(product = 0; product < 5; product++)
    {
        for(month = 0; month < 12; month++)
        {
            salesData >> monthlyProductSales[product][month];

            //sets maxProduct and maxMonth to the current element if it is greater
            if(monthlyProductSales[product][month] > monthlyProductSales[maxProduct][maxMonth])
            {
                maxProduct = product;
                maxMonth = month;
            }
        }
    }

    //finds the total sales for the first month
    for(product = 0; product < 5; product++)
        totalFirstMonth += monthlyProductSales[product][0];

    //finds the total sales for the first product
    for(month = 0; month < 12; month++)
        totalFirstProduct+= monthlyProductSales[0][month];

    //header for the output
    cout<<"________________________________________________\n";
    cout<<"Month\t|Item 1\t|Item 2\t|Item 3\t|Item 4\t|Item 5\t|\n";
    cout<<"________________________________________________\n";

    //outputs the data from the array to the screen
    for(month = 0; month < 12; month++)
    {
        cout<<month+1<<"\t|";
        for(product = 0; product < 5; product++)
        {
            cout<<monthlyProductSales[product][month]<<"\t|";
        }
        cout<<endl;
    }

    //outputs the answers for questions 3-5
    cout<<"________________________________________________\n";
    cout<<"\nThe total sales of product 1 was: " <<totalFirstProduct;
    cout<<"\nThe total sales for the first month was: "<<totalFirstMonth;
    cout<<"\nThe most sales for a product was: " <<monthlyProductSales[maxProduct][maxMonth];
    cout<<"\nOf product #"<<maxProduct +1;
    cout<<" sold during: ";

    //outputs the month in text rather than a number
    switch(maxMonth)
    {
        case 0:
            cout<<"January";
            break;
        case 1:
            cout<<"February";
            break;
        case 2:
            cout<<"March";
            break;
        case 3:
            cout<<"April";
            break;
        case 4:
            cout<<"May";
            break;
        case 5:
            cout<<"June";
            break;
        case 6:
            cout<<"July";
            break;
        case 7:
            cout<<"August";
            break;
        case 8:
            cout<<"September";
            break;
        case 9:
            cout<<"October";
            break;
        case 10:
            cout<<"November";
            break;
        case 11:
            cout<<"December";
            break;
    }

    cout<<endl;

    salesData.close();      //closes the file

    return 0;
}
