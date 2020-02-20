//
// Created by 阿部竜大 on 2020-02-20.
//

#ifndef CTCI_OOP_EMPLOYEE_H
#define CTCI_OOP_EMPLOYEE_H

#include "Rank.cpp"
#include "Call.h"
#include "CallHandler.h"

class Call;
class CallHandler;

class Employee {
private:
    Call *currentCall;
    CallHandler *callHandler;

protected:
    Rank rank;

public:
    Employee(CallHandler *ch, Rank r);

    void receiveCall(Call *call);

    void callCompleted();

    void escalateAndRessign();

    bool assignNewCall();

    bool isFree();

    Rank getRank();
};


#endif //CTCI_OOP_EMPLOYEE_H
