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

#ifndef WITHINAREAALERTCONDITIONDATA_H
#define WITHINAREAALERTCONDITIONDATA_H

#include "AlertConditionData.h"

namespace Esri
{
namespace ArcGISRuntime
{
class GeoElement;
class Graphic;
}
}

class WithinAreaAlertConditionData : public AlertConditionData
{
  Q_OBJECT

public:
  explicit WithinAreaAlertConditionData(const QString& name,
                                        AlertLevel level,
                                        AlertSource* source,
                                        AlertTarget* target,
                                        QObject* parent = nullptr);

  ~WithinAreaAlertConditionData();
};

#endif // WITHINAREAALERTCONDITIONDATA_H
