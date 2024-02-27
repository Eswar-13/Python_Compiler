%{
#include <bits/stdc++.h>
using namespace std;
int questionCount = 0;
int singleSelectCount = 0;
int multiSelectCount = 0;
int choiceCount = 0;
int correctCount = 0;
int totalMarks = 0;
int prev_num=0;
int marks=0;
extern int start;
int marksCount[9] = {0};  // Index 1 represents 1 mark, Index 2 represents 2 marks, and so on.

extern int yyparse();
extern int yylex();
int yyerror(const char* s);
extern int yylineno;
extern char* yytext;
stack<pair<string,pair<int,int>>>s;
int convert(string s){
    int x=0;
    int c=0;
    for(int i=0;i<s.length();i++){
        if(c==0&&s[i]=='"')c=1;
        else if(c==1&&s[i]=='"'){
            c++;
            break;
        }
        else if(c==1&&s[i]>='0'&&s[i]<='9')x=x*10+(s[i]-'0');
    }
    if(c!=2) return -1;
    return x;
}
%}



%token T_QUIZ_OPEN T_QUIZ_CLOSE T_SINGLESELECT_CLOSE T_MULTISELECT_CLOSE T_CHOICE_OPEN T_CHOICE_CLOSE T_CORRECT_OPEN T_CORRECT_CLOSE T_SINGLESELECT_OPEN T_MULTISELECT_OPEN

%start quiz

%%

quiz: QO quiz_content T_QUIZ_CLOSE {
    s.pop();
}
;
QO: T_QUIZ_OPEN {
    s.push({yytext,{start,T_QUIZ_CLOSE}});
}
;
quiz_content: question quiz_content {
    questionCount++;
}
|

;
question: singleselect_question {
    singleSelectCount++;
}

| multiselect_question {
    multiSelectCount++;
}
;

singleselect_question: S_Open choice T_SINGLESELECT_CLOSE {
    if(choiceCount-prev_num<3||choiceCount-prev_num>4){
        yyerror("few");
        return 0;
    }
    s.pop();
    marksCount[marks]++;
    totalMarks += marks;
}   
;
S_Open: T_SINGLESELECT_OPEN {
    prev_num=choiceCount;
    string r=yytext;
    marks = convert(r);
    s.push({yytext,{start,T_SINGLESELECT_CLOSE}});
    if(marks==-1){
        yyerror("quote");
        return 0;
    }
    if(marks<1||marks>2){
        yyerror("marks");
        return 0;
    }
}
multiselect_question: M_Open choice T_MULTISELECT_CLOSE {
    if(choiceCount-prev_num<3||choiceCount-prev_num>4){
        yyerror("few");
        return 0;
    }
    s.pop();
    marksCount[marks]++;
    totalMarks += marks;
    
}
;
M_Open: T_MULTISELECT_OPEN {
    prev_num=choiceCount;
    string r=yytext;
    marks = convert(r);
    s.push({yytext,{start,T_MULTISELECT_CLOSE}});
    if(marks==-1){
        yyerror("quote");
        return 0;
    }
    if(marks<2||marks>8){
        yyerror("marks");
        return 0;
    }
}
choice: t_choice choice
| t_correct choice
|
;
t_choice: ChO T_CHOICE_CLOSE {
    choiceCount++;
    s.pop();
}
;
ChO: T_CHOICE_OPEN {
    s.push({yytext,{start,T_CHOICE_CLOSE}});
}
;
t_correct: CoO T_CORRECT_CLOSE {
    correctCount++;
    s.pop();
}
CoO: T_CORRECT_OPEN {
    s.push({yytext,{start,T_CORRECT_CLOSE}});
}
;
%%
int yyerror(const char* msg)
{
    if(msg=="few"){
        cout<<"Error: there are too few or too many choices on Question from line no."<<s.top().second.first<<endl;
    }
    else if(msg=="quote"){
        cout<<"Error: the attribute marks is not enclosed in double-quotes in tag in line no."<<s.top().second.first<<endl;
    }
    else if(msg=="marks"){
        cout<<"Error: Marks is is out of range in tag in line no."<<s.top().second.first<<endl;
    }
    else if(yychar==T_CHOICE_CLOSE||yychar==T_CORRECT_CLOSE||yychar==T_MULTISELECT_CLOSE||yychar==T_SINGLESELECT_CLOSE||yychar==T_QUIZ_CLOSE){
        string at_top=s.top().first;
        int lineno=s.top().second.first;

        while(!s.empty()){
            if(s.top().second.second==yychar){
                cout<<"Error: No Closing tag for "<<at_top<<" in line no."<<lineno<<endl;
                return 0;
            }
            s.pop();
        }
        cout<<"Error: No Opening tag for "<<yytext<<" in line no."<<start<<endl;
    }
    else if(yychar==T_CHOICE_OPEN||yychar==T_CORRECT_OPEN||yychar==T_MULTISELECT_OPEN||yychar==T_SINGLESELECT_OPEN||yychar==T_QUIZ_OPEN){
        cout<<"Error: No Closing tag for "<<s.top().first<<" in line no."<<start<<endl;
    }
    return 0;

}
int main() {
    yyparse();
    cout << "Number of questions: " << questionCount << endl;
    cout << "Number of singleselect questions: " << singleSelectCount << endl;
    cout << "Number of multiselect questions: " << multiSelectCount << endl;
    cout << "Number of answer choices: " << choiceCount << endl;
    cout << "Number of correct answers: " << correctCount << endl;
    cout << "Total marks: " << totalMarks << endl;
    for (int i = 1; i <= 8; i++) {
        cout << "Number of " << i << " mark questions: " << marksCount[i] << endl;
    }
    return 0;
}
