// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

string reverseString(string s)
{
    string result;
    s.insert(0, " ");
    int breakpoint = 0;
 
     for(int i = 1; i <= s.length(); i++) {
        char c = s[i];
        
        if (c == ' ' || c == '\0') { 
           
            for(int k=i-1; k>breakpoint; k--){
                char j = s[k];
                if (k == i-1) { result += toupper(j);}
               
                else{result += tolower(j);};
                
        };
        
        breakpoint = i;
        result += " ";
     };

     };
  
   
    return result;
}



void programmInfoBox(){
    cout<<"Revserse String"<<endl;
    cout<<"Enter String as Input. Any string is possible, but be aware that special characters may cause problems!"<<endl;
    cout <<"Enter 'exit()' to terminate the programm"<<endl;

}


string inputHandler() {
    cout<<"\nEnter new string:"<<endl;
    string newString;
    if (getline(cin, newString)) {
        return(newString);
    } else {
        cout<<"Unspecified Error occured. Programm will terminate now";
        return (0);}
    return(0);
}






int main() {

    programmInfoBox();
    while(1){
        string newInputStr = inputHandler();
        if (newInputStr == "exit()") {break;};
        cout<<reverseString(newInputStr) <<endl;;

    }
}