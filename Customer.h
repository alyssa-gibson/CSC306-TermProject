/* 
 * File:   Customer.h
 * Author: Alyssa Gibson
 * -An adaptation of Ryan's customer class
 *  make it a header and class file instead.
 *
 * Created on January 29, 2019, 1:31 PM
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

class Customer {
    
    private: 
        
        std::string ID, first, last, address, city, state, zipcode;

    public:
        
        // Constructor:
        Customer(std::string, std::string, std::string, std::string,
                std::string, std::string, std::string);
        // This constructor builds a customer object
        // with up to six strings** passed in with
        // the following order:
	// 1) Customer ID
	//    (i.e. 123456)
        // 2) First Name
        //    (i.e. 'Alyssa')
        // 3) Last Name
        //    (i.e. 'Gibson')
        // 4) Street Address
        //    (i.e. '40 N. Brainard Street')
        // 5) City
        //    (i.e. 'Naperville')
        // 6) State
        //    (i.e. 'IL' or 'Illinois')
        // 7) ZIP
        //    (i.e. '60540')
        // **If less than 6 string params are passed in,
        // the default for each is a null string ("").
        
        // ---Get methods:---
        // -Basic get methods for retrieving the
        //  six private variables of the customer
        //  class.
	std::string getID();
        std::string getFirst();
        std::string getLast();
        std::string getAddress();
        std::string getCity();
        std::string getState();
        std::string getZipcode();
        // -Extra get methods that may come in 
        //  handy later for formatting. If not,
        //  they can be removed at any time.
        std::string getFullName_FirstLast();
        // Returns full name First Last,
        // i.e. 'Alyssa Gibson'.
        std::string getFullName_LastFirst();
        // Returns full name Last First,
        // i.e. 'Gibson, Alyssa'.
        // ---
        std::string getFullAddress();
        // Returns a full formatted address.
        // i.e. '40 N. Brainard St. 
        // Naperville, Illinois 60540'.
        // (no newline characters)
        std::string getWriteData();
        // ---Set methods:---
        // -Includes a set method for every
        //  private variable of the customer class.
	void setID(std::string);
        void setFirst(std::string);
        void setLast(std::string);
        void setAddress(std::string);
        void setCity(std::string);
        void setState(std::string);
        void setZipcode(std::string);
        // ---
        
};

#endif /* CUSTOMER_H */