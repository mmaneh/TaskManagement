#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <striing>

enum class Priority { LOW, MID, HIGH, URGENT };
enum class Status { NOT_STARTED, IN_PROGRESS, COMPLETED };

class Task {

private:
	std::string m_task_id;
	std::string m_uid;
	std::string m_title;
	std::string m_description;
	std::string m_deadline;
	std::string m_category;
	Priority m_prio;
	Status m_status;
public:
	Task();
    Task(const std::string& id, const std::string& uid, const std::string& title, const std::string& desc,
         const std::string& deadline, const std::string& category, int prio, int status);
    Task(const Task& other);
    Task(Task&& other) noexcept;
    Task& operator=(const Task& other);
    Task& operator=(Task&& other) noexcept;
    ~Task();

    void edit(const std::string& title, const std::string& desc, const std::string& deadline,
              const std::string& category, Priority prio);
    void set_status(Status status);
    void set_priority(Priority prio);
    void display() const;

    std::string get_task_id() const;
    std::string get_title() const;
    Status get_status() const;
    int get_priority() const;

    bool operator==(const Task& other) const;
    bool operator<(const Task& other) const;
    Task& operator++();   
    Task& operator--();   
    friend std::ostream& operator<<(std::ostream&, const Task&);
    friend std::istream& operator>>(std::istream&, Task&);
};
	
#endif

