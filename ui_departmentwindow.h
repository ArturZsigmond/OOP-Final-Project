
#ifndef UI_DEPARTMENTWINDOW_H
#define UI_DEPARTMENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DepartmentWindow
{
public:
    QWidget* centralwidget;
    QVBoxLayout* verticalLayout;
    QTableView* volunteerTableView;
    QPushButton* addVolunteerButton;
    QPushButton* assignVolunteerButton;
    QPushButton* findSuitableVolunteersButton;
    QTableView* unassignedVolunteerTableView;

    void setupUi(QMainWindow* DepartmentWindow)
    {
        if (DepartmentWindow->objectName().isEmpty())
            DepartmentWindow->setObjectName(QString::fromUtf8("DepartmentWindow"));
        DepartmentWindow->resize(800, 600);
        centralwidget = new QWidget(DepartmentWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        volunteerTableView = new QTableView(centralwidget);
        volunteerTableView->setObjectName(QString::fromUtf8("volunteerTableView"));

        verticalLayout->addWidget(volunteerTableView);

        addVolunteerButton = new QPushButton(centralwidget);
        addVolunteerButton->setObjectName(QString::fromUtf8("addVolunteerButton"));

        verticalLayout->addWidget(addVolunteerButton);

        assignVolunteerButton = new QPushButton(centralwidget);
        assignVolunteerButton->setObjectName(QString::fromUtf8("assignVolunteerButton"));

        verticalLayout->addWidget(assignVolunteerButton);

        findSuitableVolunteersButton = new QPushButton(centralwidget);
        findSuitableVolunteersButton->setObjectName(QString::fromUtf8("findSuitableVolunteersButton"));

        verticalLayout->addWidget(findSuitableVolunteersButton);

        unassignedVolunteerTableView = new QTableView(centralwidget);
        unassignedVolunteerTableView->setObjectName(QString::fromUtf8("unassignedVolunteerTableView"));

        verticalLayout->addWidget(unassignedVolunteerTableView);

        DepartmentWindow->setCentralWidget(centralwidget);

        retranslateUi(DepartmentWindow);

        QMetaObject::connectSlotsByName(DepartmentWindow);
    } 

    void retranslateUi(QMainWindow* DepartmentWindow)
    {
        DepartmentWindow->setWindowTitle(QCoreApplication::translate("DepartmentWindow", "Department Window", nullptr));
        addVolunteerButton->setText(QCoreApplication::translate("DepartmentWindow", "Add Volunteer", nullptr));
        assignVolunteerButton->setText(QCoreApplication::translate("DepartmentWindow", "Assign Volunteer", nullptr));
        findSuitableVolunteersButton->setText(QCoreApplication::translate("DepartmentWindow", "Find Most Suitable Volunteers", nullptr));
    } 

};

namespace Ui {
    class DepartmentWindow : public Ui_DepartmentWindow {};
} 

QT_END_NAMESPACE

#endif 
