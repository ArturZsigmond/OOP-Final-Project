#pragma once
#ifndef DEPARTMENTOVERVIEWWINDOW_H
#define DEPARTMENTOVERVIEWWINDOW_H

#include "volunteermodel.h"
#include "department.h"
#include <QMainWindow>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class DepartmentOverviewWindow; }
QT_END_NAMESPACE

class DepartmentOverviewWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit DepartmentOverviewWindow(const std::vector<Department>& departments, VolunteerModel* volunteerModel, QWidget* parent = nullptr);
    ~DepartmentOverviewWindow();

private:
    Ui::DepartmentOverviewWindow* ui;
    VolunteerModel* volunteerModel;
    QStandardItemModel* departmentTableModel;
};

#endif 
