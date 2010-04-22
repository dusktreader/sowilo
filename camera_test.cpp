
#include "camera.h"
#include "scene.h"
#include "sphere.h"
#include "triangle.h"
#include "mattematerial.h"
#include "glossymaterial.h"
#include "glassymaterial.h"
#include "mirrormaterial.h"
#include "directluminaire.h"
#include "color.h"
#include "vector.h"
#include "point.h"
#include "trajectory.h"
#include "orientation.h"
#include "trackingorientation.h"
#include "circulartrajectory.h"

#include <QDir>

using namespace std;

int main(){
    try
    {

        // Generic Orientation
        Orientation ornt;

        // ++Test Scene
            double scn_nRefr = 1.0;
            Color  scn_ambi = CLR_WHITE;
            Color  scn_background = CLR_GRAY50;
            int    scn_depthLim = 20;
            Scene  scn( scn_nRefr, scn_ambi, scn_background, scn_depthLim );
        // --Test Scene

        vector<Primitive*> prims;
        vector<Trajectory*> trajs;
        vector<Material*> mats;

        Material* mat;
        Trajectory* traj;
        Primitive* prim;

        int n=10;
        for( int i=0; i<n; i++ )
        {
            if( i%2 )
                mat  = new GlassyMaterial( 0.8, 2.1, 0.05, CLR_WHITE );
            else
                mat  = new MirrorMaterial( 0.9, 0.1, CLR_BLUE );
            double v = .1;
            traj = new CircularTrajectory( Vector( 0, 0, 1 ), 5, v, Point( 0, 0, -10 ), i / ( n * v ) );
            prim = new Sphere( 1.0, mat, traj, &ornt );
            prims.push_back( prim );
            mats.push_back( mat );
            trajs.push_back( traj );
            scn.addPrimitive( prim );
        }

        double v = .2;
        mat = new GlossyMaterial( 0.9, 2, 0.7, 0.1, CLR_GREEN );
        traj = new CircularTrajectory( Vector( 0, 1, 0 ), 20, v, Point( -20, 0, -10 ), 0 );
        prim = new Sphere( 3.0, mat, traj, &ornt );
        prims.push_back( prim );
        mats.push_back( mat );
        trajs.push_back( traj );;
        scn.addPrimitive( prim );;

        mat = new MatteMaterial( 0.8, 0.1, CLR_RED );
        traj = new CircularTrajectory( Vector( 0, 1, 0 ), 20, -v, Point( 20, 0, -10 ), 1 / ( 2 * v ) );
        prim = new Sphere( 3.0, mat, traj, &ornt );
        prims.push_back( prim );
        mats.push_back( mat );
        trajs.push_back( traj );;
        scn.addPrimitive( prim );;

        // ++Test Luminaire
            Vector             lum_l = Vector( 1.0, -3.0, -1.0 ).u();
            double             lum_E = .8;
            DirectLuminaire    lum( lum_l, lum_E );
            scn.addLuminaire( &lum  );
        // --Test Luminaire

        // ++Test Camera
            // Orientation
            Trajectory          targTraj( Point( 0, 0, -10 ), 0, 0 );
            Trajectory          camTraj ( Point( 0, 10, 5 ), 0, 0 );
            TrackingOrientation camOrnt( &camTraj, &targTraj );

            Camera             cam( &scn, &camTraj, &camOrnt, Vector( 0, 1, 0 ), 1000, 1000, 45.0 );
        // --Test Camera

        cam.videoRender( 0, 10, 12, "/home/d3x874/homework/sowilo/trunk/output/op-vid", ".png" );

        for( int i=0; i<prims.size(); i++ )
            delete prims[i];
        for( int i=0; i<mats.size(); i++ )
            delete mats[i];
        for( int i=0; i<trajs.size(); i++ )
            delete trajs[i];
    }
    catch( LocalAssert lex )
    {
        DB_REP_VAR( lex.what() );
        DB_REP_VAR( lex.where() );
    }
}
