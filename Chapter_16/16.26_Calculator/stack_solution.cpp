#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;


enum Operator {
    ADD, SUBTRACT, MULTIPLY, DIVIDE, BLANK
};

int priorityNumber(Operator op) {
    switch (op) {
        case ADD:
            return 1;
        case SUBTRACT:
            return 1;
        case MULTIPLY:
            return 2;
        case DIVIDE:
            return 2;
        case BLANK:
            return 0;
    }
    return 0;
}

double applyOp(double left, Operator op, double right) {
    if (op == Operator::ADD) {
        return left + right;
    } else if (op == Operator::SUBTRACT) {
        return left - right;
    } else if (op == Operator::MULTIPLY) {
        return left * right;
    } else if (op == Operator::DIVIDE) {
        return left / right;
    } else {
        return right;
    }
}

Operator parseOperator(char op) {
    switch (op) {
        case '+':
            return Operator::ADD;
        case '-':
            return Operator::SUBTRACT;
        case '*':
            return Operator::MULTIPLY;
        case '/':
            return Operator::DIVIDE;
        default:
            return Operator::BLANK;
    }
}

int parseNextNumber(string sequence, int offset) {
    string s;
    while (offset < sequence.size() && sequence[offset] >= '0' && sequence[offset] <= '9') {
        s.push_back(sequence[offset]);
        offset++;
    }
    return stoi(s);
}

void collapseTop(Operator futureTop, stack<double> &numberStack, stack<Operator> &operatorStack) {
    while (!operatorStack.empty() && numberStack.size() >= 2) {
        if (priorityNumber(futureTop) <= priorityNumber(operatorStack.top())) {
            double second = numberStack.top(); numberStack.pop();
            double first = numberStack.top(); numberStack.pop();
            Operator op = operatorStack.top(); operatorStack.pop();
            double collapsed = applyOp(first, op, second);
            numberStack.push(collapsed);
        } else {
            break;
        }
    }
}

double compute(string sequence) {
    stack<double> numberStack;
    stack<Operator> operatorStack;

    for (int i = 0; i < sequence.size(); i++) {
        int value = parseNextNumber(sequence, i);
        numberStack.push((double)value);

        i += to_string(value).size();
        if (i >= sequence.size()) {
            break;
        }

        Operator op = parseOperator(sequence[i]);
        collapseTop(op, numberStack, operatorStack);
        operatorStack.push(op);
    }

    collapseTop(Operator::BLANK, numberStack, operatorStack);
    if (numberStack.size() == 1 && operatorStack.empty()) {
        return numberStack.top();
    }
    return 0;
}


int main() {
    string expression = "2-6-7*8/2+5";
    double result = compute(expression);
    cout << result << endl; // -27
    return 0;
}