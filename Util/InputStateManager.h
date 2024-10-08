#pragma once
#include <map>
#include <vector>

// ボタンの入力タイプ
enum class InputType
{
	DECISION,	// 決定
	BACK,		// 戻る
	PAUSE,		// ポーズ
	UP,			// 上
	DOWN,		// 下
	RIGHT,		// 右
	LEFT,		// 左
	RIGHT_SHOULDER,	// 右ショルダー
	LEFT_SHOULDER,	// 左ショルダー
	ANY_BUTTON,		// どのボタンでもいい

	// ボタンの入力タイプの合計値
	NUM
};

// パッドのトリガーの左か右かまたはパッドのスティックの左か右か
enum class PadLR
{
	LEFT,	// トリガーまたはスティックの左
	RIGHT,	// トリガーまたはスティックの右
};

// パッドのスティックの入力タイプ
enum class PadStickInputType
{
	UP,				// 上
	DOWN,			// 下
	LEFT,			// 左
	RIGHT,			// 右
};

// パッドのスティックの強さ
enum class PadStickStrength
{
	WEAK,	// 弱い
	NORMAL,	// 普通
	STRONG	// 強い
};

// 入力装置カテゴリ
enum class InputCategory
{
	KEYBORD,	// キーボード
	PAD,		// ゲームパッド
	MOUSE		// マウス
};

// 入力情報
struct InputInfo
{
	InputCategory cat;	// 入力装置カテゴリ
	int id;				// 入力ID(KEY_INPUT_〜,PAD_INPUT_〜,MOUSE_INPUT_〜)
};

/// <summary>
/// 入力状態を管理する名前空間
/// </summary>
namespace InputStateManager
{
	/// <summary>
	/// 初期化
	/// </summary>
	void Init();

	/// <summary>
	/// 入力情報の更新 
	/// 毎フレームUpdateを呼ばないと入力状態は更新されない
	/// </summary>
	void Update();

	/// <summary>
	/// ボタンが押された瞬間の入力情報の取得
	/// </summary>
	/// <param name="type">取得したい入力タイプ</param>
	/// <returns>true : 入力、false : 非入力</returns>
	bool IsTriggered(const InputType type);

	/// <summary>
	/// ボタンが押されている間の入力情報の取得
	/// </summary>
	/// <param name="type">取得したい入力タイプ</param>
	/// <returns>true : 入力中、false : 非入力</returns>
	bool IsPressed(const InputType type);

	/// <summary>
	/// パッドのトリガーの入力情報の取得
	/// </summary>
	/// <param name="type">取得したい入力タイプ</param>
	/// <returns>true : 入力中、false : 非入力</returns>
	bool IsPadTrigger(const PadLR type);

	/// <summary>
	/// パッドのスティックの入力情報を値で取得
	/// </summary>
	/// <param name="stick">右スティックか左スティックか</param>
	/// <param name="input">スティックのどの入力タイプか</param>
	/// <returns>スティックの傾きぐわい(0のときは入力なし)　傾いている角度が大きいほど大きい数字が返ってくる</returns>
	int IsPadStick(const PadLR stic, const PadStickInputType type);

	/// <summary>
	/// パッドのスティックの入力情報を取得
	/// </summary>
	/// <param name="stick">右スティックか左スティックか</param>
	/// <param name="type">スティックのどの入力タイプか</param>
	/// <param name="strength">スティックをどれくらい入力しているか</param>
	/// <returns>true : 入力、false : 非入力</returns>
	bool IsPadStick(const PadLR stick, const PadStickInputType type, const PadStickStrength strength);

	// private
	namespace
	{
		// 仮想入力情報と実際の入力のテーブル
		std::map<InputType, std::vector<InputInfo>> m_inputMapTable;

		// 現在の入力情報(押してるか押してないか)
		std::vector<bool> m_currentInput;

		// 直前の入力情報(直前押してるか押してないか)
		std::vector<bool> m_lastInput;
	}
};