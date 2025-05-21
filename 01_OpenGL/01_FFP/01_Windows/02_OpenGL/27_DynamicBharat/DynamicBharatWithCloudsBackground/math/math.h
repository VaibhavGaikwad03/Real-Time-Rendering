#ifndef MATH_H
#define MATH_H

struct Point2D
{
    float x;
    float y;
};

struct Point3D
{
    float x;
    float y;
    float z;
};

struct Point2D lerp(struct Point2D A, struct Point2D B, float t);
struct Point2D quadraticBezier(struct Point2D A, struct Point2D B, struct Point2D C, float t);
struct Point2D cubicBezier(struct Point2D A, struct Point2D B, struct Point2D C, struct Point2D D, float t);

#endif // MATH_H