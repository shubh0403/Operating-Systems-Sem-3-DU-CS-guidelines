/*
9. Write a program to implement non-preemptive priority based scheduling algorithm.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Process
{
	int pID;
	int priority;
	float arrivalTime;
	float burstTime;
	float completionTime;
	float waitingTime;
	float turnAroundTime;
};

void swapProcess(struct Process *a, struct Process *b)
{
	struct Process temp = *a;
	*a = *b;
	*b = temp;
}

void sortForExec(struct Process *p, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		if (p[i].arrivalTime > p[i + 1].arrivalTime)
		{
			swapProcess(&p[i], &p[i + 1]);
		}
		else if (p[i].arrivalTime == p[i + 1].arrivalTime)
		{
			if (p[i].priority > p[i + 1].priority)
				swapProcess(&p[i], &p[i + 1]);
			else if (p[i].priority == p[i + 1].priority)
			{
				if (p[i].pID > p[i + 1].pID)
					swapProcess(&p[i], &p[i + 1]);
			}
		}
	}
	return;
}

void sortAccPID(struct Process *p, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		if (p[i].pID > p[i + 1].pID)
		{
			swapProcess(&p[i], &p[i + 1]);
		}
	}
	return;
}

void calcCompletionTime(struct Process *p, int n)
{
	p[0].completionTime = p[0].burstTime;
	for (int i = 1; i < n; ++i)
	{
		p[i].completionTime = p[i - 1].completionTime + p[i].burstTime;
	}
	return;
}

void calcTurnAroundTime(struct Process *p, int n)
{
	for (int i = 0; i < n; ++i)
	{
		p[i].turnAroundTime = p[i].completionTime - p[i].arrivalTime;
	}
	return;
}

void calcWaitingTime(struct Process *p, int n)
{
	for (int i = 0; i < n; ++i)
	{
		p[i].waitingTime = p[i].turnAroundTime - p[i].burstTime;
	}
	return;
}

void printAvgTime(struct Process *p, int n)
{
	sortForExec(p, n);
	calcCompletionTime(p, n);
	sortAccPID(p, n);
	calcTurnAroundTime(p, n);
	calcWaitingTime(p, n);

	// Printing Process Info
	cout << " Non-preemptive Priority Based CPU Scheduling" << endl;
	cout << " ------------------------------------------------" << endl;
	cout << "\n process -> { priority, arrivalTime, burstTime, completionTime, turnAroundTime, waitingTime }\n";
	for (int i = 0; i < n; ++i)
	{
		cout << " P" << p[i].pID << "      -> { " << p[i].priority << " , " << p[i].arrivalTime << " , " << p[i].burstTime << " , " << p[i].completionTime << " , " << p[i].turnAroundTime << " , " << p[i].waitingTime << " }\n";
	}

	// Calculating sum of waitingTime and turnAroundTime
	float sumW = 0.0;
	float sumT = 0.0;
	for (int i = 0; i < n; ++i)
	{
		sumW += p[i].waitingTime;
		sumT += p[i].turnAroundTime;
	}

	// Printing average waitingTime and turnAroundTime
	cout << "\n Average Waiting Time: " << sumW / n;
	cout << "\n Average Turn Around Time: " << sumT / n << endl;

	return;
}

int main()
{
	int n;

	cout << "\n Enter number of Processes: ";
	cin >> n;
	cout << endl;

	struct Process p[n];
	for (int i = 0; i < n; ++i)
	{
		p[i].pID = i + 1;
		cout << " Enter Priority of Process " << i + 1 << ": ";
		cin >> p[i].priority;
		cout << " Enter Arrival Time of Process " << i + 1 << ": ";
		cin >> p[i].arrivalTime;
		cout << " Enter Burst Time of Process " << i + 1 << ": ";
		cin >> p[i].burstTime;
		cout << endl;
	}

	printAvgTime(p, n);
	cout << endl;

	return 0;
}