
#include "camera.h"
#include "scene.h"
#include "sphere.h"
#include "glossymaterial.h"
#include "directluminaire.h"
#include "color.h"
#include "vector.h"
#include "point.h"
#include "trajectory.h"
#include "orientation.h"
#include "circulartrajectory.h"

using namespace std;

int main(){

    // Generic Orientation
    Orientation ornt;

    // ++Test Scene
        double scn_nRefr = 1.0;
        Color  scn_ambi = CLR_WHITE;
        Color  scn_background = CLR_GRAY50;
        int    scn_depthLim = 5;
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
        Vector             spr_traj_n( 0, 0, 1.0 );
        double             spr_traj_v = 1.0;
        double             spr_traj_R = 3.0;
        CircularTrajectory spr_traj( spr_traj_n, spr_traj_R, spr_traj_v, spr_traj_p0 );


        // Primitive
        double             spr_R = 2.0;
        Sphere             spr( spr_R, &spr_mat, &spr_traj, &ornt );
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
    scn.addLuminaire( &lum );

    cam.videoRender( 0, 10, 12, "/data/op-vid", ".png" );
}
