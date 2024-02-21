#include "QtWidgetsApplication16.h"
#include <QtWidgets/QApplication>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "SmileItem.h"
#include <QDebug>


int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	SmileItem* pItem = new SmileItem();
	pItem->setRect(QRect(-25, -25, 50, 50));
	pItem->setPos(-100, 50); //���ڳ����е�λ��

	SmileItem* pItem2 = new SmileItem();
	pItem2->setRect(QRect(-50, -50, 100, 100));
	pItem2->setPos(100, 50);

	SmileItem* pItem3 = new SmileItem();
	pItem3->setRect(QRect(-75, -75, 150, 150));
	pItem3->setPos(250, 50);

	// ��Ц�������������
	QGraphicsScene* pScene = new QGraphicsScene();
	pScene->addItem(pItem);
	//pScene->setSceneRect(0, 0, 100, 100);
	pScene->addItem(pItem2);
	pScene->addItem(pItem3);

	// Ϊ��ͼ���ó���
	QGraphicsView* pView = new QGraphicsView();
	pView->setScene(pScene);
	pView->show();
	qDebug() << pScene->sceneRect();

	return a.exec();
}

