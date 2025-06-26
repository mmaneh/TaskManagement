#include "task.h"
#include <iostream>

Task::Task() : m_task_id(""), m_uid(""), m_title(""), m_decription(""), m_deadline(""), m_category(""), m_prio(Priority::LOW), m_status(Status::NOT_STARTED)  {}

Task::Task(const std::string& id, const std::string& uid,const std::string& title, const std::string& description, const std::string& deadline, const std::string& category, int prio, int status) : m_task_id(id), m_uid(uid), m_title(title), m_descriptor(description), m_deadline(deadline), m_category(category), m_prio(static_cast<Priority>(prio)), m_status(static_cast<Status>(status)) {}

Task::Task(const Task& other) : m_task_id(other.m_task_id), m_uid(other.m_uid), m_title(other.m_title), m_description(other.m_description), m_deadline(other.m_deadline), m_category(other.m_category), m_prio(other.m_prio), m_status(other.m_status) {}

Task::Task(const Task&& other) noexcept : m_task_id(other.m_task_id), m_uid(other.m_uid), m_title(other.m_title), m_description(other.m_description), m_deadline(other.m_deadline), m_category(other.m_category), m_prio(other.m_prio), m_status(other.m_status) {
        other.m_task_id.clear();
    other.m_uid.clear();
    other.m_title.clear();
    other.m_description.clear();
    other.m_deadline.clear();
    other.m_category.clear();
    other.m_prio = Priority::LOW;
    other.m_status = Status::NOT_STARTED;
}

Task::~Task() {}

Task& Task::operator=(const Task& other) {
	if (this != &other) {
		m_task_id = other.m_task_id;
        	m_uid = other.m_uid;
        	m_title = other.m_title;
        	m_description = other.m_description;
        	m_deadline = other.m_deadline;
        	m_category = other.m_category;
        	m_prio = other.m_prio;
        	m_status = other.m_status;
	}
	return *this;
}

Task& Task::operator=(Task&& other) noexcept {
	if (this != &other) {
        	m_task_id = other.m_task_id;
        	m_uid = other.m_uid;
        	m_title = other.m_title;
       		m_description = other.m_description;
        	m_deadline = other.m_deadline;
        	m_category = other.m_category;
        	m_prio = other.m_prio;
	        m_status = other.m_status;
    }
    return *this;

}

void Task::edit(const std::string& title, const std::string& decriptor, const std::string& deadline, const std::string& category, Priority prio) {
	m_title = title;
	m_descriptor = descriptor;
	m_deadline = deadline;
	m_category = category;
	m_prio = prio;
}

void Task::set_status(Status status) {
	m_status = status;
}

void Task::set_priority(Priority prio) {
	m_prio = prio;
}

void Task::display() const {
	std::cout << "Task ID " << m_task_id << std::endl; 
	std::cout << "Title " << m_title << std::endl;
        std::cout << "Description" << m_description << std::endl;
	std::cout << "Deadline" << m_deadline << std::endl;
	std::cout << "Category" << m_category << std::endl;
	std::cout << "Priority" << static_cast<int>(m_prio) << std::endl;
	std::count << "Status" << static_cast<int>(m_status) << std::endl;

}

std::string Task::get_task_id() const {
       	return m_task_id;
}

std::string Task::get_title() const { 
	return m_title; 
}

Status Task::get_status() const { 
	return m_status; 
}

int Task::get_priority() const { 
	return static_cast<int>(m_prio);
}

bool Task::operator==(const Task& other) const {
	return m_task_id == other.m_task_id;
}

bool Task::operator<(const Task& other) const {
	return m_deadline < deadline;
}

Task& Task::operator++() {
	if (m_status == Status::NOT_STARTED) m_status = Status::IN_PROGRESS;
	else if (m_status == Status::IN_PROGRESS) m_status = Status::COMPLETED;
        return *this;	
}

Task& Task::operator--() {
	if (m_prio == Priority::URGENT) m_prio = Priority::HIGH;
    	else if (m_prio == Priority::HIGH) m_prio = Priority::MID;
    	else if (m_prio == Priority::MID) m_prio = Priority::LOW;
    	return *this;
}

friend ostream& Task::operator<<(ostream& os, const Task& task) {
    os << task.m_task_id << "," << task.m_title << "," << task.m_description << ","
       << task.m_deadline << "," << task.m_category << "," << static_cast<int>(task.m_prio)
       << "," << static_cast<int>(task.m_status);
    return os;
}
friend istream& Task::operator>>(istream& is, Task& task) {
	int status;
	is >> status;
	int prio;
	is >> prio;
	task.set_priority(static_cast<Priority>(prio));
	task.set_status(static_cast<Status>(status));

}
