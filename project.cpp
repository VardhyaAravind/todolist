#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        Task newTask;
        newTask.description = description;
        newTask.completed = false;
        tasks.push_back(newTask);
    }

    void markCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void displayTasks() {
        cout << "\nTO-DO LIST:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed) {
                cout << "[X] ";
            } else {
                cout << "[ ] ";
            }
            cout << tasks[i].description << endl;
        }
        cout << endl;
    }
};

int main() {
    ToDoList todoList;
    int choice;
    string taskDescription;
    int taskIndex;

    while (true) {
        cout << "1. Add Task" << endl;
        cout << "2. Mark Task as Completed" << endl;
        cout << "3. View Tasks" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the task description: ";
                cin.ignore();
                getline(cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                cout << "Enter the index of the task to mark as completed: ";
                cin >> taskIndex;
                todoList.markCompleted(taskIndex - 1); // Adjusting for 0-based indexing
                break;
            case 3:
                todoList.displayTasks();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
