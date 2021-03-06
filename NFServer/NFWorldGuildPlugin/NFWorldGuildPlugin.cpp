// -------------------------------------------------------------------------
//    @FileName      :    NFWorldGuildPlugin.cpp
//    @Author           :    LvSheng.Huang
//    @Date             :    2015-05-24 08:51
//    @Module           :   NFWorldGuildPlugin
//
// -------------------------------------------------------------------------


//#include "stdafx.h"
#include "NFCWorldGuildModule.h"
#include "NFWorldGuildPlugin.h"

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
#if NF_PLATFORM == NF_PLATFORM_WIN
#endif // NF_PLATFORM
    CREATE_PLUGIN(pm, NFWorldGuildPlugin)
};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFWorldGuildPlugin)
};

//////////////////////////////////////////////////////////////////////////

const int NFWorldGuildPlugin::GetPluginVersion()
{
    return 0;
}

const std::string NFWorldGuildPlugin::GetPluginName()
{
    GET_PLUGIN_NAME(NFWorldGuildPlugin)
}

void NFWorldGuildPlugin::Install()
{

    REGISTER_MODULE(pPluginManager, NFCWorldGuildModule)


}

void NFWorldGuildPlugin::Uninstall()
{
    UNREGISTER_MODULE(pPluginManager, NFCWorldGuildModule)
}
