#include <iostream>
#include <string>
using namespace std;
struct CricketPlayer {
    string name;
    int runs;
    int hundreds;
    int wickets;
    int catches;
    bool availability;
};
void listPlayers(CricketPlayer players[], int playerCount) {
    if (playerCount == 0) {
        cout << "No players available." << endl;
    } else {
        cout << "List of Potential Players:" << endl;
        for (int i = 0; i < playerCount; i++) {
            cout << "Name: " << players[i].name
                 << ", Runs: " << players[i].runs
                 << ", Hundreds: " << players[i].hundreds
                 << ", Wickets: " << players[i].wickets
                 << ", Catches: " << players[i].catches
                 << ", Availability: " << (players[i].availability ? "Available" : "Unavailable") << endl;
        }
    }
    cout << "Press Enter to continue..." << endl;
    cin.ignore();
    cin.get();
}
void nameSearch(CricketPlayer players[], int playerCount) {
    string searchName;
    cout << "Enter the player's name to search: ";
    cin >> searchName;
    
    bool found = false;
    for (int i = 0; i < playerCount; i++) {
        if (players[i].name == searchName) {
            cout << "Found player - Name: " << players[i].name
                 << ", Runs: " << players[i].runs
                 << ", Hundreds: " << players[i].hundreds
                 << ", Wickets: " << players[i].wickets
                 << ", Catches: " << players[i].catches
                 << ", Availability: " << (players[i].availability ? "Available" : "Unavailable") << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No player found with the name " << searchName << "." << endl;
    }
    cout << "Press Enter to continue..." << endl;
    cin.ignore();
    cin.get();
}
void addNewPlayer(CricketPlayer players[], int &playerCount, int maxPlayers) {
    if (playerCount >= maxPlayers) {
        cout << "Cannot add more players. Maximum limit reached." << endl;
        return;
    }

    string name;
    int runs, hundreds, wickets, catches;
    char availability;

    cout << "Enter player's name: ";
    cin >> name;
    cout << "Enter runs: ";
    cin >> runs;
    cout << "Enter hundreds: ";
    cin >> hundreds;
    cout << "Enter wickets: ";
    cin >> wickets;
    cout << "Enter catches: ";
    cin >> catches;
    cout << "Is the player available? (y/n): ";
    cin >> availability;
    
    bool avail = (availability == 'y' || availability == 'Y');
    players[playerCount++] = {name, runs, hundreds, wickets, catches, avail};
    cout << "Player " << name << " added successfully." << endl;
    cout << "Press Enter to continue..." << endl;
    cin.ignore();
    cin.get();
}
void removeByName(CricketPlayer players[], int &playerCount) {
    string name;
    cout << "Enter the player's name to remove: ";
    cin >> name;

    bool found = false;
    for (int i = 0; i < playerCount; i++) {
        if (players[i].name == name) {
            for (int j = i; j < playerCount - 1; j++) {
                players[j] = players[j + 1];
            }
            playerCount--;
            cout << "Player " << name << " removed successfully." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No player found with the name " << name << "." << endl;
    }
    cout << "Press Enter to continue..." << endl;
    cin.ignore();
    cin.get();
}
void updateByName(CricketPlayer players[], int playerCount) {
    string name;
    cout << "Enter the player's name to update: ";
    cin >> name;

    bool found = false;
    for (int i = 0; i < playerCount; i++) {
        if (players[i].name == name) {
            cout << "Current details for " << name << ": "
                 << "Runs: " << players[i].runs
                 << ", Hundreds: " << players[i].hundreds
                 << ", Wickets: " << players[i].wickets
                 << ", Catches: " << players[i].catches
                 << ", Availability: " << (players[i].availability ? "Available" : "Unavailable") << endl;
            
            cout << "Enter new runs: ";
            cin >> players[i].runs;
            cout << "Enter new hundreds: ";
            cin >> players[i].hundreds;
            cout << "Enter new wickets: ";
            cin >> players[i].wickets;
            cout << "Enter new catches: ";
            cin >> players[i].catches;
            char availability;
            cout << "Is the player available? (y/n): ";
            cin >> availability;
            players[i].availability = (availability == 'y' || availability == 'Y');
            cout << "Player " << name << "'s details updated successfully." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No player found with the name " << name << "." << endl;
    }
    cout << "Press Enter to continue..." << endl;
    cin.ignore();
    cin.get();
}

int main() {
    const int MAX_PLAYERS = 100; 
    CricketPlayer players[MAX_PLAYERS]; 
    int playerCount = 0; 

    int choice;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "0: Close Program" << endl;
        cout << "1: List" << endl;
        cout << "2: Name Search" << endl;
        cout << "3: Add New" << endl;
        cout << "4: Remove by Name" << endl;
        cout << "5: Update by Name" << endl;
        cout << "Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Exiting program." << endl;
                return 0;
            case 1:
                listPlayers(players, playerCount);
                break;
            case 2:
                nameSearch(players, playerCount);
                break;
            case 3:
                addNewPlayer(players, playerCount, MAX_PLAYERS);
                break;
            case 4:
                removeByName(players, playerCount);
                break;
            case 5:
                updateByName(players, playerCount);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}
