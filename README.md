# make-abc-tmp

AtCoderのABC用テンプレートを作成する。

具体的にはmake-abc-tmpの親ディレクトリに対して、テンプレートを作成する。
フォルダ構成は以下の通り。

```
abc-mine
    |
    |―― 240
    │  
    ├── 241(template)
    │   ├── Ex.cpp
    │   ├── a.cpp
    │   ├── b.cpp
    │   ├── c.cpp
    │   ├── d.cpp
    │   ├── e.cpp
    │   ├── f.cpp
    │   └── g.cpp
    |
    ├── README.md
    └── make-abc-tmp
        ├── LICENSE
        ├── README.md
        ├── a.out
        ├── main.c
        └── template.txt
```

私の実際に使用しているテンプレートの内容
```cpp:template.txt
#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
using vi = vector<int>;
using vii = vector<vi>;

int main()
{
  return 0;
}
```
# 動作環境
Ubuntu on WSL2

gcc version 11.3.0

# 使用方法
自分のabcのディレクトリに移動したら以下をターミナルにコピペ。
```
git clone https://github.com/satabie/make-abc-tmp.git &&
cd make-abc-tmp
```
template.txtを自分の好きなように編集する。

以下で実行ファイルを作成し、
```
gcc main.c
```
第一引数にabc-ID(abc245等)、第二引数に先ほどのテンプレートに対応する言語の拡張子（.c, .cpp, .py等)を与える。
```
./a.out [abc-ID] [ファイル拡張子]
```
# 具体例
```
./a.out 276 .cpp
```
