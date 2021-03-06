/*
    Copyright (C) 2013 by Jelle Hellemans

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#include <crystalspace.h>
#include "inetwork/socket.h"
#include "inetwork/eventmanager.h"

using namespace CS::Network::Socket;
using namespace CS::Network::EventManager;



class NetworkEventServerTest : public csApplicationFramework, public csBaseEventHandler
{
  // Stuff for displaying the info message
  csRef<iGraphics3D> g3d;
  csRef<iFont> font;
  
  csRef<iSocketManager> socketManager;
  csRef<iEventManager> eventManager;
  
public:
  bool OnKeyboard (iEvent&);
  bool HandleEvent (iEvent &);

  /// Construct our game. This will just set the application ID for now.
  NetworkEventServerTest ();

  /// Destructor.
  ~NetworkEventServerTest ();

  /// Final cleanup.
  void OnExit ();

  /**
   * Main initialization routine. This routine will set up some basic stuff
   * (like load all needed plugins, setup the event handler, ...).
   * In case of failure this routine will return false. You can assume
   * that the error message has been reported to the user.
   */
  bool OnInitialize (int argc, char* argv[]);

  /**
   * Run the application.
   * First, there are some more initialization (everything that is needed 
   * by EventTest1 to use Crystal Space), then this routine fires up the main
   * event loop. This is where everything starts. This loop will  basically
   * start firing events which actually causes Crystal Space to function.
   * Only when the program exits this function will return.
   */
  bool Application ();
  
  void Frame ();
  bool SetupModules ();
  
  // Declare the name of this event handler.
  CS_EVENTHANDLER_NAMES("application.eventtest")
      
  /* Declare that we're not terribly interested in having events
     delivered to us before or after other modules, plugins, etc. */
  CS_EVENTHANDLER_NIL_CONSTRAINTS
};
