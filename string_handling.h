/**
    ============ string_handling.h ============
    Code for String Handling Functions

    This file should NOT be included
    anywhere besides from main.cpp.

    This Header does NOT contain a
    header guard so include with
    cation.
*/

using namespace std;

///Declarations
void error_show(string a);

bool string_contains(string parent_string, string sub_string){
    if (parent_string.find(sub_string)==string::npos)
        return false;
    else
        return true;
}

string string_get_until(string parent_string, string character){
    unsigned int index = 0;

    while(!( parent_string.substr(index,1)==character or index >= parent_string.length() )){
        index++;
    }

    if (index >= parent_string.length()){
        return parent_string;
    }
    else{
        return parent_string.substr(0,index);
    }
}

string string_delete_until(string parent_string, string character){
    unsigned int index = 0;

    while(!( parent_string.substr(index,1)==character or index >= parent_string.length() )){
        index++;
    }

    if (index >= parent_string.length()){
        return parent_string;
    }
    else{
        return parent_string.substr(index,parent_string.length()-index);
    }
}

string string_get_until_or(string parent_string, string characters){
    unsigned int index = 0;

    while(!( string_contains(characters,parent_string.substr(index,1)) or index >= parent_string.length() )){
        index++;
    }

    if (index >= parent_string.length()){
        return parent_string;
    }
    else{
        return parent_string.substr(0,index);
    }
}

string string_delete_until_or(string parent_string, string characters){
    unsigned int index = 0;

    while(!( string_contains(characters,parent_string.substr(index,1)) or index >= parent_string.length() )){
        index++;
    }

    if (index >= parent_string.length()){
        return parent_string;
    }
    else{
        return parent_string.substr(index,parent_string.length()-index);
    }
}

string string_delete_amount(string str, int num){
    return str.substr(num,str.length()-num);
}

string string_replace(string str, const std::string from, const string to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return "";
    else
        return str.replace(start_pos, from.length(), to);
}

string string_replace_all(string str, const std::string from, const string to) {
    if(from.empty())
        return "";
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }

    return str;
}

string string_kill_whitespace(string str){
    int n = 0;

    while(!(str.substr(n,1)!=" " and str.substr(n,1)!="\t")){
        n++;
    }

    return string_delete_amount(str,n);
}

string string_kill_all_whitespace(string str){
    int n = 0;

    while(!(str.substr(n,1)!=" " and str.substr(n,1)!="\t" and str.substr(n,1)!="\n")){
        n++;
    }

    return string_delete_amount(str,n);
}

string resource(string a){
    return "BOOMSLANG_" + string_replace_all(string_replace_all(a,":","::BOOMSLANG_"),".",".BOOMSLANG_");
}

string resource_function(string a){
    return "BOOMSLANG_" + string_replace_all(string_replace_all(a,":","::BOOMSLANG_"),".","::BOOMSLANG_");
}

string resource_hidden(string a){
    return "BOOMSLANGHIDDEN_" + string_replace_all(string_replace_all(a,":","::BOOMSLANG_"),".",".BOOMSLANG_");
}

string delete_backslash(string a){
    if (a.substr(0,1)=="\\")
        return string_delete_amount(a,1);
    else
        return a;
}

string string_upper(string a){
    string aa = a;
    ::transform(aa.begin(), aa.end(), aa.begin(), ::toupper);
    return aa;
}

bool is_identifier(string what){
    //Is it blank?
    if (what=="") return false;

    //Does it start with a number?
    if (what.substr(0,1)=="0"
        or what.substr(0,1)=="1"
        or what.substr(0,1)=="2"
        or what.substr(0,1)=="3"
        or what.substr(0,1)=="4"
        or what.substr(0,1)=="5"
        or what.substr(0,1)=="6"
        or what.substr(0,1)=="7"
        or what.substr(0,1)=="8"
        or what.substr(0,1)=="9")
        return false;

    //Underscore are ok
    string a = string_replace_all(what,"_","");

    //Numbers are ok
    a = string_replace_all(a,"1","");
    a = string_replace_all(a,"2","");
    a = string_replace_all(a,"3","");
    a = string_replace_all(a,"4","");
    a = string_replace_all(a,"5","");
    a = string_replace_all(a,"6","");
    a = string_replace_all(a,"7","");
    a = string_replace_all(a,"8","");
    a = string_replace_all(a,"9","");
    a = string_replace_all(a,"0","");

    //Lowercase Letters are ok
    a = string_replace_all(a,"a","");
    a = string_replace_all(a,"b","");
    a = string_replace_all(a,"c","");
    a = string_replace_all(a,"d","");
    a = string_replace_all(a,"e","");
    a = string_replace_all(a,"f","");
    a = string_replace_all(a,"g","");
    a = string_replace_all(a,"h","");
    a = string_replace_all(a,"i","");
    a = string_replace_all(a,"j","");
    a = string_replace_all(a,"k","");
    a = string_replace_all(a,"l","");
    a = string_replace_all(a,"m","");
    a = string_replace_all(a,"n","");
    a = string_replace_all(a,"o","");
    a = string_replace_all(a,"p","");
    a = string_replace_all(a,"q","");
    a = string_replace_all(a,"r","");
    a = string_replace_all(a,"s","");
    a = string_replace_all(a,"t","");
    a = string_replace_all(a,"u","");
    a = string_replace_all(a,"v","");
    a = string_replace_all(a,"w","");
    a = string_replace_all(a,"x","");
    a = string_replace_all(a,"y","");
    a = string_replace_all(a,"z","");

    //Uppercase Letters are ok
    a = string_replace_all(a,"A","");
    a = string_replace_all(a,"B","");
    a = string_replace_all(a,"C","");
    a = string_replace_all(a,"D","");
    a = string_replace_all(a,"E","");
    a = string_replace_all(a,"F","");
    a = string_replace_all(a,"G","");
    a = string_replace_all(a,"H","");
    a = string_replace_all(a,"I","");
    a = string_replace_all(a,"J","");
    a = string_replace_all(a,"K","");
    a = string_replace_all(a,"L","");
    a = string_replace_all(a,"M","");
    a = string_replace_all(a,"N","");
    a = string_replace_all(a,"O","");
    a = string_replace_all(a,"P","");
    a = string_replace_all(a,"Q","");
    a = string_replace_all(a,"R","");
    a = string_replace_all(a,"S","");
    a = string_replace_all(a,"T","");
    a = string_replace_all(a,"U","");
    a = string_replace_all(a,"V","");
    a = string_replace_all(a,"W","");
    a = string_replace_all(a,"X","");
    a = string_replace_all(a,"Y","");
    a = string_replace_all(a,"Z","");

    if (a==""){
        return true;
    } else {
        return false;
    }
}

bool rawvalue_exists(string what){
    if (what=="") return false;

    if (what.substr(0,1)=="\""){
        return true;
    }
    if (what.substr(0,1)=="0"){
        return true;
    }
    if (what.substr(0,1)=="1"){
        return true;
    }
    if (what.substr(0,1)=="2"){
        return true;
    }
    if (what.substr(0,1)=="3"){
        return true;
    }
    if (what.substr(0,1)=="4"){
        return true;
    }
    if (what.substr(0,1)=="5"){
        return true;
    }
    if (what.substr(0,1)=="6"){
        return true;
    }
    if (what.substr(0,1)=="7"){
        return true;
    }
    if (what.substr(0,1)=="8"){
        return true;
    }
    if (what.substr(0,1)=="9"){
        return true;
    }

    return false;
}

string harvest_string(string& code){
    string str;

    if(code.substr(0,1)=="\""){
        code = string_delete_amount(code,1);

        while(code.substr(0,1)!="\""){
            str += code.substr(0,1);
            code = string_delete_amount(code,1);
        }

        code = string_delete_amount(code,1);
    }

    return str;
}

string harvest_decimal(string& code){
    string str;

    while(code.substr(0,1)=="0"
          or code.substr(0,1)=="1"
          or code.substr(0,1)=="2"
          or code.substr(0,1)=="3"
          or code.substr(0,1)=="4"
          or code.substr(0,1)=="5"
          or code.substr(0,1)=="6"
          or code.substr(0,1)=="7"
          or code.substr(0,1)=="8"
          or code.substr(0,1)=="9"
          or code.substr(0,2)==".0"
          or code.substr(0,2)==".1"
          or code.substr(0,2)==".2"
          or code.substr(0,2)==".3"
          or code.substr(0,2)==".4"
          or code.substr(0,2)==".5"
          or code.substr(0,2)==".6"
          or code.substr(0,2)==".7"
          or code.substr(0,2)==".8"
          or code.substr(0,2)==".9"){
        str += code.substr(0,1);
        code = string_delete_amount(code,1);
    }

    return str;
}
