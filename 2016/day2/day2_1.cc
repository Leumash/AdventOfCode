/*

--- Day 2: Bathroom Security ---

You arrive at Easter Bunny Headquarters under cover of darkness. However, you left in such a rush that you forgot to use the bathroom! Fancy office buildings like this one usually have keypad locks on their bathrooms, so you search the front desk for the code.

"In order to improve security," the document you find says, "bathroom codes will no longer be written down. Instead, please memorize and follow the procedure below to access the bathrooms."

The document goes on to explain that each button to be pressed can be found by starting on the previous button and moving to adjacent buttons on the keypad: U moves up, D moves down, L moves left, and R moves right. Each line of instructions corresponds to one button, starting at the previous button (or, for the first line, the "5" button); press whatever button you're on at the end of each line. If a move doesn't lead to a button, ignore it.

You can't hold it much longer, so you decide to figure out the code as you walk to the bathroom. You picture a keypad like this:

1 2 3
4 5 6
7 8 9

Suppose your instructions are:

ULL
RRDDD
LURDL
UUUUD

- You start at "5" and move up (to "2"), left (to "1"), and left (you can't, and stay on "1"), so the first button is 1.
- Starting from the previous button ("1"), you move right twice (to "3") and then down three times (stopping at "9" after two moves and ignoring the third), ending up with 9.
- Continuing from "9", you move left, up, right, down, and left, ending with 8.
- Finally, you move up four times (stopping at "2"), then down once, ending with 5.

So, in this example, the bathroom code is 1985.

Your puzzle input is the instructions from the document you found at the front desk. What is the bathroom code?

*/

#include <iostream>
#include <vector>

using namespace std;

enum Direction { UP, DOWN, LEFT, RIGHT };

class KeypadPosition {
    public:
        KeypadPosition();
        string getCurrentPosition();
        void move(Direction direction);
    private:
        int pos;
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
};

KeypadPosition::KeypadPosition() {
    pos = 5;
}

string KeypadPosition::getCurrentPosition() {
    return to_string(pos);
}

void KeypadPosition::move(Direction direction) {
    switch (direction) {
        case UP:
            moveUp();
            break;
        case DOWN:
            moveDown();
            break;
        case LEFT:
            moveLeft();
            break;
        case RIGHT:
            moveRight();
            break;
    }
}

void KeypadPosition::moveUp() {
    if (pos == 1 || pos == 2 || pos == 3) {
        return;
    }
    pos = pos - 3;
}

void KeypadPosition::moveDown() {
    if (pos == 7 || pos == 8 || pos == 9) {
        return;
    }
    pos = pos + 3;
}

void KeypadPosition::moveLeft() {
    if (pos == 1 || pos == 4 || pos == 7) {
        return;
    }
    --pos;
}

void KeypadPosition::moveRight() {
    if (pos == 3 || pos == 6 || pos == 9) {
        return;
    }
    ++pos;
}

Direction stringToDirection(char move) {
    switch(move) {
        case 'U': return UP;
        case 'D': return DOWN;
        case 'L': return LEFT;
        case 'R': return RIGHT;
    }
    return UP;
}

string getBathroomCode(const vector<string> &sequences) {
    string bathroomCode;
    KeypadPosition keypad;

    for (string moves : sequences) {
        for (char move : moves) {
            keypad.move(stringToDirection(move));
        }
        bathroomCode += keypad.getCurrentPosition();
    }

    return bathroomCode;
}

vector<string> readInput() {
    vector<string> sequences;
    string input;
    while(cin >> input) {
        sequences.push_back(input);
    }
    return sequences;
}

int main() {
    vector<string> sequences = readInput();
    cout << getBathroomCode(sequences);
}

