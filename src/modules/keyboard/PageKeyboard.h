/*
 *  Manjaro Settings Manager
 *  Roland Singer <roland@manjaro.org>
 *  Ramon Buldó <ramon@manjaro.org>
 *
 *  Copyright (C) 2007 Free Software Foundation, Inc.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PAGEKEYBOARD_H
#define PAGEKEYBOARD_H

#include "KeyboardModel.h"
#include "KeyboardPreview.h"
#include "PageWidget.h"

#include "ApplyDialog.h"

#include <KF5/KItemModels/KSelectionProxyModel>


namespace Ui
{
class PageKeyboard;
}


class PageKeyboard : public PageWidget
{
    Q_OBJECT

public:
    explicit PageKeyboard( QWidget* parent = 0 );
    ~PageKeyboard();

    void activated();
    void apply_clicked();

private:
    Ui::PageKeyboard* ui;
    KeyboardModel* keyboardModel_;
    QSortFilterProxyModel* keyboardProxyModel_;
    KeyBoardPreview* keyboardPreview_;
    KSelectionProxyModel* layoutsSelectionProxy_;
    QSortFilterProxyModel* variantsSortProxy_;

    QString currentLayout_;
    QString currentVariant_;
    QString currentModel_;

    void setKeyboardLayout();
    void configureKeystroke();
    void setLayoutsListViewIndex( const QString& layout );
    void setVariantsListViewIndex( const QString& variant );
    void setModelComboBoxIndex( const QString& model );

    int getKeyboardRate();
    int getKeyboardDelay();

protected slots:
    void buttonRestore_clicked();
    void setDefaultIndexToVariantListView( const QModelIndex& index );
    void setKeyboardPreviewLayout( const QModelIndex& index );
};

#endif // PAGEKEYBOARD_H