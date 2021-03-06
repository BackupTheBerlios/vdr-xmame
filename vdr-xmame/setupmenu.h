/***************************************************************************
 *   Copyright (C) 2007 by Thomas Maass                                    *
 *   inyourface@gmx.de                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/



#ifndef SETUPMENU_H
#define SETUPMENU_H



#include <vdr/plugin.h>
#include <string>



class cXmameSetup
{
public:
    cXmameSetup();
    ~cXmameSetup();
    int GeneralStopVDR;
    char PathRom[255];
};



class cSetupMenu : public cMenuSetupPage
{
public:
    cSetupMenu();
    ~cSetupMenu();
private:
    cXmameSetup m_tmpSetup;
protected:
    virtual void Store();
};



extern cXmameSetup g_XmameSetup;



#endif
