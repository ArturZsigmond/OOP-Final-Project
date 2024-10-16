#pragma once
#ifndef DEPARTMENTREPOSITORY_H
#define DEPARTMENTREPOSITORY_H

#include "department.h"
#include <vector>

class DepartmentRepository {
public:
    std::vector<Department> loadDepartments(const QString& filename);
};

#endif 
