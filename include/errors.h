
#ifndef ERRORS_H_INCLUDED
#define ERRORS_H_INCLUDED

#include <string>
#include "token.h"
#include "management.h"

#define DEV_ERRORS

#define ERROR_INDICATOR                    (filename_name(current_filename) + " (" + getLineString(context.tokens,context.index) + "): ")
#define NOLINE_ERROR_INDICATOR             (filename_name(current_filename) + ": ")

#define NO_MAIN                            (NOLINE_ERROR_INDICATOR + "Missing main method")
#define INVALID_TOKEN                      (NOLINE_ERROR_INDICATOR + "Found valid operators but can't assemble them")
#define INVALID_METHOD_NAME(a)             (ERROR_INDICATOR + "Invalid method name '" + a + "'")
#define INVALID_CLASS_NAME(a)              (ERROR_INDICATOR + "Invalid class name '" + a + "'")
#define GLOBAL_STATEMENT                   (ERROR_INDICATOR + "Unexpected statement in global scope")
#define UNEXPECTED_TERMINATE               (ERROR_INDICATOR + "Unexpected statement termination")
#define UNEXPECTED_OPERATOR                (ERROR_INDICATOR + "Unexpected operator '" + token_operator(context.tokens[context.index]) + "'")
#define UNEXPECTED_OPERATOR_INEXP          (ERROR_INDICATOR + "Unexpected operator '" + token_operator(context.tokens[context.index]) + "' in expression")
#define UNEXPECTED_WORD                    (ERROR_INDICATOR + "Unexpected identifier '" + context.tokens[context.index].data + "'")
#define UNEXPECTED_WORD_AFTER_VARNAME(a)   (ERROR_INDICATOR + "Unexpected identifier '" + context.tokens[context.index].data + "' after variable '" + a + "'")
#define UNDECLARED_VARIABLE(a)             (ERROR_INDICATOR + "Undeclared variable '" + a + "'")
#define VARIABLE_NOT_EXIST_YET(a)          (ERROR_INDICATOR + "Variable '" + a + "' doesn't exist yet")
#define UNDECLARED_METHOD(a)               (ERROR_INDICATOR + "Undeclared method '" + a + "'")
#define UNDECLARED_CLASS(a)                (ERROR_INDICATOR + "Undeclared class '" + a + "'")
#define UNEXPECTED_KEYWORD(a)              (ERROR_INDICATOR + "Unexpected keyword " + a)
#define CLASS_DECLARED_AFTER(a, b)         (ERROR_INDICATOR + "The Class '" + a + "' was declared after '" + b + "', it can't be used before that")
#define CLASS_IS_FINAL(a)                  (ERROR_INDICATOR + "The Class '" + a + "' is final, methods can't be added")
#define UNDECLARED_METHOD_OTHERS(a)        (ERROR_INDICATOR + "Undeclared method '" + a + "' - similar methods exist with different arguments")
#define INCOMPATIBLE_CLASSES(a,b)          (ERROR_INDICATOR + "Incompatible classes '" + a + "' and '" + b + "'")
#define CANT_CALL_METHODS_OF_VOID          (ERROR_INDICATOR + "Can't call methods of void, it has no type")
#define CANT_PASS_VOID_AS_ARGUMENT         (ERROR_INDICATOR + "Can't pass void as method argument, it has no type")
#define PACKAGE_DOESNT_EXIST(a)            (ERROR_INDICATOR + "The Package '" + a + "' doesn't exist")

#define DEV_BLANK_TYPE                     (NOLINE_ERROR_INDICATOR + "Returning blank type at " + string(__LINE__))

extern std::string current_filename;

unsigned int getLineNumber(const TokenList&, unsigned int);
std::string getLineString(const TokenList&, unsigned int);

#endif // ERRORS_H_INCLUDED