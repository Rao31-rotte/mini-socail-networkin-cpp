#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User {
public:
    string name;
    vector<string> messages;

    User(string n) : name(n) {}

    void receiveMessage(const string& msg) {
        messages.push_back(msg);
    }

    void viewMessages() const {
        cout << "\n--- Messages for " << name << " ---\n";
        if (messages.empty()) {
            cout << "No messages.\n";
            return;
        }
        for (size_t i = 0; i < messages.size(); i++)
            cout << i + 1 << ". " << messages[i] << endl;
    }
};

class SocialNetwork {
private:
    vector<User> users;

public:
    // Preload users and messages
    SocialNetwork() {
        users.push_back(User("Anushka Rotte"));
        users.push_back(User("Vijay Rotte"));

        // Add demo messages
        users[1].receiveMessage("From Anushka Rotte: Hi, I am working on something new.");
        users[0].receiveMessage("From Vijay Rotte: Ok, well done!");
        users[1].receiveMessage("From Anushka Rotte: Can you review my code?");
        users[0].receiveMessage("From Vijay Rotte: Sure, looks good to me!");
    }

    void createUser() {
        string name;
        cout << "\nEnter user name: ";
        cin.ignore();
        getline(cin, name);
        users.push_back(User(name));
        cout << "User '" << name << "' created successfully!\n";
    }

    void sendMessage() {
        if (users.size() < 2) {
            cout << "At least 2 users are required to send messages.\n";
            return;
        }

        int senderIndex, receiverIndex;
        cout << "\nSelect sender:\n";
        for (size_t i = 0; i < users.size(); i++)
            cout << i << ". " << users[i].name << endl;
        cin >> senderIndex;

        if (senderIndex < 0 || senderIndex >= (int)users.size()) {
            cout << "Invalid sender!\n";
            return;
        }

        cout << "Select receiver:\n";
        for (size_t i = 0; i < users.size(); i++)
            if ((int)i != senderIndex)
                cout << i << ". " << users[i].name << endl;
        cin >> receiverIndex;

        if (receiverIndex < 0 || receiverIndex >= (int)users.size() || receiverIndex == senderIndex) {
            cout << "Invalid receiver!\n";
            return;
        }

        cin.ignore();
        string message;
        cout << "Enter message: ";
        getline(cin, message);

        users[receiverIndex].receiveMessage("From " + users[senderIndex].name + ": " + message);
        cout << "Message sent successfully!\n";
    }

    void viewMessages() {
        if (users.empty()) {
            cout << "No users available.\n";
            return;
        }

        int userIndex;
        cout << "\nSelect user to view messages:\n";
        for (size_t i = 0; i < users.size(); i++)
            cout << i << ". " << users[i].name << endl;
        cin >> userIndex;

        if (userIndex < 0 || userIndex >= (int)users.size()) {
            cout << "Invalid user selection!\n";
            return;
        }

        users[userIndex].viewMessages();
    }
};

int main() {
    SocialNetwork sn;
    int choice;

    cout << "=== Welcome to Mini Social Network ===\n";

    do {
        cout << "\nMenu:\n";
        cout << "1. Create User\n";
        cout << "2. Send Message\n";
        cout << "3. View Messages\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: sn.createUser(); break;
            case 2: sn.sendMessage(); break;
            case 3: sn.viewMessages(); break;
            case 4: cout << "Thank you for using Mini Social Network! Goodbye!\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
