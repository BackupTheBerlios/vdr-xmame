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



#include <vdr/plugin.h>
#include "mainmenu.h"
#include "setupmenu.h"



static const char *VERSION        = "0.0.1";
static const char *DESCRIPTION    = "Xmame emulator";
static const char *MAINMENUENTRY  = "Xmame";

class cPluginXmame : public cPlugin
{
private:
public:
    cPluginXmame(void);
    virtual ~cPluginXmame();
    virtual const char *Version(void)
    {
        return VERSION;
    }
    virtual const char *Description(void)
    {
        return DESCRIPTION;
    }
    virtual const char *CommandLineHelp(void);
    virtual bool ProcessArgs(int argc, char *argv[]);
    virtual bool Initialize(void);
    virtual bool Start(void);
    virtual void Stop(void);
    virtual void Housekeeping(void);
    virtual void MainThreadHook(void);
    virtual cString Active(void);
    virtual const char *MainMenuEntry(void)
    {
        return MAINMENUENTRY;
    }
    virtual cOsdObject *MainMenuAction(void);
    virtual cMenuSetupPage *SetupMenu(void);
    virtual bool SetupParse(const char *Name, const char *Value);
    virtual bool Service(const char *Id, void *Data = NULL);
    virtual const char **SVDRPHelpPages(void);
    virtual cString SVDRPCommand(const char *Command, const char *Option, int &ReplyCode);
};



cPluginXmame::cPluginXmame(void)
{
    // Initialize any member variables here.
    // DON'T DO ANYTHING ELSE THAT MAY HAVE SIDE EFFECTS, REQUIRE GLOBAL
    // VDR OBJECTS TO EXIST OR PRODUCE ANY OUTPUT!
}



cPluginXmame::~cPluginXmame()
{
    // Clean up after yourself!
}



const char *cPluginXmame::CommandLineHelp(void)
{
    // Return a string that describes all known command line options.
    return NULL;
}



bool cPluginXmame::ProcessArgs(int argc, char *argv[])
{
    // Implement command line argument processing here if applicable.
    return true;
}



bool cPluginXmame::Initialize(void)
{
    // Initialize any background activities the plugin shall perform.
    return true;
}



bool cPluginXmame::Start(void)
{
    // Start any background activities the plugin shall perform.
    return true;
}



void cPluginXmame::Stop(void)
{
    // Stop any background activities the plugin shall perform.
}



void cPluginXmame::Housekeeping(void)
{
    // Perform any cleanup or other regular tasks.
}



void cPluginXmame::MainThreadHook(void)
{
    // Perform actions in the context of the main program thread.
    // WARNING: Use with great care - see PLUGINS.html!
}



cString cPluginXmame::Active(void)
{
    // Return a message string if shutdown should be postponed
    return NULL;
}



cOsdObject *cPluginXmame::MainMenuAction(void)
{
    return new cFolderList();
}



cMenuSetupPage *cPluginXmame::SetupMenu(void)
{
    return new cSetupMenu();
}



bool cPluginXmame::SetupParse(const char *Name, const char *Value)
{
    if      (!strcasecmp(Name, "GeneralStopVDR"))  g_XmameSetup.GeneralStopVDR = atoi(Value);
    else if (!strcasecmp(Name, "PathRom"))         strn0cpy(g_XmameSetup.PathRom, Value, sizeof(g_XmameSetup.PathRom));
    else
        return false;

    return true;
}



bool cPluginXmame::Service(const char *Id, void *Data)
{
    // Handle custom service requests from other plugins
    return false;
}



const char **cPluginXmame::SVDRPHelpPages(void)
{
    // Return help text for SVDRP commands this plugin implements
    return NULL;
}



cString cPluginXmame::SVDRPCommand(const char *Command, const char *Option, int &ReplyCode)
{
    // Process SVDRP commands this plugin implements
    return NULL;
}



VDRPLUGINCREATOR(cPluginXmame); // Don't touch this!
