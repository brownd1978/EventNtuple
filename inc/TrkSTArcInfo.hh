//
// TrkSTArcInfo: stopping target material transit of one arc of a LoopHelix fit, copied from the
// TrkMaterialTransit (Offline RecoDataProducts) associated with the KalSeed (made by LoopHelixFit or RegrowLoopHelix when
// configured with STTransitSettings).  The payload is PROBABILISTIC: an arc is a time range over which the fit covariance gives
// a non-negligible probability of being inside the volume bounding the ST foils (ST_Front, ST_Back, ST_Inner, ST_Outer).  The
// nominal trajectory may never actually enter that volume or any foil.  The material path length is the probability-weighted
// path length in the volume times the foil fill factor, not the path through any particular foil.
//
#ifndef TrkSTArcInfo_HH
#define TrkSTArcInfo_HH
namespace mu2e
{
  struct TrkSTArcInfo {
    double tentry = 0.0; // time the probability of being inside the volume rises above threshold (ns)
    double texit = 0.0; // time it falls below threshold (ns)
    int sentry = -1; // SurfaceId of the bounding surface limiting the probability at tentry (unknown if the trajectory starts inside)
    int sexit = -1; // SurfaceId of the bounding surface limiting the probability at texit (unknown if the trajectory ends inside)
    float vollen = 0.0; // expected path length inside the bounding volume (mm)
    float matlen = 0.0; // expected path length through foil material (mm)
    float mom = 0.0; // scalar momentum at tentry (MeV/c)
    float eloss = 0.0; // energy loss estimated for matlen (MeV, positive for a loss)
    float elossvar = 0.0; // variance of that energy loss (MeV^2)
  };
}
#endif
