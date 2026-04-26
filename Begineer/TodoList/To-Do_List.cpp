#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

class Task {
private:
    string description;
    bool completed;
public:
    Task(string desc = "", bool status = false) : description(desc), completed(status) {}

    void markCompleted() {
        completed = true;
    }

    string getDescription() const {
        return description;
    }

    bool isCompleted() const {
        return completed;
    }

    string serialize() const {
        return description + "|" + (completed ? "1" : "0");
    }

    static Task deserialize(const string &line) {
        size_t pos = line.find('|');
        string desc = line.substr(0, pos);
        bool status = (line.substr(pos + 1) == "1");
        return Task(desc, status);
    }
};

class TodoList {
private:
    vector<Task> tasks;
    string filename;
public:
    TodoList(const string &file) : filename(file) {
        loadFromFile();
    }

    void addTask(const string &desc) {
        tasks.push_back(Task(desc));
        saveToFile();
        cout << "Task added successfully!\n";
    }

    void viewTasks() const {
        if(tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }
        cout << "\nTo-Do List:\n";
        for(size_t i=0; i<tasks.size(); ++i) {
            cout << i+1 << ". " << tasks[i].getDescription() << " [" << (tasks[i].isCompleted() ? "Done" : "Pending") << "]\n";
        }
    }

    void deleteTask(size_t index) {
        if(index < 1 || index > tasks.size()) {
            cout << "Invalid task number!\n";
            return;
        }

        tasks.erase(tasks.begin() + (index - 1));
        saveToFile();
        cout << "Task deleted successfully!\n";
    }


    void markCompleted(int index) {
        if(index < 1 || index > tasks.size()) {
            cout << "Invalid task number!\n";
            return;
        }
        tasks[index-1].markCompleted();
        saveToFile();
        cout << "Task marked as completed!\n";
    }

private:
    void saveToFile() {
        ofstream file(filename);
        if(!file) {
            cout << "Error saving file!\n";
            return;
        }
        for(const auto &task : tasks) {
            file << task.serialize() << endl;
        }
    }

    void loadFromFile() {
        ifstream file(filename);
        if(!file) return;

        string line;
        while(getline(file,line)) {
            if(!line.empty()) {
                tasks.push_back(Task::deserialize(line));
            }
        }
    }
};


int main() {
    TodoList todo("tasks.txt");
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
        cin.ignore();

        switch(choice) {
            case 1: {
                string desc;
                cout << "Enter task: ";
                getline(cin, desc);
                todo.addTask(desc);
                break;
            }
            case 2: todo.viewTasks(); break;
            case 3: {
                int index;
                cout << "Enter task number:";
                cin >> index;
                todo.deleteTask(index);
                break;
            }
            case 4: {
                int index;
                cout << "Enter task number: ";
                cin >> index;
                todo.markCompleted(index);
                break;
            }
            case 5: cout << "Exiting...\n"; break;

            default: 
                cout << "Invalid choice!\n";
        }
    } while(choice != 5);

    return 0;
}