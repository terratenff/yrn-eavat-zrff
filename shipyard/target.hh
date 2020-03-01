#ifndef TARGET_HH
#define TARGET_HH

#include "subject.hh"

enum target_type{
    PRIMARY = 1,
    SECONDARY = 2,
    TERTIARY = 3,
    MOUSE_POINT = 4,
    ADVERSARY = 5,
    NONE = 0
};

class Target: public Subject
{
public:
    Target(QGraphicsScene *scene, target_type role);
    void setRole(target_type role);
    void setDefaultTargetPolygon();
    void setDefaultMousePointPolygon();

    void setCourse(XY destination);

    void update();
private:
    XY destination_;
    bool traveling_;
    target_type role_;

    void updatePrimary();
    void updateSecondary();
    void updateTertiary();
    void updateMousePoint();
    void updateAdversary();
};

#endif // TARGET_HH
