#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Struct to hold player information
struct Player {
    long long position;
    long long speed;
    int id;
};

// Comparator to sort players by position
bool compareByPosition(const Player &a, const Player &b) {
    return a.position < b.position;
}

int main() {
    int N;
    long long T;
    cin >> N >> T;

    vector<Player> players(N);

    // Read the input data
    for (int i = 0; i < N; i++) {
        cin >> players[i].position >> players[i].speed;
        players[i].id = i + 1; // Assign player IDs starting from 1
    }

    // Sort players by their starting positions
    sort(players.begin(), players.end(), compareByPosition);

    // Track the groups
    vector<int> frontRunners; // This will store the IDs of the front-runners of the groups

    // Traverse players from the last to the first
    long long lastGroupPosition = players[N - 1].position + players[N - 1].speed * T;
    frontRunners.push_back(players[N - 1].id); // Start with the last player

    for (int i = N - 2; i >= 0; i--) {
        // Calculate the position of the current player after T minutes
        long long currentPosition = players[i].position + players[i].speed * T;

        // If the current player can't catch up to the last group's position, they form a new group
        if (currentPosition < lastGroupPosition) {
            frontRunners.push_back(players[i].id);
            lastGroupPosition = currentPosition; // Update the last group's position
        }
    }

    // Output the results
    cout << frontRunners.size() << endl;

    // Print the front-runners 

    for (int id : frontRunners) {
        cout << id << " ";
    }

    cout << endl;

    return 0;
}