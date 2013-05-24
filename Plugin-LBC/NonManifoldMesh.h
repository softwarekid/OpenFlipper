#ifndef NONMANIFOLD_H
#define NONMANIFOLD_H

#include <stdlib.h>
#include <stdio.h>

#include <math.h>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <tr1/array>
#include <assert.h>
#include <fstream>
#include <limits>
#include <algorithm>

#include "GeomPredicates.hpp"

typedef std::tr1::array<double,2>  Point2D;
typedef std::tr1::array<double,3>  Point3D;

using namespace std;

#define OUTSIDE      1
#define ON_BOUNDARY  0
#define INSIDE      -1

struct BoundingBox {
    BoundingBox() {
        coordSystem = 'c';
    };

    BoundingBox(const vector<Point2D> &p) {

        double xmin = p[0][0];
        double xmax = p[0][0];

        double ymin = p[0][1];
        double ymax = p[0][1];

        for (size_t i = 0; i < p.size(); i++) {
            xmin = min(xmin, p[i][0]);
            xmax = max(xmax, p[i][0]);

            ymin = min(ymin, p[i][1]);
            ymax = max(ymax, p[i][1]);
        }

        assert(xmin <= xmax);
        assert(ymin <= ymax);

        minCorner[0] = xmin;
        minCorner[1] = ymin;

        maxCorner[0] = xmax;
        maxCorner[1] = ymax;
    }

    BoundingBox(const Point2D &pl, const Point2D & pu) {
        minCorner = pl;
        maxCorner = pu;
    }

    void extend(double percent) {
        double xlen = fabs(maxCorner[0] - minCorner[0]);
        double ylen = fabs(maxCorner[1] - minCorner[1]);

        minCorner[0] -= percent * minCorner[0];
        minCorner[1] -= percent * minCorner[1];

        maxCorner[0] += percent * maxCorner[0];
        maxCorner[1] += percent * maxCorner[1];
    }

    int orient(const Point2D  &qpoint) const {
        if (qpoint[0] < minCorner[0]) return OUTSIDE;
        if (qpoint[1] < minCorner[1]) return OUTSIDE;

        if (qpoint[0] > maxCorner[0]) return OUTSIDE;
        if (qpoint[1] > maxCorner[1]) return OUTSIDE;

        return INSIDE;
    }
    char coordSystem;
    Point2D minCorner;
    Point2D maxCorner;
};

class ManifoldVertex;
class ManifoldEdge;
class ManifoldFace;
class Cell;

struct RelationRep 
{
    void clearAllRelations() {
        relations0.clear();
        relations2.clear();
        relations3.clear();
    }

    size_t getSize( int e ) {
        switch( e ) {
        case 0:
            return relations0.size();
            break;
        case 2:
            return relations2.size();
            break;
        case 3:
            return relations3.size();
            break;
        }
        return 0;
    }

    void clearRelations(int e ) {
        switch( e ) {
        case 0:
            relations0.clear();
            break;
        case 2:
            relations2.clear();
            break;
        case 3:
            relations3.clear();
            break;
        }
    }

    bool hasRelation( const ManifoldVertex *v)
    {
        if( find(relations0.begin(), relations0.end(), v ) == relations0.end() ) return 0;
        return 1;
    }

    bool hasRelation( const ManifoldFace *f)
    {
        if( find(relations2.begin(), relations2.end(), f ) == relations2.end() ) return 0;
        return 1;
    }

    bool hasRelation( const Cell *c)
    {
        if( find(relations3.begin(), relations3.end(), c ) == relations3.end() ) return 0;
        return 1;
    }

    void addRelation( const ManifoldVertex *v ) {
        if( find(relations0.begin(), relations0.end(), v ) == relations0.end() )
            relations0.push_back(const_cast<ManifoldVertex*>( v ));
        sort( relations0.begin(), relations0.end() );
    }

    void addRelation( const ManifoldFace *f ) {
        if( find(relations2.begin(), relations2.end(), f ) == relations2.end() )
            relations2.push_back(const_cast<ManifoldFace*>( f ));
        sort( relations2.begin(), relations2.end() );
    }

    void addRelation( const Cell *c ) {
        if( find(relations3.begin(), relations3.end(), c ) == relations3.end() )
            relations3.push_back(const_cast<Cell*> (c) );
        sort( relations3.begin(), relations3.end() );
    }

    vector<ManifoldVertex*>  relations0;
    vector<ManifoldFace*>    relations2;
    vector<Cell*>    relations3;
};

struct MeshEntity 
{
    MeshEntity() {
       relationRep = NULL;
    }
    void   setID( size_t i ) {
        id = i;
    }
    size_t getID() const     {
        return id;
    }

    size_t getNumRelations(int e) const
    {
        if( relationRep ) return relationRep->getSize(e);
        return 0;
    }

    bool hasRelation( const ManifoldVertex *v) const {
        if( relationRep ) return relationRep->hasRelation(v);
        return 0;
    }
    bool hasRelation( const ManifoldFace *f) const {
        if( relationRep ) return relationRep->hasRelation(f);
        return 0;
    }
    bool hasRelation( const Cell *c) const {
        if( relationRep ) return relationRep->hasRelation(c);
        return 0;
    }

    void addRelation( const ManifoldVertex *v) {
        if( relationRep == NULL ) relationRep = new RelationRep;
        relationRep->addRelation(v);
    }

    void  addRelation( const ManifoldFace   *f) {
        if( relationRep == NULL ) relationRep = new RelationRep;
        relationRep->addRelation(f);
    }

    void  addRelation( const Cell *c) {
        if( relationRep == NULL ) relationRep = new RelationRep;
        relationRep->addRelation(c);
    }

    void clearRelations(int e) {
        if( relationRep == NULL ) return;
        relationRep->clearRelations( e );
    }

    void clearAllRelations();

    const vector<ManifoldVertex*>  &getRelations0() const
    {
          assert(relationRep);
          return relationRep->relations0;
    }

    const vector<ManifoldFace*>    &getRelations2() const
    {
          assert(relationRep);
          return relationRep->relations2;
    }

    const vector<Cell*>  &getRelations3() const
    {
          assert(relationRep);
          return relationRep->relations3;
    }
    void setVisitMark ( bool b) { visitMark = b; }
    bool isVisited() const { return visitMark; }

    mutable bool   visitMark;
    size_t id;
    RelationRep  *relationRep;
};

class ManifoldVertex : public MeshEntity
{
public:
    static int global_id;

    ManifoldVertex() {
        pristine = 1;
        boundaryMark = 0;
    }

    void setBoundaryMark( int b) { boundaryMark = b; }
    int  isBoundary() const { return boundaryMark; }

    //  It will set the Pristine Coordinates;
    void setCoords( double x, double y) {
        xyCoords[0]  = x;
        xyCoords[1]  = y;
    }

    void setCoords( const Point2D &p) {
        xyCoords = p;
    }

    const Point2D &getCoords() const {
        return xyCoords;
    }

    Point2D &getCoords() {
        return xyCoords;
    }

    void setBaryCoords(const vector<double> &b)
    {
         baryCoords = b;
    }
    const vector<double> &getBaryCoords() const { return baryCoords; }

    // A pristine coordinate is the coordinate that is input and not derived from
    // intersections.

    bool  isPristine() const   {
        return pristine;
    }
    void  setPristine( bool p) {
        pristine = p;
    }

    // Returns if the vertex is on the boundary of the domain.
    // Useful in applying boundary conditions in simulation.
    bool hasBoundary( const ManifoldVertex *v);

    Point2D   xyCoords;
private:
    bool   pristine;
    int    boundaryMark;
    vector<double>  baryCoords;
};

inline long double l_length( const Point2D &p0, const Point2D &p1)
{
    long double dx = (long double)p0[0] - (long double)p1[0];
    long double dy = (long double)p0[1] - (long double)p1[1];
    return sqrt( dx*dx + dy*dy );
}

inline double length( const Point2D &p0, const Point2D &p1)
{
    double dx = p0[0] - p1[0];
    double dy = p0[1] - p1[1];
    return sqrt( dx*dx + dy*dy );
}

class ManifoldEdge : public MeshEntity
{
public:
    ManifoldEdge() {}
    ManifoldEdge( const ManifoldVertex *v0, const ManifoldVertex *v1) {
        setNodes( v0, v1);
    }

    void setNodes( const ManifoldVertex *v0, const ManifoldVertex *v1) {
        cutNode = NULL;
        connect[0] = const_cast<ManifoldVertex*>(v0);
        connect[1] = const_cast<ManifoldVertex*>(v1);
    }

    BoundingBox  getBoundingBox() const;

    ManifoldVertex *getNodeAt( int i ) const {
        return connect[i];
    }

    // Given an edge, returns all the cells adjacent to it
    // (Will return chidren if present, otherwise original tet cells)

    const vector<Cell*> &getRelations13() const;

    ManifoldVertex *cutNode;  // Node that cuts this edge into two pieces.

private:
    ManifoldVertex *connect[2];   // An edge is an undirected connection of 2 nodes.
};

class ManifoldFace : public MeshEntity
{
public:
    ManifoldFace() {}

    ManifoldFace( const vector<ManifoldVertex*> &v) {
        setNodes( v );
    }
    //  Description:   A face is a set of unordered edges which form a close loop.

    // Which cut surface this face belong to ? Here I assume that a face is exclusively
    //  is part of only one surface, if not, it is divided.

    int  getSurfaceID();

    int  getSize(int e) const {
        if( e == 0) return connect.size();
    }

    // Returns the set of nodes forming this faces. The vertices are unordered...
    void  setNodes( const vector<ManifoldVertex*> &v) {
        connect = v;
    }

    void reverse() {
        std::reverse( connect.begin(), connect.end() );
    }

    const vector<ManifoldVertex*>  &getNodes() {
        return connect;
    }

    ManifoldVertex *getNodeAt( int i ) const {
        return connect[i];
    }

    BoundingBox  getBoundingBox() const;

    //  Return tree if any of its vertices is on the domain boundary.
    bool hasBoundary( const ManifoldFace *f);

    // Given a face, return all the cells adjacent to it;  ( Will return childen if present, otherwise original tets );
    const vector<Cell*> &getRelations3() const;

    // Returns 1 if the given cell faces any interface ( embedded surface )
    bool hasInterface();

    bool contains(Point2D &p) const;

    void addChild( ManifoldFace *f) {
        children.push_back(f);
    }
    const vector<ManifoldFace*> &getChildren() const  {
        return children;
    }
    const vector<ManifoldFace*>  getLeafs() const;

    // Returns the Root Face(Triangle).
    ManifoldFace*  getUnduplicated() const;

// Return the entire hierarchy of duplicated cells:
    const vector<ManifoldFace*>  &getAllDuplicated();

    const ManifoldFace*  getRoot() const;

    // Boolean queries:
    bool isChildOf( const ManifoldFace *parent);
    bool isParentOf( const ManifoldFace *child);

    vector<ManifoldFace> getDelaunay();

private:
    int   surfaceID;
    vector<ManifoldEdge*>    edges;
    vector<ManifoldVertex*>  connect;
    vector<ManifoldFace*>    children;   // When this face is split, children are created.
};

inline
double polygon_area(double *x, double *y, int n)
{
    // Anticlockwise sequence will give positive area;
    double sum = 0.0;
    for (int i = 1; i <= n; i++)
        sum += x[i]*(y[(i + 1) % n] - y[(i - 1) % n]);
    sum *= 0.5;
    return sum;
}

class Cell :  public MeshEntity
{
    // Description:  A cell is unordered set of boundary faces which form a closed region.

    bool isDuplicated();

    // For a cell, nodes are always unordered, i.e. there is no direction.
    vector<ManifoldVertex*>  getNodes();

    Cell*  getUnduplicated() const;
    const vector<Cell*>  &getAllDuplicated();   // Return the entire hierarchy of duplicated cells:

    // Get the root of the cell in a hierachical decomposition (Always a tet element from the original mesh)
    const Cell*  getRoot() const;

    // It returns all the subcells of the given tet element ( of the original mesh );
    const vector<Cell*> &getLeafs() const;

    // Given a cell; returns the parent cell; ( A cell is divided into children after the cut with embedded surfaces )
    const Cell*  getParent() const;

    // Given a tetrahdron cell ( of the input mesh) return all subdivided polyhedra cells;
    const vector<Cell*>  &getChildren() const;

    // Boolean queries:
    bool isChildOf( const Cell *parent);
    bool isParentOf( const Cell *child);

    // Returns true, if any of its vertices in on the domain boundary..
    bool hasBoundary( const Cell *c);

    // Returns true, if the parents cell is cut by the surfaces.
    bool hasInterface( const Cell *c);

    //  How many differerent surfaces cut this cell ?
    int  getNumCutSurface();

    // Returns all the cells adjacent to it ( via vertices )
    const vector<Cell*>  &getRelations303() const;

    // Return all the cells adjacents to it ( via edges )
    const vector<Cell*>  &getRelations313() const;

    // Given a cell, return all the cells adjacent to it ( via faces )
    const vector<Cell*> &getRelations323() const;

private:
    vector<ManifoldFace*>   faces;
    vector<Cell*>   children;
};

///////////////////////////////////////////////////////////////////////////////

struct Mesh {

    const vector<ManifoldVertex*> &getNodes() const {
        return nodes;
    }

    ManifoldVertex *getNodeAt( size_t id ) const
    {
        return nodes[id]; 
    }
    vector<ManifoldVertex*>  nodes;
};

///////////////////////////////////////////////////////////////////////////////

struct FaceMesh : public Mesh 
{
    static vector<ManifoldFace*> getRelations112( const ManifoldVertex *v0, const ManifoldVertex *v1);
    // Returns the size of mesh of a given entity:
    // ( vertex = 0; edge = 1; face = 2; cell = 3 )

    size_t getSize( int e ) const {
        if( e == 0) return nodes.size();
        if( e == 2) return faces.size();
        return 0;
    }

    ManifoldFace* getFaceAt( int id ) { return faces[id]; }

    ManifoldFace* intersect(const ManifoldEdge *edge);

    // Which face contains the given vertex coords;
    ManifoldFace* contains( const ManifoldVertex *v) const;

    void addFace(ManifoldFace *f) {
        faces.push_back(f);
    }

    vector<ManifoldEdge*>  getEdges();

    void build_relations( int src, int dst);

    vector<ManifoldFace*>  faces;
private:
    void build_relations00();
    void build_relations02();
    void build_relations22();
};
///////////////////////////////////////////////////////////////////////////////

struct CellMesh : public Mesh {
    // Returns the size of mesh of a given entity:
    // ( vertex = 0; edge = 1; face = 2; cell = 3 )
    size_t getSize( int e ) const;

    vector<Cell*>  cells;
};

///////////////////////////////////////////////////////////////////////////////

int
intersect(const ManifoldEdge *seg1, const ManifoldEdge *seg2, Point2D &point);

void intersect( const ManifoldFace *face, const ManifoldEdge *cutedge,
                vector<int> &faceSides, vector<ManifoldVertex*> &newnodes);

///////////////////////////////////////////////////////////////////////////////

struct GeomCurve {
    BoundingBox getBoundingBox() const;

    // Return new edge
    ManifoldEdge* splitAt(ManifoldEdge *edge, ManifoldVertex *vertex);

    size_t getNumSegments() const {
        return edges.size();
    }

    // Return edge segment whose first node is the given vertex "v".
    ManifoldEdge *findFirst( const ManifoldVertex *v) const {
        list<ManifoldEdge*>::const_iterator it;
        for( it = edges.begin(); it != edges.end(); ++it) {
            ManifoldEdge *e = *it;
            if( e->getNodeAt(0) == v ) return e;
        }
        return NULL;
    }

    // Get the last new node inserted in the chain.
    ManifoldVertex *getLastSplitNode() const {
        return splitNodes.back();
    }

    // Refine linearly every edge segment...
    void linear_refine(int ntimes = 1);

    // Derefine the edge segments..
    void linear_derefine(int ntimes = 1);

    // Returns if the curve form a linear chain.
    bool isChain() const;

    list<ManifoldEdge*>      edges;
    vector<ManifoldVertex*>  splitNodes; // Nodes where the curve is split
};

///////////////////////////////////////////////////////////////////////////////

class NonManifoldMesh2D
{
public:
    static int SplitPolygon( const ManifoldFace *parent, vector<GeomCurve> &curves, vector<ManifoldFace*> &children);

    NonManifoldMesh2D () {
        exactinit();
        mesh = NULL;
    }

    // Load Tetrahedral mesh. This is the base mesh in which embedding take place. Return 0 on success.
    int  readEmbeddedTriMesh ( const string &s);

    int  addEmbeddedTriMesh (const vector<ManifoldFace*> &faces);
    int  addEmbeddedTriMesh (const vector<Point3D>  &nodes, const vector<int>  &faces);

    //  Load a cut curves in the domain.
    //  Curves can be concave, non-simple, and non-manifold.
    int  readCutCurves( const string &s);

    GeomCurve*  addCutCurve( vector<ManifoldEdge*>  &edge);
    GeomCurve*  addCutCurve( vector<ManifoldVertex*>  &v, int closed);
    GeomCurve*  addCutCurve( vector<Point2D>  &v, int closed);

    const vector<GeomCurve*> &getCurves() const {
        return cutCurves;
    }

    // Cut the volume mesh with the embedded surfaces: Lazy evaluation:
    int cutTriMesh();

    // Get  unduplicated face mesh i.e. Original embedded mesh.
    FaceMesh*  getUnduplicatedMesh() const {
        return mesh;
    }

    // Returns duplicated mesh in which the triangle  which are cut by curves are partitioned...
    FaceMesh*  getDuplicatedMesh() const;

    void saveAs( const string &s);
private:
    struct IntersectInfo {
        IntersectInfo() {
            cornerIntersect = NULL;
        }

        ManifoldFace  *orgface;    // Parent face for which we are checking intersection.
        ManifoldEdge  *orgedge;    // Edge for which we checking intersection with the face.

        // Did the intesection happened at the vertex of the edge;
        // Return 0, if on the vertex and 1 if that happened on the edge.
        ManifoldVertex*  cornerIntersect;

        vector<int>   faceSides;

        vector<ManifoldVertex*> intesectNodes;
    };
    bool face_edge_intersection( const ManifoldFace *f, const ManifoldEdge *edge, IntersectInfo &info);
    ManifoldFace* getStartingFace( GeomCurve *curve);

    FaceMesh *mesh; // representative, concrete implementation will be delegated to this class.
    vector<GeomCurve*>  cutCurves;
    int  cutTriMesh( GeomCurve *c);
    void enumerate();
};

///////////////////////////////////////////////////////////////////////////////


class NonManifoldMesh3D
{
public:
    // Load Tetrahedral mesh. This is the base mesh in which embedding take place. Return 0 on success.
    int  readEmbeddedTetMesh ( const string &s);
    int  readEmbeddedTetMesh ( const vector<ManifoldVertex*>  &node, const vector<Cell*> &cells);
    int  readEmbeddedTetMesh( const  vector<Point3D>  &nodes, const vector<int>  &cells);

    // Load a cut surface in the domain. All cut surfaces are in the form of triangle soup. Returns 0 on success.
    int  readCutSurface( const string &s);
    int  readCutSurface( const vector<ManifoldVertex*>  &nodes, const vector<ManifoldFace*>  &faces);
    int  readCutSurface( const vector<Point3D>  &nodes, const vector<int> &faces);

    // Cut the volume mesh with the embedded surfaces: Lazy evaluation:
    int cutTetMesh();

    // Get  unduplicated volume mesh i.e. Original embedded mesh.
    Mesh*  getUnduplicatedMesh() const;

    // Returns duplicated mesh in which the tets which are cut by surfaces are partitioned...
    Mesh*  getDuplicatedMesh();

    void saveAs( const string &s);
private:
    CellMesh *rep; // representative, concrete implementation will be delegated to this class.
};

#endif

