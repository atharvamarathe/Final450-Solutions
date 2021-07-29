/*  Following code is written by RASHI GUPTA (GFG username: guptarashi2001)  */

// Program for SJF(shortest job first) CPU Scheduling
// This is a non-preemptive scheduling

#include <bits/stdc++.h>
using namespace std;

// Structure for Process in RAM
class process {
    public:
        int id;
        int arrival_time;
        int burst_time;
        int completion_time;
        int waiting_time;
};

bool sortByArrival (process a, process b) {
    return a.arrival_time<b.arrival_time;
}

bool sortById (process a, process b) {
    return a.id<b.id;
}

// to set priority_queue comparision criteria as burst_time
class compare {
    public:
    bool operator() (process* a, process* b) {
        return a->burst_time > b->burst_time;
    }
};

int main()
{
    int n;
    cout << "Enter no of processes: ";
    cin >> n;

    process p[n];
    cout << "\nEnter burst and arrival time for " << n << " processes: \n";
    for (int i = 0; i < n; i++)
    {
        p[i].id = i+1;
        cout<< "Process "<<i+1<<" :\nArrival time- ";
        cin >> p[i].arrival_time;
        cout<<"Burst time- ";
        cin>> p[i].burst_time;
        cout<<endl;
    }

    sort(p, p + n, sortByArrival);

    priority_queue<process*, vector<process*>, compare> readyQueue;   // min heap based on burst_time
    int timeElapsed = 0, processesLeft = n, toBeInserted=0, i;
    
    // Executing all processes
    while (processesLeft) {

        for (i = toBeInserted; i<n && p[i].arrival_time <= timeElapsed; i++) {
            readyQueue.push(p+i);         // adding process to ready queue
        }
        toBeInserted = i;

        // finding the process to execute in the ready queue
        if (readyQueue.empty()) {       // ready queue is empty

            timeElapsed = p[toBeInserted].arrival_time;
        } else {

            process* processToExecute = readyQueue.top();
            
            (*processToExecute).waiting_time = timeElapsed - (*processToExecute).arrival_time;
            timeElapsed += processToExecute->burst_time;
            (*processToExecute).completion_time = timeElapsed;

            readyQueue.pop();         // removing process from ready queue
            processesLeft--;            // reducing the number of process left to execute
        }
    }

    sort(p, p+n, sortById);

    // printing values
    double avgWaitingTime = 0;
    printf("    Process \t Arrival Time \t Burst Time \t Waiting Time \t Completion Time\n\n");
    for (int i = 0; i < n; i++) {

        cout<<"\t"<<p[i].id<<"\t\t"<<p[i].arrival_time<<"\t\t"<<p[i].burst_time<<"\t\t"<<p[i].waiting_time<<"\t\t"<<p[i].completion_time<<endl;
        avgWaitingTime += p[i].waiting_time;
    }
    avgWaitingTime /= n;

    cout<<"\nAverage waiting time: "<<avgWaitingTime;
    return 0;
}