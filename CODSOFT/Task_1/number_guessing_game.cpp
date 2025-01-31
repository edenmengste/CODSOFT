#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    
    srand(time(0));

    // Generate random number between 1 and 10
    int randomNumber = rand()% 10 + 1;

    int guess;
  

    cout << "Guess the number between 1 and 10: ";

    while (true) {
        cin >> guess;
        if(guess>10 || guess<1){
            cout<<"Please enter a number between 1 and 10: ";
        } else if (guess < randomNumber) {
            cout << "Too low. Try again: ";
        } else if (guess > randomNumber) {
            cout << "Too high. Try again: ";
        } else {
            cout << "Congratulations! You guessed the correct number." << endl;
         break;
        }
    }

    return 0;
}