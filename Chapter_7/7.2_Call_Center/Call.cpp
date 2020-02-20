//
// Created by 阿部竜大 on 2020-02-20.
//

#include <iostream>
#include <string>
#include "Call.h"
#include "Employee.h"
#include "CallHandler.h"

using namespace std;

Call::Call(Caller *c) : caller(c), rank(Rank::responder) {}

void Call::setHandler(Employee *e) {
    handler = e;
}

void Call::reply(std::string message) {
    cout << message << endl;
}

Rank Call::getRank() {
    return rank;
}

void Call::setRank(Rank r) {
    rank = r;
}

Rank Call::incrementRank() {
    if (rank == Rank::responder) {
        rank = Rank::manager;
    } else if (rank == Rank::manager) {
        rank = Rank::director;
    }
    return rank;
}

void Call::disconnect() {
    cout << "Thank you for calling" << endl;
}