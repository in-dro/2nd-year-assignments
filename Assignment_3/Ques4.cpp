#include <iostream>
#include "helpers.h"
using namespace std;

int main(){
    Person p1(1), *PreviousPerson = NULL, *CurrentPerson = &p1;
    int n;
    bool FoundWinner = false;
    int winner;
    const int skip=2; // Predefined value
    cout << "Enter n: ";
    cin >> n;
    CreateCircle(p1, n);
    // Loop through the circle till a winner is found
    while(!FoundWinner){
        // Loop through the circle to skip some members and the find the person to be evicted
        for(int i=0;i<skip;++i){
            PreviousPerson = CurrentPerson;
            CurrentPerson = CurrentPerson->NextPerson;
        }
        // Evict the person
        evict(PreviousPerson, CurrentPerson);
        // Check if there is only one person remaining in the circle
        if(CurrentPerson->NextPerson == CurrentPerson){
            FoundWinner = true;
            winner = CurrentPerson->position;
            cout << "Winner: " << winner << endl;
        }
    }
    return 0;
}