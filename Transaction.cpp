/* 
 * File:   Transaction.cpp
 * Author: Daniel Jirasek
 * Class for Transactions that holds customer's unique ID, salesperson ID
 * and the unique order ID number.
 * Created on February 8, 2019, 1:51 PM
 */

#include "Transaction.h"

//Default constructor
Transaction::Transaction(){}

Transaction::Transaction(std::string cID="", std::string sID="", 
std::string oID="")
{
    customerId = cID;
    salesPersonID = sID;
    orderId = oID;
}
//returns the customerId in transaction as a string
std::string Transaction::getCustomerId(){return customerId;}

//returns the salesPersonID in transaction as a string
std::string Transaction::getSalesPersonID(){return salesPersonID;}

//returns the orderId in transaction as a string
std::string Transaction::getOrderId(){return orderId;}

//returns entire Transaction with semicolons
std::string Transaction::toString(){
    return customerId+";"+salesPersonID+";"+orderId;}

Transaction::~Transaction() {
}

