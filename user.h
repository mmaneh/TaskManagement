#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include "Task.h"

class User {
private:
    std::string m_id;
    std::string m_name;
    std::string m_passwd;
    std::vector<Task*> m_tasks;
    bool is_logged;

public:
    User();
    User(const std::string& id, const std::string& name, const std::string& password);
    User(const User& other);
    User(User&& other) noexcept;
    User& operator=(const User& other);
    User& operator=(User&& other) noexcept;
    ~User();

    void add_task(Task* task);
    void delete_task(const std::string& title);
    void edit_task(const std::string& title, const Task& updatedTask);
    void list_tasks() const;
    Task* search_task(const std::string& title);

    bool login(const std::string& password);
    void logout();

    std::string get_name() const;
    std::string get_id() const;

    explicit operator bool() const;
    friend std::ostream& operator<<(std::ostream&, const User&);
};
#endif
