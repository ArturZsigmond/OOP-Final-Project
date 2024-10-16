#include "departmentwindow.h"
#include "ui_departmentwindow.h"
#include <QInputDialog>
#include <QMessageBox>

DepartmentWindow::DepartmentWindow(const Department& department, VolunteerModel* volunteerModel, QWidget* parent)
    : QMainWindow(parent), ui(new Ui::DepartmentWindow), volunteerModel(volunteerModel), department(department) {
    ui->setupUi(this);
    setWindowTitle(department.name);

    
    descriptionLabel = new QLabel(department.description, this);
    ui->verticalLayout->insertWidget(0, descriptionLabel); 

    volunteerTableModel = new QStandardItemModel(0, 4, this);
    volunteerTableModel->setHorizontalHeaderLabels({ "Name", "Email", "Interests", "Department" });
    ui->volunteerTableView->setModel(volunteerTableModel);

    unassignedVolunteerModel = new QStandardItemModel(0, 4, this);
    unassignedVolunteerModel->setHorizontalHeaderLabels({ "Name", "Email", "Interests", "Department" });
    ui->unassignedVolunteerTableView->setModel(unassignedVolunteerModel);

    connect(ui->addVolunteerButton, &QPushButton::clicked, this, &DepartmentWindow::addVolunteer);
    connect(ui->assignVolunteerButton, &QPushButton::clicked, this, &DepartmentWindow::assignVolunteer);
    connect(ui->findSuitableVolunteersButton, &QPushButton::clicked, this, &DepartmentWindow::findMostSuitableVolunteers);

    volunteerModel->addObserver(this);
    update();
}

DepartmentWindow::~DepartmentWindow() {
    volunteerModel->removeObserver(this);
    delete ui;
}

void DepartmentWindow::update() {
    volunteerTableModel->clear();
    volunteerTableModel->setHorizontalHeaderLabels({ "Name", "Email", "Interests", "Department" });
    unassignedVolunteerModel->clear();
    unassignedVolunteerModel->setHorizontalHeaderLabels({ "Name", "Email", "Interests", "Department" });

    auto volunteers = volunteerModel->getVolunteersByDepartment(department.name);
    std::sort(volunteers.begin(), volunteers.end(), [](const Volunteer& a, const Volunteer& b) {
        return a.name < b.name;
        });
    for (const auto& v : volunteers) {
        QList<QStandardItem*> items;
        items.append(new QStandardItem(v.name));
        items.append(new QStandardItem(v.email));
        items.append(new QStandardItem(v.interests.join(", ")));
        items.append(new QStandardItem(v.department));
        volunteerTableModel->appendRow(items);
    }

    auto unassignedVolunteers = volunteerModel->getVolunteersByDepartment("");
    std::sort(unassignedVolunteers.begin(), unassignedVolunteers.end(), [](const Volunteer& a, const Volunteer& b) {
        return a.name < b.name;
        });
    for (const auto& v : unassignedVolunteers) {
        QList<QStandardItem*> items;
        items.append(new QStandardItem(v.name));
        items.append(new QStandardItem(v.email));
        items.append(new QStandardItem(v.interests.join(", ")));
        items.append(new QStandardItem(v.department));
        unassignedVolunteerModel->appendRow(items);
    }
}

void DepartmentWindow::addVolunteer() {
    QString name = QInputDialog::getText(this, "Add Volunteer", "Name:");
    if (name.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Name cannot be empty.");
        return;
    }

    QString email = QInputDialog::getText(this, "Add Volunteer", "Email:");
    if (email.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Email cannot be empty.");
        return;
    }

    QString interests = QInputDialog::getText(this, "Add Volunteer", "Interests (comma separated):");

    Volunteer newVolunteer(name, email, interests.split(","));
    volunteerModel->addVolunteer(newVolunteer);
}

void DepartmentWindow::assignVolunteer() {
    QModelIndexList selected = ui->unassignedVolunteerTableView->selectionModel()->selectedIndexes();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Selection Error", "No volunteer selected.");
        return;
    }

    QString email = selected.at(1).data().toString();
    auto volunteers = volunteerModel->getVolunteers();
    for (auto& v : volunteers) {
        if (v.email == email) {
            v.department = department.name;
            volunteerModel->updateVolunteer(v);
            break;
        }
    }
}


void DepartmentWindow::findMostSuitableVolunteers() {
    auto unassignedVolunteers = volunteerModel->getVolunteersByDepartment("");
    struct Score {
        int count;
        Volunteer volunteer;
    };
    std::vector<Score> scores;

    for (const auto& v : unassignedVolunteers) {
        int count = 0;
        for (const auto& interest : v.interests) {
            if (department.description.contains(interest, Qt::CaseInsensitive)) {
                ++count;
            }
        }
        scores.push_back({ count, v });
    }

    std::sort(scores.begin(), scores.end(), [](const Score& a, const Score& b) {
        return a.count > b.count;
        });

    unassignedVolunteerModel->clear();
    unassignedVolunteerModel->setHorizontalHeaderLabels({ "Name", "Email", "Interests", "Department" });

    int count = 0;
    for (const auto& score : scores) {
        if (count++ >= 3) break;
        QList<QStandardItem*> items;
        items.append(new QStandardItem(score.volunteer.name));
        items.append(new QStandardItem(score.volunteer.email));
        items.append(new QStandardItem(score.volunteer.interests.join(", ")));
        items.append(new QStandardItem(score.volunteer.department));
        unassignedVolunteerModel->appendRow(items);
    }
}

