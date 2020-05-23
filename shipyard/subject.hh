#ifndef SUBJECT_HH
#define SUBJECT_HH

#include "subjectcore.hh"
#include <QGraphicsScene>
#include <QGraphicsPolygonItem>
#include <QPolygonF>
#include <QTransform>

/*!
 * \class Subject
 * \brief The graphical implementation of the subjects.
 * \author terratenff
 */
class Subject: public SubjectCore
{
public:

    /*!
     * \brief Upon the creation of a Subject, it is placed
     * onto a graphics scene so that it can be seen in a
     * graphics view that the user interacts with.
     * \param scene Graphics scene (bound to the graphics view
     * on the main window).
     */
    Subject(QGraphicsScene *scene);

    /*!
     * \brief Subject destructor.
     */
    ~Subject();

    /*!
     * \fn setPolygon
     * \brief Sets the shape of the subject, changing its look
     * on the scene.
     * \param polygon Target subject shape as a polygon.
     */
    void setPolygon(QPolygonF polygon);

    /*!
     * \fn setDefaultPolygon
     * \brief Setter for the default subject shape on the
     * scene.
     */
    void setDefaultPolygon();

    /*!
     * \fn update
     * \brief Updates the state of the subject, both data-wise
     * and graphics-wise.
     */
    virtual void update();
private:

    /*!
     * \var scene_
     * \brief Pointer to the scene present on the main window.
     */
    QGraphicsScene *scene_;

    /*!
     * \var polygonBase_
     * \brief The model polygon that the subject uses. Acts as
     * storage for the unmodified polygon.
     */
    QPolygonF polygonBase_;

    /*!
     * \var polygon_
     * \brief Actively used polygon for the subject drawing.
     * A normal state copy of this is maintained as "polygonBase_".
     */
    QPolygonF polygon_;

    /*!
     * \var t_
     * \brief Convenient variable that handles the rotation
     * of a polygon.
     */
    QTransform t_;

    /*!
     * \var polygonItem_
     * \brief The graphical polygon that is drawn on the
     * scene.
     */
    QGraphicsPolygonItem *polygonItem_;

    /*!
     * \fn updateGraphics
     * \brief Updates the graphics of the subject. Used during
     * the subject update.
     */
    void updateGraphics();
};

#endif // SUBJECT_HH
