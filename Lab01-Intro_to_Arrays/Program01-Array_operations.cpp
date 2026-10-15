#include <iostream>
using namespace std;

const int MAX = 100;

// Display array elements
void display(int arr[], int n) {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }

    cout << "Array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// Insert an element at a position
void insertElement(int arr[], int &n, int pos, int value) {
    if (n >= MAX) {
        cout << "Array is full.\n";
        return;
    }

    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position.\n";
        return;
    }

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = value;
    n++;

    cout << "Element inserted successfully.\n";
}

// Delete an element from a position
void deleteElement(int arr[], int &n, int pos) {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }

    if (pos < 1 || pos > n) {
        cout << "Invalid position.\n";
        return;
    }

    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;

    cout << "Element deleted successfully.\n";
}

// Search for an element
void searchElement(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            cout << "Element found at index " << i << ".\n";
            return;
        }
    }

    cout << "Element not found.\n";
}

// Rotate array left by one position
void rotateLeft(int arr[], int n) {
    if (n <= 1) {
        cout << "Rotation not required.\n";
        return;
    }

    int first = arr[0];

    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    arr[n - 1] = first;

    cout << "Array rotated left by one position.\n";
}

int main() {
    int arr[MAX];
    int n, choice, pos, value;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n < 0 || n > MAX) {
        cout << "Invalid array size.\n";
        return 1;
    }

    cout << "Enter array elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    do {
        cout << "\n--- ARRAY OPERATIONS ---\n";
        cout << "1. Display\n";
        cout << "2. Insert\n";
        cout << "3. Delete\n";
        cout << "4. Search\n";
        cout << "5. Rotate Left\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                display(arr, n);
                break;

            case 2:
                cout << "Enter position (1-based): ";
                cin >> pos;

                cout << "Enter value: ";
                cin >> value;

                insertElement(arr, n, pos, value);
                break;

            case 3:
                cout << "Enter position to delete: ";
                cin >> pos;

                deleteElement(arr, n, pos);
                break;

            case 4:
                cout << "Enter value to search: ";
                cin >> value;

                searchElement(arr, n, value);
                break;

            case 5:
                rotateLeft(arr, n);
                break;

            case 6:
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
//here my code ends - divya
