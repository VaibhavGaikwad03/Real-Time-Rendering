#include "math.h"

struct Point2D lerp(struct Point2D A, struct Point2D B, float t)
{
    struct Point2D result;

    result.x = (1 - t) * A.x + t * B.x;
    result.y = (1 - t) * A.y + t * B.y;

    return result;
}

struct Point2D quadraticBezier(struct Point2D A, struct Point2D B, struct Point2D C, float t)
{
    struct Point2D D = lerp(A, B, t);
    struct Point2D E = lerp(B, C, t);

    return lerp(D, E, t);
}

struct Point2D cubicBezier(struct Point2D A, struct Point2D B, struct Point2D C, struct Point2D D, float t)
{
    struct Point2D AB = lerp(A, B, t);
    struct Point2D BC = lerp(B, C, t);
    struct Point2D CD = lerp(C, D, t);

    struct Point2D ABC = lerp(AB, BC, t);
    struct Point2D BCD = lerp(BC, CD, t);

    return lerp(ABC, BCD, t);
}
