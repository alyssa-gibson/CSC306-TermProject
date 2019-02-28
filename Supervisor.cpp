/* 
 * File:   Supervisor.cpp
 * Author: Alyssa Gibson
 * 
 * Created on February 26, 2019, 3:33 PM
 */

#include "Supervisor.h"

#include <string>

using namespace std;

Supervisor::Supervisor(string t, string n, string sid, string bid)
    :Manager(t, n, sid, bid) {
    commission = 0;
}

double Supervisor::getCommission() {
    // Commission calculations go here.
}

Supervisor::~Supervisor() {
}

