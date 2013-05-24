#include "NonManifoldMesh.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <stdio.h>
#include <algorithm>
#include <math.h>

typedef std::vector<ManifoldVertex*> Segment;

double rellength = 0.001;

using namespace std;

double getBoundaryLength(const vector<ManifoldVertex*> &nodes)
{
    int nSize = nodes.size();
    double sum = 0.0;
    for( int i = 0; i < nSize; i++)
    {
        Point2D &p0 = nodes[i]->getCoords();
        Point2D &p1 = nodes[(i+1)%nSize]->getCoords();
        double  dx  = p1[0] - p0[0];
        double  dy  = p1[1] - p0[1];
        sum  += sqrt( dx*dx + dy*dy );
    }
    return sum;
}
///////////////////////////////////////////////////////////////////////////////

void refinedBoundary(const vector<ManifoldVertex*> &nodes,
                     const vector<bool> &nodeSelected,
                     double minlen,
                     vector<Segment> &refinedSegments)
{
    size_t numNodes = nodes.size();

    if( numNodes < 2 ) return;

    refinedSegments.resize(numNodes);

    Point2D p;
    for(size_t i = 0; i < numNodes; i++)
    {
        ManifoldVertex  *v0 = nodes[i];
        ManifoldVertex  *v1 = nodes[(i + 1)%numNodes];
        Point2D &p0 = v0->getCoords();
        Point2D &p1 = v1->getCoords();
        double  dx  = p1[0] - p0[0];
        double  dy  = p1[1] - p0[1];
        double  dl  = sqrt(dx*dx + dy*dy);
        int n = (ceil)(dl/minlen);  // Higher value better.
        refinedSegments[i].push_back(v0);
        if (n && !(nodeSelected[i] && nodeSelected[(i + 1)%numNodes]))
        {
            double dt = 1.0/(double)n;
            for(int j = 1; j < n; j++)
            {
                double t = j*dt;
                p[0]  = (1.0-t)*p0[0] + t*p1[0];
                p[1]  = (1.0-t)*p0[1] + t*p1[1];
                ManifoldVertex *vm = new ManifoldVertex;
                vm->setCoords( p );
                refinedSegments[i].push_back(vm);
            }
        }
        refinedSegments[i].push_back(v1);
    }
}

///////////////////////////////////////////////////////////////////////////////

void delaunay_triangulation(const vector<Segment> &cageSegments,
                            const vector<Segment> &modelSegments,
                            std::string maxTArea)
{
    int numCageSegments   = cageSegments.size();
    int numModelSegments  = modelSegments.size();

    // Mark all Nodes Visit = 0;
    for( int i = 0; i < numCageSegments; i++)
    {
        int nSub = cageSegments[i].size();
        for( int j = 0; j < nSub; j++)
        {
            ManifoldVertex *v = cageSegments[i][j];
            v->setVisitMark(0);
        }
    }

    for( int i = 0; i < numModelSegments; i++)
    {
        int nSub = modelSegments[i].size();
        for( int j = 0; j < nSub; j++)
        {
            ManifoldVertex *v = modelSegments[i][j];
            v->setVisitMark(0);
        }
    }

    vector<ManifoldVertex*>  trinodes;

    int numEdges = 0;
    int nodeid   = 0;

    for( int i = 0; i < numModelSegments; i++)
    {
        int nSub = modelSegments[i].size();
        numEdges += nSub-1;
        for( int j = 0; j < nSub; j++)
        {
            ManifoldVertex *v = modelSegments[i][j];
            if( !v->isVisited() )
            {
                v->setBoundaryMark(2);
                v->setID( nodeid++);
                v->setVisitMark(1);
                trinodes.push_back(v);
            }
        }
    }

    for( int i = 0; i < numCageSegments; i++)
    {
        int nSub = cageSegments[i].size();
        numEdges += nSub-1;
        for( int j = 0; j < nSub; j++)
        {
            ManifoldVertex *v = cageSegments[i][j];
            if( !v->isVisited() )
            {
                v->setBoundaryMark(1);
                v->setID( nodeid++);
                v->setVisitMark(1);
                trinodes.push_back(v);
            }
        }
    }

    ofstream ofile("/Users/Juyong/Mesh-CGL/src/Libraries/bin/data.poly", ios::out);
    ofile << trinodes.size() << " 2  0  1 " << endl;
    int numNodes = trinodes.size();
    for (int i = 0; i < numNodes; i++)
    {
        ManifoldVertex *v = trinodes[i];
        Point2D p = v->getCoords();
        ofile << v->getID() << setprecision(25) << " "
        << p[0] << " " << p[1] << " " << v->isBoundary() << endl;
    }
    ofile << numEdges << " 0 " << endl;

    int edgeid  = 1;
    for (int i = 0; i < numModelSegments; i++)
    {
        int nSub = modelSegments[i].size();
        for( int j = 0; j < nSub-1; j++)
        {
            ManifoldVertex *v0 = modelSegments[i][j];
            ManifoldVertex *v1 = modelSegments[i][j+1];
            ofile <<  edgeid++  << " " << v0->getID() << " " << v1->getID() << endl;
        }
    }

    for( int i = 0; i < numCageSegments; i++)
    {
        int nSub = cageSegments[i].size();
        for( int j = 0; j < nSub-1; j++)
        {
            ManifoldVertex *v0 = cageSegments[i][j];
            ManifoldVertex *v1 = cageSegments[i][j+1];
            ofile <<  edgeid++  << " " << v0->getID() << " " << v1->getID() << endl;
        }
    }

    ofile << " 0 " << endl;
    ofile.close();

    //call executable file
    std::string parameters = "/Users/Juyong/Mesh-CGL/src/Libraries/bin/triangle -DFpga" + maxTArea + "q33.0Y /Users/Juyong/Mesh-CGL/src/Libraries/bin/data.poly";
    int err = system(parameters.c_str());
    //end of call
}

///////////////////////////////////////////////////////////////////////////////
int loadPoly ( const string &s, vector<ManifoldVertex*> &nodes )
{
    ifstream infile( s.c_str(), ios::in);
    if( infile.fail() ) return 1;

    int numNodes, dim , nattribs, boundmark;
    infile >> numNodes >> dim >> nattribs >> boundmark;

    assert( numNodes > 0);
    assert( dim  == 2);
    assert( nattribs == 0);

    nodes.resize( numNodes );
    int vid, bid;
    Point2D p;
    for( int i = 0; i < numNodes; i++)
    {
        infile >> vid >> p[0] >> p[1];
        ManifoldVertex *v = new ManifoldVertex;
        v->setCoords(p);
        if( boundmark )
        {
            infile >> bid;
            v->setBoundaryMark(bid);
        }
        nodes[i] = v;
    }
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////

void setCageNormals( const vector<ManifoldVertex*> &cageNodes, vector<Point2D> &normals)
{
    int nSize = cageNodes.size();

    normals.resize(nSize);

    Point2D  a, nj;
    double    len;
    for( int j = 0; j < nSize; j++)
    {
        const Point2D &vj1 =  cageNodes[j]->getCoords();
        const Point2D &vj2 =  cageNodes[(j+1)%nSize]->getCoords();
        a[0]  = vj2[0] - vj1[0];
        a[1]  = vj2[1] - vj1[1];

        len   =  sqrt( a[0]*a[0] + a[1]*a[1] );
        nj[0] =  a[1]/len;
        nj[1] = -a[0]/len;
        normals[j] = nj;
    }
}
//////////////////////////////////////////////////////////////////////////////////

void setGreenBary2GlobalCoords( const vector<ManifoldVertex*> &cageNodes,
                                const vector<double>  &newSegLen,
                                const vector<double>  &orgSegLen,
                                const vector<Point2D> &cageNormals,
                                ManifoldVertex *anyNode)
{
    int nSize = cageNodes.size();

    double  xsum = 0;
    double  ysum = 0;

    const vector<double> &b =  anyNode->getBaryCoords();
    assert( b.size() == 2*nSize);

    for( int i = 0; i < nSize; i++)
    {
        Point2D &pi = cageNodes[i]->getCoords();
        double si  = newSegLen[i]/orgSegLen[i];
        double phi =  b[i];
        double psi =  b[i+ nSize];
        xsum += phi*pi[0] + psi*si*cageNormals[i][0];
        ysum += phi*pi[1] + psi*si*cageNormals[i][1];
    }
    anyNode->setCoords( xsum, ysum );
}
//////////////////////////////////////////////////////////////////////////////////

void setBary2GlobalCoords( const vector<ManifoldVertex*> &cageNodes, ManifoldVertex *anyNode )
{
    double xsum = 0.0;
    double ysum = 0.0;
    int nSize = cageNodes.size();

    vector<double> b = anyNode->getBaryCoords();
    double wsum = 0.0;
    for( int i = 0; i < nSize; i++)
    {
        Point2D &p = cageNodes[i]->getCoords();
        xsum +=  b[i]*p[0];
        ysum +=  b[i]*p[1];
        wsum    +=  b[i];
    }
    xsum /= wsum;
    ysum /= wsum;
    anyNode->setCoords( xsum, ysum );
}

//////////////////////////////////////////////////////////////////////////////////

