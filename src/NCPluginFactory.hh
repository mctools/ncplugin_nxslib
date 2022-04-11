#ifndef NCPlugin_Factory_hh
#define NCPlugin_Factory_hh

#include "NCrystal/NCPluginBoilerplate.hh"//Common stuff (includes NCrystal
                                          //public API headers, sets up
                                          //namespaces and aliases)

namespace NCPluginNamespace {

  class PluginFactory final : public NC::FactImpl::InfoFactory {
  public:
    const char * name() const noexcept override;
    NC::Priority query( const NC::FactImpl::InfoRequest& ) const override;
    NC::InfoPtr produce( const NC::FactImpl::InfoRequest& ) const override;
  };
}

#endif
