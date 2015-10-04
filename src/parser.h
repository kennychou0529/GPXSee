#ifndef PARSER_H
#define PARSER_H

#include <QXmlStreamReader>
#include <QDateTime>
#include <QPointF>

struct TrackPoint
{
	QPointF coordinates;
	QDateTime timestamp;
	qreal elevation;
};

class Parser
{
public:
	bool loadFile(QIODevice *device, QVector<TrackPoint> &data);
	QString errorString() const;

private:
	bool parse(QVector<TrackPoint> &data);
	void gpx(QVector<TrackPoint> &data);
	void trek(QVector<TrackPoint> &data);
	void trekPoints(QVector<TrackPoint> &data);
	void trekPointData(QVector<TrackPoint> &data);

	void handleTrekPointAttributes(QVector<TrackPoint> &data,
	  const QXmlStreamAttributes &attr);
	void handleTrekPointData(QVector<TrackPoint> &data, QStringRef element,
	  const QString &value);

	QXmlStreamReader _reader;
};

#endif // PARSER_H
