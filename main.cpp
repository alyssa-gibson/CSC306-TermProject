/* 
 * File:   main.cpp
 * Authors: Alyssa Gibson 
 *          Daniel Jirasek 
 *          Ryan Ziolkowski
 *
 * Created on January 24, 2019, 11:19 PM
 * Last Modified on February 16, 2019, 9:18 AM
 */

// Changes to menus:
// - add() is no longer a void method. It also has a single string parameter.
//   It instead returns a customer object and the main menu adds it 
//   to the customers vector. The main menu call to add simply includes
//   a null string as the ID.
//   These changes were made so that this method could be used in the
//   transaction() method for when a cashier inputs an ID that currently
//   does not exist.
// - Changed the menu options "Search by last name" and "Search by ID"
//   to one option on the main menu, then created a submenu.
// - Changed the order a bit to make more sense.

// BIG CHANGES:
// - The re-introduction of the FileHandler class. We have moved everything 
//   regarding reading and writing files to there. This makes main() a lot
//   less cluttered.
//   Originally, our vectors were global variables of main, then read in
//   from the FileHandler class. HOWEVER, if you do it this way, then unless
//   you add/remove from both copies of the vector EVERY TIME, there will
//   be discrepencies in the data in our vectors and written to the files.
//   To combat this, I changed it to a global FileHandler object to access
//   all the vectors from.

// To-Do:
// - ID Generation for orders is completely broken. Hard coding the start
//   at 14 is not a good idea, and it doesn't have the leading 0s.
// - Writing to files is similarly extremely broken.

#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "Customer.h"
#include "OrderData.h"
#include "Transaction.h"
#include "FileHandler.h"

using namespace std;

void menu();
Customer add(string);
void searchByLastName(string);
Customer searchByID(string);
void transaction();
void rainbowtribble();
void salesReport();

FileHandler fileHandler;

string currentdate; // Prompts for in main menu.
// Could take computer date, but... 
// It's not currently 1988.
// Used for writing order records.

int main(int argc, char** argv) {

    fileHandler = FileHandler();
    fileHandler.readFiles();
    fileHandler.setEmployeeGrossSales();
    fileHandler.setEmployeeComission();

    int userin = 0;
    cout << "Please input current date in the following format:"
            "\nDD-Mon-YY\n" << endl;
    cin >> currentdate;
    cin.ignore(1); // <- Adding that juuuust in case.

    while (userin != 6) {
        cout << "\n\t-Tribble Business Customer Database-\n"
                "\t\t    Main Menu:\n"
                "Please enter the number corresponding"
                " to the option you would like.\n"
                "\t1) Add a customer to the database.\n"
                "\t2) Search database for existing customer.\n"
                "\t3) Customer Sale\n"
                "\t4) Rainbow Tribble Pre-Order\n"
                "\t5) Generate sales report\n"
                "\t6) Exit program and save any changes." << endl;

        cin >> userin;

        switch (userin) {
            case 1:
            {
                // Add a customer.
                Customer temp = add("");
                fileHandler.addCustomerEntry(temp);
                break;
            }
            case 2:
            {
                // Look up a customer by last name.
                int input = 0;
                string q = "";
                cout << "Search by: \n\t1) Last Name\n\t2) Customer ID" << endl;
                cin >> input;
                switch (input) {
                    case 1:
                    {
                        cout << "Please input last name to search by:" << endl;
                        cin >> q;
                        searchByLastName(q);
                        break;
                    }
                    case 2:
                    {
                        cout << "Please input ID to search by:" << endl;
                        cin >> q;
                        Customer temp = searchByID(q);
                        if (temp.getID().compare("") == 0) {
                            cout << "Could not find any customers with that ID." << endl;
                        } else {
                            string info = ("Customer ID: " + temp.getID()
                                    + "\nName: " + temp.getFullName_FirstLast()
                                    + "\nAddress: " + temp.getFullAddress());
                            cout << info << endl;
                            vector<OrderData> tempOrders = fileHandler.getOrders(temp);
                            if (!tempOrders.empty()) {
                                cout << "Customer Orders:" << endl
                                        << "order ID;date;quantity;amount paid" << endl;
                                for (OrderData o : tempOrders) {
                                    cout << o.toString() << endl;
                                }
                            }
                        }
                        break;
                    }
                    default:
                    {
                        cout << "Invalid input, please try again." << endl;
                        break;
                    }
                }
                break;
            }
            case 3:
            {
                // Customer Sale
                transaction();
                break;
            }
            case 4:
            {
                // Rainbow Tribble
                rainbowtribble();
                break;
            }
            case 5:
            {
                //Sales Report
                salesReport();
                break;
            }
            case 6:
            {
                // Exit.
                fileHandler.saveFiles();
                break;
            }
            default:
            {
                // If the user does not put in a valid
                // menu entry, default is chosen.
                cout << "Invalid input, please try again." << endl;
                break;
            }
        };
    }

    // If the program has reached here, that means
    // that the user wants to end the program, so
    // it is safe to close the files for good,
    // saving their changes, and exiting the program.

    return 0;

}

Customer add(string ID) {
    // Function to add a new customer to the
    // existing customers vector.
    char first[32], last[32], address[32],
            city[32], state[32], zipcode[32];

    cin.ignore(1); // Ignores the new line character 
    // left in the buffer.

    // Prompts the user for customer values
    // and stores them in separate cstrings.
    cout << "Input First Name:" << endl;
    ;
    cin.getline(first, 32);

    cout << "Input Last Name:" << endl;
    cin.getline(last, 32);

    cout << "Input Street:" << endl;
    cin.getline(address, 32);

    cout << "Input City:" << endl;
    cin.getline(city, 32);

    cout << "Input State:" << endl;
    cin.getline(state, 32);

    cout << "Input ZIP Code:" << endl;
    cin.getline(zipcode, 32);

    // If the ID variable is null, that means that
    // we need to assign one to this new customer.
    // Assign variable like this:
    // 1) Check if ID variable param is null.
    // 2) If no, do nothing. If yes, randomly generate an ID number.
    // 3) Check if this is in use with searchByID(string).
    // 4) If in use, generate a new one.
    // It would be a good idea to use some sort of while loop for this.

    if (ID.compare("") == 0) {
        srand(time(NULL));
        do {
            ID = to_string(rand() % 1000000);
            while (ID.length() < 6) {
                ID = "0" + ID;
            }
        } while (searchByID(ID).getID().compare(ID) == 0);
    }
    Customer temp = Customer(ID, first, last, address,
            city, state, zipcode);

    // Perhaps printing out the customer ID would be a nice touch
    // because (most of the time) it is randomly generated. 
    // However, it's not required.

    // Tells the user the customer has been added,
    // then returns to main to actually add it to the database...
    cout << "Customer added to database. Returning to main menu. . ." << endl;
    return temp;

}

void searchByLastName(string query) {

    vector<Customer> customers = fileHandler.getCustomerVector();
    vector<Customer> found;

    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].getLast() == query) {
            found.push_back(customers[i]);
        }
    }
    if (found.size() > 0) {
        cout << "Found the following customers with the last name " << query
                << ":\n";
        int counter = 1;
        for (int i = 0; i < found.size(); i++) {
            cout << counter << ") " << found[i].getFullName_LastFirst() << endl;
            counter++;
        }

        int userin; // User input to select which found
        // customer's address the user wants
        // to view.
        // If 0 is inputed, it will skip over
        // the if and else clause and return
        // to main.
        cout << "Which do you want to view more information for?:\n"
                "Alternatively, input 0 to exit back to the main menu.\n";

        cin >> userin;

        if (userin != 0 && userin <= found.size()) {

            string info = ("Customer ID: " + found[userin - 1].getID()
                    + "\nName: " + found[userin - 1].getFullName_FirstLast()
                    + "\nAddress: " + found[userin - 1].getFullAddress());
            cout << info << endl;
            vector<OrderData> tempOrders = fileHandler.getOrders(found[userin - 1]);
            if (!tempOrders.empty()) {
                cout << "Customer Orders:" << endl
                        << "order ID;date;quantity;amount paid" << endl;
                for (OrderData o : tempOrders) {
                    cout << o.toString() << endl;
                }
            }
        }

    } else {
        cout << "Could not find any customers with that last name. Returning to the main menu . . ." << endl;
    }

    return;

}

Customer searchByID(string query) {
    // This method is used by the transaction method
    // to search a customer by ID, instead of last name.
    // Because this could be a useful method to have in the future,
    // I made it separate from the transaction() method.

    // Because an ID is unique to each customer and there are no
    // duplicates, this method is much less complicated than
    // searching by last name.
    vector<Customer> customers = fileHandler.getCustomerVector();

    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].getID() == query) {
            return customers[i];
        }
    }
    // If the program reaches here, then no match is found.
    // In this case, return a null customer.
    // Originally I had it call the add(string) method here,
    // but I noticed that there is a possible infinite loop
    // that could occur, so I put this... sort of kludgey 
    // fix in place.
    Customer notfound = Customer("", "", "", "", "", "", "");
    return notfound;

}

void transaction() {
    // 1) Prompt user for an ID
    string ID;
    int amt; // Amount of tribbles purchased (used later)
    string paidAmt;
    cout << "Please input Customer ID:" << endl;
    cin >> ID;
    // 2) Calls the searchbyID(string) method to search
    //    whether that ID exists in the database or not.
    //    if not, it prompts the user to create a new 
    //    customer object through the add(string) method.
    Customer temp = searchByID(ID);
    if (temp.getID() == "") {
        // If there is no ID for this temporary customer,
        // we know that the method returned null/no match
        // for the ID.
        // That means that the ID was not found.
        cout << "No customer matching that ID was found. Returning to the main menu . . ." << endl;

    }// 3) Prompts user to put in how many tribbles purchased,
        //    and returns the price of said tribbles. Also prevents
        //    the user from inputting invalid data 
        //    (i.e. less than 0, greater than 5)
    else {
        cout << "How many tribbles?" << endl;
        cin >> amt;
        switch (amt) {
            case 1:
                cout << temp.getFullName_FirstLast() << " - 1 Tribble - $9.50." << endl;
                paidAmt = "9.50";
                break;

            case 2:
                cout << temp.getFullName_FirstLast() << " - 2 Tribbles - $16.15." << endl;
                paidAmt = "16.50";
                break;

            case 3:
                cout << temp.getFullName_FirstLast() << " - 3 Tribbles - $25.88." << endl;
                paidAmt = "25.88";
                break;

            case 4:
                cout << temp.getFullName_FirstLast() << " - 4 Tribbles - $28.15." << endl;
                paidAmt = "28.15";
                break;

            case 5:
                cout << temp.getFullName_FirstLast() << " - 5 Tribbles - $30.00" << endl;
                paidAmt = "30.00";
                break;

            default:
                cout << "Invalid input. Returning to the main menu . . ." << endl;
                break;

        }

        // 4) Adds appropriate data to Transaction and OrderData objects.
        OrderData orderTemp = OrderData("", currentdate, to_string(amt), paidAmt);
        //sets new ID for order
        orderTemp.setNewID(fileHandler.getOrderVector().size());
        Transaction trTemp = Transaction(ID, "000000", orderTemp.getId());
        // Object vectors needed here.
        //add the objects to the appropriate object vectors
        fileHandler.addOrderEntry(orderTemp);
        fileHandler.addTransactionEntry(trTemp);

    }

    // 5) Returns to main.
    return;

}

void rainbowtribble() {
    // This method deals with adding users to the Rainbow Tribble
    // preorder list. Instead of with the exit method that saves
    // new customers and appends the customers.txt file,
    // this method just appends the customer ID string
    // because creating a new customer object for this purpose is
    // unneeded.

    int userin = 0;
    cout << "Rainbow Tribble Menu:"
            "\n\t1) Add a new customer to the pre-order list."
            "\n\t2) Remove a customer from the pre-order list." << endl;
    cin >> userin;
    switch (userin) {
        case 1:
        {
            string ID;
            cout << "Please input Customer ID:" << endl;
            cin >> ID;
            Customer temp = searchByID(ID);
            if (temp.getID().compare("") == 0) {
                cout << "Customer not found. Returning to the main menu . . .";
                break;
            }
            fileHandler.addRainbowEntry(ID);
            cout << temp.getFullName_FirstLast() << " added. Returning to the main menu . . ." << endl;
            break;
        }
        case 2:
        {
            string ID;
            cout << "Please input Customer ID:" << endl;
            cin >> ID;
            Customer temp = searchByID(ID);
            if (temp.getID().compare("") == 0 || !fileHandler.removeRainbowEntry(ID)) {
                cout << "Customer not found on pre-order list. Returning to the main menu . . .";
                break;
            }
                cout << temp.getFullName_FirstLast() << " removed. Returning to the main menu . . ." << endl;

            break;

        }
        default:
        {
            cout << "Invalid input. Returning to the main menu . . ." << endl;
            break;
        }
    }
    return;

}

void salesReport(){
    for(Employee * employee : fileHandler.getEmployeePointers())
    {
        cout << employee->toString() << endl;
    }
}