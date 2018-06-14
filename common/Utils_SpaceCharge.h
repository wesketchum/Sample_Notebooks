#include "gsl/gsl_interp.h"
#include "gsl/gsl_poly.h"
#include "uboone/SpaceCharge/SpaceChargeMicroBooNE.h"
#include "fhiclcpp/make_ParameterSet.h"

void CreateSCE(std::unique_ptr<spacecharge::SpaceChargeMicroBooNE>& sce){
    fhicl::ParameterSet pset;
    std::string config("EnableCorrSCE:false EnableSimSpatialSCE:true EnableSimEfieldSCE:true RepresentationType:Parametric InputFilename:\"SpaceCharge/SCEoffsets_MicroBooNE_E273.root\"");
    fhicl::make_ParameterSet(config,pset);
        
    std::unique_ptr<spacecharge::SpaceChargeMicroBooNE> tmp(new spacecharge::SpaceChargeMicroBooNE(pset));
    sce.swap(tmp);
}
