//
// Created by rsturza on 5/14/2021.
//

#ifndef FINAL_PROJECT_RSTURZA_RECT_H
#define FINAL_PROJECT_RSTURZA_RECT_H

#include "shape.h"

struct dimensions {
    double width;
    double height;

    /* Constructors */
    dimensions();
    dimensions(double w, double h);

    /* Overloaded Operator */
    friend std::ostream& operator << (std::ostream& outs, const dimensions &d);
};

class Rect : public Shape {
private:
    dimensions size;
public:
    /* Constructors */
    Rect();
    explicit Rect(dimensions size);
    explicit Rect(color fill);
    explicit Rect(point2D center);
    Rect(color fill, point2D center);
    Rect(double red, double green, double blue, double alpha);
    Rect(double x, double y);
    Rect(double red, double green, double blue, double alpha, double x, double y);
    Rect(color fill, double x, double y);
    Rect(double red, double green, double blue, double alpha, point2D center);
    Rect(color fill, dimensions size);
    Rect(point2D center, dimensions size);
    Rect(color fill, point2D center, dimensions size);
    Rect(double red, double green, double blue, double alpha, dimensions size);
    Rect(double x, double y, dimensions size);
    Rect(double red, double green, double blue, double alpha, double x, double y, dimensions size);
    Rect(color fill, double x, double y, dimensions size);
    Rect(double red, double green, double blue, double alpha, point2D center, dimensions size);

    /* Destructor */
    virtual ~Rect() = default;

    /* Getters */
    dimensions getSize() const;
    double getWidth() const;
    double getHeight() const;
    double getLeftX() const override;
    double getRightX() const override;
    double getTopY() const override;
    double getBottomY() const override;

    /* Setters */
    void setSize(dimensions size);
    void setSize(double width, double height);
    void setWidth(double width);
    void setHeight(double height);
    void changeSize(double deltaWidth, double deltaHeight);
    void changeWidth(double delta);
    void changeHeight(double delta);

    /* Check if two Rect objects are overlapping the user's mouse */
    bool isOverlapping(int x, int y) const;

    /* Draw */
    void draw() const override;

};

#endif //FINAL_PROJECT_RSTURZA_RECT_H
