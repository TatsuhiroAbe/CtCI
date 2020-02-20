//
// Created by 阿部竜大 on 2020-02-20.
//

#include <string>
#include "Call.h"
#include "Employee.h"
#include "CallHandler.h"

using namespace std;

CallHandler::CallHandler() {
    employeeLevels.resize(LEVELS);
    callQueues.resize(LEVELS);

    vector<Employee*> respondents;
    for (int i = 0; i < NUN_RESPONDENTS; i++) {
        Employee *respondent = new Employee(this, Rank::responder);
        respondents.push_back(respondent);
    }

    vector<Employee*> managers;
    for (int i = 0; i < NUM_MANAGERS; i++) {
        Employee *manager = new Employee(this, Rank::manager);
        managers.push_back(manager);
    }

    vector<Employee*> directors;
    for (int i = 0; i < NUM_DIRECTORS; i++) {
        Employee *director = new Employee(this, Rank::director);
        directors.push_back(director);
    }

    employeeLevels.push_back(respondents);
}

Employee* CallHandler::getHandlerForCall(Call *call) {
    for (int level = call->getRank(); level < LEVELS - 1; level++) {
        vector<Employee*> employeeLevel = employeeLevels[level];
        for (Employee *e : employeeLevel) {
            if (e->isFree()) {
                return e;
            }
        }
    }
    return nullptr;
}

void CallHandler::dispatchCall(Caller *caller) {
    Call *call = new Call(caller);
    dispatchCall(call);
}

void CallHandler::dispatchCall(Call *call) {
    Employee *e = getHandlerForCall(call);
    if (e != nullptr) {
        e->receiveCall(call);
        call->setHandler(e);
    } else {
        call->reply("Please wait for free employee to reply");
        callQueues[call->getRank()].push(call);
    }
}

bool CallHandler::assignCall(Employee *e) {
    for (int rank = e->getRank(); rank >= 0; rank--) {
        queue<Call*> que = callQueues[rank];

        if (!que.empty()) {
            Call *call = que.front(); que.pop();
            if (call != nullptr) {
                e->receiveCall(call);
                return true;
            }
        }
    }
    return false;
}