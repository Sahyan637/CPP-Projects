#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Task {
    string description;
    bool completed;
};

Task todoList[MAX];
int taskCount = 0;

void addTask() {
    if(taskCount >= MAX) {
        cout << "To-Do List is full\n";
        return;
    }
    cin.ignore();
    cout << "Enter task: ";
    getline(cin, todoList[taskCount].description);
    todoList[taskCount].completed = false;
    taskCount++;

    cout << "Task added successfully!\n";
}

void viewTasks() {
    if(taskCount == 0) {
        cout << "No tasks available.\n";
        return;
    }
    cout << "\nTo-Do List:\n";
    for(int i=0; i<taskCount; ++i) {
        cout << i+1 << ". " << todoList[i].description << " [" << (todoList[i].completed ? "Done" : "Pending") << "]\n";
    }
}

void deleteTask() {
    int index;
    cout << "Enter task number to delete: ";
    cin >> index;
    if(index < 1 || index > taskCount) {
        cout << "Invalid task number!\n";
        return;
    }

    for(int i=index-1; i<taskCount-1; ++i) {
        todoList[i] = todoList[i+1];
    }
    taskCount--;
    cout << "Task deleted successfully!\n";
}

void markCompleted() {
    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;

    if(index < 1 || index > taskCount) {
        cout << "Invalid task number!\n";
        return;
    }
    todoList[index-1].completed = true;
    cout << "Task marked as completed!\n";
}

int main() {
    int choice;

    do {
        cout << "\n=== To-Do List Menu ===";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Mark Task Completed\n";
        cout << "5. Exi\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: deleteTask(); break;
            case 4: markCompleted; break;
            case 5: cout << "Exiting...\n"; break;

            default: cout << "Invalid choice!\n";
        }
    }while(choice != 5);

    return 0;
}