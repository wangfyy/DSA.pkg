扩展欧几里得算法是对欧几里得算法的扩展。

首先，欧几里得算法：

[cpp] view plain copy
int gcd(int a, int b) {  
    return !b ? a : gcd(b, a % b);  
}  
四部分：

    1. 扩展欧几里得算法，方程 ax + by = gcd(a, b) 的求解

    2. 方程 ax + by = c 的求解

    3. 同余式 ax ≡ c(mod m) 的求解

    4. 逆元的求解 以及(b / a) % m 计算

--------------------------------------------------------------------

1. 扩展欧几里得算法，方程 ax + by = gcd(a, b) 的求解

    给定2个非零整数a、b，求一组整数解(x, y)，使得ax+ by = gcd(a,b)成立。（通过相关定理知解一定存在）

    可以利用欧几里得算法的过程来计算x和y（推倒过程略），代码：

int exGcd(int a, int b, int &x, int &y) {  
    if(b == 0) {  
        x = 1;  //递归到最底层时，给x和y赋值  
        y = 0;  
        return a;  
    }  
    int g = exGcd(b, a % b, x, y);  
    int temp = x;  
    x = y;  
    y = temp - a / b * y;  
    return g;  
}  
exGcd函数结束后便得到一对解，可通过下面的下面的式子得到全部解（过程略）：

x' = x + b / gcd * k            y' = y - a / gcd * k           (k为任意整数)

对任意整数来说，（ x % (b / gcd) + (b / gcd)） % (b / gcd) 为对应的最小非负整数解。

特殊地，如果gcd == 1，即 ax + by= 1 时，全部解的公式化简为：

x' = x + b  * k            y' = y - a  * k           (k为任意整数)

（ x % b + b） % b 为对应的最小非负整数解。

2. 方程 ax + by = c 的求解

ax + by = c 存在解的充要条件是 c % gcd == 0

假设 ax + by = gcd 的一组解为（x0，y0），则方程 ax + by = c 的一组解为 （cx0 / gcd，cy0 / gcd）


全部解：
    x' = x + b / gcd * k = cx0 / gcd + b / gcd * k 
    y' = y - a / gcd * k = cy0 / gcd - a / gcd * k            (k为任意整数)

对任意整数来说，（ x % (b / gcd) + (b / gcd)） % (b / gcd) 为对应的最小非负整数解， x 可取值为 cx0 / gcd


特殊地，如果gcd == 1，全部解的公式化简为：

x' = x + b  * k = cx0 + bk           y' = y - a  * k  = cy0 - ak           (k为任意整数)

（ x % b + b） % b 为对应的最小非负整数解。

3. 同余式 ax ≡ c(mod m) 的求解

"什么是同余式？" 对整数a,b,m来说，如果m整除a-b（即：（a - b）% m = 0），那么就说a与b模m同余，
对应的同余式为a ≡ b(mod m)，m称为同余式的模。 例如：10 ≡ 13（mod 3）    10 ≡ 1（mod 3）   
显然每一个整数都各自与[0,m)中的唯一的整数同余。

此处要解决的就是同余式 ax ≡ c(mod m)的求解，根据同余式的定义，有（ax - c）%m = 0成立，
因此存在整数y，使得ax - c = my 成立。移项并令y = -y后即得：ax + by = c   我们已知这个方程的解法。

结论： 
设 a,c,m是整数，其中 m >= 1，则：
(1)若 c % gcd(a, m) != 0，则同余式方程ax ≡ c(mod m)无解


(2)若 c % gcd(a, m) == 0，则同余式方程ax ≡ c(mod m)恰好有gcd(a,m)个模m意义下的不同的解，
且解的形式为 x' = x + m / gcd(a, m) * k，k = 0，1，...，gcd(a，m)-1，  x是一个解。  '


4. 逆元的求解 以及(b / a) % m 计算

"什么是逆元(乘法逆元)？" 对整数a,b,m来说，m>1，且ab≡1(mod m)成立，那么就说a和b互为模m逆元，
一般也记做a ≡ 1 / b (mod m) 或 b ≡ 1 / a (mod m)，通俗的说，如果两个整数的乘积模m后等于1，就称他们互为模m逆元。
逆元的作用：

对乘法来说，有 (b * a) % m = ( (b % m) * (a % m) ) % m 成立，
但是对除法来讲，(b / a) % m = ( (b % m) / (a % m) ) % m却不成立，(b / a) % m = ( (b % m) / a ) % m也不成立。  
此时就需要逆元来计算(b / a) % m。  通过找到a模m的逆元x，就有（b / a）% m = （b * x）% m 成立（仅考虑整数取模，
也即假设 b % a = 0，即b是a的整数倍），于是就把除法取模转换为乘法取模，这对于解决被除数b非常大(即使b已经取过模)的问题来讲是很有用的。

有定义知：求a模m的逆元，就是求解同余式 ax ≡ 1(mod m)，并且在使用中一般把x的最小整数解称为a模m的逆元，
下同，显然同余式ax ≡ 1(mod m)是否有解取决于1%gcd(a,m)是否为0，而这等价于gcd(a,m)是否为1：
(1)若gcd(a,m) ！= 1，那么同余式ax ≡ 1(mod m)无解，a不存在m的逆元。
(2)若gcd(a,m) == 1，那么同余式ax ≡ 1(mod m)在（0，m）上有唯一解，可以通过求解ax + my = 1得到。
注意：由于gcd(a,m) == 1，因此ax + my = 1 = gcd(a,m)，直接使用扩展欧几里得算法解出x之后就可以用（x%m + m） % m得到（0，m）范围内的解，
即所需要的逆元。

下面代码使用扩展欧几里得算法a模m的逆元，使用条件是gcd(a，m) = 1，当然如果m是素数，就肯定成立了

int inverse(int a, int m) {  
    int x, y;  
    int g = exGcd(a, m, x, y);  //求解 ax + my = 1  
    return (x % m + m) % m;  //a模m的逆元为(x % m + m) % m  
}  
另外，如果m是素数，且a不是m的素数，则还可以直接用费马小定理来得到逆元，这种做法不需要使用扩展欧几里得算法：

a ^ (m-2) % m 就是 a模m的逆元，快速幂求解。

当gcd(a,m) ！= 1时，扩展欧几里得算法和费马小定理均会失效，（过程略），得：

在a和m有可能不互素的情况下，可以使用公式 (b / a) % m = (b % (am)) / a来计算(b / a) % m 的值，
但是当a和m的乘积太大时可能溢出...