#include "Load.h"
#include "../MyDebug/Text.h"
#include <DxLib.h>

namespace
{
	// ロード画面が表示される最低時間
	// ロード画面が一瞬だけ表示されるのを防ぐため
	constexpr int lowest_time_load_scene = 120;
}

namespace Scene
{
	// コンストラクタ
	Load::Load(const std::shared_ptr<Scene::Manager>& manager) :
		Scene::Base(manager),
		m_time(0)
	{
	}

	// デストラクタ
	Load::~Load()
	{
	}

	// 初期化
	void Load::Init()
	{
	}

	// 終了処理
	void Load::End()
	{
	}

	// 更新
	void Load::Update()
	{
		// 現在のシーン名を表示
		Debug::Text::AddLog("LoadScene");

		// 非同期代読み込みを行っていなく、
		// ロード画面が表示される最低時間を過ぎたら
		// ロード画面を削除
		if (GetASyncLoadNum() <= 0 && 
			m_time++ >= lowest_time_load_scene)
		{
			m_manager->PopScene();
		}
	}

	// 描画
	void Load::Draw()
	{
		DrawBox(0, 0, 1920, 1080, 0x000000, true);
	}
}