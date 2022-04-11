#include "NCPluginFactory.hh"
#include "NCrystal/NCInfo.hh"
#include "NCrystal/NCFactImpl.hh"
#include "NCrystal/NCDataSources.hh"
#include "NCrystal/NCMatCfg.hh"
#include "NCrystal/internal/NCString.hh"
#include "NCFactory_NXS.hh"
#include <iostream>

const char * NCP::PluginFactory::name() const noexcept
{
  return NCPLUGIN_NAME_CSTR "Factory";
}

NC::Priority NCP::PluginFactory::query( const NC::FactImpl::InfoRequest& cfg ) const
{
  return cfg.getDataType()=="nxs" ? Priority{100} : Priority::Unable;
}

NC::InfoPtr NCP::PluginFactory::produce( const NC::FactImpl::InfoRequest& cfg ) const
{
  nc_assert_always( cfg.getDataType()=="nxs" );
  if ( !NC::trim2(cfg.get_atomdb()).empty() )
    std::cout<<"NCrystal WARNING: atomdb parameter is ignored for .nxs files"<<std::endl;
  auto builder = loadNXSCrystal( cfg.textData(),
                                 cfg.get_temp().dbl()==-1.0?NC::Temperature{293.15}:cfg.get_temp(),
                                 cfg.get_dcutoff(),
                                 cfg.get_dcutoffup() );
  builder.dataSourceName = cfg.dataSourceName();
  return buildInfoPtr(std::move(builder));
}
