/* 
 * File:   FileHandler.h
 * Author: Daniel Jirasek
 * Header file for FileHandler class
 * Created on February 24, 2019, 4:19 AM
 */
#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <vector>
#include <string>
#include "Transaction.h"
#include "OrderData.h"
#include "Customer.h"
#include "Employee.h"
#include "Manager.h"
#include "Sales.h"
#include "SuperSales.h"
#include "Supervisor.h"
class FileHandler {
private:
    //holds all past customers found in customers.txt
    std::vector<Customer> customerVector;
    //holds all the data for every order made in orders.txt
    std::vector<OrderData> orderVector;
    //holds all transactions from transactions.txt
    std::vector<Transaction> transactionVector;
    //holds all entries found in rainbowList.txt
    std::vector<std::string> rainbowVector;
    //holds all base class pointers to objects that are derived from Employee
    std::vector<Sales *> employeePointers;
public:
    FileHandler();
    void addOrderEntry(OrderData);
    void addTransactionEntry(Transaction);
    void addCustomerEntry(Customer);
    void addRainbowEntry(std::string);
    //Adds new pointer to Employee
    void addEmployeePointerEntry(Sales *);
    bool removeRainbowEntry(std::string);
    OrderData getOrderEntry(int);
    Transaction getTransactionEntry(std::string);
    std::vector<OrderData> getOrderVector();
    std::vector<Transaction> getTransactionVector();
    std::vector<Customer> getCustomerVector();
    std::vector<std::string> getRainbowCustVector();
    std::vector<Sales *> getEmployeePointers();
    std::vector<OrderData> getOrders(Customer);
    void readTransactionsFile();
    void readOrdersFile();
    void readRainbowFile();
    void readCustomerFile();
    void readFiles();//reads all files including salesStaff.txt
    void saveFiles();
    void readSalesStaffFile();//reads data from salesStaff.txt and stores it
                              //in employeePointers
    void sortEmployees(); //meant to sort employees(currently not working)
    virtual ~FileHandler();

};

#endif /* FILEHANDLER_H */
