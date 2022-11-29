// 13. Write a program to implement first-fit, best-fit and worst-fit allocation strategies.

#include <iostream>
using namespace std;

class MemoryManagementAlgo
{
public:
    int *block_size;
    int total_blocks;
    int *process_size;
    int total_process;
    MemoryManagementAlgo(int blkSize[], int tBlocks, int prSize[], int tProcess)
    {
        block_size = blkSize;
        total_blocks = tBlocks;
        process_size = prSize;
        total_process = tProcess;
    }
    void First_Fit()
    {
        int allocation[total_process];
        for (int i = 0; i < total_process; i++)
        {
            allocation[i] = -1;
        }

        for (int i = 0; i < total_process; i++)
        {
            for (int j = 0; j < total_blocks; j++)
            {
                if (block_size[j] >= process_size[i])
                {
                    allocation[i] = j;
                    block_size[j] -= process_size[i];
                    break;
                }
            }
        }
        cout << "Process No.\t\tProcess Size\t\tBlock no." << endl;
        for (int i = 0; i < total_process; i++)
        {
            cout << " " << i + 1 << " \t\t\t" << process_size[i] << " \t\t\t";
            if (allocation[i] != -1)
            {
                cout << allocation[i] + 1;
            }
            else
            {
                cout << "Not Allocated";
            }
            cout << endl;
        }
    }

    void Best_Fit()
    {
        int allocation[total_process];
        for (int i = 0; i < total_process; i++)
        {
            allocation[i] = -1;
        }

        for (int i = 0; i < total_process; i++)
        {
            // Find the best fit block for current process
            int bestIdx = -1;
            for (int j = 0; j < total_blocks; j++)
            {
                if (block_size[j] >= process_size[i])
                {
                    if (bestIdx == -1)
                    {
                        bestIdx = j;
                    }
                    else if (block_size[bestIdx] > block_size[j])
                    {
                        bestIdx = j;
                    }
                }
            }
            if (bestIdx != -1)
            {
                // allocate block j to p[i] process
                allocation[i] = bestIdx;
                // Reduce available memory in this block.
                block_size[bestIdx] -= process_size[i];
            }
        }
        cout << "Process No.\t\tProcess Size\t\tBlock no." << endl;
        for (int i = 0; i < total_process; i++)
        {
            cout << " " << i + 1 << " \t\t\t" << process_size[i] << " \t\t\t";
            if (allocation[i] != -1)
            {
                cout << allocation[i] + 1;
            }
            else
            {
                cout << "Not Allocated";
            }
            cout << endl;
        }
    }

    void Worst_Fit()
    {
        int allocation[total_process];
        for (int i = 0; i < total_process; i++)
        {
            allocation[i] = -1;
        }

        for (int i = 0; i < total_process; i++)
        {
            // Find the best fit block for current process
            int worstIdx = -1;
            for (int j = 0; j < total_blocks; j++)
            {
                if (block_size[j] >= process_size[i])
                {
                    if (worstIdx == -1)
                    {
                        worstIdx = j;
                    }
                    else if (block_size[worstIdx] < block_size[j])
                    {
                        worstIdx = j;
                    }
                }
            }
            if (worstIdx != -1)
            {
                // allocate block j to p[i] process
                allocation[i] = worstIdx;
                // Reduce available memory in this block.
                block_size[worstIdx] -= process_size[i];
            }
        }
        cout << "Process No.\t\tProcess Size\t\tBlock no." << endl;
        for (int i = 0; i < total_process; i++)
        {
            cout << " " << i + 1 << " \t\t\t" << process_size[i] << " \t\t\t";
            if (allocation[i] != -1)
            {
                cout << allocation[i] + 1;
            }
            else
            {
                cout << "Not Allocated";
            }
            cout << endl;
        }
    }
};

int main()
{
    /*
    blkSize - Array to store Block Sizes
    prcSize - Array to store Process Size
    tblocks - Total number of blocks
    tprc - Total number of process
    */

    int tblocks, tprc;
    cout << "Enter the number of blocks available ::: ";
    cin >> tblocks;

    int blkSize[tblocks];
    cout << "Enter block sizes :::" << endl;
    for (int i = 0; i < tblocks; i++)
    {
        cout << i + 1 << " - ";
        cin >> blkSize[i];
    }

    cout << "Enter the number of processes available ::: ";
    cin >> tprc;

    int prcSize[tprc];
    cout << "Enter process sizes :::" << endl;
    for (int i = 0; i < tprc; i++)
    {
        cout << i + 1 << " - ";
        cin >> prcSize[i];
    }

    cout << "\nEnter choice : \n1 - First Fit \n2 - Best Fit \n3 - Worst Fit\n";
    int choice;
    cin >> choice;
    MemoryManagementAlgo ob(blkSize, tblocks, prcSize, tprc);
    switch (choice)
    {
    case 1:
    {
        cout << "Your choice : First Fit" << endl;
        ob.First_Fit();
        break;
    }
    case 2:
    {
        cout << "Your choice : Best Fit" << endl;
        ob.Best_Fit();
        break;
    }
    case 3:
    {
        cout << "Your choice : Worst Fit" << endl;
        ob.Worst_Fit();
        break;
    }
    default:
    {
        cout << "Invalid choice" << endl;
        break;
    }
    }

    return 0;
}
