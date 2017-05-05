# MFCダイアログのテストカバレッジを高くしたい

## (解決策1) ダイアログクラスからロジックを分離する

ダイアログクラスのイベントハンドラに、ロジックを直接記述しない。
ロジックは別クラスに記述し、イベントハンドラからそのメソッドを呼び出すようにする。
こうすればロジック側はMFCのUIコントロールから切り離されるのでテストが容易になる。

この手法はHumble ObjectやHumble Dialogと呼ばれる。

### 例

(ロジックが単純なため却って複雑になっており、良いサンプルではない…)

#### before

![before](http://gravizo.com/g?%40startuml%3BActor%20%E3%83%A6%E3%83%BC%E3%82%B6%20as%20user%3Bparticipant%20CSampleAppDlg%3Bparticipant%20CEdit%3Bparticipant%20CListBox%3Buser%20-%3E%20CSampleAppDlg%20%3A%20%E3%80%8C%E8%BF%BD%E5%8A%A0%E3%80%8D%E3%83%9C%E3%82%BF%E3%83%B3%E6%8A%BC%E4%B8%8B%3Bactivate%20CSampleAppDlg%3B%20%20CSampleAppDlg%20-%3E%20CSampleAppDlg%20%3A%20OnBnClickedBtnAdd()%3B%20%20activate%20CSampleAppDlg%3B%20%20%20%20CSampleAppDlg%20-%3E%20CEdit%20%3A%20GetWindowText()%3B%20%20%20%20CSampleAppDlg%20%3C--%20CEdit%20%3A%20%E6%96%87%E5%AD%97%E5%88%97%3B%20%20%20%20CSampleAppDlg%20-%3E%20CListBox%20%3A%20AddString(%E6%96%87%E5%AD%97%E5%88%97)%3B%20%20deactivate%20CSampleAppDlg%3Bdeactivate%20CSampleAppDlg%3B%40enduml%3B)
<!--
@startuml
Actor ユーザ as user
participant CSampleAppDlg
participant CEdit
participant CListBox

user -> CSampleAppDlg : 「追加」ボタン押下
activate CSampleAppDlg
  CSampleAppDlg -> CSampleAppDlg : OnBnClickedBtnAdd()
  activate CSampleAppDlg
    CSampleAppDlg -> CEdit : GetWindowText()
    CSampleAppDlg <-- CEdit : 文字列
    CSampleAppDlg -> CListBox : AddString(文字列)
  deactivate CSampleAppDlg
deactivate CSampleAppDlg

@enduml
-->

#### after

![after](http://gravizo.com/g?%40startuml%3BActor%20%E3%83%A6%E3%83%BC%E3%82%B6%20as%20user%3Bparticipant%20CSampleAppDlg%3Bparticipant%20CEdit%3Bparticipant%20CListBox%3Bparticipant%20CLogic%3Bparticipant%20%22std%3A%3Avector%22%20as%20vector%3Buser%20-%3E%20CSampleAppDlg%20%3A%20%E3%80%8C%E8%BF%BD%E5%8A%A0%E3%80%8D%E3%83%9C%E3%82%BF%E3%83%B3%E6%8A%BC%E4%B8%8B%3Bactivate%20CSampleAppDlg%3B%20%20CSampleAppDlg%20-%3E%20CSampleAppDlg%20%3A%20OnBnClickedBtnAdd()%3B%20%20activate%20CSampleAppDlg%3B%20%20%20%20CSampleAppDlg%20-%3E%20CEdit%20%3A%20GetWindowText()%3B%20%20%20%20CSampleAppDlg%20%3C--%20CEdit%20%3A%20%E6%96%87%E5%AD%97%E5%88%97%3B%20%20%20%20CSampleAppDlg%20-%3E%20CLogic%20%3A%20Add(%E6%96%87%E5%AD%97%E5%88%97)%3B%20%20%20%20activate%20CLogic%3B%20%20%20%20%20%20CLogic%20-%3E%20vector%20%3A%20push_back(%E6%96%87%E5%AD%97%E5%88%97)%3B%20%20%20%20deactivate%20CLogic%3B%20%20%20%20CSampleAppDlg%20-%3E%20CSampleAppDlg%20%3A%20UpdateList%3B%20%20%20%20activate%20CSampleAppDlg%3B%20%20%20%20%20%20CSampleAppDlg%20-%3E%20CListBox%20%3A%20ResetContent()%3B%20%20%20%20%20%20CSampleAppDlg%20-%3E%20CLogic%20%3A%20GetList()%3B%20%20%20%20%20%20activate%20CLogic%3B%20%20%20%20%20%20%20%20CSampleAppDlg%20%3C--%20CLogic%20%3A%20vector%3B%20%20%20%20%20%20deactivate%20CLogic%3Bloop%3B%20%20%20%20%20%20CSampleAppDlg%20-%3E%20CListBox%20%3A%20AddString(%E6%96%87%E5%AD%97%E5%88%97)%3Bend%3B%20%20%20%20deactivate%20CSampleAppDlg%3B%20%20deactivate%20CSampleAppDlg%3Bdeactivate%20CSampleAppDlg%3B%40enduml%3B)
<!--
@startuml
Actor ユーザ as user
participant CSampleAppDlg
participant CEdit
participant CListBox
participant CLogic
participant "std::vector" as vector

user -> CSampleAppDlg : 「追加」ボタン押下
activate CSampleAppDlg
  CSampleAppDlg -> CSampleAppDlg : OnBnClickedBtnAdd()
  activate CSampleAppDlg
    CSampleAppDlg -> CEdit : GetWindowText()
    CSampleAppDlg <-- CEdit : 文字列
    CSampleAppDlg -> CLogic : Add(文字列)
    activate CLogic
      CLogic -> vector : push_back(文字列)
    deactivate CLogic

    CSampleAppDlg -> CSampleAppDlg : UpdateList
    activate CSampleAppDlg
      CSampleAppDlg -> CListBox : ResetContent()
      CSampleAppDlg -> CLogic : GetList()
      activate CLogic
        CSampleAppDlg <-- CLogic : vector
      deactivate CLogic
loop
      CSampleAppDlg -> CListBox : AddString(文字列)
end
    deactivate CSampleAppDlg

  deactivate CSampleAppDlg
deactivate CSampleAppDlg

@enduml
-->

## (解決策2) UIコントロールをモック化

1つのイベント中で複数のUIコントロールを協調させている場合、その部分にも複雑なロジックが発生するかもしれない。
そこまで含めたユニットテストを書きたい場合、UIコントロールのモックを作り、それらに対する呼び出しをテストすることもできる。
が、課題もある…

### 課題

下記はGoogleMockを使う前提。

- MFCのUIコントロールクラス群のメソッドは非virtual。
- この場合、モックを作るために2つの選択肢がある。
  - (1) UIコントロールクラスと無関係に、同じメソッド群をもつモッククラスを定義する。本物のクラスを使うかモッククラスを使うかは、template引数で指定する。 → [非仮想メソッドをモック化する](http://opencv.jp/googlemockdocs/cookbook.html#cookbook-mocking-nonvirtual-methods)
   - (2) インタフェースを定義する。実コードでは、インタフェースから派生し、UIコントロールクラスのメソッドを呼び出すラッパークラスを使う。テストでは、インタフェースから派生したモッククラスを使う。 → [具象クラスのモック化に対する代替案](http://opencv.jp/googlemockdocs/cookbook.html#cookbook-alternative-to-mocking-concrete-classes)
- (1)の場合、クラスをtemplateで指定するため、クラスメソッドに対するIntelliSenseが効かない。ISによる補完やコメント表示に頼りきっている場合、ビルドしてみないと正しいかわからないため不安。
- (2)の場合、インタフェース・ラッパークラス・モッククラスと、余分なクラスを定義するのが面倒。
  - モッククラスは[gmock_gen.py](https://github.com/google/googletest/blob/master/googlemock/scripts/generator/gmock_gen.py)を使えば生成できるはず。

## (解決策3) UIをテストする

(策2)にコストを費してロジックテストを頑張るよりは、いっそUI経由のテストを実行した方が楽かもしれない。

- [Friendly](http://www.codeer.co.jp/AutoTest)
- [TestStack/White: TestStack.White](https://github.com/TestStack/White)
- [UI オートメーションを使用してコードをテストする](https://msdn.microsoft.com/ja-jp/library/dd286726.aspx?f=255&MSPPError=-2147217396)