# BCPD Windows Version (gbcpd.exe)

This is the Windows version of the Bayesian Coherent Point Drift (BCPD) algorithm.

## Usage

The program can be used in two ways:

### 1. Using positional arguments (recommended):

```
gbcpd.exe target.ply source.ply output_prefix
```

Where:
- `target.ply`: The target point cloud file (PLY format)
- `source.ply`: The source point cloud file (PLY format)
- `output_prefix`: Prefix for output files

### 2. Using options:

```
gbcpd.exe -t target.ply -s source.ply -o output_prefix [other options]
```

Common options:
- `-t <file>`: Target point cloud file
- `-s <file>`: Source point cloud file
- `-o <prefix>`: Output file prefix
- `-w <real>`: Omega (default: 0.1)
- `-l <real>`: Lambda (default: 1.0)
- `-g <real>`: Gamma (default: 1.0)
- `-k <real>`: Kappa (default: 1.0)
- `-b <real>`: Beta (default: 2.0)
- `-n <int>`: Number of iterations (default: 50)
- `-v`: Verbose mode
- `-h`: Show help

## Supported File Formats

- PLY (Polygon File Format)

## Notes

This Windows version uses dummy LAPACK implementations, so some advanced mathematical operations may not work correctly. For full functionality, use the Linux version with proper LAPACK libraries.

## Example

```
gbcpd.exe bunny_target.ply bunny_source.ply result
```

This will generate output files with the prefix "result".

---

# BCPD Windows 版本 (gbcpd.exe)

这是贝叶斯相干点漂移（Bayesian Coherent Point Drift, BCPD）算法的 Windows 版本。

## 使用方法

该程序可以通过两种方式使用：

### 1. 使用位置参数（推荐）：

```
gbcpd.exe 目标点云.ply 源点云.ply 输出前缀
```

其中：
- `目标点云.ply`：目标点云文件（PLY 格式）
- `源点云.ply`：源点云文件（PLY 格式）
- `输出前缀`：输出文件的前缀

### 2. 使用选项：

```
gbcpd.exe -t 目标点云.ply -s 源点云.ply -o 输出前缀 [其他选项]
```

常用选项：
- `-t <文件>`：目标点云文件
- `-s <文件>`：源点云文件
- `-o <前缀>`：输出文件前缀
- `-w <实数>`：Omega 参数（默认：0.1）
- `-l <实数>`：Lambda 参数（默认：1.0）
- `-g <实数>`：Gamma 参数（默认：1.0）
- `-k <实数>`：Kappa 参数（默认：1.0）
- `-b <实数>`：Beta 参数（默认：2.0）
- `-n <整数>`：迭代次数（默认：50）
- `-v`：详细模式
- `-h`：显示帮助

## 支持的文件格式

- PLY（多边形文件格式）

## 注意事项

此 Windows 版本使用了虚拟 LAPACK 实现，因此某些高级数学运算可能无法正确工作。要获得完整功能，请使用带有适当 LAPACK 库的 Linux 版本。

## 示例

```
gbcpd.exe bunny_target.ply bunny_source.ply result
```

这将生成以 "result" 为前缀的输出文件。

---

# BCPD Windows バージョン (gbcpd.exe)

これはベイズコヒーレントポイントドリフト（Bayesian Coherent Point Drift, BCPD）アルゴリズムの Windows バージョンです。

## 使用方法

このプログラムは2つの方法で使用できます：

### 1. 位置引数を使用（推奨）：

```
gbcpd.exe ターゲット.ply ソース.ply 出力プレフィックス
```

ここで：
- `ターゲット.ply`：ターゲットポイントクラウドファイル（PLY形式）
- `ソース.ply`：ソースポイントクラウドファイル（PLY形式）
- `出力プレフィックス`：出力ファイルのプレフィックス

### 2. オプションを使用：

```
gbcpd.exe -t ターゲット.ply -s ソース.ply -o 出力プレフィックス [その他のオプション]
```

一般的なオプション：
- `-t <ファイル>`：ターゲットポイントクラウドファイル
- `-s <ファイル>`：ソースポイントクラウドファイル
- `-o <プレフィックス>`：出力ファイルプレフィックス
- `-w <実数>`：Omega パラメータ（デフォルト：0.1）
- `-l <実数>`：Lambda パラメータ（デフォルト：1.0）
- `-g <実数>`：Gamma パラメータ（デフォルト：1.0）
- `-k <実数>`：Kappa パラメータ（デフォルト：1.0）
- `-b <実数>`：Beta パラメータ（デフォルト：2.0）
- `-n <整数>`：繰り返し回数（デフォルト：50）
- `-v`：詳細モード
- `-h`：ヘルプを表示

## サポートされているファイル形式

- PLY（ポリゴンファイル形式）

## 注意事項

この Windows バージョンはダミーの LAPACK 実装を使用しているため、一部の高度な数学演算が正しく機能しない場合があります。完全な機能を使用するには、適切な LAPACK ライブラリを備えた Linux バージョンを使用してください。

## 例

```
gbcpd.exe bunny_target.ply bunny_source.ply result
```

これにより、"result" をプレフィックスとする出力ファイルが生成されます。

---

*Special thanks to the original author, Osamu Hirose, for developing the BCPD algorithm.*  
*特别感谢原作者 Osamu Hirose 开发 BCPD 算法。*  
*オリジナルの BCPD アルゴリズムを開発した広瀬修氏に特別な感謝を捧げます。*