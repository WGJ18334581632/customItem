#pragma once

#include <QGraphicsItem>
#include <QRectF>

class SmileItem : public QGraphicsItem
{
public:
	explicit SmileItem(QGraphicsItem* parent = NULL);
	explicit SmileItem(const QRectF& rect, QGraphicsItem* parent);
	explicit SmileItem(qreal x, qreal y, qreal w, qreal h, QGraphicsItem* parent);

	QRectF rect() const;

	void setRect(const QRectF& rect);

	~SmileItem();

protected:
	QRectF boundingRect() const; //override
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget); //override


private:
	QRectF m_rect;

	mutable QRectF m_boundingRect;

	void updateRect();

	inline void setRect(qreal ax, qreal ay, qreal w, qreal h);


	// 缩放比例
	double m_dScale;

	// 左眼、右眼、嘴的中点
	QPointF m_leftEyeCenter;
	QPointF m_rightEyecenter;
	QPointF m_smileCenter;

	// 眼睛的宽度、高度
	double m_dEyeWidth;
	double m_dEyeHeight;

	// 嘴的高度、宽度
	double m_dSmileWidth;
	double m_dSmileHeight;
};

