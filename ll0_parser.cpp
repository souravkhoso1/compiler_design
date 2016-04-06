#include<iostream>
#include<stack>
#include<cstring>
#include<cstdio>
#define MAXSTACKSIZE 10  // Change maximum element the stack may be holding here 
#define TABLEROW 1       // Change number of rows (excluding headers) in parsing table here 
#define TABLECOLUMN 3    // Change number of columns (excluding headers) in parsing table here 
#define TABLECELL 10     // Change Maximum Number of elements each cell of parsing table will hold 
using namespace std;

int sizof(char *a){
    int i=0;
    while(*(a+i) != '\0'){
        i++;
    }
    return i;
}

int main(){
    stack<char> st;
    st.push('$');
    st.push('S');
    int flagerror=0;    
    int i=0,j=0;
    int p,q,r;
    string input;
    char c;
    char t[20],u[10];
    char array[TABLEROW+1][TABLECOLUMN+1][TABLECELL] = { // Enter the parsing table here 
                 " ", "(",")","$",
                 "S", "(S)","E","E"
                  };
    cout << "\n\tLL(1)  PARSER  TABLE \n\n";
    for(i=0;i<TABLEROW+1;i++)
    {
        for(j=0;j<TABLECOLUMN+1;j++)
        {
            cout.setf(ios::right);
            cout.width(TABLECELL);
            cout<<array[i][j];
        }
        cout<<endl;
    }
    cout << endl;
    i=0;
    cout << "\nEnter the string(enter '$' at end): " ;
    cin >> c;
    while(1){
        if(c == '$'){
            t[i] = '\0';
            break;
        } else{
            t[i] = c;
            i++;
            cin >> c;
        } 
    }
    cout << "\n\n ------------------------- STACK IN ACTION -------------------------------\n\n";
    j=0;
    /*for(int x=0;x<MAXSTACKSIZE-5;x++){ cout << "  ";} cout<<"STACK";
    cout << "\t";
    for(int x=0;x<2*i-5;x++){ cout << "  ";}cout<<"INPUT\n\n";*/
    
    
    for(int z=0;z<MAXSTACKSIZE-st.size();z++){
        cout << "  " ;
    }   
    for(stack<char> dump = st; !dump.empty(); dump.pop())
        cout << dump.top() << " ";
    cout << "\t";   
    for(int y=0;y<i;y++){ cout << t[y] << " ";}
    cout << "$" << endl; 
    
    while(1){
        if(j == i) { break;}
        if(st.top() == '$' && j<i){ flagerror=1; break; }
        
        if(st.top() == t[j]){
            st.pop();
            j++;
            //cout << "ok11\n";
        } else {
            //cout << "ok11\n";
            for(p=0;;p++){
                if(array[0][p][0] == t[j]){
                    break;
                }
                //cout << "ok1\n";
            }
            for(q=0;;q++){
                if(array[q][0][0] == st.top()){
                    break;
                }
                //cout << "ok2\n";
            }
            st.pop();
            if(array[p][q][0] == 'E'){
                //cout << "ok4\n";
            } else if(array[p][q][0] == ' ') {
                flagerror = 1;
                //cout << "ok5\n";
                goto end;
            } else {
                for(r=sizof(array[p][q]);r>0;r--){
                    //cout << r;
                    st.push(array[p][q][r-1]);
                }
            }
            
        }
        for(int z=0;z<MAXSTACKSIZE-st.size();z++){
            cout << "  " ;
        }
        
        for (stack<char> dump = st; !dump.empty(); dump.pop())
            cout << dump.top() << " ";
            
        cout << "\t";
        
        for(int x=0;x<j;x++){ cout << "  ";}
        for(int y=j;y<i;y++){ cout << t[y] << " ";}
        cout << "$" << endl; 
    }
    end:
    if(st.top() != '$') flagerror = 1;
    if(flagerror == 1){
        cout << "Input string not accepted\n";
    } else {
        cout << "\nInput string accepted\n";
    }
    cout << "\n\n ------------------------PROGRAM ENDED-------------------\n\n";
    return 0;
}

