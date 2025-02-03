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