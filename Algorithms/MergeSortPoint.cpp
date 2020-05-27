#include <iostream>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <math.h>

using namespace std;

#define MAPSIZE 500000
#define POINTSIZE 100

struct Point2D
{
    int x;
    int y;
};

pair<Point2D, Point2D> findNearestPair(vector<Point2D> points);
vector<Point2D> MergeSortPoint(vector<Point2D> parr);

int main(int argc, char *argv[])
{
    vector<Point2D> points;

    cout << "Point Size is " << POINTSIZE << "\t Map size is " << MAPSIZE << "*" << MAPSIZE << endl;
    
    srand(time(NULL));
    for (int i = 0; i < POINTSIZE; i++)
    {
        Point2D thePoint;
        thePoint.x = rand() % MAPSIZE;
        thePoint.y = rand() % MAPSIZE;
        points.push_back(thePoint);
    }

    for (int i = 0; i < POINTSIZE; i++)
    {
        cout << "Point " << i << " coordinates: " << points[i].x << " " << points[i].y << endl;
    }

    points = MergeSortPoint(points);

    for (int i = 0; i < POINTSIZE; i++)
    {
        cout << "Point " << i << " coordinates: " << points[i].x << " " << points[i].y << endl;
    }
}

vector<Point2D> MergeSortPoint(vector<Point2D> parr)
{
    if (parr.size() > 1)
    {
        vector<Point2D> Lparr, Rparr;
        vector<Point2D> Parr;

        for (int i = 0; i < parr.size() / 2; i++)
        {
            Lparr.push_back(parr[i]);
        }
        for (int j = parr.size() / 2; j < parr.size(); j++)
        {
            Rparr.push_back(parr[j]);
        }

        Lparr = MergeSortPoint(Lparr);
        Rparr = MergeSortPoint(Rparr);

        int i = 0;
        int j = 0;

        while (i < Lparr.size() && j < Rparr.size())
        {
            if (Lparr[i].y <= Rparr[j].y)
            {
                Parr.push_back(Lparr[i]);
                i++;
            }
            else
            {
                Parr.push_back(Rparr[j]);
                j++;
            }
        }

        while (i < Lparr.size())
        {
            Parr.push_back(Lparr[i]);
            i++;
        }

        while (j < Rparr.size())
        {
            Parr.push_back(Rparr[j]);
            j++;
        }

        return Parr;
    }
    else
    {
        return parr;
    }
}