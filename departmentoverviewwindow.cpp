#include "departmentoverviewwindow.h"
#include "ui_departmentoverviewwindow.h"

DepartmentOverviewWindow::DepartmentOverviewWindow(const std::vector<Department>& departments, VolunteerModel* volunteerModel, QWidget* parent)
    : QMainWindow(parent), ui(new Ui::DepartmentOverviewWindow), volunteerModel(volunteerModel) {
    ui->setupUi(this);
    setWindowTitle("Departments Overview");

    departmentTableModel = new QStandardItemModel(0, 3, this);
    departmentTableModel->setHorizontalHeaderLabels({ "Department", "Description", "Number of Volunteers" });
    ui->departmentTableView->setModel(departmentTableModel);

    std::vector<std::pair<int, Department>> departmentCounts;
    for (const auto& dept : departments) {
        int count = volunteerModel->getVolunteersByDepartment(dept.name).size();
        departmentCounts.push_back({ count, dept });
    }

    std::sort(departmentCounts.begin(), departmentCounts.end(), [](const std::pair<int, Department>& a, const std::pair<int, Department>& b) {
        return b.first < a.first;
        });

    for (const auto& pair : departmentCounts) {
        const auto& dept = pair.second;
        QList<QStandardItem*> items;
        items.append(new QStandardItem(dept.name));
        items.append(new QStandardItem(dept.description));
        items.append(new QStandardItem(QString::number(pair.first)));
        departmentTableModel->appendRow(items);
    }
}

DepartmentOverviewWindow::~DepartmentOverviewWindow() {
    delete ui;
}
