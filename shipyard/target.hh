#ifndef TARGET_HH
#define TARGET_HH

#include "subject.hh"

/*!
 * \enum target_type
 * \brief Collection of "target types" that are exceptions to the
 * normal subjects. These are used to determine the behaviour and
 * nature of the Target entities.
 * \author terratenff
 */
enum target_type{
    PRIMARY = 1,
    SECONDARY = 2,
    TERTIARY = 3,
    MOUSE_POINT = 4,
    ADVERSARY = 5,
    NONE = 0
};

/*!
 * \class Target
 * \brief Customized implementation of the subjects.
 * \author terratenff
 */
class Target: public Subject
{
public:

    /*!
     * \brief A target entity is to behave differently from normal
     * subjects. Behaviour is determined with a specific role.
     * \param scene Graphics scene (bound to the graphics view
     * on the main window).
     * \param role Target type that determines behaviour and nature
     * of the target.
     */
    Target(QGraphicsScene *scene, target_type role);

    /*!
     * \fn setRole
     * \brief Setter for target role.
     * \param role Target type that determines behaviour and nature
     * of the target.
     */
    void setRole(target_type role);

    /*!
     * \fn setDefaultTargetPolygon
     * \brief Setter for the default looks of a Target entity.
     */
    void setDefaultTargetPolygon();

    /*!
     * \fn setDefaultMousePointPolygon
     * \brief Setter for the default looks of a Target Mouse Point
     * entity.
     * \pre Target type should be MOUSE_POINT if this function
     * is to be used.
     */
    void setDefaultMousePointPolygon();

    /*!
     * \fn setCourse
     * \brief Setter for a point in 2D space that acts as the
     * destination of a Target entity.
     * \param destination Destination as coordinates in 2D space.
     */
    void setCourse(XY destination);

    /*!
     * \fn update
     * \brief Updates the state of the Target entity. Considers
     * core data, general subject states and specific Target
     * states.
     */
    void update();
private:

    /*!
     * \var destination_
     * \brief Current destination of the target.
     */
    XY destination_;

    /*!
     * \var traveling_
     * \brief Flag that determines whether the target is currently
     * traveling to its destination.
     */
    bool traveling_;

    /*!
     * \var role_
     * \brief Target type. Determines the behaviour and nature
     * of the target.
     */
    target_type role_;

    /*!
     * \fn updatePrimary
     * \brief Update function specifically for the target type
     * "PRIMARY".
     */
    void updatePrimary();

    /*!
     * \fn updateSecondary
     * \brief Update function specifically for the target type
     * "SECONDARY".
     */
    void updateSecondary();

    /*!
     * \fn updateTertiary
     * \brief Update function specifically for the target type
     * "TERTIARY".
     */
    void updateTertiary();

    /*!
     * \fn updateMousePoint
     * \brief Update function specifically for the target type
     * "MOUSE_POINT".
     */
    void updateMousePoint();

    /*!
     * \fn updateAdversary
     * \brief Update function specifically for the target type
     * "ADVERSARY".
     */
    void updateAdversary();
};

#endif // TARGET_HH
