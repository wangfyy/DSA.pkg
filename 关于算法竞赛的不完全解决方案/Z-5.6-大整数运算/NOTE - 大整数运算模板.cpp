
// 大整数结构体
struct bign{  // big number
	int d[1000];
	int len;
	bign() {
		memset(d,0,sizeof(d));
		len = 0;
	}
}

// 将字符串表示的大整数转换为bign
bign change(char str[]) {
	bign a;
	a.len = strlen(str);
	for(int i=0; i<a.len; i++) {
		a.d[i] = str[a.len - i - 1] - '0';  // d[0]为个位数字
	}
	return a;
}

// 比较两个bign的大小
int compare(bign a, bign b) {
	if(a.len > b.len) return 1;  //a大
	else if(a.len < b.len) return -1;  //b大
	else {
		for(int i=a.len-1; i>=0; i--) {
			if(a.d[i] > b.d[i]) return 1;  //a大
			else if(a.d[i] < b.d[i]) return -1;  //b大
		}
		return 0;  //两数相等
	}
}

// 高精度 + 高精度
bign add(bign a, bign b) {
	bign c;
	int carry = 0;  // carry是进位
	for(int i=0; i<a.len || i<b.len; i++) {  ////以较长的为界限
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if(carry != 0) c.d[c.len++] = carry;
	return c;
}

// 高精度 - 高精度
bign sub(bign a, bign b) {
	bign c;
	for(int i=0; i<a.len || i<b.len; i++) {  ////以较长的为界限
		if(a.d[i] < b.d[i]) {  //如果不够减
			a.d[i++]--;  //向高位借位
			a.d[i] += 10;  //当前位加10
		}
		c.d[c.len++] = a.d[i] - b.d[i];
	}
	while(c.len - 1 >= 1 && c.d[c.len - 1] == 0) {  //为什么‘ c.len - 1 ’
		c.len--;  // 去处高位的0，同时至少保留一位最低位(0)
	}
	return c;
}

// 高精度 * 低精度
bign multi(bign a, int b) {
	bign c;
	int carry = 0
	for(int i=0; i<a.len; i++) {
		int temp = a.d[i] * b + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	while(carry != 0) {
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

// 高精度 / 低精度
bign divide(bign a, int b, int& r) {
	bign c;
	c.len = a.len;  //被除数的每一位和商的每一位都是一一对应的
	for(int i=a.len-1; i>=0; i--) {  //从高位开始
		r = r * 10 + a.d[i];  //和上一位遗留的余数组合
		if(r < b) c.d[i] = 0;  //不够除，该位为0
		else {  //够除
			c.d[i] = r / b;  //商
			r = r % b;  //获取新的余数
		}
	}
	while(c.len - 1 >= 1 && c.d[c.len - 1] == 0) {  //为什么‘ c.len - 1 ’
		c.len--;  // 去处高位的0，同时至少保留一位最低位(0)
	}
	return c;
}