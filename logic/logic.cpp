// logic.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"
#include "logic.h"


// これは、エクスポートされた変数の例です。
LOGIC_API int nlogic=0;

// これは、エクスポートされた関数の例です。
LOGIC_API int fnlogic(void)
{
	return 42;
}

// これは、エクスポートされたクラスのコンストラクターです。
// クラス定義に関しては logic.h を参照してください。
Clogic::Clogic()
{
	return;
}
