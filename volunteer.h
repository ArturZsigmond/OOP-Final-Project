#ifndef VOLUNTEER_H
#define VOLUNTEER_H

#include <QString>
#include <QStringList>

class Volunteer {
public:
    QString name;
    QString email;
    QStringList interests;
    QString department;

    Volunteer(const QString& name, const QString& email, const QStringList& interests, const QString& department = "")
        : name(name), email(email), interests(interests), department(department) {}
};

#endif 
