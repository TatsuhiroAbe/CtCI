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


class Term {
public:
    enum Operator {
        ADD, SUBTRACT, MULTIPLY, DIVIDE, BLANK
    };

private:
    double value;
    Operator op = Operator::BLANK;

public:
    Term(double v, Operator o) : value(v), op(o) {}

    double getNumber() {
        return value;
    }

    Operator getOperator() {
        return op;
    }

    void setNumber(double v) {
        value = v;
    }

    static vector<Term*> parseTermSequence(string sequence) {
        vector<Term*> terms;
        int offset = 0;
        while (offset < sequence.size()) {
            Operator o = Operator::BLANK;
            if (offset > 0) {
                o = parseOperator(sequence[offset]);
                offset++;
            }

            int value = parseNextNumber(sequence, offset);
            offset += to_string(value).size();
            Term *term = new Term(value, o);
            terms.push_back(term);
        }

        return terms;
    }

    static Operator parseOperator(char op) {
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

    static int parseNextNumber(string sequence, int offset) {
        string s;
        while (offset < sequence.size() && sequence[offset] >= '0' && sequence[offset] <= '9') {
            s.push_back(sequence[offset]);
            offset++;
        }
        return stoi(s);
    }
};

double applyOp(double left, Term::Operator op, double right) {
    if (op == Term::Operator::ADD) {
        return left + right;
    } else if (op == Term::Operator::SUBTRACT) {
        return left - right;
    } else if (op == Term::Operator::MULTIPLY) {
        return left * right;
    } else if (op == Term::Operator::DIVIDE) {
        return left / right;
    } else {
        return right;
    }
}

Term *collapseTerm(Term *primary, Term *secondary) {
    if (primary == nullptr) return secondary;
    if (secondary == nullptr) return primary;

    double value = applyOp(primary->getNumber(), secondary->getOperator(), secondary->getNumber());
    primary->setNumber(value);
    return primary;
}

double compute(string sequence) {
    vector<Term*> terms = Term::parseTermSequence(sequence);
    if (terms.empty()) {
        return INT32_MIN;
    }

    double result = 0;
    Term *processing = nullptr;
    for (int i = 0; i < terms.size(); i++) {
        Term *curr = terms[i];
        Term *next = (i + 1 < terms.size()) ? terms[i + 1] : nullptr;

        processing = collapseTerm(processing, curr);

        if (next == nullptr ||
            next->getOperator() == Term::Operator::ADD ||
            next->getOperator() == Term::Operator::SUBTRACT) {
            result = applyOp(result, processing->getOperator(), processing->getNumber());
            processing = nullptr;
        }
    }

    return result;
}


int main() {
    string expression = "2-6-7*8/2+5";
    double result = compute(expression);
    cout << result << endl; // -27
    return 0;
}