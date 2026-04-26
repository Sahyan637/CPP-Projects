#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> todoList;
int taskCount = 0;

void addTask() {
    cin.ignore();
    Task t;
    cout << "Enter task description: ";
    getline(cin, t.description);
    t.completed = false;
    todoList.push_back(t);
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

    todoList.erase(todoList.begin() + (index - 1));
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
        cout << "\n=== To-Do List Menu ===\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Mark Task Completed\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: deleteTask(); break;
            case 4: markCompleted(); break;
            case 5: cout << "Exiting...\n"; break;

            default: cout << "Invalid choice!\n";
        }
    }while(choice != 5);

    return 0;
}