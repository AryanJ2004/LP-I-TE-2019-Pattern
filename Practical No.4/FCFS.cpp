#include <iostream>
using namespace std;


int main(){
    int n,avg_wt=0,avg_tat=0;
    cout << "Enter the number of processes: ";
    cin >> n;
    int bt[n], wt[n], tat[n];
    cout << "Enter the burst time of each process: ";
    for(int i=0; i<n; i++){
        cin >> bt[i];
    }
    wt[0] = 0; //waiting time for the first process is 0
    for(int i=1; i<n; i++){
        wt[i] = wt[i-1] + bt[i-1];
    }
    for(int i=0; i<n; i++){
        tat[i] = wt[i] + bt[i];
    }
    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for(int i=0; i<n; i++){
        cout << i+1 << "\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\n";
    }
    for(int i=0; i<n; i++){
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    cout << "Average Waiting Time: " << (float)avg_wt/n << "\n";
    cout << "Average Turnaround Time: " << (float)avg_tat/n << "\n";

}