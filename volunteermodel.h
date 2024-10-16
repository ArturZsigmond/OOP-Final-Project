#pragma once
#ifndef VOLUNTEERMODEL_H
#define VOLUNTEERMODEL_H

#include "volunteer.h"
#include "subject.h"
#include <vector>
#include <QString>

class VolunteerModel : public Subject {
public:
    void addVolunteer(const Volunteer& volunteer);
    void removeVolunteer(const QString& email);
    void updateVolunteer(const Volunteer& volunteer);
    std::vector<Volunteer> getVolunteers() const;
    std::vector<Volunteer> getVolunteersByDepartment(const QString& department) const;

private:
    std::vector<Volunteer> volunteers;
};

#endif 
