//
// TrkSegInfo: track fit results at particular surfaces
// All momenta are in units of MeV/c, time in nsec WRT when the proton bunch pulse peak hits the production target,
// positions are in mm WRT the center of the tracker.
// Dave Brown (LBNL)
//
#ifndef TrkSegInfo_HH
#define TrkSegInfo_HH
#include "EventNtuple/inc/RootVectors.hh"
#include "Offline/DataProducts/inc/SurfaceId.hh"
namespace mu2e
{
  struct TrkSegInfo {

    XYZVectorF mom = XYZVectorF(); // momentum of the fit at this Surface
    XYZVectorF pos = XYZVectorF(); // position of the fit at this Surface
    double time = 0.0; // time of the fit at this Surface
    float dmom; // scalar momentum change in positive time direction
    float momerr = -1000;  // projected error on the scalar momentum
    bool inbounds = false; // was the intersection within the (literal) surface bounds? false for a near miss (out of bounds, recorded as inactive material)
    float inbfrac = -1.0; // fraction of the track position covariance, projected onto the surface, that lies inside the surface bounds; -1 if not computed
    float sigu = -1.0; // sqrt of the U diagonal of the track position covariance projected onto the plane tangent to the surface (mm); -1 if not computed or not positive
    float sigv = -1.0; // sqrt of the V diagonal of the same projection (mm); -1 if not computed or not positive
    float ndot = -2.0; // dot product of the momentum direction with the surface normal at the intersection (the normal of the tangent plane used for the covariance projection; sign follows the surface normal convention).  Small |ndot| (grazing crossings) make the projection, and so inbfrac, unreliable. -2 if the normal is not available
    bool gap = false; // was the intersection in a piecewise trajectory gap?
    int sid = SurfaceIdEnum::unknown; // SurfaceId of the intersected surface, see Offline/KinKalGeom/inc/SurfaceId.hh for definitions
    int sindex = 0; // index to the intersected surface (for multi-surface elements like StoppingTarget)
    void reset() { *this = TrkSegInfo(); }
  };
}
#endif
