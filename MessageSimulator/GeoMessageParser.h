/*******************************************************************************
 *  Copyright 2012-2018 Esri
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ******************************************************************************/

#ifndef GEOMESSAGEPARSER_H
#define GEOMESSAGEPARSER_H

#include "AbstractMessageParser.h"

#include <QFile>
#include <QXmlStreamReader>

class GeoMessageParser : public AbstractMessageParser
{
  Q_OBJECT

public:
  explicit GeoMessageParser(const QString& filePath, QObject* parent = nullptr);
  ~GeoMessageParser();

  QByteArray nextMessage() override;

  void reset() override;

  bool atEnd() const override;

private:
  Q_DISABLE_COPY(GeoMessageParser)
  GeoMessageParser() = delete;

  QFile m_device;
  QXmlStreamReader m_reader;
  bool m_isParsing = false;
};

#endif // GEOMESSAGEPARSER_H
