#ifndef BARY_H
#define BARY_H

#include <vector>
#include <tr1/array>
#include <assert.h>
#include <math.h>
#include <limits>
#include "NonManifoldMesh.h"

using namespace std;

typedef std::tr1::array<double,2>  Point2D;
typedef std::tr1::array<double,3>  Point3D;
typedef std::vector<ManifoldVertex*> Segment;

////////////////////////////////////////////////////////////////////////////////
double getBoundaryLength(const vector<ManifoldVertex*> &nodes);

void refinedBoundary(const vector<ManifoldVertex*> &nodes,
                     const vector<bool> &nodeSelected,
                     double minlen,
                     vector<Segment> &refinedSegments);

void delaunay_triangulation(const vector<Segment> &cageSegments,
                            const vector<Segment> &modelSegments,
                            std::string maxTArea);

void setGreenBary2GlobalCoords( const vector<ManifoldVertex*> &cageNodes,
                                const vector<double>  &orgseglen, 
                                const vector<double>  &newseglen, 
                                const vector<Point2D> &cageNormals,
                                ManifoldVertex *anyNode );

void setBary2GlobalCoords( const vector<ManifoldVertex*> &cageNodes, ManifoldVertex *anyNode );


#endif
