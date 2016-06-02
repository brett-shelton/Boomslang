
#include <iostream>
#include <stdlib.h>
#include "../include/log.h"
#include "../include/token.h"
#include "../include/lexer.h"
#include "../include/errors.h"
#include "../include/management.h"

#define LEXER_LOG_PREFIX (to_string(tokens.size()) + " ")

using namespace std;

void process_indentation(TokenList& tokens, string& code, unsigned int& indentation){
    unsigned int line_indentaion = 0;

    while(is_indent(code)){
        line_indentaion++;

        if(code.substr(0,4) == "    "){
            code = string_delete_amount(code,4);
        } else {
            code = string_delete_amount(code,1);
        }
    }
    if(line_indentaion > indentation){
        while(line_indentaion > indentation){
            indentation++;
            tokens.push_back( TOKEN_INDENT );
        }
    }
    else if(line_indentaion < indentation){
        while(line_indentaion < indentation){
            indentation--;
            tokens.push_back( TOKEN_DEDENT );
        }
    }
}

TokenList tokenize(string code){
    // Converts code into a stream of tokens

    TokenList tokens;
    unsigned int indentation = 0;
    string prev;

    process_indentation(tokens, code, indentation);

    if(code == ""){
        lexer_log_tokens(tokens);
        return tokens;
    }

    if(code[code.length()-1] != '\n'){
        code += "\n";
    }

    while(code != "" and code!=prev){
        prev = code;

        // Remove Newlines and track indentation
        while(code.substr(0,1) == "\n"){
            log_lexer(LEXER_LOG_PREFIX + "Found a newline, adding terminate token");
            code = string_delete_amount(code,1);
            tokens.push_back( TOKEN_TERMINATE );

            process_indentation(tokens, code, indentation);
        }

        if(code.substr(0,1) == "\"" or code.substr(0,1) == "'"){ // String Literal
            log_lexer(LEXER_LOG_PREFIX + "Found string literal, adding string literal token");
            code = string_delete_amount(code,1);
            tokens.push_back( TOKEN_STRING_LITERAL(string_get_until_or(code,"\"'")) );
            code = string_delete_until_or(code,"\"'");
            code = string_delete_amount(code,1);
        }
        else if( (int)code[0] >= 48 and (int)code[0] <= 57){     // Numeric Literal
            log_lexer(LEXER_LOG_PREFIX + "Found numeric literal, adding numeric literal token");
            tokens.push_back( TOKEN_NUMERIC_LITERAL(string_get_until_or(code," ,)].\n")) );
            code = string_delete_until_or(code," ,)].\n");
        }
        else if( code.substr(0,1) == "."){                       // Member
            log_lexer(LEXER_LOG_PREFIX + "Found member operator, adding member token");
            code = string_delete_amount(code,1);
            tokens.push_back( TOKEN_MEMBER );
        }
        else if( code.substr(0,1) == "("){                       // Open
            log_lexer(LEXER_LOG_PREFIX + "Found open operator, adding open token");
            tokens.push_back( TOKEN_OPEN );
            code = string_delete_amount(code,1);
        }
        else if( code.substr(0,1) == ")"){                       // Close
            log_lexer(LEXER_LOG_PREFIX + "Found close operator, adding close token");
            tokens.push_back( TOKEN_CLOSE );
            code = string_delete_amount(code,1);
        }
        else if( code.substr(0,1) == "["){                       // Square Open
            log_lexer(LEXER_LOG_PREFIX + "Found opening square bracket, adding sq open token");
            tokens.push_back( TOKEN_SQOPEN );
            code = string_delete_amount(code,1);
        }
        else if( code.substr(0,1) == "]"){                       // Square Close
            log_lexer(LEXER_LOG_PREFIX + "Found closing square bracket, adding sq close token");
            tokens.push_back( TOKEN_SQCLOSE );
            code = string_delete_amount(code,1);
        }
        else if( code.substr(0,1) == "{"){                       // Curly Open
            log_lexer(LEXER_LOG_PREFIX + "Found opening curly bracket, adding curly open token");
            tokens.push_back( TOKEN_CURLYOPEN );
            code = string_delete_amount(code,1);
        }
        else if( code.substr(0,1) == "}"){                       // Curly Close
            log_lexer(LEXER_LOG_PREFIX + "Found closing curly bracket, adding curly close token");
            tokens.push_back( TOKEN_CURLYCLOSE );
            code = string_delete_amount(code,1);
        }
        else if( code.substr(0,1) == "="){                       // Assign
            log_lexer(LEXER_LOG_PREFIX + "Found equal sign, adding assign token");
            tokens.push_back( TOKEN_ASSIGN );
            code = string_delete_amount(code,1);
        }
        else if( code.substr(0,1) == "+"){                       // Add
            log_lexer(LEXER_LOG_PREFIX + "Found addition sign, adding add token");
            tokens.push_back( TOKEN_ADD );
            code = string_delete_amount(code,1);
        }
        else if( code.substr(0,1) == "-"){                       // Subtract
            log_lexer(LEXER_LOG_PREFIX + "Found subtraction sign, adding subtract token");
            tokens.push_back( TOKEN_SUBTRACT );
            code = string_delete_amount(code,1);
        }
        else if( code.substr(0,1) == "*"){                       // Multiply
            log_lexer(LEXER_LOG_PREFIX + "Found asterisk, adding multiplication token");
            tokens.push_back( TOKEN_MULTIPLY );
            code = string_delete_amount(code,1);
        }
        else if( code.substr(0,1) == "/"){                       // Divide
            log_lexer(LEXER_LOG_PREFIX + "Found forward slash, adding division token");
            tokens.push_back( TOKEN_DIVIDE );
            code = string_delete_amount(code,1);
        }
        else if( code.substr(0,1) == ","){                       // Next
            log_lexer(LEXER_LOG_PREFIX + "Found comma, adding next argument token");
            tokens.push_back( TOKEN_NEXT );
            code = string_delete_amount(code,1);
        }
        else if( code.substr(0,1) == "!"){                       // Not
            log_lexer(LEXER_LOG_PREFIX + "Found exclamation point, adding not token");
            tokens.push_back( TOKEN_NOT );
            code = string_delete_amount(code,1);
        }
        else if( code.substr(0,1) == "&"){                       // Address
            log_lexer(LEXER_LOG_PREFIX + "Found `and` symbol, adding address token");
            tokens.push_back( TOKEN_ADDRESS );
            code = string_delete_amount(code,1);
        }
        else if( code.substr(0,1) == ":"){                       // Address Member
            log_lexer(LEXER_LOG_PREFIX + "Found colon, adding address member token");
            tokens.push_back( TOKEN_ADDRESSMEMBER );
            code = string_delete_amount(code,1);
        }
        else if( code.substr(0,1) == "#"){                       // Line Comment
            log_lexer(LEXER_LOG_PREFIX + "Found hashtag, ignoring comment");
            code = string_delete_amount(code,1);
            code = string_delete_until(code, "\n");
        }
        else if( string_get_until(code," ") == "on"){            // Method Declaration
            log_lexer(LEXER_LOG_PREFIX + "Found `on` keyword");
            tokens.push_back( TOKEN_KEYWORD("on") );

            code = string_delete_amount(code,2);
            code = string_kill_whitespace(code);

            tokens.push_back( TOKEN_WORD(string_get_until_or(code," (\n")) );
            code = string_delete_until_or(code," (\n");
        }
        else if( string_get_until(code," ") == "import"){        // import
            log_lexer(LEXER_LOG_PREFIX + "Found `import` keyword");
            tokens.push_back( TOKEN_KEYWORD("import") );

            code = string_delete_amount(code,6);
            code = string_kill_whitespace(code);

            tokens.push_back( TOKEN_WORD(string_get_until(code,"\n")) );
            code = string_delete_until(code,"\n");
        }
        else if( string_get_until(code," ") == "return"){        // return
            log_lexer(LEXER_LOG_PREFIX + "Found `return` keyword");
            tokens.push_back( TOKEN_KEYWORD("return") );

            code = string_delete_amount(code,6);
            code = string_kill_whitespace(code);
        }
        else if( string_get_until(code," ") == "class"){      // class
            log_lexer(LEXER_LOG_PREFIX + "Found `class` keyword");
            tokens.push_back( TOKEN_KEYWORD("class") );

            code = string_delete_amount(code,5);

            code = string_kill_whitespace(code);
        }
        else if( string_get_until(code," ") == "unique"){        // Method Declaration
            log_lexer(LEXER_LOG_PREFIX + "Found `unique` keyword");
            tokens.push_back( TOKEN_KEYWORD("unique") );

            code = string_delete_amount(code,6);
            code = string_kill_whitespace(code);
        }
        else if( is_identifier(string_get_until_or(code, " ,()[]\n.+-*/=&:")) ){
            tokens.push_back( TOKEN_WORD(string_get_until_or(code, " ,()[]\n.+-*/=&:")) );
            code = string_delete_until_or(code, " ,()[]\n.+-*/=&:");
        }

        code = string_kill_whitespace(code);
    }

    if(code == prev){
        log_lexer("Discovered unrecognized operator '" + code.substr(0,1) + "'");

        cerr << "Unrecognized operator '" + code.substr(0,1) + "'" << endl;
        exit(1);
    }

    lexer_log_tokens(tokens);
    return tokens;
}
