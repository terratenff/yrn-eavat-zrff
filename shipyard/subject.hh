#ifndef SUBJECT_HH
#define SUBJECT_HH

#include "subjectcore.hh"
#include <QGraphicsScene>
#include <QGraphicsPolygonItem>
#include <QPolygonF>
#include <QTransform>

class Subject: public SubjectCore
{
public:
    Subject(QGraphicsScene *scene);
    ~Subject();
    void setPolygon(QPolygonF polygon);
    void setDefaultPolygon();
    virtual void update();
private:
    QGraphicsScene *scene_;
    QPolygonF polygonBase_;
    QPolygonF polygon_;
    QTransform t_;
    QGraphicsPolygonItem *polygonItem_;

    void updateGraphics();
};

#endif // SUBJECT_HH
