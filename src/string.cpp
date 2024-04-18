#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include "parser.tab.h"
using namespace std;

map<string,map<string,string>>m;
int curr_offset=-8;
int param=0;
string curr_function="global";
string temp_string="";
int param_offset=16;
int is_return=0;
bool check_identifier(string s){
    if(s=="popparameter")return 0;
    if(s=="param")return 0;
    if(s=="return")return 0;
    if(s=="stackpointer")return 0;
    if(s[0]=='#')return 1;
    for(char ch:s){
        if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'||ch>='0'&&ch<='9'||ch=='_')continue;
        return 0;
    }
    for(char ch:s){
        if(ch<'0'||ch>'9')return 1;
    }
    return 0;
}
void check(vector<string>&a){
    int i=0;
    for(string s:a){
        // cout<<s<<" ";
        if(check_identifier(s)){
            if(m[curr_function].find(s)==m[curr_function].end()){
                m[curr_function][s]=to_string(curr_offset)+"(%rbp)";
                curr_offset-=8;
            }
        }else{
                m[curr_function][s]="$"+s;
            }
    }
    // cout<<endl;
}
string arith_oper(string s){
    if(s=="+")return "addq";
    if(s=="-")return "subq";
    if(s=="*")return "imulq";
    return "";
}
string rel_oper(string s){
    if(s=="<")return "setl";
    if(s==">")return "setg";
    if(s=="<=")return "setle";
    if(s==">=")return "setge";
    if(s=="==")return "sete";
    if(s=="!=")return "setne";
    return "";
}
int main(int argc, char *argv[] ) {
    // Prompt the user to enter the input filename
    
    string inputFilename;
    inputFilename=argv[1];

    // Open the input file
    ifstream inputFile(inputFilename);

    // Check if the input file is opened successfully
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file " << inputFilename << endl;
        return 1;
    }

    // Read the contents of the input file into a string
    vector<string>content;
    string line;
    while (getline(inputFile, line)) {
        content.push_back(line);
             // Append each line to the fileContents string
    }
    string modifiedString="";
    modifiedString+=".data\n";
    modifiedString+="format_print_str: .asciz \"%s\\n\"\nformat_print_int: .asciz \"%ld\\n\"\nformat_print_true: .asciz \"True\\n\"\nformat_print_false: .asciz \"False\\n\"\n";
    modifiedString+=".text\n.globl main\n";
    char prev=' ';
    int c=0;
    for (string s : content) {
        if(s=="")continue;
        // cout<<s<<endl;
        vector<string>a(5,"");
        int i=0;
        string temp="";
        for(char ch:s){
            if(ch==' '){
                // cout<<temp<<" ";
                a[i]=temp;
                temp="";
                i++;
            }else{
                temp+=ch;
            }
        }
        // cout<<temp<<endl;
        a[i]=temp;
        if(is_return&&a[2]!="popparameter"){
            temp_string+="movq %rbx, %rsp\npopq %r11\npopq %r10\npopq %r9\npopq %r8\npopq %rsi\npopq %rdi\npopq %rdx\npopq %rcx\npopq %rax\n";
            is_return=0;
        }
        if(a[1]==":"){
            // cout<<a[0]<<endl;
            if(a[0][0]=='.'){
                temp_string+=a[0]+a[1]+"\n";
            }else{
                curr_function=a[0];
                modifiedString+=a[0]+a[1]+"\n";
            }
            continue;
        }
        if(a[0]=="funcbegin"){
            modifiedString+="pushq %rbp\n";
            modifiedString+="movq %rsp, %rbp\n";
            temp_string="";
            continue;
        }
        if(a[0]=="funcend"){
            curr_function="global";
            modifiedString+="subq $"+to_string(-curr_offset-8)+", %rsp\n";
            modifiedString+=temp_string;
            modifiedString+="leave\n";
            modifiedString+="ret\n";
            curr_offset=-8;
            continue;
        }
        if(a[0]=="call"){
            temp_string+="call "+a[1]+"\n";
            continue;
        }
        check(a);
        if(a[0]=="return"&&a[1]!=""){
            temp_string+="movq "+m[curr_function][a[1]]+", %rax\n";
            continue;
        }
        if(a[2]=="popparameter"&&!is_return){
            temp_string+="movq "+to_string(param_offset)+"(%rbp), %rdx\n";
            temp_string+="movq %rdx, "+m[curr_function][a[0]]+"\n";
            param_offset+=8;
            continue;
        }
        if(a[2]=="popparameter"&&is_return){
            // cout<<a[0]<<endl;
            temp_string+="movq %rax, "+m[curr_function][a[0]]+"\n";
            continue;
        }
        if(a[0]=="param"){
            if(!param)temp_string+="pushq %rax\npushq %rcx\npushq %rdx\npushq %rdi\npushq %rsi\npushq %r8\npushq %r9\npushq %r10\npushq %r11\nmovq %rsp, %rbx\nmovq %rsp, %rcx\naddq $-8, %rcx\nandq $15, %rcx\nsubq %rcx, %rsp\n";
            param=1;
            temp_string+="movq "+m[curr_function][a[1]]+", %rdx\n";
            temp_string+="pushq %rdx\n";
            continue;
        }
        if(a[0]=="stackpointer"&&a[1][0]=='-'){
            // cout<<a[1]<<endl;
            is_return=1;
            param=0;
            continue;
        }
        if(a[3]=="[]"&&a[1]=="="){
            temp_string+="movq "+m[curr_function][a[2]]+", %rcx\n";
            temp_string+="movq "+m[curr_function][a[4]]+", %rdx\n";
            temp_string+="addq %rdx, %rcx\n";
            temp_string+="movq (%rcx), %rdx\n";
            temp_string+="movq %rdx, "+m[curr_function][a[0]]+"\n";
            continue;
        }
        if(a[1]=="[]"&&a[3]=="="){
            temp_string+="movq "+m[curr_function][a[0]]+", %rcx\n";
            temp_string+="movq "+m[curr_function][a[2]]+", %rdx\n";
            temp_string+="addq %rdx, %rcx\n";
            temp_string+="movq "+m[curr_function][a[4]]+", %rdx\n";
            temp_string+="movq %rdx, (%rcx)\n";
            continue;
        }
        if(a[0][0]=='*'){
            string y="";
            for(int i=2;i<a[0].length()-1;i++){
                y+=a[0][i];
            }
            temp_string+="movq "+m[curr_function][y]+", %rdx\n";
            temp_string+="movq "+m[curr_function][a[2]]+", %rcx\n";
            temp_string+="movq %rcx, (%rdx)\n";
            continue;
        }
        if(a[3]==""&&a[1]=="="){
            temp_string+="movq "+m[curr_function][a[2]]+", %rdx\n";
            temp_string+="movq %rdx, "+m[curr_function][a[0]]+"\n";
            continue;
        }
        if(a[3]=="/"||a[3]=="//"){
            temp_string+="movq "+m[curr_function][a[2]]+", %rax\n";
            temp_string+="cdq\n";
            // temp_string+="movq "+m[curr_function][a[4]]+", %rdx\n";
            temp_string+="idivq "+m[curr_function][a[4]]+"\n";
            temp_string+="movq %rax, "+m[curr_function][a[0]]+"\n";
            continue;
        }
        if(a[3]=="%"){
            temp_string+="movq "+m[curr_function][a[2]]+", %rax\n";
            temp_string+="cdq\n";
            // temp_string+="movq "+m[curr_function][a[4]]+", %rdx\n";
            temp_string+="idivq "+m[curr_function][a[4]]+"\n";
            temp_string+="movq %rdx, "+m[curr_function][a[0]]+"\n";
            continue;
        }
        if(arith_oper(a[3])!=""){
            temp_string+="movq "+m[curr_function][a[2]]+", %rcx\n";
            temp_string+="movq "+m[curr_function][a[4]]+", %rdx\n";
            temp_string+=arith_oper(a[3])+" %rdx, %rcx\n";
            temp_string+="movq %rcx, "+m[curr_function][a[0]]+"\n";
            continue;
        }
        if(rel_oper(a[3])!=""){
            temp_string+="movq "+m[curr_function][a[2]]+", %rdx\n";
            temp_string+="movq "+m[curr_function][a[4]]+", %rcx\n";
            temp_string+="cmp %rcx, %rdx\n";
            temp_string+="movq $0, %rdx\n";
            temp_string+=rel_oper(a[3])+" %dl\n";
            temp_string+="movq %rdx, "+m[curr_function][a[0]]+"\n";
            continue;
        }
        if(a[0]=="if"){
            temp_string+="movq "+m[curr_function][a[1]]+", %rdx\n";
            temp_string+="cmp $1, %rdx\n";
            temp_string+="je "+a[3]+"\n";
            continue;
        }
        if(a[0]=="jump"){
            temp_string+="jmp "+a[1]+"\n";
            continue;
        }
    }
    // cout<<modifiedString<<endl;
    modifiedString+="print_int:\npushq %rbp\nmovq %rsp, %rbp\nmovq 16(%rbp), %rsi\nlea format_print_int(%rip), %rdi\nxorq %rax, %rax\ncallq printf@plt\nleave\nret\n";
    modifiedString+="print_bool:\npushq %rbp\nmovq %rsp, %rbp\nmovq 16(%rbp), %rcx\ncmp $0, %rcx\njne print_true_label\nlea format_print_false(%rip), %rdi\njmp print_false_exit\nprint_true_label:\nlea format_print_true(%rip), %rdi\nprint_false_exit:\nxorq %rax, %rax\ncallq printf@plt\nleave\nret\n";
    modifiedString+="print_str:\npushq %rbp\nmovq %rsp, %rbp\nmovq 16(%rbp), %rsi\nlea format_print_str(%rip), %rdi\nxorq %rax, %rax\ncallq printf@plt\nleave\nret\n";
    modifiedString+="mem_alloc:\npushq %rbp\nmovq %rsp, %rbp\nmovq 16(%rbp), %rdi\ncallq malloc\nleave\nret\n";
    modifiedString+="strcmpl:\npushq %rbp\nmovq %rsp, %rbp\nmovq 16(%rbp), %rdi\nmovq 24(%rbp), %rsi\ncallq strcmp\ncmp $0, %eax\nmovq $0, %rdx\nsetl %dl\nmovq %rdx, %rax\nleave\nret\n";
    modifiedString+="strcmpg:\npushq %rbp\nmovq %rsp, %rbp\nmovq 16(%rbp), %rdi\nmovq 24(%rbp), %rsi\ncallq strcmp\ncmp $0, %eax\nmovq $0, %rdx\nsetg %dl\nmovq %rdx, %rax\nleave\nret\n";
    modifiedString+="strcmpe:\npushq %rbp\nmovq %rsp, %rbp\nmovq 16(%rbp), %rdi\nmovq 24(%rbp), %rsi\ncallq strcmp\ncmp $0, %eax\nmovq $0, %rdx\nsete %dl\nmovq %rdx, %rax\nleave\nret\n";
    modifiedString+="strcmpne:\npushq %rbp\nmovq %rsp, %rbp\nmovq 16(%rbp), %rdi\nmovq 24(%rbp), %rsi\ncallq strcmp\ncmp $0, %eax\nmovq $0, %rdx\nsetne %dl\nmovq %rdx, %rax\nleave\nret\n";
    modifiedString+="strcmple:\npushq %rbp\nmovq %rsp, %rbp\nmovq 16(%rbp), %rdi\nmovq 24(%rbp), %rsi\ncallq strcmp\ncmp $0, %eax\nmovq $0, %rdx\nsetle %dl\nmovq %rdx, %rax\nleave\nret\n";
    modifiedString+="strcmpge:\npushq %rbp\nmovq %rsp, %rbp\nmovq 16(%rbp), %rdi\nmovq 24(%rbp), %rsi\ncallq strcmp\ncmp $0, %eax\nmovq $0, %rdx\nsetge %dl\nmovq %rdx, %rax\nleave\nret\n";
    modifiedString+=".power:\npushq %rbp\nmovq %rsp, %rbp\nsubq $-32, %rsp\nmovq $0, -24(%rbp)\nmovq $1, -32(%rbp)\njmp .L2\n.L3:\nmovq -32(%rbp), %rax\nimulq 16(%rbp), %rax\nmovq %rax, -32(%rbp)\naddq $1, -24(%rbp)\n.L2:\nmovq -24(%rbp), %rax\ncmpq 24(%rbp), %rax\njl .L3\nmovq -32(%rbp), %rax\nleave\nret\n";
    // Close the input file
    inputFile.close();

    // Prompt the user to enter the output filename
    string outputFilename;
    outputFilename=argv[2];

    // Open the output file
    ofstream outputFile(outputFilename);

    // Check if the output file is opened successfully
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file " << outputFilename << endl;
        return 1;
    }
    // Write the contents of the string to the output file
    outputFile << modifiedString;

    // Close the output file
    outputFile.close();

    return 0;
}