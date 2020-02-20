//
// Created by 阿部竜大 on 2020-02-20.
//

#ifndef CTCI_OOP_CALLHANDLER_H
#define CTCI_OOP_CALLHANDLER_H

#include <vector>
#include <queue>
#include "Call.h"
#include "Caller.h"
#include "Employee.h"

class Call;
class Employee;

class CallHandler {
private:
    const int LEVELS = 3;
    const int NUN_RESPONDENTS = 10;
    const int NUM_MANAGERS = 4;
    const int NUM_DIRECTORS = 2;

    std::vector<std::vector<Employee*>> employeeLevels;
    std::vector<std::queue<Call*>> callQueues;

public:
    CallHandler();

    Employee *getHandlerForCall(Call *call);

    void dispatchCall(Caller *caller);

    void dispatchCall(Call *call);

    bool assignCall(Employee *e);
};


#endif //CTCI_OOP_CALLHANDLER_H
