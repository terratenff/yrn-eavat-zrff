#include "subject.hh"
#include <QPointF>
#include <QPen>

Subject::Subject(QGraphicsScene *scene): SubjectCore()
{
    scene_ = scene;

    QPen pen = QPen(Qt::black, 3);
    polygonItem_ = new QGraphicsPolygonItem();

    setDefaultPolygon();

    polygonItem_->setPolygon(polygon_);
    polygonItem_->setPen(pen);

    scene_->addItem(polygonItem_);
}

Subject::~Subject()
{
    scene_->removeItem(polygonItem_);
}

void Subject::setPolygon(QPolygonF polygon)
{
    polygonBase_ = polygon;
    polygon_ = polygonBase_;
}

void Subject::setDefaultPolygon()
{
    polygonBase_.clear();

    polygonBase_ << QPointF(20, 0)
                 << QPointF(-20, 8)
                 << QPointF(-8, 0)
                 << QPointF(-20, -8)
                 << QPointF(20, 0);
    polygon_ = polygonBase_;
}

void Subject::update()
{
    SubjectCore::update();

    updateGraphics();
}

void Subject::updateGraphics()
{
    XY coordinates = getCoordinates();
    double angle = getAngle();

    t_.reset();
    t_.rotate(angle);
    polygon_ = t_.map(polygonBase_);
    polygonItem_->setPolygon(polygon_);
    polygonItem_->setPos(coordinates.x, coordinates.y);
}
