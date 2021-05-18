#include "employee.h"

std::ostream& operator<<(std::ostream& out, const Employee& rhs){
    out << "(" << rhs.id_ << ", " << rhs.name_ << ", ";
    out << ( (rhs.pManager_ == NULL) ? "none" : rhs.pManager_->name_) << ")";

    return out;
}
Employee::Employee(int id, String name, const Employee* pManager)
: id_(id), name_(name), pManager_((Employee*)pManager) {    /// 생성자 초기화 리스트

}
Employee::~Employee() {
    
}
int Employee::id() const {
    return id_;
}
String Employee::name() const {
    return name_;
}
const Employee* Employee::getManager() const {
    return pManager_;
}
void Employee::setManager(const Employee *pManager) {
    pManager_ = ( Employee* )pManager;
}
bool Employee::isManager() const {
    return pManager_ == NULL;
}