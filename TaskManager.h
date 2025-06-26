#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include <vector>
#include "User.h"

class TaskManager {
private:
    std::vector<User*> m_users;
    User* m_logged_user;

public:
    TaskManager();
    TaskManager(const TaskManager& other);
    TaskManager(TaskManager&& other) noexcept;
    TaskManager& operator=(const TaskManager& other);
    TaskManager& operator=(TaskManager&& other) noexcept;
    ~TaskManager();

    void register_user(const std::string& username, const std::string& password);
    bool login(const std::string& username, const std::string& password);
    void logout();
    User* get_logged_user() const;

    void add_task(const Task& task);
    void delete_task(const std::string& title);
    void edit_task(const std::string& title, const Task& updatedTask);
    void display_task() const;
};
#endif
