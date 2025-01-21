
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  This file is part of NCrystal (see https://mctools.github.io/ncrystal/)   //
//                                                                            //
//  Copyright 2015-2024 NCrystal developers                                   //
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

#include "NCTestPlugin.hh"
#include "NCrystal/internal/utils/NCMsg.hh"
#include "NCrystal/internal/utils/NCMath.hh"
#include "NCrystal/internal/utils/NCStrView.hh"

void NCP::customPluginTest()
{
  //This function is called by NCrystal after the plugin is loaded, but only if
  //the NCRYSTAL_PLUGIN_RUNTESTS environment variable is set to "1". In case of
  //errors or anything about the plugin not working, simply throw an exception
  //(which is what the nc_assert_always function does below, but feel free to
  //simply throw an exception directly).

  NCRYSTAL_MSG("Testing plugin "<<pluginName());

  // File Al.nxs
  const char * testdata =
    "space_group = 225\n"
    "lattice_a = 4.049\n"
    "lattice_b = 4.049\n"
    "lattice_c = 4.049\n"
    "lattice_alpha = 90\n"
    "lattice_beta  = 90\n"
    "lattice_gamma = 90\n"
    "debye_temp = 429.0\n"
    "[atoms]\n"
    "add_atom = Al 3.449 0.008 0.23 26.98 0.0 0.0 0.0\n";

  if ( true ) {
    NCRYSTAL_MSG("Test NCMAT data begin:");
    NCRYSTAL_RAWOUT(testdata);
    NCRYSTAL_MSG("Test NCMAT data end.");
  }

  //Let us load and exercise this testdata. We do NOT want to register the
  //testdata as a virtual file, since we want this test to not leave anything
  //registered after it is done running. So we simply put the raw data directly
  //into a MatCfg object (which is the C++ object representing a cfg-string):

  auto cfg = NC::MatCfg::createFromRawData( std::string(testdata),
                                            "",
                                            "nxs" );
  auto cfg_braggonly = NC::MatCfg::createFromRawData( std::string(testdata),
                                                      ";comp=coh_elas",
                                                      "nxs" );
  auto info = NC::createInfo( cfg );
  auto info_braggonly = NC::createInfo( cfg_braggonly );



  {
    NCRYSTAL_MSG("Loading plugins::nxslib/Al_sg225.nxs");
    auto info2 = NC::createInfo( "plugins::nxslib/Al_sg225.nxs" );
  }

  unsigned nfound = 0;
  for ( auto& e : NC::DataSources::listAvailableFiles() ) {
    if ( e.factName != "plugins" )
      continue;
    NC::StrView name(e.name);
    if (!name.startswith("nxslib/"))
      continue;
    std::string key = e.factName + "::" + e.name;
    NCRYSTAL_MSG("Loading "<<key);
    auto iii = NC::createInfo( "plugins::nxslib/Al_sg225.nxs" );
    auto sss = NC::createScatter( "plugins::nxslib/Al_sg225.nxs" );
    auto aaa = NC::createAbsorption( "plugins::nxslib/Al_sg225.nxs" );
    nfound += 1;
  }

  if ( nfound < 30 || nfound > 100 )
    NCRYSTAL_THROW(CalcError,"Unexpected number of data files from plugin");

  NCRYSTAL_MSG("All tests of plugin "<<pluginName()<<" were successful!");
}
