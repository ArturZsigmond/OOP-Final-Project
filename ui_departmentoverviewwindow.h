#pragma once

#ifndef UI_DEPARTMENTOVERVIEWWINDOW_H
#define UI_DEPARTMENTOVERVIEWWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DepartmentOverviewWindow
{
public:
    QWidget* centralwidget;
    QVBoxLayout* verticalLayout;
    QTableView* departmentTableView;

    void setupUi(QMainWindow* DepartmentOverviewWindow)
    {
        if (DepartmentOverviewWindow->objectName().isEmpty())
            DepartmentOverviewWindow->setObjectName(QString::fromUtf8("DepartmentOverviewWindow"));
        DepartmentOverviewWindow->resize(800, 600);
        centralwidget = new QWidget(DepartmentOverviewWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        departmentTableView = new QTableView(centralwidget);
        departmentTableView->setObjectName(QString::fromUtf8("departmentTableView"));

        verticalLayout->addWidget(departmentTableView);

        DepartmentOverviewWindow->setCentralWidget(centralwidget);

        retranslateUi(DepartmentOverviewWindow);

        QMetaObject::connectSlotsByName(DepartmentOverviewWindow);
    } 

    void retranslateUi(QMainWindow* DepartmentOverviewWindow)
    {
        DepartmentOverviewWindow->setWindowTitle(QCoreApplication::translate("DepartmentOverviewWindow", "Department Overview", nullptr));
    } 

};

namespace Ui {
    class DepartmentOverviewWindow : public Ui_DepartmentOverviewWindow {};
} 

QT_END_NAMESPACE

#endif 
