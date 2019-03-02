/* 
 * File:   FileHandler.cpp
 * Author: Daniel Jirasek, Alyssa Gibson
 * 
 * Class for handling and retrieving data from Transactions.txt, orders.txt,
 * rainbowList.txt, customers.txt, and salesStaff.txt
 * Created on January 29, 2019
 */


#include "FileHandler.h"
#include "Transaction.h"
#include "OrderData.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include <bits/stl_vector.h>
#include <iostream>
#include <algorithm>
using namespace std;

//constructor for FileHandler
FileHandler::FileHandler() {
    orderVector.reserve(20);
    transactionVector.reserve(20);
    customerVector.reserve(125);
    rainbowVector.reserve(20);
}


//adds order entry to the vector of OrderData objects by first creating the 
//object in the method with what is needed for its constructor and then adding 
//it to the orderVector that contains OrderData objects
void FileHandler::addOrderEntry(OrderData o) 
{
    orderVector.push_back(o);
}

void FileHandler::readOrdersFile(){
    ifstream iFile("orders.txt");
    char orderID[32], orderDate[32], quantity[32], paidAmount[32];
    string orderIdStr, oDateStr, qtyStr, paidAmStr;
    while(!iFile.eof()){
        iFile.getline(orderID, 32, ';');
        orderIdStr = orderID;
        iFile.getline(orderDate, 32, ';');
        oDateStr = orderDate;
        iFile.getline(quantity, 32, ';');
        qtyStr = quantity;
        iFile.getline(paidAmount, 32);
        paidAmStr = paidAmount;
        OrderData temp = OrderData(orderIdStr, oDateStr, qtyStr, paidAmStr);
        orderVector.push_back(temp);
    }
    iFile.close();
}

//returns all orders made by specific Customer, as a vector of OrderData objects
vector<OrderData> FileHandler::getOrders(Customer c)
{
    vector<OrderData> orders;
    for(int i = 0; i < transactionVector.size(); i ++)
    {
        if(transactionVector[i].getCustomerId().compare(c.getID()) == 0)
        {
            orders.push_back(orderVector[i]);
        }
    }
    return orders;
}

//adds transaction entry to vector of transaction objects by 1st creating the 
//object in the method with what is needed for its constructor and then adding 
//it to the transactionVector that contains transaction objects
void FileHandler::addTransactionEntry(Transaction t) 
{
    transactionVector.push_back(t);
    return;
}

//reads from transactions.txt and stores each entry as transaction objects
//in the transactionsVector
void FileHandler::readTransactionsFile(){
    ifstream iFile("transactions.txt");
    char customerID[32], salesPersonId[32], orderID[32];
    string cIDStr, sIDStr, oIDStr;
    while(!iFile.eof()){
        iFile.getline(customerID, 32, ';');
        cIDStr = customerID;
        iFile.getline(salesPersonId, 32, ';');
        sIDStr = salesPersonId;
        iFile.getline(orderID, 32);
        oIDStr = orderID;
        Transaction t = Transaction(cIDStr, sIDStr, oIDStr);
        addTransactionEntry(t);
    }
    iFile.close();
}

//add new customer to customerVector
void FileHandler::addCustomerEntry(Customer c) {
    customerVector.push_back(c);
    return;
}

//Reads all data from customers.txt and stores it all in customerVector
void FileHandler::readCustomerFile() {
    ifstream infile;
    infile.open("customers.txt");
    // ---Ryan---
    char id[32], first[32], last[32], 
         address[32], city[32], state[32], zipcode[32];
    while (!infile.eof())
    {   
        infile.getline(id, 32, ';');
        infile.getline(first, 32, ';');
        infile.getline(last, 32, ';');
        infile.getline(address, 32, ';');
        infile.getline(city, 32, ';');
        infile.getline(state, 32, ';');
        infile.getline(zipcode, 32);
        Customer temp = Customer(id, first, last, 
                                 address, city, state, zipcode);
        addCustomerEntry(temp);
    }
    // ---------
    infile.close();
    return;
}

//add new entry to rainbowVector
void FileHandler::addRainbowEntry(string id) {
    rainbowVector.push_back(id);
    return;
}

//removes entry from rainbowVector
bool FileHandler::removeRainbowEntry(string id) {
    for (int i = 0; i < rainbowVector.size(); i++) {
        if (rainbowVector[i].compare(id) == 0) {
            rainbowVector.erase(rainbowVector.begin()+i);
            return true;
        }
    }
    return false;
}

//reads data in from rainbowList.txt and stores it in rainbowVector
void FileHandler::readRainbowFile() {
    fstream rfile;
    rfile.open("rainbowList.txt");
    char id[32];
    while (!rfile.eof()) {
        rfile.getline(id, 32);
        rainbowVector.push_back(id);
    }
    rfile.close();
    return;
}

/**
 * adds new pointer to class object that IS an employee to employeePointers
 * vector.
*/
void FileHandler::addEmployeePointerEntry(Employee *e){
    Employee *ePt = e;
    employeePointers.push_back(ePt);
    return;
}

//reads data in from salesStaff.txt and stores all pointers to 
//derived classes that inherit from base class Employee
void FileHandler::readSalesStaffFile(){
    int count = 0;
    char eTitle[32], ename[32], eSalesID[32], eBossId[32];
    string empTitle, empName, empID, empBossID;
    ifstream rFile;
    rFile.open("salesStaff.txt");
    while (!rFile.eof()) {
        rFile.getline(eTitle, 32, ';');
        empTitle = eTitle;
        //If there is no title, do not make a new pointer for the entry
        if(empTitle.empty()){

        }
        else 
        {

            rFile.getline(ename, 32, ';');
            empName = ename;
            rFile.getline(eSalesID, 32, ';');
            empID = eSalesID;
            rFile.getline(eBossId, 32, ';');
            empBossID = eBossId;
            if(!rFile.eof())
            {
                rFile.ignore(1,'\n');
            }
            //create pointer to new Employee object
            Employee *empPtr = nullptr;

            //uses unique 6th character in eTitle(eTitle[5]) to determine which
            //derived class the pointer will point to
            switch(eTitle[5]) {
                //SuperSales case
                case 'S':
                    empPtr = new SuperSales(empTitle, empName, empID, empBossID);
                    addEmployeePointerEntry(empPtr);
                    break;
                //Supervisor case    
                case 'v':
                    empPtr = new Supervisor(empTitle, empName, empID, empBossID);
                    addEmployeePointerEntry(empPtr);
                    break;        
                //Manager case    
                case 'e':
                    empPtr = new Manager(empTitle, empName, empID, empBossID);
                    addEmployeePointerEntry(empPtr);
                    break;
                //Sales case    
                default:
                    empPtr = new Sales(empTitle, empName, empID, empBossID);
                    addEmployeePointerEntry(empPtr);
                    break;
            }
            count++;
            empPtr = nullptr;
        }
    }
    rFile.close();
}

void FileHandler::setEmployeeGrossSales(){
    for(Employee * employee : employeePointers){
        double sales = 0;
        for(Transaction t : transactionVector)
        {
            if(t.getSalesPersonID().compare(employee->getSalesID()) == 0)
            {
                for(OrderData order : orderVector)
                {
                    if(t.getOrderId().compare(order.getId()) == 0)
                    {
                        sales += stod(order.getPaidAmount());
                    }
                }
            }
        }
        employee->setSales(sales);
    }
}

void FileHandler::setEmployeeComission(){
    for(Employee * employee1 : employeePointers)
    {
        double reportedSales = 0;
        for(Employee * employee2 : employeePointers)
        {
            if(employee1->getSalesID().compare(employee2->getBossID()) == 0)
            {
                for(Employee * employee3 : employeePointers)
                {
                    if(employee2->getSalesID().compare(employee3->getBossID()) == 0)
                    {
                        reportedSales += employee3->getSales();
                    }
                }
                reportedSales += employee2->getSales();
            }
        }

        employee1->setCommission((employee1->getSales() *0.065) + (reportedSales * 0.03));
    }
}

//reads all files and stores the data in the
//appropriate vectors
void FileHandler::readFiles(){
    readSalesStaffFile();
    readOrdersFile();
    readTransactionsFile();
    readCustomerFile();
    readRainbowFile();
    return;
}


//saves all of the entries of all of FileHandler's vectors into the txt files 
void FileHandler::saveFiles() {
    ofstream cfile, ofile, tfile, rfile;
    cfile.open("customers.txt");
    
    for (int i = 0; i < customerVector.size()-1; i++) {
        cfile << customerVector[i].getWriteData() << endl;
    }
    cfile << customerVector.back().getWriteData();
    cfile.close();
    
    ofile.open("orders.txt");
    for (int i = 0; i < orderVector.size()-1; i++) {
        ofile << orderVector[i].toString() << endl;
    }
    ofile << orderVector.back().toString();
    ofile.close();
    tfile.open("transactions.txt");
    for (int i = 0; i < transactionVector.size()-1; i++) {
        tfile << transactionVector[i].toString() << endl;
    }
    tfile << transactionVector.back().toString();
    tfile.close();
    
    rfile.open("rainbowList.txt");
    for (int i = 0; i < rainbowVector.size()-1; i++) {
        rfile << rainbowVector[i] << endl;
    }
    rfile << rainbowVector.back();
    rfile.close();
    return;
}

//Retrieves the vector of OrderData objects, orderVector
vector<OrderData> FileHandler::getOrderVector() {
    return orderVector;
}

//Retrieves the vector of Transaction objects, transactionVector
vector<Transaction> FileHandler::getTransactionVector() {
    return transactionVector;
}

//Retrieves the vector of Customer objects, customerVector
vector<Customer> FileHandler::getCustomerVector() {
    return customerVector;
}

//Retrieves the vector of strings, rainbowVector
vector<string> FileHandler::getRainbowCustVector() {
    return rainbowVector;
}
//Returns vector containing pointers to objects that are or inherit from Sales class
vector<Employee *>FileHandler::getEmployeePointers(){return employeePointers;}

//Method for sorting employeePointers vector
//Does not currently work
void FileHandler::sortEmployees(){
    std::sort(employeePointers.begin(), employeePointers.end());
}

//destructor for FileHandler, also deletes every pointer to prevent
//memory leaks and dangling pointers
FileHandler::~FileHandler() {
    for(Employee *empPt : employeePointers){
        delete empPt;
        empPt = nullptr;
    }
    
}