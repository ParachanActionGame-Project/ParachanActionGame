﻿
//
// OpenSiv3D v0.4.3 ゲームテンプレート
//

//
// macOS では README.md と同じフォルダに
// include と lib をコピーしてください。
//

# include "Common.hpp"
# include "CreditScene.hpp"
# include "Title.hpp"
# include "Rule.hpp"
# include "Game.hpp"
# include "Start.hpp"
# include "ParaSampleScene.hpp"
# include "ResultScene.hpp"

void Main()
{
	// （Esc キーで終了しないようにする場合はコメントを外す）
	//System::SetTerminationTriggers(UserAction::CloseButtonClicked);

	// タイトルを設定
	Window::SetTitle(U"KurachanActionGame");

	// 背景色を設定
	Scene::SetBackground(ColorF(0.2, 0.8, 0.4));

	// 使用するフォントアセットを登録
	FontAsset::Register(U"Title", 120, Typeface::Bold);
	FontAsset::Register(U"Menu", 30, Typeface::Regular);
	FontAsset::Register(U"Score", 36, Typeface::Bold);
	FontAsset::Register(U"ParaSampleScene", 36, Typeface::Bold);
	FontAsset::Register(U"CreditScene", 36, Typeface::Bold);
	//FontAsset::Register(U"LL",36,);


	// シーンと遷移時の色を設定
	MyApp manager;
	manager
		.add<Start>(State::Start)
		.add<Rule>(State::Rule)
		.add<ParaSampleScene>(State::ParaSample)
		.add<CreditScene>(State::Credit)
		//.add<Title>(State::Title)
		.add<Game>(State::Game)
		.add<ResultScene>(State::Result)
		.setFadeColor(ColorF(1.0));
	    

	//Console.open();

	// （ゲームシーンから開始する場合はコメントを外す）
	//manager.init(State::Game);

	Window::Resize(Size(1280,720));

	while (System::Update())
	{
		if (!manager.update())
		{
			break;
		}
	}

}

//
// = クロスプラットフォーム開発の注意 =
//
// Xcode でソースコードを保存すると UTF-8 形式 (BOM 無し) になります。
// MSVC で作業するときはソースコードを UTF-8 (BOM 付き) に直す必要があります。
//
//
// = アドバイス =
// macOS 10.15 Catalina の Xcode プロジェクトで、
// ビルドしたプログラムを起動するたびにファイルアクセス許可のダイアログが表示される場合、
// プロジェクトのフォルダを User/アプリケーション に移動させることで通常は表示されなくなります。
// 特別なファイルシステム関数の使用や、Web カメラ、マイク使用時のダイアログまでは消せません。
//
//
// = アドバイス =
// Debug ビルドではプログラムの最適化がオフになります。
// 実行速度が遅いと感じた場合は Release ビルドを試しましょう。
// アプリをリリースするときにも、Release ビルドにするのを忘れないように！
//
// 思ったように動作しない場合は「デバッグの開始」でプログラムを実行すると、
// 出力ウィンドウに詳細なログが表示されるので、エラーの原因を見つけやすくなります。
//
//
// = お役立ちリンク =
//
// OpenSiv3D リファレンス
// https://siv3d.github.io/ja-jp/
//
// チュートリアル
// https://siv3d.github.io/ja-jp/tutorial/basic/
//
// よくある間違い
// https://siv3d.github.io/ja-jp/articles/mistakes/
//
// サポートについて
// https://siv3d.github.io/ja-jp/support/support/
//
// Siv3D ユーザコミュニティ Slack への参加
// https://siv3d.github.io/ja-jp/community/community/
//
// 新機能の提案やバグの報告
// https://github.com/Siv3D/OpenSiv3D/issues
//
