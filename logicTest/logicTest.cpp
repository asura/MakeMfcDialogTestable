// logicTest.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

int main(int argc, char** argv)
{
	const int result = Catch::Session().run(argc, argv);
	return (result < 0xFF ? result : 0xFF);
}

