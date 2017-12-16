#include <iostream>
#include <vector>

struct Point2D
{
    Point2D(int _x=0, int _y=0):
        x(_x), y(_y)
    {
    }

    int x;
    int y;
};

std::vector<Point2D> getPoints()
{
    std::vector<Point2D> ret;
    int n; std::cin >> n;

    for(int i=0; i<n; ++i)
    {
        Point2D newPoint;
        std::cin >> newPoint.x;
        std::cin >> newPoint.y;

        ret.push_back(newPoint);
    }

    return ret;
}

void printPoints(std::vector<Point2D> const& points)
{
    for(std::vector<Point2D>::const_iterator it = points.begin(); it != points.end(); ++it)
        std::cout << "x = " << (*it).x << " y = " << (*it).y << std::endl;
}

float getPolygonArea(std::vector<Point2D> const& pointsP)
{
    if(pointsP.size() <= 2)
    {
        std::cout << "Not a polygon!" << std::endl;
        return 0;
    }

    std::vector<Point2D> points = pointsP;
    points.push_back(*(points.begin()));

    float ret = 0;
    std::vector<Point2D>::const_iterator slow = points.begin(),
            fast = (slow + 1);

    for(; fast != points.end(); ++fast, ++slow)
        ret += ((fast->x - slow->x) * (fast->y + slow->y) * 0.5f);

    return ret;
}

bool isPolygonConvex(std::vector<Point2D> const& pointsP)
{
    /*
     * Reference:
     * https://stackoverflow.com/questions/471962/how-do-determine-if-a-polygon-is-complex-convex-nonconvex
     */

    if(pointsP.size() <= 2)
        return false;
    if(pointsP.size() == 3)
        return true;

    std::vector<Point2D> points = pointsP;
    points.push_back(*(points.begin()));
    points.push_back(*(points.begin() + 1));

    std::vector<bool> signs;
    std::vector<Point2D>::const_iterator first = points.begin(),
            middle = (first + 1),
            last = (first + 2);

    for(; last != points.end(); ++first, ++middle, ++last)
    {
        int dx1 = middle->x - first->x,
                dy1 = middle->y - first->y,
                dx2 = last->x - middle->x,
                dy2 = last->y - middle->y;

        int crossProd = dx1 * dy2 - dy1 * dx2;
        signs.push_back((crossProd > 0));
    }

    for(std::vector<bool>::const_iterator it = (signs.begin() + 1); it != signs.end(); ++it)
        if(*it != *(signs.begin()))
            return false;

    return true;
}

int main()
{
    /*
     * How to use:
     * Enter n points on the first line
     * Then on the next n lines, enter i-th point's X and Y coords
     */

    const std::vector<Point2D> points = getPoints();
    //printPoints(points);
    std::cout << std::endl;

    std::cout << "Polygon area: " << getPolygonArea(points) << std::endl;
    std::cout << "Is the polygon convex? - " << ((isPolygonConvex(points))?"Yes":"No") << std::endl;

    return 0;
}
