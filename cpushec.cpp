#include <iostream>
#include <string.h>
using namespace std;
int main()
{

int n;
cout<<"Enter how many process you want to enter?"<<endl;
cin>>n;
int arr[n];
//cout<<"Enter Brust Time"<<endl;

for(int i=0;i<n;i++){
cout<<"Enter Burst Time for "<<i<<": ";
cin>>arr[i];
}
cout<<endl;
cout<<"Process"<<"\t\t"<<"Brust Time"<<endl;
for(int i=0;i<n;i++){
cout<<i<<"\t\t";
cout<<arr[i]<<endl;
}
int bst[n];
int sum=0;
for(int i=0;i<n;i++){
sum+=arr[i];
bst[i]=sum;
}

cout<<"\n"<<endl;
//cout<<"Brust Table\n\n";
//for(int i=0;i<n;i++){
//cout<<bst[i]<<"  ";
//}


cout<<"Process"<<"\t\t"<<"Burst Time"<<"\t\t"<<"Completion Time"<<"\t\t"<<"XYZ TIME"<<endl;
for(int i=0;i<n;i++){
cout<<i<<"\t\t";
cout<<arr[i]<<"\t\t\t"<<bst[i]<<"\t\t\t"<<bst[i]-arr[i]<<endl;
}
cout<<"\n\n";
}
