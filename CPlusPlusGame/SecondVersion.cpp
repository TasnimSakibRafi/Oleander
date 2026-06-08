#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    string my;
    string comp;
    int random;

    cout << "Enter Your Choice : ";
    cin >> my;

    srand(time(0));
    random = rand() % 3;

    if (random == 0) {
        comp = "Rock";
    } else if (random == 1) {
        comp = "Paper";
    } else {
        comp = "Scissor";
    }

    if (my == comp) {
        cout << "Its a tie Play Once More To Win!";
    } else if ((my == "Rock" && comp == "Paper") ||
     (my == "Scissor" && comp == "Rock") || 
     (my == "Paper" && comp == "Scissor")) {
        cout << "Computer Win!";
    }
    else if ((my == "rock" && comp == "Paper")||(my == "scissor" && comp == "Rock")||(my == "Paper" && comp == "Scissor")) {
         cout << "Computer Win!";
    }
    else {
        cout << "You Win!";
    }

    return 0;
}


// Discontinued Game !!!!!!!!!!!!
