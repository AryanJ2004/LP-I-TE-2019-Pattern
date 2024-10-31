#include <iostream>
using namespace std;

int main(){
    cout<<"Round Robin Scheduling\n";
    int n,avg_wt=0,avg_tat=0;
    cout << "Enter the number of processes: ";
    cin >> n;
    int bt[n], wt[n], tat[n];
    cout << "Enter the burst time of each process: ";
    for(int i=0; i<n; i++){
        cin >> bt[i];
    }
    int quantum;
    cout << "Enter the quantum: ";
    cin >> quantum;
    int rem_bt[n];
    for(int i=0; i<n; i++){
        rem_bt[i] = bt[i];
    }
    int t=0;
    while(true){
        bool done = true;
        for(int i=0; i<n; i++){
            if(rem_bt[i] > 0){
                done = false;
                if(rem_bt[i] > quantum){
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else{
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if(done){
            break;
        }
    }
    for(int i=0; i<n; i++){
        tat[i] = bt[i] + wt[i];
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