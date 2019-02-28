/* 
 * File:   Manager.cpp
 * Author: Alyssa Gibson
 * 
 * Created on February 26, 2019, 3:25 PM
 */

#include "Manager.h"
#include <string>

using namespace std;

Manager::Manager(string t, string n, string sid, string bid):SuperSales(t, n, sid, bid) {
    commission = 0;
}

double Manager::getCommission() {
    // Commission calculation goes here
    return commission;
}

Manager::~Manager() {
}

