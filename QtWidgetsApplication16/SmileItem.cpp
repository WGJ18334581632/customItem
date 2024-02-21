#include "SmileItem.h"
#include <QPainter>

SmileItem::SmileItem(QGraphicsItem* parent)
	: QGraphicsItem(parent)
{
	setRect(QRect(-50, -50, 100, 100));
}

SmileItem::~SmileItem()
{
}
SmileItem::SmileItem(const QRectF& rect, QGraphicsItem* parent)
	: QGraphicsItem(parent)
{
	setRect(rect);
}
SmileItem::SmileItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem* parent)
	: QGraphicsItem(parent)
{
	setRect(x, y, w, h);
}

QRectF SmileItem::rect() const
{
	return m_rect;
}

void SmileItem::setRect(const QRectF& rect)
{
	if (m_rect == rect)
		return;

	prepareGeometryChange(); //���� setRect()���������κη�ʽ���� item �ļ�����״���������ȵ���prepareGeometryChange()���Ա�֤ QGraphicsScene �е����������µġ�
	m_rect = rect;
	m_boundingRect = QRectF(); //m_boundingRectΪ��
	updateRect();

	update(); //����paintEvent�ػ�
}

QRectF SmileItem::boundingRect() const
{
	if (m_boundingRect.isNull())
		m_boundingRect = m_rect;

	return m_boundingRect;
}

//������ updateRect() �����¼���Ц���и�����λ�����ꡢ��С
void SmileItem::updateRect()
{
	// ���ű���
	m_dScale = m_rect.width() / 100.0;
	//m_dScale = 1;

	// ���۵��е�
	m_leftEyeCenter.setX(-15 * m_dScale);
	m_leftEyeCenter.setY(-25 * m_dScale);

	// ���۵��е�
	m_rightEyecenter.setX(15 * m_dScale);
	m_rightEyecenter.setY(-25 * m_dScale);

	// ����е�
	m_smileCenter.setX(0);
	m_smileCenter.setY(10 * m_dScale);

	// �۾��Ŀ�ȡ��߶ȣ���ȵ� 2 ����
	m_dEyeWidth = m_rect.width() / (100.0 / 12);
	m_dEyeHeight = m_dEyeWidth * 2;

	// ��ĸ߶ȡ����
	m_dSmileWidth = m_rect.width() / (100.0 / 66);
	m_dSmileHeight = m_rect.height() / (100.0 / 50);

}

inline void SmileItem::setRect(qreal ax, qreal ay, qreal w, qreal h)
{
	setRect(QRectF(ax, ay, w, h));
}

void SmileItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);

	// ������
	painter->setRenderHint(QPainter::Antialiasing, true);

	// ��
	painter->setPen(Qt::NoPen);
	painter->setBrush(Qt::yellow);
	painter->drawEllipse(m_rect);

	// ����
	painter->setPen(QPen(Qt::black));
	painter->setBrush(Qt::white);
	painter->drawEllipse(
		QRectF(m_leftEyeCenter.x() - m_dEyeWidth / 2,
			m_leftEyeCenter.y() - m_dEyeHeight / 2,
			m_dEyeWidth, m_dEyeHeight));

	// ����
	painter->setPen(QPen(Qt::black));
	painter->setBrush(Qt::white);
	painter->drawEllipse(
		QRectF(m_rightEyecenter.x() - m_dEyeWidth / 2,
			m_rightEyecenter.y() - m_dEyeHeight / 2,
			m_dEyeWidth, m_dEyeHeight));

	// �� - Ц��
	painter->setPen(QPen(Qt::red));
	painter->setBrush(Qt::NoBrush);

	//QPainterPath
	QPainterPath path;
	path.arcMoveTo(
		QRectF(-m_dSmileWidth / 2,
			-(m_dSmileHeight / 2 - m_smileCenter.y()),
			m_dSmileWidth, m_dSmileHeight),
		0);
	path.arcTo(QRectF(-m_dSmileWidth / 2,
		-(m_dSmileHeight / 2 - m_smileCenter.y()),
		m_dSmileWidth, m_dSmileHeight), 0, -180);
	painter->drawPath(path);
}

