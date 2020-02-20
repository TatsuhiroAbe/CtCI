//
// Created by 阿部竜大 on 2020-02-20.
//

#include "Caller.h"
#include "CallHandler.h"
#include "Employee.h"

Employee::Employee(CallHandler *ch, Rank r) : callHandler(ch), rank(r) {}

void Employee::receiveCall(Call *call) {
    currentCall = call;
}

void Employee::callCompleted() {
    if (currentCall != nullptr) {
        currentCall->disconnect();
        currentCall = nullptr;
    }
    assignNewCall();
}
void  Employee::escalateAndRessign() {
    if (currentCall != nullptr) {
        currentCall->incrementRank();
        callHandler->dispatchCall(currentCall);

        currentCall = nullptr;
    }
    assignNewCall();
}

bool Employee::assignNewCall() {
    if (!isFree()) {
        return false;
    }
    return callHandler->assignCall(this);
}

bool Employee::isFree() {
    return currentCall == nullptr;
}

Rank Employee::getRank() {
    return rank;
}