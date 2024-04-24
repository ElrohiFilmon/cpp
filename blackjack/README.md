
# Blackjack Game Documentation

## Overview
This C++ program simulates a simple game of Blackjack against the computer. The game includes basic features like shuffling, drawing cards, determining the winner, and the option to play again.

## System Requirements
- C++ compiler (e.g., g++, clang)
- Standard Template Library (STL)

## Compilation
Compile the source code using a C++ compiler. For example:
```bash
g++ -o blackjack blackjack.cpp
```

## Running the Program
Execute the compiled program:
```bash
./blackjack
```

## Code Structure

1. **Header Inclusion**
    - Standard input/output and string libraries.
    - Ctime and cstdlib for random number generation.
    - Cctype for character manipulation.
    - Limits for numeric limits in streams.

2. **Platform-Specific Clear Screen**
    - The `clearScreen` function clears the console screen. It uses `system("cls")` for Windows and `system("clear")` for Unix/Linux.

3. **Main Function**
    - Initializes random seed.
    - The main game loop controlled by `playAgain` variable.

4. **Game Initialization**
    - Declares and initializes the card decks for the user and CPU.
    - Shuffles and assigns initial cards.

5. **Gameplay Loop**
    - Displays initial hands and prompts the user for actions: hit or stand.
    - Handles user's decision to draw a card or stand.
    - Adjusts for Ace's value based on the player's hand.

6. **Computer's Turn**
    - The computer draws cards until its total is 17 or higher.

7. **Determining the Outcome**
    - Compares the scores of the player and the computer to determine the winner.

8. **Replay Option**
    - Asks the user if they want to play again.

9. **Function: clearInputBuffer**
    - Clears the input buffer to handle invalid input.

## Code Conventions
- Constants: MAX_CARDS, MAX_HAND
- CamelCase for function names.
- snake_case for variable names.
- Comments for code clarity.

## Limitations and Possible Improvements
- The game does not handle all Blackjack rules (e.g., splitting, insurance).
- The shuffling algorithm is basic and could be improved for better randomness.
- The user interface is text-based and can be enhanced with a graphical interface.


## Detailed Function Descriptions
This section provides detailed explanations of key functions within the code.

### clearInputBuffer()
- **Purpose**: Clears the input buffer to prevent invalid input from affecting the game flow.
- **Parameters**: None
- **Return Type**: Void

### clearScreen()
- **Purpose**: Clears the console screen for a cleaner user interface.
- **Parameters**: None
- **Return Type**: Void
- **Platform Specific**: Uses different commands for Windows and Unix/Linux.

## Example Gameplay
An example session illustrating how the game progresses:
1. The game starts and displays the user's and computer's initial hands.
2. The user chooses to hit or stand.
3. If the user hits, a new card is added to their hand.
4. The game continues until the user stands or busts.
5. The computer then plays its hand.
6. The winner is determined based on the final scores.

## Troubleshooting Section
Common issues and their solutions:
- **Issue**: Game not starting.
  - **Solution**: Ensure C++ compiler is correctly installed and path variables are set.
- **Issue**: Screen not clearing on command.
  - **Solution**: Check the operating system and ensure the correct command is used.

## FAQs
**Q**: Can I split my hand?
**A**: No, splitting is not implemented in this version.

**Q**: What happens if both the player and computer bust?
**A**: The game ends, and it's considered a loss for the player.

## Future Enhancements
- Implementing splitting and insurance options.
- Adding a graphical user interface for a more engaging experience.

## Contributors
1. **Betelhem Worku**
2. **Elrohi Filmon**
3. **Dagmawi Asfaw**
4. **Lozan Getnet** 
5. **Meti Abera** 
