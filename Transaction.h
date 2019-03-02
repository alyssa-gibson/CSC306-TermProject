/* 
 * File:   Transaction.h
 * Author: Daniel Jirasek
 * Header File for Transaction class
 * Created on February 8, 2019, 1:51 PM
 */

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>

class Transaction {
public:
    Transaction();
    Transaction(std::string, std::string, std::string);
    std::string getCustomerId();
    std::string getSalesPersonID();
    std::string getOrderId();
    std::string toString();
    virtual ~Transaction();
private:
    //customerId holds the unique ID number of the customer
    //salesPersonID holds the unique ID number of the salesperson
    //orderId holds the unique order ID number for the order
    std::string customerId, salesPersonID, orderId;    
};

#endif /* TRANSACTION_H */
