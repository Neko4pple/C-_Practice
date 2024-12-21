#include <iostream>
#include <sstream>
using namespace std;

// Define a simple structure to hold a character and an integer
struct Pair {
    char data_name;
    int recog_num;
};

int main() {
    Pair pairs[5]; // Array of 5 Pair objects
    int count = 0; // Count of entered pairs

    cout << "After you type, press [Enter] btn twice." << endl;
    cout << "Input your data (ex - a 30 b 25 c 40 ...): ";

    string line;
    while (getline(cin, line)) {
        if (line.empty()) { // Check for a second enter (empty line)
            break;
        }

        istringstream iss(line);
        while (iss >> pairs[count].data_name >> pairs[count].recog_num) {
            count++;
            if (count > 5) {
                cout << "Your input exceeds max limits." << endl;
                return 0;
            }
        }
    }

    // Display the contents of the array
    for (int i = 0; i < count; ++i) {
        cout << pairs[i].data_name << " is " << pairs[i].recog_num << endl;
    }
    cout << endl;

    // Ask for an index and display the corresponding pair
    cout << "Enter an index number to display (0-4): ";
    int index;
    cin >> index;
    cout << endl;

    if (index >= 0 && index < count) {
        cout << "At index " << index << ": " << pairs[index].data_name << " is " << pairs[index].recog_num << endl;
    }
    else {
        cout << "Invalid index number." << endl;
    }

    return 0;
}
