/* 
 * File:   Customer.cpp
 * Author: Ryan Ziolkowski
 *         (modified by Alyssa Gibson)
 *
 * Created on February 16, 2019, 9:19 AM
 */

#include "Customer.h"

using namespace std;
    
Customer::Customer(string i = "", string f = "", string l = "", string a = "", 
                   string c = "", string s = "", string z = "")
{
    ID = i;
    first = f;
    last = l;
    address = a;
    city = c;
    state = s;
    zipcode = z;
}
    
string Customer::getID() {return ID;}    
string Customer::getFirst() {return first;}
string Customer::getLast() {return last;}
string Customer::getAddress() {return address;}
string Customer::getCity() {return city;}
string Customer::getState() {return state;}
string Customer::getZipcode() {return zipcode;}
string Customer::getFullName_FirstLast() {return (first + " " + last);}
string Customer::getFullName_LastFirst() {return (last + ", " + first);}
string Customer::getFullAddress() {
    return (address + " " + city + 
            ", " + state + " " + zipcode);
}
string Customer::getWriteData() {return (ID + ";" + first + ";" + last +
        ";" + city + ";" + address + ";" + state + ";" + zipcode); }
 
void Customer::setID(string i) {ID = i; return;}
void Customer::setFirst(string f) {first = f; return;}
void Customer::setLast(string l) {last = l; return;}
void Customer::setAddress(string a) {address = a; return;}
void Customer::setCity(string c) {city = c; return;}
void Customer::setState(string s) {state = s; return;}
void Customer::setZipcode(string z) {zipcode = z; return;}