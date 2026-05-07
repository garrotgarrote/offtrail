#include "QtDeviceScaledPixmap.h"

#include <QApplication>

#include "utilityQt.h"

qreal QtDeviceScaledPixmap::devicePixelRatio()
{
	QApplication* app = dynamic_cast<QApplication*>(QCoreApplication::instance());
	return app->devicePixelRatio();
}

QtDeviceScaledPixmap::QtDeviceScaledPixmap() {}

QtDeviceScaledPixmap::QtDeviceScaledPixmap(const QString& filePath): m_pixmap(filePath)
{
	m_pixmap.setDevicePixelRatio(devicePixelRatio());
}

QtDeviceScaledPixmap::~QtDeviceScaledPixmap() {}

const QPixmap& QtDeviceScaledPixmap::pixmap() const
{
	return m_pixmap;
}

qreal QtDeviceScaledPixmap::width() const
{
	return m_pixmap.width() / devicePixelRatio();
}

qreal QtDeviceScaledPixmap::height() const
{
	return m_pixmap.height() / devicePixelRatio();
}

void QtDeviceScaledPixmap::scaleToWidth(int width)
{
	m_pixmap = m_pixmap.scaledToWidth(
		static_cast<int>(width * devicePixelRatio()), Qt::SmoothTransformation);
	m_pixmap.setDevicePixelRatio(devicePixelRatio());
}

void QtDeviceScaledPixmap::scaleToHeight(int height)
{
	m_pixmap = m_pixmap.scaledToHeight(
		static_cast<int>(height * devicePixelRatio()), Qt::SmoothTransformation);
	m_pixmap.setDevicePixelRatio(devicePixelRatio());
}

void QtDeviceScaledPixmap::mirror(bool horizontal, bool vertical)
{
	auto orientation_h = (horizontal ? Qt::Horizontal : Qt::Orientations(0x0));
	auto orientation_v = (vertical   ? Qt::Vertical   : Qt::Orientations(0x0));

	m_pixmap = QPixmap::fromImage(m_pixmap.toImage().flipped(orientation_h | orientation_v));
	m_pixmap.setDevicePixelRatio(devicePixelRatio());
}

void QtDeviceScaledPixmap::colorize(QColor color)
{
	m_pixmap = utility::colorizePixmap(m_pixmap, color);
}
