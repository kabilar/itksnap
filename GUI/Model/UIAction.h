#ifndef UIACTION_H
#define UIACTION_H

#include "itkObject.h"
#include "IRISException.h"
#include <list>

class GlobalUIModel;
class IRISException;

/**
  Actions can generate warnings. These warnings are simply instances of
  IRISException that are not fired, but rather stored. Warnings do not
  keep the action from executing, they are just messages that are sent to
  the user. Optimally, there should be an option to react to the message.

  Actions can also generate errors, but these are achieved by throwing an
  exception.
  */
class IRISWarning : public IRISException
{
public:
  IRISWarning(const char *fmt, ...);
  IRISWarning();

  virtual ~IRISWarning() throw() {}


};

class IRISWarningList : public std::list<IRISWarning> {};


/**
  A UI action is an object used to perform complex actions in SNAP. This
  includes any actions that are undoable.
  */
class UIAbstractAction : public itk::Object
{
public:
  typedef std::list<IRISWarning> WarningList;
  typedef std::list<IRISWarning>::const_iterator WarningIter;

  virtual void Execute() = 0;

  virtual void Initialize(GlobalUIModel *model);

  bool HasWarnings() const
    { return m_Warnings.size() > 0; }

  const WarningList &GetWarnings() const
    { return m_Warnings; }


protected:

  GlobalUIModel *m_Model;

  std::list<IRISWarning> m_Warnings;

};



class UIUndoableAction : public UIAbstractAction
{
public:
  virtual void Undo() = 0;

};

#endif // UIACTION_H
