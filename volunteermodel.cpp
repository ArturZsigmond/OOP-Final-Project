#include "volunteermodel.h"

void VolunteerModel::addVolunteer(const Volunteer& volunteer) {
    volunteers.push_back(volunteer);
    notifyObservers();
}

void VolunteerModel::removeVolunteer(const QString& email) {
    auto it = std::remove_if(volunteers.begin(), volunteers.end(), [&](const Volunteer& v) {
        return v.email == email;
        });
    if (it != volunteers.end()) {
        volunteers.erase(it, volunteers.end());
        notifyObservers();
    }
}

void VolunteerModel::updateVolunteer(const Volunteer& volunteer) {
    for (auto& v : volunteers) {
        if (v.email == volunteer.email) {
            v = volunteer;
            notifyObservers();
            break;
        }
    }
}

std::vector<Volunteer> VolunteerModel::getVolunteers() const {
    return volunteers;
}

std::vector<Volunteer> VolunteerModel::getVolunteersByDepartment(const QString& department) const {
    std::vector<Volunteer> result;
    for (const auto& v : volunteers) {
        if (v.department == department) {
            result.push_back(v);
        }
    }
    return result;
}
