
#ifndef SCOPE_H_INCLUDED
#define SCOPE_H_INCLUDED

#include <string>
#include <vector>

struct Variable {
    std::string name;
    std::string type;
};
typedef std::vector<Variable> VariableList;

struct Scope {
    std::string name;
    Scope* parent;
    std::vector<Scope*> children;
    VariableList variables;
};
typedef std::vector<Scope> ScopeList;

struct Method {
    std::string name;
    Scope* parent;
    std::string arguments;
    std::string return_type;
};
typedef std::vector<Method> MethodList;

struct Template {
    std::string name;
};
typedef std::vector<Template> TemplateList;

struct Environment {
    Scope        global{"global", NULL};
    MethodList   methods;
    TemplateList templates;
};

bool environment_method_exists(Environment*, Method);

void print_scopes(Scope* scope, unsigned int indent = 0);
void clean_scopes(Scope* scope);

#endif // SCOPE_H_INCLUDED
