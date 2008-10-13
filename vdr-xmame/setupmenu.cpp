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



#include "setupmenu.h"



using namespace std;



cXmameSetup g_XmameSetup;



cXmameSetup::cXmameSetup()
{
    GeneralStopVDR = true;
    strncpy(PathRom, "/usr/local/share/xmame/roms", sizeof(PathRom));
}



cXmameSetup::~cXmameSetup()
{}



cSetupMenu::cSetupMenu() : m_tmpSetup(g_XmameSetup)
{
    static const char Allowed[] = "a�bcdefghijklmno�pqrstu�vwxyz0123456789-+_@/&.";
    Add(new cMenuEditBoolItem(tr("Stop VDR before play"), &m_tmpSetup.GeneralStopVDR, tr("no"), tr("yes")));
    Add(new cMenuEditStrItem(tr("Rom Path"), m_tmpSetup.PathRom, 255, Allowed));
}



cSetupMenu::~cSetupMenu()
{}



void cSetupMenu::Store()
{
    g_XmameSetup = m_tmpSetup;
    SetupStore("GeneralStopVDR", g_XmameSetup.GeneralStopVDR);
    SetupStore("PathRom", g_XmameSetup.PathRom);
}
