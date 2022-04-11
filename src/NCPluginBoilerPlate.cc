#define NCPLUGIN_BOILERPLATE_CC

#include "NCPluginFactory.hh"

void NCP::registerPlugin()
{
  NC::FactImpl::registerFactory(std::make_unique<NCP::PluginFactory>());
  NC::DataSources::addRecognisedFileExtensions("nxs");
};
