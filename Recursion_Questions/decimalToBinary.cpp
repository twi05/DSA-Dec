#include<iostream>
using namespace std;
int main(){
char ans[1000]; 
string answer;
int a = 40;

itoa(a,ans,2); 
cout<<"Binary- "<<ans<<endl;

answer = ans;
cout<<answer+'5'<<endl;

cout<<stoi(answer)+5;


return 0;
}