#include "TestScene.h"
#include "TransporterScene.h"
#include "../MyDebug/DebugText.h"
#include "../Util/InputStateManager.h"
#include "../Resource/Image/ImageResourceManager.h"
#include <string>
#include <DxLib.h>

namespace
{
	// テスト用の画像ファイルパス
	const std::string image_file_path = "Data/Image/UI/Test.png";
}

namespace Scene
{
	// コンストラクタ
	Test::Test(const std::shared_ptr<Scene::Manager>& pSceneManager) :
		Scene::Base(pSceneManager)
	{
	}

	// デストラクタ
	Test::~Test()
	{
	}

	// 初期化
	void Test::Init()
	{
		// 画像の読み込み
		m_pImage = Resource::ImageManager::GetInstance()->Load(image_file_path);
	}

	// 終了処理
	void Test::End()
	{
	}

	// 更新
	void Test::Update()
	{
		// 現在のシーン名を表示
		Debug::Text::AddLog("TestScene");

#ifdef _DEBUG
		// Transporterシーンに遷移
		if (InputStateManager::IsTriggered(InputType::BACK))
		{
			m_pSceneManager->ChangeScene(std::make_shared<Scene::Transporter>(m_pSceneManager));
		}
#endif
	}

	// 描画
	void Test::Draw()
	{
		// 画像の描画
		DrawRotaGraph(1920 / 2, 1080 / 2, 2.0, 0.0, m_pImage->GetHandle(), true);
	}
}