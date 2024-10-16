#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <QString>

class Department {
public:
    QString name;
    QString description;

    Department(const QString& name, const QString& description)
        : name(name), description(description) {}
};

#endif
