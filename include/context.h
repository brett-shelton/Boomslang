
#ifndef CONTEXT_H_INCLUDED
#define CONTEXT_H_INCLUDED

/*
    Higher Level Context Aware Functions
    that take an Environment& instead of a Scope*
    like most of the recursive functions called
*/

#include "token.h"

bool context_variable_exists(Environment&, Variable);
bool context_class_exists(Environment&, Class);
bool context_method_exists(Environment&, Method);
bool context_method_exists(Environment&, Class, Method);

Variable context_variable_get(Environment&, Variable);
Class context_class_get(Environment&, Class);
Method context_method_get(Environment&, Method);

void context_enforce_expression(TokenContext context, Environment& e, Class& type);
void context_enforce_arguments(TokenContext context, Environment& e, Class& type);
void context_enforce_method_declaration_arguments(TokenContext tokens, Environment& e, MethodArgumentList& method_arguments, std::string& argument_string);
void context_enforce_following_method_calls(TokenContext context, Environment& e, Class& type);

bool name_is_class(std::string);
std::string name_get_class(std::string);
bool name_is_method(std::string);
std::string name_get_method(std::string);

#endif // CONTEXT_H_INCLUDED
