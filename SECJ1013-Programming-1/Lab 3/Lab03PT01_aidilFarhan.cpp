#include <iostream>
#include <string>
using namespace std;

void dispStatus(int activeCase);
void getInput(int &totalCase, int &newCase, int &totalDeath, int &totalRecovered);
void dispOutput(int activeCase);
int calcAverage(int states, int totalCase);

int main() {
    char continueChoice;
    string stateName, highestStateName;
    int totalCase, newCase, totalDeath, totalRecovered;
    int activeCase, highestActiveCase = 0, totalActiveAllStates = 0, stateCount = 0;
    
    do {
        cout << "<<<<<<<<<<<<<<<< DATA >>>>>>>>>>>>>>>" << endl;
        cout << "State name\t: ";
        cin >> stateName;
        
        getInput(totalCase, newCase, totalDeath, totalRecovered);
        
        activeCase = totalCase + newCase - totalDeath - totalRecovered;
        
        dispOutput(activeCase);
        
        stateCount++;
        totalActiveAllStates += activeCase;

        if (activeCase > highestActiveCase) {
            highestActiveCase = activeCase;
            highestStateName = stateName;
        }
        
        // Ask if user wants to continue
        cout << "Press <ENTER> to continue...";
        cin.ignore(); // Clear input buffer
        continueChoice = cin.get();
        
    } while (continueChoice != 'N' && continueChoice != 'n');

    cout << endl << "<<<<<<<<< ACTIVE CASES >>>>>>>>>>>>" << endl;
    cout << "Total : " << totalActiveAllStates << endl;
    cout << "Highest: " << highestActiveCase << " (" << highestStateName << ")" << endl;
    cout << "Average for " << stateCount << " states: " << calcAverage(stateCount, totalActiveAllStates) << endl;
    
    return 0;
}

void dispStatus(int activeCase) {
    cout << "Status\t: ";
    if (activeCase > 40) 
        cout << "Red zone" << endl;
    else if (activeCase >= 21 && activeCase <= 40)
        cout << "Orange zone" << endl;
    else if (activeCase >= 1 && activeCase <= 20)
        cout << "Yellow zone" << endl;
    else
        cout << "Green zone" << endl;
}

void getInput(int &totalCase, int &newCase, int &totalDeath, int &totalRecovered) {
    cout << "Total cases\t: ";
    cin >> totalCase;
    cout << "New cases\t: ";
    cin >> newCase;
    cout << "Total death\t: ";
    cin >> totalDeath;
    cout << "Total recovered\t: ";
    cin >> totalRecovered;
}

void dispOutput(int activeCase) {
    cout << endl << "<<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>>>>" << endl;
    cout << "Active cases\t: " << activeCase << endl;
    dispStatus(activeCase);
}

int calcAverage(int states, int totalCase) {
    return totalCase / states;
}