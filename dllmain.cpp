#include <random>
#include "includes.h"
#include "custom-layer.hpp"
#include "hooks.hpp"
#include "mod_utils.hpp"
#include "LoadingLayer.hpp"
#include <windows.h>
#include <shellapi.h>
#include <gd.h>

bool write_bytes(
    const std::uintptr_t address,
    std::vector<uint8_t> const& bytes)
{
    return WriteProcessMemory(
        GetCurrentProcess(),
        reinterpret_cast<LPVOID>(address),
        bytes.data(),
        bytes.size(),
        nullptr);
}

class TeamGDPSWow : public cocos2d::CCLayer {
public:
    void ToMorritow(cocos2d::CCObject* pSender) {
        auto GM = gd::GameManager::sharedState();
        auto code = "ToMorritowCode";
        gd::FLAlertLayer::create(nullptr, "ToMorritow Mod", "https://discord.gg/THmJJ75Kcc", nullptr, code)->show();
    }
};

bool (__thiscall* MenuLayer_init)(CCLayer* self);
bool __fastcall MenuLayer_init_H(CCLayer* self, void*) {

    if (!MenuLayer_init(self)) return false;

    return true;
}

bool (__thiscall* GatoSexoLayer_init)(CCLayer* self);
bool __fastcall GatoSexoLayer_init_H(CCLayer* self, void*) {

    if (!GatoSexoLayer_init(self)) return false;

    auto SpriteCreditos = CCSprite::create("GJ_musicOnBtn_001.png");
    SpriteCreditos->setScale(1.0f);

    auto BottonCreditos = gd::CCMenuItemSpriteExtra::create(SpriteCreditos, self, menu_selector(ToMorritowCode::switchToToMorritowCodeButton));
    BottonCreditos->setPosition({255, 134});

    auto Menu = CCMenu::create();
    Menu->addChild(BottonCreditos);
    self->addChild(Menu);
    
    return true;
}

const char* (__thiscall* LoadingLayer_getString_org)(LoadingLayer*);
const char* __fastcall LoadingLayer_getString_h(LoadingLayer* self, void*) {

    return "Welcome to <co>GD Revolutions 2.0!</c>";

}

DWORD WINAPI thread_func(void* hModule) {

    MH_Initialize();

    auto base = reinterpret_cast<uintptr_t>(GetModuleHandle(0));

    MH_CreateHook( // MenuLayer
        reinterpret_cast<void*>(base + 0x4DE40),
        reinterpret_cast<void*>(&MenuLayer_init_H),
        reinterpret_cast<void**>(&MenuLayer_init)
    );

    MH_CreateHook(
        reinterpret_cast<void*>(base + 0x1907b0),
        reinterpret_cast<void*>(&GatoSexoLayer_init_H),
        reinterpret_cast<void**>(&GatoSexoLayer_init)
    );

    MH_CreateHook(
        reinterpret_cast<void*>(base + 0x18cf40),
        reinterpret_cast<void*>(&LoadingLayer_getString_h),
        reinterpret_cast<void**>(&LoadingLayer_getString_org)
    );

    MH_EnableHook(MH_ALL_HOOKS);

    // Load Failed
    ModUtils::write_bytes(base + 0x18B2B4, { 0xB0 , 0x01 });

    /// Practice Music
    ModUtils::write_bytes(base + 0x20C925, { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 });
    ModUtils::write_bytes(base + 0x20D143, { 0x90, 0x90 });
    ModUtils::write_bytes(base + 0x20A563, { 0x90, 0x90 });
    ModUtils::write_bytes(base + 0x20A595, { 0x90, 0x90 });

    ///Icons Hacks
    ModUtils::write_bytes(base + 0xC50A8, { 0xB0, 0x01, 0x90, 0x90, 0x90 });

    ///Colors Hacks
    ModUtils::write_bytes(base + 0xC54BA, { 0xB0, 0x01, 0x90, 0x90, 0x90 });

    return 0;
}

BOOL APIENTRY DllMain(HMODULE handle, DWORD reason, LPVOID reserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        auto h = CreateThread(0, 0, thread_func, handle, 0, 0);
        if (h)
            CloseHandle(h);
        else
            return FALSE;
    }
    return TRUE;
}