# 数学っぽいライブラリ

## BabyStepGiantStep
### 使い方
```C++
ll BSGS(ll x,ll y,ll mod)
```
$x^n \equiv y$なる整数 ${n}$が存在するか確認し、あるなら最小の $n$を返し、存在しない場合は-1を返す
#### 計算量
$O(\sqrt{mod})$
#### 制約
$2\le mod \le 3\times 10^9$, $mod$は素数
## Base-n-number
### コンストラクタ
```C++
BaseN() //(1)
BaseN(int bas) //(2)
BaseN(int bas,ll n) //(3)
```
#### 計算量
(1),(2) $$O(1)$$  
(3) $$O(\log{n})$$
#### 制約
$2\le base\le 97$
### 各進数への変換
```C++
baseN.to_base(ll n)
```
baseN.bas進数にnを変換した値をstringで返す
### 計算量
$O(\log n)$
