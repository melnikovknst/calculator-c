#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "string.h"


char* postfix_notation(char*);
void calculate(char*);
int order(char);


int main(void) {
    char* input = get_input();
    char* postfix = postfix_notation(input);
    
    if ((is_digit(input[0]) != 1 && input[0] != '(') || !postfix) {
        printf("syntax error\n");
        
        return 0;
    }
        
    
    
    
    
    
    //printf("%d", atoi("25")+3);
        
    //calculate(postfix);
    
    return 0;
}


char* postfix_notation(char* str) {
    char* postfix = (char*)malloc(sizeof(char));
    STACK* op_stack = NULL;     // stack for operators
    int len = (int)strlen(str);
    int operators = 0;
    int brackets = 0;
    
    for (int i = 0; i < len; i++) {
        char chr = str[i];
        
        if (is_digit(chr) == 1)
            concatenate(&chr, &postfix);
        else if (is_digit(chr) == 0) {
            if (chr != '(')
                concatenate(" ", &postfix);
            
            if (empty(op_stack)) {
                push(&op_stack, (int)chr);
                
                if (chr != '(')
                    operators++;
                else
                    brackets++;
            }
            else if (chr == '(') {
                push(&op_stack, (int)chr);
                brackets++;
                operators++;
            }
            else if (chr == ')' && brackets <= 0)
                return NULL;
            else if (chr == ')') {
                brackets--;
                
                while ((char)(op_stack->value) != '(') {
                    char op = (char)pop(&op_stack);
                    concatenate(&op, &postfix);
                    concatenate(" ", &postfix);
                }
                
                pop(&op_stack);
            }
            else if (order(chr) > order(op_stack->value)) {
                push(&op_stack, (int)chr);
                operators++;
            }
            else {
                while (op_stack) {
                    char op = (char)pop(&op_stack);
                    concatenate(&op, &postfix);
                    concatenate(" ", &postfix);
                }
                
                push(&op_stack, (int)chr);
                operators++;
            }
        }
        else
            return NULL;
    }
    
    concatenate(" ", &postfix);
    
    while (op_stack) {
        char op = pop(&op_stack);
        if (op != ')') {
            concatenate(&op, &postfix);
            concatenate(" ", &postfix);
        }
    }
    
    
    if (count(postfix, ' ') - operators * 2 == 1)
        return NULL;
    
    return postfix;
}


int order(char op) {
    char* opers = "((-+*/)";
    for (int i = 0; i < (int)strlen(opers); i++)
        if (opers[i] == op)
            return i/2;
    
    return -1;
}


void calculate(char* postfix) {
    postfix[0] = '2';
}
