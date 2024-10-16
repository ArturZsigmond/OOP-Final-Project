#include "departmentrepository.h"
#include <QFile>
#include <QTextStream>

std::vector<Department> DepartmentRepository::loadDepartments(const QString& filename) {
    std::vector<Department> departments;
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(",");
            if (parts.size() == 2) {
                departments.emplace_back(parts[0], parts[1]);
            }
        }
        file.close();
    }
    return departments;
}

