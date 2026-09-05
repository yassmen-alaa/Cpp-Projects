#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class NumberGuessingGame {
private:
    int number;
    int count;
    int answer;

    int getValidNumber() {
        int input;
        cin >> input;

        while (input < 0 || input > 50) {
            cout << "Invalid input! Please enter a number between 0 and 50: ";
            cin >> input;
        }

        return input;
    }

public:
    NumberGuessingGame() {
        count = 5;
        srand(time(0));
        answer = rand() % 50 + 1;
    }

    void start() {
        cout << "welcome to the number guessing game" << endl;
        cout << "you have 5 chances to guess the number between 1 and 50" << endl;

        for (int i = 0; i < count; i++) {
            cout << "guess #: " << i + 1 << endl;
            
            number = getValidNumber();

            if (answer != number) {
                if (number > answer) {
                    cout << "your guess is too high" << endl;
                    cout << "you have " << count - i - 1 << " chances left" << endl;
                    if (i < count - 1) cout << "guess again" << endl;
                } else if (number < answer) {
                    cout << "your guess is too low" << endl;
                    cout << "you have " << count - i - 1 << " chances left" << endl;
                    if (i < count - 1) cout << "guess again" << endl;
                }
            } else {
                cout << "congratulations you guessed the number" << endl;
                break;
            }
        }
    }
};

int main() {
    NumberGuessingGame game;
    game.start();

    return 0;
}