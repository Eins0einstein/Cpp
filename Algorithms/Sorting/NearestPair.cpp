#include <iostream>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <math.h>

using namespace std;

#define MAPSIZE 500000
#define POINTSIZE 5000

struct Point2D
{
	int x;
	int y;
};

pair<Point2D, Point2D> findNearestPair(vector<Point2D> points);
vector<Point2D> MergeSortPointX(vector<Point2D> parr);
vector<Point2D> MergeSortPointY(vector<Point2D> parr);
double Dist(pair<Point2D, Point2D> pair);

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

	pair<Point2D, Point2D> nearestPair = findNearestPair(points);

	cout << "Nearest Pair: "
		 << "x1 = " << nearestPair.first.x << " y1 = " << nearestPair.first.y << ", x2 = " << nearestPair.second.x << " y2 = " << nearestPair.second.y << endl;
}

pair<Point2D, Point2D> findNearestPair(vector<Point2D> points)
{
	if (points.size() > 1)
	{
		pair<Point2D, Point2D> nearestPair;
		pair<Point2D, Point2D> Pair;

		double distl;
		double distr;
		double min;
		int mid = points.size() / 2;

		vector<Point2D> pointsL;
		vector<Point2D> pointsR;
		vector<Point2D> pointsS;

		points = MergeSortPointX(points);

		for (int i = 0; i < mid; i++)
		{
			pointsL.push_back(points[i]);
		}
		for (int j = mid; j < points.size(); j++)
		{
			pointsR.push_back(points[j]);
		}

		pair<Point2D, Point2D> pairl = findNearestPair(pointsL);
		pair<Point2D, Point2D> pairr = findNearestPair(pointsR);

		distl = Dist(pairl);
		distr = Dist(pairr);

		if (distl < distr)
		{
			min = distl;
			nearestPair = pairl;
		}
		else
		{
			min = distr;
			nearestPair = pairr;
		}

		for (int i = 0; i < points.size(); i++)
		{
			if (points.at(i).x < points.at(mid).x + min && points.at(i).x > points.at(mid).x - min)
			{
				pointsS.push_back(points.at(i));
			}
		}

		if (pointsS.size() > 1)
		{
			pointsS = MergeSortPointY(pointsS);

			double mindis = Dist(nearestPair);
			double pairdist;

			for (int i = 0; i < pointsS.size() - 1; i++)
			{
				int k;
				Pair.first = pointsS.at(i);

				if (pointsS.size() - i < 8)
				{
					k = pointsS.size() - i;
				}
				else
				{
					k = 8;
				}

				for (int j = 1; j < k; j++)
				{
					Pair.second = pointsS.at(i + j);
					pairdist = Dist(Pair);

					if (pairdist < mindis)
					{
						nearestPair = Pair;
					}
				}
			}
		}
		return nearestPair;
	}
	else
	{
		pair<Point2D, Point2D> errorPair;
		errorPair.first.x = 500000;
		errorPair.first.y = 500000;
		errorPair.second.x = 0;
		errorPair.second.y = 0;
		return errorPair;
	}
}

vector<Point2D> MergeSortPointY(vector<Point2D> parr)
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

		Lparr = MergeSortPointY(Lparr);
		Rparr = MergeSortPointY(Rparr);

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

vector<Point2D> MergeSortPointX(vector<Point2D> parr)
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

		Lparr = MergeSortPointX(Lparr);
		Rparr = MergeSortPointX(Rparr);

		int i = 0;
		int j = 0;

		while (i < Lparr.size() && j < Rparr.size())
		{
			if (Lparr[i].x <= Rparr[j].x)
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

double Dist(pair<Point2D, Point2D> pair)
{
	double dist;
	dist = sqrt((pair.first.x - pair.second.x) * (pair.first.x - pair.second.x) + (pair.first.y - pair.second.y) * (pair.first.y - pair.second.y));
	return dist;
}
