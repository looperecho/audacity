/**********************************************************************

   Audacity - A Digital Audio Editor
   Copyright 1999-2009 Audacity Team
   File License: wxWidgets

   Dan Horgan

******************************************************************//**

\file CommandBuilder.h
\brief Contains declaration of CommandBuilder class.

*//*******************************************************************/

#ifndef __COMMANDBUILDER__
#define __COMMANDBUILDER__

#include "../MemoryX.h"

class AudacityProject;
class OldStyleCommand;
using OldStyleCommandPointer = std::shared_ptr<OldStyleCommand>;
class wxString;

// CommandBuilder has the task of validating and interpreting a command string.
// If the string represents a valid command, it builds the command object.

class CommandBuilder
{
   private:
      bool mValid;
      OldStyleCommandPointer mCommand;
      wxString mError;

      void Failure(const wxString &msg = {});
      void Success(const OldStyleCommandPointer &cmd);
      void BuildCommand( AudacityProject *project,
         const wxString &cmdName, const wxString &cmdParams);
      void BuildCommand( AudacityProject *project, const wxString &cmdString);
   public:
      CommandBuilder(AudacityProject *project, const wxString &cmdString);
      CommandBuilder(AudacityProject *project, const wxString &cmdName,
                     const wxString &cmdParams);
      ~CommandBuilder();
      bool WasValid();
      OldStyleCommandPointer GetCommand();
      const wxString &GetErrorMessage();
};
#endif /* End of include guard: __COMMANDBUILDER__ */
