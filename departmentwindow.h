#ifndef DEPARTMENTWINDOW_H
#define DEPARTMENTWINDOW_H

#include "volunteermodel.h"
#include "department.h"
#include "observer.h"
#include <QMainWindow>
#include <QStandardItemModel>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class DepartmentWindow; }
QT_END_NAMESPACE

class DepartmentWindow : public QMainWindow, public Observer {
    Q_OBJECT

public:
    explicit DepartmentWindow(const Department& department, VolunteerModel* volunteerModel, QWidget* parent = nullptr);
    ~DepartmentWindow();

    void update() override;

private slots:
    void addVolunteer();
    void assignVolunteer();
    void findMostSuitableVolunteers();

private:
    Ui::DepartmentWindow* ui;
    VolunteerModel* volunteerModel;
    Department department;
    QStandardItemModel* volunteerTableModel;
    QStandardItemModel* unassignedVolunteerModel;
    QLabel* descriptionLabel;
};

#endif
