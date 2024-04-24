#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

const int MAX_CARDS = 13; // The number of different card values in Blackjack
const int MAX_HAND = 11;  // The maximum number of cards a player can hold without busting

// Function to clear the input buffer
void clearInputBuffer() {
    cin.clear();  // Clear error flags
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard input until newline
}

// Function to clear the screen
void clearScreen() {
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Unix/Linux
#endif
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    bool playAgain = true;

    while (playAgain) {
        int cards[MAX_CARDS] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
        int user_cards[MAX_HAND] = {0};
        int cpu_cards[MAX_HAND] = {0};
        int sum_user_cards = 0, sum_cpu = 0;
        int user_card_count = 2;
        int cpu_card_count = 2;

        for (int i = 0; i < MAX_CARDS; ++i) {
            int r = rand() % MAX_CARDS;
            swap(cards[i], cards[r]);
        }

        user_cards[0] = cards[0];
        user_cards[1] = cards[1];
        sum_user_cards = user_cards[0] + user_cards[1];

        for (int i = 0; i < MAX_CARDS; ++i) {
            int r = rand() % MAX_CARDS;
            swap(cards[i], cards[r]);
        }

        cpu_cards[0] = cards[0];
        cpu_cards[1] = cards[1];
        sum_cpu = cpu_cards[0] + cpu_cards[1];

        cout << "=========================\n";
        cout << "🃏 Welcome to Blackjack! 🃏\n";
        cout << "=========================\n";
        cout << "Your hand: [ " << user_cards[0] << ", " << user_cards[1] << " ], Score: " << sum_user_cards << endl;
        cout << "Computer's showing: " << cpu_cards[0] << endl;
        cout << "-------------------------\n";

        bool user_continues = true;

        while (user_continues && sum_user_cards < 21) {
            char draw;
            cout << "Hit (y) or Stand (n)? ";
            cin >> draw;

            // Convert the input character to lowercase
            draw = tolower(draw);

            // Clear the input buffer if anything other than 'y' or 'n' is entered
            while (draw != 'y' && draw != 'n' && draw != 'c') {
                clearInputBuffer(); // Clear the input buffer
                cout << "Invalid input. Please enter 'y' for Hit, 'n' for Stand, or 'c' to clear the screen: ";
                cin >> draw;
                draw = tolower(draw);  // Convert the input character to lowercase again
            }

            if (draw == 'y') {
                int card_index = rand() % MAX_CARDS;
                user_cards[user_card_count] = cards[card_index];
                sum_user_cards += user_cards[user_card_count];
                user_card_count++;

                for (int i = 0; i < user_card_count; ++i) {
                    if (user_cards[i] == 11) {
                        if (sum_user_cards > 21) {
                            sum_user_cards -= 10;
                            user_cards[i] = 1;
                        } else {
                            cout << "You drew an Ace. Choose value (1 or 11): ";
                            int aceValue;
                            cin >> aceValue;
                            while (aceValue != 1 && aceValue != 11) {
                                clearInputBuffer(); // Clear the input buffer
                                cout << "Invalid value. Choose either 1 or 11: ";
                                cin >> aceValue;
                            }
                            if (aceValue == 1) {
                                sum_user_cards -= 10;
                                user_cards[i] = 1;
                            }
                        }
                        break;
                    }
                }

                cout << "You drew a " << user_cards[user_card_count - 1] << ".\n";
                cout << "Your hand now: [ ";
                for (int i = 0; i < user_card_count; ++i) {
                    cout << user_cards[i] << " ";
                }
                cout << "], Score: " << sum_user_cards << endl;

                if (sum_user_cards > 21) {
                    cout << "💥 Bust! Over 21. 💥\n";
                    user_continues = false;
                } else if (sum_user_cards == 21) {
                    cout << "🌟 Blackjack! You win! 🌟\n";
                    user_continues = false;
                }
            } else if (draw == 'n') {
                user_continues = false;
            } else if (draw == 'c') {
                clearScreen();
            }
        }

        if (sum_user_cards <= 21) {
            while (sum_cpu < 17) {
                cpu_cards[cpu_card_count] = cards[rand() % MAX_CARDS];
                sum_cpu += cpu_cards[cpu_card_count];
                cpu_card_count++;

                for (int i = 0; i < cpu_card_count; ++i) {
                    if (cpu_cards[i] == 11 && sum_cpu > 21) {
                        sum_cpu -= 10;
                        cpu_cards[i] = 1;
                    }
                }
            }
        }

        cout << "=========================\n";
        cout << "🎉 Game Results 🎉\n";
        cout << "=========================\n";
        cout << "Your final score: " << sum_user_cards << endl;
        cout << "Your cards: [ ";
        for (int i = 0; i < user_card_count; ++i) {
            cout << user_cards[i] << " ";
        }
        cout << "]" << endl;

        cout << "Computer's final score: " << sum_cpu << endl;
        cout << "Computer's cards: [ ";
        for (int i = 0; i < cpu_card_count; ++i) {
            cout << cpu_cards[i] << " ";
        }
        cout << "]" << endl;

        if (sum_user_cards > 21) {
            cout << "🚨 You bust! Computer wins. 🚨\n";
        } else if (sum_cpu > 21 || sum_user_cards > sum_cpu) {
            cout << "🏆 Congratulations! You win! 🏆\n";
        } else if (sum_user_cards == sum_cpu) {
            cout << "🤝 It's a draw! 🤝\n";
        } else {
            cout << "🔥 Computer wins. Better luck next time! 🔥\n";
        }

        string play;
        cout << "Play again? (y/n): ";
        cin >> play;

        // Convert the input string to lowercase
        for (char &c : play) {
            c = tolower(c);
        }

        // Clear the input buffer if anything other than 'y' or 'n' is entered
        while (play != "y" && play != "n") {
            clearInputBuffer(); // Clear the input buffer
            cout << "Invalid input. Please enter 'y' to play again or 'n' to quit: ";
            cin >> play;

            // Convert the input string to lowercase again
            for (char &c : play) {
                c = tolower(c);
            }
        }

        if (play != "y") {
            playAgain = false;
        }
    }

    return 0;
}
