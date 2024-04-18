#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;

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
    }
    string modifiedString;
    int lino=1;
    set<int>breaks;
    map<int,int>jumps;
    map<int,int>regs;
    for (string s : content) {
        if(s==""){lino++; continue;}
        vector<string>a;
        string temp="";
        for(char ch:s){
            if(ch==' '){
                a.push_back(temp);
                temp="";
            }else{
                temp+=ch;
            }
        }
        a.push_back(temp);
        for(auto x : a){
            if(x.size()>2){
                if(x[0]=='#' && x[1]=='r') {
                    string temp=x;
                    temp[0]='0';
                    temp[1]='0';
                    char * num = new char[temp.size()];
                    strcpy(num, temp.c_str());
                    regs[atoi(num)]++;
                }
            }
        }
        if(a.size()>4 && a[2]=="jump" && a[3]=="line"){
            char * num = new char[a[4].size()];
            strcpy(num, a[4].c_str());
            breaks.insert(atoi(num));
            jumps.insert({lino,atoi(num)});
        }
        if(a.size()>2 && a[0]=="jump" && a[1]=="line"){
            char * num = new char[a[2].size()];
            strcpy(num, a[2].c_str());
            breaks.insert(atoi(num));
            jumps.insert({lino,atoi(num)});
        }
        lino++;
    }
    int i=4;
    map <int,int> ind;
    for(auto x:breaks){
        ind.insert({x,i});
        i++;
    }
    // for(auto x:regs){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
    i=1;
    for(auto s : content){
        string c;
        if(breaks.count(i)){
        modifiedString+=(".L"+to_string(ind[i])+" :\n");
        }
        vector<string>a;
        string temp="";
        for(char ch:s){
            if(ch==' '){
                a.push_back(temp);
                temp="";
            }else{
                temp+=ch;
            }
        }
        a.push_back(temp);
        if(a[0].size()>2){
            if(a[0][0]=='#' && a[0][1]=='r') {
                string temp=a[0];
                temp[0]='0';
                temp[1]='0';
                char * num = new char[temp.size()];
                strcpy(num, temp.c_str());
                if(regs[atoi(num)]==1) {i++; continue;}
            }
        }
        if(jumps.count(i)){
            
            if(a.size()>4 && a[2]=="jump" && a[3]=="line"){
                a[3]=".L"+to_string(ind[jumps[i]])+"\n";
                c=a[0]+' '+a[1]+' '+a[2]+' '+a[3];
            }
            if(a.size()>2 && a[0]=="jump" && a[1]=="line"){
                a[1]=".L"+to_string(ind[jumps[i]])+"\n";
                c=a[0]+' '+a[1];
            }
        }
        else c=s+"\n";
        // cout<<s<<'@'<<c<<'\n';
        modifiedString+=c;
        i++;
    }

    // Close the input file
    inputFile.close();
    
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