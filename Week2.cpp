#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MIN_SENIORS = 10;
const int MAX_SENIORS = 36;
const int CARERS_BASE = 2;
const int CARERS_THRESHOLD = 24;

void task1(int& totalSeniors, float& totalCost, float& costPerPerson) {
    cout << "Enter the number of senior citizens for the outing: ";
    cin >> totalSeniors;

    if (totalSeniors < MIN_SENIORS || totalSeniors > MAX_SENIORS) 
    {
        cerr << "Error: Invalid number of senior citizens. The outing cannot proceed.\n";
        exit(0);
    }

    int carers = CARERS_BASE + (totalSeniors > CARERS_THRESHOLD ? 1 : 0);

    if (totalSeniors >= 12 && totalSeniors <= 16) 
    {
        totalCost = 150 + carers * 0;  // 0 cost for carers
        costPerPerson = totalCost / (totalSeniors + carers);
    }
    else if (totalSeniors >= 17 && totalSeniors <= 26) 
     {
        totalCost = 190 + carers * 0;
        costPerPerson = totalCost / (totalSeniors + carers);
    } 
    else if (totalSeniors >= 27 && totalSeniors <= 39) 
    {
        totalCost = 225 + carers * 0;
        costPerPerson = totalCost / (totalSeniors + carers);
    }
}

void task2(int totalSeniors, float costPerPerson, float& totalCollected) {
    vector<string> name(totalSeniors);
    vector<float> amount(totalSeniors);

    // Record names and amounts paid for each participant
    for (int i = 0; i < totalSeniors; i++) 
    {
        cout << "Enter the name of senior citizen " << i + 1 << ": ";
        cin >> name[i];
        cout << "Enter the amount paid by " << name[i] << ": $";
        cin >> amount[i];
    }

    // Print list of people on the outing and total amount collected
    cout << "\nList of people on the outing:\n";
    for (int i = 0; i < totalSeniors; i++) 
    {
        cout << name[i] << " - Amount Paid: $" << amount[i] << "\n";
        totalCollected += amount[i];
    }

    cout << "\nTotal amount collected: $" << totalCollected << "\n";
}

void task3(float totalCost, float totalCollected) {
    
    if (totalCollected >= totalCost) 
    {
        float profit = totalCollected - totalCost;
        cout << "\nThe outing has made a profit of $" << profit << ".\n";
    } 
    else {
        cout << "\nThe outing has broken even. No profit made.\n";
    }
}

int main() {
    int totalSeniors;
    float totalCost, costPerPerson, totalCollected;

    // Task 1
    task1(totalSeniors, totalCost, costPerPerson);

    // Task 2
    task2(totalSeniors, costPerPerson, totalCollected);

    // Task 3
    cout << "\nTask 3:\n";
    task3(totalCost, totalCollected);
    cout << endl;

    return 0;
}
