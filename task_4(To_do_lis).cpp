// to do list using cpp
#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int MAX_TASKS = 100; // Maximum number of tasks

string tasks[MAX_TASKS];
bool completed[MAX_TASKS];
int taskCount = 0;

void addTask() {
    if (taskCount < MAX_TASKS) {
        cout << "Enter task: ";
        getline(cin >> ws, tasks[taskCount]); // Important to use getline to capture full task description
        completed[taskCount] = false;
        taskCount++;
        cout << "Task added.\n";
    } else {
        cout << "Task list is full.\n";
    }
}

void viewTasks() {
    if (taskCount == 0) {
        cout << "No tasks in the list.\n";
        return;
    }

    cout << "\nTo-Do List:\n";
    for (int i = 0; i < taskCount; i++) {
        cout << i + 1 << ". " << tasks[i] << " (" << (completed[i] ? "Completed" : "Pending") << ")\n";
    }
}

void markTaskCompleted() {
    viewTasks(); // Display tasks so user can choose
    if (taskCount == 0) return;

    int taskNumber;
    while (true) {
        cout << "Enter the number of the task to mark as completed: ";
        cin >> taskNumber;
        if (cin.fail()) {
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a number.\n";
        } else if (taskNumber >= 1 && taskNumber <= taskCount) {
            completed[taskNumber - 1] = true;
            cout << "Task marked as completed.\n";
            break;
        } else {
            cout << "Invalid task number. Please try again.\n";
        }
    }
}

void removeTask() {
    viewTasks(); // Show tasks so user can choose
    if (taskCount == 0) return;

    int taskNumber;
    while (true) {
        cout << "Enter the number of the task to remove: ";
        cin >> taskNumber;
        if (cin.fail()) {
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a number.\n";
        } else if (taskNumber >= 1 && taskNumber <= taskCount) {
            for (int i = taskNumber - 1; i < taskCount - 1; i++) { // Shift tasks down to fill the gap
                tasks[i] = tasks[i + 1];
                completed[i] = completed[i + 1];
            }
            taskCount--;
            cout << "Task removed.\n";
            break;
        } else {
            cout << "Invalid task number. Please try again.\n";
        }
    }
}

void showMenu() {
    cout << "\nMenu:\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
}

int main() {
    int choice;
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
