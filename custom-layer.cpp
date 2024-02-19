#include "includes.h"
#include "custom-layer.hpp"
#include "mod_utils.hpp"
#include <MinHook.h>
#include <gd.h>

ToMorritowCode* ToMorritowCode::create() {
    auto ret = new ToMorritowCode();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool ToMorritowCode::init() {

    auto InfoSprite = CCSprite::create("GJ_infoBtn_001.png");
    InfoSprite->setScale({0.75f});

    auto InfoButton = gd::CCMenuItemSpriteExtra::create(InfoSprite, this, menu_selector(LoadingLayerXD::switchToCustomLayerButton));

    InfoButton->setPosition({541.71, 294.29});

    gd::GameManager::sharedState()->fadeInMusic("menuLoop2.mp3"); // change of song on layer

    auto backgroundSprite = CCSprite::create("CreditosBG.png"); // bg ( background )
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();

    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setColor({100, 100, 100});
    
    backgroundSprite->setZOrder(-1);

    auto MenuUwU = CCMenu::create();
    MenuUwU->addChild(InfoButton);
    MenuUwU->addChild(backgroundSprite);
    MenuUwU->setPosition(0, 0);
    addChild(MenuUwU);

    auto button = gd::CCMenuItemSpriteExtra::create(

        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(MenuLayer::onCreator)
    );

    auto menu = CCMenu::create();
    menu->addChild(button);

    menu->setPosition({25, winSize.height - 25});

    addChild(menu);

    //setKeypadEnabled(true);
	this->setKeypadEnabled(false);
	this->setTouchEnabled(true);

    return true;
}

void ToMorritowCode::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void ToMorritowCode::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void ToMorritowCode::switchToToMorritowCodeButton(CCObject* object) {

    auto layer = ToMorritowCode::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    auto transition = CCTransitionFade::create(0.5f, scene);
    CCDirector::sharedDirector()->pushScene(transition);
}

//Otra Layer xdd

NuevoLayer* NuevoLayer::create() {
    auto ret = new NuevoLayer();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool NuevoLayer::init() {

	auto winSize = CCDirector::sharedDirector()->getWinSize();

	auto m_pLayer = CCLayer::create();

	this->addChild(m_pLayer);

	auto bg = CCScale9Sprite::create("GJ_square05.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	bg->setContentSize({ 380.0f, 103.0f });
	bg->setPosition(winSize.width / 2, winSize.height / 2);
	m_pLayer->addChild(bg);

	auto m_pButtonMenu = CCMenu::create();
	m_pLayer->addChild(m_pButtonMenu,5);

	auto textBg = CCScale9Sprite::create("square02_001.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	textBg->setPosition({330.1, 160});
	textBg->setContentSize({ 320.0f, 100.f });
	textBg->setOpacity(60);
	textBg->setScaleX({0.840});
	textBg->setScaleY({0.808});
	m_pLayer->addChild(textBg);

	auto Titulo = CCLabelBMFont::create("Smile", "bigFont.fnt", 320, kCCTextAlignmentCenter);
	Titulo->setScale(0.5f);
	Titulo->setPosition({228.76, 184.1});
	m_pLayer->addChild(Titulo);

	auto SpriteLogo = CCSprite::create("dialogIcon_002.png");
    SpriteLogo->setPosition({146.49, 160.0});
    SpriteLogo->setScale({1.1f});
	m_pLayer->addChild(SpriteLogo);

	auto Texto1 = CCLabelBMFont::create("Humano", "chatFont.fnt");
	Texto1->setPosition({-48.01, -9.3});
	Texto1->setOpacity(001);

	auto Texto3 = CCLabelBMFont::create(".", "chatFont.fnt");
	Texto3->setPosition({-19, -9.3});
	Texto3->setOpacity(001);

	auto Texto4 = CCLabelBMFont::create(".", "chatFont.fnt");
	Texto4->setPosition({-13, -9.3});
	Texto4->setOpacity(001);

	auto Texto5 = CCLabelBMFont::create(".", "chatFont.fnt");
	Texto5->setPosition({-8, -9.3});
	Texto5->setOpacity(001);

	auto Texto6 = CCLabelBMFont::create("Quien", "chatFont.fnt");
	Texto6->setPosition({25, -9.3});
	Texto6->setOpacity(001);

	auto Texto7 = CCLabelBMFont::create("te", "chatFont.fnt");
	Texto7->setPosition({56, -9.3});
	Texto7->setOpacity(001);

	auto Texto8 = CCLabelBMFont::create("dejo", "chatFont.fnt");
	Texto8->setPosition({82, -9.3});
	Texto8->setOpacity(001);

	auto Texto9 = CCLabelBMFont::create("entrar?", "chatFont.fnt");
	Texto9->setPosition({123, -9.3});
	Texto9->setOpacity(001);

	//Animaciones
	Texto1->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.15, 250), CCFadeTo::create(1.0, 250), nullptr)));
	Texto3->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.35, 250), CCFadeTo::create(3.0, 250), nullptr)));
	Texto4->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.45, 250), CCFadeTo::create(4.0, 250), nullptr)));
	Texto5->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.55, 250), CCFadeTo::create(5.0, 250), nullptr)));
	Texto6->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(2.50, 250), CCFadeTo::create(8.0, 250), nullptr)));
	Texto7->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(2.75, 250), CCFadeTo::create(9.0, 250), nullptr)));
	Texto8->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(2.85, 250), CCFadeTo::create(10.0, 250), nullptr)));
	Texto9->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(2.95, 250), CCFadeTo::create(11.0, 250), nullptr)));

	m_pButtonMenu->addChild(Texto1);
	m_pButtonMenu->addChild(Texto3);
	m_pButtonMenu->addChild(Texto4);
	m_pButtonMenu->addChild(Texto5);
	m_pButtonMenu->addChild(Texto6);
	m_pButtonMenu->addChild(Texto7);
	m_pButtonMenu->addChild(Texto8);
	m_pButtonMenu->addChild(Texto9);

	this->runAction(CCSequence::create(CCDelayTime::create(3.5f), CCCallFuncO::create(this, callfuncO_selector(DialogPlayer001::switchToCustomLayerButton), this), nullptr));

	this->setKeypadEnabled(false);
	this->setTouchEnabled(true);
	//GameSoundManager::playEffect("chest08.ogg");
    return true;
}

void NuevoLayer::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.0f, PopTransition::kPopTransitionFade);
}

void NuevoLayer::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void NuevoLayer::switchToCustomLayerButton(CCObject* object) {
    auto layer = NuevoLayer::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.0f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}

DialogPlayer001* DialogPlayer001::create() {
    auto ret = new DialogPlayer001();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool DialogPlayer001::init() {

	AchievementNotifier::sharedState()->notifyAchievement("Egg 1", ("Has encontrando un Egg!!."), "GJ_downloadsIcon_001.png", true);

	gd::GameManager::sharedState()->fadeInMusic("secretLoop02.mp3");

	auto winSize = CCDirector::sharedDirector()->getWinSize();

	auto m_pLayer = CCLayer::create();

	this->addChild(m_pLayer);

	auto bg = CCScale9Sprite::create("GJ_square05.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	bg->setContentSize({ 380.0f, 103.0f });
	bg->setPosition(winSize.width / 2, winSize.height / 2);
	m_pLayer->addChild(bg);

	auto m_pButtonMenu = CCMenu::create();
	m_pLayer->addChild(m_pButtonMenu,5);

	auto textBg = CCScale9Sprite::create("square02_001.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	textBg->setPosition({330.1, 160});
	textBg->setContentSize({ 320.0f, 100.f });
	textBg->setOpacity(60);
	textBg->setScaleX({0.840});
	textBg->setScaleY({0.808});
	m_pLayer->addChild(textBg);

	auto Titulo = CCLabelBMFont::create("ToMorritow", "bigFont.fnt", 320, kCCTextAlignmentCenter);
	Titulo->setScale(0.5f);
	Titulo->setPosition({256.240, 189.3});
	m_pLayer->addChild(Titulo);

	auto SpriteLogo = CCSprite::create("ToMorritowDialog.png");
    SpriteLogo->setPosition({146.49, 160.0});
    SpriteLogo->setScale({1.1f});
	m_pLayer->addChild(SpriteLogo);

	auto Texto1 = CCLabelBMFont::create("Yo", "chatFont.fnt");
	Texto1->setPosition({-70.01, -9.3});
	Texto1->setOpacity(001);

	auto Texto3 = CCLabelBMFont::create("le", "chatFont.fnt");
	Texto3->setPosition({-50, -9.3});
	Texto3->setOpacity(001);

	auto Texto4 = CCLabelBMFont::create("deje", "chatFont.fnt");
	Texto4->setPosition({-24, -9.3});
	Texto4->setOpacity(001);

	auto Texto5 = CCLabelBMFont::create("entrar.", "chatFont.fnt");
	Texto5->setPosition({14, -9.3});
	Texto5->setOpacity(001);

	//Animaciones
	Texto1->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.50, 250), CCFadeTo::create(1.0, 250), nullptr)));
	Texto3->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(2.5, 250), CCFadeTo::create(3.0, 250), nullptr)));
	Texto4->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(4.0, 250), CCFadeTo::create(4.0, 250), nullptr)));
	Texto5->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(5.5, 250), CCFadeTo::create(5.0, 250), nullptr)));

	m_pButtonMenu->addChild(Texto1);
	m_pButtonMenu->addChild(Texto3);
	m_pButtonMenu->addChild(Texto4);
	m_pButtonMenu->addChild(Texto5);

	this->runAction(CCSequence::create(CCDelayTime::create(5.9f), CCCallFuncO::create(this, callfuncO_selector(DialogPlayer002::switchToCustomLayerButton), this), nullptr));

	this->setKeypadEnabled(false);
	this->setTouchEnabled(true);
	//GameSoundManager::playEffect("chest08.ogg");
    return true;
}

void DialogPlayer001::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.0f, PopTransition::kPopTransitionFade);
}

void DialogPlayer001::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void DialogPlayer001::switchToCustomLayerButton(CCObject* object) {
    auto layer = DialogPlayer001::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.0f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}

DialogPlayer002* DialogPlayer002::create() {
    auto ret = new DialogPlayer002();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool DialogPlayer002::init() {

	auto winSize = CCDirector::sharedDirector()->getWinSize();

	auto m_pLayer = CCLayer::create();

	this->addChild(m_pLayer);

	auto bg = CCScale9Sprite::create("GJ_square05.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	bg->setContentSize({ 380.0f, 103.0f });
	bg->setPosition(winSize.width / 2, winSize.height / 2);
	m_pLayer->addChild(bg);

	auto m_pButtonMenu = CCMenu::create();
	m_pLayer->addChild(m_pButtonMenu,5);

	auto textBg = CCScale9Sprite::create("square02_001.png", { 0.0f, 0.0f, 80.0f, 80.0f });
	textBg->setPosition({330.1, 160});
	textBg->setContentSize({ 320.0f, 100.f });
	textBg->setOpacity(60);
	textBg->setScaleX({0.840});
	textBg->setScaleY({0.808});
	m_pLayer->addChild(textBg);

	auto Titulo = CCLabelBMFont::create("Smile", "bigFont.fnt", 320, kCCTextAlignmentCenter);
	Titulo->setScale(0.5f);
	Titulo->setPosition({228.76, 184.1});
	m_pLayer->addChild(Titulo);

	auto SpriteLogo = CCSprite::create("dialogIcon_017.png");
    SpriteLogo->setPosition({146.49, 160.0});
    SpriteLogo->setScale({1.1f});
	m_pLayer->addChild(SpriteLogo);

	auto Texto1 = CCLabelBMFont::create("Ok", "chatFont.fnt");
	Texto1->setPosition({-68.01, -9.3});
	Texto1->setOpacity(001);

	auto Texto3 = CCLabelBMFont::create("Entonces", "chatFont.fnt");
	Texto3->setPosition({-19, -9.3});
	Texto3->setOpacity(001);

	auto Texto4 = CCLabelBMFont::create("Bienvenido", "chatFont.fnt");
	Texto4->setPosition({53, -9.3});
	Texto4->setOpacity(001);

	auto Texto5 = CCLabelBMFont::create("Player", "chatFont.fnt");
	Texto5->setPosition({113, -9.3});
	Texto5->setOpacity(001);

	//Animaciones
	Texto1->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.20, 250), CCFadeTo::create(1.0, 250), nullptr)));
	Texto3->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(1.50, 250), CCFadeTo::create(3.0, 250), nullptr)));
	Texto4->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(2.20, 250), CCFadeTo::create(4.0, 250), nullptr)));
	Texto5->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(3.50, 250), CCFadeTo::create(5.0, 250), nullptr)));

	m_pButtonMenu->addChild(Texto1);
	m_pButtonMenu->addChild(Texto3);
	m_pButtonMenu->addChild(Texto4);
	m_pButtonMenu->addChild(Texto5);

	this->runAction(CCSequence::create(CCDelayTime::create(4.5f), CCCallFuncO::create(this, callfuncO_selector(EggEastterOWO::switchToCustomLayerButton), this), nullptr));

	this->setKeypadEnabled(false);
	this->setTouchEnabled(true);
	//GameSoundManager::playEffect("chest08.ogg");
    return true;
}

void DialogPlayer002::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.0f, PopTransition::kPopTransitionFade);
}

void DialogPlayer002::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void DialogPlayer002::switchToCustomLayerButton(CCObject* object) {
    auto layer = DialogPlayer002::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(0.0f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}

EggEastterOWO* EggEastterOWO::create() {
    auto ret = new EggEastterOWO();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool EggEastterOWO::init() {

	gd::GameManager::sharedState()->fadeInMusic("Desarrollo.mp3");

	auto winSize = CCDirector::sharedDirector()->getWinSize();

	auto TextoLabel = CCLabelBMFont::create("Mods Developer by ToMorritow", "chatFont.fnt");
	TextoLabel->setPosition({ winSize.width / 2, winSize.height / 2 });
	TextoLabel->setScale({1.0f});
	TextoLabel->setTag(5);
	TextoLabel->runAction(CCRepeatForever::create(CCSequence::create(
    CCEaseInOut::create(CCMoveBy::create(3.0, { 0,4 }), 2.0),
    CCEaseInOut::create(CCMoveBy::create(3.0, { 0,-4 }), 2.0), nullptr)));
	addChild(TextoLabel);

	auto LinkUwu = CCLabelBMFont::create("Regresando al GDPS en 1 minuto restante.", "chatFont.fnt");
	LinkUwu->setOpacity(100);
	LinkUwu->setPosition(224.785, -55.150);
	addChild(LinkUwu);

	this->runAction(CCSequence::create(CCDelayTime::create(59.0f), CCCallFuncO::create(this, callfuncO_selector(EggEastterOWO::Eventouwu), this), nullptr));

	
	auto GM = gd::GJAccountManager::sharedState();
    std::string Nombre = GM->m_sUsername;
    std::string mensaje = "Hola " + Nombre + " uwu";
    auto bienvenida = CCLabelBMFont::create(mensaje.c_str(), "bigFont.fnt");
    bienvenida->setPosition({92, 13.6});
    bienvenida->setScale({0.421f});
    bienvenida->setZOrder(2);
    addChild(bienvenida);
	

	//menu_selector(CreatorLayer::onExit);

    return true;
}

void EggEastterOWO::Eventouwu(cocos2d::CCObject*) {
	CCApplication::sharedApplication()->openURL("https://www.youtube.com/channel/UCJ73MdeBMcrLuSRE-A5TQqg"); //Mi Canal fue borrado...
	this->runAction(CCSequence::create(CCDelayTime::create(1.0f), CCCallFuncO::create(this, callfuncO_selector(ToMorritowCode::switchToToMorritowCodeButton), this), nullptr));
	auto Chambea = gd::FLAlertLayer::create(nullptr, "Gracias", "Ok", nullptr, "Gracias por Apoyar el <cy>mod</c>\nuwu");
	Chambea->show();
	}

void EggEastterOWO::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.0f, PopTransition::kPopTransitionFade);
}

void EggEastterOWO::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void EggEastterOWO::switchToCustomLayerButton(CCObject* object) {
    auto layer = EggEastterOWO::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(2.0f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}

//Loading uwu
LoadingLayerXD* LoadingLayerXD::create() {
    auto ret = new LoadingLayerXD();
    if (ret && ret->init()) {
        ret->autorelease();
    } else {
        delete ret;
        ret = nullptr;
    }
    return ret;
}

bool LoadingLayerXD::init() {

	//Aqui el codigo xdd
	this->runAction(CCSequence::create(CCDelayTime::create(3.0f), CCCallFuncO::create(this, callfuncO_selector(NuevoLayer::switchToCustomLayerButton), this), nullptr));
	GameSoundManager::sharedState()->stopBackgroundMusic();

    return true;
}

void LoadingLayerXD::keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.0f, PopTransition::kPopTransitionFade);
}

void LoadingLayerXD::backButtonCallback(CCObject* object) {
    keyBackClicked();
}

void LoadingLayerXD::switchToCustomLayerButton(CCObject* object) {
    auto layer = LoadingLayerXD::create();
    auto scene = CCScene::create();
    scene->addChild(layer);
    
    auto transition = CCTransitionFade::create(2.0f, scene);
    
    CCDirector::sharedDirector()->pushScene(transition);
}