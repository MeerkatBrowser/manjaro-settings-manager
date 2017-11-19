/*
 *  This file is part of Namib Settings Manager.
 *
 *  Roland Singer <roland@namib.org>
 *
 *  Namib Settings Manager is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Namib Settings Manager is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Namib Settings Manager.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CHANGEPASSWORDDIALOG_H
#define CHANGEPASSWORDDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QStringList>


namespace Ui
{
class ChangePasswordDialog;
}

class ChangePasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePasswordDialog( QWidget* parent = 0 );
    ~ChangePasswordDialog();
    using QDialog::exec;

public slots:
    int exec( QString username );

private:
    Ui::ChangePasswordDialog* ui;
    QString username;

private slots:
    void buttonApply_clicked();
    void textbox_textChanged();

};

#endif // CHANGEPASSWORDDIALOG_H
