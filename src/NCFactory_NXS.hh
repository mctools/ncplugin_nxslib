#ifndef NCPlugin_Factory_NXS_hh
#define NCPlugin_Factory_NXS_hh

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  This file is part of NCrystal (see https://mctools.github.io/ncrystal/)   //
//                                                                            //
//  Copyright 2015-2022 NCrystal developers                                   //
//                                                                            //
//  Licensed under the Apache License, Version 2.0 (the "License");           //
//  you may not use this file except in compliance with the License.          //
//  You may obtain a copy of the License at                                   //
//                                                                            //
//      http://www.apache.org/licenses/LICENSE-2.0                            //
//                                                                            //
//  Unless required by applicable law or agreed to in writing, software       //
//  distributed under the License is distributed on an "AS IS" BASIS,         //
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  //
//  See the License for the specific language governing permissions and       //
//  limitations under the License.                                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include "NCrystal/NCPluginBoilerplate.hh"
#include "NCrystal/NCTextData.hh"
#include "NCrystal/NCInfoBuilder.hh"

namespace NCPluginNamespace {

  NC::InfoBuilder::SinglePhaseBuilder loadNXSCrystal( const NC::TextData&,
                                                      NC::Temperature,
                                                      double dcutoff_low_aa,
                                                      double dcutoff_upper_aa,
                                                      bool bkgdlikemcstas=false,//compose background curve as done in McStas
                                                                                //Sample_nxs.comp rather than as in NXSG4.
                                                      bool fixpolyatom=false//upstream nxslib
                                                                  //overestimates
                                                                  //incoherent xsect of
                                                                  //polyatomic crystals at
                                                                  //long wavelengths. Set
                                                                  //to exclude this
                                                                  //contribution (warning:
                                                                  //this might instead
                                                                  //underestimate at short
                                                                  //wavelengths).
                                                  );

}

#endif
