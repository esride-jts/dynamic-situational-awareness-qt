// Copyright 2017 ESRI
//
// All rights reserved under the copyright laws of the United States
// and applicable international laws, treaties, and conventions.
//
// You may freely redistribute and use this sample code, with or
// without modification, provided you include the original copyright
// notice and use restrictions.
//
// See the Sample code usage restrictions document for further information.
//

#ifndef IDENTIFYFEATURESCONTROLLER_H
#define IDENTIFYFEATURESCONTROLLER_H

#include <QMouseEvent>
#include <QObject>

#include "AbstractTool.h"

namespace Esri
{
namespace ArcGISRuntime
{
class GeoElement;
class IdentifyGraphicsOverlayResult;
class IdentifyLayerResult;
class PopupManager;
}
}

#include "TaskWatcher.h"

class IdentifyController : public Esri::ArcGISRuntime::Toolkit::AbstractTool
{
  Q_OBJECT

  Q_PROPERTY(bool busy READ busy NOTIFY busyChanged)
  Q_PROPERTY(bool active READ isActive WRITE setActive NOTIFY activeChanged)
  Q_PROPERTY(QVariantList popupManagers READ popupManagers NOTIFY popupManagersChanged)

public:

  explicit IdentifyController(QObject* parent = nullptr);
  ~IdentifyController();

  QString toolName() const override;

  void setActive(bool active) override;

  bool busy() const;
  QVariantList popupManagers() const;

private slots:
  void onMouseClicked(QMouseEvent& event);
  void onIdentifyLayersCompleted(const QUuid& taskId, QList<Esri::ArcGISRuntime::IdentifyLayerResult*> identifyResults);
  void onIdentifyGraphicsOverlaysCompleted(const QUuid& taskId, QList<Esri::ArcGISRuntime::IdentifyGraphicsOverlayResult*> identifyResults);

signals:
  void activeChanged();
  void busyChanged();
  void popupManagersChanged();

private:
  bool addGeoElementPopup(Esri::ArcGISRuntime::GeoElement* geoElement, const QString& popupTitle);

  double m_tolerance = 5.0;
  Esri::ArcGISRuntime::TaskWatcher m_layersWatcher;
  Esri::ArcGISRuntime::TaskWatcher m_graphicsOverlaysWatcher;
  QList<Esri::ArcGISRuntime::PopupManager*> m_popupManagers;
};

#endif // IDENTIFYFEATURESCONTROLLER_H