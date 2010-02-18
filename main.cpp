#include "camera.h"
#include "scene.h"
#include "sphere.h"
#include "triangle.h"
#include "mattematerial.h"
#include "glossymaterial.h"
#include "mirrormaterial.h"
#include "directluminaire.h"
#include "pointluminaire.h"
#include "color.h"
#include "vector.h"
#include "point.h"
#include "trajectory.h"
#include "lineartrajectory.h"
#include "circulartrajectory.h"

using namespace std;

void testIntersection(){
    Point  p0( 0.0, 0.0,  0.0 );
    Point  p1( 3.0, 3.0,  0.0 );
    Point  p2( -2.0, 4.0,  0.0 );
    Trajectory traj( p0, 0.0 );
    Material   mat;
    Triangle tri( p0, p1, p2, &mat, &traj );

    Vector d( 0.0, 0.0, -1.0 );
    Point  o( 3.0, 3.0,  2.0 );
    Ray    r( o, d, 0, 0.0, 0.0 );

    double D = tri.ix( r );
    //DB_REP_VAR( D );
}
void testRender(){

    // Scene
    double scn_nRefr = 1.0;
    Color  scn_ambi = CLR_WHITE;
    Color  scn_background = CLR_GRAY50;
    int    scn_depthLim = 5;
    Scene  scn( scn_nRefr, scn_ambi, scn_background, scn_depthLim );

    // Material
    double             mat_kDiff = 0.7;
    double             mat_kAmbi = 0.2;
    Color              mat_shade = CLR_RED;
    MatteMaterial      mat( mat_kDiff, mat_kAmbi, mat_shade );

    // Trajectory
    Point              traj_p0( 0.0, 0.0, -5.0 );
    Vector             traj_n( 0.0, 0.0, 1.0 );
    double             traj_V = 1.0;
    double             traj_R = 1.0;
    CircularTrajectory traj( traj_n, traj_R, traj_V, traj_p0 );

    // Primitive
    Point              tri_p0( -1.0, -3.0, 0.0 );
    Point              tri_p1( 2.0, 1.0, -5.0 );
    Point              tri_p2( -3.0, 2.0, 0.0 );
    Triangle           tri( tri_p0, tri_p1, tri_p2, &mat, &traj );

    // Direct Luminaire
    Vector             lum_l = Vector( 1.0, -3.0, -1.0 ).u();
    double             lum_E = 0.8;
    DirectLuminaire    lum( lum_l, lum_E );

    // Camera
    Point              cam_p0( 0.0, 0.0, 10.0 );
    Vector             cam_e( 0, 0, -1.0 );
    Vector             cam_u = Vector( 0.0, 1.0, 0.0 ).u();
    Trajectory         cam_traj( cam_p0, 0.0 );
    Camera             cam( &scn, &cam_traj, cam_e, cam_u, 256, 256, 45.0 );

    scn.addPrimitive( &tri );
    scn.addLuminaire( &lum );

    //cam.render( 0.0, "op.png" );
    cam.videoRender( 0, 2.0, 10, "op.avi" );
}

int main(int argc, char *argv[])
{
    testRender();
    return 0;

    // Scene
    double scn_nRefr = 1.0;
    Color  scn_ambi = CLR_WHITE;
    Color  scn_background( 0.75, 0.75, 0.75 );
    int    scn_depthLim = 5;
    Scene  scn( scn_nRefr, scn_ambi, scn_background, scn_depthLim );

    // Reflective Sphere
    double             spr_mat_kRefl = 0.9;
    double             spr_mat_kAmbi = 0.1;
    Color              spr_mat_shade = CLR_WHITE;
    MirrorMaterial     spr_mat( spr_mat_kRefl, spr_mat_kAmbi, spr_mat_shade );

    Point              spr_traj_p0( 0.0, 0.0, -10.0 );
    Vector             spr_traj_d(  0.0, 0.0, -1.0 );
    double             spr_traj_V = 1.0;
    //LinearTrajectory   spr_traj( spr_traj_d, spr_traj_V, spr_traj_p0 );
    Trajectory         spr_traj( spr_traj_p0, 0.0 );

    double             spr_R = 2.0;
    Sphere             spr( spr_R, &spr_mat, &spr_traj );

    // Green Sphere
    double             spr2_mat_kSpec = 0.9;
    double             spr2_mat_xSpec = 5.0;
    double             spr2_mat_kDiff = 0.5;
    double             spr2_mat_kAmbi = 0.1;
    Color              spr2_mat_shade = CLR_GREEN;
    GlossyMaterial     spr2_mat( spr2_mat_kSpec, spr2_mat_xSpec, spr2_mat_kDiff, spr2_mat_kAmbi, spr2_mat_shade );

    Point              spr2_traj_p0( 0.0, 0.0, -8.0 );
    Vector             spr2_traj_n = Vector( 0, 1.0, 0.25 ).u();
    double             spr2_traj_R = 4;
    double             spr2_traj_V = 0.5;
    CircularTrajectory spr2_traj( spr2_traj_n, spr2_traj_R, spr2_traj_V, spr2_traj_p0 );

    double             spr2_R = 1.0;
    Sphere             spr2( spr2_R, &spr2_mat, &spr2_traj );

    // Yellow Sphere (point light source)
    double             spr3_mat_kDiff = 0.0;
    double             spr3_mat_kAmbi = 1.0;
    Color              spr3_mat_shade = CLR_YELLOW;
    MatteMaterial      spr3_mat( spr3_mat_kDiff, spr3_mat_kAmbi, spr3_mat_shade );

    Point              spr3_traj_p0( 0.0, 0.0, -8.0 );
    Vector             spr3_traj_n( 0, 0, 1.0 );
    double             spr3_traj_R = 8;
    double             spr3_traj_V = 1.0;
    CircularTrajectory spr3_traj( spr3_traj_n, spr3_traj_R, spr3_traj_V, spr3_traj_p0 );

    double             spr3_R = 1.0;
    Sphere             spr3( spr3_R, &spr3_mat, &spr3_traj );

    // Direct Luminaire
    Vector             lumD_l = Vector( 1.0, -3.0, -1.0 ).u();
    double             lumD_E = .5;
    DirectLuminaire    lumD( lumD_l, lumD_E );

    // Point Luminaire
    Point              lumP_traj_p0( 0.0, 0.0, -8.0 );
    Vector             lumP_traj_n( 0, 0, 1.0 );
    double             lumP_traj_R = 6;
    double             lumP_traj_V = 1.0;
    CircularTrajectory lumP_traj( lumP_traj_n, lumP_traj_R, lumP_traj_V, lumP_traj_p0 );
    double             lumP_phi = 1000;
    PointLuminaire     lumP( lumP_phi, &lumP_traj );

    // Camera
    Point              cam_p0( 0.0, 0.0, 8.0 );
    Vector             cam_e( 0, 0, -1.0 );
    Vector             cam_u = Vector( 0.0, 1.0, 0.0 ).u();
    Trajectory         cam_traj( cam_p0, 0.0 );
    Camera             cam( &scn, &cam_traj, cam_e, cam_u, 256, 256, 45.0 );

    scn.addPrimitive( &spr );
    scn.addPrimitive( &spr2 );
    scn.addPrimitive( &spr3 );
    scn.addLuminaire( &lumD );
    scn.addLuminaire( &lumP );

    cam.videoRender( 0, 15, 5, "op.avi");


}
