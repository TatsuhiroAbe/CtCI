//
// Created by 阿部竜大 on 2020-02-20.
//

#ifndef CTCI_OOP_CALL_H
#define CTCI_OOP_CALL_H

#include "Caller.h"
#include "Employee.h"
#include "CallHandler.h"

class Employee;
class CallHandler;

class Call {
private:
    Rank rank;
    Caller *caller;
    Employee *handler;

public:
    Call(Caller *c);

    void setHandler(Employee *e);

    void reply(std::string message);

    Rank getRank();

    void setRank(Rank r);

    Rank incrementRank();

    void disconnect();
};


#endif //CTCI_OOP_CALL_H
