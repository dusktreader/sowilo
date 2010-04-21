
#include "camera.h"
#include "scene.h"
#include "sphere.h"
#include "glossymaterial.h"
#include "glassymaterial.h"
#include "directluminaire.h"
#include "color.h"
#include "vector.h"
#include "point.h"
#include "trajectory.h"
#include "orientation.h"
#include "circulartrajectory.h"

#include <QDir>

using namespace std;

int main(){

    // Generic Orientation
    Orientation ornt;

    // ++Test Scene
        double scn_nRefr = 1.0;
        Color  scn_ambi = CLR_WHITE;
        Color  scn_background = CLR_GRAY50;
        int    scn_depthLim = 20;
        Scene  scn( scn_nRefr, scn_ambi, scn_background, scn_depthLim );
    // --Test Scene

    // ++Test Sphere
        // Material
        double             spr_mat_kSpec = 0.9;
        double             spr_mat_xSpec = 2;
        double             spr_mat_kDiff = 0.7;
        double             spr_mat_kAmbi = 0.1;
        Color              spr_mat_shade = CLR_GREEN;
        GlossyMaterial     spr_mat( spr_mat_kSpec, spr_mat_xSpec, spr_mat_kDiff, spr_mat_kAmbi, spr_mat_shade );

        // Trajectory
        Point              spr_traj_p0( 0.0, 0.0, -10.0 );
        Vector             spr_traj_n = Vector( 0, 1.0, 0.1).u();
        double             spr_traj_v = 1.0;
        double             spr_traj_R = 5.0;
        CircularTrajectory spr_traj( spr_traj_n, spr_traj_R, spr_traj_v, spr_traj_p0 );


        // Primitive
        double             spr_R = 2.0;
        Sphere             spr( spr_R, &spr_mat, &spr_traj, &ornt );
    // --Test Sphere

    // ++Test Sphere 2
        // Material
        double             spr2_mat_kRefr = 0.8;
        double             spr2_mat_nRefr = 1.66;
        double             spr2_mat_kAmbi = 0.2;
        Color              spr2_mat_shade = CLR_RED + CLR_GRAY50;
        GlassyMaterial     spr2_mat( spr2_mat_kRefr, spr2_mat_nRefr, spr2_mat_kAmbi, spr2_mat_shade );

        // Trajectory
        Point              spr2_traj_p0( 0.0, 0.0, -10.0 );
        Trajectory         spr2_traj( spr2_traj_p0, 0.0 );


        // Primitive
        double             spr2_R = 2.0;
        Sphere             spr2( spr2_R, &spr2_mat, &spr2_traj, &ornt );
    // --Test Sphere

    // ++Test Luminaire
        Vector             lum_l = Vector( 1.0, -3.0, -1.0 ).u();
        double             lum_E = .8;
        DirectLuminaire    lum( lum_l, lum_E );
    // --Test Luminaire

    // ++Test Camera
        // Orientation
        Orientation        cam_ornt( Vector( 0, 0, -1 ) );

        Point              cam_p0( 0.0, 0.0, 10.0 );
        Vector             cam_u = Vector( 0.0, 1.0, 0.0 ).u();
        Trajectory         cam_traj( cam_p0, 0.0 );
        Camera             cam( &scn, &cam_traj, &cam_ornt, cam_u, 256, 256, 45.0 );
    // --Test Camera

    scn.addPrimitive( &spr );
    scn.addPrimitive( &spr2 );
    scn.addLuminaire( &lum );

    cam.videoRender( 0, 10, 12, "/home/d3x874/homework/sowilo/trunk/output/op-vid", ".png" );
}
