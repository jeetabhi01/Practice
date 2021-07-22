#include<bits/stdc++.h>
#include<stack>
#include<string>


//using namespace std;

class texteditor{
private:
    std::stack<char> leftstack, rightstack;
    void moveleft(size_t position);
    void moveright(size_t position);
public:
void insertcharacter(char );
void insertword(char word[]);
void movecursor(size_t position);
bool deletechar();
bool backspacechar();
void findandreplacechar(char findwhat, char replacewith);
void examinetop();
};

signed main(){
        int i =0;
        char text[80];
        texteditor txt;
        std::cout<<"Enter the word to be inserted : \n";
        std::cin.getline(text,80);
        txt.insertword(text);
        std::cout<<"Inserting word    \n";
        txt.examinetop();

        std::cout<<"Move the cursor to position 14\n";
        txt.movecursor(14);
        txt.examinetop();
        txt.movecursor(25);
        txt.examinetop();


    for(auto i = 0; i<3 ; i++){
        if(txt.deletechar())
        std::cout<<"There is nothing to delete in the stack\n";
        else
        txt.deletechar();
        txt.examinetop();
    }

        return 0;
}
void texteditor::insertcharacter(char x){
    leftstack.push(x);
    return;
}

void texteditor::insertword(char word[]){
    int i = 0;
    while(word[i]!= '\0'){
    insertcharacter(word[i]);
    i++;
    }
 return;
}

void texteditor::examinetop(){
    if(leftstack.empty())
    std::cout<<"The leftstack is empty\n";
    else
    std::cout<<"The element at the end of the stack is '"<<leftstack.top()<<"'\t"
    <<leftstack.size()<<"\n";
    if(rightstack.empty())
    std::cout<<"The rightstack is empty\n";
    else
    std::cout<<"The element at the end of the stack is '"<<rightstack.top()<<"'\n";
    return;

}

void texteditor::moveleft(size_t position){

    int leftsize;
    leftsize = leftstack.size();
    //rightsize = rightstack.size();
    while(position!=leftsize){
        rightstack.push(leftstack.top());
        leftstack.pop();
        leftsize--;
    }
}

void texteditor::moveright(size_t position){
    position = position-leftstack.size();
    int rightsize = rightstack.size();
    while(position!=rightsize){
    leftstack.push(rightstack.top());
    rightstack.pop();
    rightsize = rightstack.size();
    //position--;
    }
}

bool texteditor::backspacechar(){
    if(leftstack.empty())
    return false;
    else{
    leftstack.pop();
    return true;
    }
}

bool texteditor::deletechar(){
    if(rightstack.empty())
    return false;
    else{
    rightstack.pop();
    return true;
    }
}

void texteditor::findandreplacechar(char findwhat, char replacewith){
    int originialcurpos = leftstack.size();
    int count = 1;
    movecursor(0);
    while(!rightstack.empty()){
        if(findwhat==rightstack.top()){
        deletechar();
        insertcharacter(replacewith);
        }
        else
        movecursor(count);
        count++;
    }
movecursor(originialcurpos);
}


void texteditor::movecursor(size_t position){
    int count = 0;
  auto  leftsize = leftstack.size();
  auto rightsize = rightstack.size();
    if (position < leftsize){
        moveleft(position);
    }
    else{
    count = position - leftsize;
    moveright(position);
    }
}