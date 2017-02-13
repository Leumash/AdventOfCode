#include <iostream>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

enum Direction {NORTH, SOUTH, EAST, WEST};

enum Turn {LEFT, RIGHT};

struct Move {
    Turn turn;
    int distance;
};

Direction turnRight(Direction current) {
    switch(current) {
        case NORTH:
            return EAST;
        case SOUTH:
            return WEST;
        case EAST:
            return SOUTH;
        case WEST:
            return NORTH;
    }
}


Direction turnLeft(Direction current) {
    switch(current) {
        case NORTH:
            return WEST;
        case SOUTH:
            return EAST;
        case EAST:
            return NORTH;
        case WEST:
            return SOUTH;
    }
}

void performMove(Direction direction, int &x, int &y) {
    switch(direction) {
        case NORTH:
            y = y + 1;
            break;
        case SOUTH:
            y = y - 1;
            break;
        case EAST:
            x = x + 1;
            break;
        case WEST:
            x = x - 1;
            break;
    }
}

int getManhanteasldfkajdlDistance(const vector<Move> &moves) {
    int x = 0;
    int y = 0;
    Direction direction = NORTH;
    unordered_map<int, unordered_set<int>> traversed;

    // Insert (0,0)
    traversed[0].insert(0);

    for (Move move : moves) {
        if (move.turn == RIGHT) {
            direction = turnRight(direction);
        } else {
            direction = turnLeft(direction);
        }

        for (int distance = move.distance; distance > 0; --distance) {
            performMove(direction, x, y);
            if (traversed.count(x) > 0 && traversed[x].count(y) > 0) {
                return abs(x) + abs(y);
            } else {
                traversed[x].insert(y);
            }
        }
    }

    // Error: No overlap found
    return -1;
}

Move getMove(string line) {
    stringstream ss;
    ss << line[0];
    ss << line.substr(1);
    char direction;
    int distance;

    Move toReturn;

    ss >> direction;
    ss >> distance;

    toReturn.turn = direction == 'R' ? RIGHT : LEFT;
    toReturn.distance = distance;

    return toReturn;
}

int main() {
    string input;
    vector<Move> moves;

    while (cin >> input) {
        Move move = getMove(input);
        moves.push_back(move);
    }

    cout << getManhanteasldfkajdlDistance(moves) << endl;
}

