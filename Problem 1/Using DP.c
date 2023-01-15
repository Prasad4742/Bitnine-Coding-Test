#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    TypeTag type;
    int value;
    struct Node *left;
    struct Node *right;
} Node;

typedef enum TypeTag {
    ADD,
    SUB,
    MUL,
    DIV,
    FIB,
    CONST
} TypeTag;

Node* makeFunc(TypeTag type) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->type = type;
    return node;
}

int calc(Node *node) {
    if(node->type == ADD) {
        return calc(node->left) + calc(node->right);
    } else if(node->type == SUB) {
        return calc(node->left) - calc(node->right);
    } else if(node->type == MUL) {
        return calc(node->left) * calc(node->right);
    } else if(node->type == DIV) {
        return calc(node->left) / calc(node->right);
    } else if(node->type == FIB) {
        if(node->left == NULL) {
            return 0;
        } else if(node->left->value == 0) {
            return 0;
        } else if(node->left->value == 1) {
            return 1;
        } else {
            Node *left = makeFunc(FIB);
            left->left = (Node *) malloc(sizeof(Node));
            left->left->value = node->left->value - 1;
            Node *right = makeFunc(FIB);
            right->left = (Node *) malloc(sizeof(Node));
            right->left->value = node->left->value - 2;
            Node *add = makeFunc(ADD);
            add->left = left;
            add->right = right;
            return calc(add);
        }
    } else {
        return node->value;
    }
}

int main() {
    Node *add = (*makeFunc(ADD))(10, 6);
    Node *mul = (*makeFunc(MUL))(5, 4);
    Node *sub = (*makeFunc(SUB))(mul, add);
    Node *fibo = (*makeFunc(SUB))(sub, NULL);
    printf("add : %d\n", calc(add));
    printf("mul : %d\n", calc(mul));
    printf("sub : %d\n", calc(sub));
    printf("fibo : %d\n", calc(fibo));
    return 0;
}
