#include "departmentwindow.h"
#include "departmentrepository.h"
#include "volunteerrepository.h"
#include "departmentoverviewwindow.h"
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    DepartmentRepository departmentRepo;
    auto departments = departmentRepo.loadDepartments("departments.txt");

    VolunteerRepository volunteerRepo;
    auto volunteers = volunteerRepo.loadVolunteers("volunteers.txt");

    VolunteerModel volunteerModel;
    for (const auto& volunteer : volunteers) {
        volunteerModel.addVolunteer(volunteer);
    }

    std::vector<DepartmentWindow*> windows;
    for (const auto& department : departments) {
        auto* window = new DepartmentWindow(department, &volunteerModel);
        window->show();
        windows.push_back(window);
    }

    auto* overviewWindow = new DepartmentOverviewWindow(departments, &volunteerModel);
    overviewWindow->show();

    int result = a.exec();

    volunteerRepo.saveVolunteers("volunteers.txt", volunteerModel.getVolunteers());

    return result;
}
