#ifndef INTENSITYCURVEBOX_H
#define INTENSITYCURVEBOX_H

#include <SNAPQGLWidget.h>
#include <QtInteractionDelegateWidget.h>
#include <SNAPEvents.h>

class IntensityCurveModel;
class IntensityCurveRenderer;
class IntensityCurveInteractionDelegate;

class IntensityCurveBox : public SNAPQGLWidget
{
  Q_OBJECT

  FIRES(ModelUpdateEvent)

public:
  explicit IntensityCurveBox(QWidget *parent = 0);
  virtual ~IntensityCurveBox();

  // Get the model in this widget
  irisGetMacro(Model, IntensityCurveModel *)

  // Get the renderer for this widget
  irisGetMacro(Renderer, IntensityCurveRenderer *)

  // Set the model (state) for this widget
  void SetModel(IntensityCurveModel *model);

  void paintGL();
  void resizeGL(int w, int h);

public slots:

  void onModelUpdate(const EventBucket &bucket);

private:

  IntensityCurveModel *m_Model;
  SmartPtr<IntensityCurveRenderer> m_Renderer;
  IntensityCurveInteractionDelegate *m_Delegate;

};


class IntensityCurveInteractionDelegate : public QtInteractionDelegateWidget
{
  Q_OBJECT

public:
  explicit IntensityCurveInteractionDelegate(QWidget *parent = 0);

  void mousePressEvent(QMouseEvent *);
  void mouseReleaseEvent(QMouseEvent *);
  void mouseMoveEvent(QMouseEvent *);

  // Set the model (state) for this widget
  irisGetSetMacro(Model, IntensityCurveModel *)

private:

  IntensityCurveModel *m_Model;
};

#endif // INTENSITYCURVEBOX_H