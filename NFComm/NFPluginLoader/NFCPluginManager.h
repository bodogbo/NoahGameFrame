// -------------------------------------------------------------------------
//    @FileName      :    NFCPluginManager.h
//    @Author           :    LvSheng.Huang
//    @Date             :    2012-12-15
//    @Module           :    NFCPluginManager
//
// -------------------------------------------------------------------------

#ifndef _NFC_PLUGIN_MANAGER_H_
#define _NFC_PLUGIN_MANAGER_H_

#include <map>
#include <string>
#include "NFCDynLib.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"

class NFCPluginManager
    : public NFIPluginManager
{
public:
	//NFCPluginManager(Theron::Framework &framework, NFIActorManager* pManager, NFIActorManager::EACTOR eActor) : NFIPluginManager(framework, pManager, eActor)
	NFCPluginManager(NFIActorManager* pManager) : NFIPluginManager(pManager)
	{
		mbOnReloadPlugin = false;
		m_pActorManager = pManager;
	}

    virtual bool Init();

    virtual bool AfterInit();

    virtual bool CheckConfig();

    virtual bool BeforeShut();

    virtual bool Shut();

    //////////////////////////////////////////////////////////////////////////
	
    virtual bool LoadPlugin();

    // virtual bool UnLoadPlugin();

    virtual void Registered(NFIPlugin* pPlugin);

    virtual void UnsRegistered(NFIPlugin* pPlugin);

	virtual bool ReInitialize();
    //////////////////////////////////////////////////////////////////////////

    virtual NFIPlugin* FindPlugin(const std::string& strPluginName);

    virtual void AddModule(const std::string& strModuleName, NFILogicModule* pModule);

    virtual void RemoveModule(const std::string& strModuleName);

    virtual NFILogicModule* FindModule(const std::string& strModuleName);

    virtual bool Execute(const float fLasFrametime, const float fStartedTime);

    //  virtual void OnReloadModule( const std::string& strModuleName, NFILogicModule* pModule );
    //
    //  virtual void ReloadPlugin( const std::string& pluginName );


protected:

    virtual bool LoadPluginLibrary(const std::string& strPluginDLLName);
    virtual bool UnLoadPluginLibrary(const std::string& strPluginDLLName);

#ifdef NF_USE_ACTOR
    virtual void HandlerEx(const NFIActorMessage& message, const Theron::Address from);

	virtual NFIActorManager* GetActorManager(){ return m_pActorManager;}
#endif

private:
    bool mbOnReloadPlugin;
	NFIActorManager* m_pActorManager;

	typedef std::map<std::string, bool> PluginNameMap;
	typedef std::map<std::string, NFCDynLib*> PluginLibMap;
	typedef std::map<std::string, NFIPlugin*> PluginInstanceMap;
	typedef std::map<std::string, NFILogicModule*> ModuleInstanceMap;

	typedef void(* DLL_START_PLUGIN_FUNC)(NFIPluginManager* pm);
	typedef void(* DLL_STOP_PLUGIN_FUNC)(NFIPluginManager* pm);


    PluginNameMap mPluginNameMap;
    PluginLibMap mPluginLibMap;
    PluginInstanceMap mPluginInstanceMap;
    ModuleInstanceMap mModuleInstanceMap;
};

#endif