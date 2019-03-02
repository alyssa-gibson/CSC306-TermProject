/* 
 * File:   OrderData.cpp
 * Author: Daniel Jirasek
 * 
 * Object is used to hold data from OrderData.txt
 * Created on January 29, 2019
 */

#include "OrderData.h"
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;
//default constructor
OrderData::OrderData() {
}

//constructor that takes parameters for all fields
OrderData::OrderData(string iD="", string dte="", string qt="", 
                     string paidAm="") 
{
    id = iD;
    date = dte;
    quantity = qt;
    paidAmount = paidAm;
}

//prints entire order
string OrderData::toString(){
    return id + ";" + date + ";" + quantity + ";" + paidAmount;
}

//gets Order ID
string OrderData::getId(){
    return id;
}

//gets date of order
string OrderData::getDate(){
    return date;
}

//gets the number of items purchased
string OrderData::getQuantity(){
    return quantity;
}

//gets the amount paid in the order
string OrderData::getPaidAmount(){
    return paidAmount;
}

//adds new unique id, converts it to a string, then sets it to id.
void OrderData::setNewID(int lastID){
    /*int numOrders = 1;
    ifstream readLines;
    readLines.open("orders.txt");
    char garbage[32];
    while(!readLines.eof())
    {
    while(id.length() < 6)
        readLines.getline(garbage, 256);
        numOrders++;
    }
    readLines.close();
    id = to_string(numOrders);*/
    id = to_string(lastID + 1);
    while(id.length() < 6)
    {
        id = "0" + id;
    }
    
}

//destructor for OrderData object
OrderData::~OrderData() {
}