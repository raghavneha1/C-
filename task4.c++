#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class ToDoList {
public:
    void addTask(const std::string& description);
    void viewTasks() const;
    void markAsCompleted(int taskIndex);
    void removeTask(int taskIndex);

private:
    std::vector<Task> tasks;
};

void ToDoList::addTask(const std::string& description) {
    tasks.emplace_back(description);
    std::cout << "Task added: " << description << "\n";
}

void ToDoList::viewTasks() const {
    std::cout << "Task List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << "[" << i + 1 << "] ";
        std::cout << (tasks[i].completed ? "[Completed] " : "[Pending] ");
        std::cout << tasks[i].description << "\n";
    }
    std::cout << "\n";
}

void ToDoList::markAsCompleted(int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
        tasks[taskIndex - 1].completed = true;
        std::cout << "Task marked as completed: " << tasks[taskIndex - 1].description << "\n";
    } else {
        std::cout << "Invalid task index.\n";
    }
}

void ToDoList::removeTask(int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
        std::cout << "Task removed: " << tasks[taskIndex - 1].description << "\n";
        tasks.erase(tasks.begin() + taskIndex - 1);
    } else {
        std::cout << "Invalid task index.\n";
    }
}

int main() {
    ToDoList todo;

    while (true) {
        std::cout << "==== To-Do List Manager ====\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::string description;
                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                todo.addTask(description);
                break;
            }
            case 2:
                todo.viewTasks();
                break;
            case 3: {
                int taskIndex;
                std::cout << "Enter the task index to mark as completed: ";
                std::cin >> taskIndex;
                todo.markAsCompleted(taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                std::cout << "Enter the task index to remove: ";
                std::cin >> taskIndex;
                todo.removeTask(taskIndex);
                break;
            }
            case 5:
                std::cout << "Exiting the program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please choose a valid option.\n";
        }
    }

    return 0;
}
