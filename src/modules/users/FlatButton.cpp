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


#include "FlatButton.h"


FlatButton::FlatButton( QWidget* parent ) :
    QPushButton( parent )
{
    setFlat( true );
}


void FlatButton::enterEvent( QEvent* )
{
    if ( !isEnabled() )
        setFlat( true );
    else
        setFlat( false );
}


void FlatButton::leaveEvent( QEvent* )
{
    setFlat( true );
}
