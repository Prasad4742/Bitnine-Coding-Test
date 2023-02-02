#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Function F gives nth fibonacci number in output recurssively
int F(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return F(n-1) + F(n-2);
}

struct Node {
    int data;
    Node* next;
};

Node* addNumbers(int a, int b) {
    Node* result = new Node;
    result->data = a + b;
    result->next = nullptr;
    return result;
}

Node* mulNumbers(int a, int b) {
    Node* result = new Node;
    result->data = a * b;
    result->next = nullptr;
    return result;
}

Node* subNumbers(int a,int b) {
    Node* result = new Node;
    result->data = a - b;
    result->next = nullptr;
    return result;
}



Node* (*makeFunc(char op))(int, int) {
    switch (op) {
        case '+':
            return addNumbers;
        case '*':
            return mulNumbers;
        case '-':
            return subNumbers;
        default:
            return nullptr;
    }
}

int main() {
    Node* add = (*makeFunc('+'))(10, 6);
    Node* mul = (*makeFunc('*'))(5, 4);
    //conversion to integer
    int addResult = add->data; int mulResult = mul->data; 
    
    Node* sub = (*makeFunc('-'))(addResult, mulResult);
    //conversion to integer
    int subResult = sub->data;
    
    Node *fibo = (*makeFunc('-'))(abs(subResult), NULL);
    //conversion to integer
    int n = fibo->data;
    
    std::cout << add->data << std::endl;
    std::cout << mul->data << std::endl;
    std::cout << sub->data << std::endl;
    std::cout << F(n) << std::endl;
    return 0;
}
