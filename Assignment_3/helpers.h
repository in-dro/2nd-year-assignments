#ifndef HELPERS_H
#define HELPERS_H

class Person {
    public:
        int position;           // Variable to store poistion of a person in the circle
        Person *NextPerson;         // Used to point to the next person in the circle
        Person(int position){
            this->position = position;
            this->NextPerson = NULL;
        }
};

// Creates a circle by taking in first person object and number of people as the input
void CreateCircle(Person &p1, int n){
    // Initially PreviousPerson points to the first person as there is only 1 person
    Person *PreviousPerson = &p1;
    // Loop to add all participants to the circle
    for(int i=2; i<=n; ++i){
        // Create a new person to be added to the circle
        Person *NewPerson = new Person(i);
        // Connect the previous person to the next person in the circle
        PreviousPerson->NextPerson = NewPerson;
        PreviousPerson = NewPerson;
    }
    // Connect the last person in the circle to the first person
    PreviousPerson->NextPerson = &p1;
}

// Removes a person from the circle
void evict(Person *&PreviousPerson, Person *&CurrentPerson){
    PreviousPerson->NextPerson = CurrentPerson->NextPerson;
    CurrentPerson = CurrentPerson->NextPerson;

    // Delete the previous person
    PreviousPerson = NULL;
    delete PreviousPerson;
}

#endif