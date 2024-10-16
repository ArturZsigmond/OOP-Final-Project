#ifndef VOLUNTEERREPOSITORY_H
#define VOLUNTEERREPOSITORY_H

#include "volunteer.h"
#include <vector>

class VolunteerRepository {
public:
    std::vector<Volunteer> loadVolunteers(const QString& filename);
    void saveVolunteers(const QString& filename, const std::vector<Volunteer>& volunteers);
};

#endif 
