#include "StackVisualizer.h"
#include "need.h"
#include <iostream>
#include <iomanip>
using namespace std;

StackVisualizer::StackVisualizer(){}

bool StackVisualizer::empty() const{
    return values.empty();
}

int StackVisualizer::size() const{
    return static_cast<int>(values.size());
}

void StackVisualizer::display() const{
    cout << "\nStack State (LIFO | size = " << values.size() << "):\n";
    if(values.empty()){
        cout << " [ empty stack ]\n";
        return;
    }
    for(int i = static_cast<int>(values.size()) - 1; i >= 0; i--){
        cout << "  | " << setw(5) << values[i] << " |";
        if (i == static_cast<int>(values.size()) - 1){
            cout << "  <-- TOP";
        }
        cout << "\n  +-------+\n";
    }
}

void StackVisualizer::push(int value){
    cout << "\n-- BEFORE PUSH(" << value << ") ---";
    display();
    values.push_back(value);
    cout << "\n[Step] Pushed " << value << " onto top of stack.\n";
    cout << "-- AFTER PUSH(" << value << ") ---";
    display();
    cout << "Complexity: Time O(1) amortized | Auxiliary Space O(1)\n";
}

void StackVisualizer::pop(){
    cout << "\n-- BEFORE POP() ---";
    display();

    if(empty()){
        cout << "\n [Underflow Error] Stack is empty. Nothing to pop.\n";
        cout << "Complexity: Time O(1) | Auxiliary Space O(1)\n";
        return;
    }
    int removedVal = values.back();
    values.pop_back();

    cout << "\n[Step] Popped " << removedVal << " from top of stack.\n";
    cout << "--- AFTER POP() ---";
    display();
    cout << "Complexity: Time O(1) | Auxiliary Space O(1)\n";
}

void StackVisualizer::top() const{
    if(empty()){
        cout << "\n [Underflow Error] Stack is empty. No top element.\n";
    } else{
        cout << "\n Top elemenet: " << values.back() << " (stack unchanged)\n";
    }
    cout << "Complexity: Time O(1) | Auxiliary Space O(1)\n";
}

void StackVisualizer::checkBalancedDeLimiters(const std::string& expression) const {
    cout << "\n--- BALANCED DELIMITERS CHECK: \"" << expression << "\" ---\n";
    vector<char> charStack;

    auto printCharStack = [&charStack]() {
        std::cout << "Stack (bottom -> top): [ ";
        for (char ch : charStack) cout << ch << " ";
        cout << "]\n";
    };

    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            charStack.push_back(c);
            cout << "Read '" << c << "' -> Push opening delimiter. ";
            printCharStack();
        } else if (c == ')' || c == ']' || c == '}') {
            if (charStack.empty()) {
                cout << "Read '" << c << "' -> [FAIL] Stack is empty (premature closing delimiter).\n";
                cout << "Result: UNBALANCED\n";
                cout << "Complexity: Time O(n) | Auxiliary Space O(n)\n";
                return;
            }
            char openTop = charStack.back();
            bool matches = (openTop == '(' && c == ')') ||
                           (openTop == '[' && c == ']') ||
                           (openTop == '{' && c == '}');
            if (!matches) {
                cout << "Read '" << c << "' -> [FAIL] Top is '" << openTop << "', expected matching pair.\n";
                cout << "Result: UNBALANCED\n";
                cout << "Complexity: Time O(n) | Auxiliary Space O(n)\n";
                return;
            }
            charStack.pop_back();
            cout << "Read '" << c << "' -> Matches '" << openTop << "', pop top. ";
            printCharStack();
        }
    }

    if (charStack.empty()) {
        cout << "End of expression -> Stack is empty.\n";
        std::cout << "Result: BALANCED\n";
    } else {
        cout << "End of expression -> [FAIL] Unclosed opening delimiter(s) remain.\n";
        cout << "Result: UNBALANCED\n";
    }
    cout << "Complexity: Time O(n) | Auxiliary Space O(n)\n";
}

void StackVisualizer::runMenu(){
    int choice = 0;
    while (choice != 6){
        cout << "\n";
        need::printDivider();
        cout << "  Stack Visualizer (LIFO)\n";
        need::printDivider();
        cout << "1. Push (Insert at Top)\n";
        cout << "2. Pop (Remove Top)\n";
        cout << "3. Top (Peek Top Element)\n";
        cout << "4. Display Stack\n";
        cout << "5. Application: Balanced Delimiters Checker\n";
        cout << "6. Back to Main Menu\n";
        need::printDivider();

        choice = need::getValidInt("Choose a operation(1-6) : ", 1, 6);

        switch(choice){
            case 1: {
                int val = need::getAnyInt("Enter integer value to push:");
                push(val);
                break;
            }
            case 2: 
                pop();
                break;
            case 3:
            top();
            break;
            case 4:
            display();
            break;
            case 5: {
                cout << "Enter expression with brackets (eg {[()]} or  ([)]): )";
                string expr;
                getline(cin, expr);
                checkBalancedDeLimiters(expr);
                break;
            }
            case 6:
            cout << "Returning to Main Menu...\n";
            break;
        }
    }
}