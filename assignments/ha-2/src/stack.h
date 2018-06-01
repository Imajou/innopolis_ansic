//
// Created by Gleb Petrakov on 31/05/2018.
//

#ifndef HA_2_STACK_H
#define HA_2_STACK_H


#include <stdlib.h>

int push(struct Stack *stack, double value);

double pop(struct Stack *stack);

double peek(struct Stack *stack);

#endif //HA_2_STACK_H
