#include "volunteerrepository.h"
#include <QFile>
#include <QTextStream>

std::vector<Volunteer> VolunteerRepository::loadVolunteers(const QString& filename) {
    std::vector<Volunteer> volunteers;
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(",");
            if (parts.size() >= 3) {
                QStringList interests = parts.mid(2, parts.size() - 3);
                QString department = parts.last();
                volunteers.emplace_back(parts[0], parts[1], interests, department);
            }
        }
        file.close();
    }
    return volunteers;
}

void VolunteerRepository::saveVolunteers(const QString& filename, const std::vector<Volunteer>& volunteers) {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (const auto& volunteer : volunteers) {
            out << volunteer.name << "," << volunteer.email << ",";
            out << volunteer.interests.join(",") << "," << volunteer.department << "\n";
        }
        file.close();
    }
}
