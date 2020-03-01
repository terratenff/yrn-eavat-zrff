#include "target.hh"

Target::Target(QGraphicsScene *scene, target_type role):
    Subject(scene),
    destination_(0,0),
    traveling_(false),
    role_(role)
{

}

void Target::setRole(target_type role)
{
    role_ = role;
}

void Target::setDefaultTargetPolygon()
{
    if (role_ != PRIMARY) return;

    QPolygonF polygon;
    polygon << QPointF(30, 0)
            << QPointF(-30, 12)
            << QPointF(-12, 0)
            << QPointF(-30, -12)
            << QPointF(30, 0);

    setPolygon(polygon);
}

void Target::setDefaultMousePointPolygon()
{
    if (role_ != MOUSE_POINT) return;

    QPolygonF polygon;
    polygon << QPointF(30, 0)
            << QPointF(3, 3)
            << QPointF(0, 30)
            << QPointF(-3, 3)
            << QPointF(-30, 0)
            << QPointF(-3, -3)
            << QPointF(0, -30)
            << QPointF(3, -3);

    setPolygon(polygon);
}

void Target::setCourse(XY destination)
{
    destination_ = destination;
    XY coordinates = getCoordinates();
    double angle = calculate_angle(coordinates, destination);
    setAngle(angle);
    XY movement = unit_vector(coordinates, destination);
    movement.x *= 5;
    movement.y *= 5;
    setAxisVelocity(movement);
    traveling_ = true;
}

void Target::update()
{
    Subject::update();

    switch(role_) {
    case PRIMARY: updatePrimary(); break;
    case SECONDARY: updateSecondary(); break;
    case TERTIARY: updateTertiary(); break;
    case MOUSE_POINT: updateMousePoint(); break;
    case ADVERSARY: updateAdversary(); break;
    case NONE: break;
    }
}

void Target::updatePrimary()
{
    if (traveling_) {
        if (distance(getCoordinates(), destination_) < 15) {
            traveling_ = false;
        } else {
            setCoordinates(getCoordinates() + getAxisVelocity());
        }
    }
}

void Target::updateSecondary()
{
    // TODO
}

void Target::updateTertiary()
{
    // TODO
}

void Target::updateMousePoint()
{
    setAngle(getAngle() + 5);
}

void Target::updateAdversary()
{
    // TODO
}
